#ifndef __GLOBALS_HPP
#define __GLOBALS_HPP
#include <string>
#include "libm2/lib/singleton.hpp"
using namespace libm2;
class globals: public singleton<globals>{
public:
    std::string account;
public:
    globals();
};
#endif // __GLOBALS_HPP
