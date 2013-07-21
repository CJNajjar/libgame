#include "CHARACTER.hpp"
#include "../addr.hpp"

void CHARACTER::ChatPacket(BYTE type, const char * msg){
    ((void(*)(CHARACTER* pkCh,BYTE,const char*))(Addr::CHARACTER::ChatPacket))(this,type,msg);
}
