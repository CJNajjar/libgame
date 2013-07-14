#ifndef _GAME_CWARMAP_HPP
#define _GAME_CWARMAP_HPP
#include "stdInclude.hpp"
#include "PIXEL_POSITION.hpp"
#include "EVENT.hpp"
struct SWarMapInfo {
    BYTE bType;
    long lMapIndex;
    PIXEL_POSITION posStart[3];
} typedef TWarMapInfo;

typedef char $_112[15];

class CWarMap {
  public:
    class STeamData {
        DWORD dwID;
        CGuild *pkGuild;
        int iMemberCount;
        int iUsePotionPrice;
        int iScore;
        LPCHARACTER pkChrFlag;
        LPCHARACTER pkChrFlagBase;
        std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > set_pidJoiner;
      public:
        void Initialize(void);
        int GetAccumulatedJoinerCount(void);
        int GetCurJointerCount(void);
        void AppendMember(LPCHARACTER);
        void RemoveMember(LPCHARACTER);
    };
  private:
    TWarMapInfo m_kMapInfo;
    bool m_bEnded;
    LPEVENT m_pkBeginEvent;
    LPEVENT m_pkTimeoutEvent;
    LPEVENT m_pkEndEvent;
    LPEVENT m_pkResetFlagEvent;
    CWarMap::STeamData m_TeamData[2];
    int m_iObserverCount;
    DWORD m_dwStartTime;
    BYTE m_bTimeout;
    $_112 m_WarInfo;
    CHARACTER_SET m_set_pkChr;

  public:
    CWarMap(long, const $_112 &, TWarMapInfo *, DWORD, DWORD);
    ~CWarMap();
    bool GetTeamIndex(DWORD, BYTE &);
    void IncMember(LPCHARACTER);
    void DecMember(LPCHARACTER);
    CGuild * GetGuild(BYTE);
    DWORD GetGuildID(BYTE);
    BYTE GetType(void);
    long GetMapIndex(void);
    DWORD GetGuildOpponent(LPCHARACTER);
    DWORD GetWinnerGuild(void);
    void UsePotion(LPCHARACTER, LPITEM);
    void Draw(void);
    void Timeout(void);
    void CheckWarEnd(void);
    bool SetEnded(void);
    void ExitAll(void);
    void SetBeginEvent(LPEVENT);
    void SetTimeoutEvent(LPEVENT);
    void SetEndEvent(LPEVENT);
    void SetResetFlagEvent(LPEVENT);
    void UpdateScore(DWORD, int, DWORD, int);
    bool CheckScore(void);
    int GetRewardGold(BYTE);
    bool GetGuildIndex(DWORD, int &);
    void Packet(const void *, int);
    void Notice(const char *);
    void SendWarPacket(LPDESC);
    void SendScorePacket(BYTE, LPDESC);
    void OnKill(LPCHARACTER, LPCHARACTER);
    void AddFlag(BYTE, DWORD, DWORD);
    void AddFlagBase(BYTE, DWORD, DWORD);
    void RemoveFlag(BYTE);
    bool IsFlagOnBase(BYTE);
    void ResetFlag(void);
  private:
    void UpdateUserCount(void);
};

#endif // _GAME_CWARMAP_HPP
