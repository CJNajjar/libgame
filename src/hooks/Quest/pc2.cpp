#include "pc2.hpp"
using namespace quest;
Quest_PC2::Quest_PC2(){}
const luaL_reg Quest_PC2::reg[]= {
    { "get_special_slot", get_special_slot},
    { "get_wear", get_wear},
    { NULL, NULL }
};
int Quest_PC2::get_special_slot(lua_State* L)
{
    if (!Lua::IsNumber(L, 1))
    {
        Lua::PushNumber(L, 0);
        return 1;
    }

    if(!*singleton_CQuestManager)
    {
        SYSERR << "singelton CQuestManager check failed" << std::endl;
        Lua::PushNumber(L, 0);
        return 1;
    }

    GameFunc::quest::CQuestManager* questManager = *singleton_CQuestManager;
    GameFunc::CHARACTER * pkCh = questManager->m_pCurrentCharacter;

    lua_Number arg = Lua::ToNumber(L, 1);
    if(static_cast<uint8_t>(arg) > 1)
    {
        Lua::PushNumber(L, 0);
        return 1;
    }

    GameFunc::CItem* wearItem = CHARACTER::GetWear(pkCh, 6 + static_cast<uint8_t>(arg));
    if(!wearItem->m_pProto)
    {
        Lua::PushNumber(L, 0);
        return 1;
    }

    Lua::PushNumber(L, wearItem->m_pProto->dwVnum);
    return 1;


}

int Quest_PC2::get_wear(lua_State* L)
{
    if(!*singleton_CQuestManager)
    {
        SYSERR << "singelton CQuestManager check failed" << std::endl;
        Lua::PushNil(L);
        return 1;
    }

    GameFunc::quest::CQuestManager* questManager = *singleton_CQuestManager;
    GameFunc::CHARACTER * pkCh = questManager->m_pCurrentCharacter;

    if(!Lua::IsNumber(L, 1))
    {
        Lua::PushNil(L);
        return 1;
    }

    GameFunc::CItem* pkItem = CHARACTER::GetWear(pkCh, static_cast<DWORD>(Lua::ToNumber(L, 1)));
    if(!pkItem->m_pProto)
    {
        Lua::PushNil(L);
        return 1;
    }
    Lua::PushNumber(L, pkItem->m_pProto->dwVnum);
    return 1;
}

