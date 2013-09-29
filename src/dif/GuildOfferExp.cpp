#include "GuildOfferExp.hpp"
#include "../libm2/lib/dif.hpp"
namespace dif{
void enableOfferingAtMax(){
    libm2::dif((void*)0x8141EAF,new unsigned char[2]{0xED,0x24},2); // locale europe
}
}
