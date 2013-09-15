#include "ChangeAttr.hpp"
#include "../libm2/lib/dif.hpp"
#include "../myAddr.hpp"
namespace dif{
ChangeAttr::ChangeAttr(){
    unsigned char change_attr_dif[]={0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90};
    libm2::dif((void*)0x80A6CFB,change_attr_dif,11);
    libm2::dif((void*)0x80A6CEE,new char(0xC6),1);
    // min change_attr time (eventflag) =0
    libm2::dif((void*)0x80A6C94,new char(0x1),1);
    SetTime(1);
}
void ChangeAttr::SetTime(int time){
    (*(int*)myAddr::misc::change_attr_time)=time;
}
}
