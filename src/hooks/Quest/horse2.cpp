#include "horse2.hpp"

using namespace quest;

Quest_Horse2::Quest_Horse2(){}
const luaL_reg Quest_Horse2::reg[]= {
    { "summon",Quest_Horse2::summon},
    { NULL, NULL }
};
int Quest_Horse2::summon(lua_State* L){
    if(Lua::IsNumber(L, 1))
    {
        if(!*singleton_CHARACTER_MANAGER)
        {
            SYSERR << "singelton singleton_CHARACTER_MANAGER check failed" << std::endl;
            Lua::PushNumber(L, 0);
            return 1;
        }

        if(!*singleton_CQuestManager)
        {
            SYSERR << "singelton CQuerManager check failed" << std::endl;
            Lua::PushNumber(L, 0);
            return 1;
        }


        GameFunc::quest::CQuestManager * questManager = *singleton_CQuestManager;
        GameFunc::CHARACTER * pkCh = questManager->m_pCurrentCharacter;

        if(!pkCh)
        {
            SYSERR << "Quest did not set current character -> pkCh = " << pkCh << std::endl;
            SYSERR << sizeof(GameFunc::quest::CQuestManager) << " = sizeof(CQuestManager)" << std::endl;
            Lua::PushNumber(L, 0);
            return 1;
        }

		/*if(pkCh->m_chHorse != nullptr)
		{
		    CHARACTER::HorseSummon(pkCh,false,false);
			CHARACTER::ChatPacket(pkCh, 1, "Du hast bereits ein Pferd gerufen.");
			Lua::PushNumber(L, 0.0);
			return 1;
		}else{
            CHARACTER::HorseSummon(pkCh,true,false);
            if (pkCh->m_chHorse == nullptr){
                CHARACTER::ChatPacket(pkCh, 1, "No horsie for you... :/");
            }else{

                CHARACTER::ChatPacket(pkCh, 1, "Name: ");
                CHARACTER::ChatPacket(pkCh, 1, pkCh->m_chHorse->m_stName.c_str());
                CHARACTER::ChatPacket(pkCh, 1, "");
                CHARACTER_MANAGER::DestroyCharacter(*singleton_CHARACTER_MANAGER, pkCh->m_chHorse);
            }
		}*/

        long lPosX = pkCh->m_pos.x;
        long lPosY = pkCh->m_pos.y;
        long lPosZ = pkCh->m_pos.z;

        long lSpawnPosX = number_ex(-100, 100, __FILE__, __LINE__);
        long lSpawnPosY = number_ex(-100, 100, __FILE__, __LINE__);

        lPosX = lPosX + lSpawnPosX;
        lPosY = lPosY + lSpawnPosY;

        float fRot =  pkCh->m_pointsInstant.fRot;
        long lMapIndex = pkCh->m_lMapIndex;

        uint32_t dwVnum = static_cast<uint32_t>(Lua::ToNumber(L, 1));
        /*  LPCHARACTER CHARACTER_MANAGER::SpawnMob(char*, unsigned int dwVnum, long lMapIndex, long x, long y, long z, bool bSpawnMotion, int iRot, bool bShow); */

        GameFunc::CHARACTER* pkMob = CHARACTER_MANAGER::SpawnMob(*singleton_CHARACTER_MANAGER,
                                     dwVnum,
                                     lMapIndex,
                                     lPosX,
                                     lPosY,
                                     lPosZ,
                                     0,
                                     static_cast<int>(fRot + 180.0),
                                     0);

        //pkCh->m_chHorse = pkMob;

        /*if (Lua::IsString(L, 2))
        {
            pkCh->m_pkPet->m_stName = Lua::ToString(L, 2);
        }*/

        pkMob->m_stName = pkCh->m_stName +  "'s Pet";
        //pkCh->m_chHorse->m_stateMove.Set(pkCh->m_chHorse, &GameFunc::CHARACTER::StateHorse, &GameFunc::CHARACTER::StateHorse, &GameFunc::CHARACTER::StateHorse );



        if ( pkMob )
        {
            if(!CHARACTER::Show(pkMob, pkCh->m_lMapIndex, lPosX, lPosY, lPosZ, 0))
            {

                CHARACTER_MANAGER::DestroyCharacter(*singleton_CHARACTER_MANAGER, pkMob);
                SYSERR << "horse2.summon cannot show monster" << std::endl;
                Lua::PushNumber(L, 0);
                return 1;
            }

            CHARACTER::SetRider(pkMob, pkCh);
            Lua::PushNumber(L, 1);
            return 1;
        }
        else
        {
            CHARACTER::ChatPacket(pkCh, 1, "Could not spawn horse");
            Lua::PushNumber(L, 0);
            return 1;
        }


    }
    else
    {
        SYSERR << "Called Pet Summon without vnum" << std::endl;
    }
    return 1;
}

