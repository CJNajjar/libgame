#ifndef __HOOKS_USEITEMEX_HPP
#define __HOOKS_USEITEMEX_HPP
#include "../game/iCHARACTER.hpp"
using namespace libm2;
namespace Hooks{
bool UseItemExWrapper(iCHARACTER* self, LPITEM item, int iDestCell);
void initUseItemEx();
}
#endif // __HOOKS_USEITEMEX_HPP
