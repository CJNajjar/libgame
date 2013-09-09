#include "test.hpp"
namespace command{
bool Test::isReplaced(){
    return false;
};
bool Test::usableFor(LPCHARACTER ch){
    return true;
};
void Test::use(CHARACTER* ch,std::vector<std::string> args){
    ch->ChatPacket(1,"Test %i",args.size());
};
}
