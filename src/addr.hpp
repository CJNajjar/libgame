/*
GAME_REV:
    1 -> 2089M
    2 -> 2089
*/
#ifndef __ADDR_HPP
#define __ADDR_HPP
#if GAME_REV==2
#include "addr/2089.hpp"
#else
#include "addr/2089M.hpp"
#endif
#endif // __ADDR_HPP
