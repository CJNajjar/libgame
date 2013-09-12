#ifndef _HOOKS_DOWAR_HPP
#define _HOOKS_DOWAR_HPP
#include "../libm2/lib/hook.hpp"
#include "../libm2/addr.hpp"
#include "../myAddr.hpp"
using namespace libm2;
namespace Hooks{
class DoWar: public Hook<void (*)(CHARACTER*, const char *, int, int),(unsigned int)myAddr::misc::do_war,DoWar>{
    public:
    DoWar();
    static void hook(CHARACTER*, const char *, int, int);
};
}
#endif // _HOOKS_DOWAR_HPP


