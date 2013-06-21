#include "CharacterConstructor.hpp"
using namespace CHARACTER;
CharacterConstructor* CharacterConstructor::instance(){
    if (sInstance==NULL){
        sInstance = new CharacterConstructor();
    }
    return sInstance;
}
CharacterConstructor* CharacterConstructor::sInstance=NULL;
CharacterConstructor::CharacterConstructor(){
}

void CharacterConstructor::init(){
    detour = new MologieDetours::Detour<tCHARACTER>((tCHARACTER)Addr::kCHARACTER, CharacterConstructor::hook);
}
void CharacterConstructor::hook(GameFunc::CHARACTER* pkCh){
    CharacterConstructor::instance()->detour->GetOriginalFunction()(pkCh);
    pkCh->m_pkPet=nullptr;
    pkCh->m_tLastSync=0;
    pkCh->m_fSyncDist=0.0;
}

