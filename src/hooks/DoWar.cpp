#include "DoWar.hpp"
#include "../libm2/game/misc.hpp"
using namespace Hooks;
DoWar::DoWar():Hook::Hook(){}

void DoWar::hook(CHARACTER* self, const char * args, int cmd, int subcmd){
    char dummy, numbuf[100];
    two_arguments(args,&dummy,1,numbuf,100);
    if (numbuf[0]=='-'||strtol(numbuf,0,10)<0){
        return;
    }
    instance()->detour->GetOriginalFunction()(self,args,cmd,subcmd);
}

