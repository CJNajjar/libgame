#ifndef _GAME_CMOB_HPP
#define _GAME_CMOB_HPP
#include "stdInclude.hpp"
#include "SEntityTable.hpp"

struct SMobSkillLevel {
    DWORD dwVnum;
    BYTE bLevel;
} typedef TMobSkillLevel;

struct SMobTable : public SEntityTable {
    char szName[25];
    char szLocaleName[25];
    BYTE bType;
    BYTE bRank;
    BYTE bBattleType;
    BYTE bLevel;
    BYTE bSize;
    DWORD dwGoldMin;
    DWORD dwGoldMax;
    DWORD dwExp;
    DWORD dwMaxHP;
    BYTE bRegenCycle;
    BYTE bRegenPercent;
    WORD wDef;
    DWORD dwAIFlag;
    DWORD dwRaceFlag;
    DWORD dwImmuneFlag;
    BYTE bStr;
    BYTE bDex;
    BYTE bCon;
    BYTE bInt;
    DWORD dwDamageRange[2];
    short sAttackSpeed;
    short sMovingSpeed;
    BYTE bAggresiveHPPct;
    WORD wAggressiveSight;
    WORD wAttackRange;
    char cEnchants[6];
    char cResists[11];
    DWORD dwResurrectionVnum;
    DWORD dwDropItemVnum;
    BYTE bMountCapacity;
    BYTE bOnClickType;
    BYTE bEmpire;
    char szFolder[65];
    float fDamMultiply;
    DWORD dwSummonVnum;
    DWORD dwDrainSP;
    DWORD dwMobColor;
    DWORD dwPolymorphItemVnum;
    TMobSkillLevel Skills[5];
    BYTE bBerserkPoint;
    BYTE bStoneSkinPoint;
    BYTE bGodSpeedPoint;
    BYTE bDeathBlowPoint;
    BYTE bRevivePoint;
} typedef TMobTable;
class SMobSplashAttackInfo {
    DWORD dwTiming;
    DWORD dwHitDistance;
  public:
    SMobSplashAttackInfo(DWORD, DWORD);
};

struct SMobSkillInfo {
    DWORD dwSkillVnum;
    BYTE bSkillLevel;
    std::vector<SMobSplashAttackInfo, std::allocator<SMobSplashAttackInfo> > vecSplashAttack;
} typedef TMobSkillInfo;

class CMob {
    TMobTable m_table;
    TMobSkillInfo m_mobSkillInfo[5];
  public:
    CMob(void);
    ~CMob();
    void AddSkillSplash(int, DWORD, DWORD);
};
#endif
