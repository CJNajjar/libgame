#ifndef __HOOKS_QUEST_HPP
#define __HOOKS_QUEST_HPP
#include "Hook.hpp"
#include "../addr.hpp"
#include "../gameinfo.hpp"
#include "Quest/pc2.hpp"
#include "Quest/npc2.hpp"
#include "Quest/mob.hpp"
#include "Quest/party2.hpp"
#include "Quest/d2.hpp"
#include "Quest/pet.hpp"
#include "Quest/mysql.hpp"
#include "Quest/horse2.hpp"
#include "../func/quest.hpp"
#include "../func/CQuestManager.hpp"
#include "../func/General.hpp"
#include "../func/CHARACTER.hpp"
namespace quest{
class Quest: public Hook{
    public:
        static void hook();
        void init();
        Quest_PC2* pc2;
        Quest_NPC2* npc2;
        Quest_Mob* mob;
        Quest_Party2* party2;
        Quest_D2* d2;
        Quest_MySQL* mysql;
        Quest_Horse2* horse2;
        Quest_Pet* pet;
        static Quest* instance();
        MologieDetours::Detour<tRegisterAffectFunctionTable>* detour;
    private:
        Quest();
        static Quest* sInstance;
};
}

#endif // __HOOKS_QUEST_HPP