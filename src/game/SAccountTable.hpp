#ifndef _GAME_SACCOUNTTABLE_HPP
#define _GAME_SACCOUNTTABLE_HPP
#include "stdInclude.hpp"
#include "SSimplePlayer.hpp"
typedef struct SAccountTable {
    DWORD id;
    char login[31];
    char passwd[17];
    char social_id[19];
    char status[9];
    BYTE bEmpire;
    TSimplePlayer players[4];
} TAccountTable, * PAccountTable;

#endif // _GAME_SACCOUNTTYPE_HPP
