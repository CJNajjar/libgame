#ifndef _GAME_CINPUTDEAD_HPP
#define _GAME_CINPUTDEAD_HPP
#include "CInputMain.hpp"
class CInputDead : public CInputMain {
  public:
    virtual BYTE GetType(void);
  protected:
    virtual int Analyze(LPDESC, BYTE, const char *);
};

#endif // _GAME_CINPUTDEAD_HPP
