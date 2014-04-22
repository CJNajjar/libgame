#ifndef __HOOKS_POINTCHANGE_HPP
#define __HOOKS_POINTCHANGE_HPP
#include "../game/iCHARACTER.hpp"
using namespace libm2;
namespace Hooks{
void PointChangeWrapper(iCHARACTER * self, BYTE type, int ammount, bool bAmmount, bool bBroadcast);
void initPointChange();
}
#endif // __HOOKS_POINTCHANGE_HPP
