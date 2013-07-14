#ifndef _GAME_CINPUTLOGIN_HPP
#define _GAME_CINPUTLOGIN_HPP
#include "CInputProcessor.hpp"
class CInputLogin : public CInputProcessor {
  public:
    virtual BYTE GetType(void);
  protected:
    virtual int Analyze(LPDESC, BYTE, const char *);
    void Login(LPDESC, const char *);
    void LoginByKey(LPDESC, const char *);
    void CharacterSelect(LPDESC, const char *);
    void CharacterCreate(LPDESC, const char *);
    void CharacterDelete(LPDESC, const char *);
    void Entergame(LPDESC, const char *);
    void Empire(LPDESC, const char *);
    void GuildMarkCRCList(LPDESC, const char *);
    void GuildMarkIDXList(LPDESC, const char *);
    void GuildMarkUpload(LPDESC, const char *);
    int GuildSymbolUpload(LPDESC, const char *, size_t);
    void GuildSymbolCRC(LPDESC, const char *);
    void ChangeName(LPDESC, const char *);
};


#endif // _GAME_CINPUTLOGIN_HPP
