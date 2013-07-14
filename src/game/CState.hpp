#ifndef _GAME_CSTATE_HPP
#define _GAME_CSTATE_HPP
class CState {
  public:
    ~CState();
    virtual void ExecuteBeginState(void);
    virtual void ExecuteState(void);
    virtual void ExecuteEndState(void);
};
#endif // _GAME_CSTATE_HPP
