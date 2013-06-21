#ifndef __QUEST_ABSTRACT_HPP
#define __QUEST_ABSTRACT_HPP
#include "../../addr.hpp"
#include "../../gameinfo.hpp"
#include "../../func/Lua.hpp"
#include "../../func/quest.hpp"
namespace quest{
class AbstractQList{
public:
    AbstractQList();
    const char* name;
    static const luaL_reg reg[];
};
}
#endif // __QUEST_ABSTRACT_HPP
