#include "HorseApply.hpp"
#include "../libm2/game/enums.hpp"
#include "../dif/ApplyInfo.hpp"
using namespace libm2;
namespace Hooks{
HorseApply::HorseApply(){
    detour_StartRiding=simpleHook<bool(*)(CHARACTER*)>((unsigned int)Addr::CHARACTER::StartRiding,StartRiding);
    detour_StopRiding=simpleHook<bool(*)(CHARACTER*)>((unsigned int)Addr::CHARACTER::StopRiding,StopRiding);
}
bool HorseApply::StartRiding(CHARACTER* ch ){
    if (instance()->detour_StartRiding->GetOriginalFunction()(ch)){
        quest::PC* qPC = quest::CQuestManager::instance()->GetPC(ch->GetPlayerID());
        if (qPC){
            int type = qPC->GetFlag("horse_summon.apply_type");
            int value = qPC->GetFlag("horse_summon.apply_value");
            if (type&&value){
                // type = AFFECT_AUTO_SP_RECOVERY+1 (AFFECT_AUTO_SP_RECOVERY= max 500 range, 1000+ = quest)
                ch->RemoveAffect(536);
                ch->AddAffect(536,dif::aApplyInfo[type],value,0,3600*24*356,0,0,0);
            }
        }
        return true;
    }
    return false;
}
bool HorseApply::StopRiding(CHARACTER* ch ){
    if (instance()->detour_StopRiding->GetOriginalFunction()(ch)){
        ch->RemoveAffect(536);
        return true;
    }
    return false;
}
}
