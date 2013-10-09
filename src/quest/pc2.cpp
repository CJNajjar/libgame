#include "pc2.hpp"
using namespace libm2::quest;
namespace quest {
std::string tPC2::getName() {
    return "pc2";
}
tPC2::tPC2() {
    add("send_effect",send_effect);
    add("set_level",set_level);
    add("give_or_drop_item_and_select",(lua_CFunction)0x81B7550);
}
int tPC2::set_level(lua_State *L){
    CHARACTER* pkCh = CQuestManager::instance()->GetCurrentCharacterPtr();
    if(pkCh&&lua::IsNumber(L,1)) {
        pkCh->ResetPoint(lua::ToNumber(L,1));
        lua::PushBoolean(L,1);
        return 1;
    }
    lua::PushBoolean(L,0);
    return 1;
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
