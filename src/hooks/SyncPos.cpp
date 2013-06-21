#include "SyncPos.hpp"
using namespace CInputMain;
HSyncPos* HSyncPos::instance(){
    if (sInstance==NULL){
        sInstance = new HSyncPos();
    }
    return sInstance;
}
HSyncPos* HSyncPos::sInstance=NULL;
HSyncPos::HSyncPos(){
}

void HSyncPos::init(){
    detour = new MologieDetours::Detour<tSyncPosition>((tSyncPosition)Addr::kSyncPosition, HSyncPos::hook);
}
int HSyncPos::hook(char * self, GameFunc::CHARACTER* ch , const char* data, size_t s){
    size_t len = *(short*)(data+1);
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
    /*DWORD segments[16][3];
    short segmentCount=0;
    DWORD selfSegments[16][3];
    short selfSegmentCount=0;*/
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
                        /*selfSegments[selfSegmentCount][0]=target;
                        selfSegments[selfSegmentCount][1]=chTarget->m_pos.x;
                        selfSegments[selfSegmentCount][2]=chTarget->m_pos.y;
                        selfSegmentCount++;*/
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
                /*segments[segmentCount][0]=target;
                segments[segmentCount][1]=px;
                segments[segmentCount][2]=py;
                segmentCount++;*/
                CHARACTER::Sync(chTarget,(long)px,(long)py);
            }
        }
    }
    /*if (segmentCount>0){
        // Send update packet to all players
        char* buffer = new char(3+0xC*segmentCount);
        // type
        *(BYTE*)(buffer)=5;
        // size
        *(short*)(buffer+1)=3+0xC*segmentCount;
        char* base=(buffer+3);
        for(int i=0;i<segmentCount;i++){
            *(DWORD*)(base)=segments[i][0];
            *(DWORD*)(base+4)=segments[i][1];
            *(DWORD*)(base+8)=segments[i][2];
            base+=0xC;
        }
        CEntity::PacketAround(ch,buffer,3+0xC*segmentCount,ch);
    }
    if (selfSegmentCount>0){
        // Send update packet to all players
        char* buffer2 = new char(3+0xC*selfSegmentCount);
        // type
        *(BYTE*)(buffer2)=5;
        // size
        *(short*)(buffer2+1)=3+0xC*selfSegmentCount;
        char* base=(buffer2+3);
        for(int i=0;i<selfSegmentCount;i++){
            *(DWORD*)(base)=selfSegments[i][0];
            *(DWORD*)(base+4)=selfSegments[i][1];
            *(DWORD*)(base+8)=selfSegments[i][2];
            base+=0xC;
        }
        CEntity::PacketAround(ch,buffer2,3+0xC*selfSegmentCount,nullptr);
    }*/
    return len-3;
}

