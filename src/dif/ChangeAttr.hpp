#ifndef __DIF_CHANGEATTR_HPP
#define __DIF_CHANGEATTR_HPP
#include "../libm2/lib/singleton.hpp"
namespace dif{
class ChangeAttr: public libm2::singleton<ChangeAttr>{
public:
    ChangeAttr();
    void SetTime(int);
};
}
#endif // __DIF_CHANGEATTR_HPP
