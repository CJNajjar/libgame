#include "CharacterConstructor.hpp"
using namespace Hooks;

CharacterConstructor::CharacterConstructor():Hook::Hook(){}

void CharacterConstructor::hook(iCHARACTER* self){
    self->m_tLastSync=0;
    self->m_fSyncDist=0;
    instance()->detour->GetOriginalFunction()(self);
}
