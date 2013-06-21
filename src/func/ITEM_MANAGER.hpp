#include "../addr.hpp"
#include "../gameinfo.hpp"
#ifndef __ITEM_MANAGER_HPP
#define __ITEM_MANAGER_HPP
namespace ITEM_MANAGER
{
typedef void (*tRemoveItem)(GameFunc::ITEM_MANAGER*, GameFunc::CItem*, char const*);
typedef GameFunc::CSpecialItemGroup* (*tGetSpecialItemGroup)(GameFunc::ITEM_MANAGER*, DWORD);
typedef GameFunc::LPITEM (*tCreateItem)(GameFunc::ITEM_MANAGER *, DWORD, DWORD, DWORD, bool, int);
typedef void (*tDestroyItem)(GameFunc::ITEM_MANAGER *, GameFunc::LPITEM);
typedef GameFunc::LPITEM (*tFindByVID)(GameFunc::ITEM_MANAGER *, DWORD);
extern tFindByVID FindByVID;
extern tCreateItem CreateItem;
extern tDestroyItem DestroyItem;
extern tRemoveItem RemoveItem;
extern tGetSpecialItemGroup GetSpecialItemGroup;
}

#endif // __CITEMMANAGER_HPP
