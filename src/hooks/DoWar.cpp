#include "DoWar.hpp"
#include "../libm2/game/misc.hpp"
#include "../libm2/lib/log.hpp"
#include "../libm2/game/CHARACTER.hpp"
using namespace Hooks;
DoWar::DoWar():Hook::Hook(){}

void DoWar::hook(CHARACTER* self, const char * args, int cmd, int subcmd){
    char dummy[1024], numbuf[1024];
    two_arguments(args,dummy,1024,numbuf,1024);
    if (numbuf[0]=='-'||strtol(numbuf,0,10)<0){
        SYSLOG << self->GetName() << " tried to crash the server. (\"/war" << args << "\")" << std::endl;
        return;
    }
    instance()->detour->GetOriginalFunction()(self,args,cmd,subcmd);
}
