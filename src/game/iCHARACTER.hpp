#ifndef _GAME_ICHARACTER_HPP
#define _GAME_ICHARACTER_HPP
#include "../libm2/game/CHARACTER.hpp"
using namespace libm2;
class iCHARACTER: public CHARACTER{
  public:
    time_t m_tLastSync;
    float m_fSyncDist;
};
#endif // _GAME_ICHARACTER_HPP
