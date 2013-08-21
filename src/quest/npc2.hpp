#ifndef __QUEST_NPC2_HPP
#define __QUEST_NPC2_HPP
#include "../libm2/IQuest.hpp"
#include "../libm2/game/quest/CQuestManager.hpp"
#include "../libm2/lib/singleton.hpp"
#include "../libm2/game/lua.hpp"
#include "../libm2/game/CHARACTER.hpp"

using namespace libm2;
namespace quest{
class tNPC2: public IQuest, public singleton<tNPC2>{
public:
    tNPC2();
    std::string getName();
    static int get_pc_vid(lua_State* L);
    static int get_pc_pid(lua_State* L);
    static int get_level(lua_State* L);
};
}
#endif // __QUEST_NPC2_HPP
