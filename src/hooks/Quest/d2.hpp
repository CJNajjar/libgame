#ifndef __QUEST_D2_HPP
#define __QUEST_D2_HPP
#include "AbstractQList.hpp"
#include "../../func/CHARACTER.hpp"
namespace quest{
class Quest_D2{
public:
    Quest_D2();
    const char* name="d2";
    static int set_warp_location(lua_State* L);
    static const luaL_reg reg[];

};
}
#endif // __QUEST_D2_HPP


