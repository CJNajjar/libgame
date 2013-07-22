// Forward declarations
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include <string>
#include <vector>
//#include <unordered_map>
#include <map>
#include <list>
#include <queue>
#include <unordered_set>
#include <set>
#include <stdexcept>
#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstdarg>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <pthread.h>
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>
#include <boost/functional/hash.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/concept.hpp>
#include <boost/algorithm/string/constants.hpp>
#include <boost/algorithm/string/erase.hpp>
#include <boost/algorithm/string/find.hpp>
#include <boost/algorithm/string/find_format.hpp>
#include <boost/algorithm/string/find_iterator.hpp>
#include <boost/foreach.hpp>
#include <boost/algorithm/string/finder.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/std_containers_traits.hpp>
#include <typeinfo>
#include "../utils/lua.hpp"
#include "../utils/mysql/mysql.h"
#include <boost/intrusive_ptr.hpp>
#include <tr1/unordered_set>


class ENTITY;
typedef ENTITY* LPENTITY;
class CHARACTER;
typedef CHARACTER* LPCHARACTER;
class DESC;
typedef DESC* LPDESC;
class ITEM;
typedef ITEM* LPITEM;
class CParty;
typedef CParty* LPPARTY;
class CDungeon;
typedef CDungeon* LPDUNGEON;
typedef  std::tr1::unordered_set<CHARACTER*, std::tr1::hash<CHARACTER*>, std::equal_to<CHARACTER*>, std::allocator<CHARACTER*>> CHARACTER_SET;
