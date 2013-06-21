#include "General.hpp"
const std::string CurrentDateTime(){
    struct tm  tstruct;
    char       buf[80];
    time_t t;
    time(&t);
    tstruct = *localtime(&t);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

    return buf;
};
std::ofstream slog("libgame.stdlog.txt", std::ios_base::app | std::ios_base::out);
std::ofstream serr("libgame.stderr.txt", std::ios_base::app | std::ios_base::out);

tGetGlobalTime GetGlobalTime = (tGetGlobalTime)General::Addr::kGetGlobalTime;
tOneArgument one_argument = (tOneArgument)General::Addr::kOneArgument;
tnumber_ex number_ex = (tnumber_ex)General::Addr::kNumber_ex;
char** singleton_DBManager = (char**)General::Addr::kSingleton_DBManager;
GameFunc::ITEM_MANAGER** singleton_ITEM_MANAGER = (GameFunc::ITEM_MANAGER**)General::Addr::kSingleton_ITEM_MANAGER;
char** singleton_CHARACTER_MANAGER = (char**)General::Addr::kSingleton_CHARACTER_MANAGER;
GameFunc::quest::CQuestManager** singleton_CQuestManager = (GameFunc::quest::CQuestManager**)General::Addr::kSingleton_QUEST_MANAGER;
tSendNoticeMap SendNoticeMap = (tSendNoticeMap)General::Addr::kSendNoticeMap;
