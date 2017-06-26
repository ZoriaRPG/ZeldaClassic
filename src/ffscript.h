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
