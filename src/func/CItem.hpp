#ifndef __CITEM_HPP
#define __CITEM_HPP
#include "../addr.hpp"
#include "../gameinfo.hpp"
namespace CItem
{
typedef void (*tChangeAttribute)(GameFunc::CItem*,int const*);
typedef uint32_t (*tGetCount)(GameFunc::CItem*);
typedef void (*tSetAttribute)(GameFunc::CItem*, int, unsigned char, short);
typedef bool (*tEquipTo)(GameFunc::CItem *, GameFunc::LPCHARACTER, BYTE);
typedef void (*tClearAttribute)(GameFunc::CItem *);
typedef int (*tFindEquipCell)(GameFunc::CItem *, GameFunc::LPCHARACTER);
typedef void (*tUpdatePacket)(GameFunc::CItem *);
extern tEquipTo EquipTo;
extern tFindEquipCell FindEquipCell;
extern tChangeAttribute ChangeAttribute;
extern tGetCount GetCount;
extern tSetAttribute SetAttribute;
extern tClearAttribute ClearAttribute;
}
#endif // __CITEM_HPP
