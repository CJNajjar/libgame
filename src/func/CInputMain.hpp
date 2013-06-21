#ifndef __CINPUTMAIN_HPP
#define __CINPUTMAIN_HPP
#include "../addr.hpp"
#include "../gameinfo.hpp"
namespace CInputMain {
typedef void (*tItemMove)(char*, GameFunc::CHARACTER*, TPacketCGItemMoveNew*);
typedef void (*tItemDrop)(char * const, GameFunc::LPCHARACTER, TPacketCGItemDropNew *);
typedef void (*tItemDrop2)(char * const, GameFunc::LPCHARACTER, TPacketCGItemDrop2New *);
typedef void (*tItemGive)(char * const, GameFunc::LPCHARACTER, const char *);
typedef void (*tItemToItem)(char * const, GameFunc::LPCHARACTER, TPacketCGItemUseToItemNew *);
typedef void (*tItemUse)(char * const, GameFunc::LPCHARACTER, TPacketCGItemUseNew *);
typedef void (*tItemUse)(char * const, GameFunc::LPCHARACTER, TPacketCGItemUseNew *);
typedef int (*tSyncPosition)(char *, GameFunc::CHARACTER*,  const char*, size_t);
}
#endif // __CINPUTMAIN_HPP
