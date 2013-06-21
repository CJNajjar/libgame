#ifndef __QUEST_PC2_HPP
#define __QUEST_PC2_HPP
#include "AbstractQList.hpp"
#include "../../func/CHARACTER.hpp"
namespace quest{
class Quest_PC2{
public:
    Quest_PC2();
    const char* name="pc2";
    static int get_special_slot(lua_State* L);
    static int get_wear(lua_State* L);
    static const luaL_reg reg[];
};
}
#endif // __QUEST_PC2_HPP
