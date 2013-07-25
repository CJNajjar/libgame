#include <iostream>
#include <fstream>
#include "libm2/utils/detours.h"
#include "libm2/game/stdInclude.hpp"
#include "hooks/SyncPosition.hpp"
#include "hooks/CharacterConstructor.hpp"
#include "libm2/addr.hpp"
#include "libm2/lib/log.hpp"
#include "libm2/lib/increaseSize.hpp"
#include "libm2/LibM2.hpp"
void __attribute__ ((constructor)) lib_main(void);
using namespace libm2;
std::string Revision((char*)Addr::misc::version,5);
bool RIGHTREV=Revision=="34083";
MologieDetours::Detour<int(*)(int, char **)>* detour_main;
int main(int argc, char** argv){
    std::cout << std::endl << "****************** Starting LibGame Kickhackfix******************" << std::endl;
    std::cout << "**** Made by iMer (www.imer.cc).\n**** Special Thanks to Nova & tim66613" << std::endl;
    std::cout << "**** Game Revision is " << Revision << std::endl;
    try{
        Hooks::SyncPosition::instance();
        Hooks::CharacterConstructor::instance();
        LibM2::instance();
    }
    catch(MologieDetours::DetourException &e){
        std::cout << std::endl << "Error when hooking function: " << e.what() << std::endl << std::endl;
    }
    std::cout << "**** Hooking Phase completed!" << std::endl;
    increaseSize<iCHARACTER>((unsigned int*)Addr::CHARACTER_MANAGER::createCharacter_alloc);
    return detour_main->GetOriginalFunction()(argc, argv);
}
void lib_main()
{
    if (RIGHTREV){
        detour_main =new MologieDetours::Detour<int(*)(int, char **)>((int(*)(int, char **))Addr::misc::main, main);
    }
}
