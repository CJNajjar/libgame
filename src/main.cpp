#include <iostream>
#include <fstream>
#include "libm2/utils/detours.h"
#include "libm2/game/stdInclude.hpp"
#include "hooks/SyncPosition.hpp"
#include "hooks/CharacterConstructor.hpp"
#include "libm2/addr.hpp"
#include "libm2/lib/log.hpp"
#include "libm2/lib/hook.hpp"
#include "libm2/lib/increaseSize.hpp"
#include "libm2/LibM2.hpp"
#include "quest/npc2.hpp"
#include "libm2/game/ITEM_MANAGER.hpp"
#include "libm2/game/DESC_MANAGER.hpp"
#include "myAddr.hpp"
#include "dif/EmpirePriv.hpp"
void __attribute__ ((constructor)) lib_main(void);
using namespace ::quest;
using namespace libm2;
std::string Revision((char*)Addr::misc::version,5);
bool RIGHTREV=Revision=="34083";
MologieDetours::Detour<void(*)(void)>* detour_hook;
void lib_main(){
    if (!RIGHTREV){
        std::cout << "This lib is not compatible to this game revision!" << std::endl;
        return;
    }
    std::cout << std::endl << "****************** Starting LibGame (HC Edition) ******************" << std::endl;
    std::cout << "**** Made by iMer (www.imer.cc).\n**** Special Thanks to Nova & tim66613" << std::endl;
    std::cout << "**** Game Revision is " << Revision << std::endl;
    LibM2::removePRELOAD();
    try{
        //detour_hook=simpleHook<void(*)(void)>((unsigned int)Addr::misc::Metin2Server_Check,Check);
        //detour_hook=simpleHook<void(*)(void)>(0x82321B0,Check);

        Hooks::SyncPosition::instance();
        Hooks::CharacterConstructor::instance();
        LibM2::instance();
        LibM2::addQuestTable(tNPC2::instance());
    } catch(MologieDetours::DetourException &e) {
        std::cout << std::endl << "Error when hooking function: " << e.what() << std::endl << std::endl;
    }
    std::cout << "**** Hooking Phase completed!" << std::endl;
    dif::priv_empire_change_max_rate(1000);
    increaseSize<iCHARACTER>((unsigned int*)Addr::CHARACTER_MANAGER::createCharacter_alloc);
    std::cout << "**** Done initializing!" << std::endl;
}
