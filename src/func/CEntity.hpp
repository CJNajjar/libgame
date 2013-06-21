#ifndef __CENTITY_HPP
#define __CENEITY_HPP
#include "../addr.hpp"
#include "../gameinfo.hpp"
namespace CEntity
{
/* void CEntity::PacketAround(void const*data, int bytes, CEntity*except); */
typedef void (*tPacketAround)(GameFunc::CEntity*, void const*, int, GameFunc::CEntity*);
extern tPacketAround PacketAround;
}
#endif // __CENTITY_HPP
