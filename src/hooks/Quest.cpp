#include "Quest.hpp"
using namespace quest;
Quest* Quest::instance(){
    if (sInstance==NULL){
        sInstance = new Quest();
    }
    return sInstance;
}
Quest* Quest::sInstance=NULL;
Quest::Quest(){
    this->detour = NULL;
    this->pc2 = new Quest_PC2();
    this->npc2 = new Quest_NPC2();
    this->mob = new Quest_Mob();
    this->party2 = new Quest_Party2();
    this->d2 = new Quest_D2();
    this->mysql = new Quest_MySQL();
    this->horse2 = new Quest_Horse2();
    this->pet = new Quest_Pet();
}

void Quest::init(){
    Quest::detour = new MologieDetours::Detour<tRegisterAffectFunctionTable>((tRegisterAffectFunctionTable)Addr::kRegisterAffectFunctionTable, Quest::hook);
    std::cout << "*** Adding Quest Hook, following tables will be added:"<<std::endl;
    std::cout << "    "<< this->pc2->name << std::endl;
    std::cout << "    "<< this->npc2->name << std::endl;
    std::cout << "    "<< this->mob->name << std::endl;
    std::cout << "    "<< this->party2->name << std::endl;
    std::cout << "    "<< this->d2->name << std::endl;
    std::cout << "    "<< this->mysql->name << std::endl;
    //std::cout << "    "<< this->horse2->name << std::endl;
    std::cout << "    "<< this->pet->name << std::endl;
}
void Quest::hook(){
    Quest* i = Quest::instance();
    AddLuaFunctionTable(*singleton_CQuestManager, i->pc2->name, i->pc2->reg) ;
    AddLuaFunctionTable(*singleton_CQuestManager, i->npc2->name, i->npc2->reg);
    AddLuaFunctionTable(*singleton_CQuestManager, i->mob->name, i->mob->reg);
    AddLuaFunctionTable(*singleton_CQuestManager, i->party2->name, i->party2->reg);
    AddLuaFunctionTable(*singleton_CQuestManager, i->d2->name, i->d2->reg);
    AddLuaFunctionTable(*singleton_CQuestManager, i->mysql->name, i->mysql->reg);
    //AddLuaFunctionTable(*singleton_CQuestManager, i->horse2->name, i->horse2->reg);
    AddLuaFunctionTable(*singleton_CQuestManager, i->pet->name, i->pet->reg);
    i->detour->GetOriginalFunction()();
}
