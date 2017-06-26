#ifndef ZSPARSER_TYPES_H
#define ZSPARSER_TYPES_H

#include <string>
#include <functional>
#include <iostream>

class Scope;

using std::string;

////////////////////////////////////////////////////////////////
// Script Types

enum ScriptType {SCRIPTTYPE_VOID, SCRIPTTYPE_GLOBAL, SCRIPTTYPE_FFC, SCRIPTTYPE_ITEM};

////////////////////////////////////////////////////////////////
// Variable Types

typedef int ZVarTypeId;

// I can't figure out a better way to do this in C++98.
enum ZVarTypeClassId
{
	ZVARTYPE_CLASSID_BASE,
	ZVARTYPE_CLASSID_SIMPLE,
	ZVARTYPE_CLASSID_UNRESOLVED,
	ZVARTYPE_CLASSID_CONST_FLOAT,
	ZVARTYPE_CLASSID_CLASS,
	ZVARTYPE_CLASSID_ARRAY
};

enum ZVarTypeIdBuiltin
{
	ZVARTYPEID_START = 0,

	ZVARTYPEID_PRIMITIVE_START = 0,
    ZVARTYPEID_VOID = 0, ZVARTYPEID_FLOAT, ZVARTYPEID_BOOL,
	ZVARTYPEID_PRIMITIVE_END,

	ZVARTYPEID_CONST_FLOAT = ZVARTYPEID_PRIMITIVE_END,

	ZVARTYPEID_CLASS_START,
    ZVARTYPEID_GAME = ZVARTYPEID_CLASS_START, ZVARTYPEID_LINK, ZVARTYPEID_SCREEN,
    ZVARTYPEID_FFC, ZVARTYPEID_ITEM, ZVARTYPEID_ITEMCLASS, ZVARTYPEID_NPC, ZVARTYPEID_LWPN, ZVARTYPEID_EWPN,
	ZVARTYPEID_AUDIO, ZVARTYPEID_DEBUG, ZVARTYPEID_NPCDATA,  ZVARTYPEID_TEXT, ZVARTYPEID_GRAPHICS, ZVARTYPEID_COMBOS, ZVARTYPEID_SPRITEDATA,
	
	ZVARTYPEID_CLASS_END,

	ZVARTYPEID_END = ZVARTYPEID_CLASS_END
};

class ZVarTypeSimple;
class ZVarTypeConstFloat;
class ZVarTypeClass;
class ZVarTypeArray;

class ZVarType
{
public:
	virtual ZVarType* clone() const = 0;
	virtual string getName() const = 0;
	virtual ZVarType* resolve(Scope& scope) {return this;}
	virtual bool isResolved() const {return true;}
	virtual bool canBeGlobal() const {return false;}
	virtual bool canCastTo(ZVarType const& target) const = 0;
	virtual int typeClassId() const {return ZVARTYPE_CLASSID_BASE;};

	int compare(ZVarType const& other) const;
	bool operator==(ZVarType const& other) const {return compare(other) == 0;}
	bool operator!=(ZVarType const& other) const {return compare(other) != 0;}
	bool operator<(ZVarType const& other) const {return compare(other) < 0;}

	// Comparator for pointers to types.
	struct PointerLess : public std::less<ZVarType*> {
		bool operator() (ZVarType* const& a, ZVarType* const& b) const
		{
			if (b == NULL) return false;
			if (a == NULL) return true;
			return *a < *b;
		}
	};

	// This comes up so often I'm adding in this shortcut.
	bool isArray() const {return typeClassId() == ZVARTYPE_CLASSID_ARRAY;}

	// Get the number of nested arrays at top level.
	int getArrayDepth() const;
	
protected:
	virtual int selfCompare(ZVarType const& other) const = 0;

// Standard Types.
public:
	static ZVarTypeSimple const ZVOID;
	static ZVarTypeSimple const FLOAT;
	static ZVarTypeSimple const BOOL;
	static ZVarTypeConstFloat const CONST_FLOAT;
	static ZVarTypeClass const FFC;
	static ZVarTypeClass const ITEM;
	static ZVarTypeClass const ITEMCLASS;
	static ZVarTypeClass const NPC;
	static ZVarTypeClass const LWPN;
	static ZVarTypeClass const EWPN;
	static ZVarTypeClass const GAME;
	static ZVarTypeClass const LINK;
	static ZVarTypeClass const SCREEN;
	static ZVarTypeClass const AUDIO;
	static ZVarTypeClass const DEBUG;
	static ZVarTypeClass const NPCDATA;
static ZVarTypeClass const TEXT;
static ZVarTypeClass const GRAPHICS;
static ZVarTypeClass const COMBOS;
static ZVarTypeClass const SPRITEDATA;
	static ZVarType const* get(ZVarTypeId id);
};

class ZVarTypeSimple : public ZVarType
{
public:
	ZVarTypeSimple(int simpleId, string const& name, string const& upName)
			: simpleId(simpleId), name(name), upName(upName) {}
	ZVarTypeSimple* clone() const {return new ZVarTypeSimple(*this);}
	string getName() const {return name;}
	string getUpName() const {return upName;}
	bool canBeGlobal() const;
	bool canCastTo(ZVarType const& target) const;
	int getId() const {return simpleId;}
	int typeClassId() const {return ZVARTYPE_CLASSID_SIMPLE;}
protected:
	int selfCompare(ZVarType const& other) const;
private:
	int simpleId;
	string name;
	string upName;
};

class ZVarTypeUnresolved : public ZVarType
{
public:
	ZVarTypeUnresolved(string const& name) : name(name) {}
	ZVarTypeUnresolved* clone() const {return new ZVarTypeUnresolved(*this);}
	string getName() const {return name;}
	ZVarType* resolve(Scope& scope);
	bool isResolved() const {return false;}
	bool canCastTo(ZVarType const& target) const {return false;}
	int typeClassId() const {return ZVARTYPE_CLASSID_UNRESOLVED;}
protected:
	int selfCompare(ZVarType const& other) const;
private:
	string name;
};

// Temporary while only floats can be constant.
class ZVarTypeConstFloat : public ZVarType
{
public:
	ZVarTypeConstFloat() {}
	ZVarType* clone() const {return new ZVarTypeConstFloat(*this);}
	string getName() const {return "const float";}
	ZVarType* resolve(Scope& scope) {return this;}
	bool canBeGlobal() const {return true;}
	bool canCastTo(ZVarType const& target) const;
	int typeClassId() const {return ZVARTYPE_CLASSID_CONST_FLOAT;};
protected:
	int selfCompare(ZVarType const& other) const {return 0;};
};

class ZVarTypeClass : public ZVarType
{
public:
	ZVarTypeClass(int classId) : classId(classId), className("") {}
	ZVarTypeClass(int classId, string const& className) : classId(classId), className(className) {}
	ZVarTypeClass* clone() const {return new ZVarTypeClass(*this);}
	string getName() const;
	string getClassName() const {return className;}
	int getClassId() const {return classId;}
	ZVarType* resolve(Scope& scope);
	bool canBeGlobal() const {return true;}
	bool canCastTo(ZVarType const& target) const;
	int typeClassId() const {return ZVARTYPE_CLASSID_CLASS;}
protected:
	int selfCompare(ZVarType const& other) const;
private:
	int classId;
	string className;
};

class ZVarTypeArray : public ZVarType
{
public:
	ZVarTypeArray(ZVarType const& elementType) : elementType(elementType) {}
	ZVarTypeArray* clone() const {return new ZVarTypeArray(*this);}

	int typeClassId() const {return ZVARTYPE_CLASSID_ARRAY; }

	string getName() const {return elementType.getName() + "[]";}
	ZVarType* resolve(Scope& scope) {return this;}

	bool canBeGlobal() const {return true;}
	bool canCastTo(ZVarType const& target) const;
	ZVarType const& getElementType() const {return elementType;}
	ZVarType const& getBaseType() const;
protected:
	int selfCompare(ZVarType const& other) const;
private:
	ZVarType const& elementType;
};

#endif
