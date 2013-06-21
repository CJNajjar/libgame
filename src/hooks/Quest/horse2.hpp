#ifndef __QUEST_HORSE2_HPP
#define __QUEST_HORSE2_HPP
#include "AbstractQList.hpp"
#include "../../addr.hpp"
#include "../../gameinfo.hpp"
#include "../../func/Lua.hpp"
#include "../../func/quest.hpp"
#include "../../func/CHARACTER.hpp"
#include "../../func/CHARACTER_MANAGER.hpp"
namespace quest{
class Quest_Horse2{
public:
    Quest_Horse2();
    const char* name="horse2";
    static int summon(lua_State* L);
    static const luaL_reg reg[];
};
}
#endif // __QUEST_HORSE2_HPP
