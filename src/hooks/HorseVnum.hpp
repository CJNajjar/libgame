#ifndef __HOOKS_CHARACTERGETHORSEVNUM_HPP
#define __HOOKS_CHARACTERGETHORSEVNUM_HPP
#include "../libm2/lib/hook.hpp"
#include "../libm2/addr.hpp"
#include "../libm2/game/CHARACTER.hpp"
using namespace libm2;
namespace Hooks{
class HorseVnum: public Hook<unsigned int(*)(CHARACTER*),(unsigned int)Addr::CHARACTER::GetMyHorseVnum,HorseVnum>{
struct TVnum{
    unsigned int normal;
    unsigned int guild;
    unsigned int guildmaster;
};
private:
    TVnum vnums[31];
public:
    HorseVnum();
    void set(short level, unsigned int vnum);
    void set(short level, unsigned int vnum, unsigned int vnum_guild);
    void set(short level, unsigned int vnum, unsigned int vnum_guild, unsigned int vnum_guildmaster);
    TVnum get(short level);
    static unsigned int hook(CHARACTER* self);
};
}
#endif // __HOOKS_CHARACTERGETHORSEVNUM_HPP
