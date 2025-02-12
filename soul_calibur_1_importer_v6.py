import struct
import bpy
import bmesh
import os
from math import radians
from mathutils import Vector, Matrix, Euler

def read_little_endian_uint32(file):
    return struct.unpack("<I", file.read(4))[0]

def read_little_endian_uint16(file):
    return struct.unpack("<H", file.read(2))[0]

def read_little_endian_uint8(file):
    return struct.unpack("<b", file.read(1))[0]

def read_little_endian_int16(file):
    return struct.unpack("<h", file.read(2))[0]

def read_little_endian_float(file):
    return struct.unpack("<f", file.read(4))[0]

def reset_msb(value, bit_width=16):
    # Create a mask with all bits set except the MSB
    mask = (1 << (bit_width - 1)) - 1
    # Reset the MSB using bitwise AND
    return value & mask

# Manual bone rotation fixes (similar to MAXScript)
def manual_bone_fixes(bone_index, bone_matrix):
    corrections = {
        1: Euler((0, radians(90), 0), 'XYZ'),        # Torso
        4: Euler((radians(180), 0, radians(180)), 'XYZ'),  # Right shoulder
        5: Euler((0, 0, radians(335)), 'XYZ'),      # Right arm
        7: Euler((radians(90), radians(180), radians(90)), 'XYZ'),  # Right wrist
        9: Euler((radians(180), 0, radians(335)), 'XYZ'),  # Left arm
        11: Euler((radians(90), radians(180), radians(90)), 'XYZ'), # Left wrist
        12: Euler((radians(180), radians(270), 0), 'XYZ'),  # Hips
    }
    if bone_index in corrections:
        correction_matrix = corrections[bone_index].to_matrix().to_4x4()
        bone_matrix = bone_matrix @ correction_matrix
    return bone_matrix

def create_armature(submeshes):
    # Create armature and enter edit mode
    armature = bpy.data.armatures.new("SoulCaliburArmature")
    armature_obj = bpy.data.objects.new("SoulCaliburArmature", armature)
    bpy.context.collection.objects.link(armature_obj)
    
    # Make the armature active and enter edit mode
    bpy.context.view_layer.objects.active = armature_obj
    bpy.ops.object.mode_set(mode='EDIT')
    
    # Dictionary to store bone objects for parenting
    bones = {}
    
    # First pass: Create all bones
    for bone_index, submesh in enumerate(submeshes):
        bone_name = f"Bone_{bone_index}"
        bone = armature.edit_bones.new(bone_name)
        
        # Convert position to world space
        position = Vector((
            submesh["bone_position"][0] / 4000.0,
            submesh["bone_position"][1] / 4000.0,
            submesh["bone_position"][2] / 4000.0
        ))
        
        # Set bone position
        bone.head = position
        bone.tail = position + Vector((0, 0.1, 0))  # Add small length to bone
        
        # Store bone for parenting
        bones[bone_index] = bone
    
    # Second pass: Set up bone parenting
    for bone_index, submesh in enumerate(submeshes):
        if submesh["parent_bone_id"] >= 0:
            parent_index = submesh["parent_bone_id"]
            if parent_index in bones:
                bones[bone_index].parent = bones[parent_index]
    
    # Exit edit mode to apply changes
    bpy.ops.object.mode_set(mode='OBJECT')
    return armature_obj

def import_soul_calibur_model(filepath):
    with open(filepath, "rb") as file:
        # Read the main header
        filename = file.read(24)
        triangle_strip_table_pointer = read_little_endian_uint32(file)
        header_length = read_little_endian_uint16(file)
        file.read(1)[0]
        file.read(1)[0]

        print(f"Filename: {filename}")
        print(f"Triangle Strip Table Pointer: {triangle_strip_table_pointer}")
        print(f"Header Length: {header_length}")
        
        submesh_id = 0

        # Read submesh headers
        submeshes = []
        while file.tell() < 2624:
            unk1 = file.read(2)[0]
            unk2 = file.read(2)[0]
            vertex_list_pointer = read_little_endian_uint32(file)
            unknown = read_little_endian_uint32(file)
            vertex_count = read_little_endian_uint16(file)
            normal_count = read_little_endian_uint16(file)
            bone_rotation_x = read_little_endian_int16(file)
            bone_rotation_y = read_little_endian_int16(file)
            bone_rotation_z = read_little_endian_int16(file)
            unknown2 = read_little_endian_int16(file)
            bone_position_x = read_little_endian_int16(file)
            bone_position_y = read_little_endian_int16(file)
            bone_position_z = read_little_endian_int16(file)
            parent_bone_id = read_little_endian_int16(file)

            submeshes.append({
                "unk1": unk1,
                "unk2": unk2,
                "vertex_list_pointer": vertex_list_pointer,
                "vertex_count": vertex_count,
                "normal_count": normal_count,
                "bone_rotation": (bone_rotation_x, bone_rotation_y, bone_rotation_z),
                "bone_position": (bone_position_x, bone_position_y, bone_position_z),
                "parent_bone_id": parent_bone_id,
            })
        
        # Create the armature first
        armature_obj = create_armature(submeshes)
        
        # Create a new Blender object for the model
        mesh = bpy.data.meshes.new("SoulCaliburModel")
        obj = bpy.data.objects.new("SoulCaliburModel", mesh)
        bpy.context.collection.objects.link(obj)
        
        # Add vertex groups for each bone
        for bone_index in range(len(submeshes)):
            obj.vertex_groups.new(name=f"Bone_{bone_index}")
        
        bm = bmesh.new()
        
        # Dictionary to store vertex weights
        vertex_weights = {}  # {vertex_index: [(bone_index, weight), ...]}
        
        # Read vertices and apply bone transforms
        for bone_index, submesh in enumerate(submeshes):
            file.seek(submesh["vertex_list_pointer"])
            
            # Calculate bone transformation matrix
            bone_translation = Vector((
                submesh["bone_position"][0] / 4000.0,
                submesh["bone_position"][1] / 4000.0,
                submesh["bone_position"][2] / 4000.0
            ))
            
            bone_rotation = Euler((
                radians(submesh["bone_rotation"][0] / 32768.0 * 360.0),
                radians(submesh["bone_rotation"][1] / 32768.0 * 360.0),
                radians(submesh["bone_rotation"][2] / 32768.0 * 360.0)
            ), 'XYZ').to_matrix().to_4x4()
            
            bone_matrix = Matrix.Translation(bone_translation) @ bone_rotation
            bone_matrix = manual_bone_fixes(bone_index, bone_matrix)
            
            for vertex_idx in range(submesh["vertex_count"]):
                vertex_x = read_little_endian_float(file)
                vertex_y = read_little_endian_float(file)
                vertex_z = read_little_endian_float(file)
                vertex_index = read_little_endian_uint16(file)
                flags = read_little_endian_uint16(file)
                
                if vertex_index < 32768:
                    # Transform vertex by bone matrix
                    vertex = Vector((vertex_x, vertex_y, vertex_z))
                    transformed_vertex = bone_matrix @ vertex.to_4d()
                    bm.verts.new(transformed_vertex.to_3d())
                    
                    # Store vertex weight
                    if vertex_index not in vertex_weights:
                        vertex_weights[vertex_index] = []
                    vertex_weights[vertex_index].append((bone_index, 1.0))
        
        bm.verts.ensure_lookup_table()
        
        
        


        # Read triangle strips
        file.seek(triangle_strip_table_pointer)
        strip_inc = 0
    
        while True:
            # Read the strip header
            unk_uv = read_little_endian_uint16(file)
            unk_uv = read_little_endian_uint8(file)
            strip_length = read_little_endian_uint8(file)
            strip_inc += 1
        
            print(f'Strip No.: {strip_inc}')
            print(hex(strip_length))
        
            # Check for the end of triangle strips
            if strip_length == 0:
                # Peek ahead to confirm end of strips
                next_unk_uv = read_little_endian_uint16(file)
                next_unk_uv = read_little_endian_uint8(file)
                next_strip_length = read_little_endian_uint8(file)
        
                if next_strip_length == 0:
                    # Double-zero terminator detected, end of strips
                    break
                else:
                    # Not the end, rewind to process the next strip
                    file.seek(-4, os.SEEK_CUR)
                    continue
        
            # Process the current triangle strip
            triangles = []
            for _ in range(strip_length):
                vertex_index = read_little_endian_uint16(file)
                vertex_color = read_little_endian_uint16(file)
                print(f"vertex_index: {vertex_index}")
                uv_coordinates = read_little_endian_uint32(file)
                triangles.append(vertex_index)
        
            # Create faces from the current triangle strip
            for i in range(len(triangles) - 2):
                try:
                    v1 = bm.verts[triangles[i]]
                    v2 = bm.verts[triangles[i + 1]]
                    v3 = bm.verts[triangles[i + 2]]
        
                    # Handle winding order
                    if i % 2 == 0:  # Even winding
                        face_verts = [v1, v2, v3]
                    else:           # Odd winding (reverse)
                        face_verts = [v1, v3, v2]
        
                    # Avoid duplicate faces
                    if not bm.faces.get(face_verts):
                        bm.faces.new(face_verts)
                        print(f'Drawing face: {triangles[i]}, {triangles[i + 1]}, {triangles[i + 2]}')
        
                except IndexError as e:
                    print(f"Invalid triangle indices: {triangles[i]}, {triangles[i + 1]}, {triangles[i + 2]} (Error: {e})")
                except ValueError as e:
                    print(f"Face creation error: {e}")
            
            bm.faces.ensure_lookup_table()
        
        # Apply the mesh to the object
        bm.to_mesh(mesh)
        bm.free()
        
        # Apply vertex weights
        for vertex_index, weights in vertex_weights.items():
            # Normalize weights for each vertex
            total_weight = sum(w for _, w in weights)
            if total_weight > 0:
                normalized_weights = [(bone_idx, w/total_weight) for bone_idx, w in weights]
                
                for bone_index, weight in normalized_weights:
                    vertex_group = obj.vertex_groups[f"Bone_{bone_index}"]
                    vertex_group.add([vertex_index], weight, 'REPLACE')
        
        # Add armature modifier
        armature_mod = obj.modifiers.new(name="Armature", type='ARMATURE')
        armature_mod.object = armature_obj
        obj.parent = armature_obj
        
        print("Model imported successfully with armature!")

# Usage
os.chdir(r'R:\stuff\sc1_apk')
os.system("cls")
import_soul_calibur_model("xianghua_dc_1p_decompressed.bin")