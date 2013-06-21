#ifndef __COMMAND_HPP_ASD
#define __COMMAND_HPP_ASD
#include "../addr.hpp"
#include "../gameinfo.hpp"
namespace Command
{
typedef void (*tcommand)(GameFunc::CHARACTER*, char const*, int, int);
typedef void (*tinterpret_command)(GameFunc::LPCHARACTER, const char *, size_t);//} 0x80c2d00
extern std::map<std::string, my_command_info> myCommandMap;
typedef void (*command_ptr)(LPCHARACTER, const char *);
// first_cmd(char const* argument, char* first_arg, unsigned int first_arg_size, unsigned int* first_arg_len_result);
typedef void (*tdouble_dollar)(const char *, size_t, char *, size_t);
typedef const char * (*tfirst_cmd)(const char *, char *, size_t, size_t *);
extern tfirst_cmd first_cmd;
extern tdouble_dollar double_dollar;
}
#endif // __COMMAND_HPP
