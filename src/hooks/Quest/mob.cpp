#include "mob.hpp"
using namespace quest;
Quest_Mob::Quest_Mob(){}
const luaL_reg Quest_Mob::reg[]= {
    { "get_vnum", Quest_Mob::get_vnum},
    { "get_type", Quest_Mob::get_type},
    { "get_rank", Quest_Mob::get_rank},
    { "get_exp", Quest_Mob::get_exp},
    { "get_level", Quest_Mob::get_level},
    { "get_str", Quest_Mob::get_str},
    { "get_dex", Quest_Mob::get_dex},
    { "get_con", Quest_Mob::get_con},
    { "get_int", Quest_Mob::get_int},
    { "get_max_hp", Quest_Mob::get_max_hp},
    { "get_summon_vnum", Quest_Mob::get_summon_vnum},
    { "get_regen_cycle", Quest_Mob::get_regen_cycle},
    { "get_regen_percent", Quest_Mob::get_regen_percent},
    { "get_def", Quest_Mob::get_def},
    { "set_def", Quest_Mob::set_def},
    { "get_damage_multiply", Quest_Mob::get_damage_multiply},
    { "set_damage_multiply", Quest_Mob::set_damage_multiply},
    { NULL, NULL }
};
int Quest_Mob::get_vnum(lua_State* L)
{
    GameFunc::CMob* pkMob = GetMobPointer();
    if(pkMob != nullptr)
        Lua::PushNumber(L, pkMob->m_table.dwVnum);
    else
        Lua::PushNil(L);
    return 1;
}

int Quest_Mob::get_type(lua_State* L)
{
    GameFunc::CMob* pkMob = GetMobPointer();
    if(pkMob != nullptr)
        Lua::PushNumber(L, pkMob->m_table.bType);
    else
        Lua::PushNil(L);
    return 1;
}

int Quest_Mob::get_rank(lua_State* L)
{
    GameFunc::CMob* pkMob = GetMobPointer();
    if(pkMob != nullptr)
        Lua::PushNumber(L, pkMob->m_table.bRank);
    else
        Lua::PushNil(L);
    return 1;
}

int Quest_Mob::get_level(lua_State* L)
{
    GameFunc::CMob* pkMob = GetMobPointer();
    if(pkMob != nullptr)
        Lua::PushNumber(L, pkMob->m_table.bLevel);
    else
        Lua::PushNil(L);
    return 1;
}

int Quest_Mob::get_str(lua_State* L)
{
    GameFunc::CMob* pkMob = GetMobPointer();
    if(pkMob != nullptr)
        Lua::PushNumber(L, pkMob->m_table.bStr);
    else
        Lua::PushNil(L);
    return 1;
}

int Quest_Mob::get_dex(lua_State* L)
{
    GameFunc::CMob* pkMob = GetMobPointer();
    if(pkMob != nullptr)
        Lua::PushNumber(L, pkMob->m_table.bDex);
    else
        Lua::PushNil(L);
    return 1;
}

int Quest_Mob::get_con(lua_State* L)
{
    GameFunc::CMob* pkMob = GetMobPointer();
    if(pkMob != nullptr)
        Lua::PushNumber(L, pkMob->m_table.bCon);
    else
        Lua::PushNil(L);
    return 1;
}

int Quest_Mob::get_int(lua_State* L)
{
    GameFunc::CMob* pkMob = GetMobPointer();
    if(pkMob != nullptr)
        Lua::PushNumber(L, pkMob->m_table.bInt);
    else
        Lua::PushNil(L);
    return 1;
}

int Quest_Mob::get_max_hp(lua_State* L)
{
    GameFunc::CMob* pkMob = GetMobPointer();
    if(pkMob != nullptr)
        Lua::PushNumber(L, pkMob->m_table.dwMaxHP);
    else
        Lua::PushNil(L);
    return 1;
}

int Quest_Mob::get_summon_vnum(lua_State* L)
{
    GameFunc::CMob* pkMob = GetMobPointer();
    if(pkMob != nullptr)
        Lua::PushNumber(L, pkMob->m_table.dwSummonVnum);
    else
        Lua::PushNil(L);
    return 1;
}

int Quest_Mob::get_exp(lua_State* L)
{
    GameFunc::CMob* pkMob = GetMobPointer();
    if(pkMob != nullptr)
        Lua::PushNumber(L, pkMob->m_table.dwExp);
    else
        Lua::PushNil(L);
    return 1;
}

int Quest_Mob::get_regen_cycle(lua_State* L)
{
    GameFunc::CMob* pkMob = GetMobPointer();
    if(pkMob != nullptr)
        Lua::PushNumber(L, pkMob->m_table.bRegenCycle);
    else
        Lua::PushNil(L);
    return 1;
}

int Quest_Mob::get_regen_percent(lua_State* L)
{
    GameFunc::CMob* pkMob = GetMobPointer();
    if(pkMob != nullptr)
        Lua::PushNumber(L, pkMob->m_table.bRegenPercent);
    else
        Lua::PushNil(L);
    return 1;
}

int Quest_Mob::get_def(lua_State* L)
{
    GameFunc::CMob* pkMob = GetMobPointer();
    if(pkMob != nullptr)
        Lua::PushNumber(L, pkMob->m_table.wDef);
    else
        Lua::PushNil(L);
    return 1;
}

int Quest_Mob::set_def(lua_State* L)
{
    if(!Lua::IsNumber(L, 1))
    {
        Lua::PushNil(L);
        return 1;
    }

    GameFunc::CMob* pkMob = GetMobPointer();
    if(pkMob != nullptr)
        pkMob->m_table.wDef = Lua::ToNumber(L, 1);
    else
        Lua::PushNil(L);
    return 1;
}

int Quest_Mob::get_damage_multiply(lua_State* L)
{
    GameFunc::CMob* pkMob = GetMobPointer();
    if(pkMob != nullptr)
        Lua::PushNumber(L, pkMob->m_table.fDamMultiply);
    else
        Lua::PushNil(L);
    return 1;
}

int Quest_Mob::set_damage_multiply(lua_State* L)
{
    if(!Lua::IsNumber(L, 1))
    {
        Lua::PushNil(L);
        return 1;
    }

    GameFunc::CMob* pkMob = GetMobPointer();
    if(pkMob != nullptr)
        pkMob->m_table.fDamMultiply = Lua::ToNumber(L, 1);
    else
        Lua::PushNil(L);
    return 1;
}


