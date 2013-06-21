#ifndef __HOOKS_SYNCPOS_HPP
#define __HOOKS_SYNCPOS_HPP
#include "Hook.hpp"
#include "../addr.hpp"
#include "../gameinfo.hpp"
#include "../func/General.hpp"
#include "../func/CHARACTER.hpp"
#include "../func/CHARACTER_MANAGER.hpp"
#include "../func/CInputMain.hpp"
#include "../func/CEntity.hpp"
namespace CInputMain{
class HSyncPos: public Hook{
    public:
        static int hook(char * self, GameFunc::CHARACTER* ch ,  const char*arg, size_t s);
        void init();
        static HSyncPos* instance();
        MologieDetours::Detour<tSyncPosition>* detour;
    private:
        HSyncPos();
        static HSyncPos* sInstance;
};
}

#endif // __HOOKS_SYNCPOS_HPP


