#ifndef __HOOKS_CHARACTERCONSTRUCTOR_HPP
#define __HOOKS_CHARACTERCONSTRUCTOR_HPP
#include "Hook.hpp"
#include "../addr.hpp"
#include "../gameinfo.hpp"
#include "../func/General.hpp"
#include "../func/CHARACTER.hpp"
#include "../func/CHARACTER_MANAGER.hpp"
namespace CHARACTER{
class CharacterConstructor: public Hook{
    public:
        static void hook(GameFunc::CHARACTER* pkCh);
        void init();
        static CharacterConstructor* instance();
        MologieDetours::Detour<tCHARACTER>* detour;
    private:
        CharacterConstructor();
        static CharacterConstructor* sInstance;
};
}

#endif // __HOOKS_CHARACTERCONSTRUCTOR_HPP

