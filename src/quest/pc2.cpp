#include "pc2.hpp"
using namespace libm2::quest;
namespace quest {
std::string tPC2::getName() {
    return "npc2";
}
tPC2::tPC2() {
    add("send_effect",send_effect);
}
int tPC2::send_effect(lua_State *L){
    CHARACTER* pkCh = CQuestManager::instance()->GetCurrentCharacterPtr();
    if(pkCh != nullptr) {
        if (lua::IsString(L,1)){
            pkCh->SpecificEffectPacket(lua::ToString(L,1));        }
    } else {
        lua::PushNumber(L, 0);
    }
    return 1;
}
}
