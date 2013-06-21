#ifndef __QUEST_NPC2_HPP
#define __QUEST_NPC2_HPP
#include "AbstractQList.hpp"
namespace quest{
class Quest_NPC2{
public:
    Quest_NPC2();
    const char* name="npc2";
    static int get_pc_vid(lua_State* L);
    static int get_pc_pid(lua_State* L);
    static int get_level(lua_State* L);
    static const luaL_reg reg[];
};
}
#endif // __QUEST_NPC2_HPP
