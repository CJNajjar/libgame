#include "quest.hpp"
namespace quest{
GameFunc::CMob* GetMobPointer()
{
    GameFunc::CHARACTER* pkCh = CQuestManager::GetCurrentNPCCharacterPtr(*singleton_CQuestManager);
    if(pkCh != nullptr)
    {
        return pkCh->m_pkMobData;
    }
    else
    {
        return 0;
    }
}
tAddLuaFuncTable AddLuaFunctionTable = (tAddLuaFuncTable)Addr::kAddLuaFunctionTable;
tRegisterAffectFunctionTable RegisterAffectFunctionTable = (tRegisterAffectFunctionTable)Addr::kRegisterAffectFunctionTable;
}
