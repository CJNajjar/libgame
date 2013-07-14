#ifndef _GAME_CGUILD_HPP
#define _GAME_CGUILD_HPP

struct SGuildGrade {
    char grade_name[9];
    BYTE auth_flag;
} typedef TGuildGrade;

struct SGuildData {
    DWORD guild_id;
    DWORD master_pid;
    DWORD exp;
    BYTE level;
    char name[13];
    TGuildGrade grade_array[15];
    BYTE skill_point;
    BYTE abySkill[12];
    int power;
    int max_power;
    int ladder_point;
    int win;
    int draw;
    int loss;
    int gold;
} typedef TGuildData;

class SGuildWar {
    DWORD war_start_time;
    DWORD score;
    DWORD state;
    BYTE type;
    DWORD map_index;
  public:
    SGuildWar(BYTE);
    bool IsWarBegin(void) const;
};

class SGuildMember {
    DWORD pid;
    BYTE grade;
    BYTE is_general;
    BYTE job;
    BYTE level;
    DWORD offer_exp;
    BYTE _dummy;
    std::string name;
  public:
    SGuildMember(LPCHARACTER, BYTE, DWORD);
    SGuildMember(DWORD, BYTE, BYTE, BYTE, BYTE, DWORD, char *);
} typedef TGuildMember;

struct TGuildCreateParameter {
    LPCHARACTER master;
    char name[13];
};
struct SPacketDGGuildMember {
    DWORD dwPID;
    DWORD dwGuild;
    BYTE bGrade;
    BYTE isGeneral;
    BYTE bJob;
    BYTE bLevel;
    DWORD dwOffer;
    char szName[25];
} typedef TPacketDGGuildMember;

class CGuild {
    public:
 enum GuildJoinErrCode {GERR_NONE,
    GERR_WITHDRAWPENALTY, GERR_COMMISSIONPENALTY,
    GERR_ALREADYJOIN, GERR_GUILDISFULL,
    GERR_GUILD_IS_IN_WAR, GERR_INVITE_LIMIT, GERR_MAX};
  private:
    TGuildData m_data;
    int m_general_count;
    int m_iMemberCountBonus;
    std::map<unsigned int, SGuildMember, std::less<unsigned int>, std::allocator<std::pair<unsigned int const, SGuildMember> > > m_member;
    CHARACTER_SET m_memberOnline;
    std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > m_memberP2POnline;
    std::map<unsigned int, SGuildWar, std::less<unsigned int>, std::allocator<std::pair<unsigned int const, SGuildWar> > > m_EnemyGuild;
    std::map<unsigned int, unsigned int, std::less<unsigned int>, std::allocator<std::pair<unsigned int const, unsigned int> > > m_mapGuildWarEndTime;
    bool abSkillUsable[12];
    std::map<unsigned int, boost::intrusive_ptr<event>, std::less<unsigned int>, std::allocator<std::pair<unsigned int const, boost::intrusive_ptr<event> > > > m_GuildInviteEventMap;

  public:
    CGuild(DWORD);
    CGuild(TGuildCreateParameter &);
    ~CGuild();
    DWORD GetID(void) const;
    const char * GetName(void) const;
    int GetSP(void) const;
    int GetMaxSP(void);
    DWORD GetMasterPID(void) const;
    LPCHARACTER GetMasterCharacter(void);
    BYTE GetLevel(void) const;
    void Reset(void);
    void RequestDisband(DWORD);
    void Disband(void);
    void RequestAddMember(LPCHARACTER, int);
    void AddMember(TPacketDGGuildMember *);
    bool RequestRemoveMember(DWORD);
    bool RemoveMember(DWORD);
    void LoginMember(LPCHARACTER);
    void P2PLoginMember(DWORD);
    void LogoutMember(LPCHARACTER);
    void P2PLogoutMember(DWORD);
    void ChangeMemberGrade(DWORD, BYTE);
    bool OfferExp(LPCHARACTER, int);
    void LevelChange(DWORD, BYTE);
    void ChangeMemberData(DWORD, DWORD, BYTE, BYTE);
    void ChangeGradeName(BYTE, const char *);
    void ChangeGradeAuth(BYTE, BYTE);
    void P2PChangeGrade(BYTE);
    bool ChangeMemberGeneral(DWORD, BYTE);
    bool ChangeMasterTo(DWORD);
    void Packet(const void *, int);
    void SendOnlineRemoveOnePacket(DWORD);
    void SendAllGradePacket(LPCHARACTER);
    void SendListPacket(LPCHARACTER);
    void SendListOneToAll(DWORD);
    void SendListOneToAll(LPCHARACTER);
    void SendLoginPacket(LPCHARACTER, LPCHARACTER);
    void SendLoginPacket(LPCHARACTER, DWORD);
    void SendLogoutPacket(LPCHARACTER, LPCHARACTER);
    void SendLogoutPacket(LPCHARACTER, DWORD);
    void SendGuildInfoPacket(LPCHARACTER);
    void SendGuildDataUpdateToAllMember(void /* SQLMsg*/ *);
    void Load(DWORD);
    void SaveLevel(void);
    void SaveSkill(void);
    void SaveMember(DWORD);
    int GetMaxMemberCount(void);
    int GetMemberCount(void);
    int GetTotalLevel(void) const;
    void SetMemberCountBonus(int);
    void BroadcastMemberCountBonus(void);
    int GetMaxGeneralCount(void) const;
    int GetGeneralCount(void) const;
    TGuildMember * GetMember(DWORD);
    DWORD GetMemberPID(const std::string &);
    bool HasGradeAuth(int, int) const;
    void AddComment(LPCHARACTER, const std::string &);
    void DeleteComment(LPCHARACTER, DWORD);
    void RefreshComment(LPCHARACTER);
    void RefreshCommentForce(DWORD);
    int GetSkillLevel(DWORD);
    void SkillLevelUp(DWORD);
    void UseSkill(DWORD, LPCHARACTER, DWORD);
    void SendSkillInfoPacket(LPCHARACTER) const;
    void ComputeGuildPoints(void);
    void GuildPointChange(BYTE, int, bool);
    void UpdateSkill(BYTE, BYTE *);
    void SendDBSkillUpdate(int);
    void SkillRecharge(void);
    bool ChargeSP(LPCHARACTER, int);
    void Chat(const char *);
    void P2PChat(const char *);
    void SkillUsableChange(DWORD, bool);
    void AdvanceLevel(int);
    void RequestDepositMoney(LPCHARACTER, int);
    void RequestWithdrawMoney(LPCHARACTER, int);
    void RecvMoneyChange(int);
    void RecvWithdrawMoneyGive(int);
    int GetGuildMoney(void) const;
    void GuildWarPacket(DWORD, BYTE, BYTE);
    void SendEnemyGuild(LPCHARACTER);
    int GetGuildWarState(DWORD);
    bool CanStartWar(BYTE);
    DWORD GetWarStartTime(DWORD);
    bool UnderWar(DWORD);
    DWORD UnderAnyWar(BYTE);
    void SetGuildWarMapIndex(DWORD, long);
    int GetGuildWarType(DWORD);
    DWORD GetGuildWarMapIndex(DWORD);
    void GuildWarEntryAsk(DWORD);
    void GuildWarEntryAccept(DWORD, LPCHARACTER);
    void NotifyGuildMaster(const char *);
    void RequestDeclareWar(DWORD, BYTE);
    void RequestRefuseWar(DWORD);
    bool DeclareWar(DWORD, BYTE, BYTE);
    void RefuseWar(DWORD);
    bool WaitStartWar(DWORD);
    bool CheckStartWar(DWORD);
    void StartWar(DWORD);
    void EndWar(DWORD);
    void ReserveWar(DWORD, BYTE);
    void SetWarScoreAgainstTo(DWORD, int);
    int GetWarScoreAgainstTo(DWORD);
    int GetLadderPoint(void) const;
    void SetLadderPoint(int);
    void SetWarData(int, int, int);
    void ChangeLadderPoint(int);
    int GetGuildWarWinCount(void) const;
    int GetGuildWarDrawCount(void) const;
    int GetGuildWarLossCount(void) const;
    bool HasLand(void);
    void Invite(LPCHARACTER, LPCHARACTER);
    void InviteAccept(LPCHARACTER);
    void InviteDeny(DWORD);
  private:
    void Initialize(void);
    void LoadGuildData(void /*SQLMsg*/ *);
    void LoadGuildGradeData(void /*SQLMsg*/ *);
    void LoadGuildMemberData(void /*SQLMsg*/ *);
    void __P2PUpdateGrade(void /*SQLMsg*/ *);
    CGuild::GuildJoinErrCode VerifyGuildJoinableCondition(LPCHARACTER);
};
#endif // _GAME_CGUILD_HPP
