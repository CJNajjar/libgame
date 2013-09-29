#include "test.hpp"
#include "../libm2/lib/log.hpp"
#include "../libm2/game/CHARACTER_MANAGER.hpp"
#include "../libm2/game/enums.hpp"
namespace command{
bool Test::isReplaced(){
    return false;
};
bool Test::usableFor(LPCHARACTER ch){
    return true;
};
void Test::use(CHARACTER* ch,std::vector<std::string> args){
    ch->ChatPacket(1,"%i",ch->GetPoint(POINT_PARTY_ATTACKER_BONUS));
    ch->ChatPacket(1,"%i",ch->GetPoint(POINT_ATT_BONUS));
    ch->ChatPacket(1,"%i",ch->GetPoint(POINT_MELEE_MAGIC_ATT_BONUS_PER));
};
}
