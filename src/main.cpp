#define GAME_REV 1
#include "gameinfo.hpp"
#include "utils/detours.h"
#include "func/CEntity.hpp"
#include "func/CHARACTER.hpp"
#include "func/CHARACTER_MANAGER.hpp"
#include "func/CItem.hpp"
#include "func/CInputMain.hpp"
#include "func/ITEM_MANAGER.hpp"
#include "func/Command.hpp"
#include "func/CParty.hpp"
#include "func/CShop.hpp"
#include "func/DBManager.hpp"
#include "func/DESC.hpp"
#include "func/General.hpp"
#include "func/libMySQL.hpp"
#include "func/Lua.hpp"
#include "func/quest.hpp"
#include "func/CQuestManager.hpp"
#include "func/CAsyncSQL.hpp"
#include "hooks/Quest.hpp"
#include "hooks/CharacterDestroy.hpp"
#include "hooks/CharacterConstructor.hpp"
#include "hooks/SyncPos.hpp"
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
#ifndef SYNCPOSONLY
// detours
MologieDetours::Detour<tWriteVersion>* detour_WriteVersion;
MologieDetours::Detour<tMetin2Server_Check>* detour_Metin2Server_Check;
MologieDetours::Detour<Command::tcommand>* detour_GMBigNotice = NULL;
MologieDetours::Detour<Command::tcommand>* detour_GMChangeAttr = NULL;
MologieDetours::Detour<Command::tcommand>* detour_GMIpurge = NULL;
MologieDetours::Detour<quest::tRegisterAffectFunctionTable>* detour_RegisterAffectLua = NULL;

namespace Command {
	MologieDetours::Detour<tinterpret_command>* detour_InterpretCommand = NULL;
}

namespace CHARACTER{
MologieDetours::Detour<CHARACTER::tDestroy>* detour_CharacterDestroy = NULL;
void SendSpecialEffect2Packet(GameFunc::CHARACTER*, const char*);
}
namespace Command
{
void do_attribute_set(GameFunc::CHARACTER* ch,  const char* argument)
{

    GameFunc::LPITEM v1;
    GameFunc::LPITEM v2;
    GameFunc::LPITEM v3;
    GameFunc::LPITEM v4;
    GameFunc::LPITEM v5;
    GameFunc::LPITEM v6;
    GameFunc::LPITEM v7;
    GameFunc::LPITEM v8;
    GameFunc::LPITEM v9;
    GameFunc::LPITEM v10;
    GameFunc::LPITEM v11;
    GameFunc::LPITEM v12;
    GameFunc::LPITEM v13;
    GameFunc::LPITEM v14;
    GameFunc::LPITEM v15;
    GameFunc::LPITEM v16;

     if ( (uint8_t)CHARACTER::GetJob(ch) <= 3u )
      {
        v1 = CHARACTER::GetWear(ch, 1);
        v2 = v1;
        if ( v1 )
        {
          CItem::ClearAttribute(v1);
          CItem::SetAttribute(v2, 0, 7, 8);
          CItem::SetAttribute(v2, 1, 10, 30);
          CItem::SetAttribute(v2, 2, 11, 30);
          CItem::SetAttribute(v2, 3, 28, 15);
          CItem::SetAttribute(v2, 4, 24, 10);
        }
        v3 = CHARACTER::GetWear(ch, 4);
        v4 = v3;
        if ( v3 )
        {
          CItem::ClearAttribute(v3);
          CItem::SetAttribute(v4, 0, 9, 20);
          CItem::SetAttribute(v4, 1, 15, 10);
          CItem::SetAttribute(v4, 2, 16, 10);
          CItem::SetAttribute(v4, 3, 22, 20);
          CItem::SetAttribute(v4, 4, 5, 12);
        }
        v5 = CHARACTER::GetWear(ch, 10);
        v6 = v5;
        if ( v5 )
        {
          CItem::ClearAttribute(v5);
          CItem::SetAttribute(v6, 0, 3, 12);
          CItem::SetAttribute(v6, 1, 27, 15);
          CItem::SetAttribute(v6, 2, 39, 10);
          CItem::SetAttribute(v6, 3, 48, 1);
          CItem::SetAttribute(v6, 4, 49, 1);
        }
        v7 = CHARACTER::GetWear(ch, 0);
        v8 = v7;
        if ( v7 )
        {
          CItem::ClearAttribute(v7);
          CItem::SetAttribute(v8, 0, 1, 2000);
          CItem::SetAttribute(v8, 1, 9, 20);
          CItem::SetAttribute(v8, 2, 23, 10);
          CItem::SetAttribute(v8, 3, 39, 10);
          CItem::SetAttribute(v8, 4, 53, 50);
        }
        v9 = CHARACTER::GetWear(ch, 2);
        v10 = v9;
        if ( v9 )
        {
          CItem::ClearAttribute(v9);
          CItem::SetAttribute(v10, 0, 1, 2000);
          CItem::SetAttribute(v10, 1, 2, 80);
          CItem::SetAttribute(v10, 2, 8, 8);
          CItem::SetAttribute(v10, 3, 7, 8);
          CItem::SetAttribute(v10, 4, 15, 10);
        }
        v11 = CHARACTER::GetWear(ch, 3);
        v12 = v11;
        if ( v11 )
        {
          CItem::ClearAttribute(v11);
          CItem::SetAttribute(v12, 0, 1, 2000);
          CItem::SetAttribute(v12, 1, 2, 80);
          CItem::SetAttribute(v12, 2, 16, 10);
          CItem::SetAttribute(v12, 3, 23, 10);
          CItem::SetAttribute(v12, 4, 25, 10);
        }
        v13 = CHARACTER::GetWear(ch, 5);
        v14 = v13;
        if ( v13 )
        {
          CItem::ClearAttribute(v13);
          CItem::SetAttribute(v14, 0, 1, 2000);
          CItem::SetAttribute(v14, 1, 2, 80);
          CItem::SetAttribute(v14, 2, 15, 10);
          CItem::SetAttribute(v14, 3, 16, 10);
          CItem::SetAttribute(v14, 4, 24, 10);
        }
        v15 = CHARACTER::GetWear(ch, 6);
        v16 = v15;
        if ( v15 )
        {
          CItem::ClearAttribute(v15);
          CItem::SetAttribute(v16, 0, 8, 20);
          CItem::SetAttribute(v16, 1, 25, 10);
          CItem::SetAttribute(v16, 2, 41, 5);
          CItem::SetAttribute(v16, 3, 22, 20);
          CItem::SetAttribute(v16, 4, 21, 20);
        }
      }
}

void _addToEquip(GameFunc::CHARACTER* pkCh, DWORD vnum)
{
    GameFunc::CItem* newItem;
    int newEquipCell;

    newItem = ITEM_MANAGER::CreateItem(*singleton_ITEM_MANAGER, vnum, 1, 0, 0, -1);
    newEquipCell = CItem::FindEquipCell(newItem, pkCh);
    if( !newItem || !CItem::EquipTo(newItem, pkCh, newEquipCell))
        ITEM_MANAGER::DestroyItem(*singleton_ITEM_MANAGER, newItem);
}

void do_item_set(GameFunc::CHARACTER* ch,  const char* argument)
{
    BYTE job = CHARACTER::GetJob(ch);
    int i = 0;
    do
    {
        GameFunc::CItem* pWear = CHARACTER::GetWear(ch, i);
        if(pWear)
            CHARACTER::UnequipItem(ch, pWear);
		++i;
    } while(i != 6);

    switch(job)
    {
    case 0:
        _addToEquip(ch, 11299); // Rüstung
        _addToEquip(ch, 13069); // Schild
        _addToEquip(ch, 15209); // Schuhe
        _addToEquip(ch, 149); // Waffe
        _addToEquip(ch, 12249); // Helm
        _addToEquip(ch, 14209); // Armband
        _addToEquip(ch, 17109); // Ohrringe
        _addToEquip(ch, 16209); // Kette

        do_attribute_set(ch,argument);
        break;
    case 1:
        _addToEquip(ch, 11499); // Rüstung
        _addToEquip(ch, 13069); // Schild
        _addToEquip(ch, 15209); // Schuhe
        _addToEquip(ch, 1139); // Waffe
        _addToEquip(ch, 12249); // Helm
        _addToEquip(ch, 14209); // Armband
        _addToEquip(ch, 17109); // Ohrringe
        _addToEquip(ch, 16209); // Kette
        do_attribute_set(ch,argument);
        break;
    case 2:
        _addToEquip(ch, 11699); // Rüstung
        _addToEquip(ch, 13069); // Schild
        _addToEquip(ch, 15209); // Schuhe
        _addToEquip(ch, 159); // Waffe
        _addToEquip(ch, 12249); // Helm
        _addToEquip(ch, 14209); // Armband
        _addToEquip(ch, 17209); // Ohrringe
        _addToEquip(ch, 16209); // Kette
        do_attribute_set(ch,argument);
        break;
    case 3:
        _addToEquip(ch, 11899); // Rüstung
        _addToEquip(ch, 13069); // Schild
        _addToEquip(ch, 15209); // Schuhe
        _addToEquip(ch, 7149); // Waffe
        _addToEquip(ch, 12249); // Helm
        _addToEquip(ch, 14209); // Armband
        _addToEquip(ch, 17209); // Ohrringe
        _addToEquip(ch, 16209); // Kette
        do_attribute_set(ch,argument);
        break;
    }
}

void do_all_skill_master(GameFunc::CHARACTER* ch,  const char* argument)
{
    int i = 1;
    do
    {
        if(CHARACTER::CanUseSkill(ch, i) || i - 137 <= 3)
            CHARACTER::SetSkillLevel(ch, i, 40);
        ++i;
    }
    while (i != 255);
}

void do_full_set(GameFunc::CHARACTER* ch,  const char* argument)
{
    do_item_set(ch, argument);
    do_all_skill_master(ch, argument);
}

void hook_GMChangeAttr(GameFunc::CHARACTER* ch, char const* argument, int cmd, int subcmd)
{
    uint8_t Wear;
    Wear = atoi(argument);
    if(Wear > 8)
    {
        CHARACTER::ChatPacket(ch, 1, "Der Parameter 1 darf nicht größer als 8 sein.");
        return;
    }
    GameFunc::CItem* itemPtr = CHARACTER::GetWear(ch, Wear);
    if(itemPtr)
    {
        CItem::ChangeAttribute(itemPtr, 0);
    }

}

void hook_GMBigNotice(GameFunc::CHARACTER * ch, char const* argument, int cmd, int subcmd)
{
    if (argument){
        SendNoticeMap(argument, ch->m_lMapIndex, 1);
    }else{
        CHARACTER::ChatPacket(ch, 1, "Usage: bignotice <name>");
        CHARACTER::ChatPacket(ch, 1, "sends map-wide notice");
    }
}

void hook_GMIPurge(GameFunc::CHARACTER* ch, char const* argument, int cmd, int subcmd)
{
    char charName;

    one_argument(argument, &charName, 256u);

    if ( charName )
    {
        if(!*singleton_CHARACTER_MANAGER)
        {
            CHARACTER::ChatPacket(ch , 1,"Error character manager check failed");
            return;
        }



        GameFunc::CHARACTER* player = CHARACTER_MANAGER::FindPC(*singleton_CHARACTER_MANAGER, &charName);
        if( player )
        {
            CHARACTER::ChatPacket(ch, 1, "Found player");

            int i = 0;

            while(i != 111)
            {
                GameFunc::CItem* lpItem = CHARACTER::GetItem(player, i);
                if(lpItem)
                {
                    CHARACTER::ChatPacket(ch, 1, "Item Found!");

                    if( !*singleton_ITEM_MANAGER )
                    { //http://pastebin.com/JxKsVAxU
                        CHARACTER::ChatPacket(ch, 1, "Item_Manager not found");
                        return;

                    }

                    ITEM_MANAGER::RemoveItem(*singleton_ITEM_MANAGER, lpItem, "PURGE");
                    CHARACTER::SyncQuickslot(player, 1, i, 255);
                }
                ++i;
            }

        }
        else
        {
            CHARACTER::ChatPacket(ch, 1, "Player not found");
        }


    }
    else
    {
        CHARACTER::ChatPacket(ch, 1, "Usage: ipurge <name>");
    }


}

}
namespace GameFunc
{

void CHARACTER::StateHorse() {
	SYSLOG << "Pet state executed" << std::endl;
    ::CHARACTER::StateHorse(this);
}
}

namespace Command {
void hook_InterpretCommand(GameFunc::LPCHARACTER ch, char const* argument, unsigned int len)
{
    std::string command (argument, strlen(argument));
    std::vector<std::string> x = split(command, ' ');

    auto i = FindCommand(myCommandMap, x[0]);
    if(i != myCommandMap.end())
    {
        CHARACTER::ChatPacket(ch, 1, i->first.c_str());

        my_command_info cmd = i->second;
        if(ch->m_pointsInstant.gm_level >= cmd.gm_level)
        {
            cmd.command_pointer(ch, x[1].c_str());
        } else {
            CHARACTER::ChatPacket(ch, 1, "Befehl nicht gefunden.");
        }
    } else {
        detour_InterpretCommand->GetOriginalFunction()(ch, argument, len);
    }
}

void RegisterCommand(std::string argument, command_ptr command_pointer, int gm_level)
{
    my_command_info myCommand;
    myCommand.command_pointer = command_pointer;
    myCommand.gm_level = gm_level;
    myCommandMap.insert( std::pair<std::string, my_command_info>(argument, myCommand));
}
}

void hook_WriteVersion()
{

    std::ofstream VersionFile("Version.txt", std::ios_base::app | std::ios_base::out);
    VersionFile << "game svn revision: " << Revision << std::endl;
    VersionFile << "Libgame Version " << Version << std::endl;
}

void hook_Metin2Server_Check()
{
    GameInitialized = 1;
    Command::RegisterCommand("all_skill_master", Command::do_all_skill_master, 3);
    Command::RegisterCommand("attribute_set", Command::do_attribute_set, 3);
    Command::RegisterCommand("full_set", Command::do_full_set, 3);
    Command::RegisterCommand("gm_item_set", Command::do_item_set, 3);
}

namespace CHARACTER {
	void hook_Destroy(GameFunc::CHARACTER * pkCh)
	{
		if( pkCh->m_pkPet->m_chRider == pkCh)
		{
			SYSLOG << "Destroying pet with pet pointer " << (int)pkCh->m_pkPet << std::endl;
			if(*singleton_CHARACTER_MANAGER)
				CHARACTER_MANAGER::DestroyCharacter(*singleton_CHARACTER_MANAGER, pkCh->m_pkPet);
			//CHARACTER::RemoveAffect(pkCh, 534);

		}
		detour_CharacterDestroy->GetOriginalFunction()(pkCh);
	}
}
#endif // SYNCPOSONLY

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
            quest::Quest::instance()->init();
            CInputMain::HSyncPos::instance()->init();
            CHARACTER::CharacterDestroy::instance()->init();
            CHARACTER::CharacterConstructor::instance()->init();
            detour_WriteVersion = new MologieDetours::Detour<tWriteVersion>((tWriteVersion)General::Addr::kWriteVersion , hook_WriteVersion);
            detour_Metin2Server_Check = new MologieDetours::Detour<tMetin2Server_Check>((tMetin2Server_Check)General::Addr::kMetin2Server_Check , hook_Metin2Server_Check);
			Command::detour_InterpretCommand = new MologieDetours::Detour<Command::tinterpret_command>((Command::tinterpret_command)Command::Addr::kInterpret_command, Command::hook_InterpretCommand);
			detour_GMBigNotice = new MologieDetours::Detour<Command::tcommand>((Command::tcommand)Command::Addr::kBigNotice , Command::hook_GMBigNotice);
            detour_GMChangeAttr = new MologieDetours::Detour<Command::tcommand>((Command::tcommand)Command::Addr::kChangeAttr , Command::hook_GMChangeAttr);
            detour_GMIpurge = new MologieDetours::Detour<Command::tcommand>((Command::tcommand)Command::Addr::kIPurge , Command::hook_GMIPurge);
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
