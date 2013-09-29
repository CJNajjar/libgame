#ifndef __QUEST_ITEM2_HPP
#define __QUEST_ITEM2_HPP
#include "../libm2/IQuest.hpp"
#include "../libm2/game/quest/CQuestManager.hpp"
#include "../libm2/lib/singleton.hpp"
#include "../libm2/game/lua.hpp"
#include "../libm2/game/CItem.hpp"

using namespace libm2;
namespace quest{
class tItem2: public IQuest, public singleton<tItem2>{
public:
    tItem2();
    std::string getName();
    static int get_wearflag(lua_State* L);
    static int is_wearflag(lua_State* L);
    static int get_attr(lua_State* L);
    static int set_attr(lua_State* L);
    static int equip(lua_State* L);
};
}
#endif // __QUEST_ITEM2_HPP
/*
 - int[] item.get_attr() // return {int applytype, int applyvalue}
 - item.set_attr(int applyslot, int applytype, int applyvalue)
 - pc.set_equipment_item(int itemVnum, int[] itemSockets, int[] itemAttrs) // erstellt ein Gegenstand im EQ
 - pc.set_level(int level)*/
