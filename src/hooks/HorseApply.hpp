#ifndef __HOOKS_HORSEAPPLY_HPP
#define __HOOKS_HORSEAPPLY_HPP
#include "../libm2/lib/singleton.hpp"
#include "../libm2/lib/hook.hpp"
#include "../libm2/addr.hpp"
#include "../libm2/game/quest/CQuestManager.hpp"
#include "../libm2/game/CHARACTER.hpp"
using namespace libm2;
namespace Hooks{
class HorseApply: public singleton<HorseApply>{
private:
    MologieDetours::Detour<bool(*)(CHARACTER*)>*detour_StartRiding;
    MologieDetours::Detour<bool(*)(CHARACTER*)>*detour_StopRiding;
public:
    HorseApply();
    static bool StartRiding(CHARACTER*);
    static bool StopRiding(CHARACTER*);
};
}
#endif // __HOOKS_HORSEAPPLY_HPP
