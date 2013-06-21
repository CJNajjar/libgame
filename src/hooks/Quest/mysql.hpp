#ifndef __QUEST_MYSQL_HPP
#define __QUEST_MYSQL_HPP
#include "AbstractQList.hpp"
#include "../../func/DBManager.hpp"
#include "../../func/libMySQL.hpp"
#include "../../func/General.hpp"

namespace quest{
class Quest_MySQL{
public:
    Quest_MySQL();
    const char* name="mysql";
    static int query(lua_State* L);
    static int escape(lua_State* L);
    static const luaL_reg reg[];
};
}
#endif // __QUEST_MYSQL_HPP


