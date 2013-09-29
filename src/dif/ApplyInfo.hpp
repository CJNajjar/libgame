#ifndef __DIF_APPLYINFO_HPP
#define __DIF_APPLYINFO_HPP
#include "../libm2/game/stdInclude.hpp"
#include "../libm2/lib/singleton.hpp"
namespace dif{
extern uint8_t* aApplyInfo;
class ApplyInfo: public libm2::singleton<ApplyInfo>{
protected:
    std::map<uint8_t,uint8_t> m_mapApplyInfo;
    uint8_t max_index;
public:
    ApplyInfo();
    void SetApply(uint8_t apply, uint8_t point);
protected:
    void init();
};
}
#endif // __DIF_APPLYINFO_HPP
