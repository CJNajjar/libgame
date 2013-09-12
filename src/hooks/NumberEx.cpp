#include "NumberEx.hpp"
#include "../libm2/game/misc.hpp"
using namespace Hooks;
NumberEx::NumberEx():Hook::Hook(){}

int NumberEx::hook(int from, int to, const char *file, int line){


  int from2 = from;
  int to2 = to;

  if ( from > to )
  {
    to = from;
    from = to;
  }

  unsigned int div = to + 1 - from;
  if (div==0)
	return 0;

  return from + thecore_random() % div;
}
