#ifndef _HOOKS_DROPGOLD_HPP
#define _HOOKS_DROPGOLD_HPP
#include "../libm2/lib/hook.hpp"
#include "../libm2/addr.hpp"
#include "../libm2/lib/singleton.hpp"
using namespace libm2;
namespace Hooks{
class DropGold: public Hook<void(*)(CHARACTER*, int),(unsigned int)Addr::CHARACTER::DropGold,DropGold>{
    public:
    DropGold();
    static void hook(CHARACTER* self, int c);
};
}
#endif // _HOOKS_DROPGOLD_HPP


