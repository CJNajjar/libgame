#include "mysql.hpp"
using namespace quest;
Quest_MySQL::Quest_MySQL(){}
const luaL_reg Quest_MySQL::reg[3]= {
    { "query", Quest_MySQL::query},
    { "escape",Quest_MySQL::escape},
    { NULL, NULL }
};
int Quest_MySQL::query(lua_State *L)
{

    if (Lua::IsString(L, 1))
    {
        GameFunc::_SQLMsg* sqlMsg = DBManager::DirectQuery(*singleton_DBManager, Lua::ToString(L, 1));
        if(sqlMsg == nullptr)
        {
            SYSERR << "DBManager::DirectQuery failed" << std::endl;
            Lua::PushBoolean(L, 0);
            return 1;
        }

        MYSQL_RES* pRes = sqlMsg->vec_pkResult[0]->pSQLResult;

        if (pRes == nullptr)
        {
            Lua::PushBoolean(L, 0);
            return 0;
        }


        MYSQL_ROW row;

        Lua::NewTable(L);
        int rowcount = 1;
        unsigned int num_fields = libMySQL::NumFields(pRes);
        MYSQL_FIELD * fields = libMySQL::FetchFields(pRes);
        while((row = libMySQL::FetchRow(pRes)))
        {
            Lua::NewTable(L);
            Lua::PushNumber(L, rowcount);
            Lua::PushValue(L, -2);
            Lua::SetTable(L, -4);

            unsigned int i;

            for(i = 0; i < num_fields; i++)
            {
                SYSERR << row[i] << " " << fields[i].name << std::endl;
                Lua::PushNumber(L, i + 1);
                Lua::PushString(L, row[i]);
                Lua::SetTable(L, -3);
            }

            Lua::SetTop(L, Lua::GetTop(L) - 1);

            rowcount++;
        }
        libMySQL::FreeResult(pRes);

        /* return the number of results */

        return 1;


    }
    return 0;

}


int Quest_MySQL::escape(lua_State *L)
{
    return 1;
}

