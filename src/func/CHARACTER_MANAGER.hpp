#ifndef __CHARACTER_MANAGER_HPP
#define __CHARACTER_MANAGER_HPP
#include "../addr.hpp"
#include "../gameinfo.hpp"
namespace CHARACTER_MANAGER
{
typedef GameFunc::CHARACTER* (*tFindPC)(char*, char const*);
extern tFindPC FindPC;

typedef GameFunc::CHARACTER* (*tDestroyCharacter)(char*, GameFunc::CHARACTER*);
extern tDestroyCharacter DestroyCharacter;

/*  LPCHARACTER CHARACTER_MANAGER::SpawnMob(char*, unsigned int dwVnum, long lMapIndex, long x, long y, long z, bool bSpawnMotion, int iRot, bool bShow); */
typedef GameFunc::CHARACTER * (*tSpawnMob)(char*,unsigned int, long, long, long, long, bool, int, bool);
extern tSpawnMob SpawnMob;
typedef GameFunc::CHARACTER* (*tFindDWORD)(char *, DWORD);
extern tFindDWORD Find;
}
#endif // __CHARACTER_MANAGER_HPP
