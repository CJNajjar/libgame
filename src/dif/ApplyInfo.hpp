#ifndef __DIF_APPLYINFO_HPP
#define __DIF_APPLYINFO_HPP
#include "../libm2/game/stdInclude.hpp"
#include "../libm2/lib/singleton.hpp"
#include "../libm2/lib/hook.hpp"
#include "../libm2/game/CHARACTER.hpp"
namespace dif {
    using namespace libm2;
    extern uint8_t* aApplyInfo;

    class ApplyInfo : public libm2::singleton<ApplyInfo> {
    protected:
        std::map<uint8_t, uint8_t> m_mapApplyInfo;
        uint8_t max_index;
        MologieDetours::Detour<void (*)(CHARACTER*, BYTE, int)>* hookApplyPoint;
    public:
        ApplyInfo();
        void static hook(CHARACTER* ch, BYTE type, int value);
        void SetApply(uint8_t apply, uint8_t point);
    protected:
        void init();
    };
}
#endif // __DIF_APPLYINFO_HPP
