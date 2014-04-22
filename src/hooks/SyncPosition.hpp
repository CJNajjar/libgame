#ifndef _HOOKS_SYNCPOSITION_HPP
#define _HOOKS_SYNCPOSITION_HPP
#include "../libm2/lib/hook.hpp"
#include "../libm2/game/CInputMain.hpp"
#include "../libm2/addr.hpp"
#include "../game/iCHARACTER.hpp"
#include "../libm2/lib/singleton.hpp"
#include <yaml-cpp/yaml.h>
using namespace libm2;
namespace Hooks{
typedef int (*tSyncPosition)(CInputMain* self, iCHARACTER*, const char *, size_t);
class SyncPosition: public Hook<tSyncPosition,(unsigned int)Addr::CInputMain::SyncPosition__LPCHARACTER_const_char__size_t,SyncPosition>{
private:
    float limit;
    bool playeronly;
    float scoreaddThreshold;
    unsigned int killwarning;
    unsigned int autobanscore;
    std::string autobanreason;
    int scoreDecay;
public:
    SyncPosition();
    void configure(const YAML::Node config);
    static int hook(CInputMain* self, iCHARACTER* ch, const char * data, size_t size);
};
}
#endif // _HOOKS_SYNCPOSITION_HPP

