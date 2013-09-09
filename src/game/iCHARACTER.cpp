#include "iCHARACTER.hpp"
#include "../libm2/game/DBManager.hpp"
#include "../globals.hpp"
#include "../libm2/lib/log.hpp"
void iCHARACTER::ban(long len, const char* reason, const char* by){
    std::ostringstream ss;
    // system used by hc (old hp)
    // todo: add better one
    ss << "UPDATE " << globals::instance()->account << ".account SET availDt=DATE_ADD(NOW(), INTERVAL "<< len <<" SECOND), question2=\""<<by << "\", answer2=\"" << reason << "\" WHERE id = (SELECT account_id FROM player where id="<< this->GetPlayerID() << ");";
    SYSLOG << ss.str() << std::endl;
    SQLMsg* res = DBManager::instance()->DirectQuery(ss.str().c_str());
    if (res->Get()->uiAffectedRows){
        SYSLOG << "iCHARACTER::ban  - banned " << this->GetName() << " ("<<this->GetPlayerID()<<") for " << len << " seconds for '"<< reason <<"' by " << by <<"." << std::endl;
        this->GetDesc()->DelayedDisconnect(5);
    }
}
