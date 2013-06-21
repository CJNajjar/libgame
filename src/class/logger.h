#ifndef LIBGAME_LOGGER_H
#define LIBGAME_LOGGER_H


#include <cstdint>
#include <cstdio>
#include <fstream>

void SYSERR(std::string errMsg);
void SYSLOG(std::string logMsg);
void SYSDEBUG(std::string debugMsg);

std::ofstream logfile( "libgame.stdlog.txt", std::ios_base::app | std::ios_base::out );
std::ofstream errorfile( "libgame.stderr.txt", std::ios_base::app | std::ios_base::out );
std::ofstream debugfile( "libgame.debug.txt", std::ios_base::app | std::ios_base::out );
const std::string CurrentDateTime();


#endif // LIBGAME_LOGGER_H
