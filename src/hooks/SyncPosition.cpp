#include "SyncPosition.hpp"
using namespace Hooks;
SyncPosition::SyncPosition():Hook::Hook(){}

int SyncPosition::hook(LPCHARACTER ch, const char * data, size_t size){
    ch->ChatPacket(0,"BlaBlub");
    ch->ChatPacket(0,"BlaBlub");
    ch->ChatPacket(0,"BlaBlub");
    ch->ChatPacket(0,"BlaBlub");
    ch->ChatPacket(0,"BlaBlub");
    ch->ChatPacket(0,"BlaBlub");
    return 1;
   /* size_t len = *(short*)(data+1);
    if (len>s){
        SYSERR << "CInputMain::SycPosition :: length mismatch. Expected "<< s << " got "<< len <<". Player ("<<ch->m_stName<<")" << std::endl;
        return -1;
    }
    short times=(len-3)/0xC;
    if (times > 16){
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
    for (int i=0;i<3+0xC*16;i++){
        selfBuffer[i]=0;
        buffer[i]=0;
    }
    const char* curAddr=data+3;
    GameFunc::CHARACTER* chTarget;
    DWORD target;
    time_t time=GetGlobalTime();
    for (int i=0;i<times;i++,curAddr+=0xC){
        if (!*singleton_CHARACTER_MANAGER)
            break;
        target = *(DWORD*)(curAddr);
        chTarget = CHARACTER_MANAGER::Find(*singleton_CHARACTER_MANAGER,target);
        if (!chTarget){
            SYSERR << "CInputMain::SycPosition :: Invalid Target (" << target << " | " << chTarget << ") by Name(" << ch->m_stName << ")" << std::endl;
            continue;
        }
        charType = CHARACTER::GetCharType(chTarget);
        if (charType!=1&&charType!=3&&CHARACTER::SetSyncOwner(chTarget,ch,1)){
            int px=(int)*(DWORD*)(curAddr+4);
            x = static_cast<float>(chTarget->m_pos.x-px)/100;
            int py=(int)*(DWORD*)(curAddr+8);
            y = static_cast<float>(chTarget->m_pos.y-py)/100;
            dist = sqrt(x*x+y*y);
            if (dist < 25.0){
                if (chTarget->m_tLastSync != time){
                    chTarget->m_tLastSync=time;
                    chTarget->m_fSyncDist=0.0;
                }
                if (chTarget->m_fSyncDist+dist > 25.0){
                    if (chTarget->m_fSyncDist>=25.0){
                        SYSLOG << "CInputMain::SycPosition :: Dist too high (" << chTarget->m_fSyncDist << " already) - skipping - Name (" << ch->m_stName << ") Target (" << chTarget->m_stName << ")" << std::endl;
                        *(DWORD*)(sbBase)=target;
                        *(DWORD*)(sbBase+4)=(DWORD)chTarget->m_pos.x;
                        *(DWORD*)(sbBase+8)=(DWORD)chTarget->m_pos.y;
                        sbBase+=0xC;
                        sbCount++;
                        chTarget->m_fSyncDist+=dist;
                        continue;
                    }
                    SYSLOG << "CInputMain::SycPosition :: Dist too high (" << chTarget->m_fSyncDist << " + " << dist << ") - limiting - Name (" << ch->m_stName << ") Target (" << chTarget->m_stName << ")" << std::endl;
                    // normalize
                    float xN = x/dist;
                    float yN = y/dist;
                    // get dist it can go at max
                    float allowedDist=25.0-chTarget->m_fSyncDist;
                    // and multiply and subtract the different from the real values
                    px -=(int)((x-xN*allowedDist)*100);
                    py -=(int)((y-yN*allowedDist)*100);
                }
                chTarget->m_fSyncDist+=dist;
                *(DWORD*)(bBase)=target;
                *(DWORD*)(bBase+4)=(DWORD)px;
                *(DWORD*)(bBase+8)=(DWORD)py;
                bBase+=0xC;
                bCount++;
                CHARACTER::Sync(chTarget,(long)px,(long)py);
            }
        }
    }
    // Send update packet to all players
    if (bCount>0){
        // type
        *(buffer)=(char)5;
        //  size
        *(buffer+1)=(short)(3+0xC*bCount);
        CEntity::PacketAround(ch,buffer,3+0xC*bCount,ch);
    }
    // Send update packet to all players
    if (sbCount>0){
        // type
        *(BYTE*)(selfBuffer)=(char)5;
        // size
        *(short*)(selfBuffer+1)=(short)(3+0xC*sbCount);
        CEntity::PacketAround(ch,selfBuffer,(short)(3+0xC*sbCount),nullptr);
    }
    delete buffer;
    delete selfBuffer;
    return len-3;*/
}
