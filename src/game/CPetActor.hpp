#ifndef _GAME_CPETACTOR_HPP
#define _GAME_CPETACTOR_HPP
#include "stdInclude.hpp"
class CPetActor {
  public:
    enum EPetOptions {EPetOption_Followable = 1,
    EPetOption_Mountable, EPetOption_Summonable = 4,
    EPetOption_Combatable = 8};

  private:
    DWORD m_dwVnum;
    DWORD m_dwVID;
    DWORD m_dwOptions;
    DWORD m_dwLastActionTime;
    DWORD m_dwSummonItemVID;
    DWORD m_dwSummonItemVnum;
    short m_originalMoveSpeed;
    std::string m_name;
    LPCHARACTER m_pkChar;
    LPCHARACTER m_pkOwner;

  protected:
    CPetActor(LPCHARACTER, DWORD, DWORD);
    ~CPetActor();
    virtual bool Update(DWORD);
    virtual bool _UpdateFollowAI(void);
    virtual bool _UpdatAloneActionAI(float, float);
  private:
    bool Follow(float);
  public:
    LPCHARACTER GetCharacter(void) const;
    LPCHARACTER GetOwner(void) const;
    DWORD GetVID(void) const;
    DWORD GetVnum(void) const;
    bool HasOption(CPetActor::EPetOptions) const;
    void SetName(const char *);
    bool Mount(void);
    void Unmount(void);
    DWORD Summon(const char *, LPITEM, bool);
    void Unsummon(void);
    bool IsSummoned(void) const;
    void SetSummonItem(LPITEM);
    DWORD GetSummonItemVID(void);
    void GiveBuff(void);
    void ClearBuff(void);
};

#endif // _GAME_CPETACTOR_HPP
