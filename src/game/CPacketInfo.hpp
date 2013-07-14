#ifndef _GAME_CPACKETINFO_HPP
#define _GAME_CPACKETINFO_HPP
#include "stdInclude.hpp"
struct SPacketElement {
    int iSize;
    std::string stName;
    int iCalled;
    DWORD dwLoad;
    bool bSequencePacket;
};
typedef SPacketElement TPacketElement;

class CPacketInfo {
  protected:
    std::map<int, SPacketElement*, std::less<int>, std::allocator<std::pair<int const, SPacketElement*> > > m_pPacketMap;
    TPacketElement *m_pCurrentPacket;
    DWORD m_dwStartTime;

  public:
    CPacketInfo();
    ~CPacketInfo();
    void Set(int, int, const char *, bool);
    bool Get(int, int *, const char **);
    void Start(void);
    void End(void);
    void Log(const char *);
    bool IsSequence(int);
    void SetSequence(int, bool);
  private:
    TPacketElement * GetElement(int);
};
class CPacketInfoCG : public CPacketInfo {
  public:
    CPacketInfoCG();
    ~CPacketInfoCG();
};
#endif // _GAME_CPACKETINFO_HPP
