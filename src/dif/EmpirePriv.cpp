#include "EmpirePriv.hpp"
#include "../libm2/lib/dif.hpp"
#include "../myAddr.hpp"
#include <iostream>
using namespace libm2;
namespace dif{
void priv_empire_change_max_rate(int rate){
    int* priv_empire_rate_max = (int*)myAddr::misc::priv_empire_maxrate; // CPrivManager::Request
    int* priv_empire_rate_max2 = (int*)myAddr::misc::priv_empire_maxrate2; // do_priv_empire
    int* priv_empire_rate_max3 = (int*)myAddr::misc::priv_empire_maxrate3; // CPrivManager::Give
    std::cout << "Increasing max. priv_empire rate to 1000 (previous: "<< *priv_empire_rate_max << ", "<< *priv_empire_rate_max2 << ", "<< *priv_empire_rate_max3 << ")" <<std::endl;
    unprotect(priv_empire_rate_max,4);
    unprotect(priv_empire_rate_max2,4);
    unprotect(priv_empire_rate_max3,4);
    *priv_empire_rate_max=1000;
    *priv_empire_rate_max2=1000;
    *priv_empire_rate_max3=1000;
}
}
