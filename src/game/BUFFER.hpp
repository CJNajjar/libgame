#ifndef _GAME_BUFFER_HPP
#define _GAME_BUFFER_HPP
typedef struct buffer {
    buffer *next;
    char *write_point;
    int write_point_pos;
    const char *read_point;
    int length;
    char *mem_data;
    int mem_size;
    long flag;
} BUFFER, * LPBUFFER;
#endif // _GAME_BUFFER_HPP
