#ifndef __GLOBALS_HPP
#define __GLOBALS_HPP
#include <string>
#include "libm2/lib/singleton.hpp"
#include "game/iCHARACTER.hpp"
#include "libm2/utils/detours.h"
using namespace libm2;
class globals: public singleton<globals>{
public:
    std::string account;
    MologieDetours::Detour<bool (*)(iCHARACTER*,LPITEM,int)>* UseItemEx;
    MologieDetours::Detour<void (*)(iCHARACTER * const, BYTE, int, bool, bool)>* PointChange;
public:
    globals();
};
#endif // __GLOBALS_HPP
