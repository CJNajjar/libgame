#include "CalcAttBonus.hpp"
#include "../libm2/game/enums.hpp"
namespace Hooks {

    CalcAttBonus::CalcAttBonus() : Hook::Hook() {
    }

    int CalcAttBonus::hook(CHARACTER* pkAttacker, CHARACTER* pkVictim, int iAtk) {
        if (pkVictim->GetDesc()) {
            iAtk += pkAttacker->GetMarriageBonus(UNIQUE_ITEM_MARRIAGE_ATTACK_BONUS, true);
        }
        int iAtkBase = iAtk;
        // mob boni
        if (pkVictim->GetCharType() != CHAR_TYPE_PC) {
            if (pkVictim->IsRaceFlag(RACE_FLAG_ANIMAL)) {
                iAtk += (iAtkBase * pkAttacker->GetPoint(POINT_ATTBONUS_ANIMAL)) / 100;
            }
            if (pkVictim->IsRaceFlag(RACE_FLAG_UNDEAD)) {
                iAtk += (iAtkBase * pkAttacker->GetPoint(POINT_ATTBONUS_UNDEAD)) / 100;
            }
            if (pkVictim->IsRaceFlag(RACE_FLAG_DEVIL)) {
                iAtk += (iAtkBase * pkAttacker->GetPoint(POINT_ATTBONUS_DEVIL)) / 100;
            }
            if (pkVictim->IsRaceFlag(RACE_FLAG_HUMAN)) {
                iAtk += (iAtkBase * pkAttacker->GetPoint(POINT_ATTBONUS_HUMAN)) / 100;
            }
            if (pkVictim->IsRaceFlag(RACE_FLAG_ORC)) {
                iAtk += (iAtkBase * pkAttacker->GetPoint(POINT_ATTBONUS_ORC)) / 100;
            }
            if (pkVictim->IsRaceFlag(RACE_FLAG_MILGYO)) {
                iAtk += (iAtkBase * pkAttacker->GetPoint(POINT_ATTBONUS_MILGYO)) / 100;
            }
            if (pkVictim->IsRaceFlag(RACE_FLAG_INSECT)) {
                iAtk += (iAtkBase * pkAttacker->GetPoint(POINT_ATTBONUS_INSECT)) / 100;
            }
            if (pkVictim->IsRaceFlag(RACE_FLAG_FIRE)) {
                iAtk += (iAtkBase * pkAttacker->GetPoint(POINT_ATTBONUS_FIRE)) / 100;
            }
            if (pkVictim->IsRaceFlag(RACE_FLAG_ICE)) {
                iAtk += (iAtkBase * pkAttacker->GetPoint(POINT_ATTBONUS_ICE)) / 100;
            }
            if (pkVictim->IsRaceFlag(RACE_FLAG_DESERT)) {
                iAtk += (iAtkBase * pkAttacker->GetPoint(POINT_ATTBONUS_DESERT)) / 100;
            }
            if (pkVictim->IsRaceFlag(RACE_FLAG_TREE)) {
                iAtk += (iAtkBase * pkAttacker->GetPoint(POINT_ATTBONUS_TREE)) / 100;
            }
            iAtk += (iAtk * pkAttacker->GetPoint(POINT_ATTBONUS_MONSTER)) / 100;
        }
        if (pkVictim->GetDesc()) {
            iAtk += (iAtk * pkAttacker->GetPoint(POINT_ATTBONUS_HUMAN)) / 100;
            DWORD type = 0;
            switch (pkVictim->GetJob()) {
                case 0:
                    type = POINT_ATTBONUS_WARRIOR;
                    break;
                case 1:
                    type = POINT_ATTBONUS_ASSASSIN;
                    break;
                case 2:
                    type = POINT_ATTBONUS_SURA;
                    break;
                case 3:
                    type = POINT_ATTBONUS_SHAMAN;
                    break;
            }
            iAtk += (iAtk * pkAttacker->GetPoint(type)) / 100;
        }
        if (pkAttacker->GetDesc()) {
            DWORD type = 0;
            switch (pkAttacker->GetJob()) {
                case 0:
                    type = POINT_RESIST_WARRIOR;
                    break;
                case 1:
                    type = POINT_RESIST_ASSASSIN;
                    break;
                case 2:
                    type = POINT_RESIST_SURA;
                    break;
                case 3:
                    type = POINT_RESIST_SHAMAN;
                    break;
            }
            iAtk -= (iAtk * pkVictim->GetPoint(type)) / 100;
        }
        return iAtk;
    }

};
