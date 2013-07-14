#ifndef _GAME_DESC_HPP
#define _GAME_DESC_HPP
#include "stdInclude.hpp"
#include "CInputProcessor.hpp"
#include "CInputClose.hpp"
#include "CInputHandshake.hpp"
#include "CInputLogin.hpp"
#include "CInputMain.hpp"
#include "CInputDead.hpp"
#include "CInputAuth.hpp"
#include "FDWATCH.hpp"
#include "Cipher.hpp"
#include "BUFFER.hpp"
#include "EVENT.hpp"
#include "SAccountTable.hpp"
#include "CLoginKey.hpp"
class DESC;
typedef DESC* LPDESC;

class DESC {
  protected:
    CInputProcessor *m_pInputProcessor;
    CInputClose m_inputClose;
    CInputHandshake m_inputHandshake;
    CInputLogin m_inputLogin;
    CInputMain m_inputMain;
    CInputDead m_inputDead;
    CInputAuth m_inputAuth;
    LPFDWATCH m_lpFdw;
    socket_t m_sock;
    int m_iPhase;
    DWORD m_dwHandle;
    std::string m_stHost;
    WORD m_wPort;
    time_t m_LastTryToConnectTime;
    LPBUFFER m_lpInputBuffer;
    int m_iMinInputBufferLen;
    DWORD m_dwHandshake;
    DWORD m_dwHandshakeSentTime;
    int m_iHandshakeRetry;
    DWORD m_dwClientTime;
    bool m_bHandshaking;
    LPBUFFER m_lpBufferedOutputBuffer;
    LPBUFFER m_lpOutputBuffer;
    LPEVENT m_pkPingEvent;
    LPCHARACTER m_lpCharacter;
    TAccountTable m_accountTable;
    sockaddr_in m_SockAddr;
    sockaddr_in m_UDPSockAddr;
    FILE *m_pLogFile;
    std::string m_stRelayName;
    std::string m_stP2PHost;
    WORD m_wP2PPort;
    BYTE m_bP2PChannel;
    bool m_bAdminMode;
    bool m_bPong;
    int m_iCurrentSequence;
    DWORD m_dwMatrixRows;
    DWORD m_dwMatrixCols;
    BYTE m_bMatrixTryCount;
    CLoginKey *m_pkLoginKey;
    DWORD m_dwLoginKey;
    DWORD m_dwPanamaKey;
    BYTE m_bCRCMagicCubeIdx;
    DWORD m_dwProcCRC;
    DWORD m_dwFileCRC;
    bool m_bHackCRCQuery;
    DWORD m_dwBillingExpireSecond;
    std::string m_stClientVersion;
    std::string m_stMatrixCode;
    std::string m_Login;
    int m_outtime;
    int m_playtime;
    int m_offtime;
    bool m_bDestroyed;
    Cipher cipher_;
  public:
    LPEVENT m_pkDisconnectEvent;
  protected:
    std::string m_stMatrixCardID;
    std::string m_stMatrixQuiz;
  public:
    seq_vector_t m_seq_vector;

    DESC();
    ~DESC();
    virtual BYTE GetType(void);
    virtual void Destroy(void);
    virtual void SetPhase(int);
    void FlushOutput(void);
    bool Setup(LPFDWATCH, socket_t, const sockaddr_in &, DWORD, DWORD);
    socket_t GetSocket(void) const;
    const char * GetHostName(void);
    void SetP2P(const char *, WORD, BYTE);
    const char * GetP2PHost(void);
    WORD GetP2PPort(void) const;
    BYTE GetP2PChannel(void) const;
    void BufferedPacket(const void *, int);
    void Packet(const void *, int);
    void LargePacket(const void *, int);
    int ProcessInput(void);
    int ProcessOutput(void);
    CInputProcessor * GetInputProcessor(void);
    DWORD GetHandle(void) const;
    LPBUFFER GetOutputBuffer(void);
    void BindAccountTable(TAccountTable *);
    TAccountTable & GetAccountTable(void);
    void BindCharacter(LPCHARACTER);
    LPCHARACTER GetCharacter(void);
    bool IsPhase(int) const;
    const sockaddr_in & GetAddr(void);
    void UDPGrant(const sockaddr_in &);
    const sockaddr_in & GetUDPAddr(void);
    void Log(const char *, ...);
    void StartHandshake(DWORD);
    void SendHandshake(DWORD, long);
    bool HandshakeProcess(DWORD, long, bool);
    bool IsHandshaking(void);
    DWORD GetHandshake(void) const;
    DWORD GetClientTime(void);
    void SendKeyAgreement(void);
    void SendKeyAgreementCompleted(void);
    bool FinishHandshake(size_t, const void *, size_t);
    bool IsCipherPrepared(void);
    BYTE GetEmpire(void);
    void SetRelay(const char *);
    bool DelayedDisconnect(int);
    void DisconnectOfSameLogin(void);
    void SetAdminMode(void);
    bool IsAdminMode(void);
    void SetPong(bool);
    bool IsPong(void);
    BYTE GetSequence(void);
    void SetNextSequence(void);
    void SendLoginSuccessPacket(void);
    void SetMatrixCode(const char *);
    const char * GetMatrixCode(void);
    void SetMatrixCardRowsAndColumns(unsigned long, unsigned long);
    unsigned long GetMatrixRows(void);
    unsigned long GetMatrixCols(void);
    bool CheckMatrixTryCount(void);
    void SetPanamaKey(DWORD);
    DWORD GetPanamaKey(void) const;
    void SetLoginKey(DWORD);
    void SetLoginKey(CLoginKey *);
    DWORD GetLoginKey(void);
    void AssembleCRCMagicCube(BYTE, BYTE);
    void SetBillingExpireSecond(DWORD);
    DWORD GetBillingExpireSecond(void);
    void SetClientVersion(const char *);
    const char * GetClientVersion(void);
  protected:
    void Initialize(void);
  public:
    void SetMatrixCardID(const char *);
    const char * GetMatrixCardID(void);
    void SetMatrixQuiz(const char *);
    const char * GetMatrixQuiz(void);
    void SetLogin(const std::string &);
    void SetLogin(const char *);
    const std::string & GetLogin(void);
    void SetOutTime(int);
    void SetOffTime(int);
    void SetPlayTime(int);
    void RawPacket(const void *, int);
    void ChatPacket(BYTE, const char *, ...);
    void push_seq(BYTE, BYTE);
};
#endif // _GAME_DESC_HPP
