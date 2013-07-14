#ifndef _GAME_CAFFECT_HPP
#define _GAME_CAFFECT_HPP
#include "stdInclude.hpp"
struct CAffect {
    DWORD dwType;
    BYTE bApplyOn;
    long lApplyValue;
    DWORD dwFlag;
    long lDuration;
    long lSPCost;
  public:
    static CAffect * Acquire(void);
    static void Release(CAffect *);
};

#endif // _GAME_CAFFECT_HPP
