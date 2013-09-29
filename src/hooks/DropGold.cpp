#include "DropGold.hpp"
#include "../libm2/game/enums.hpp"
#include "../libm2/game/CHARACTER.hpp"
using namespace Hooks;
DropGold::DropGold():Hook::Hook(){}

void DropGold::hook(CHARACTER* self, int c){
    self->ChatPacket(CHAT_TYPE_INFO,"Du kannst kein Yang fallen lassen.");
}
