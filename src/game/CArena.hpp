#ifndef _GAME_CARENA_HPP
#define _GAME_CARENA_HPP
#include "stdInclude.hpp"
#include "EVENT.hpp"
#include "PIXEL_POSITION.hpp"
#include "CHARACTER.hpp"

class CArena {
  private:
    DWORD m_dwPIDA;
    DWORD m_dwPIDB;
    LPEVENT m_pEvent;
    LPEVENT m_pTimeOutEvent;
    PIXEL_POSITION m_StartPointA;
    PIXEL_POSITION m_StartPointB;
    PIXEL_POSITION m_ObserverPoint;
    DWORD m_dwSetCount;
    DWORD m_dwSetPointOfA;
    DWORD m_dwSetPointOfB;
    std::map<unsigned int, CHARACTER*, std::less<unsigned int>, std::allocator<std::pair<unsigned int const, CHARACTER*> > > m_mapObserver;

  protected:
    CArena(WORD, WORD, WORD, WORD);
    bool StartDuel(LPCHARACTER, LPCHARACTER, int, int);
    bool IsEmpty(void) const;
    bool IsMember(DWORD) const;
    bool CheckArea(WORD, WORD, WORD, WORD);
    void Clear(void);
    bool CanAttack(DWORD, DWORD);
    bool OnDead(DWORD, DWORD);
    bool IsObserver(DWORD);
    bool IsMyObserver(WORD, WORD);
    bool AddObserver(LPCHARACTER);
    bool RegisterObserverPtr(LPCHARACTER);
  public:
    DWORD GetPlayerAPID(void);
    DWORD GetPlayerBPID(void);
    LPCHARACTER GetPlayerA(void);
    LPCHARACTER GetPlayerB(void);
    PIXEL_POSITION GetStartPointA(void);
    PIXEL_POSITION GetStartPointB(void);
    PIXEL_POSITION GetObserverPoint(void);
    void EndDuel(void);
    void ClearEvent(void);
    void OnDisconnect(DWORD);
    void RemoveObserver(DWORD);
    void SendPacketToObserver(const void *, int);
    void SendChatPacketToObserver(BYTE, const char *, ...);
};
#endif
