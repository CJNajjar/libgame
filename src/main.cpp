#include <iostream>
#include <fstream>
#include "libm2/utils/detours.h"
#include "libm2/game/stdInclude.hpp"
#include "hooks/SyncPosition.hpp"
#include "hooks/CharacterConstructor.hpp"
#include "hooks/HorseVnum.hpp"
#include "hooks/HorseApply.hpp"
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
#include "libm2/game/enums.hpp"
#include "dif/HorseTable.hpp"
#include <yaml-cpp/yaml.h>
#include "globals.hpp"
#include "commands/test.hpp"
#include "hooks/DoWar.hpp"
void __attribute__ ((constructor)) lib_main(void);
using namespace ::quest;
using namespace libm2;
std::string Revision((char*)Addr::misc::version,5);
bool RIGHTREV=Revision=="34083";
bool file_exists(const char* filename){
    std::ifstream f(filename);
    return f;
}
void lib_main(){
    if (!RIGHTREV){
        std::cout << "This lib is not compatible to this game revision!" << std::endl;
        abort();
    }
    if (!file_exists("config.yml")){
        std::cout << "Could not load config.yml - file does not exist." << std::endl;
        abort();
    }
    YAML::Node config = YAML::LoadFile("config.yml");
    std::cout << std::endl << "****************** Starting LibGame ******************" << std::endl;
    std::cout << "**** Made by iMer (www.imer.cc).\n**** Special Thanks to Nova & tim66613" << std::endl;
    std::cout << "**** Game Revision is " << Revision << std::endl;
    LibM2::removePRELOAD();
    if (config["account-db"]){
        globals::instance()->account=config["account-db"].as<std::string>();
        std::cout << "Account table: " << globals::instance()->account << std::endl;
    }
    try{
        if (config["hooks"]["SyncPosition"]["enable"]){
            Hooks::SyncPosition::instance()->configure(config["hooks"]["SyncPosition"]);
            Hooks::CharacterConstructor::instance();
            increaseSize<iCHARACTER>((unsigned int*)Addr::CHARACTER_MANAGER::createCharacter_alloc);
        }
        if (config["hooks"]["HorseVnum"]["enable"]){
            Hooks::HorseVnum::instance();
        }
        if (config["hooks"]["HorseApply"]["enable"]){
            Hooks::HorseApply::instance();
        }
        Hooks::DoWar::instance();
        LibM2::instance();
    } catch(MologieDetours::DetourException &e) {
        std::cout << std::endl << "Error when hooking function: " << e.what() << std::endl << std::endl;
        abort();
    }
    if (config["quest"]["npc2"]){
        LibM2::addQuestTable(tNPC2::instance());
    }
    LibM2::addCommand("test",new command::Test());
    std::cout << "**** Hooking Phase completed!" << std::endl;
    if (config["dif"]["priv_empire_max_rate"]){
        dif::priv_empire_change_max_rate(config["dif"]["priv_empire_max_rate"].as<int>());
    }
    std::cout << "Setting max. map count to 255" << std::endl;
    libm2::dif((void*)0x80FDD65,new char(0xFF),1);
    std::cout << "Enabling always recieving status points" << std::endl;
    unsigned char status_always_dif[]={0xE9,0x8D,0x0B,0x00,0x00};
    // Always recieve them for levelup
    libm2::dif((void*)0x80787AC,&status_always_dif,5);
    // reset, give full ammount
    libm2::dif((void*)0x807C93F,new char(0xFF),1);
    std::cout << "**** Done initializing!" << std::endl;
}
