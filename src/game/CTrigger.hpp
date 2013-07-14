#ifndef _GAME_CTRIGGER_HPP
#define _GAME_CTRIGGER_HPP
#include "stdInclude.hpp"
class CTrigger {
    BYTE bType;
    int (*pFunc)(LPCHARACTER, LPCHARACTER);
  public:
    CTrigger(void);
};

#endif // _GAME_CTRIGGER_HPP

