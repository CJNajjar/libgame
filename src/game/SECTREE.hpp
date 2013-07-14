#ifndef _GAME_SECTREE_HPP
#define _GAME_SECTREE_HPP
#include "stdInclude.hpp"
#include "CEntity.hpp"
#include "CAttribute.hpp"
class SECTREE;
typedef SECTREE* LPSECTREE;

typedef struct sectree_coord {
    unsigned int x : 16;
    unsigned int y : 16;
} SECTREE_COORD;

union sectreeid {
    DWORD package;
    SECTREE_COORD coord;
} typedef SECTREEID;

typedef std::list<SECTREE*,std::allocator<SECTREE*> > LPSECTREE_LIST;

class SECTREE {
  private:
    SECTREEID m_id;
    ENTITY_SET m_set_entity;
    LPSECTREE_LIST m_neighbor_list;
    int m_iPCCount;
    bool isClone;
    CAttribute *m_pkAttribute;
  public:
    SECTREE();
    ~SECTREE();
    void Initialize(void);
    void Destroy(void);
    SECTREEID GetID(void);
    bool InsertEntity(LPENTITY);
    void RemoveEntity(LPENTITY);
    void SetRegenEvent(LPEVENT);
    bool Regen(void);
    void IncreasePC(void);
    void DecreasePC(void);
    void BindAttribute(CAttribute *);
    CAttribute * GetAttributePtr(void);
    DWORD GetAttribute(long, long);
    bool IsAttr(long, long, DWORD);
    void CloneAttribute(LPSECTREE);
    int GetEventAttribute(long, long);
    void SetAttribute(DWORD, DWORD, DWORD);
    void RemoveAttribute(DWORD, DWORD, DWORD);
  private:
    //void for_each_entity<FCollectEntity>(FCollectEntity &);
};




#endif // _GAME_SECTREE_HPP
