#ifndef __LIBMYSQL_HPP
#define __LIBMYSQL_HPP
#include "../addr.hpp"
#include "../gameinfo.hpp"
namespace libMySQL
{
typedef MYSQL_FIELD * (*tFetchField)(MYSQL_RES*);
typedef MYSQL_FIELD * (*tFetchFields)(MYSQL_RES*);
typedef void (*tFreeResult)(MYSQL_RES*);
typedef MYSQL_ROW (*tFetchRow)(MYSQL_RES*);
typedef unsigned int (*tNumFields)(MYSQL_RES *);
extern tFetchField FetchField;
extern tFreeResult FreeResult;
extern tFetchRow FetchRow;
extern tFetchFields FetchFields;
extern tNumFields NumFields;
}
#endif // __LIBMYSQL_HPP
