#include "fwDecl.hpp"

#ifndef _GAME_STDINCLUDE_HPP
#define _GAME_STDINCLUDE_HPP


// Typedefs
typedef int socket_t;
typedef uint8_t BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef uint64_t QWORD;

typedef struct seq_t {
    BYTE hdr;
    BYTE seq;
} seq_t;

typedef std::vector<seq_t,std::allocator<seq_t> > seq_vector_t;

#endif // _GAME_STDINCLUDE_HPP
