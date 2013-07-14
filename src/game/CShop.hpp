#ifndef _GAME_CSHOP_HPP
#define _GAME_CSHOP_HPP
#include "stdInclude.hpp"
#include "CGrid.hpp"
struct SShopItemTable {
    DWORD vnum;
    BYTE count;
    BYTE pos;
    DWORD price;
    BYTE display_pos;
} typedef TShopItemTable;

class CShop {
  public:
    class shop_item {
        DWORD vnum;
        long price;
        BYTE count;
        LPITEM pkItem;
        int itemid;
      public:
        shop_item(void);
    };
  private:
    DWORD m_dwVnum;
    DWORD m_dwNPCVnum;
    CGrid *m_pGrid;
    std::map<CHARACTER*,bool> m_map_guest;
    std::vector<CShop::shop_item, std::allocator<CShop::shop_item> > m_itemVector;
    LPCHARACTER m_pkPC;

  public:
    CShop(void);
    ~CShop();
    bool Create(DWORD, DWORD, TShopItemTable *);
    void SetShopItems(TShopItemTable *, BYTE);
    void SetPCShop(LPCHARACTER);
    bool IsPCShop(void);
    bool AddGuest(LPCHARACTER, DWORD, bool);
    void RemoveGuest(LPCHARACTER);
    int Buy(LPCHARACTER, BYTE);
    void BroadcastUpdateItem(BYTE);
    int GetNumberByVnum(DWORD);
    bool IsSellingItem(DWORD);
    DWORD GetVnum(void);
    DWORD GetNPCVnum(void);
  protected:
    void Broadcast(const void *, int);
};
typedef CShop * LPSHOP;
#endif // _GAME_CSHOP_HPP
