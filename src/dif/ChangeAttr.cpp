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
    // enable 6/7 attr change/add item, just disables it for isYmir
    libm2::dif((void*)0x80A1896,new unsigned char[2]{0x65,0x28},2);
    libm2::dif((void*)0x80A18A7,new unsigned char[2]{0x55,0x28},2);
    libm2::dif((void*)0x80A18B7,new unsigned char[2]{0x45,0x28},2);
    libm2::dif((void*)0x80A73BE,new unsigned char[2]{0x3E,0xCD},2);
    libm2::dif((void*)0x80A73D1,new unsigned char[2]{0x28,0xCD},2);
    libm2::dif((void*)0x80A73E1,new unsigned char[2]{0x1B,0xCD},2);
}
void ChangeAttr::SetTime(int time){
    (*(int*)myAddr::misc::change_attr_time)=time;
}
}
