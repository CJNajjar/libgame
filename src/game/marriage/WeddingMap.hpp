#ifndef _GAME_MARRIAGE_WEDDINGMAP_HPP
#define _GAME_MARRIAGE_WEDDINGMAP_HPP
#include "../stdInclude.hpp"
namespace marriage{
class WeddingMap {
  private:
    DWORD m_dwMapIndex;
    LPEVENT m_pEndEvent;
    CHARACTER_SET m_set_pkChr;
    bool m_isDark;
    bool m_isSnow;
    bool m_isMusic;
    DWORD dwPID1;
    DWORD dwPID2;
    std::string m_stMusicFileName;

  public:
    WeddingMap(DWORD, DWORD, DWORD);
    ~WeddingMap();
    DWORD GetMapIndex(void);
    void WarpAll(void);
    void DestroyAll(void);
    void Notice(const char *);
    void SetEnded(void);
    void IncMember(LPCHARACTER);
    void DecMember(LPCHARACTER);
    bool IsMember(LPCHARACTER);
    void SetDark(bool);
    void SetSnow(bool);
    void SetMusic(bool, const char *);
    bool IsPlayingMusic(void);
    void SendLocalEvent(LPCHARACTER);
    void ShoutInMap(BYTE, const char *);
  private:
    const char * __BuildCommandPlayMusic(char *, size_t, BYTE, const char *);

    typedef CHARACTER_SET charset_t;
};
}
#endif // _GAME_MARRIAGE_WEDDINGMAP_HPP
