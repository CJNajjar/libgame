#ifndef _GAME_CBUFFONATTRIBUTES_HPP
#define _GAME_CBUFFONATTRIBUTES_HPP
#include "stdInclude.hpp"
#include "CItem.hpp"
class CBuffOnAttributes {
  private:
    LPCHARACTER m_pBuffOwner;
    BYTE m_bPointType;
    BYTE m_bBuffValue;
    std::vector<unsigned char, std::allocator<unsigned char> > *m_p_vec_buff_wear_targets;
    std::map<unsigned char, int, std::less<unsigned char>, std::allocator<std::pair<unsigned char const, int> > > m_map_additional_attrs;
  public:
    CBuffOnAttributes(LPCHARACTER, BYTE,
        std::vector<unsigned char, std::allocator<unsigned char> > *);
    ~CBuffOnAttributes();
    void RemoveBuffFromItem(LPITEM);
    void AddBuffFromItem(LPITEM);
    void ChangeBuffValue(BYTE);
    void GiveAllAttributes(void);
    bool On(BYTE);
    void Off(void);
  private:
    void Initialize(void);
};

#endif // _GAME_CBUFFONATTRIBUTES_HPP
