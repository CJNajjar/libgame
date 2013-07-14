#ifndef _GAME_CINPUTPROCESSOR_HPP
#define _GAME_CINPUTPROCESSOR_HPP
#include "stdInclude.hpp"
#include "DESC.hpp"
#include "CPacketInfo.hpp"
class CInputProcessor {
  protected:
    CPacketInfo *m_pPacketInfo;
    int m_iBufferLeft;
    CPacketInfoCG m_packetInfoCG;

  public:
    CInputProcessor();
    ~CInputProcessor();
    virtual bool Process(LPDESC, const void *, int, int &);
    virtual BYTE GetType(void);
    void BindPacketInfo(CPacketInfo *);
    void Pong(LPDESC);
    void Handshake(LPDESC, const char *);
    void Version(LPCHARACTER, const char *);
  protected:
    virtual int Analyze(LPDESC, BYTE, const char *);
};
#endif // _GAME_CINPUTPROCESSOR_HPP
