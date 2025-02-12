import struct
import bpy
import bmesh
import os
from mathutils import Vector

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

        # Read submesh headers
        submeshes = []
        while file.tell() < 2624:
            bone_id0 = file.read(2)[0]
            bone_id1 = file.read(2)[0]
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
                "bone_id0": bone_id0,
                "bone_id1": bone_id1,
                "vertex_list_pointer": vertex_list_pointer,
                "vertex_count": vertex_count,
                "normal_count": normal_count,
                "bone_rotation": (bone_rotation_x, bone_rotation_y, bone_rotation_z),
                "bone_position": (bone_position_x, bone_position_y, bone_position_z),
                "parent_bone_id": parent_bone_id,
            })

        # Create a new Blender object for the model
        mesh = bpy.data.meshes.new("SoulCaliburModel")
        obj = bpy.data.objects.new("SoulCaliburModel", mesh)
        bpy.context.collection.objects.link(obj)
        bm = bmesh.new()

        # Read vertices and keep track of highest index
        highest_vertex_index = -1
        for submesh in submeshes:
            print(f'Vertex list pointer: {submesh["vertex_list_pointer"]}')
            file.seek(submesh["vertex_list_pointer"])
            vertices = []
            for _ in range(submesh["vertex_count"]):
                vertex_x = read_little_endian_float(file)
                vertex_y = read_little_endian_float(file)
                vertex_z = read_little_endian_float(file)
                vertex_index = read_little_endian_uint16(file)
                print(f"Vertex ID: {vertex_index}")
                flags = read_little_endian_uint16(file)

                vertices.append((vertex_x, vertex_y, vertex_z))
                bm.verts.new((vertex_x, vertex_y, vertex_z))
                highest_vertex_index = max(highest_vertex_index, vertex_index)

            bm.verts.ensure_lookup_table()

        print(f"Highest vertex index: {highest_vertex_index}")

        # Read triangle strips
        file.seek(triangle_strip_table_pointer)
        while True:
            triangles = []
            while True:
                # Read the strip_length (lowest 8 bits of the word)
                unk_uv = read_little_endian_uint16(file)
                unk_uv = read_little_endian_uint8(file)
                strip_length = read_little_endian_uint8(file)
        
                print(hex(strip_length))
        
                if strip_length == 0:
                    # Terminate the current strip and process the triangles
                    if triangles:
                        # Create faces from triangles
                        for i in range(len(triangles) - 2):
                            try:
                                v1 = bm.verts[triangles[i]]
                                v2 = bm.verts[triangles[i + 1]]
                                v3 = bm.verts[triangles[i + 2]]
        
                                # Ensure the vertices form a valid triangle and no duplicate face exists
                                if (i % 2 == 0):  # Handle strip directionality (even winding)
                                    face_verts = [v1, v2, v3]
                                else:  # Reverse winding on odd indices
                                    face_verts = [v1, v3, v2]
        
                                if not bm.faces.get(face_verts):
                                    bm.faces.new(face_verts)
        
                            except IndexError as e:
                                print(f"Invalid triangle indices: {triangles[i]}, {triangles[i + 1]}, {triangles[i + 2]} (Error: {e})")
                            except ValueError as e:
                                print(f"Face creation error: {e}")
                    # Clear triangles and check for termination
                    triangles = []
        
                    # Peek ahead to check if it's the end of strips
                    unk_uv = read_little_endian_uint16(file)
                    unk_uv = read_little_endian_uint8(file)
                    strip_length = read_little_endian_uint8(file)
                    if strip_length == 0:
                        # End of triangle strips
                        break
                    else:
                        # Reset file pointer to reprocess this strip
                        file.seek(-4, os.SEEK_CUR)
                        continue
        
                for _ in range(strip_length):
                    vertex_index = read_little_endian_uint16(file)
                    vertex_color = read_little_endian_uint16(file)
                    print(f"vertex_index: {vertex_index}")
                    # print(f"vertex_color: {vertex_color}")
                    uv_coordinates = read_little_endian_uint32(file)
                    triangles.append(vertex_index)
        
            # If we reach here, it means the entire strip table is done
            break
        
        bm.faces.ensure_lookup_table()

        
#        except struct.error as e:
#           print(f"Struct error while parsing triangle strips: {e}")
        
        # Finalize the mesh
        bm.to_mesh(mesh)
        bm.free()
        print("Model imported successfully!")

        
os.chdir(r'R:\stuff\sc1_apk')
os.system("cls")
import_soul_calibur_model("xianghua_dc_1p_decompressed.bin")
