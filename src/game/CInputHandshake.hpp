#ifndef _GAME_CINPUTHANDSHAKE_HPP
#define _GAME_CINPUTHANDSHAKE_HPP
#include "CInputProcessor.hpp"
class CInputHandshake : public CInputProcessor {
  protected:
    CPacketInfo *m_pMainPacketInfo;
  public:
    CInputHandshake();
    ~CInputHandshake();
    virtual BYTE GetType(void);
  protected:
    virtual int Analyze(LPDESC, BYTE, const char *);
    void GuildMarkLogin(LPDESC, const char *);
};

#endif // _GAME_CINPUTHANDSHAKE_HPP
