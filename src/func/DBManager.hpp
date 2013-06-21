#ifndef __DBMANAGER_HPP
#define __DBMANAGER_HPP
#include "../addr.hpp"
#include "../gameinfo.hpp"
namespace DBManager
{
typedef GameFunc::_SQLMsg* (*tDirectQuery)(char *, const char *, ...);
typedef size_t (*tEscapeString)(GameFunc::DBManager*, char *, size_t, const char *, size_t);
extern tDirectQuery DirectQuery;
extern tEscapeString EscapeString;
}
#endif // __DBMANAGER_HPP
