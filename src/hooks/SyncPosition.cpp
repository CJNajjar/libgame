#include "SyncPosition.hpp"
#include "../libm2/game/CHARACTER_MANAGER.hpp"
#include "../libm2/lib/log.hpp"
#include "../libm2/game/misc.hpp"

namespace Hooks{
SyncPosition::SyncPosition():Hook::Hook() {
    // default config
    limit=25.0;
    playeronly=true;
    scoreaddThreshold=35.0;
    killwarning=5;
    autobanscore=10;
    scoreDecay=600;
}
void SyncPosition::configure(const YAML::Node config) {
    std::cout << "SyncPosition::configure" << std::endl;
    if (config["limit"]){
        this->limit=config["limit"].as<float>();
        std::cout << "\tlimit: "<<limit << std::endl;
    }
    if (config["playeraddonly"]){
        this->playeronly=config["playeraddonly"].as<bool>();
        std::cout << "\tplayeronly: " << playeronly<< std::endl;
    }
    if (config["scoreadd-threshold"]){
        this->scoreaddThreshold=config["scoreadd-threshold"].as<float>();
        std::cout << "\tscoreaddThreshold: " << scoreaddThreshold << std::endl;
    }
    if (config["killwarning"]){
        this->killwarning=config["killwarning"].as<unsigned int>();
        std::cout << "\tkillwarning: " << killwarning<< std::endl;
    }
    if (config["autobanscore"]){
        this->autobanscore=config["autobanscore"].as<unsigned int>();
        std::cout << "\tautobanscore: " << autobanscore << std::endl;
    }
    if (config["autobanreason"]){
        this->autobanreason=config["autobanreason"].as<std::string>();
        std::cout << "\tautobanreason: " << autobanreason<< std::endl;
    }
    if (config["score-decay"]){
        this->scoreDecay=config["score-decay"].as<int>();
        std::cout << "\tscoreDecay: " << scoreDecay << std::endl;
    }
}
int SyncPosition::hook(CInputMain* CInputMainPtr, iCHARACTER* ch, const char * data, size_t s) {
    SyncPosition* self=instance();
    size_t len = *(short*)(data+1);
    if (len>s) {
        SYSERR << "CInputMain::SycPosition :: length mismatch. Expected "<< s << " got "<< len <<". Player ("<<  ch->GetName() <<")" << std::endl;
        return -1;
    }
    short times=(len-3)/0xC;
    if (times > 16) {
        times=16;
    }
    unsigned char charType;
    float dist,y, x;
    // Buffer sent to everyone, but ch
    char* buffer = new char[3+0xC*16];
    char* bBase=buffer+3;
    short bCount=0;
    // Buffer sent to everyone
    char* selfBuffer = new char[3+0xC*16];
    char* sbBase=buffer+3;
    short sbCount=0;
    for (int i=0; i<3+0xC*16; i++) {
        selfBuffer[i]=0;
        buffer[i]=0;
    }
    const char* curAddr=data+3;
    iCHARACTER* chTarget;
    DWORD target;
    time_t time=get_global_time();
    for (int i=0; i<times; i++,curAddr+=0xC) {
        target = *(DWORD*)(curAddr);
        chTarget = (iCHARACTER*)CHARACTER_MANAGER::instance()->Find(target);
        if (!chTarget) {
            SYSERR << "CInputMain::SycPosition :: Invalid Target (" << target << " | " << chTarget << ") by Name(" << ch->GetName() << ")" << std::endl;
            continue;
        }
        charType = ch->GetCharType();
        if (charType!=1&&charType!=3&&chTarget->SetSyncOwner(ch,1)) {
            int px=(int)*(DWORD*)(curAddr+4);
            x = static_cast<float>(chTarget->GetX()-px)/100;
            int py=(int)*(DWORD*)(curAddr+8);
            y = static_cast<float>(chTarget->GetY()-py)/100;
            dist = sqrt(x*x+y*y);
            if (dist < 25.0) {
                if (chTarget->m_tLastSync != time) {
                    chTarget->m_tLastSync=time;
                    chTarget->m_fSyncDist=0.0;
                }
                if (chTarget->m_fSyncDist+dist > self->limit) {
                    if (chTarget->m_fSyncDist>=self->limit) {
                        SYSLOG << "CInputMain::SycPosition :: Dist too high (" << (chTarget->m_fSyncDist+dist) << ") - skipping - Name (" << ch->GetName() << ") Target (" << chTarget->GetName() << ")" << std::endl;
                        *(DWORD*)(sbBase)=target;
                        *(DWORD*)(sbBase+4)=chTarget->GetX();
                        *(DWORD*)(sbBase+8)=chTarget->GetY();
                        if (chTarget->m_fSyncDist + dist > self->scoreaddThreshold && ((self->playeronly && chTarget->GetDesc()) || !self->playeronly) ){
                            SYSLOG << "CInputMain::SyncPosition :: Violation! " << std::endl;
                            syncpos_violation violation;
                            violation.dist=chTarget->m_fSyncDist+dist;
                            violation.time=time;
                            violation.pid=chTarget->GetPlayerID();
                            ch->m_vec_syncPosViolation.push_back(violation);
                            for(unsigned int o=0;o<ch->m_vec_syncPosViolation.size();o++){
                                if (time - ch->m_vec_syncPosViolation[o].time > self->scoreDecay){
                                    ch->m_vec_syncPosViolation.erase(ch->m_vec_syncPosViolation.begin()+o);
                                }
                            }
                            if (ch->m_vec_syncPosViolation.size() >= self->autobanscore){
                                SYSLOG << "CInputMain::SycPosition :: Banning " << ch->GetName() << "("<<ch->GetPlayerID()<<")" << std::endl;
                                ch->ban(3600*24*265*30,self->autobanreason.c_str(),"SYSTEM");
                            }
                        }
                        sbBase+=0xC;
                        sbCount++;
                        chTarget->m_fSyncDist+=dist;
                        continue;
                    }
                    // normalize
                    float xN = x/dist;
                    float yN = y/dist;
                    // get dist it can go at max
                    float allowedDist=self->limit-chTarget->m_fSyncDist;
                    // and multiply and subtract the different from the real values
                    px -=(int)((x-xN*allowedDist)*100);
                    py -=(int)((y-yN*allowedDist)*100);
                }
                chTarget->m_fSyncDist+=dist;
                *(DWORD*)(bBase)=target;
                *(DWORD*)(bBase+4)=px;
                *(DWORD*)(bBase+8)=py;
                bBase+=0xC;
                bCount++;
                chTarget->Sync((long)px,(long)py);
            }
        }
    }
    // Send update packet to all players
    if (bCount>0) {
        // type
        *(buffer)=(char)5;
        //  size
        *(short*)(buffer+1)=(short)(3+0xC*bCount);
        ch->PacketAround(buffer,3+0xC*bCount,ch);
    }
    // Send update packet to all players
    if (sbCount>0) {
        // type
        *(selfBuffer)=(char)5;
        // size
        *(short*)(selfBuffer+1)=(short)(3+0xC*sbCount);
        ch->PacketAround(selfBuffer,(short)(3+0xC*sbCount),ch);
        ch->GetDesc()->Packet(selfBuffer,(short)(3+0xC*sbCount));
    }
    delete buffer;
    delete selfBuffer;
    return len-3;
}
}
