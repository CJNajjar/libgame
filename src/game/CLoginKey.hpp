#ifndef _GAME_CLOGINKEY_HPP
#define _GAME_CLOGINKEY_HPP
#include "stdInclude.hpp"
class CLoginKey {
    DWORD m_dwKey;
    DWORD m_dwExpireTime;
    LPDESC m_pkDesc;
  public:
    CLoginKey(DWORD, LPDESC);
    void Expire(void);
    operator DWORD(void) const;
};

#endif // _GAME_CLOGINKEY_HPP
