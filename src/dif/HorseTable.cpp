#include "HorseTable.hpp"
#include "../myAddr.hpp"
namespace dif{
THorseStat* c_aHorseStat=(THorseStat*)myAddr::horse::c_aHorseStat;
THorseStat* getHorseTable(){
    return c_aHorseStat;
};
THorseStat getHorseTable(short level){
    if (level > 30){
        return {};
    }
    return c_aHorseStat[level];
};
void setHorseTable(short level, THorseStat stat){

};
}
