#include "HorseVnum.hpp"
#include <sstream>
#include "../libm2/game/quest/CQuestManager.hpp"
#include "../game/iCHARACTER.hpp"
using namespace Hooks;
using namespace libm2;
HorseVnum::HorseVnum():Hook::Hook(){
    // Default settings
    int i;
    vnums[0].normal=0;
    vnums[0].guild=0;
    vnums[0].guildmaster=0;
    for (i=1;i<11;i++){
        vnums[i].normal=20101;
        vnums[i].guild=20102;
        vnums[i].guildmaster=20103;
    }
    for (i=10;i<21;i++){
        vnums[i].normal=20104;
        vnums[i].guild=20105;
        vnums[i].guildmaster=20106;
    }
    for (i=21;i<30;i++){
        vnums[i].normal=20107;
        vnums[i].guild=20108;
        vnums[i].guildmaster=20109;
    }
    detourSummon=simpleHook<void (*)(CHARACTER * const, bool, bool, DWORD, const char *)>((unsigned int)Addr::CHARACTER::HorseSummon,HorseVnum::hookSummon);
}
unsigned int HorseVnum::hook(CHARACTER* self){
    quest::PC* qPC = quest::CQuestManager::instance()->GetPC(self->GetPlayerID());
    if (qPC){
        int flag = qPC->GetFlag("horse_summon.horse_vnum");
        if (flag){
            return flag;
        }
    }
    if (self->GetGuild()){
        if (self->GetGuild()->GetMasterPID()==self->GetPlayerID()){
            return instance()->vnums[self->GetHorseLevel()].guildmaster;
        }
        return instance()->vnums[self->GetHorseLevel()].guild;
    }
    return instance()->vnums[self->GetHorseLevel()].normal;
}
void HorseVnum::set(short level, unsigned int vnum, unsigned int vnum_guild, unsigned int vnum_guildmaster){
    if (level < 30){
        vnums[level].normal=vnum;
        vnums[level].guild=vnum_guild;
        vnums[level].guildmaster=vnum_guildmaster;
    }
}
void HorseVnum::set(short level, unsigned int vnum, unsigned int vnum_guild){
    set(level, vnum, vnum_guild, vnum_guild);
}
void HorseVnum::set(short level, unsigned int vnum){
    set(level, vnum, vnum, vnum);
}
HorseVnum::TVnum HorseVnum::get(short level){
    return vnums[level];
}
void HorseVnum::hookSummon(CHARACTER* self,bool b1,bool b2,DWORD vnum, const char* name){
    instance()->detourSummon->GetOriginalFunction()(self,b1,b2,vnum,name);
    if (self->GetHorse()){
        ((iCHARACTER*)self->GetHorse())->setHorseState();
    }
}
