#ifndef __QUEST_MOB_HPP
#define __QUEST_MOB_HPP
#include "AbstractQList.hpp"
namespace quest{
class Quest_Mob{
public:
    Quest_Mob();
    const char* name="mob";
    static int get_vnum(lua_State* L);
    static int get_type(lua_State* L);
    static int get_rank(lua_State* L);
    static int get_exp(lua_State* L);
    static int get_level(lua_State* L);
    static int get_str(lua_State* L);
    static int get_dex(lua_State* L);
    static int get_con(lua_State* L);
    static int get_int(lua_State* L);
    static int get_max_hp(lua_State* L);
    static int get_summon_vnum(lua_State* L);
    static int get_regen_cycle(lua_State* L);
    static int get_regen_percent(lua_State* L);
    static int get_def(lua_State* L);
    static int set_def(lua_State* L);
    static int get_damage_multiply(lua_State* L);
    static int set_damage_multiply(lua_State* L);
    static const luaL_reg reg[];
};
}
#endif // __QUEST_MOB_HPP
