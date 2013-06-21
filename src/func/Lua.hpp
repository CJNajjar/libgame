#ifndef __LUA_HPP
#define __LUA_HPP
#include "../addr.hpp"
#include "../gameinfo.hpp"
namespace Lua
{

extern lua_dostring DoString;
extern lua_dofile DoFile;

extern lua_tostring ToString;
extern lua_toboolean ToBoolean;
extern lua_tonumber ToNumber;
extern lua_topointer ToPointer;
extern lua_tothread ToThread;
extern lua_touserdata ToUserData;

extern lua_pushboolean PushBoolean;
extern lua_pushcclosure PushClosure;
extern lua_pushfstring PushFString;
extern lua_pushlightuserdata PushLightUserData;
extern lua_pushlstring PushLString;
extern lua_pushnil PushNil;
extern lua_pushnumber PushNumber;
extern lua_pushstring PushString;
extern lua_pushupvalues PushUpValues;
extern lua_pushvalue PushValue;
extern lua_pushvfstring PushVFString;

extern lua_isnumber IsNumber;
extern lua_isstring IsString;

extern lua_settable SetTable;
extern lua_newtable NewTable;
extern lua_gettop GetTop;
extern lua_settop SetTop;
extern lua_rawseti RawSetI;
extern lua_rawset RawSet;

}
#endif // __LUA_HPP
