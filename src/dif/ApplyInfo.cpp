#include "ApplyInfo.hpp"
#include "../myAddr.hpp"
#include "../libm2/lib/dif.hpp"
#include "../libm2/addr.hpp"
namespace dif{
// Original in case the "dif" doesnt get used
uint8_t* aApplyInfo=(uint8_t*)myAddr::misc::aApplyInfo;
ApplyInfo::ApplyInfo(){
    hookApplyPoint = simpleHook<void (*)(CHARACTER*, BYTE, int)>((unsigned int)Addr::CHARACTER::ApplyPoint__BYTE_int,ApplyInfo::hook);
    this->max_index=0;
    // read original
    for (int i=0;i<87;i++){
        this->m_mapApplyInfo.insert(std::pair<uint8_t,uint8_t>(i,aApplyInfo[i]));
    }
    this->init();
}
void ApplyInfo::hook(CHARACTER* ch, BYTE type, int value){
    if (type <= 86 || type > instance()->max_index){
        instance()->hookApplyPoint->GetOriginalFunction()(ch,type,value);
    }else{
        ch->PointChange(aApplyInfo[type], value, false, false);
    }
};
void ApplyInfo::init(){
    if (aApplyInfo!=(uint8_t*)myAddr::misc::aApplyInfo){
        delete aApplyInfo;
    }
    this->max_index=0;
    for (auto it=this->m_mapApplyInfo.begin();it!=this->m_mapApplyInfo.end();it++){
        if (it->first > this->max_index){
            this->max_index=it->first;
        }
    }
    // create new pointer
    aApplyInfo = new uint8_t[this->max_index+1];
    // fill empty array
    for (int i=0;i<this->max_index+1;i++){
        auto info = this->m_mapApplyInfo.find(i);
        if (info!=this->m_mapApplyInfo.end()){
            aApplyInfo[i] = info->second;
        }else{ // Automagically fill gaps with zeros
            aApplyInfo[i]=0;
        }
    }
    // overwrite all the old pointers
    for (unsigned int i=0;i<(sizeof(myAddr::aApplyInfo_refs)/4);i++){
        libm2::unprotect((void*)myAddr::aApplyInfo_refs[i],4);
        *(void**)myAddr::aApplyInfo_refs[i]=aApplyInfo;
    }
}
void ApplyInfo::SetApply(uint8_t apply, uint8_t point){
    auto info = this->m_mapApplyInfo.find(apply);
    if (info!=this->m_mapApplyInfo.end()){
        info->second=point;
    }else{
        this->m_mapApplyInfo.insert(std::pair<uint8_t,uint8_t>(apply,point));
    }
    this->init();
}

}
