#ifndef _GAME_ITEMTABLE_HPP
#define _GAME_ITEMTABLE_HPP
#include "SEntityTable.hpp"
struct SItemLimit {
    BYTE bType;
    long lValue;
} typedef TItemLimit;
struct SItemApply {
    BYTE bType;
    long lValue;
} typedef TItemApply;
struct SItemTable : public SEntityTable {
    char szName[25];
    char szLocaleName[25];
    BYTE bType;
    BYTE bSubType;
    BYTE bWeight;
    BYTE bSize;
    DWORD dwAntiFlags;
    DWORD dwFlags;
    DWORD dwWearFlags;
    DWORD dwImmuneFlag;
    DWORD dwGold;
    DWORD dwShopBuyPrice;
    TItemLimit aLimits[2];
    TItemApply aApplies[3];
    long alValues[6];
    long alSockets[3];
    DWORD dwRefinedVnum;
    WORD wRefineSet;
    BYTE bAlterToMagicItemPct;
    BYTE bSpecular;
    BYTE bGainSocketPct;
    short sAddonType;
    char cLimitRealTimeFirstUseIndex;
    char cLimitTimerBasedOnWearIndex;
} typedef TItemTable;

#endif // _GAME_ITEMTABLE_HPP
