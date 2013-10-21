#include "GiveExp.hpp"
#include "../libm2/game/misc.hpp"
#include "../libm2/game/CPrivManager.hpp"
#include "../libm2/game/CHARACTER_MANAGER.hpp"
#include "../libm2/game/enums.hpp"
#include "../libm2/game/marriage/TMarriage.hpp"
#include "../libm2/game/marriage/CManager.hpp"

namespace Hooks {
const int* aiPercentByDeltaLev_euckr = (const int*)myAddr::misc::aiPercentByDeltaLev_euckr;
GiveExp::GiveExp(): Hook::Hook() {}
void GiveExp::hook(CHARACTER* from, CHARACTER* to, int iExp) {
    long long delta = ((long long)iExp) * aiPercentByDeltaLev_euckr[MINMAX(0, from->GetLevel() + 15 - to->GetLevel(), 30)] / 100;
    if (delta < 0) {
        return;
    }
    delta = (delta*(CPrivManager::instance()->GetPriv(to, 4) + 100)) / 100;
    if (to->IsEquipUniqueItem(UNIQUE_ITEM_LARBOR_MEDAL)) {
        delta += delta / 5;
    }
    if (to->GetMapIndex() > 659999 && to->GetMapIndex() <= 669999) {
        delta += delta / 5;
    }
    if (to->GetPoint(POINT_EXP_DOUBLE_BONUS) && number_ex(1, 100, __FILE__, __LINE__) <= to->GetPoint(POINT_EXP_DOUBLE_BONUS)) {
        delta += 30 * delta / 100;
    }
    if (to->IsEquipUniqueItem(UNIQUE_ITEM_DOUBLE_EXP)) {
        delta += delta / 2;
    }
    DWORD mountvnum = to->GetMountVnum() - 20110;
    if ( mountvnum <= 15 ) {
        DWORD shifted_mountvnum = 1 << mountvnum;
        if ( shifted_mountvnum & 0xFC10 ) {
            delta += 30 * delta / 100;
        } else {
            if ( shifted_mountvnum & 0xF && (to->IsEquipUniqueItem(71115)
                                             || to->IsEquipUniqueItem(71117)
                                             || to->IsEquipUniqueItem(71119)
                                             || to->IsEquipUniqueItem(71121))) {
                delta += delta / 10;
            }
        }
    }
    if (to->IsEquipUniqueGroup(10060)) {
        delta = 0;
        return;
    }
    if (to->GetPremiumRemainSeconds(0) > 0) {
        delta += delta / 2;
    }
    if (to->IsEquipUniqueGroup(UNIQUE_GROUP_RING_OF_EXP)) {
        delta += delta / 2;
    }
    delta += (delta * to->GetMarriageBonus(UNIQUE_ITEM_MARRIAGE_EXP_BONUS, 1)) / 100;
    delta += (delta * to->GetPoint(POINT_RAMADAN_CANDY_BONUS_EXP)) / 100;
    delta += (delta * to->GetPoint(POINT_MALL_EXPBONUS)) / 100;
    delta += (delta * to->GetPoint(POINT_EXP)) / 100;
    delta += (delta * CHARACTER_MANAGER::instance()->GetMobExpRate(to)) / 100;
    // AdjustExpByLevel
    long long adjusted;
    if (to->GetLevel() > 100){
        adjusted = AdjustExpByLevel(to, MIN(to->GetNextExp()*0.013, delta));
    }else{
        adjusted = AdjustExpByLevel(to, MIN(to->GetNextExp() / 10, delta));
    }
    long long xp = adjusted;
    if (to->GetNextExp() + adjusted >= 0x7FFFFFFF) { // overflow
        to->PointChange(POINT_EXP, 0x7FFFFFFF - to->GetNextExp(), true, false);
        adjusted -= 0x7FFFFFFF - to->GetNextExp();
    }
    to->PointChange(POINT_EXP, adjusted, true, false);
    from->CreateFly(FLY_EXP, to);
    LPCHARACTER you = to->GetMarryPartner();
    if (you) {
        DWORD dwUpdatePoint = 2000 * xp / to->GetLevel() / to->GetLevel() / 3;
        if (to->GetPremiumRemainSeconds(PREMIUM_MARRIAGE_FAST) > 0 ||
                you->GetPremiumRemainSeconds(PREMIUM_MARRIAGE_FAST) > 0)
            dwUpdatePoint = (DWORD)(dwUpdatePoint * 3);

        marriage::TMarriage* pMarriage = marriage::CManager::instance()->Get(to->GetPlayerID());

        if (pMarriage && pMarriage->IsNear())
            pMarriage->Update(dwUpdatePoint);
    }
}
long long AdjustExpByLevel(CHARACTER* ch, long long exp) {
    int level = ch->GetLevel();
    long double multiplier;
    long double multi2;
    if (level > 99) {
        multiplier = 0.95;
        if (level > 100) {
            multi2 = 0.1;
            for (int i = 0; i < level; i++) {
                multi2 *= 0.5;
                multiplier *= (1.0 - multi2);
            }
        }
        long double res = exp * multiplier;
        if (res < 1.0) {
            res = 1;
        }
        return res;
    }
    return exp;
}
}
