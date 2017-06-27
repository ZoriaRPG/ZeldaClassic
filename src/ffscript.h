#ifndef _FFSCRIPT_H_
#define _FFSCRIPT_H_
#include "zdefs.h"
#include <utility>
#include <string>
#include <list>
#include "zelda.h"


class FFScript
{
private:
    long sid;
    
public:
    byte rules[512]; //For Migration of Quest Rules, and Scritp Engine Rules


    int screenbounds[4]; //edges of the screen, left, right, top, bottom used for where to scroll. 
    int screen_dimensions[4]; //height, width, displaywidth, displayheight
    int subscreen_dimensions[4];
    int eweapon_removal_bounds[4]; //left, right, top, bottom coordinates for automatic eweapon removal. 
    int lweapon_removal_bounds[4]; //left, right, top, bottom coordinates for automatic lweapon removal. 
    int linktile, linkaction; //Overrides for the tile used when blitting Limk to the bitmap; and a var to hold a script-set action/
		//This way, we can make safe replicas of internal Link actions to be set by script. 
#define FFSCRIPTCLASS_CLOCKS 10
    int clocks[FFSCRIPTCLASS_CLOCKS]; //Will be used for Linkaction, anims, and so forth 

    #define SCRIPT_DRAWING_RULES 20
    bool ScriptDrawingRules[SCRIPT_DRAWING_RULES];
	//Allow or forbid drawing during specific game events. 
	enum{
		scdrDRAW_WHILE_SCROLLING, scdrDRAW_DURING_SCREEN_TRANSITION, scdrDRAW_DURING_WARP,
		scdrDRAW_DURING_WIPES, scdrLAST
	};
#define NUM_USER_MIDI_OVERRIDES 6
	int UserMidis[NUM_USER_MIDI_OVERRIDES]; //MIDIs to use for Game Over, and similar to override system defaults. 
    
    virtual ~FFScript();
    virtual int getrule(int rule);   
    virtual void setrule(int rule, bool state); 
static void set_screenwarpReturnY(mapscr *m, int d, int value);
static void set_screendoor(mapscr *m, int d, int value);
static void set_screenenemy(mapscr *m, int index, int value);
static void set_screenlayeropacity(mapscr *m, int d, int value);
static void set_screensecretcombo(mapscr *m, int d, int value);
static void set_screensecretcset(mapscr *m, int d, int value);
static void set_screensecretflag(mapscr *m, int d, int value);
static void set_screenlayermap(mapscr *m, int d, int value);
static void set_screenlayerscreen(mapscr *m, int d, int value);
static void set_screenpath(mapscr *m, int d, int value);
static void set_screenwarpReturnX(mapscr *m, int d, int value);
static void set_screenWidth(mapscr *m, int value);
static void set_screenHeight(mapscr *m, int value);
static void set_screenViewX(mapscr *m, int value);
static void set_screenViewY(mapscr *m, int value);
static void set_screenGuy(mapscr *m, int value);
static void set_screenString(mapscr *m, int value);
static void set_screenRoomtype(mapscr *m, int value);
static void set_screenEntryX(mapscr *m, int value);
static void set_screenEntryY(mapscr *m, int value);
static void set_screenitem(mapscr *m, int value);
static void set_screenundercombo(mapscr *m, int value);
static void set_screenundercset(mapscr *m, int value);
static void set_screenatchall(mapscr *m, int value);
static long get_screenWidth(mapscr *m);
static long get_screenHeight(mapscr *m);
static void deallocateZScriptArray(const long ptrval);
static int get_screen_d(long index1, long index2);
static void set_screen_d(long index1, long index2, int val);
static int whichlayer(long scr);
static void clear_ffc_stack(const byte i);
static void clear_global_stack();
static void do_zapout();
static void do_zapin();
static void do_openscreen();
static void do_wavyin();
static void do_wavyout();
static void do_triggersecret(const bool v);
static void do_changeffcscript(const bool v);

static void setLinkDiagonal(bool v);
static bool getLinkDiagonal();
static bool getLinkBigHitbox();
static void setLinkBigHitbox(bool v);

//NPCData getters One Input, One Return
	static void getNPCData_flags(); //word
	static void getNPCData_flags2();
	static void getNPCData_width();
	static void getNPCData_height();
	static void getNPCData_s_tile();
	static void getNPCData_s_width();
	static void getNPCData_s_height();
	static void getNPCData_e_tile();
	static void getNPCData_e_width();
	static void getNPCData_hp();
	static void getNPCData_family();
	static void getNPCData_cset();
	static void getNPCData_anim();
	static void getNPCData_e_anim();
	static void getNPCData_frate();
	static void getNPCData_e_frate();
	static void getNPCData_dp();
	static void getNPCData_wdp();
	static void getNPCData_weapon();
	static void getNPCData_rate();
	static void getNPCData_hrate();
	static void getNPCData_step();
	static void getNPCData_homing();
	static void getNPCData_grumble();
	static void getNPCData_item_set();
	static void getNPCData_bgsfx();
	static void getNPCData_hitsfx();
	static void getNPCData_deadsfx();
	static void getNPCData_xofs();
	static void getNPCData_yofs();
	static void getNPCData_zofs();
	static void getNPCData_hxofs();
	static void getNPCData_hyofs();
	static void getNPCData_hxsz();
	static void getNPCData_hysz();
	static void getNPCData_hzsz();
	static void getNPCData_txsz();
	static void getNPCData_tysz();
	static void getNPCData_wpnsprite();

	//NPCData Getters, two inouts, one return



	//static void getNPCData_scriptdefence();
	static void getNPCData_misc();//switch-case
	static void getNPCData_defense(); //extra arg
	static void getNPCData_SIZEflags();


	//NPCData Setters, two inputs, no return.

	static void setNPCData_flags(); //word
	static void setNPCData_flags2();
	static void setNPCData_width();
	static void setNPCData_height();
	static void setNPCData_s_tile();
	static void setNPCData_s_width();
	static void setNPCData_s_height();
	static void setNPCData_e_tile();
	static void setNPCData_e_width();
	static void setNPCData_hp();
	static void setNPCData_family();
	static void setNPCData_cset();
	static void setNPCData_anim();
	static void setNPCData_e_anim();
	static void setNPCData_frate();
	static void setNPCData_e_frate();
	static void setNPCData_dp();
	static void setNPCData_wdp();
	static void setNPCData_weapon();
	static void setNPCData_rate();
	static void setNPCData_hrate();
	static void setNPCData_step();
	static void setNPCData_homing();
	static void setNPCData_grumble();
	static void setNPCData_item_set();
	static void setNPCData_bgsfx();
	static void setNPCData_hitsfx();
	static void setNPCData_deadsfx();
	static void setNPCData_xofs();
	static void setNPCData_yofs();
	static void setNPCData_zofs();
	static void setNPCData_hxofs();
	static void setNPCData_hyofs();
	static void setNPCData_hxsz();
	static void setNPCData_hysz();
	static void setNPCData_hzsz();
	static void setNPCData_txsz();
	static void setNPCData_tysz();
	static void setNPCData_wpnsprite();

	//NPCData Setters, three inputs, no return.
	//static void setNPCData_scriptdefence();
	static void setNPCData_defense(int v); //extra arg
	static void setNPCData_SIZEflags(int v);
	static void setNPCData_misc(int val);
	
	
	//one input, one return
	static void getComboData_block_enemies(){ GET_COMBODATA_TYPE_INT(block_enemies); } //byte a
	static void getComboData_block_hole(){ GET_COMBODATA_TYPE_INT(block_hole); } //byte b
	static void getComboData_block_trigger(){ GET_COMBODATA_TYPE_INT(block_trigger); } //byte c
	static void getComboData_conveyor_x_speed(){ GET_COMBODATA_TYPE_INT(conveyor_x_speed); } //short e
	static void getComboData_conveyor_y_speed(){ GET_COMBODATA_TYPE_INT(conveyor_y_speed); } //short f
	static void getComboData_create_enemy(){ GET_COMBODATA_TYPE_INT(create_enemy); } //word g
	static void getComboData_create_enemy_when(){ GET_COMBODATA_TYPE_INT(create_enemy_when); } //byte h
	static void getComboData_create_enemy_change(){ GET_COMBODATA_TYPE_INT(create_enemy_change); } //long i
	static void getComboData_directional_change_type(){ GET_COMBODATA_TYPE_INT(directional_change_type); } //byte j
	static void getComboData_distance_change_tiles(){ GET_COMBODATA_TYPE_INT(distance_change_tiles); } //long k
	static void getComboData_dive_item(){ GET_COMBODATA_TYPE_INT(dive_item); } //short l
	static void getComboData_dock(){ GET_COMBODATA_TYPE_INT(dock); } //byte m
	static void getComboData_fairy(){ GET_COMBODATA_TYPE_INT(fairy); } //byte n
	static void getComboData_ff_combo_attr_change(){ GET_COMBODATA_TYPE_INT(ff_combo_attr_change); } //byte o
	static void getComboData_foot_decorations_tile(){ GET_COMBODATA_TYPE_INT(foot_decorations_tile); } //long p
	static void getComboData_foot_decorations_type(){ GET_COMBODATA_TYPE_INT(foot_decorations_type); } //byte q
	static void getComboData_hookshot_grab_point(){ GET_COMBODATA_TYPE_INT(hookshot_grab_point); } //byte r
	static void getComboData_ladder_pass(){ GET_COMBODATA_TYPE_INT(ladder_pass); } //byte s
	static void getComboData_lock_block_type(){ GET_COMBODATA_TYPE_INT(lock_block_type); } //byte t
	static void getComboData_lock_block_change(){ GET_COMBODATA_TYPE_INT(lock_block_change); } //long u
	static void getComboData_magic_mirror_type(){ GET_COMBODATA_TYPE_INT(magic_mirror_type); } //byte v
	static void getComboData_modify_hp_amount(){ GET_COMBODATA_TYPE_INT(modify_hp_amount); } //short w
	static void getComboData_modify_hp_delay(){ GET_COMBODATA_TYPE_INT(modify_hp_delay); } //byte x
	static void getComboData_modify_hp_type(){ GET_COMBODATA_TYPE_INT(modify_hp_type); } //byte y
	static void getComboData_modify_mp_amount(){ GET_COMBODATA_TYPE_INT(modify_mp_amount); } //short z
	static void getComboData_modify_mp_delay(){ GET_COMBODATA_TYPE_INT(modify_mp_delay); } //byte aa
	static void getComboData_modify_mp_type(){ GET_COMBODATA_TYPE_INT(modify_mp_type); } //byte ab
	static void getComboData_no_push_blocks(){ GET_COMBODATA_TYPE_INT(no_push_blocks); } //byte ac
	static void getComboData_overhead(){ GET_COMBODATA_TYPE_INT(overhead); } //byte ad
	static void getComboData_place_enemy(){ GET_COMBODATA_TYPE_INT(place_enemy); } //byte ae
	static void getComboData_push_direction(){ GET_COMBODATA_TYPE_INT(push_direction); } //byte af
	static void getComboData_push_weight(){ GET_COMBODATA_TYPE_INT(push_weight); } //byte ag  heavy or not
	static void getComboData_push_wait(){ GET_COMBODATA_TYPE_INT(push_wait); } //byte ah
	static void getComboData_pushed(){ GET_COMBODATA_TYPE_INT(pushed); } //byte ai
	static void getComboData_raft(){ GET_COMBODATA_TYPE_INT(raft); } //byte aj
	static void getComboData_reset_room(){ GET_COMBODATA_TYPE_INT(reset_room); } //byte ak
	static void getComboData_save_point_type(){ GET_COMBODATA_TYPE_INT(save_point_type); } //byte al
	static void getComboData_screen_freeze_type(){ GET_COMBODATA_TYPE_INT(screen_freeze_type); } //byte am

	static void getComboData_secret_combo(){ GET_COMBODATA_TYPE_INT(secret_combo); } //byte an
	static void getComboData_singular(){ GET_COMBODATA_TYPE_INT(singular); } //byte ao
	static void getComboData_slow_movement(){ GET_COMBODATA_TYPE_INT(slow_movement); } //byte ap
	static void getComboData_statue_type(){ GET_COMBODATA_TYPE_INT(statue_type); } //byte aq
	static void getComboData_step_type(){ GET_COMBODATA_TYPE_INT(step_type); } //byte ar
	static void getComboData_step_change_to(){ GET_COMBODATA_TYPE_INT(step_change_to); } //long as
	static void getComboData_strike_remnants(){ GET_COMBODATA_TYPE_INT(strike_remnants); } //long au
	static void getComboData_strike_remnants_type(){ GET_COMBODATA_TYPE_INT(strike_remnants_type); } //byte av
	static void getComboData_strike_change(){ GET_COMBODATA_TYPE_INT(strike_change); } //long aw
	static void getComboData_strike_item(){ GET_COMBODATA_TYPE_INT(strike_item); } //short ax
	static void getComboData_touch_item(){ GET_COMBODATA_TYPE_INT(touch_item); } //short ay
	static void getComboData_touch_stairs(){ GET_COMBODATA_TYPE_INT(touch_stairs); } //byte az
	static void getComboData_trigger_type(){ GET_COMBODATA_TYPE_INT(trigger_type); } //byte ba
	static void getComboData_trigger_sensitive(){ GET_COMBODATA_TYPE_INT(trigger_sensitive); } //byte bb
	static void getComboData_warp_type(){ GET_COMBODATA_TYPE_INT(warp_type); } //byte bc
	static void getComboData_warp_sensitive(){ GET_COMBODATA_TYPE_INT(warp_sensitive); } //byte bd
	static void getComboData_warp_direct(){ GET_COMBODATA_TYPE_INT(warp_direct); } //byte be
	static void getComboData_warp_location(){ GET_COMBODATA_TYPE_INT(warp_location); } //byte bf
	static void getComboData_water(){ GET_COMBODATA_TYPE_INT(water); } //byte bg
	static void getComboData_whistle(){ GET_COMBODATA_TYPE_INT(whistle); } //byte bh
	static void getComboData_win_game(){ GET_COMBODATA_TYPE_INT(win_game); } //byte bi
	static void getComboData_block_weapon_lvl(){ GET_COMBODATA_TYPE_INT(block_weapon_lvl); } //byte bj - max level of weapon to block

	static void getComboData_tile(){ GET_COMBODATA_VAR_INT(tile); } //newcombo, word
	static void getComboData_flip(){ GET_COMBODATA_VAR_INT(flip); } //newcombo byte

	static void getComboData_walk(){ GET_COMBODATA_VAR_INT(walk); } //newcombo byte
	static void getComboData_type(){ GET_COMBODATA_VAR_INT(type); } //newcombo byte
	static void getComboData_csets(){ GET_COMBODATA_VAR_INT(csets); } //newcombo byte
	static void getComboData_foo(){ GET_COMBODATA_VAR_INT(foo); } //newcombo word
	static void getComboData_frames(){ GET_COMBODATA_VAR_INT(frames); } //newcombo byte
	static void getComboData_speed(){ GET_COMBODATA_VAR_INT(speed); } //newcombo byte
	static void getComboData_nextcombo(){ GET_COMBODATA_VAR_INT(nextcombo); } //newcombo word
	static void getComboData_nextcset(){ GET_COMBODATA_VAR_INT(nextcset); } //newcombo byte
	static void getComboData_flag(){ GET_COMBODATA_VAR_INT(flag); } //newcombo byte
	static void getComboData_skipanim(){ GET_COMBODATA_VAR_INT(skipanim); } //newcombo byte
	static void getComboData_nexttimer(){ GET_COMBODATA_VAR_INT(nexttimer); } //newcombo word
	static void getComboData_skipanimy(){ GET_COMBODATA_VAR_INT(skipanimy); } //newcombo byte
	static void getComboData_animflags(){ GET_COMBODATA_VAR_INT(animflags); } //newcombo byte


	//two inputs, one return
	static void getComboData_block_weapon(){ GET_COMBODATA_TYPE_INDEX(block_weapon); } //byte array[32] d (ID of LWeapon)
	static void getComboData_expansion(){ GET_COMBODATA_VAR_INDEX(expansion); } //newcombo byte, arr[6]
	static void getComboData_strike_weapons(){ GET_COMBODATA_TYPE_INDEX(strike_weapons); } //byte at, arr[32]

	//Setters, two inputs no returns

	static void setComboData_block_enemies(){ SET_COMBODATA_TYPE_INT(block_enemies); } //byte a
	static void setComboData_block_hole(){ SET_COMBODATA_TYPE_INT(block_hole); } //byte b
	static void setComboData_block_trigger(){ SET_COMBODATA_TYPE_INT(block_trigger); } //byte c
	static void setComboData_conveyor_x_speed(){ SET_COMBODATA_TYPE_INT(conveyor_x_speed); } //short e
	static void setComboData_conveyor_y_speed(){ SET_COMBODATA_TYPE_INT(conveyor_y_speed); } //short f
	static void setComboData_create_enemy(){ SET_COMBODATA_TYPE_INT(create_enemy); } //word g
	static void setComboData_create_enemy_when(){ SET_COMBODATA_TYPE_INT(create_enemy_when); } //byte h
	static void setComboData_create_enemy_change(){ SET_COMBODATA_TYPE_INT(create_enemy_change); } //long i
	static void setComboData_directional_change_type(){ SET_COMBODATA_TYPE_INT(directional_change_type); } //byte j
	static void setComboData_distance_change_tiles(){ SET_COMBODATA_TYPE_INT(distance_change_tiles); } //long k
	static void setComboData_dive_item(){ SET_COMBODATA_TYPE_INT(dive_item); } //short l
	static void setComboData_dock(){ SET_COMBODATA_TYPE_INT(dock); } //byte m
	static void setComboData_fairy(){ SET_COMBODATA_TYPE_INT(fairy); } //byte n
	static void setComboData_ff_combo_attr_change(){ SET_COMBODATA_TYPE_INT(ff_combo_attr_change); } //byte o
	static void setComboData_foot_decorations_tile(){ SET_COMBODATA_TYPE_INT(foot_decorations_tile); } //long p
	static void setComboData_foot_decorations_type(){ SET_COMBODATA_TYPE_INT(foot_decorations_type); } //byte q
	static void setComboData_hookshot_grab_point(){ SET_COMBODATA_TYPE_INT(hookshot_grab_point); } //byte r
	static void setComboData_ladder_pass(){ SET_COMBODATA_TYPE_INT(ladder_pass); } //byte s
	static void setComboData_lock_block_type(){ SET_COMBODATA_TYPE_INT(lock_block_type); } //byte t
	static void setComboData_lock_block_change(){ SET_COMBODATA_TYPE_INT(lock_block_change); } //long u
	static void setComboData_magic_mirror_type(){ SET_COMBODATA_TYPE_INT(magic_mirror_type); } //byte v
	static void setComboData_modify_hp_amount(){ SET_COMBODATA_TYPE_INT(modify_hp_amount); } //short w
	static void setComboData_modify_hp_delay(){ SET_COMBODATA_TYPE_INT(modify_hp_delay); } //byte x
	static void setComboData_modify_hp_type(){ SET_COMBODATA_TYPE_INT(modify_hp_type); } //byte y
	static void setComboData_modify_mp_amount(){ SET_COMBODATA_TYPE_INT(modify_mp_amount); } //short z
	static void setComboData_modify_mp_delay(){ SET_COMBODATA_TYPE_INT(modify_mp_delay); } //byte aa
	static void setComboData_modify_mp_type(){ SET_COMBODATA_TYPE_INT(modify_mp_type); } //byte ab
	static void setComboData_no_push_blocks(){ SET_COMBODATA_TYPE_INT(no_push_blocks); } //byte ac
	static void setComboData_overhead(){ SET_COMBODATA_TYPE_INT(overhead); } //byte ad
	static void setComboData_place_enemy(){ SET_COMBODATA_TYPE_INT(place_enemy); } //byte ae
	static void setComboData_push_direction(){ SET_COMBODATA_TYPE_INT(push_direction); } //byte af
	static void setComboData_push_weight(){ SET_COMBODATA_TYPE_INT(push_weight); } //byte ag  heavy or not
	static void setComboData_push_wait(){ SET_COMBODATA_TYPE_INT(push_wait); } //byte ah
	static void setComboData_pushed(){ SET_COMBODATA_TYPE_INT(pushed); } //byte ai
	static void setComboData_raft(){ SET_COMBODATA_TYPE_INT(raft); } //byte aj
	static void setComboData_reset_room(){ SET_COMBODATA_TYPE_INT(reset_room); } //byte ak
	static void setComboData_save_point_type(){ SET_COMBODATA_TYPE_INT(save_point_type); } //byte al
	static void setComboData_screen_freeze_type(){ SET_COMBODATA_TYPE_INT(screen_freeze_type); } //byte am

	static void setComboData_secret_combo(){ SET_COMBODATA_TYPE_INT(secret_combo); } //byte an
	static void setComboData_singular(){ SET_COMBODATA_TYPE_INT(singular); } //byte ao
	static void setComboData_slow_movement(){ SET_COMBODATA_TYPE_INT(slow_movement); } //byte ap
	static void setComboData_statue_type(){ SET_COMBODATA_TYPE_INT(statue_type); } //byte aq
	static void setComboData_step_type(){ SET_COMBODATA_TYPE_INT(step_type); } //byte ar
	static void setComboData_step_change_to(){ SET_COMBODATA_TYPE_INT(step_change_to); } //long as

	static void setComboData_strike_remnants(){ SET_COMBODATA_TYPE_INT(strike_remnants); } //long au
	static void setComboData_strike_remnants_type(){ SET_COMBODATA_TYPE_INT(strike_remnants_type); } //byte av
	static void setComboData_strike_change(){ SET_COMBODATA_TYPE_INT(strike_change); } //long aw
	static void setComboData_strike_item(){ SET_COMBODATA_TYPE_INT(strike_item); } //short ax
	static void setComboData_touch_item(){ SET_COMBODATA_TYPE_INT(touch_item); } //short ay
	static void setComboData_touch_stairs(){ SET_COMBODATA_TYPE_INT(touch_stairs); } //byte az
	static void setComboData_trigger_type(){ SET_COMBODATA_TYPE_INT(trigger_type); } //byte ba
	static void setComboData_trigger_sensitive(){ SET_COMBODATA_TYPE_INT(trigger_sensitive); } //byte bb
	static void setComboData_warp_type(){ SET_COMBODATA_TYPE_INT(warp_type); } //byte bc
	static void setComboData_warp_sensitive(){ SET_COMBODATA_TYPE_INT(warp_sensitive); } //byte bd
	static void setComboData_warp_direct(){ SET_COMBODATA_TYPE_INT(warp_direct); } //byte be
	static void setComboData_warp_location(){ SET_COMBODATA_TYPE_INT(warp_location); } //byte bf
	static void setComboData_water(){ SET_COMBODATA_TYPE_INT(water); } //byte bg
	static void setComboData_whistle(){ SET_COMBODATA_TYPE_INT(whistle); } //byte bh
	static void setComboData_win_game(){ SET_COMBODATA_TYPE_INT(win_game); } //byte bi
	static void setComboData_block_weapon_lvl(){ SET_COMBODATA_TYPE_INT(block_weapon_lvl); } //byte bj - max level of weapon to block

	//combosbuf
	static void setComboData_tile(){ SET_COMBODATA_VAR_INT(tile); } //newcombo, word
	static void setComboData_flip(){ SET_COMBODATA_VAR_INT(flip); } //newcombo byte

	static void setComboData_walk(){ SET_COMBODATA_VAR_INT(walk); } //newcombo byte
	static void setComboData_type(){ SET_COMBODATA_VAR_INT(type); } //newcombo byte
	static void setComboData_csets(){ SET_COMBODATA_VAR_INT(csets); } //newcombo byte
	static void setComboData_foo(){ SET_COMBODATA_VAR_INT(foo); } //newcombo word
	static void setComboData_frames(){ SET_COMBODATA_VAR_INT(frames); } //newcombo byte
	static void setComboData_speed(){ SET_COMBODATA_VAR_INT(speed); } //newcombo byte
	static void setComboData_nextcombo(){ SET_COMBODATA_VAR_INT(nextcombo); } //newcombo word
	static void setComboData_nextcset(){ SET_COMBODATA_VAR_INT(nextcset); } //newcombo byte
	static void setComboData_flag(){ SET_COMBODATA_VAR_INT(flag); } //newcombo byte
	static void setComboData_skipanim(){ SET_COMBODATA_VAR_INT(skipanim); } //newcombo byte
	static void setComboData_nexttimer(){ SET_COMBODATA_VAR_INT(nexttimer); } //newcombo word
	static void setComboData_skipanimy(){ SET_COMBODATA_VAR_INT(skipanimy); } //newcombo byte
	static void setComboData_animflags(){ SET_COMBODATA_VAR_INT(animflags); } //newcombo byte

	//three inputs, no returns
	static void setComboData_block_weapon(){ SET_COMBODATA_TYPE_INDEX(block_weapon); } //byte array[32] d (ID of LWeapon)
	static void setComboData_strike_weapons(){ SET_COMBODATA_TYPE_INDEX(strike_weapons); } //byte at, arr[32]
	static void setComboData_expansion(){ SET_COMBODATA_VAR_INDEX(expansion); } //newcombo byte, arr[6]



#define INVALIDARRAY localRAM[0]  //localRAM[0] is never used

enum __Error
    {
        _NoError, //OK!
        _Overflow, //script array too small
        _InvalidPointer, //passed NULL pointer or similar
        _OutOfBounds, //library array out of bounds
        _InvalidSpriteUID //bad npc, ffc, etc.
    };
    
    
    static INLINE int checkUserArrayIndex(const long index, const dword size)
    {
        if(index < 0 || index >= long(size))
        {
          //  Z_scripterrlog("Invalid index (%ld) to local array of size %ld\n", index, size);
            return _OutOfBounds;
        }
        
        return _NoError;
    }

    
    
    //only if the player is messing with their pointers...
    static ZScriptArray& InvalidError(const long ptr)
    {
        //Z_scripterrlog("Invalid pointer (%i) passed to array (don't change the values of your array pointers)\n", ptr);
        return INVALIDARRAY;
    }
    
    //Returns a reference to the correct array based on pointer passed
    static ZScriptArray& getArray(const long ptr)
    {
        if(ptr <= 0)
            return InvalidError(ptr);
            
        if(ptr >= MAX_ZCARRAY_SIZE) //Then it's a global
        {
            dword gptr = ptr - MAX_ZCARRAY_SIZE;
            
            if(gptr > game->globalRAM.size())
                return InvalidError(ptr);
                
            return game->globalRAM[gptr];
        }
        else
        {
            if(localRAM[ptr].Size() == 0)
                return InvalidError(ptr);
                
            return localRAM[ptr];
        }
    }
    
    static size_t getSize(const long ptr)
    {
        ZScriptArray& a = getArray(ptr);
        
        if(a == INVALIDARRAY)
            return size_t(-1);
            
        return a.Size();
    }
    
    //Can't you get the std::string and then check its length?
    static int strlen(const long ptr)
    {
        ZScriptArray& a = getArray(ptr);
        
        if(a == INVALIDARRAY)
            return -1;
            
        word count;
        
        for(count = 0; checkUserArrayIndex(count, a.Size()) == _NoError && a[count] != '\0'; count++) ;
        
        return count;
    }
    
    //Returns values of a zscript array as an std::string.
    static void getString(const long ptr, std::string &str, word num_chars = 256)
    {
        ZScriptArray& a = getArray(ptr);
        
        if(a == INVALIDARRAY)
        {
            str.clear();
            return;
        }
        
        str.clear();
        
        for(word i = 0; checkUserArrayIndex(i, a.Size()) == _NoError && a[i] != '\0' && num_chars != 0; i++)
        {
            str += char(a[i] / 10000);
            num_chars--;
        }
    }
    
    //Like getString but for an array of longs instead of chars. *(arrayPtr is not checked for validity)
    static void getValues(const long ptr, long* arrayPtr, word num_values)
    {
        ZScriptArray& a = getArray(ptr);
        
        if(a == INVALIDARRAY)
            return;
            
        for(word i = 0; checkUserArrayIndex(i, a.Size()) == _NoError && num_values != 0; i++)
        {
            arrayPtr[i] = (a[i] / 10000);
            num_values--;
        }
    }
    
    //Get element from array
    static INLINE long getElement(const long ptr, const long offset)
    {
        ZScriptArray& a = getArray(ptr);
        
        if(a == INVALIDARRAY)
            return -10000;
            
        if(checkUserArrayIndex(offset, a.Size()) == _NoError)
            return a[offset];
        else
            return -10000;
    }
    
    //Set element in array
    static INLINE void setElement(const long ptr, const long offset, const long value)
    {
        ZScriptArray& a = getArray(ptr);
        
        if(a == INVALIDARRAY)
            return;
            
        if(checkUserArrayIndex(offset, a.Size()) == _NoError)
            a[offset] = value;
    }
    
    //Puts values of a zscript array into a client <type> array. returns 0 on success. Overloaded
    template <typename T>
    static int getArray(const long ptr, T *refArray)
    {
        return getArray(ptr, getArray(ptr).Size(), 0, 0, 0, refArray);
    }
    
    template <typename T>
    static int getArray(const long ptr, const word size, T *refArray)
    {
        return getArray(ptr, size, 0, 0, 0, refArray);
    }
    
    template <typename T>
    static int getArray(const long ptr, const word size, word userOffset, const word userStride, const word refArrayOffset, T *refArray)
    {
        ZScriptArray& a = getArray(ptr);
        
        if(a == INVALIDARRAY)
            return _InvalidPointer;
            
        word j = 0, k = userStride;
        
        for(word i = 0; j < size; i++)
        {
            if(i >= a.Size())
                return _Overflow;
                
            if(userOffset-- > 0)
                continue;
                
            if(k > 0)
                k--;
            else if (checkUserArrayIndex(i, a.Size()) == _NoError)
            {
                refArray[j + refArrayOffset] = T(a[i]);
                k = userStride;
                j++;
            }
        }
        
        return _NoError;
    }
    
    
    static int setArray(const long ptr, const std::string s2)
    {
        ZScriptArray& a = getArray(ptr);
        
        if(a == INVALIDARRAY)
            return _InvalidPointer;
            
        word i;
        
        for(i = 0; i < s2.size(); i++)
        {
            if(i >= a.Size())
            {
                a.Back() = '\0';
                return _Overflow;
            }
            
            if(checkUserArrayIndex(i, a.Size()) == _NoError)
                a[i] = s2[i] * 10000;
        }
        
        if(checkUserArrayIndex(i, a.Size()) == _NoError)
            a[i] = '\0';
            
        return _NoError;
    }
    
    
    //Puts values of a client <type> array into a zscript array. returns 0 on success. Overloaded
    template <typename T>
    static int setArray(const long ptr, const word size, T *refArray)
    {
        return setArray(ptr, size, 0, 0, 0, refArray);
    }
    
    template <typename T>
    static int setArray(const long ptr, const word size, word userOffset, const word userStride, const word refArrayOffset, T *refArray)
    {
        ZScriptArray& a = getArray(ptr);
        
        if(a == INVALIDARRAY)
            return _InvalidPointer;
            
        word j = 0, k = userStride;
        
        for(word i = 0; j < size; i++)
        {
            if(i >= a.Size())
                return _Overflow; //Resize?
                
            if(userOffset-- > 0)
                continue;
                
            if(k > 0)
                k--;
            else if(checkUserArrayIndex(i, a.Size()) == _NoError)
            {
                a[i] = long(refArray[j + refArrayOffset]) * 10000;
                k = userStride;
                j++;
            }
        }
        
        return _NoError;
    }
    
    
  
    
};



extern long ffmisc[32][16];
extern refInfo ffcScriptData[32];

extern PALETTE tempgreypal; //script greyscale

long get_register(const long arg);
int run_script(const byte type, const word script, const byte i = -1); //Global scripts don't need 'i'
int ffscript_engine(const bool preload);

void clear_ffc_stack(const byte i);
void clear_global_stack();
void deallocateArray(const long ptrval);
void clearScriptHelperData();


void do_getscreenflags();
void do_getscreeneflags();
long get_screendoor(mapscr *m, int d);
long get_screenlayeropacity(mapscr *m, int d);
long get_screensecretcombo(mapscr *m, int d);
long get_screensecretcset(mapscr *m, int d);
long get_screensecretflag(mapscr *m, int d);
long get_screenlayermap(mapscr *m, int d);
long get_screenlayerscreen(mapscr *m, int d);
long get_screenpath(mapscr *m, int d);
long get_screenwarpReturnX(mapscr *m, int d);
long get_screenwarpReturnY(mapscr *m, int d);

long get_screenViewX(mapscr *m);
long get_screenGuy(mapscr *m);
long get_screenString(mapscr *m);
long get_screenRoomtype(mapscr *m);
long get_screenViewY(mapscr *m);
long get_screenEntryX(mapscr *m);
long get_screenEntryY(mapscr *m);
long get_screenitem(mapscr *m);
long get_screenundercombo(mapscr *m);
long get_screenundercset(mapscr *m);
long get_screenatchall(mapscr *m);
void do_getscreenLayerOpacity();
void do_getscreenSecretCombo();
void do_getscreenSecretCSet();
void do_getscreenSecretFlag();
void do_getscreenLayerMap();
void do_getscreenLayerscreen();
void do_getscreenPath();
void do_getscreenWarpReturnX();
void do_getscreenWarpReturnY();
void do_getscreenatchall();
void do_getscreenUndercombo();
void do_getscreenUnderCSet();
void do_getscreenWidth();
void do_getscreenHeight();
void do_getscreenViewX();
void do_getscreenGuy();
void do_getscreenString();
void do_getscreenRoomType();
void do_getscreenEntryX();
void do_getscreenEntryY();
void do_getscreenItem();
void do_getscreendoor();
long get_screennpc(mapscr *m, int index);
void do_getscreennpc();

// Defines for script flags
#define TRUEFLAG          0x0001
#define MOREFLAG          0x0002
#define TRIGGERED         0x0004

//What are these for exactly?
//#define fflong(x,y,z)       (((x[(y)][(z)])<<24)+((x[(y)][(z)+1])<<16)+((x[(y)][(z)+2])<<8)+(x[(y)][(z)+3]))
//#define ffword(x,y,z)       (((x[(y)][(z)])<<8)+(x[(y)][(z)+1]))

struct quad3Dstruct
{
    int index;
    float pos[12], uv[8];
    int size[2], color[4];
};

struct triangle3Dstruct
{
    int index;
    float pos[9], uv[6];
    int size[2], color[3];
};

#endif
