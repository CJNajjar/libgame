#ifndef _GAME_CINPUTAUTH_HPP
#define _GAME_CINPUTAUTH_HPP
#include "CInputProcessor.hpp"
class CInputAuth : public CInputProcessor {
  public:
    CInputAuth();
    virtual BYTE GetType(void);
  protected:
    virtual int Analyze(LPDESC, BYTE, const char *);
    int auth_OpenID(const char *, const char *, char *);
  public:
    void Login(LPDESC, const char *);
    void LoginOpenID(LPDESC, const char *);
    void PasspodAnswer(LPDESC, const char *);
};

#endif // _GAME_CINPUTAUTH_HPP
