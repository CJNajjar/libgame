#ifndef _HOOKS_SYNCPOSITION_HPP
#define _HOOKS_SYNCPOSITION_HPP
#include "../lib/hook.hpp"
#include "../game/CInputMain.hpp"
#include "../addr.hpp"
#include "../game/CHARACTER.hpp"
namespace Hooks{
typedef int (*tSyncPosition)(LPCHARACTER, const char *, size_t);
class SyncPosition: public Hook<tSyncPosition,(unsigned int)Addr::CInputMain::SyncPosition,SyncPosition>{
    public:
    SyncPosition();
    static int hook(LPCHARACTER ch, const char * data, size_t size);
};
}
#endif // _HOOKS_SYNCPOSITION_HPP

