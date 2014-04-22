#include "PointChange.hpp"
#include "../globals.hpp"

#include "../libm2/addr.hpp"
#include "../libm2/lib/hook.hpp"
namespace Hooks{
void PointChangeWrapper(iCHARACTER * self, BYTE type, int ammount, bool bAmmount, bool bBroadcast){
    return self->PointChange(type, ammount, bAmmount, bBroadcast);
}
void initPointChange(){
    globals::instance()->PointChange = libm2::simpleHook<void (*)(iCHARACTER * const, BYTE, int, bool, bool)>((unsigned int)libm2::Addr::CHARACTER::PointChange__BYTE_int_bool_bool,PointChangeWrapper);
}
}
