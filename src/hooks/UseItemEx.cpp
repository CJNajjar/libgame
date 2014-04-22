#include "UseItemEx.hpp"
#include "../globals.hpp"
#include "../game/iCHARACTER.hpp"
#include "../libm2/addr.hpp"
#include "../libm2/lib/hook.hpp"
namespace Hooks{
bool UseItemExWrapper(iCHARACTER* self, LPITEM item, int iDestCell){
    return self->UseItemEx(item, iDestCell);
}
void initUseItemEx(){
    globals::instance()->UseItemEx = libm2::simpleHook<bool (*)(iCHARACTER*,LPITEM,int)>((unsigned int)libm2::Addr::CHARACTER::UseItemEx__LPITEM_int,UseItemExWrapper);
}
}
