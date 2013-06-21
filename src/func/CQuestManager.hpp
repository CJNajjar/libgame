#ifndef __CQUESTMANAGER_HPP
#define __CQUESTMANAGER_HPP
#include "../gameinfo.hpp"
#include "../addr.hpp"
namespace CQuestManager
{
typedef GameFunc::CDungeon* (*tGetCurrentDungeon)(GameFunc::quest::CQuestManager*);
extern tGetCurrentDungeon GetCurrentDungeon;
typedef GameFunc::CHARACTER* (*tGetCurrentNPCCharacterPtr)(GameFunc::quest::CQuestManager*);
extern tGetCurrentNPCCharacterPtr GetCurrentNPCCharacterPtr;
typedef GameFunc::CItem* (*tGetCurrentItem)(GameFunc::quest::CQuestManager*);
extern tGetCurrentItem GetCurrentItem;
}
#endif // __CQUESTMANAGER_HPP
