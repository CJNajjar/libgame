#include "test.hpp"
#include "../libm2/lib/log.hpp"
#include "../libm2/game/CHARACTER_MANAGER.hpp"
#include "../libm2/game/enums.hpp"
#include "../libm2/game/DBManager.hpp"
namespace command{
bool Test::isReplaced(){
    return false;
};
bool Test::usableFor(LPCHARACTER ch){
    return true;
};
void Test::use(CHARACTER* ch,std::vector<std::string> args){
    SQLMsg* msg = DBManager::instance()->DirectQuery("SELECT 1,2");
    MYSQL_RES* res=msg->Get()->pSQLResult;
    if (!res){
     // error
    }
    MYSQL_ROW row; // array of char* strings
    while ((row=mysql_fetch_row(res))){
     // row[0] is "1" (null-terminated char* string)
     // row[1] is "2" 
        ch->ChatPacket(1,row[0]);
        ch->ChatPacket(1,row[1]);
     // if you want a number (int, bool etc) look into (http://www.cplusplus.com/reference/cstdlib/strtoul/)[stroul] and the sort
    }
};
}
