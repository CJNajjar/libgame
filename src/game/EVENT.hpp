#ifndef _GAME_EVENT_HPP
#define _GAME_EVENT_HPP
#include "stdInclude.hpp"

class event;
typedef event* LPEVENT;

typedef long (*TEVENTFUNC)(LPEVENT);

struct TQueueElement {
    LPEVENT pvData;
    int iKey;
    bool bCancel;
};

class event_info_data {
  public:
    event_info_data();
    ~event_info_data();
};

class event {
    TEVENTFUNC func;
    event_info_data *info;
    TQueueElement *q_el;
    char is_force_to_end;
    char is_processing;
    size_t ref_count;
  public:
    event();
    ~event();
} typedef EVENT;


#endif // _GAME_EVENT_HPP
