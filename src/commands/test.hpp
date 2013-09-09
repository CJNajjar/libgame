#ifndef __COMMAND_TEST_HPP
#define __COMMAND_TEST_HPP
#include "../libm2/Command.hpp"
using namespace libm2;
namespace command{
class Test: public ICommand{
    bool isReplaced();
    bool usableFor(LPCHARACTER);
    void use(LPCHARACTER,std::vector<std::string> args);
};
}
#endif // __COMMAND_TEST_HPP
