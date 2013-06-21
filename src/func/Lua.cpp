#include "Lua.hpp"
namespace Lua{
lua_dostring DoString = (lua_dostring)Addr::kDoString;
lua_dofile DoFile = (lua_dofile)Addr::kDoFile;

lua_tostring ToString = (lua_tostring)Addr::kToString;
lua_toboolean ToBoolean = (lua_toboolean)Addr::kToBoolean;
lua_tonumber ToNumber = (lua_tonumber)Addr::kToNumber;
lua_topointer ToPointer = (lua_topointer)Addr::kToPointer;
lua_tothread ToThread = (lua_tothread)Addr::kToThread;
lua_touserdata ToUserData = (lua_touserdata)Addr::kToUserData;

lua_pushboolean PushBoolean = (lua_pushboolean)Addr::kPushBoolean;
lua_pushcclosure PushClosure = (lua_pushcclosure)Addr::kPushCClosure;
lua_pushfstring PushFString = (lua_pushfstring)Addr::kPushFString;
lua_pushlightuserdata PushLightUserData = (lua_pushlightuserdata)Addr::kPushLightUserData;
lua_pushlstring PushLString = (lua_pushlstring)Addr::kPushLString;
lua_pushnil PushNil = (lua_pushnil)Addr::kPushNil;
lua_pushnumber PushNumber = (lua_pushnumber)Addr::kPushNumber;
lua_pushstring PushString = (lua_pushstring)Addr::kPushString;
lua_pushupvalues PushUpValues = (lua_pushupvalues)Addr::kPushUpValues;
lua_pushvalue PushValue = (lua_pushvalue)Addr::kPushValue;
lua_pushvfstring PushVFString = (lua_pushvfstring)Addr::kPushVFString;

lua_isnumber IsNumber = (lua_isnumber)Addr::kIsNumber;
lua_isstring IsString = (lua_isstring)Addr::kIsString;

lua_settable SetTable = (lua_settable)Addr::kSetTable;
lua_newtable NewTable = (lua_newtable)Addr::kNewTable;
lua_gettop GetTop = (lua_gettop)Addr::kGetTop;
lua_settop SetTop = (lua_settop)Addr::kSetTop;
lua_rawseti RawSetI = (lua_rawseti)Addr::kRawSetI;
lua_rawset RawSet = (lua_rawset)Addr::kRawSet;
}
