#ifndef _GAME_CHARACTER_HPP
#define _GAME_CHARACTER_HPP
#include "stdInclude.hpp"
#include "CEntity.hpp"
#include "CFSM.hpp"
#include "CHorseRider.hpp"
#include "CAffect.hpp"
#include "VID.hpp"
#include "CItem.hpp"
#include "CParty.hpp"
#include "EVENT.hpp"
#include "CGuild.hpp"
#include "CWarMap.hpp"
#include "CShop.hpp"
#include "CExchange.hpp"
#include "CTrigger.hpp"
#include "CSafebox.hpp"
#include "CPetSystem.hpp"
#include "marriage/WeddingMap.hpp"
#include "CMob.hpp"
#include "CMobInstance.hpp"
#include "CArena.hpp"
#include "misc.hpp"
#include "CBuffOnAttributes.hpp"
#include "SPlayerTable.hpp"
#include "packet.hpp"
#include "../addr.hpp"

struct character_point {
    long points[255];
    BYTE job;
    BYTE voice;
    BYTE level;
    DWORD exp;
    long gold;
    int hp;
    int sp;
    int iRandomHP;
    int iRandomSP;
    int stamina;
    BYTE skill_group;
} typedef CHARACTER_POINT;

struct character_point_instant {
    long points[255];
    float fRot;
    int iMaxHP;
    int iMaxSP;
    long position;
    long instant_flag;
    DWORD dwAIFlag;
    DWORD dwImmuneFlag;
    DWORD dwLastShoutPulse;
    WORD parts[4];
    LPITEM pItems[111];
    BYTE bItemGrid[111];
    LPITEM pCubeItems[15];
    LPCHARACTER pCubeNpc;
    LPCHARACTER battle_victim;
    BYTE gm_level;
    BYTE bBasePart;
    int iMaxStamina;
    BYTE bBlockMode;
} typedef CHARACTER_POINT_INSTANT;

typedef std::list<CHARACTER*, std::allocator<CHARACTER*> > CHARACTER_LIST;


class TAffectFlag {
    DWORD bits[2];
  public:
    TAffectFlag();
    TAffectFlag(DWORD, DWORD);
    bool IsSet(int) const;
    void Set(int);
    void Reset(int);
    TAffectFlag & operator=(const TAffectFlag &);
};


class TSkillUseInfo {
    int iHitCount;
    int iMaxHitCount;
    int iSplashCount;
    DWORD dwNextSkillUsableTime;
    int iRange;
    bool bUsed;
    DWORD dwVID;
    bool isGrandMaster;
    boost::unordered_map<VID, unsigned int, boost::hash<VID>, std::equal_to<VID>, std::allocator<std::pair<VID const, unsigned int> > > TargetVIDMap;
  public:
    TSkillUseInfo(void);
    bool HitOnce(DWORD);
    bool UseSkill(bool, DWORD, DWORD, int, int, int);
    DWORD GetMainTargetVID(void) const;
    void SetMainTargetVID(DWORD);
    void ResetHitCount(void);
};

class CHARACTER : public CEntity, public CFSM, public CHorseRider {
  public:
    class TBattleInfo {
        int iTotalDamage;
        int iAggro;
      public:
        TBattleInfo(int, int);
    };
    struct SAttackLog {
        DWORD dwVID;
        DWORD dwTime;
    };
    class AttackedLog {
        DWORD dwPID;
        DWORD dwAttackedTime;
      public:
        AttackedLog(void);
    };
    enum PartyJoinErrCode {
        PERR_NONE,
        PERR_SERVER,
        PERR_DUNGEON,
        PERR_OBSERVER,
        PERR_LVBOUNDARY,
        PERR_LOWLEVEL,
        PERR_HILEVEL,
        PERR_ALREADYJOIN,
        PERR_PARTYISFULL,
        PERR_SEPARATOR,
        PERR_DIFFEMPIRE,
        PERR_MAX
    };
    enum MONARCH_INDEX {MI_HEAL, MI_WARP, MI_TRANSFER, MI_TAX, MI_SUMMON, MI_MAX};


  protected:
    CStateTemplate<CHARACTER> m_stateMove;
    CStateTemplate<CHARACTER> m_stateBattle;
    CStateTemplate<CHARACTER> m_stateIdle;
    DWORD m_dwStateDuration;
    DWORD m_dwPolymorphRace;
    bool m_bPolyMaintainStat;
    DWORD m_dwLoginPlayTime;
    DWORD m_dwPlayerID;
    VID m_vid;
    std::string m_stName;
    BYTE m_bCharType;
    CHARACTER_POINT m_points;
    CHARACTER_POINT_INSTANT m_pointsInstant;
    int m_iMoveCount;
    DWORD m_dwPlayStartTime;
    BYTE m_bAddChrState;
    bool m_bSkipSave;
    std::string m_stMobile;
    char m_szMobileAuth[5];
    BYTE m_bChatCounter;
    float m_fSyncTime;
    LPCHARACTER m_pkChrSyncOwner;
    CHARACTER_LIST m_kLst_pkChrSyncOwned;
    PIXEL_POSITION m_posDest;
    PIXEL_POSITION m_posStart;
    PIXEL_POSITION m_posWarp;
    long m_lWarpMapIndex;
    PIXEL_POSITION m_posExit;
    long m_lExitMapIndex;
    DWORD m_dwMoveStartTime;
    DWORD m_dwMoveDuration;
    DWORD m_dwLastMoveTime;
    DWORD m_dwLastAttackTime;
    DWORD m_dwWalkStartTime;
    DWORD m_dwStopTime;
    bool m_bWalking;
    bool m_bNowWalking;
    bool m_bStaminaConsume;
    TQuickslot m_quickslot[36];
    bool m_bIsLoadedAffect;
    TAffectFlag m_afAffectFlag;
    std::list<CAffect*, std::allocator<CAffect*> > m_list_pkAffect;
    LPPARTY m_pkParty;
    DWORD m_dwLastDeadTime;
    LPEVENT m_pkPartyRequestEvent;
    std::map<unsigned int, boost::intrusive_ptr<event>, std::less<unsigned int>, std::allocator<std::pair<unsigned int const, boost::intrusive_ptr<event> > > > m_PartyInviteEventMap;
    LPDUNGEON m_pkDungeon;
    int m_iEventAttr;
    CGuild *m_pGuild;
    DWORD m_dwUnderGuildWarInfoMessageTime;

    CWarMap *m_pWarMap;
    bool m_bNoOpenedShop;
    bool m_bItemLoaded;
    int m_iRefineAdditionalCell;
    bool m_bUnderRefine;
    DWORD m_dwRefineNPCVID;
    LPSHOP m_pkShop;
    LPSHOP m_pkMyShop;
    std::string m_stShopSign;
    LPCHARACTER m_pkChrShopOwner;
    CExchange *m_pkExchange;
    BYTE m_bComboSequence;
    DWORD m_dwLastComboTime;
    int m_iValidComboInterval;
    BYTE m_bComboIndex;
    int m_iComboHackCount;
    DWORD m_dwSkipComboAttackByTime;
    DWORD m_dwFlyTargetID;
    std::vector<unsigned int, std::allocator<unsigned int> > m_vec_dwFlyTargets;
    std::map<VID, CHARACTER::TBattleInfo, std::less<VID>, std::allocator<std::pair<VID const, CHARACTER::TBattleInfo> > > m_map_kDamage;
    DWORD m_dwKillerPID;
    int m_iAlignment;
    int m_iRealAlignment;
    int m_iKillerModePulse;
    BYTE m_bPKMode;
    DWORD m_dwLastVictimSetTime;
    int m_iMaxAggro;
    LPCHARACTER m_pkChrStone;
    CHARACTER_SET m_set_pkChrSpawnedBy;
    DWORD m_dwDropMetinStone;
    BYTE m_bDropMetinStonePct;
  private:
    bool m_bDisableCooltime;
    DWORD m_dwLastSkillTime;
  protected:
    DWORD m_adwMobSkillCooltime[5];
  private:
    LPEVENT m_pkMuyeongEvent;
    int m_iChainLightingIndex;
    CHARACTER_SET m_setExceptChainLighting;
    DWORD m_dwAffectedEunhyungLevel;
  protected:
    TPlayerSkill *m_pSkillLevels;
    boost::unordered_map<unsigned char, int, boost::hash<unsigned char>, std::equal_to<unsigned char>, std::allocator<std::pair<unsigned char const, int> > > m_SkillDamageBonus;
    std::map<int, TSkillUseInfo, std::less<int>, std::allocator<std::pair<int const, TSkillUseInfo> > > m_SkillUseInfo;
  public:
    VID m_kVIDVictim;
  protected:
    DWORD m_dwLastChangeAttackPositionTime;
    CTrigger m_triggerOnClick;
    LPCHARACTER m_pkChrTarget;
    CHARACTER_SET m_set_pkChrTargetedBy;
    CSafebox *m_pkSafebox;
    int m_iSafeboxSize;
    int m_iSafeboxLoadTime;
    bool m_bOpeningSafebox;
    CSafebox *m_pkMall;
    int m_iMallLoadTime;
    PIXEL_POSITION m_posSafeboxOpen;
    CPetSystem *m_petSystem;
    LPCHARACTER m_chHorse;
    LPCHARACTER m_chRider;
    DWORD m_dwMountVnum;
    DWORD m_dwMountTime;
    BYTE m_bSendHorseLevel;
    BYTE m_bSendHorseHealthGrade;
    BYTE m_bSendHorseStaminaGrade;
  private:
    bool m_bDetailLog;
    bool m_bMonsterLog;
  protected:
    BYTE m_bEmpire;
    PIXEL_POSITION m_posRegen;
    float m_fRegenAngle;
    LPREGEN m_pkRegen;
    size_t regen_id_;
  private:
    DWORD m_dwQuestNPCVID;
    DWORD m_dwQuestByVnum;
    LPITEM m_pQuestItem;
  protected:
    DWORD m_dwNextStatePulse;
  private:
    marriage::WeddingMap *m_pWeddingMap;
    LPCHARACTER m_pkChrMarried;
  public:
    LPEVENT m_pkDeadEvent;
    LPEVENT m_pkStunEvent;
    LPEVENT m_pkSaveEvent;
    LPEVENT m_pkRecoveryEvent;
    LPEVENT m_pkTimedEvent;
    LPEVENT m_pkFishingEvent;
    LPEVENT m_pkAffectEvent;
    LPEVENT m_pkPoisonEvent;
    LPEVENT m_pkFireEvent;
    LPEVENT m_pkWarpNPCEvent;
    LPEVENT m_pkMiningEvent;
    LPEVENT m_pkWarpEvent;
    LPEVENT m_pkCheckSpeedHackEvent;
    LPEVENT m_pkDestroyWhenIdleEvent;
    LPEVENT m_pkPetSystemUpdateEvent;
    bool m_bHasPoisoned;
    const CMob *m_pkMobData;
    CMobInstance *m_pkMobInst;
    std::map<int, boost::intrusive_ptr<event>, std::less<int>, std::allocator<std::pair<int const, boost::intrusive_ptr<event> > > > m_mapMobSkillEvent;
  private:
    int m_aiPremiumTimes[9];
    static const DWORD msc_dwDefaultChangeItemAttrCycle;
    static char msc_szLastChangeItemAttrFlag[];
    static char msc_szChangeItemAttrCycleFlag[];
    bool m_isinPCBang;
    CArena *m_pArena;
    bool m_ArenaObserver;
    int m_nPotionLimit;
    bool m_isOpenSafebox;
  public:
    int m_iRefineTime;
    int m_iSeedTime;
    int m_iExchangeTime;
    int m_iMyShopTime;
    DWORD m_dwMonarchCooltime[5];
    DWORD m_dwMonarchCooltimelimit[5];
  private:
    e_overtime m_eOverTime;
    int m_deposit_pulse;
  public:
    CHARACTER::SAttackLog m_kAttackLog;
    CHARACTER::AttackedLog m_AttackedLog;
    int m_speed_hack_count;
  private:
    std::string m_strNewName;
    std::set<unsigned int, std::less<unsigned int>, std::allocator<unsigned int> > m_known_guild;
    DWORD m_dwLogOffInterval;
    DWORD m_dwLastGoldDropTime;
  public:
    LPEVENT m_HackShieldCheckEvent;
  private:
    bool m_HackShieldCheckMode;
    std::map<unsigned char, CBuffOnAttributes*, std::less<unsigned char>, std::allocator<std::pair<unsigned char const, CBuffOnAttributes*> > > m_map_buff_on_attrs;
    bool cannot_dead;
    bool m_bIsPet;
    float m_fAttMul;
    float m_fDamMul;
  protected:
    virtual void EncodeInsertPacket(LPENTITY);
    virtual void EncodeRemovePacket(LPENTITY);
  public:
    LPCHARACTER FindCharacterInView(const char *, bool);
    void UpdatePacket(void);
    virtual void StateMove(void);
    virtual void StateBattle(void);
    virtual void StateIdle(void);
    virtual void StateFlag(void);
    virtual void StateFlagBase(void);
    void StateHorse(void);
  protected:
    void __StateIdle_Monster(void);
    void __StateIdle_Stone(void);
    void __StateIdle_NPC(void);
  public:
    DWORD GetAIFlag(void) const;
    void SetAggressive(void);
    bool IsAggressive(void) const;
    void SetCoward(void);
    bool IsCoward(void) const;
    void CowardEscape(void);
    void SetNoAttackShinsu(void);
    bool IsNoAttackShinsu(void) const;
    void SetNoAttackChunjo(void);
    bool IsNoAttackChunjo(void) const;
    void SetNoAttackJinno(void);
    bool IsNoAttackJinno(void) const;
    void SetAttackMob(void);
    bool IsAttackMob(void) const;
    virtual void BeginStateEmpty(void);
    virtual void EndStateEmpty(void);
    void RestartAtSamePos(void);
    CHARACTER(void);
    ~CHARACTER();
    void Create(const char *, DWORD, bool);
    void Destroy(void);
    void Disconnect(const char *);
  protected:
    void Initialize(void);
  public:
    DWORD GetPlayerID(void) const;
    void SetPlayerProto(const TPlayerTable *);
    void CreatePlayerProto(TPlayerTable &);
    void SetProto(const CMob *);
    WORD GetRaceNum(void) const;
    void Save(void);
    void SaveReal(void);
    void FlushDelayedSaveItem(void);
    const char * GetName(void) const;
    const VID & GetVID(void) const;
    void SetName(const std::string &);
    void SetRace(BYTE);
    bool ChangeSex(void);
    DWORD GetAID(void) const;
    int GetChangeEmpireCount(void) const;
    void SetChangeEmpireCount(void);
    int ChangeEmpire(BYTE);
    BYTE GetJob(void) const;
    BYTE GetCharType(void) const;
    bool IsPC(void) const;
    bool IsNPC(void) const;
    bool IsMonster(void) const;
    bool IsStone(void) const;
    bool IsDoor(void) const;
    bool IsBuilding(void) const;
    bool IsWarp(void) const;
    bool IsGoto(void) const;
    DWORD GetLastShoutPulse(void) const;
    void SetLastShoutPulse(DWORD);
    int GetLevel(void) const;
    void SetLevel(BYTE);
    BYTE GetGMLevel(void) const;
    bool IsGM(void) const;
    void SetGMLevel(void);
    DWORD GetExp(void) const;
    void SetExp(DWORD);
    DWORD GetNextExp(void) const;
    LPCHARACTER DistributeExp(void);
    void DistributeHP(LPCHARACTER);
    void DistributeSP(LPCHARACTER, int);
    void SetPosition(int);
    bool IsPosition(int) const;
    int GetPosition(void) const;
    void SetPart(BYTE, WORD);
    WORD GetPart(BYTE) const;
    WORD GetOriginalPart(BYTE) const;
    void SetHP(int);
    int GetHP(void) const;
    void SetSP(int);
    int GetSP(void) const;
    void SetStamina(int);
    int GetStamina(void) const;
    void SetMaxHP(int);
    int GetMaxHP(void) const;
    void SetMaxSP(int);
    int GetMaxSP(void) const;
    void SetMaxStamina(int);
    int GetMaxStamina(void) const;
    void SetRandomHP(int);
    void SetRandomSP(int);
    int GetRandomHP(void) const;
    int GetRandomSP(void) const;
    int GetHPPct(void) const;
    void SetRealPoint(BYTE, int);
    int GetRealPoint(BYTE) const;
    void SetPoint(BYTE, int);
    int GetPoint(BYTE) const;
    int GetLimitPoint(BYTE) const;
    int GetPolymorphPoint(BYTE) const;
    const TMobTable & GetMobTable(void) const;
    BYTE GetMobRank(void) const;
    BYTE GetMobBattleType(void) const;
    BYTE GetMobSize(void) const;
    DWORD GetMobDamageMin(void) const;
    DWORD GetMobDamageMax(void) const;
    WORD GetMobAttackRange(void) const;
    DWORD GetMobDropItemVnum(void) const;
    float GetMobDamageMultiply(void) const;
    bool IsBerserker(void) const;
    bool IsBerserk(void) const;
    void SetBerserk(bool);
    bool IsStoneSkinner(void) const;
    bool IsGodSpeeder(void) const;
    bool IsGodSpeed(void) const;
    void SetGodSpeed(bool);
    bool IsDeathBlower(void) const;
    bool IsDeathBlow(void) const;
    bool IsReviver(void) const;
    bool HasReviverInParty(void) const;
    bool IsRevive(void) const;
    void SetRevive(bool);
    bool IsRaceFlag(DWORD) const;
    bool IsSummonMonster(void) const;
    DWORD GetSummonVnum(void) const;
    DWORD GetPolymorphItemVnum(void) const;
    DWORD GetMonsterDrainSPPoint(void) const;
    void MainCharacterPacket(void);
    void ComputePoints(void);
    void ComputeBattlePoints(void);
    void PointChange(BYTE, int, bool, bool);
    void PointsPacket(void);
    void ApplyPoint(BYTE, int);
    void CheckMaximumPoints(void);
    bool Show(long, long, long, long, bool);
    void Sitdown(int);
    void Standup(void);
    void SetRotation(float);
    void SetRotationToXY(long, long);
    float GetRotation(void) const;
    void MotionPacketEncode(BYTE, LPCHARACTER, packet_motion *);
    void Motion(BYTE, LPCHARACTER);
    void ChatPacket(BYTE, const char *);
    void MonsterChat(BYTE);
    void SendGreetMessage(void);
    void ResetPoint(int);
    void SetBlockMode(BYTE);
    void SetBlockModeForce(BYTE);
    bool IsBlockMode(BYTE) const;
    bool IsPolymorphed(void) const;
    bool IsPolyMaintainStat(void) const;
    void SetPolymorph(DWORD, bool);
    DWORD GetPolymorphVnum(void) const;
    int GetPolymorphPower(void) const;
    void fishing(void);
    void fishing_take(void);
    void mining(LPCHARACTER);
    void mining_cancel(void);
    void mining_take(void);
    void ResetPlayTime(DWORD);
    void CreateFly(BYTE, LPCHARACTER);
    void ResetChatCounter(void);
    BYTE IncreaseChatCounter(void);
    BYTE GetChatCounter(void) const;
    bool IsStateMove(void) const;
    bool IsStateIdle(void) const;
    bool IsWalking(void) const;
    void SetWalking(bool);
    void SetNowWalking(bool);
    void ResetWalking(void);
    bool Goto(long, long);
    void Stop(void);
    bool CanMove(void) const;
    void SyncPacket(void);
    bool Sync(long, long);
    bool Move(long, long);
    void OnMove(bool);
    DWORD GetMotionMode(void) const;
    float GetMoveMotionSpeed(void) const;
    float GetMoveSpeed(void) const;
    void CalculateMoveDuration(void);
    void SendMovePacket(BYTE, BYTE, DWORD, DWORD, DWORD, DWORD, int);
    DWORD GetCurrentMoveDuration(void) const;
    DWORD GetWalkStartTime(void) const;
    DWORD GetLastMoveTime(void) const;
    DWORD GetLastAttackTime(void) const;
    void SetLastAttacked(DWORD);
    bool SetSyncOwner(LPCHARACTER, bool);
    bool IsSyncOwner(LPCHARACTER) const;
    bool WarpSet(long, long, long);
    void SetWarpLocation(long, long, long);
    void WarpEnd(void);
    const PIXEL_POSITION & GetWarpPosition(void) const;
    bool WarpToPID(DWORD);
    void SaveExitLocation(void);
    void ExitToSavedLocation(void);
    void StartStaminaConsume(void);
    void StopStaminaConsume(void);
    bool IsStaminaConsume(void) const;
    bool IsStaminaHalfConsume(void) const;
    void ResetStopTime(void);
    DWORD GetStopTime(void) const;
  protected:
    void ClearSync(void);
  public:
    void SyncQuickslot(BYTE, BYTE, BYTE);
    bool GetQuickslot(BYTE, TQuickslot **);
    bool SetQuickslot(BYTE, TQuickslot &);
    bool DelQuickslot(BYTE);
    bool SwapQuickslot(BYTE, BYTE);
    void ChainQuickslotItem(LPITEM, BYTE, BYTE);
    void StartAffectEvent(void);
    void ClearAffect(bool);
    void ComputeAffect(CAffect *, bool);
    bool AddAffect(DWORD, BYTE, long, DWORD, long, long, bool, bool);
    void RefreshAffect(void);
    bool RemoveAffect(DWORD);
    bool RemoveAffect(CAffect *);
    bool IsAffectFlag(DWORD) const;
    bool UpdateAffect(void);
    int ProcessAffect(void);
    void LoadAffect(DWORD, TPacketAffectElement *);
    void SaveAffect(void);
    bool IsLoadedAffect(void) const;
    bool IsGoodAffect(BYTE) const;
    void RemoveGoodAffect(void);
    void RemoveBadAffect(void);
    CAffect * FindAffect(DWORD, BYTE);
    const std::list<CAffect*, std::allocator<CAffect*> > & GetAffectContainer(void) const;
    void SetParty(LPPARTY);
    LPPARTY GetParty(void) const;
    bool RequestToParty(LPCHARACTER);
    void DenyToParty(LPCHARACTER);
    void AcceptToParty(LPCHARACTER);
    void PartyInvite(LPCHARACTER);
    void PartyInviteAccept(LPCHARACTER);
    void PartyInviteDeny(DWORD);
    bool BuildUpdatePartyPacket(TPacketGCPartyUpdate &);
    int GetLeadershipSkillLevel(void) const;
    bool CanSummon(int);
    void SetPartyRequestEvent(LPEVENT);
  protected:
    void PartyJoin(LPCHARACTER);
    static CHARACTER::PartyJoinErrCode IsPartyJoinableCondition(LPCHARACTER,
        LPCHARACTER);
    static CHARACTER::PartyJoinErrCode IsPartyJoinableMutableCondition(LPCHARACTER, LPCHARACTER);
  public:
    void SetDungeon(LPDUNGEON);
    LPDUNGEON GetDungeon(void) const;
    LPDUNGEON GetDungeonForce(void) const;
    void SetGuild(CGuild *);
    CGuild * GetGuild(void) const;
    void SetWarMap(CWarMap *);
    CWarMap * GetWarMap(void) const;
    bool CanHandleItem(bool, bool);
    bool IsItemLoaded(void) const;
    void SetItemLoaded(void);
    void ClearItem(void);
    void SetItem(BYTE, LPITEM, bool);
    LPITEM GetItem(BYTE) const;
    bool IsEmptyItemGrid(BYTE, BYTE, int) const;
    void SetWear(BYTE, LPITEM);
    LPITEM GetWear(BYTE) const;
    void UseSilkBotary(void);
    void UseSilkBotaryReal(const TPacketMyshopPricelistHeader *);
    bool UseItemEx(LPITEM, int);
    bool UseItem(BYTE, int);
    bool IsRefineThroughGuild(void) const;
    CGuild * GetRefineGuild(void) const;
    int ComputeRefineFee(int, int) const;
    void PayRefineFee(int);
    void SetRefineNPC(LPCHARACTER);
    bool RefineItem(LPITEM, LPITEM);
    bool DropItem(BYTE, BYTE);
    bool GiveRecallItem(LPITEM);
    void ProcessRecallItem(LPITEM);
    void EffectPacket(int);
    void SpecificEffectPacket(const char *);
    bool DoRefine(LPITEM, bool);
    bool DoRefineWithScroll(LPITEM);
    bool RefineInformation(BYTE, BYTE, int);
    void SetRefineMode(int);
    void ClearRefineMode(void);
    bool GiveItem(LPCHARACTER, BYTE);
    bool CanReceiveItem(LPCHARACTER, LPITEM) const;
    void ReceiveItem(LPCHARACTER, LPITEM);
    bool GiveItemFromSpecialItemGroup(DWORD, std::vector<unsigned int, std::allocator<unsigned int> > &, std::vector<unsigned int, std::allocator<unsigned int> > &,std::vector<CItem*, std::allocator<CItem*> > &, int &);
    bool MoveItem(BYTE, BYTE, BYTE);
    bool PickupItem(DWORD);
    bool EquipItem(LPITEM);
    bool UnequipItem(LPITEM);
    bool SwapItem(BYTE, BYTE);
    LPITEM AutoGiveItem(DWORD, BYTE, int, bool);
    void AutoGiveItem(LPITEM, bool);
    int GetEmptyInventory(BYTE) const;
    int CountEmptyInventory(void) const;
    int CountSpecifyItem(DWORD) const;
    void RemoveSpecifyItem(DWORD, DWORD);
    LPITEM FindSpecifyItem(DWORD) const;
    LPITEM FindItemByID(DWORD) const;
    bool IsEquipUniqueItem(DWORD) const;
    bool IsEquipUniqueGroup(DWORD) const;
    void SendEquipment(LPCHARACTER);
  protected:
    void SendMyShopPriceListCmd(DWORD, DWORD);
  public:
    int GetGold(void) const;
    void SetGold(int);
    bool DropGold(int);
    int GetAllowedGold(void) const;
    void GiveGold(int);
    void SetShop(LPSHOP);
    LPSHOP GetShop(void) const;
    void ShopPacket(BYTE);
    void SetShopOwner(LPCHARACTER);
    LPCHARACTER GetShopOwner(void) const;
    void OpenMyShop(const char *, TShopItemTable *, BYTE);
    LPSHOP GetMyShop(void) const;
    void CloseMyShop(void);
    bool ExchangeStart(LPCHARACTER);
    void SetExchange(CExchange *);
    CExchange * GetExchange(void) const;
    bool Damage(LPCHARACTER, int, EDamageType);
    bool __Profile__Damage(LPCHARACTER, int, EDamageType);
    void DeathPenalty(BYTE);
    void ReviveInvisible(int);
    bool Attack(LPCHARACTER, BYTE);
    bool IsAlive(void) const;
    bool CanFight(void) const;
    bool CanBeginFight(void) const;
    void BeginFight(LPCHARACTER);
    bool CounterAttack(LPCHARACTER);
    bool IsStun(void) const;
    void Stun(void);
    bool IsDead(void) const;
    void Dead(LPCHARACTER, bool);
    void Reward(bool);
    void RewardGold(LPCHARACTER);
    bool Shoot(BYTE);
    void FlyTarget(DWORD, long, long, BYTE);
    void ForgetMyAttacker(void);
    void AggregateMonster(void);
    void AttractRanger(void);
    void PullMonster(void);
    int GetArrowAndBow(LPITEM *, LPITEM *, int);
    void UseArrow(LPITEM, DWORD);
    void AttackedByPoison(LPCHARACTER);
    void RemovePoison(void);
    void AttackedByFire(LPCHARACTER, int, int);
    void RemoveFire(void);
    void UpdateAlignment(int);
    int GetAlignment(void) const;
    int GetRealAlignment(void) const;
    void ShowAlignment(bool);
    void SetKillerMode(bool);
    bool IsKillerMode(void) const;
    void UpdateKillerMode(void);
    BYTE GetPKMode(void) const;
    void SetPKMode(BYTE);
    void ItemDropPenalty(LPCHARACTER);
    void UpdateAggrPoint(LPCHARACTER, EDamageType, int);
    void SetComboSequence(BYTE);
    BYTE GetComboSequence(void) const;
    void SetLastComboTime(DWORD);
    DWORD GetLastComboTime(void) const;
    int GetValidComboInterval(void) const;
    void SetValidComboInterval(int);
    BYTE GetComboIndex(void) const;
    void IncreaseComboHackCount(int);
    void ResetComboHackCount(void);
    void SkipComboAttackByTime(int);
    DWORD GetSkipComboAttackByTime(void) const;
  protected:
    void UpdateAggrPointEx(LPCHARACTER, EDamageType, int,CHARACTER::TBattleInfo &);
    void ChangeVictimByAggro(int, LPCHARACTER);
  public:
    void SetStone(LPCHARACTER);
    void ClearStone(void);
    void DetermineDropMetinStone(void);
    DWORD GetDropMetinStoneVnum(void) const;
    BYTE GetDropMetinStonePct(void) const;
    void SkillLevelPacket(void);
    void SkillLevelUp(DWORD, BYTE);
    bool SkillLevelDown(DWORD);
    bool UseSkill(DWORD, LPCHARACTER, bool);
    void ResetSkill(void);
    void SetSkillLevel(DWORD, BYTE);
    int GetUsedSkillMasterType(DWORD);
    bool IsLearnableSkill(DWORD) const;
    bool CheckSkillHitCount(BYTE, VID);
    bool CanUseSkill(DWORD) const;
    bool IsUsableSkillMotion(DWORD) const;
    int GetSkillLevel(DWORD) const;
    int GetSkillMasterType(DWORD) const;
    int GetSkillPower(DWORD, BYTE) const;
    time_t GetSkillNextReadTime(DWORD) const;
    void SetSkillNextReadTime(DWORD, time_t);
    void SkillLearnWaitMoreTimeMessage(DWORD);
    void ComputePassiveSkill(DWORD);
    int ComputeSkill(DWORD, LPCHARACTER, BYTE);
    int ComputeSkillAtPosition(DWORD, const PIXEL_POSITION &, BYTE);
    void ComputeSkillPoints(void);
    void SetSkillGroup(BYTE);
    BYTE GetSkillGroup(void) const;
    int ComputeCooltime(int);
    void GiveRandomSkillBook(void);
    void DisableCooltime(void);
    bool LearnSkillByBook(DWORD, BYTE);
    bool LearnGrandMasterSkill(DWORD);
    bool HasMobSkill(void) const;
    size_t CountMobSkill(void) const;
    const TMobSkillInfo * GetMobSkill(unsigned int) const;
    bool CanUseMobSkill(unsigned int) const;
    bool UseMobSkill(unsigned int);
    void ResetMobSkillCooltime(void);
    void StartMuyeongEvent(void);
    void StopMuyeongEvent(void);
    int GetChainLightningIndex(void) const;
    void IncChainLightningIndex(void);
    void AddChainLightningExcept(LPCHARACTER);
    void ResetChainLightningIndex(void);
    int GetChainLightningMaxCount(void) const;
    const CHARACTER_SET & GetChainLightingExcept(void) const;
    void SetAffectedEunhyung(void);
    void ClearAffectedEunhyung(void);
    bool GetAffectedEunhyung(void) const;
    void AssignTriggers(const TMobTable *);
    LPCHARACTER GetVictim(void) const;
    void SetVictim(LPCHARACTER);
    LPCHARACTER GetNearestVictim(LPCHARACTER);
    LPCHARACTER GetProtege(void) const;
    bool Follow(LPCHARACTER, float);
    bool Return(void);
    bool IsGuardNPC(void) const;
    bool IsChangeAttackPosition(LPCHARACTER) const;
    void ResetChangeAttackPositionTime(void);
    void SetChangeAttackPositionTime(void);
    bool OnIdle(void);
    void OnAttack(LPCHARACTER);
    void OnClick(LPCHARACTER);
    void SetTarget(LPCHARACTER);
    void BroadcastTargetPacket(void);
    void ClearTarget(void);
    void CheckTarget(void);
    LPCHARACTER GetTarget(void) const;
    int GetSafeboxSize(void) const;
    void QuerySafeboxSize(void);
    void SetSafeboxSize(int);
    CSafebox * GetSafebox(void) const;
    void LoadSafebox(int, DWORD, int, TPlayerItem *);
    void ChangeSafeboxSize(BYTE);
    void CloseSafebox(void);
    void ReqSafeboxLoad(const char *);
    void CancelSafeboxLoad(void);
    void SetMallLoadTime(int);
    int GetMallLoadTime(void) const;
    CSafebox * GetMall(void) const;
    void LoadMall(int, TPlayerItem *);
    void CloseMall(void);
    void SetSafeboxOpenPosition(void);
    float GetDistanceFromSafeboxOpen(void) const;
    void MountVnum(DWORD);
    DWORD GetMountVnum(void) const;
    DWORD GetLastMountTime(void) const;
    bool CanUseHorseSkill(void);
    virtual void SetHorseLevel(int);
    virtual bool StartRiding(void);
    virtual bool StopRiding(void);
    virtual DWORD GetMyHorseVnum(void) const;
    virtual void HorseDie(void);
    virtual bool ReviveHorse(void);
    virtual void SendHorseInfo(void);
    virtual void ClearHorseInfo(void);
    void HorseSummon(bool, bool, DWORD, const char *);
    LPCHARACTER GetHorse(void) const;
    LPCHARACTER GetRider(void) const;
    void SetRider(LPCHARACTER);
    bool IsRiding(void) const;
    CPetSystem * GetPetSystem(void);
    void DetailLog(void);
    void ToggleMonsterLog(void);
    void MonsterLog(const char *, ...);
    void SetEmpire(BYTE);
    BYTE GetEmpire(void) const;
    void SetRegen(LPREGEN);
    bool CannotMoveByAffect(void) const;
    bool IsImmune(DWORD);
    void SetImmuneFlag(DWORD);
  protected:
    void ApplyMobAttribute(const TMobTable *);
  public:
    void SetQuestNPCID(DWORD);
    DWORD GetQuestNPCID(void) const;
    LPCHARACTER GetQuestNPC(void) const;
    void SetQuestItemPtr(LPITEM);
    void ClearQuestItemPtr(void);
    LPITEM GetQuestItemPtr(void) const;
    void SetQuestBy(DWORD);
    DWORD GetQuestBy(void) const;
    int GetQuestFlag(const std::string &) const;
    void SetQuestFlag(const std::string &, int);
    void ConfirmWithMsg(const char *, int, DWORD);
    bool StartStateMachine(int);
    void StopStateMachine(void);
    void UpdateStateMachine(DWORD);
    void SetNextStatePulse(int);
    void UpdateCharacter(DWORD);
    LPCHARACTER GetMarryPartner(void) const;
    void SetMarryPartner(LPCHARACTER);
    int GetMarriageBonus(DWORD, bool);
    void SetWeddingMap(marriage::WeddingMap *);
    marriage::WeddingMap * GetWeddingMap(void) const;
    void StartWarpNPCEvent(void);
    void StartSaveEvent(void);
    void StartRecoveryEvent(void);
    void StartCheckSpeedHackEvent(void);
    void StartDestroyWhenIdleEvent(void);
    bool IsWarping(void) const;
    int GetPremiumRemainSeconds(BYTE) const;
    bool SetPCBang(bool);
    bool IsPCBang(void) const;
    bool ItemProcess_Hair(LPITEM, int);
    void ClearSkill(void);
    void ClearSubSkill(void);
    bool ResetOneSkill(DWORD);
  private:
    void SendDamagePacket(LPCHARACTER, int, BYTE);
  public:
    void SetArena(CArena *);
    void SetArenaObserverMode(bool);
    CArena * GetArena(void) const;
    bool GetArenaObserverMode(void) const;
    void SetPotionLimit(int);
    int GetPotionLimit(void) const;
    bool IsOpenSafebox(void) const;
    void SetOpenSafebox(bool);
    int GetSafeboxLoadTime(void) const;
    void SetSafeboxLoadTime(void);
    int GetSkillPowerByLevel(int, bool) const;
    int GetRefineTime(void) const;
    void SetRefineTime(void);
    int GetUseSeedOrMoonBottleTime(void) const;
    void SetUseSeedOrMoonBottleTime(void);
    int GetExchangeTime(void) const;
    void SetExchangeTime(void);
    int GetMyShopTime(void) const;
    void SetMyShopTime(void);
    bool IsHack(bool, bool, int);
    bool IsMonarch(void) const;
    void Say(const std::string &);
    void InitMC(void);
    DWORD GetMC(CHARACTER::MONARCH_INDEX) const;
    void SetMC(CHARACTER::MONARCH_INDEX);
    bool IsMCOK(CHARACTER::MONARCH_INDEX) const;
    DWORD GetMCL(CHARACTER::MONARCH_INDEX) const;
    DWORD GetMCLTime(CHARACTER::MONARCH_INDEX) const;
    bool ItemProcess_Polymorph(LPITEM);
    LPITEM * GetCubeItem(void);
    bool IsCubeOpen(void) const;
    void SetCubeNpc(LPCHARACTER);
    bool CanDoCube(void) const;
    bool IsSiegeNPC(void) const;
    bool IsOverTime(e_overtime) const;
    void SetOverTime(e_overtime);
    void UpdateDepositPulse(void);
    bool CanDeposit(void) const;
  private:
    void __OpenPrivateShop(void);
  public:
    const std::string GetNewName(void) const;
    void SetNewName(std::string);
    void GoHome(void);
    void SendGuildName(CGuild *);
    void SendGuildName(DWORD);
    DWORD GetLogOffInterval(void) const;
    bool UnEquipSpecialRideUniqueItem(void);
    bool CanWarp(void) const;
    void StartHackShieldCheckCycle(int);
    void StopHackShieldCheckCycle(void);
    bool GetHackShieldCheckMode(void) const;
    void SetHackShieldCheckMode(bool);
    void AutoRecoveryItemProcess(EAffectTypes);
    void BuffOnAttr_AddBuffsFromItem(LPITEM);
    void BuffOnAttr_RemoveBuffsFromItem(LPITEM);
  private:
    void BuffOnAttr_ValueChange(BYTE, BYTE, BYTE);
    void BuffOnAttr_TurnOn(BYTE);
    void BuffOnAttr_TurnOff(BYTE);
  public:
    void SetArmada(void);
    void ResetArmada(void);
    void SetPet(void);
    bool IsPet(void);
    float GetAttMul(void);
    void SetAttMul(float);
    float GetDamMul(void);
    void SetDamMul(float);
};
typedef CHARACTER* LPCHARACTER;
#endif // _GAME_CHARACTER_HPP
