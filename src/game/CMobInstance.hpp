#ifndef _GAME_CMOBINSTANCE_HPP
#define _GAME_CMOBINSTANCE_HPP
#include "stdInclude.hpp"
#include "PIXEL_POSITION.hpp"

class CMobInstance {
    PIXEL_POSITION m_posLastAttacked;
    DWORD m_dwLastAttackedTime;
    DWORD m_dwLastWarpTime;
    bool m_IsBerserk;
    bool m_IsGodSpeed;
    bool m_IsRevive;
  public:
    CMobInstance(void);
};

#endif // _GAME_CMOBINSTANCE_HPP
