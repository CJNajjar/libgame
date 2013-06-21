#ifndef __CHARACTER_HPP
#define __CHARACTER_HPP
#include "../addr.hpp"
#include "../gameinfo.hpp"
namespace CHARACTER
{
typedef bool (*tIsEmptyItemGrid)(GameFunc::CHARACTER *, uint8_t, uint8_t, int);
typedef void (*tEffectPacket)(GameFunc::CHARACTER*,int);
typedef GameFunc::CItem* (*tGetWear)(GameFunc::CHARACTER*, unsigned char);
typedef void (*tSyncQuickslot)(GameFunc::CHARACTER*, unsigned char, unsigned char, unsigned char);
typedef void (*tChatPacket)(GameFunc::CHARACTER*, unsigned char, char const*, ...);
typedef void (*tMoveItem)(GameFunc::CHARACTER*, unsigned char, unsigned char, unsigned char);
typedef GameFunc::CItem* (*tGetItem)(GameFunc::CHARACTER*, unsigned char);
typedef const char* (*tGetName)(GameFunc::CHARACTER*);
typedef void (*tSetItem)(GameFunc::CHARACTER*, unsigned char, GameFunc::CItem*);
typedef bool (*tAddAffect)(GameFunc::CHARACTER*, unsigned int, unsigned char, long, unsigned int, long, long, bool, bool);
typedef void (*tSetSkillLevel)(GameFunc::CHARACTER *, DWORD, BYTE);
/* void CHARACTER::SetWarpLocation(long, long, long); */
typedef void (*tSetWarpLocation)(GameFunc::CHARACTER*, long, long, long);
/* bool CHARACTER::Show(char* this, long lMapIndex, long x, long y, long z, bool bShowSpawnMotion); */
typedef bool (*tShow)(GameFunc::CHARACTER*, long, long, long, long, bool);
typedef void (*tStateHorse)(GameFunc::CHARACTER*);
typedef bool (*tCanUseSkill)(GameFunc::CHARACTER * const, DWORD);
typedef BYTE (*tGetJob)(GameFunc::CHARACTER *);
typedef void (*tSetRider)(GameFunc::CHARACTER *, GameFunc::LPCHARACTER);//} 0x8090500
typedef bool (*tUseItem)(GameFunc::CHARACTER *, BYTE, int);
typedef bool (*tDropItem)(GameFunc::CHARACTER *, BYTE, BYTE);
typedef void (*tSetShop)(GameFunc::CHARACTER *, GameFunc::LPSHOP);
typedef bool (*tDropGold)(GameFunc::CHARACTER * const, int);
typedef bool (*tUnequipItem)(GameFunc::CHARACTER *, GameFunc::LPITEM);
typedef void (*tDestroy)(GameFunc::CHARACTER*);
typedef bool (*tRemoveAffect)(GameFunc::CHARACTER*, unsigned int);
typedef bool (*tHorseSummon)(GameFunc::CHARACTER*, bool, bool);
typedef GameFunc::CHARACTER* (*tGetRider)(GameFunc::CHARACTER*);
typedef void (*tCHARACTER)(GameFunc::CHARACTER*);
extern tHorseSummon HorseSummon;
extern tRemoveAffect RemoveAffect;
extern tUnequipItem UnequipItem;
extern tSetShop SetShop;
extern tDropItem DropItem;
extern tUseItem UseItem;
extern tDropGold DropGold;
extern tSetRider SetRider;
extern tGetJob GetJob;
extern tSetSkillLevel SetSkillLevel;
extern tCanUseSkill CanUseSkill;
extern tGetWear GetWear;
extern tChatPacket ChatPacket;
extern tEffectPacket EffectPacket;
extern tSyncQuickslot SyncQuickslot;
extern tGetItem GetItem;
extern tGetName GetName;
extern tMoveItem MoveItem;
extern tShow Show;
extern tStateHorse StateHorse;
extern tSetWarpLocation SetWarpLocation;
extern tAddAffect AddAffect;
extern tGetRider GetRider;
typedef unsigned char (*tGetCharType ) (GameFunc::CHARACTER *);
extern tGetCharType GetCharType;
typedef bool (*tSetSyncOwner ) (GameFunc::CHARACTER* , GameFunc::CHARACTER*, bool);
extern tSetSyncOwner SetSyncOwner;
typedef bool (*tSync) (GameFunc::CHARACTER*, long, long);
extern tSync Sync;
}
#endif // __CHARACTER_HPP
