#ifndef _GAME_CINPUTCLOSE_HPP
#define _GAME_CINPUTCLOSE_HPP
#include "CInputProcessor.hpp"
class CInputClose : public CInputProcessor {
  public:
    virtual BYTE GetType(void);
  protected:
    virtual int Analyze(LPDESC, BYTE, const char *);
};

#endif // _GAME_CINPUTCLOSE_HPP
