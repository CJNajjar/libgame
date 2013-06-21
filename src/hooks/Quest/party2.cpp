#include "party2.hpp"
using namespace quest;
Quest_Party2::Quest_Party2(){}
const luaL_reg Quest_Party2::reg[]= {
    { "get_leader_pid", Quest_Party2::get_leader_pid},
    { "get_members", Quest_Party2::get_members},
    { "is_in_dungeon", Quest_Party2::is_in_dungeon},
    { "give_buff", Quest_Party2::give_buff},
    { NULL, NULL }
};
int Quest_Party2::get_leader_pid(lua_State *L)
{
    GameFunc::quest::CQuestManager* pkQuest = *singleton_CQuestManager;
    GameFunc::CParty * pkParty = pkQuest->m_pCurrentCharacter->m_pkParty;
    DWORD leadPid = CParty::GetLeaderPID(pkParty);
    if (leadPid < 1)
    {
        Lua::PushBoolean(L, 0);
    }
    else
    {
        Lua::PushNumber(L, leadPid);
    }
    return 1;
}
int Quest_Party2::get_members(lua_State *L)
{
    GameFunc::quest::CQuestManager* pkQuest = *singleton_CQuestManager;
    GameFunc::CParty * pkParty = pkQuest->m_pCurrentCharacter->m_pkParty;


    int i = 0;
    for(std::map<unsigned int,GameFunc::CParty::SMember>::iterator it = pkParty->m_memberMap.begin(); it != pkParty->m_memberMap.end(); ++it)
    {
        Lua::PushString(L, it->second.strName.c_str());
        ++i;
    }


    return i;
}

int Quest_Party2::give_buff(lua_State *L)
{
    GameFunc::quest::CQuestManager* pkQuest = *singleton_CQuestManager;
    GameFunc::CParty * pkParty = pkQuest->m_pCurrentCharacter->m_pkParty;

    if(Lua::IsNumber(L, 1) &&
            Lua::IsNumber(L, 2) &&
            Lua::IsNumber(L, 3) &&
            Lua::IsNumber(L, 4) &&
            Lua::IsNumber(L, 5) &&
            Lua::IsNumber(L, 6) &&
            Lua::IsNumber(L, 7) &&
            Lua::IsNumber(L, 8)
      )
    {

        /* bool CHARACTER::AddAffect(unsigned int dwType, unsigned char bApplyOn, long lApplyValue, unsigned int dwFlag, long lDuration, long lSPCost, bool bOverride, bool IsCube); */
        for(std::map<unsigned int,GameFunc::CParty::SMember>::iterator it = pkParty->m_memberMap.begin(); it != pkParty->m_memberMap.end(); ++it)
        {
            if(it->second.pCharacter != nullptr && it->second.pCharacter->m_lpDesc != nullptr)
            {
                CHARACTER::AddAffect(it->second.pCharacter,
                                     (uint32_t)Lua::ToNumber(L, 1),
                                     (uint8_t)Lua::ToNumber(L, 2),
                                     (long)Lua::ToNumber(L, 3),
                                     (uint32_t)Lua::ToNumber(L, 4),
                                     (long)Lua::ToNumber(L, 5),
                                     (long)Lua::ToNumber(L, 6),
                                     Lua::ToBoolean(L, 7),
                                     Lua::ToBoolean(L, 8));
            }

        }


    }
    else
    {
        SYSERR << "Wrong arguments for party2.give_buff" << std::endl;
    }





    return 0;
}

int Quest_Party2::is_in_dungeon(lua_State *L)
{
    GameFunc::quest::CQuestManager* pkQuest = *singleton_CQuestManager;
    GameFunc::CParty * pkParty = pkQuest->m_pCurrentCharacter->m_pkParty;

    if(pkParty->m_pkDungeon != nullptr)
    {
        Lua::PushBoolean(L, 1);
    }
    else
    {
        Lua::PushBoolean(L, 0);
    }

    return 1;
}

