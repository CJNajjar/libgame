#include "CharacterDestroy.hpp"
using namespace CHARACTER;
CharacterDestroy* CharacterDestroy::instance(){
    if (sInstance==NULL){
        sInstance = new CharacterDestroy();
    }
    return sInstance;
}
CharacterDestroy* CharacterDestroy::sInstance=NULL;
CharacterDestroy::CharacterDestroy(){
}

void CharacterDestroy::init(){
    CharacterDestroy::detour = new MologieDetours::Detour<tDestroy>((tDestroy)Addr::kDestroy, CharacterDestroy::hook);
}
void CharacterDestroy::hook(GameFunc::CHARACTER* pkCh){

    CharacterDestroy * i = CharacterDestroy::instance();
    if( pkCh->m_pkPet != nullptr)
    {
        if(*singleton_CHARACTER_MANAGER)
            CHARACTER_MANAGER::DestroyCharacter(*singleton_CHARACTER_MANAGER, pkCh->m_pkPet);
        CHARACTER::RemoveAffect(pkCh, 534);

    }
    GameFunc::CHARACTER * rider = CHARACTER::GetRider(pkCh);
    if (rider!=nullptr&&rider->m_pkPet!=nullptr&&rider->m_pkPet==pkCh){
        rider->m_pkPet=nullptr;
    }
    i->detour->GetOriginalFunction()(pkCh);
}
