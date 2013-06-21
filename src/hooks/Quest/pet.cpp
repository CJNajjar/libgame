#include "pet.hpp"
using namespace quest;
Quest_Pet::Quest_Pet(){};

int Quest_Pet::summon(lua_State *L){
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

		if(pkCh->m_pkPet!=nullptr)
		{
			CHARACTER::ChatPacket(pkCh, 1, "Du hast bereits ein Pet gerufen.");
			Lua::PushNumber(L, 0.0);
			return 1;
		}

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

        pkCh->m_pkPet = pkMob;

        /*if (Lua::IsString(L, 2))
        {
            pkCh->m_pkPet->m_stName = Lua::ToString(L, 2);
        }*/

        pkCh->m_pkPet->m_stName = pkCh->m_stName +  "'s Pet";
        pkCh->m_pkPet->m_stateMove.Set(pkCh->m_pkPet, &GameFunc::CHARACTER::StateHorse, &GameFunc::CHARACTER::StateHorse, &GameFunc::CHARACTER::StateHorse );



        if ( pkMob )
        {
            if(!CHARACTER::Show(pkCh->m_pkPet, pkCh->m_lMapIndex, lPosX, lPosY, lPosZ, 0))
            {

                CHARACTER_MANAGER::DestroyCharacter(*singleton_CHARACTER_MANAGER, pkCh->m_pkPet);
                SYSERR << "pet.summon cannot show monster" << std::endl;
                Lua::PushNumber(L, 0);
                return 1;
            }

            CHARACTER::SetRider(pkCh->m_pkPet, pkCh);
            Lua::PushNumber(L, 1);
            return 1;


        }
        else
        {
            CHARACTER::ChatPacket(pkCh, 1, "Could not spawn pet");
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

int Quest_Pet::is_summon(lua_State *L){
    if(!*singleton_CQuestManager)
    {
        SYSERR << "singelton CQuerManager check failed" << std::endl;
        Lua::PushNumber(L, 0);
        return 1;
    }

    GameFunc::quest::CQuestManager* questManager = *singleton_CQuestManager;
    GameFunc::CHARACTER * pkCh = questManager->m_pCurrentCharacter;

    if( pkCh->m_pkPet != nullptr ){
        Lua::PushBoolean(L, 1.0);

    }else{
        Lua::PushBoolean(L, 0.0);
    }
    return 1;
}

int Quest_Pet::unsummon(lua_State *L){
    if(!*singleton_CQuestManager)
    {
        SYSERR << "singelton CQuerManager check failed" << std::endl;
        Lua::PushNumber(L, 0);
        return 1;
    }

    GameFunc::quest::CQuestManager* questManager = *singleton_CQuestManager;
    GameFunc::CHARACTER * pkCh = questManager->m_pCurrentCharacter;
    if ( pkCh->m_pkPet != nullptr )
    {
        CHARACTER_MANAGER::DestroyCharacter(*singleton_CHARACTER_MANAGER, pkCh->m_pkPet);
        pkCh->m_pkPet = nullptr;
        Lua::PushNumber(L, 1);
    }
    else
    {
        Lua::PushNumber(L, 0);
    }
    return 1;
}

int Quest_Pet::give_bonus(lua_State *L){
    GameFunc::quest::CQuestManager* questManager = *singleton_CQuestManager;
    GameFunc::CHARACTER * pkCh = questManager->m_pCurrentCharacter;
	if(pkCh != nullptr)
	{
		CHARACTER::AddAffect(pkCh,
							534,
							static_cast<int>(Lua::ToNumber(L, 1)),
							static_cast<int>(Lua::ToNumber(L, 2)),
							0,
							60*60*24*356,
							0,
							0,
							0);
	}
    return 0;
}

int Quest_Pet::remove_bonus(lua_State * L){
    GameFunc::quest::CQuestManager* questManager = *singleton_CQuestManager;
    GameFunc::CHARACTER * pkCh = questManager->m_pCurrentCharacter;
	if(pkCh != nullptr)
	{
		CHARACTER::RemoveAffect(pkCh, 534);
	}
	return 0;
}

int Quest_Pet::set_name(lua_State *L){
    if(!*singleton_CQuestManager)
    {
        SYSERR << "singelton CQuestManager check failed" << std::endl;
        Lua::PushNumber(L, 0);
        return 1;
    }

    GameFunc::quest::CQuestManager* questManager = *singleton_CQuestManager;
    GameFunc::CHARACTER * pkCh = questManager->m_pCurrentCharacter;
    uint32_t dwVnum = static_cast<uint32_t>(Lua::ToNumber(L, 1));

    if ( pkCh->m_pkPet != nullptr )
    {
        std::string petName(Lua::ToString(L, 2), strlen(Lua::ToString(L, 2)));
        pkCh->m_pkPet->m_stName = petName;
        CHARACTER_MANAGER::DestroyCharacter(*singleton_CHARACTER_MANAGER, pkCh->m_pkPet);
		long lPosX = pkCh->m_pos.x;
        long lPosY = pkCh->m_pos.y;
        long lPosZ = pkCh->m_pos.z;

        long lSpawnPosX = number_ex(-50, 50, __FILE__, __LINE__);
        long lSpawnPosY = number_ex(-50, 50, __FILE__, __LINE__);

        lPosX = lPosX + lSpawnPosX;
        lPosY = lPosY + lSpawnPosY;

        float fRot =  pkCh->m_pointsInstant.fRot;
        long lMapIndex = pkCh->m_lMapIndex;

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
		if(pkMob)
		{
            if(!CHARACTER::Show(pkCh->m_pkPet, pkCh->m_lMapIndex, lPosX, lPosY, lPosZ, 0))
            {

                CHARACTER_MANAGER::DestroyCharacter(*singleton_CHARACTER_MANAGER, pkCh->m_pkPet);
                pkCh->m_pkPet = 0;
                SYSERR << "pet.summon cannot show pet" << std::endl;
                Lua::PushNumber(L, 0);
                return 1;
            }

            CHARACTER::SetRider(pkCh->m_pkPet, pkCh);
		}
        Lua::PushNumber(L, 1);
    }
    else
    {
        Lua::PushNumber(L, 0);
    }

    return 1;

}
const luaL_reg Quest_Pet::reg[]= {
    { "summon",Quest_Pet::summon},
    { "is_summon",Quest_Pet::is_summon},
    { "unsummon",Quest_Pet::unsummon},
    { "give_bonus",Quest_Pet::give_bonus},
    { "remove_bonus",Quest_Pet::remove_bonus},
    { "set_name",Quest_Pet::set_name},
    { NULL, NULL }
};


