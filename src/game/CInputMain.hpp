#ifndef _GAME_CINPUTMAIN_HPP
#define _GAME_CINPUTMAIN_HPP
#include "CInputProcessor.hpp"
#include "CHARACTER.hpp"
class CInputMain : public CInputProcessor {
  public:
    virtual BYTE GetType(void);
  protected:
    virtual int Analyze(LPDESC, BYTE, const char *);
    void Attack(LPCHARACTER, BYTE, const char *);
    int Whisper(LPCHARACTER, const char *, size_t);
    int Chat(LPCHARACTER, const char *, size_t);
    void ItemUse(LPCHARACTER, const char *);
    void ItemDrop(LPCHARACTER, const char *);
    void ItemDrop2(LPCHARACTER, const char *);
    void ItemMove(LPCHARACTER, const char *);
    void ItemPickup(LPCHARACTER, const char *);
    void ItemToItem(LPCHARACTER, const char *);
    void QuickslotAdd(LPCHARACTER, const char *);
    void QuickslotDelete(LPCHARACTER, const char *);
    void QuickslotSwap(LPCHARACTER, const char *);
    int Shop(LPCHARACTER, const char *, size_t);
    void OnClick(LPCHARACTER, const char *);
    void Exchange(LPCHARACTER, const char *);
    void Position(LPCHARACTER, const char *);
    void Move(LPCHARACTER, const char *);
    int SyncPosition(LPCHARACTER, const char *, size_t);
    void FlyTarget(LPCHARACTER, const char *, BYTE);
    void UseSkill(LPCHARACTER, const char *);
    void ScriptAnswer(LPCHARACTER, const void *);
    void ScriptButton(LPCHARACTER, const void *);
    void ScriptSelectItem(LPCHARACTER, const void *);
    void QuestInputString(LPCHARACTER, const void *);
    void QuestConfirm(LPCHARACTER, const void *);
    void Target(LPCHARACTER, const char *);
    void Warp(LPCHARACTER, const char *);
    void SafeboxCheckin(LPCHARACTER, const char *);
    void SafeboxCheckout(LPCHARACTER, const char *, bool);
    void SafeboxItemMove(LPCHARACTER, const char *);
    int Messenger(LPCHARACTER, const char *, size_t);
    void PartyInvite(LPCHARACTER, const char *);
    void PartyInviteAnswer(LPCHARACTER, const char *);
    void PartyRemove(LPCHARACTER, const char *);
    void PartySetState(LPCHARACTER, const char *);
    void PartyUseSkill(LPCHARACTER, const char *);
    void PartyParameter(LPCHARACTER, const char *);
    int Guild(LPCHARACTER, const char *, size_t);
    void AnswerMakeGuild(LPCHARACTER, const char *);
    void Fishing(LPCHARACTER, const char *);
    void ItemGive(LPCHARACTER, const char *);
    void Hack(LPCHARACTER, const char *);
    int MyShop(LPCHARACTER, const char *, size_t);
    void Refine(LPCHARACTER, const char *);
    void Roulette(LPCHARACTER, const char *);
};

#endif // _GAME_CINPUTMAIN_HPP
