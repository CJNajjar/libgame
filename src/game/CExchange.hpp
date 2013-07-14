#ifndef _GAME_CEXCHANGE_HPP
#define _GAME_CEXCHANGE_HPP
#include "stdInclude.hpp"
#include "CItem.hpp"
#include "CGrid.hpp"
class CExchange {
  private:
    CExchange *m_pCompany;
    LPCHARACTER m_pOwner;
    BYTE m_abItemPos[12];
    LPITEM m_apItems[12];
    BYTE m_abItemDisplayPos[12];
    bool m_bAccept;
    long m_lGold;
    CGrid *m_pGrid;

  public:
    CExchange(LPCHARACTER);
    ~CExchange();
    bool Accept(bool);
    void Cancel(void);
    bool AddGold(long);
    bool AddItem(BYTE, BYTE);
    bool RemoveItem(BYTE);
    LPCHARACTER GetOwner(void);
    CExchange * GetCompany(void);
    bool GetAcceptStatus(void);
    void SetCompany(CExchange *);
  private:
    bool Done(void);
    bool Check(int *);
    bool CheckSpace(void);
};
#endif // _GAME_CEXCHANGE_HPP
