#include "iCHARACTER.hpp"
#include "../libm2/game/DBManager.hpp"
#include "../globals.hpp"
#include "../libm2/lib/log.hpp"
#include "../libm2/game/enums.hpp"
void iCHARACTER::ban(long len, const char* reason, const char* by) {
    std::ostringstream ss;
    // system used by hc (old hp)
    // todo: add better one
    ss << "UPDATE " << globals::instance()->account << ".account SET availDt=DATE_ADD(NOW(), INTERVAL " << len << " SECOND), question2=\"" << by << "\", answer2=\"" << reason << "\" WHERE id = (SELECT account_id FROM player where id=" << this->GetPlayerID() << ");";
    SYSLOG << ss.str() << std::endl;
    SQLMsg* res = DBManager::instance()->DirectQuery(ss.str().c_str());
    if (res->Get()->uiAffectedRows) {
        SYSLOG << "iCHARACTER::ban  - banned " << this->GetName() << " (" << this->GetPlayerID() << ") for " << len << " seconds for '" << reason << "' by " << by << "." << std::endl;
        this->GetDesc()->DelayedDisconnect(5);
    }
}
void iCHARACTER::setHorseState() {
    this->m_stateBattle.Set(this, &iCHARACTER::EndStateEmpty, &iCHARACTER::StateHorse, &iCHARACTER::EndStateEmpty);
    this->m_stateIdle.Set(this, &iCHARACTER::EndStateEmpty, &iCHARACTER::StateHorse, &iCHARACTER::EndStateEmpty);
};
bool iCHARACTER::UseItemEx(LPITEM item, int iDestCell) {
    switch (item->GetVnum()) {
    case 71051:
    case 71052:
        CItem* useon = this->GetItem(iDestCell);
        if (useon && useon->GetType()==ITEM_COSTUME){
            this->ChatPacket(CHAT_TYPE_INFO,locale_find("¼Ó¼ºÀ» º¯°æÇÒ ¼ö ¾ø´Â ¾ÆÀÌÅÛÀÔ´Ï´Ù."));
            return true;
        }
    }
    return globals::instance()->UseItemEx->GetOriginalFunction()(this, item, iDestCell);
}

void iCHARACTER::PointChange(BYTE type, int ammount, bool bAmmount, bool bBroadcast){
    switch (type){
        case POINT_ATTBONUS_INSECT:
            this->SetPoint(type, this->GetPoint(type)+ammount);
            if (ammount != 0 && this->GetDesc()){
                
            }
    }
    globals::instance()->PointChange->GetOriginalFunction()(this, type, ammount, bAmmount, bBroadcast);
}