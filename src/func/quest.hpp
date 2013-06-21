#ifndef __QUEST_CQUESTMANAGER_HPP
#define __QUEST_CQUESTMANAGER_HPP
#include "../gameinfo.hpp"
#include "CQuestManager.hpp"
#include "General.hpp"
namespace quest
{
typedef void (*tRegisterAffectFunctionTable)();
typedef void (*tAddLuaFuncTable)(GameFunc::quest::CQuestManager * const, const char *, const luaL_reg *);
extern tAddLuaFuncTable AddLuaFunctionTable;
extern tRegisterAffectFunctionTable RegisterAffectFunctionTable;
// util
GameFunc::CMob* GetMobPointer();
}
#endif // __QUEST_CQUESTMANAGER_HPP
