#ifndef __QUEST_NPC2_HPP
#define __QUEST_NPC2_HPP
#include "../libm2/IQuest.hpp"
#include "../libm2/game/quest/CQuestManager.hpp"
#include "../libm2/lib/singleton.hpp"
#include "../libm2/game/lua.hpp"
#include "../libm2/game/CHARACTER.hpp"

using namespace libm2;
namespace quest{
class tPC2: public IQuest, public singleton<tPC2>{
public:
    tPC2();
    std::string getName();
    static int send_effect(lua_State* L);
};
}
#endif // __QUEST_NPC2_HPP
