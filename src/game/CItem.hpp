#ifndef _GAME_CITEM_HPP
#define _GAME_CITEM_HPP
#include "stdInclude.hpp"
#include "EVENT.hpp"
#include "SItemTable.hpp"
#include "packet.hpp"

struct TPlayerItemAttribute {
    BYTE bType;
    short sValue;
};
struct SPlayerItem {
    DWORD id;
    BYTE window;
    WORD pos;
    DWORD count;
    DWORD vnum;
    long alSockets[3];
    TPlayerItemAttribute aAttr[7];
    DWORD owner;
} typedef TPlayerItem;


struct CItem : public CEntity {
  private:
    const TItemTable *m_pProto;
    LPCHARACTER m_pOwner;
    BYTE m_bWindow;
    DWORD m_dwID;
    bool m_bEquipped;
    DWORD m_dwVID;
    BYTE m_bCell;
    DWORD m_dwCount;
    long m_lFlag;
    DWORD m_dwLastOwnerPID;
    bool m_bExchanging;
    long m_alSockets[3];
    TPlayerItemAttribute m_aAttr[7];
    LPEVENT m_pkDestroyEvent;
    LPEVENT m_pkUniqueExpireEvent;
    LPEVENT m_pkTimerBasedOnWearExpireEvent;
    LPEVENT m_pkRealTimeExpireEvent;
    LPEVENT m_pkAccessorySocketExpireEvent;
    LPEVENT m_pkOwnershipEvent;
    DWORD m_dwOwnershipPID;
    bool m_bSkipSave;
    bool m_isLocked;
    DWORD m_dwMaskVnum;
    DWORD m_dwSIGVnum;

  protected:
    virtual void EncodeInsertPacket(LPENTITY);
    virtual void EncodeRemovePacket(LPENTITY);
  public:
    CItem();
    ~CItem();
    int GetLevelLimit(void);
    bool CheckItemUseLevel(int);
    bool IsPCBangItem(void);
    long FindApplyValue(BYTE);
    bool IsStackable(void);
    void Initialize(void);
    void Destroy(void);
    void Save(void);
    void SetWindow(BYTE);
    BYTE GetWindow(void);
    void SetID(DWORD);
    DWORD GetID(void);
    void SetProto(const TItemTable *);
    const TItemTable * GetProto(void);
    int GetGold(void);
    int GetShopBuyPrice(void);
    const char * GetName(void);
    const char * GetBaseName(void);
    BYTE GetSize(void);
    void SetFlag(long);
    long GetFlag(void);
    void AddFlag(long);
    void RemoveFlag(long);
    DWORD GetWearFlag(void);
    DWORD GetAntiFlag(void);
    DWORD GetImmuneFlag(void);
    void SetVID(DWORD);
    DWORD GetVID(void);
    bool SetCount(DWORD);
    DWORD GetCount(void);
    DWORD GetVnum(void) const;
    DWORD GetOriginalVnum(void) const;
    BYTE GetType(void) const;
    BYTE GetSubType(void) const;
    BYTE GetLimitType(DWORD) const;
    long GetLimitValue(DWORD) const;
    long GetValue(DWORD);
    void SetCell(LPCHARACTER, BYTE);
    BYTE GetCell(void);
    LPITEM RemoveFromCharacter(void);
    bool AddToCharacter(LPCHARACTER, BYTE, bool);
    LPCHARACTER GetOwner(void);
    LPITEM RemoveFromGround(void);
    bool AddToGround(long, const PIXEL_POSITION &, bool);
    int FindEquipCell(LPCHARACTER);
    bool IsEquipped(void) const;
    bool EquipTo(LPCHARACTER, BYTE);
    bool IsEquipable(void) const;
    bool CanUsedBy(LPCHARACTER);
    bool DistanceValid(LPCHARACTER);
    void UpdatePacket(void);
    void UsePacketEncode(LPCHARACTER, LPCHARACTER, packet_item_use *);
    void SetExchanging(bool);
    bool IsExchanging(void);
    bool IsTwohanded(void);
    bool IsPolymorphItem(void);
    void ModifyPoints(bool);
    bool CreateSocket(BYTE, BYTE);
    const long * GetSockets(void);
    long GetSocket(int);
    void SetSockets(const long *);
    void SetSocket(int, long, bool);
    int GetSocketCount(void);
    bool AddSocket(void);
    const TPlayerItemAttribute * GetAttributes(void);
    const TPlayerItemAttribute & GetAttribute(int);
    BYTE GetAttributeType(int);
    short GetAttributeValue(int);
    void SetAttributes(const TPlayerItemAttribute *);
    int FindAttribute(BYTE);
    bool RemoveAttributeAt(int);
    bool RemoveAttributeType(BYTE);
    bool HasAttr(BYTE);
    bool HasRareAttr(BYTE);
    void SetDestroyEvent(LPEVENT);
    void StartDestroyEvent(int);
    DWORD GetRefinedVnum(void);
    DWORD GetRefineFromVnum(void);
    int GetRefineLevel(void);
    void SetSkipSave(bool);
    bool GetSkipSave(void);
    bool IsOwnership(LPCHARACTER);
    void SetOwnership(LPCHARACTER, int);
    void SetOwnershipEvent(LPEVENT);
    DWORD GetLastOwnerPID(void);
    int GetAttributeSetIndex(void);
    void AlterToMagicItem(void);
    void AlterToSocketItem(int);
    WORD GetRefineSet(void);
    void StartUniqueExpireEvent(void);
    void SetUniqueExpireEvent(LPEVENT);
    void StartTimerBasedOnWearExpireEvent(void);
    void SetTimerBasedOnWearExpireEvent(LPEVENT);
    void StartRealTimeExpireEvent(void);
    bool IsRealTimeItem(void);
    int GetAttributeCount(void);
    void ClearAttribute(void);
    void ChangeAttribute(const int *);
    void AddAttribute(void);
    void AddAttribute(BYTE, short);
    void ApplyAddon(int);
    int GetSpecialGroup(void);
    bool IsAccessoryForSocket(void);
    int GetAccessorySocketGrade(void);
    int GetAccessorySocketMaxGrade(void);
    int GetAccessorySocketDownGradeTime(void);
    void SetAccessorySocketGrade(int);
    void SetAccessorySocketMaxGrade(int);
    void SetAccessorySocketDownGradeTime(DWORD);
    void AccessorySocketDegrade(void);
    void StartAccessorySocketExpireEvent(void);
    void SetAccessorySocketExpireEvent(LPEVENT);
    bool CanPutInto(LPITEM);
    void CopyAttributeTo(LPITEM);
    void CopySocketTo(LPITEM);
    int GetRareAttrCount(void);
    bool AddRareAttribute(void);
    bool ChangeRareAttribute(void);
    void AttrLog(void);
    void Lock(bool);
    bool isLocked(void) const;
  private:
    void SetAttribute(int, BYTE, short);
  public:
    void SetForceAttribute(int, BYTE, short);
  protected:
    bool EquipEx(bool);
    bool Unequip(void);
    void AddAttr(BYTE, BYTE);
    void PutAttribute(const int *);
    void PutAttributeWithLevel(BYTE);
    void StopUniqueExpireEvent(void);
    void StopTimerBasedOnWearExpireEvent(void);
    void StopAccessorySocketExpireEvent(void);
    bool OnAfterCreatedItem(void);
  public:
    bool IsRideItem(void);
    bool IsRamadanRing(void);
    void ClearMountAttributeAndAffect(void);
    bool IsNewMountItem(void);
    void SetMaskVnum(DWORD);
    DWORD GetMaskVnum(void);
    bool IsMaskedItem(void);
    void SetSIGVnum(DWORD);
    DWORD GetSIGVnum(void) const;
};

#endif // _GAME_CITEM_HPP
