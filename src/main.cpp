#define GAME_REV 1
#include "utils/detours.h"
#include "game/CHARACTER.hpp"
#if GAME_REV==1
std::string Revision((char*)0x8367B5C, 5);
bool RIGHTREV=Revision=="2089M";
#elif GAME_REV==2
std::string Revision((char*)0x836823C, 5);
bool RIGHTREV=Revision=="2089";
#endif
int Version = 1;
bool GameInitialized = 0;
void __attribute__ ((constructor)) lib_main(void);


template<int N>
struct print_size_as_warning
{
    char operator()()
    {
        return N + 256;    //deliberately causing overflow
    }
};

void lib_main()
{
//print_size_as_warning<((int)(&((GameFunc::CItem*)0)->m_pOwner))>()();
//    print_size_as_warning<sizeof(GameFunc::CHARACTER)>()();
//    static_assert(sizeof(((GameFunc::CHARACTER*)0)->m_stateMove)> 40, "Wrong char class size" );
    std::cout << std::endl << "****************** Starting Libgame ******************" << std::endl;
    if (RIGHTREV){
        std::cout << "*** Game Revision is " << Revision << std::endl;
        std::cout << "*** sizeof CHARACTER is " << sizeof(GameFunc::CHARACTER) << std::endl;
        try{

        }catch(MologieDetours::DetourException &e){
            std::cout << std::endl << "Error when hooking function: " << e.what() << std::endl << std::endl;
        }

        std::cout << "**** Hooking Phase completed!" << std::endl;

    }else{
        int i = 1;
        while(i != 10)
        {
            std::cout << "FATAL !!!! Libgame is not compatible to this game revision !!!!" << std::endl;
            usleep(200);
            ++i;
        }
    }
}
