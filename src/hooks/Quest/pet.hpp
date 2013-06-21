#ifndef __QUEST_PET_HPP
#define __QUEST_PET_HPP
#include "AbstractQList.hpp"
#include "../../func/CHARACTER.hpp"
#include "../../func/CHARACTER_MANAGER.hpp"
namespace quest{
class Quest_Pet{
public:
    Quest_Pet();
    const char* name="pet";
    static int set_name(lua_State *L);
    static int remove_bonus(lua_State * L);
    static int give_bonus(lua_State *L);
    static int unsummon(lua_State *L);
    static int is_summon(lua_State *L);
    static int summon(lua_State *L);
    static const luaL_reg reg[];
};
}
#endif // __QUEST_PET_HPP

