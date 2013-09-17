#include "item2.hpp"
using namespace libm2::quest;
namespace quest {
std::string tItem2::getName() {
    return "item2";
}
tItem2::tItem2() {
    add("get_wearflag",get_wearflag);
    add("is_wearflag",is_wearflag);

}
int tItem2::get_wearflag(lua_State* L){
    CItem* item = CQuestManager::instance()->GetCurrentItem();
    if (item){
        lua::PushNumber(L,item->GetProto()->dwWearFlags);
        return 1;
    }
    lua::PushNumber(L,0);
    return 1;
}

int tItem2::is_wearflag(lua_State* L){
    if (!lua::IsNumber(L,1)){return 0;}
    CItem* item = CQuestManager::instance()->GetCurrentItem();
    if (item){
        lua::PushBoolean(L,(item->GetProto()->dwWearFlags&(DWORD)lua::ToNumber(L,1)));
        return 1;
    }
    lua::PushNumber(L,0);
    return 1;
}
}
