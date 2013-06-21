#include "d2.hpp"
using namespace quest;
Quest_D2::Quest_D2(){};
const luaL_reg Quest_D2::reg[]= {
    { "set_warp_location",Quest_D2::set_warp_location},
    { NULL, NULL }
};
int Quest_D2::set_warp_location(lua_State *L)
{
    GameFunc::CDungeon * pkDungeon = CQuestManager::GetCurrentDungeon(*singleton_CQuestManager);

    std::for_each(pkDungeon->m_set_pkCharacter.begin(),  pkDungeon->m_set_pkCharacter.end(), [L] (GameFunc::CHARACTER* pkCh)
    {
        CHARACTER::SetWarpLocation(pkCh, (long)Lua::ToNumber(L, 1),
                                   (long)Lua::ToNumber(L, 2),
                                   (long)Lua::ToNumber(L, 3));


    });
    return 0;

}

