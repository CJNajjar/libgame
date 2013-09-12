#ifndef _HOOKS_DOWAR_HPP
#define _HOOKS_DOWAR_HPP
#include "../libm2/lib/hook.hpp"
#include "../libm2/addr.hpp"
#include "../myAddr.hpp"
using namespace libm2;
namespace Hooks{
class NumberEx: public Hook<int (*)(int, int, const char *, int),(unsigned int)myAddr::misc::number_ex,NumberEx>{
    public:
    NumberEx();
    static void hook(int, int, const char *, int));
};
}
#endif // _HOOKS_DOWAR_HPP


