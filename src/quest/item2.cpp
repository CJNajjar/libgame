#include "item2.hpp"
using namespace libm2::quest;
namespace quest {
std::string tItem2::getName() {
    return "item2";
}
tItem2::tItem2() {
    add("get_wearflag",get_wearflag);
    add("is_wearflag",is_wearflag);
    add("set_attr",set_attr);
    add("get_attr",get_attr);
    add("equip",equip);

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

int tItem2::get_attr(lua_State* L){
    CItem* item = CQuestManager::instance()->GetCurrentItem();
    if (!lua::IsNumber(L,1)||!item){
        return 0;
    }
    int attr_index = lua::ToNumber(L,1);
    if (attr_index <0 || attr_index > 6){
        return 0;
    }
    TPlayerItemAttribute attr=item->GetAttribute(attr_index);
    lua::PushNumber(L,attr.bType);
    lua::PushNumber(L,attr.sValue);
    return 2;
}
int tItem2::set_attr(lua_State* L){
    CItem* item = CQuestManager::instance()->GetCurrentItem();
    if (!lua::IsNumber(L,1)||!lua::IsNumber(L,2)||!lua::IsNumber(L,3)||!item){
        lua::PushBoolean(L,0);
        return 1;
    }
    int attr_index = lua::ToNumber(L,1);
    if (attr_index <0 || attr_index > 6){
        lua::PushBoolean(L,0);
        return 1;
    }
    item->SetForceAttribute(attr_index,lua::ToNumber(L,2),lua::ToNumber(L,3));
    lua::PushBoolean(L,1);
    return 1;
}
int tItem2::equip(lua_State* L){
    CItem* item = CQuestManager::instance()->GetCurrentItem();
    CHARACTER* ch = CQuestManager::instance()->GetCurrentCharacterPtr();
    if (!lua::IsNumber(L,1)||!item||!ch){
        lua::PushBoolean(L,0);
        return 1;
    }
    int equipcell=lua::ToNumber(L,1);
    CItem* wear=ch->GetWear(equipcell);
    if (wear){
        ch->UnequipItem(wear);
    }
    item->EquipTo(ch,equipcell);
    lua::PushBoolean(L,1);
    return 1;
}
}
