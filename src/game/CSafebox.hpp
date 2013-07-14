#ifndef _GAME_CSAFEBOX_HPP
#define _GAME_CSAFEBOX_HPP
#include "stdInclude.hpp"
#include "CItem.hpp"
#include "CGrid.hpp"

class CSafebox {
  protected:
    LPCHARACTER m_pkChrOwner;
    LPITEM m_pkItems[135];
    CGrid *m_pkGrid;
    int m_iSize;
    long m_lGold;
    BYTE m_bWindowMode;

  public:
    CSafebox(LPCHARACTER, int, DWORD);
    ~CSafebox();
    bool Add(DWORD, LPITEM);
    LPITEM Get(DWORD);
    LPITEM Remove(DWORD);
    void ChangeSize(int);
    bool MoveItem(BYTE, BYTE, BYTE);
    LPITEM GetItem(BYTE);
    void Save(void);
    bool IsEmpty(DWORD, BYTE);
    bool IsValidPosition(DWORD);
    void SetWindowMode(BYTE);
  protected:
    void __Destroy(void);
};

#endif // _GAME_CSAFEBOX_HPP
