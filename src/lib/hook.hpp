#ifndef _LIB_HOOK_HPP
#define _LIB_HOOK_HPP
#include "../utils/detours.h"
#include "../game/stdInclude.hpp"
template<typename TType,unsigned int TAddress,class T> class Hook{
protected:
    MologieDetours::Detour<TType>* detour = NULL;
    Hook(){
        std::cout << "Hook @0x" << std::hex << TAddress << std::dec << std::endl;
        detour=new MologieDetours::Detour<TType>((TType)TAddress, T::hook);
    };
};
#endif // _HOOK_HOOK_HPP
