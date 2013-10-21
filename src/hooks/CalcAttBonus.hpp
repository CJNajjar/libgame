#ifndef _HOOKS_CALCATTBONUS_HPP
#define _HOOKS_CALCATTBONUS_HPP
#include "../libm2/lib/hook.hpp"
#include "../myAddr.hpp"
#include "../libm2/game/CHARACTER.hpp"
#include "../libm2/lib/singleton.hpp"
using namespace libm2;
namespace Hooks{
class CalcAttBonus: public Hook<int(*)(CHARACTER*,CHARACTER*,int),(unsigned int)myAddr::misc::CalcAttBonus,CalcAttBonus>{
    public:
    CalcAttBonus();
    static int hook(CHARACTER* pkAttacker,CHARACTER* pkVictim,int iAtk);
};
}
#endif // _HOOKS_CALCATTBONUS_HPP


