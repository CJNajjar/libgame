#ifndef __CSHOP_HPP
#define __CSHOP_HPP
#include "../addr.hpp"
#include "../gameinfo.hpp"
namespace CShop
{
typedef bool (*tAddGuest)(GameFunc::CShop * const, GameFunc::LPCHARACTER, DWORD,  bool);
}
#endif // __CSHOP_HPP
