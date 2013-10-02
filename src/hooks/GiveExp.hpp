#ifndef _HOOKS_GIVEEXP_HPP
#define _HOOKS_GIVEEXP_HPP
#include "../libm2/lib/hook.hpp"
#include "../myAddr.hpp"
#include "../libm2/lib/singleton.hpp"
#include "../libm2/game/CHARACTER.hpp"
using namespace libm2;
namespace Hooks{
extern const int* aiPercentByDeltaLev_euckr;
long long AdjustExpByLevel(CHARACTER* ch,long long exp);
class GiveExp: public Hook<__attribute__((regparm(3)))  void(*)(CHARACTER*,CHARACTER*, int),(unsigned int)myAddr::misc::GiveExp,GiveExp>{
    public:
    GiveExp();
    __attribute__((regparm(3))) static void hook(CHARACTER* from,CHARACTER*to, int iExp);
};
}
#endif // _HOOKS_GIVEEXP_HPP


