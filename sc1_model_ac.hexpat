#pragma author spaztron64
#pragma description Soul Calibur 1 - Character Model Format (Dreamcast)
#pragma loop_limit 32768

import std.string;

struct vertex_list{
    u16       vertex_x [[color("FF0000")]];
    u16       vertex_y [[color("00FF00")]];
    u16      vertex_z [[color("0000FF")]];;
    u16    vertex_index [[color("00FFFF")]];;
};

struct normal_list{
    u16       normal_x;
    u16       normal_y;
    u16       normal_z;
    u16    normal_index;
};

struct GP0_command{
    u16    paddings [[color("000000")]];
    u8     depth_priority [[color("4391FF")]];
    u8     GP0_ID [[color("FF0000")]];
    u32    packed_vertex_IDs [[color("00FF00")]];
    u32    unknown_lighting [[color("000000")]];
    u32    unknown_2 [[color("000000")]];
    u8     Texcoord1Y [[color("AA2299")]];
    u8     Texcoord1X [[color("99AA22")]];    
    u16    CLUT [[color("6913A9")]];
    u8     Texcoord2Y [[color("21A4F2")]];
    u8     Texcoord2X [[color("F2A421")]];    
    u16    Texpage [[color("A91369")]];    
    u8     Texcoord3Y [[color("16BD27")]];
    u8     Texcoord3X [[color("BD1627")]];    
    u16    paddings2 [[color("000000")]];        

    
};

struct model_submesh{
    u8     bone_id0 [[color("338855")]]; // NULL on weapons?
    u8     bone_id1 [[color("553388")]];
    u8     unk4 [[color("222222")]];
    u8     unk5 [[color("222222")]];     
    u32    vertex_list_pointer [[color("FFAA00")]]; // points to a vertex_list_t
    u32    unknown [[color("222222")]]; // Always 0x00000000?
    u16    vertex_count [[color("2222FF")]];
    u16    normal_count [[color("FF22FF")]];
    s16     bone_rotation_x [[color("00FF99")]];
    s16     bone_rotation_y [[color("00FF99")]];;
    s16     bone_rotation_z [[color("00FF99")]];;
    s16     unknown1 [[color("222222")]];;
    s16     bone_position_x [[color("FFFF99")]];;
    s16     bone_position_y [[color("FFFF99")]];;
    s16     bone_position_z [[color("FFFF99")]];;
    s16     parent_bone_id [[color("88FF44")]];;
    
    vertex_list VLists[vertex_count] @ vertex_list_pointer [[sealed]];
    normal_list NLists[normal_count] @ vertex_list_pointer+(vertex_count*8) [[sealed]];
   
};

struct main_header{
	char           filename[24] [[color("FF0000")]]; // 24 character filename that doesn't really contain anything useful
	u32            GP0_command_list_pointer [[color("AA55FF")]]; // points to the first triangle_strip_t;
	u8             submesh_count [[color("88121F")]]; // How many model_submesh_t instances exist;
	u8             unk1 [[color("222222")]];
    u16    strip_counter;
	model_submesh  model_submesh_table[submesh_count]; // One or more submesh headers. Usually no more than 17
};

main_header Main @ $;

GP0_command GP0 [910] @ Main.GP0_command_list_pointer;