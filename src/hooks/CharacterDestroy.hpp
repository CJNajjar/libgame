#ifndef __HOOKS_CHARACTERDESTROY_HPP
#define __HOOKS_CHARACTERDESTROY_HPP
#include "Hook.hpp"
#include "../addr.hpp"
#include "../gameinfo.hpp"
#include "../func/General.hpp"
#include "../func/CHARACTER.hpp"
#include "../func/CHARACTER_MANAGER.hpp"
namespace CHARACTER{
class CharacterDestroy: public Hook{
    public:
        static void hook(GameFunc::CHARACTER* pkCh);
        void init();
        static CharacterDestroy* instance();
        MologieDetours::Detour<tDestroy>* detour;
    private:
        CharacterDestroy();
        static CharacterDestroy* sInstance;
};
}

#endif // __HOOKS_CHARACTERDESTROY_HPP

