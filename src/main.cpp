#include "utils/detours.h"
#include "game/stdInclude.hpp"
#include <iostream>
#include <fstream>
#include "hooks/SyncPosition.hpp"
#include "addr.hpp"
void __attribute__ ((constructor)) lib_main(void);

std::string Revision((char*)Addr::misc::version,5);
bool RIGHTREV=Revision=="34083";


const std::string CurrentDateTime(){
    struct tm tstruct;
    char buf[80];
    time_t t;
    time(&t);
    tstruct = *localtime(&t);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

    return buf;
};

std::ofstream slog("libgame.stdlog.txt", std::ios_base::app | std::ios_base::out);
std::ofstream serr("libgame.stderr.txt", std::ios_base::app | std::ios_base::out);

#define SYSLOG slog << CURDATE << ":" << __LINE__ << " :: "
#define SYSERR serr << CURDATE << ":" << __LINE__ << " :: "

void lib_main()
{
    std::cout << std::endl << "****************** Starting LibGame ******************" << std::endl;
    if (RIGHTREV){
        std::cout<<"sizeof(CHARACTER)" << sizeof(CHARACTER) <<std::endl;
        std::cout << "*** Game Revision is " << Revision << std::endl;
        try{
            Hooks::SyncPosition* s=new Hooks::SyncPosition();
        }catch(MologieDetours::DetourException &e){
            std::cout << std::endl << "Error when hooking function: " << e.what() << std::endl << std::endl;
        }
        std::cout << "**** Hooking Phase completed!" << std::endl;
    }else{
        int i = 1;
        while(i != 10)
        {
            std::cout << "FATAL !!!! LibGame is not compatible to this game revision !!!!" << std::endl;
            usleep(200);
            ++i;
        }
    }
}
