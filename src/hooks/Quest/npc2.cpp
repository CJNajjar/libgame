#include "npc2.hpp"
using namespace quest;
Quest_NPC2::Quest_NPC2(){}
const luaL_reg Quest_NPC2::reg[4]= {
    { "get_pc_vid", Quest_NPC2::get_pc_vid},
    { "get_pc_pid", Quest_NPC2::get_pc_pid},
    { "get_level", Quest_NPC2::get_level},
    { NULL, NULL }
};
int Quest_NPC2::get_pc_vid(lua_State* L)
{
    GameFunc::CHARACTER* pkCh = CQuestManager::GetCurrentNPCCharacterPtr(*singleton_CQuestManager);
    if(pkCh != nullptr)
    {
        if(pkCh->m_pkMobData == nullptr)
        {
            Lua::PushNumber(L, pkCh->m_vid.m_id);
            return 1;
        }
        else
        {
            Lua::PushNumber(L, 0);
            return 1;
        }
    }
    else
    {
        Lua::PushNumber(L, 0);
        return 1;
    }
}
int Quest_NPC2::get_level(lua_State* L)
{
    GameFunc::CHARACTER* pkCh = CQuestManager::GetCurrentNPCCharacterPtr(*singleton_CQuestManager);
    if(pkCh != nullptr)
    {
        Lua::PushNumber(L, pkCh->m_points.level);
        return 1;
    }
    else
    {
        Lua::PushNil(L);
        return 1;
    }
}

int Quest_NPC2::get_pc_pid(lua_State* L)
{
    GameFunc::CHARACTER* pkCh = CQuestManager::GetCurrentNPCCharacterPtr(*singleton_CQuestManager);
    if(pkCh != nullptr)
    {
        if(pkCh->m_pkMobData == nullptr)
        {
            Lua::PushNumber(L, pkCh->m_dwPlayerID);
            return 1;
        }
        else
        {
            Lua::PushNumber(L, 0);
            return 1;
        }
    }
    else
    {
        Lua::PushNumber(L, 0);
        return 1;
    }
}

