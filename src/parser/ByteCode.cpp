
#include "../precompiled.h" //always first

#include "ByteCode.h"
#include "DataStructs.h"
#include "ParseError.h"
#include "../zsyssimple.h"
#include <assert.h>
#include <iostream>
#include <cstdlib>

string LiteralArgument::toString()
{
    char temp[40];
    string sign = value < 0 ? "-" : "";
    sprintf(temp,"%ld", abs(value)/10000);
    string first = string(temp);
    
    if(value % 10000 == 0)
        return sign + first;
        
    sprintf(temp,"%ld", abs(value)%10000);
    string second = string(temp);
    
    while(second.length() < 4)
        second = "0" + second;
        
    return sign + first + "." + second;
}

string VarArgument::toString()
{
    char temp[40];
    
    switch(ID)
    {
    case SP:
        return "SP";
        
    case DATA:
        return "DATA";
        
    case FFSCRIPT:
        return "FFSCRIPT";
        
    case FCSET:
        return "CSET";
        
    case DELAY:
        return "DELAY";
        
    case FX:
        return "X";
    case FFCID:
	return "FFCID";
        
    case FY:
        return "Y";
        
    case XD:
        return "XD";
        
    case YD:
        return "YD";
        
    case XD2:
        return "XD2";
        
    case YD2:
        return "YD2";
        
    case LINKX:
        return "LINKX";
        
    case LINKY:
        return "LINKY";
        
    case LINKZ:
        return "LINKZ";
        
    case LINKJUMP:
        return "LINKJUMP";
        
    case LINKDIR:
        return "LINKDIR";
        
    case LINKHITDIR:
        return "LINKHITDIR";
        
    case LINKSWORDJINX:
        return "LINKSWORDJINX";
        
    case LINKITEMJINX:
        return "LINKITEMJINX";
        
    case LINKHP:
        return "LINKHP";
        
    case LINKMP:
        return "LINKMP";
        
    case LINKMAXHP:
        return "LINKMAXHP";
        
    case LINKMAXMP:
        return "LINKMAXMP";
        
    case LINKACTION:
        return "LINKACTION";
        
    case LINKHELD:
        return "LINKHELD";
        
    case LINKINVIS:
        return "LINKINVIS";
        
    case LINKINVINC:
        return "LINKINVINC";
        
    case LINKMISCD:
        return "LINKMISCD";
        
    case LINKTILE:
        return "LINKTILE";
        
    case LINKFLIP:
        return "LINKFLIP";
        
    case INPUTSTART:
        return "INPUTSTART";
        
    case INPUTMAP:
        return "INPUTMAP";
        
    case INPUTUP:
        return "INPUTUP";
        
    case INPUTDOWN:
        return "INPUTDOWN";
        
    case INPUTLEFT:
        return "INPUTLEFT";
        
    case INPUTRIGHT:
        return "INPUTRIGHT";
        
    case INPUTA:
        return "INPUTA";
        
    case INPUTB:
        return "INPUTB";
        
    case INPUTL:
        return "INPUTL";
        
    case INPUTR:
        return "INPUTR";
        
    case INPUTEX1:
        return "INPUTEX1";
        
    case INPUTEX2:
        return "INPUTEX2";
        
    case INPUTEX3:
        return "INPUTEX3";
        
    case INPUTEX4:
        return "INPUTEX4";
        
    case INPUTAXISUP:
        return "INPUTAXISUP";
        
    case INPUTAXISDOWN:
        return "INPUTAXISDOWN";
        
    case INPUTAXISLEFT:
        return "INPUTAXISLEFT";
        
    case INPUTAXISRIGHT:
        return "INPUTAXISRIGHT";
        
    case INPUTPRESSSTART:
        return "INPUTPRESSSTART";
        
    case INPUTPRESSMAP:
        return "INPUTPRESSMAP";
        
    case INPUTPRESSUP:
        return "INPUTPRESSUP";
        
    case INPUTPRESSDOWN:
        return "INPUTPRESSDOWN";
        
    case INPUTPRESSLEFT:
        return "INPUTPRESSLEFT";
        
    case INPUTPRESSRIGHT:
        return "INPUTPRESSRIGHT";
        
    case INPUTPRESSA:
        return "INPUTPRESSA";
        
    case INPUTPRESSB:
        return "INPUTPRESSB";
        
    case INPUTPRESSL:
        return "INPUTPRESSL";
        
    case INPUTPRESSR:
        return "INPUTPRESSR";
        
    case INPUTPRESSEX1:
        return "INPUTPRESSEX1";
        
    case INPUTPRESSEX2:
        return "INPUTPRESSEX2";
        
    case INPUTPRESSEX3:
        return "INPUTPRESSEX3";
        
    case INPUTPRESSEX4:
        return "INPUTPRESSEX4";
        
    case INPUTPRESSAXISUP:
        return "PRESSAXISUP";
        
    case INPUTPRESSAXISDOWN:
        return "PRESSAXISDOWN";
        
    case INPUTPRESSAXISLEFT:
        return "PRESSAXISLEFT";
        
    case INPUTPRESSAXISRIGHT:
        return "PRESSAXISRIGHT";
        
    case INPUTMOUSEX:
        return "INPUTMOUSEX";
        
    case INPUTMOUSEY:
        return "INPUTMOUSEY";
        
    case INPUTMOUSEZ:
        return "INPUTMOUSEZ";
        
    case INPUTMOUSEB:
        return "INPUTMOUSEB";
    
    case BUTTONPRESS: return "BUTTONPRESS";
    case BUTTONINPUT: return "BUTTONINPUT";
    case BUTTONHELD: return "BUTTONHELD";
    case KEYPRESS: return "KEYPRESS";
    case READKEY: return "READKEY";
    case JOYPADPRESS: return "JOYPADPRESS";
    
     case LINKINVFRAME:
	return "LINKINVFRAME";
    case LINKCANFLICKER:
	return "LINKCANFLICKER";
    case LINKHURTSFX:
	return "LINKHURTSFX";
    
    case LINKEATEN: return "LINKEATEN";
    
    case LINKITEMB: return "LINKITEMB";

    case LINKITEMA: return "LINKITEMA";
    case SETITEMSLOT: return "SETITEMSLOT";
    case GAMESETB: return "GAMESETB";
    case GAMESETA: return "GAMESETA";
    case LINKUSINGITEM: return "LINKUSINGITEM";
    case LINKUSINGITEMA: return "LINKUSINGITEMA";
    case LINKUSINGITEMB: return "LINKUSINGITEMB";
    
    case SDD:
        return "SDD";
        
    case SCREENFLAGSD:
        return "SCREENFLAGSD";
        
    case SCREENEFLAGSD:
        return "SCREENEFLAGSD";
        
    case COMBODD:
        return "COMBODD";
        
    case COMBOCD:
        return "COMBOCD";
        
    case COMBOFD:
        return "COMBOFD";
        
    case COMBODDM:
        return "COMBODDM";
        
    case COMBOCDM:
        return "COMBOCDM";
        
    case COMBOFDM:
        return "COMBOFDM";
        
    case REFFFC:
        return "REFFFC";
        
    case REFITEM:
        return "REFITEM";
        
    case ITEMCOUNT:
        return "ITEMCOUNT";
        
    case ITEMX:
        return "ITEMX";
        
    case ITEMY:
        return "ITEMY";
        
    case ITEMZ:
        return "ITEMZ";
        
    case ITEMJUMP:
        return "ITEMJUMP";
        
    case ITEMDRAWTYPE:
        return "ITEMDRAWTYPE";
        
    case ITEMID:
        return "ITEMID";
        
    case ITEMTILE:
        return "ITEMTILE";
        
    case ITEMCSET:
        return "ITEMCSET";
        
    case ITEMFLASHCSET:
        return "ITEMFLASHCSET";
        
    case ITEMFRAMES:
        return "ITEMFRAMES";
        
    //This DOES NOT DO what ZScript.txt claims that it does, and needs to be fixed. -Z
    case ITEMFRAME:
        return "ITEMFRAME";
        
    case ITEMASPEED:
        return "ITEMASPEED";
        
    case ITEMDELAY:
        return "ITEMDELAY";
        
    case ITEMFLASH:
        return "ITEMFLASH";
        
    case ITEMFLIP:
        return "ITEMFLIP";
        
    case ITEMEXTEND:
        return "ITEMEXTEND";
        
    case ITEMPICKUP:
        return "ITEMPICKUP";
        
    case ITEMMISCD:
        return "ITEMMISCD";
        
    case ITEMCLASSFAMILY:
        return "IDATAFAMILY";
        
    case ITEMCLASSFAMTYPE:
        return "IDATALEVEL";
        
    case ITEMCLASSAMOUNT:
        return "IDATAAMOUNT";
        
    case ITEMCLASSMAX:
        return "IDATAMAX";
        
    case ITEMCLASSSETMAX:
        return "IDATASETMAX";
        
    case ITEMCLASSSETGAME:
        return "IDATAKEEP";
        
    case ITEMCLASSCOUNTER:
        return "IDATACOUNTER";
        
    case ITEMCLASSUSESOUND:
        return "IDATAUSESOUND";
        
    case ITEMCLASSPOWER:
        return "IDATAPOWER";
        
    case ITEMCLASSINITDD:
        return "IDATAINITDD";
        
    case REFITEMCLASS:
        return "REFITEMCLASS";
        
    case COMBOID:
        return "COMBOID";
        
    case COMBOTD:
        return "COMBOTD";
        
    case COMBOSD:
        return "COMBOSD";
        
    case COMBOIDM:
        return "COMBOIDM";
        
    case COMBOTDM:
        return "COMBOTDM";
        
    case COMBOSDM:
        return "COMBOSDM";
        
    case GETMIDI:
        return "GETMIDI";
        
    case CURSCR:
        return "CURSCR";
        
    case CURDSCR:
        return "CURDSCR";
        
    case CURMAP:
        return "CURMAP";
        
    case CURDMAP:
        return "CURDMAP";
    case GAMEMAXMAPS: return "GAMEMAXMAPS";
        
    case CURLEVEL:
        return "CURLEVEL";
        
    case GAMEDEATHS:
        return "GAMEDEATHS";
        
    case GAMECHEAT:
        return "GAMECHEAT";
    
    case ZELDAVERSION:
	return "ZELDAVERSION";
    case ZELDABUILD:
	return "ZELDABUILD";
    case ZELDABETA:
	return "ZELDABETA";
    
        
    case GAMETIME:
        return "GAMETIME";
        
    case GAMEHASPLAYED:
        return "GAMEHASPLAYED";
        
    case GAMESTANDALONE:
        return "GAMESTANDALONE";
        
    case GAMETIMEVALID:
        return "GAMETIMEVALID";
        
    case GAMEGUYCOUNT:
        return "GAMEGUYCOUNT";
        
    case GAMECONTSCR:
        return "GAMECONTSCR";
        
    case GAMECONTDMAP:
        return "GAMECONTDMAP";
        
    case GAMEENTRSCR:
        return "GAMEENTRSCR";
        
    case GAMEENTRDMAP:
        return "GAMEENTRDMAP";
        
    case GAMECOUNTERD:
        return "GAMECOUNTERD";
        
    case GAMEMCOUNTERD:
        return "GAMEMCOUNTERD";
        
    case GAMEDCOUNTERD:
        return "GAMEDCOUNTERD";
        
    case GAMEGENERICD:
        return "GAMEGENERICD";
        
    case GAMEITEMSD:
        return "GAMEITEMSD";
        
    case GAMELITEMSD:
        return "GAMELITEMSD";
        
    case GAMELKEYSD:
        return "GAMELKEYSD";
        
    case SCREENSTATED:
        return "SCREENSTATED";
        
    case SCREENSTATEDD:
        return "SCREENSTATEDD";
        
    case DMAPFLAGSD:
        return "DMAPFLAGSD";
        
    case DMAPLEVELD:
        return "DMAPLEVELD";
    
    case DMAPLEVELPAL:
	return "DMAPLEVELPAL";
        
    case DMAPCOMPASSD:
        return "DMAPCOMPASSD";
        
    case DMAPCONTINUED:
        return "DMAPCONTINUED";
        
    case DMAPMIDID:
        return "DMAPMIDID";
        
    case DMAPOFFSET:
        return "DMAPOFFSET";
        
    case DMAPMAP:
        return "DMAPMAP";
        
    case SDDD:
        return "SDDD";
        
    case SDDDD:
        return "SDDDD";
        
    case GAMECLICKFREEZE:
        return "GAMECLICKFREEZE";
        
    case NOACTIVESUBSC: return "NOACTIVESUBSC"; //Disable active subscreen.
    
    case FFFLAGSD:
        return "FFFLAGSD";
        
    case FFTWIDTH:
        return "FFTWIDTH";
        
    case FFTHEIGHT:
        return "FFTHEIGHT";
        
    case FFCWIDTH:
        return "FFCWIDTH";
        
    case FFCHEIGHT:
        return "FFCHEIGHT";
        
    case FFLINK:
        return "FFLINK";
        
    case FFMISCD:
        return "FFMISCD";
        
    case FFINITDD:
        return "FFINITDD";
        
        /*case FFDD:
        return "FFDD";*/
    case LINKITEMD:
        return "LINKITEMD";
    
    case DISABLEDITEM: return "DISABLEDITEM";
        
    case REFNPC:
        return "REFNPC";
        
    case NPCCOUNT:
        return "NPCCOUNT";
        
    case NPCX:
        return "NPCX";
        
    case NPCY:
        return "NPCY";
        
    case NPCZ:
        return "NPCZ";
        
    case NPCJUMP:
        return "NPCJUMP";
        
    case NPCDIR:
        return "NPCDIR";
        
    case NPCRATE:
        return "NPCRATE";
        
    case NPCHOMING:
        return "NPCHOMING";
        
    case NPCFRAMERATE:
        return "NPCFRAMERATE";
        
    case NPCHALTRATE:
        return "NPCHALTRATE";
        
    case NPCDRAWTYPE:
        return "NPCDRAWTYPE";
        
    case NPCHP:
        return "NPCHP";
        
    case NPCID:
        return "NPCID";
        
    case NPCTYPE:
        return "NPCTYPE";
        
    case NPCDP:
        return "NPCDP";
        
    case NPCWDP:
        return "NPCWDP";
        
    case NPCTILE:
        return "NPCTILE";
        
    case NPCOTILE:
        return "NPCOTILE";
        
    case NPCWEAPON:
        return "NPCWEAPON";
        
    case NPCITEMSET:
        return "NPCITEMSET";
        
    case NPCCSET:
        return "NPCCSET";
        
    case NPCBOSSPAL:
        return "NPCBOSSPAL";
        
    case NPCBGSFX:
        return "NPCBGSFX";
        
    case NPCEXTEND:
        return "NPCEXTEND";
        
    case NPCSTEP:
        return "NPCSTEP";
        
    case NPCDEFENSED:
        return "NPCDEFENSED";
    case NPCSCRDEFENSED: return "NPCSCRDEFENSED";
        
    case NPCMISCD:
        return "NPCMISCD";
        
    case NPCDD:
        return "NPCDD";
        
    case NPCMFLAGS:
        return "NPCMFLAGS";
        
    case NPCCOLLDET:
        return "NPCCOLLDET";
        
    case NPCSTUN:
        return "NPCSTUN";
        
    case NPCHUNGER:
        return "NPCHUNGER";
    
    
    case NPCINVINC:
        return "NPCINVINC";
    case NPCSUPERMAN:
        return "NPCSUPERMAN";
    case NPCHASITEM:
        return "NPCHASITEM";
    case NPCRINGLEAD:
        return "NPCRINGLEAD";
        
        
    case SCRDOORD:
        return "SCRDOORD";
        
    case LIT:
        return "LIT";
        
    case WAVY:
        return "WAVY";
        
    case QUAKE:
        return "QUAKE";
        
    case ITEMOTILE:
        return "ITEMOTILE";
        
    case REFLWPN:
        return "REFLWPN";
        
    case LWPNCOUNT:
        return "LWPNCOUNT";
        
    case LWPNX:
        return "LWPNX";
        
    case LWPNY:
        return "LWPNY";
        
    case LWPNZ:
        return "LWPNZ";
        
    case LWPNJUMP:
        return "LWPNJUMP";
        
    case LWPNDIR:
        return "LWPNDIR";
        
    case LWPNANGLE:
        return "LWPNANGLE";
        
    case LWPNSTEP:
        return "LWPNSTEP";
        
    case LWPNFRAMES:
        return "LWPNFRAMES";
        
    case LWPNFRAME:
        return "LWPNFRAME";
        
    case LWPNDRAWTYPE:
        return "LWPNDRAWTYPE";
        
    case LWPNPOWER:
        return "LWPNPOWER";
        
    case LWPNID:
        return "LWPNID";
        
    case LWPNANGULAR:
        return "LWPNANGULAR";
        
    case LWPNBEHIND:
        return "LWPNBEHIND";
        
    case LWPNASPEED:
        return "LWPNASPEED";
        
    case LWPNTILE:
        return "LWPNTILE";
        
    case LWPNFLASHCSET:
        return "LWPNFLASHCSET";
        
    case LWPNDEAD:
        return "LWPNDEAD";
        
    case LWPNCSET:
        return "LWPNCSET";
        
    case LWPNFLASH:
        return "LWPNFLASH";
        
    case LWPNFLIP:
        return "LWPNFLIP";
        
    case LWPNOTILE:
        return "LWPNOTILE";
        
    case LWPNOCSET:
        return "LWPNOCSET";
        
    case LWPNEXTEND:
        return "LWPNEXTEND";
        
    case LWPNCOLLDET:
        return "LWPNCOLLDET";
        
    case REFEWPN:
        return "REFEWPN";
        
    case EWPNCOUNT:
        return "EWPNCOUNT";
        
    case EWPNX:
        return "EWPNX";
        
    case EWPNY:
        return "EWPNY";
        
    case EWPNZ:
        return "EWPNZ";
        
    case EWPNJUMP:
        return "EWPNJUMP";
        
    case EWPNDIR:
        return "EWPNDIR";
        
    case EWPNANGLE:
        return "EWPNANGLE";
        
    case EWPNSTEP:
        return "EWPNSTEP";
        
    case EWPNFRAMES:
        return "EWPNFRAMES";
        
    case EWPNFRAME:
        return "EWPNFRAME";
        
    case EWPNDRAWTYPE:
        return "EWPNDRAWTYPE";
        
    case EWPNPOWER:
        return "EWPNPOWER";
        
    case EWPNID:
        return "EWPNID";
        
    case EWPNANGULAR:
        return "EWPNANGULAR";
        
    case EWPNBEHIND:
        return "EWPNBEHIND";
        
    case EWPNASPEED:
        return "EWPNASPEED";
        
    case EWPNTILE:
        return "EWPNTILE";
        
    case EWPNFLASHCSET:
        return "EWPNFLASHCSET";
        
    case EWPNDEAD:
        return "EWPNDEAD";
        
    case EWPNCSET:
        return "EWPNCSET";
        
    case EWPNFLASH:
        return "EWPNFLASH";
        
    case EWPNFLIP:
        return "EWPNFLIP";
        
    case EWPNOTILE:
        return "EWPNOTILE";
        
    case EWPNOCSET:
        return "EWPNOCSET";
        
    case EWPNEXTEND:
        return "EWPNEXTEND";
        
    case EWPNCOLLDET:
        return "EWPNCOLLDET";
        
    case SCRIPTRAM:
        return "SCRIPTRAM";
        
    case GLOBALRAM:
        return "GLOBALRAM";
        
    case SCRIPTRAMD:
        return "SCRIPTRAMD";
        
    case GLOBALRAMD:
        return "GLOBALRAMD";
        
    case LWPNHXOFS:
        return "LWPNHXOFS";
        
    case LWPNHYOFS:
        return "LWPNHYOFS";
        
    case LWPNXOFS:
        return "LWPNXOFS";
        
    case LWPNYOFS:
        return "LWPNYOFS";
        
    case LWPNZOFS:
        return "LWPNZOFS";
        
    case LWPNHXSZ:
        return "LWPNHXSZ";
        
    case LWPNHYSZ:
        return "LWPNHYSZ";
        
    case LWPNHZSZ:
        return "LWPNHZSZ";
        
    case LWPNTXSZ:
        return "LWPNTXSZ";
        
    case LWPNTYSZ:
        return "LWPNTYSZ";
        
    case LWPNMISCD:
        return "LWPNMISCD";
        
    case EWPNHXOFS:
        return "EWPNHXOFS";
        
    case EWPNHYOFS:
        return "EWPNHYOFS";
        
    case EWPNXOFS:
        return "EWPNXOFS";
        
    case EWPNYOFS:
        return "EWPNYOFS";
        
    case EWPNZOFS:
        return "EWPNZOFS";
        
    case EWPNHXSZ:
        return "EWPNHXSZ";
        
    case EWPNHYSZ:
        return "EWPNHYSZ";
        
    case EWPNHZSZ:
        return "EWPNHZSZ";
        
    case EWPNTXSZ:
        return "EWPNTXSZ";
        
    case EWPNTYSZ:
        return "EWPNTYSZ";
        
    case EWPNMISCD:
        return "EWPNMISCD";
        
    case NPCHXOFS:
        return "NPCHXOFS";
        
    case NPCHYOFS:
        return "NPCHYOFS";
        
    case NPCXOFS:
        return "NPCXOFS";
        
    case NPCYOFS:
        return "NPCYOFS";
        
    case NPCZOFS:
        return "NPCZOFS";
        
    case NPCHXSZ:
        return "NPCHXSZ";
        
    case NPCHYSZ:
        return "NPCHYSZ";
        
    case NPCHZSZ:
        return "NPCHZSZ";
        
    case NPCTXSZ:
        return "NPCTXSZ";
        
    case NPCTYSZ:
        return "NPCTYSZ";
        
    case ITEMHXOFS:
        return "ITEMHXOFS";
        
    case ITEMHYOFS:
        return "ITEMHYOFS";
        
    case ITEMXOFS:
        return "ITEMXOFS";
        
    case ITEMYOFS:
        return "ITEMYOFS";
        
    case ITEMZOFS:
        return "ITEMZOFS";
        
    case ITEMHXSZ:
        return "ITEMHXSZ";
        
    case ITEMHYSZ:
        return "ITEMHYSZ";
        
    case ITEMHZSZ:
        return "ITEMHZSZ";
        
    case ITEMTXSZ:
        return "ITEMTXSZ";
        
    case ITEMTYSZ:
        return "ITEMTYSZ";
        
    case LINKHXOFS:
        return "LINKHXOFS";
        
    case LINKHYOFS:
        return "LINKHYOFS";
        
    case LINKXOFS:
        return "LINKXOFS";
        
    case LINKYOFS:
        return "LINKYOFS";
        
    case LINKZOFS:
        return "LINKZOFS";
        
    case LINKHXSZ:
        return "LINKHXSZ";
        
    case LINKHYSZ:
        return "LINKHYSZ";
        
    case LINKHZSZ:
        return "LINKHZSZ";
        
    case LINKTXSZ:
        return "LINKTXSZ";
        
    case LINKTYSZ:
        return "LINKTYSZ";
        
    case LINKDRUNK:
        return "LINKDRUNK";
        
    case LINKEQUIP:
        return "LINKEQUIP";
        
    case LINKLADDERX:
        return "LINKLADDERX";
        
    case LINKLADDERY:
        return "LINKLADDERY";
        
    case ROOMTYPE:
        return "ROOMTYPE";
        
    case ROOMDATA:
        return "ROOMDATA";
        
    case PUSHBLOCKX:
        return "PUSHBLOCKX";
        
    case PUSHBLOCKY:
        return "PUSHBLOCKY";
        
    case PUSHBLOCKCOMBO:
        return "PUSHBLOCKCOMBO";
        
    case PUSHBLOCKCSET:
        return "PUSHBLOCKCSET";
        
    case UNDERCOMBO:
        return "UNDERCOMBO";
        
    case UNDERCSET:
        return "UNDERCSET";
    
    //2.6
    case CREATELWPNDX: return "CREATELWPNDX";
    
    //2.54 -Z
/* 2.54 Implemented
    */
    
    
//itemclass / itemdata

    //case IDATAFRAME: return "IDATAFRAME";
    case ITEMCLASSID: return "IDATAID";
    case IDATALTM: return "IDATALTM";
    case IDATAPSCRIPT: return "IDATAPSCRIPT";
    case IDATASCRIPT: return "IDATASCRIPT";
    case IDATAMAGCOST: return "IDATAMAGCOST";
    case IDATAMINHEARTS: return "IDATAMINHEARTS";
    case IDATATILE: return "IDATATILE";
    case IDATAMISC: return "IDATAMISC";    
    case IDATACSET: return "IDATACSET";
    case IDATAFRAMES: return "IDATAFRAMES";
    case IDATAASPEED: return "IDATAASPEED";
    case IDATADELAY: return "IDATADELAY"; 
    case IDATACOMBINE: return "IDATACOMBINE";
    case IDATADOWNGRADE: return "IDATADOWNGRADE";
    case IDATAKEEPOLD: return "IDATAKEEPOLD";
    case IDATARUPEECOST: return "IDATARUPEECOST";
    case IDATAEDIBLE: return "IDATAEDIBLE";
    case IDATAFLAGUNUSED: return "IDATAFLAGUNUSED";
    case IDATAGAINLOWER: return "IDATAGAINLOWER";
    
    //idata arrays
    case IDATAATTRIB: return "IDATAATTRIB";
    case IDATAFLAGS: return "IDATAFLAGS";
    case IDATASPRITE: return "IDATASPRITE";
        
    case IDATAUSEWPN: return "IDATAUSEWPN";
    case IDATAUSEDEF: return "IDATAUSEDEF";
    case IDATAWRANGE: return "IDATAWRANGE";
    case IDATAUSEMVT: return "IDATAUSEMVT";
    case IDATADURATION: return "IDATADURATION";
    case IDATADUPLICATES: return "IDATADUPLICATES";
    case IDATADRAWLAYER: return "IDATADRAWLAYER";
    case IDATACOLLECTFLAGS: return "IDATACOLLECTFLAGS";
    case IDATAWEAPONSCRIPT: return "IDATAWEAPONSCRIPT";
    case IDATAMISCD: return "IDATAMISCD";
    case IDATAWEAPHXOFS: return "IDATAWEAPHXOFS";
    case IDATAWEAPHYOFS: return "IDATAWEAPHYOFS";
    case IDATAWEAPHYSZ: return "IDATAWEAPHYSZ";
    case IDATAWEAPHXSZ: return "IDATAWEAPHXSZ";
    case IDATAWEAPHZSZ: return "IDATAWEAPHZSZ";
    case IDATAWEAPXOFS: return "IDATAWEAPXOFS";
    case IDATAWEAPYOFS: return "IDATAWEAPYOFS";
    case IDATAWEAPZOFS: return "IDATAWEAPZOFS";
    case IDATAWPNINITD: return "IDATAWPNINITD";
    
    case NPCWEAPSPRITE: return "NPCWEAPSPRITE";
    
    //Debug->
    
    case DEBUGREFFFC: return "DEBUGREFFFC";
    case DEBUGREFITEM: return "DEBUGREFITEM";
    case DEBUGREFNPC: return "DEBUGREFNPC";
    case DEBUGREFITEMDATA: return "DEBUGREFITEMDATA";
    case DEBUGREFLWEAPON: return "DEBUGREFLWEAPON";
    case DEBUGREFEWEAPON: return "DEBUGREFEWEAPON";
    case DEBUGSP: return "DEBUGSP";
    case DEBUGGDR: return "DEBUGGDR";
    
    default:
    {
        sprintf(temp, "d%d", ID);
        return string(temp);
    }
    }
}

string GlobalArgument::toString()
{
    char temp[40];
    sprintf(temp, "gd%d", ID);
    return string(temp);
}

string LabelArgument::toString()
{
    if(!haslineno)
    {
        char temp[40];
        sprintf(temp, "l%d", ID);
        return string(temp);
    }
    else
    {
        char temp[40];
        sprintf(temp, "%d", lineno);
        return string(temp);
    }
}

string OSetTrue::toString()
{
    return "SETTRUE " + getArgument()->toString();
}

string OSetFalse::toString()
{
    return "SETFALSE " + getArgument()->toString();
}

string OSetMore::toString()
{
    return "SETMORE " + getArgument()->toString();
}

string OSetLess::toString()
{
    return "SETLESS " + getArgument()->toString();
}

string OSetImmediate::toString()
{
    return "SETV " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OSetRegister::toString()
{
    return "SETR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OAddImmediate::toString()
{
    return "ADDV " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OAddRegister::toString()
{
    return "ADDR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OSubImmediate::toString()
{
    return "SUBV " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OSubRegister::toString()
{
    return "SUBR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OMultImmediate::toString()
{
    return "MULTV " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}


string OMultRegister::toString()
{
    return "MULTR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string ODivImmediate::toString()
{
    return "DIVV " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string ODivRegister::toString()
{
    return "DIVR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OCompareImmediate::toString()
{
    return "COMPAREV " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OCompareRegister::toString()
{
    return "COMPARER " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OWaitframe::toString()
{
    return "WAITFRAME";
}

string OWaitdraw::toString()
{
    return "WAITDRAW";
}

//I would like to add a Jump instruction tot he parser, which would be 'GOTOLABEL' -Z
string OGotoImmediate::toString()
{
    return "GOTO " + getArgument()->toString();
}

string OGotoTrueImmediate::toString()
{
    return "GOTOTRUE " + getArgument()->toString();
}

string OGotoFalseImmediate::toString()
{
    return "GOTOFALSE " + getArgument()->toString();
}

string OGotoMoreImmediate::toString()
{
    return "GOTOMORE " + getArgument()->toString();
}

string OGotoLessImmediate::toString()
{
    return "GOTOLESS " + getArgument()->toString();
}

string OPushRegister::toString()
{
    return "PUSHR " + getArgument()->toString();
}

string OPopRegister::toString()
{
    return "POP " + getArgument()->toString();
}

string OLoadIndirect::toString()
{
    return "LOADI " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OStoreIndirect::toString()
{
    return "STOREI " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OQuit::toString()
{
    return "QUIT";
}

string OGotoRegister::toString()
{
    return "GOTOR " + getArgument()->toString();
}

string OAndImmediate::toString()
{
    return "ANDV " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OAndRegister::toString()
{
    return "ANDR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OOrImmediate::toString()
{
    return "ORV " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OOrRegister::toString()
{
    return "ORR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OXorImmediate::toString()
{
    return "XORV " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OXorRegister::toString()
{
    return "XORR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OSinRegister::toString()
{
    return "SINR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OCosRegister::toString()
{
    return "COSR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OTanRegister::toString()
{
    return "TANR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OATanRegister::toString()
{
    return "ARCTANR " + getArgument()->toString();
}

string OArcCosRegister::toString()
{
    return "ARCCOSR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OArcSinRegister::toString()
{
    return "ARCSINR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OMinRegister::toString()
{
    return "MINR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OMaxRegister::toString()
{
    return "MAXR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OPowRegister::toString()
{
    return "POWERR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OInvPowRegister::toString()
{
    return "IPOWERR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OFactorial::toString()
{
    return "FACTORIAL " + getArgument()->toString();
}

string OAbsRegister::toString()
{
    return "ABS " + getArgument()->toString();
}

string OLog10Register::toString()
{
    return "LOG10 " + getArgument()->toString();
}

string OLogERegister::toString()
{
    return "LOGE " + getArgument()->toString();
}

string OArraySize::toString()
{
    return "ARRAYSIZE " + getArgument()->toString();
}


string OArraySizeF::toString()
{
    return "ARRAYSIZEF " + getArgument()->toString();
}
string OArraySizeN::toString()
{
    return "ARRAYSIZEN " + getArgument()->toString();
}
string OArraySizeE::toString()
{
    return "ARRAYSIZEE " + getArgument()->toString();
}
string OArraySizeL::toString()
{
    return "ARRAYSIZEL " + getArgument()->toString();
}
string OArraySizeB::toString()
{
    return "ARRAYSIZEB " + getArgument()->toString();
}
string OArraySizeI::toString()
{
    return "ARRAYSIZEI " + getArgument()->toString();
}
string OArraySizeID::toString()
{
    return "ARRAYSIZEID " + getArgument()->toString();
}


string OCalcSplineRegister::toString()
{
    return "CALCSPLINER" + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OSetColorRegister::toString()
{
    return "SETCOLORR";
}

string OSetDepthRegister::toString()
{
    return "SETDEPTHR";
}

string OCollisionRectRegister::toString()
{
    return "COLLISIONRECTR" + getArgument()->toString();
}

string OCollisionBoxRegister::toString()
{
    return "COLLISIONBOXR" + getArgument()->toString();
}

string OLShiftImmediate::toString()
{
    return "LSHIFTV " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OLShiftRegister::toString()
{
    return "LSHIFTR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string ORShiftImmediate::toString()
{
    return "RSHIFTV " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string ORShiftRegister::toString()
{
    return "RSHIFTR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OModuloImmediate::toString()
{
    return "MODV " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OModuloRegister::toString()
{
    return "MODR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string ONot::toString()
{
    return "BITNOT " + getArgument()->toString();
}

string OTraceRegister::toString()
{
    return "TRACER " + getArgument()->toString();
}

string OTrace2Register::toString()
{
    return "TRACE2R " + getArgument()->toString();
}

string OTrace3::toString()
{
    return "TRACE3";
}

string OTrace4::toString()
{
    return "TRACE4";
}

string OTrace5Register::toString()
{
    return "TRACE5";
}

string OTrace6Register::toString()
{
    return "TRACE6 " + getArgument()->toString();
}


string ORandRegister::toString()
{
    return "RNDR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OCheckTrig::toString()
{
    return "CHECKTRIG";
}

string OWarp::toString()
{
    return "WARPR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OPitWarp::toString()
{
    return "PITWARPR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OSqrtRegister::toString()
{
    return "SQROOTR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OCreateItemRegister::toString()
{
    return "CREATEITEMR " + getArgument()->toString();
}

string OCreateNPCRegister::toString()
{
    return "CREATENPCR " + getArgument()->toString();
}

string OCreateLWpnRegister::toString()
{
    return "CREATELWEAPONR " + getArgument()->toString();
}

string OCreateEWpnRegister::toString()
{
    return "CREATEEWEAPONR " + getArgument()->toString();
}

string OLoadItemRegister::toString()
{
    return "LOADITEMR " + getArgument()->toString();
}

string OLoadItemDataRegister::toString()
{
    return "LOADITEMDATAR " + getArgument()->toString();
}

string OLoadNPCRegister::toString()
{
    return "LOADNPCR " + getArgument()->toString();
}

string OLoadLWpnRegister::toString()
{
    return "LOADLWEAPONR " + getArgument()->toString();
}

string OLoadEWpnRegister::toString()
{
    return "LOADEWEAPONR " + getArgument()->toString();
}

string OPlaySoundRegister::toString()
{
    return "PLAYSOUNDR " + getArgument()->toString();
}

string OPlayMIDIRegister::toString()
{
    return "PLAYMIDIR " + getArgument()->toString();
}

string OPlayEnhancedMusic::toString()
{
    return "PLAYENHMUSIC " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OGetDMapMusicFilename::toString()
{
    return "GETMUSICFILE " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OGetDMapMusicTrack::toString()
{
    return "GETMUSICTRACK " + getArgument()->toString();
}

// Audio->
string OEndSoundRegister::toString()
{
    return "ENDSOUNDR " + getArgument()->toString();
}


string OContinueSFX::toString()
{
    return "CONTINUESFX " + getArgument()->toString();
}

string OPauseSoundRegister::toString()
{
    return "PAUSESOUNDR " + getArgument()->toString();
}

string OPauseMusic::toString()
{
    return "PAUSEMUSIC";
}
string OResumeMusic::toString()
{
    return "RESUMEMUSIC";
}

string OResumeSoundRegister::toString()
{
    return "RESUMESOUNDR " + getArgument()->toString();
}

//END Audio

string OSetDMapEnhancedMusic::toString()
{
    return "SETDMAPENHMUSIC";
}

string OGetSaveName::toString()
{
    return "GETSAVENAME " + getArgument()->toString();
}

string OSetSaveName::toString()
{
    return "SETSAVENAME " + getArgument()->toString();
}

string OGetDMapName::toString()
{
    return "GETDMAPNAME " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OGetDMapTitle::toString()
{
    return "GETDMAPTITLE " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OGetDMapIntro::toString()
{
    return "GETDMAPINTRO " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}


string OSetDMapName::toString()
{
    return "SETDMAPNAME " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OSetDMapTitle::toString()
{
    return "SETDMAPTITLE " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OSetDMapIntro::toString()
{
    return "SETDMAPINTRO " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OGetItemName::toString()
{
    return "ITEMNAME " + getArgument()->toString();
}

string OGetNPCName::toString()
{
    return "NPCNAME " + getArgument()->toString();
}

string OGetMessage::toString()
{
    return "GETMESSAGE " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}


string OSetMessage::toString()
{
    return "SETMESSAGE " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OClearSpritesRegister::toString()
{
    return "CLEARSPRITESR " + getArgument()->toString();
}

string ORectangleRegister::toString()
{
    return "RECT";
}

string OCircleRegister::toString()
{
    return "CIRCLE";
}

string OArcRegister::toString()
{
    return "ARC";
}

string OEllipseRegister::toString()
{
    return "ELLIPSE";
}

string OLineRegister::toString()
{
    return "LINE";
}

string OSplineRegister::toString()
{
    return "SPLINE";
}

string OPutPixelRegister::toString()
{
    return "PUTPIXEL";
}

string ODrawCharRegister::toString()
{
    return "DRAWCHAR";
}

string ODrawIntRegister::toString()
{
    return "DRAWINT";
}

string ODrawTileRegister::toString()
{
    return "DRAWTILE";
}

string ODrawComboRegister::toString()
{
    return "DRAWCOMBO";
}

string OFastTileRegister::toString()
{
    return "FASTTILE";
}

string OFastComboRegister::toString()
{
    return "FASTCOMBO";
}

string ODrawStringRegister::toString()
{
    return "DRAWSTRING";
}

string ODrawBitmapRegister::toString()
{
    return "DRAWBITMAP";
}

string ODrawBitmapExRegister::toString()
{
    return "BITMAPEXR";
}

string OSetRenderTargetRegister::toString()
{
    return "SETRENDERTARGET";
}

string OSetDepthBufferRegister::toString()
{
    return "SETDEPTHB";
}

string OGetDepthBufferRegister::toString()
{
    return "GETDEPTHB";
}

string OSetColorBufferRegister::toString()
{
    return "SETCOLORB";
}

string OGetColorBufferRegister::toString()
{
    return "GETCOLORB";
}

string OQuadRegister::toString()
{
    return "QUAD";
}

string OTriangleRegister::toString()
{
    return "TRIANGLE";
}


string OQuad3DRegister::toString()
{
    return "QUAD3D";
}

string OTriangle3DRegister::toString()
{
    return "TRIANGLE3D";
}

string ODrawLayerRegister::toString()
{
    return "DRAWLAYER";
}

string ODrawScreenRegister::toString()
{
    return "DRAWSCREEN";
}

string OMessageRegister::toString()
{
    return "MSGSTRR " + getArgument()->toString();
}

string OIsSolid::toString()
{
    return "ISSOLID " + getArgument()->toString();
}

string OSetSideWarpRegister::toString()
{
    return "SETSIDEWARP";
}

string OGetSideWarpDMap::toString()
{
    return "GETSIDEWARPDMAP " + getArgument()->toString();
}

string OGetSideWarpScreen::toString()
{
    return "GETSIDEWARPSCR " + getArgument()->toString();
}

string OGetSideWarpType::toString()
{
    return "GETSIDEWARPTYPE " + getArgument()->toString();
}

string OGetTileWarpDMap::toString()
{
    return "GETTILEWARPDMAP " + getArgument()->toString();
}

string OGetTileWarpScreen::toString()
{
    return "GETTILEWARPSCR " + getArgument()->toString();
}

string OGetTileWarpType::toString()
{
    return "GETTILEWARPTYPE " + getArgument()->toString();
}

string OSetTileWarpRegister::toString()
{
    return "SETTILEWARP";
}

string OLayerScreenRegister::toString()
{
    return "LAYERSCREEN " + getFirstArgument()->toString() + "," +  getSecondArgument()->toString();
}

string OLayerMapRegister::toString()
{
    return "LAYERMAP " + getFirstArgument()->toString() + "," +  getSecondArgument()->toString();
}

string OTriggerSecrets::toString()
{
    return "SECRETS";
}

string OIsValidItem::toString()
{
    return "ISVALIDITEM " + getArgument()->toString();
}

string OIsValidNPC::toString()
{
    return "ISVALIDNPC " + getArgument()->toString();
}

string OCopyTileRegister::toString()
{
    return "COPYTILERR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OOverlayTileRegister::toString()
{
    return "OVERLAYTILERR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OSwapTileRegister::toString()
{
    return "SWAPTILERR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OClearTileRegister::toString()
{
    return "CLEARTILER " + getArgument()->toString();
}

string OIsValidLWpn::toString()
{
    return "ISVALIDLWPN " + getArgument()->toString();
}

string OIsValidEWpn::toString()
{
    return "ISVALIDEWPN " + getArgument()->toString();
}

string OUseSpriteLWpn::toString()
{
    return "LWPNUSESPRITER " + getArgument()->toString();
}

string OUseSpriteEWpn::toString()
{
    return "EWPNUSESPRITER " + getArgument()->toString();
}

string OAllocateMemRegister::toString()
{
    return "ALLOCATEMEMR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OAllocateMemImmediate::toString()
{
    return "ALLOCATEMEMV " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OAllocateGlobalMemImmediate::toString()
{
    return "ALLOCATEGMEMV " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string OAllocateGlobalMemRegister::toString()
{
    return "ALLOCATEGMEMR " + getFirstArgument()->toString() + "," + getSecondArgument()->toString();
}

string ODeallocateMemRegister::toString()
{
    return "DEALLOCATEMEMR " + getArgument()->toString();
}

string ODeallocateMemImmediate::toString()
{
    return "DEALLOCATEMEMV " + getArgument()->toString();
}

string OSave::toString()
{
    return "SAVE";
}

string OGetScreenFlags::toString()
{
    return "GETSCREENFLAGS " + getArgument()->toString();
}

string OGetScreenEFlags::toString()
{
    return "GETSCREENEFLAGS " + getArgument()->toString();
}

string OEnd::toString()
{
    return "GAMEEND";
}

string OComboTile::toString()
{
    return "COMBOTILE " + getFirstArgument()->toString() + "," +  getSecondArgument()->toString();
}

string OBreakShield::toString()
{
    return "BREAKSHIELD " + getArgument()->toString();
}

string OShowSaveScreen::toString()
{
    return "SAVESCREEN " + getArgument()->toString();
}

string OShowSaveQuitScreen::toString()
{
    return "SAVEQUITSCREEN";
}

string OSelectAWeaponRegister::toString()
{
    return "SELECTAWPNR " + getArgument()->toString();
}

string OSelectBWeaponRegister::toString()
{
    return "SELECTBWPNR " + getArgument()->toString();
}

string OGetFFCScript::toString()
{
    return "GETFFCSCRIPT " + getArgument()->toString();
}

//2.54

string OGreyscaleOn::toString()
{
    return "GREYSCALEON";
}

string OGreyscaleOff::toString()
{
    return "GREYSCALEOFF";
}

string OZapIn::toString()
{
    return "ZAPIN";
}

string OZapOut::toString()
{
    return "ZAPOUT";
}

//These need to be unary opcodes that accept bool linkvisible. 
string OWavyIn::toString()
{
    return "WAVYIN";
}

string OWavyOut::toString()
{
    return "WAVYOUT";
}

string OOpenWipe::toString()
{
    return "OPENWIPE";
}

//Game->GetItemScript(int ptr[])
string OGetItemScript::toString()
{
    return "GETITEMSCRIPT " + getArgument()->toString();
}


string OGetLWeaponPointer::toString()
{
    return "LWPNARRPTR " + getArgument()->toString();
}

string OSetLWeaponPointer::toString()
{
    return "LWPNARRPTR2 " + getArgument()->toString();
}

string OGetEWeaponPointer::toString()
{
    return "EWPNARRPTR " + getArgument()->toString();
}

string OSetEWeaponPointer::toString()
{
    return "EWPNARRPTR2 " + getArgument()->toString();
}

string OGetItemPointer::toString()
{
    return "ITEMARRPTR " + getArgument()->toString();
}

string OSetItemPointer::toString()
{
    return "ITEMARRPTR2 " + getArgument()->toString();
}

string OGetItemDataPointer::toString()
{
    return "IDATAARRPTR " + getArgument()->toString();
}

string OSetItemDataPointer::toString()
{
    return "IDATAARRPTR2 " + getArgument()->toString();
}

string OGetFFCPointer::toString()
{
    return "FFCARRPTR " + getArgument()->toString();
}

string OSetFFCPointer::toString()
{
    return "FFCARRPTR2 " + getArgument()->toString();
}

string OGetBoolPointer::toString()
{
    return "BOOLARRPTR " + getArgument()->toString();
}

string OSetBoolPointer::toString()
{
    return "BOOLARRPTR2 " + getArgument()->toString();
}

string OGetNPCPointer::toString()
{
    return "NPCARRPTR " + getArgument()->toString();
}

string OSetNPCPointer::toString()
{
    return "NPCARRPTR2 " + getArgument()->toString();
}

//////////////////////////////////////////////////////////////////////////////////////

