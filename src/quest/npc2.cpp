#include "npc2.hpp"
using namespace libm2::quest;
namespace quest {
std::string tNPC2::getName() {
    return "npc2";
}
tNPC2::tNPC2() {
    add("get_level",get_level);
    add("get_pc_pid",get_pc_pid);
    add("get_pc_vid",get_pc_vid);
}
int tNPC2::get_pc_vid(lua_State* L) {
    CHARACTER* pkCh = CQuestManager::instance()->GetCurrentCharacterPtr();
    if(pkCh != nullptr) {
        if(pkCh->m_pkMobData == nullptr) {
            lua::PushNumber(L, (DWORD)pkCh->GetVID());
        } else {
            lua::PushNumber(L, 0);
        }
    } else {
        lua::PushNumber(L, 0);
    }
    return 1;
}
int tNPC2::get_level(lua_State* L) {
    CHARACTER* pkCh = CQuestManager::instance()->GetCurrentNPCCharacterPtr();
    if(pkCh != nullptr) {
        lua::PushNumber(L, pkCh->GetLevel());
    } else {
        lua::PushNil(L);
    }
    return 1;
}

int tNPC2::get_pc_pid(lua_State* L) {
    CHARACTER* pkCh = CQuestManager::instance()->GetCurrentNPCCharacterPtr();
    if(pkCh != nullptr) {
        if(pkCh->m_pkMobData == nullptr) {
            lua::PushNumber(L, pkCh->GetPlayerID());
        } else {
            lua::PushNumber(L, 0);
        }
    } else {
        lua::PushNumber(L, 0);
    }
    return 1;
}
}
