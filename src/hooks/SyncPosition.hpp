#ifndef _HOOKS_SYNCPOSITION_HPP
#define _HOOKS_SYNCPOSITION_HPP
#include "../libm2/lib/hook.hpp"
#include "../libm2/game/CInputMain.hpp"
#include "../libm2/addr.hpp"
#include "../game/iCHARACTER.hpp"
#include "../libm2/lib/singleton.hpp"
using namespace libm2;
namespace Hooks{
typedef int (*tSyncPosition)(CInputMain* self, iCHARACTER*, const char *, size_t);
class SyncPosition: public Hook<tSyncPosition,(unsigned int)Addr::CInputMain::SyncPosition,SyncPosition>{
    public:
    SyncPosition();
    static int hook(CInputMain* self, iCHARACTER* ch, const char * data, size_t size);
};
}
#endif // _HOOKS_SYNCPOSITION_HPP

