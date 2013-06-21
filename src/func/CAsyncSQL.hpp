#ifndef __CASYNCSQL_HPP
#define __CASYNCSQL_HPP
#include "../addr.hpp"
#include "../gameinfo.hpp"
namespace CAsyncSQL
{
typedef GameFunc::_SQLMsg* (*tDirectQuery)(MYSQL, char *);
extern tDirectQuery DirectQuery;
}

#endif // __CASYNCSQL_HPP
