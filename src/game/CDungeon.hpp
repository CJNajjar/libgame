#ifndef _GAME_CDUNGEON_HPP
#define _GAME_CDUNGEON_HPP
#include "stdInclude.hpp"
#include "regen.hpp"

class TAreaInfo {
    int sx;
    int sy;
    int ex;
    int ey;
    int dir;
  public:
    TAreaInfo(int, int, int, int, int);
};

typedef std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, TAreaInfo, std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> > const, TAreaInfo> > > TAreaMap;

class CDungeon {
  private:
    uint32_t m_id;
    DWORD m_lOrigMapIndex;
    DWORD m_lMapIndex;
    CHARACTER_SET m_set_pkCharacter;
    std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, int, std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> > > m_map_Flag;
    std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::vector<std::pair<unsigned int, int>, std::allocator<std::pair<unsigned int, int> > >, std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> > const, std::vector<std::pair<unsigned int, int>, std::allocator<std::pair<unsigned int, int> > > > > > m_map_ItemGroup;
    std::map<CParty*,int,std::less<CParty*>,std::allocator<std::pair<CParty* const, int> > > m_map_pkParty;
    TAreaMap &m_map_Area;
    std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, CHARACTER*, std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> > const, CHARACTER*> > > m_map_UniqueMob;
    int m_iMobKill;
    int m_iStoneKill;
    bool m_bUsePotion;
    bool m_bUseRevive;
    int m_iMonsterCount;
    bool m_bExitAllAtEliminate;
    bool m_bWarpAtEliminate;
    int m_iWarpDelay;
    long m_lWarpMapIndex;
    long m_lWarpX;
    long m_lWarpY;
    std::string m_stRegenFile;
    std::vector<regen*, std::allocator<regen*> > m_regen;
    LPEVENT deadEvent;
    LPEVENT exit_all_event_;
    LPEVENT jump_to_event_;
    size_t regen_id_;
    LPPARTY m_pParty;

  public:
    ~CDungeon();
    uint32_t GetId(void) const;
    void Notice(const char *);
    void JoinParty(LPPARTY);
    void QuitParty(LPPARTY);
    void Join(LPCHARACTER);
    void IncMember(LPCHARACTER);
    void DecMember(LPCHARACTER);
    void Purge(void);
    void KillAll(void);
    void IncMonster(void);
    void DecMonster(void);
    int CountMonster(void);
    int CountRealMonster(void);
    void IncPartyMember(LPPARTY, LPCHARACTER);
    void DecPartyMember(LPPARTY, LPCHARACTER);
    void IncKillCount(LPCHARACTER, LPCHARACTER);
    int GetKillMobCount(void);
    int GetKillStoneCount(void);
    bool IsUsePotion(void);
    bool IsUseRevive(void);
    void UsePotion(LPCHARACTER);
    void UseRevive(LPCHARACTER);
    long GetMapIndex(void);
    void Spawn(DWORD, const char *);
    LPCHARACTER SpawnMob(DWORD, int, int, int);
    LPCHARACTER SpawnGroup(DWORD, long, long, float, bool, int);
    void SpawnNameMob(DWORD, int, int, const char *);
    void SpawnGotoMob(long, long, long, long);
    void SpawnRegen(const char *, bool);
    void AddRegen(LPREGEN);
    void ClearRegen(void);
    bool IsValidRegen(LPREGEN, size_t);
    void SetUnique(const char *, DWORD);
    void SpawnMoveUnique(const char *, DWORD, const char *, const char *);
    void SpawnMoveGroup(DWORD, const char *, const char *, int);
    void SpawnUnique(const char *, DWORD, const char *);
    void SpawnStoneDoor(const char *, const char *);
    void SpawnWoodenDoor(const char *, const char *);
    void KillUnique(const std::string &);
    void PurgeUnique(const std::string &);
    bool IsUniqueDead(const std::string &);
    float GetUniqueHpPerc(const std::string &);
    void DeadCharacter(LPCHARACTER);
    void UniqueSetMaxHP(const std::string &, int);
    void UniqueSetHP(const std::string &, int);
    void UniqueSetDefGrade(const std::string &, int);
    void SendDestPositionToParty(LPPARTY, long, long);
    void CheckEliminated(void);
    void JumpAll(long, int, int);
    void JumpParty(LPPARTY, long, int, int);
    void ExitAll(void);
    void ExitAllToStartPosition(void);
    void JumpToEliminateLocation(void);
    void SetExitAllAtEliminate(long);
    void SetWarpAtEliminate(long, long, int, int, const char *);
    int GetFlag(std::string);
    void SetFlag(std::string, int);
    void SetWarpLocation(long, int, int);
    void CreateItemGroup(std::string &, std::vector<std::pair<unsigned int, int>, std::allocator<std::pair<unsigned int, int> > > &);
    const std::vector<std::pair<unsigned int, int>, std::allocator<std::pair<unsigned int, int> > > * GetItemGroup(std::string &);
    bool IsAllPCNearTo(int, int, int);
  protected:
    CDungeon(uint32_t, long, long);
    void Initialize(void);
    void CheckDestroy(void);
  public:
    void SetPartyNull(void);
};

#endif // _GAME_CDUNGEON_HPP
