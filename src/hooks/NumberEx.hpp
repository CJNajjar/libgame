#ifndef _HOOKS_NUMBEREX_HPP
#define _HOOKS_NUMBEREX_HPP
#include "../libm2/lib/hook.hpp"
#include "../libm2/addr.hpp"
#include "../myAddr.hpp"
using namespace libm2;
namespace Hooks {
class NumberEx: public Hook<int (*)(int, int, const char *, int),(unsigned int)myAddr::misc::number_ex,NumberEx> {
public:
    NumberEx();
    static int hook(int from, int to, const char * file, int line);
};
}
#endif // _HOOKS_NUMBEREX_HPP
