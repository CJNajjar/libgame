#ifndef __DIF_HORSE_TABLE_HPP
#define __DIF_HORSE_TABLE_HPP
#include "../libm2/game/THorseStat.hpp"
using namespace libm2;
namespace dif{
extern THorseStat * c_aHorseStat;
THorseStat* getHorseTable();
THorseStat getHorseTable(short level);
void setHorseTable(short level, THorseStat stat);
}
#endif // __DIF_HORSE_TABLE_HP
