#include "gameinfo.hpp"

template<typename Map> typename Map::const_iterator
find_prefix(Map const& map, typename Map::key_type const& key)
{
    typename Map::const_iterator it = map.upper_bound(key);
    while (it != map.begin())
    {
        --it;
        if(key.substr(0, it->first.size()) == it->first)
            return it;
    }

    return map.end(); // map contains no prefix
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

TStrCommandMap::const_iterator FindCommand(const TStrCommandMap& map, const std::string& search_for) {
    TStrCommandMap::const_iterator i = map.lower_bound(search_for);
    if (i != map.end()) {
        const std::string& key = i->first;
        if (key.compare(0, search_for.size(), search_for) == 0) // Really a prefix?
            return i;
    }
    return map.end();
}
