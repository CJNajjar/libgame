#include "CQuestManager.hpp"

namespace CQuestManager{
tGetCurrentDungeon GetCurrentDungeon = (tGetCurrentDungeon)Addr::kGetCurrentDungeon;
tGetCurrentNPCCharacterPtr GetCurrentNPCCharacterPtr = (tGetCurrentNPCCharacterPtr)Addr::kGetCurrentNPCCharacterPtr;
tGetCurrentItem GetCurrentItem = (tGetCurrentItem)Addr::kGetCurrentItem;
}
