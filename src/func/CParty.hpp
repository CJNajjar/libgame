#ifndef __CPARTY_HPP
#define __CPARTY_HPP
#include "../addr.hpp"
#include "../gameinfo.hpp"
namespace CParty{
typedef DWORD (*tGetLeaderPID)(GameFunc::CParty*);
extern tGetLeaderPID GetLeaderPID;
}
#endif

