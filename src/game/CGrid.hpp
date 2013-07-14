#ifndef _GAME_CGRID_HPP
#define _GAME_CGRID_HPP
#include "stdInclude.hpp"
class CGrid {
  protected:
    int m_iWidth;
    int m_iHeight;
    char *m_pGrid;
  public:
    CGrid(int, int);
    CGrid(CGrid *, int, int);
    ~CGrid();
    void Clear(void);
    int FindBlank(int, int);
    bool IsEmpty(int, int, int);
    bool Put(int, int, int);
    void Get(int, int, int);
    void Print(void);
    unsigned int GetSize(void);
};
#endif // _GAME_CGRID_HPP
