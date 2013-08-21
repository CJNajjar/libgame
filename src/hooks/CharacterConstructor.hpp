#ifndef _HOOKS_CHARACTERCONSTRUCTOR_HPP
#define _HOOKS_CHARACTERCONSTRUCTOR_HPP
#include "../libm2/lib/hook.hpp"
#include "../libm2/addr.hpp"
#include "../game/iCHARACTER.hpp"
#include "../libm2/lib/singleton.hpp"
using namespace libm2;
namespace Hooks{
typedef void (*tCharacterConstructor)(iCHARACTER* self);
class CharacterConstructor: public Hook<tCharacterConstructor,(unsigned int)Addr::CHARACTER::CHARACTER,CharacterConstructor>{
    public:
    CharacterConstructor();
    static void hook(iCHARACTER* self);
};
}
#endif // _HOOKS_CHARACTERCONSTRUCTOR_HPP


