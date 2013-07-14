#ifndef _GAME_VID_HPP
#define _GAME_VID_HPP
#include "stdInclude.hpp"
class VID {
  private:
    DWORD m_id;
    DWORD m_crc;

  public:
    VID(void);
    VID(DWORD, DWORD);
    VID(const VID &);
    const VID & operator=(const VID &);
    bool operator==(const VID &) const;
    bool operator!=(const VID &) const;
    operator DWORD(void) const;
    void Reset(void);
};
#endif // _GAME_VID_HPP
