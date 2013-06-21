#ifndef __QUEST_PARTY2_HPP
#define __QUEST_PARTY2_HPP
#include "AbstractQList.hpp"
#include "../../func/CParty.hpp"
#include "../../func/CHARACTER.hpp"
namespace quest{
class Quest_Party2{
public:
    Quest_Party2();
    const char* name="party2";
    static int get_leader_pid(lua_State* L);
    static int get_members(lua_State* L);
    static int is_in_dungeon(lua_State* L);
    static int give_buff(lua_State* L);
    static const luaL_reg reg[];
};
}
#endif // __QUEST_PARTY2_HPP

