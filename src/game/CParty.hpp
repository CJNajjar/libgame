#ifndef _GAME_CPARTY_HPP
#define _GAME_CPARTY_HPP
#include "stdInclude.hpp"
#include "CDungeon.hpp"
class CParty {
  protected:
    struct SMember {
        LPCHARACTER pCharacter;
        bool bNear;
        BYTE bRole;
        BYTE bLevel;
        std::string strName;
    };

    std::map<unsigned int, CParty::SMember, std::less<unsigned int>, std::allocator<std::pair<unsigned int const, CParty::SMember> > > m_memberMap;
    DWORD m_dwLeaderPID;
    LPCHARACTER m_pkChrLeader;
    LPEVENT m_eventUpdate;
    std::_Rb_tree_iterator<std::pair<unsigned int const, CParty::SMember> > m_itNextOwner;
  private:
    int m_iExpDistributionMode;
    LPCHARACTER m_pkChrExpCentralize;
    DWORD m_dwPartyStartTime;
    DWORD m_dwPartyHealTime;
    bool m_bPartyHealReady;
    bool m_bCanUsePartyHeal;
    int m_anRoleCount[8];
    int m_anMaxRole[8];
    int m_iLongTimeExpBonus;
    int m_iLeadership;
    int m_iExpBonus;
    int m_iAttBonus;
    int m_iDefBonus;
    int m_iCountNearPartyMember;
    bool m_bPCParty;
    std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, int, std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> > > m_map_iFlag;
    LPDUNGEON m_pkDungeon;
    LPDUNGEON m_pkDungeon_for_Only_party;

  public:
    CParty();
    ~CParty();
    void P2PJoin(DWORD);
    void P2PQuit(DWORD);
    virtual void Join(DWORD);
    void Quit(DWORD);
    void Link(LPCHARACTER);
    void Unlink(LPCHARACTER);
    void ChatPacketToAllMember(BYTE, const char *, ...);
    void UpdateOnlineState(DWORD, const char *);
    void UpdateOfflineState(DWORD);
    DWORD GetLeaderPID(void);
    LPCHARACTER GetLeaderCharacter(void);
    LPCHARACTER GetLeader(void);
    DWORD GetMemberCount(void);
    DWORD GetNearMemberCount(void);
    bool IsMember(DWORD);
    bool IsNearLeader(DWORD);
    bool IsPositionNearLeader(LPCHARACTER);
    void SendMessage(LPCHARACTER, BYTE, DWORD, DWORD);
    void SendPartyJoinOneToAll(DWORD);
    void SendPartyJoinAllToOne(LPCHARACTER);
    void SendPartyRemoveOneToAll(DWORD);
    void SendPartyInfoOneToAll(DWORD);
    void SendPartyInfoOneToAll(LPCHARACTER);
    void SendPartyInfoAllToOne(LPCHARACTER);
    void SendPartyLinkOneToAll(LPCHARACTER);
    void SendPartyLinkAllToOne(LPCHARACTER);
    void SendPartyUnlinkOneToAll(LPCHARACTER);
    int GetPartyBonusExpPercent(void);
    int GetPartyBonusAttackGrade(void);
    int GetPartyBonusDefenseGrade(void);
    int ComputePartyBonusExpPercent(void);
    int ComputePartyBonusAttackGrade(void);
    int ComputePartyBonusDefenseGrade(void);
    void Update(void);
    int GetExpBonusPercent(void);
    bool SetRole(DWORD, BYTE, bool);
    BYTE GetRole(DWORD);
    bool IsRole(DWORD, BYTE);
    BYTE GetMemberMaxLevel(void);
    BYTE GetMemberMinLevel(void);
    void ComputeRolePoint(LPCHARACTER, BYTE, bool);
    void HealParty(void);
    void SummonToLeader(DWORD);
    void SetPCParty(bool);
    LPCHARACTER GetNextOwnership(LPCHARACTER, long, long);
    void SetFlag(const std::string &, int);
    int GetFlag(const std::string &);
    void SetDungeon(LPDUNGEON);
    LPDUNGEON GetDungeon(void);
    BYTE CountMemberByVnum(DWORD);
    void SetParameter(int);
    int GetExpDistributionMode(void);
    void SetExpCentralizeCharacter(DWORD);
    LPCHARACTER GetExpCentralizeCharacter(void);
    void RequestSetMemberLevel(DWORD, BYTE);
    void P2PSetMemberLevel(DWORD, BYTE);
  protected:
    void IncreaseOwnership(void);
    virtual void Initialize(void);
    void Destroy(void);
    void RemovePartyBonus(void);
    void RemoveBonus(void);
    void RemoveBonusForOne(DWORD);
    void SendParameter(LPCHARACTER);
    void SendParameterToAll(void);
  public:
    void SetDungeon_for_Only_party(LPDUNGEON);
    LPDUNGEON GetDungeon_for_Only_party(void);
    //void ForEachOnlineMember<NPartyPickupDistribute::FFindOwnership>(NPartyPickupDistribute::FFindOwnership &);
    //void ForEachOnlineMember<NPartyPickupDistribute::FMoneyDistributor>(NPartyPickupDistribute::FMoneyDistributor &);
    //void ForEachOnlineMember<NPartyPickupDistribute::FCountNearMember>(NPartyPickupDistribute::FCountNearMember &);
};

#endif // _GAME_CPARTY_HPP
