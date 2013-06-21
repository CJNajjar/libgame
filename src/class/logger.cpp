#include "logger.h"

logger::logger()
{
    logfile.open( "libgame.stdlog.txt", std::ios_base::app | std::ios_base::out );
    errorfile.open( "libgame.stderr.txt", std::ios_base::app | std::ios_base::out );
    debugfile.open ( "libgame.debug.txt", std::ios_base::app | std::ios_base::out );
}

logger::~logger()
{
    logfile.close();
    errorfile.close();
    debugfile.close();
}

void logger::SYSERR( std::string errMsg )
{
    this->errorfile << "[" << this->CurrentDateTime() << "] " << ": In Function " << __FUNCTION__ << ", L. " << __LINE__ << " :: " << errMsg;
}

void logger::SYSLOG( std::string logMsg )
{
    this->logfile << "[" << this->CurrentDateTime() << "] " << ": In Function " << __FUNCTION__ << ", L. " << __LINE__ << " :: " << logMsg;
}

void logger::SYSDEBUG( std::string dbgMsg )
{
    this->debugfile << "[" << this->CurrentDateTime() << "] " << ": In Function " << __FUNCTION__ << ", L. " << __LINE__ << " :: "  << dbgMsg;
}

const std::string logger::CurrentDateTime()
{
    struct tm  tstruct;
    char       buf[80];
    time_t t;
    time(&t);
    tstruct = *localtime(&t);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

    return buf;
};
