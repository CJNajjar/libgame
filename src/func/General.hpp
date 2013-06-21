#ifndef __GENERAL_HPP
#define __GENERAL_HPP
#include "../addr.hpp"
#include "../gameinfo.hpp"
#define CURDATE CurrentDateTime()
extern std::ofstream slog;
#define SYSLOG slog << CURDATE << ":" << __LINE__ << " :: "
extern std::ofstream serr;
#define SYSERR serr << CURDATE << ":" << __LINE__ << " :: "
const std::string CurrentDateTime();
// typedefs of functions to hook
typedef void (*tWriteVersion)();
typedef void (*tMetin2Server_Check)();
typedef void (*tCPacketInfoCG)(char*);
typedef time_t (*tGetGlobalTime)();
typedef const char* (*tOneArgument)(char const*, char*, unsigned int);
typedef int (*tnumber_ex)(int, int, const char *, int);
typedef void (*tSendNoticeMap)(char const*, int, bool);

extern tGetGlobalTime GetGlobalTime;
extern tOneArgument one_argument;
extern tnumber_ex number_ex;
extern char** singleton_DBManager;
extern GameFunc::ITEM_MANAGER** singleton_ITEM_MANAGER;
extern char** singleton_CHARACTER_MANAGER;
extern GameFunc::quest::CQuestManager** singleton_CQuestManager;
extern tSendNoticeMap SendNoticeMap;

#endif // __GENERAL_HPP
