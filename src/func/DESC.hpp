#ifndef __DESC_HPP
#define __DESC_HPP
#include "../addr.hpp"
#include "../gameinfo.hpp"
namespace DESC
{

typedef void (*tPacket)(GameFunc::DESC *, void const*, int);
typedef void (*tBufferedPacket)(GameFunc::DESC *, const void *, int);
extern tPacket Packet;
extern tBufferedPacket BufferedPacket;
}
#endif // __DESC_HPP
