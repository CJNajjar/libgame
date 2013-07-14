#ifndef _GAME_CPETSYSTEM_HPP
#define _GAME_CPETSYSTEM_HPP
#include "stdInclude.hpp"
#include "EVENT.hpp"
#include "CPetActor.hpp"
struct SPetAbility{};
class CPetSystem {
  private:
    boost::unordered_map<unsigned int, CPetActor*, boost::hash<unsigned int>, std::equal_to<unsigned int>, std::allocator<std::pair<unsigned int const, CPetActor*> > > m_petActorMap;
    LPCHARACTER m_pkOwner;
    DWORD m_dwUpdatePeriod;
    DWORD m_dwLastUpdateTime;
    LPEVENT m_pkPetSystemUpdateEvent;

  public:
    CPetSystem(LPCHARACTER);
    ~CPetSystem();
    CPetActor * GetByVID(DWORD) const;
    CPetActor * GetByVnum(DWORD) const;
    bool Update(DWORD);
    void Destroy(void);
    size_t CountSummoned(void) const;
    void SetUpdatePeriod(DWORD);
    CPetActor * Summon(DWORD, LPITEM, const char *, bool, DWORD);
    void Unsummon(DWORD, bool);
    void Unsummon(CPetActor *, bool);
    CPetActor * AddPet(DWORD, const char *, const SPetAbility &, DWORD);
    void DeletePet(DWORD);
    void DeletePet(CPetActor *);
    void RefreshBuff(void);
};

#endif // _GAME_CPETSYSTEM_HPP
