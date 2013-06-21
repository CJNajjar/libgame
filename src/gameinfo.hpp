#ifndef __GAMEINFO_HPP
#define __GAMEINFO_HPP
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>
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
#include <boost/unordered/detail/unique.hpp>
#include <typeinfo>
#include "utils/lua.hpp"
#include "utils/mysql/mysql.h"
#include "addr.hpp"

typedef int socket_t;

typedef uint8_t BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef uint64_t QWORD;


template<typename Map> typename Map::const_iterator
find_prefix(Map const& map, typename Map::key_type const& key);

#pragma pack(push, 1)

std::vector<std::string> split(const std::string &s, char delim);
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

namespace GameFunc {
class CHARACTER;
}

typedef GameFunc::CHARACTER* LPCHARACTER;



struct my_command_info {
    void (*command_pointer)(LPCHARACTER, const char *);
    int gm_level;
};
typedef std::map<std::string, my_command_info> TStrCommandMap;
typedef std::pair<std::string, my_command_info> TStrCommandPair;

TStrCommandMap::const_iterator FindCommand(const TStrCommandMap& map, const std::string& search_for);





typedef struct player_item_attribute
{
    uint8_t bType;
    short int sValue;
} TPlayerItemAttribute;

typedef struct SItemPos {
    uint8_t inventType;
    uint16_t pos;
} TItemPos;

typedef struct new_command_item_move {
    uint8_t header;
    TItemPos pos;
    TItemPos pos_to;
    uint8_t count;
}  TPacketCGItemMoveNew;


typedef struct new_packet_item_set
{
    uint8_t header;
    TItemPos Pos;
    uint32_t vnum;
    uint8_t count;
    uint32_t flags;
    uint32_t antiFlags; // 8
    uint8_t highlight; // 17
    uint32_t alSockets[3]; // 18
    TPlayerItemAttribute aAttr[7]; // 30
} TItemSetPacketNew;

typedef struct packet_item_del_new
{
    BYTE header;
    TItemPos pos;
    BYTE padding[38] = {0};
} TPacketGCItemDelNew;

typedef struct command_item_drop2 {
    BYTE header;
    TItemPos pos;
    DWORD gold;
    BYTE count;
} TPacketCGItemDrop2New;

typedef struct command_item_use_to_item {
    BYTE header;
    TItemPos bPos;
    TItemPos bTargetPos;
} TPacketCGItemUseToItemNew;

typedef struct command_item_use {
    BYTE header;
    TItemPos pos;
} TPacketCGItemUseNew;

typedef struct command_item_drop {
    BYTE header;
    TItemPos pos;
    DWORD gold;
} TPacketCGItemDropNew;

typedef struct command_item_pickup {
    BYTE header;
    DWORD vid;
} TPacketCGItemPickupNew;

typedef struct packet_item_update {
    BYTE header;
    TItemPos pos;
    BYTE count;
    long alSockets[3];
    TPlayerItemAttribute aAttr[7];
} TPacketGCItemUpdateNew;
struct packet_shop_item {
    DWORD vnum;
    DWORD price;
    BYTE count;
    long alSockets[3];
    TPlayerItemAttribute aAttr[7];
    BYTE currency = 1;
};
struct packet_shop_start {
    DWORD owner_vid;
    packet_shop_item items[40];
};

struct packet_shop {
    BYTE header;
    WORD size;
    BYTE subheader;
};
#pragma pack(pop)

enum PacketHeader {
	HEADER_CG_HANDSHAKE = 255,
	HEADER_CG_PONG = 254,
	HEADER_CG_TIME_SYNC = 252,
    HEADER_CG_LOGIN = 1,
	HEADER_CG_ATTACK,
	HEADER_CG_CHAT,
	HEADER_CG_CHARACTER_CREATE,
    HEADER_CG_CHARACTER_DELETE,
	HEADER_CG_CHARACTER_SELECT,
	HEADER_CG_MOVE,
	HEADER_CG_SYNC_POSITION,
    HEADER_CG_ENTERGAME = 10,
	HEADER_CG_ITEM_USE,
	HEADER_CG_ITEM_DROP,
	HEADER_CG_ITEM_MOVE,
    HEADER_CG_ITEM_PICKUP = 15,
	HEADER_CG_QUICKSLOT_ADD,
	HEADER_CG_QUICKSLOT_DEL,
	HEADER_CG_QUICKSLOT_SWAP,
    HEADER_CG_WHISPER,
	HEADER_CG_ITEM_DROP2,
	HEADER_CG_ON_CLICK = 26,
	HEADER_CG_EXCHANGE,
    HEADER_CG_CHARACTER_POSITION,
	HEADER_CG_SCRIPT_ANSWER,
	HEADER_CG_QUEST_INPUT_STRING,
	HEADER_CG_QUEST_CONFIRM,
    HEADER_CG_SHOP = 50,
	HEADER_CG_FLY_TARGETING,
	HEADER_CG_USE_SKILL,
	HEADER_CG_ADD_FLY_TARGETING,
    HEADER_CG_SHOOT,
	HEADER_CG_MYSHOP,
	HEADER_CG_ITEM_USE_TO_ITEM = 60,
	HEADER_CG_TARGET,
	HEADER_CG_TEXT = 64,
    HEADER_CG_WARP,
	HEADER_CG_SCRIPT_BUTTON,
	HEADER_CG_MESSENGER,
	HEADER_CG_MALL_CHECKOUT = 69,
    HEADER_CG_SAFEBOX_CHECKIN,
	HEADER_CG_SAFEBOX_CHECKOUT,
	HEADER_CG_PARTY_INVITE,
	HEADER_CG_PARTY_INVITE_ANSWER,
    HEADER_CG_PARTY_REMOVE,
	HEADER_CG_PARTY_SET_STATE,
	HEADER_CG_PARTY_USE_SKILL,
	HEADER_CG_SAFEBOX_ITEM_MOVE,
    HEADER_CG_PARTY_PARAMETER,
	HEADER_CG_GUILD = 80,
	HEADER_CG_ANSWER_MAKE_GUILD,
	HEADER_CG_FISHING,
    HEADER_CG_ITEM_GIVE,
	HEADER_CG_EMPIRE = 90,
	HEADER_CG_REFINE = 96,
	HEADER_CG_MARK_LOGIN = 100,
    HEADER_CG_MARK_CRCLIST,
	HEADER_CG_MARK_UPLOAD,
	HEADER_CG_MARK_IDXLIST = 104,
	HEADER_CG_HACK,
    HEADER_CG_CHANGE_NAME,
	HEADER_CG_LOGIN2 = 109,
	HEADER_CG_DUNGEON,
	HEADER_CG_LOGIN3,
    HEADER_CG_GUILD_SYMBOL_UPLOAD,
	HEADER_CG_SYMBOL_CRC,
	HEADER_CG_SCRIPT_SELECT_ITEM,
    HEADER_CG_PASSPOD_ANSWER = 202,
	HEADER_CG_HS_ACK,
	HEADER_CG_CLIENT_VERSION = 253,
    HEADER_CG_CLIENT_VERSION2 = 241,
	HEADER_GC_TIME_SYNC = 252,
	HEADER_GC_PHASE,
	HEADER_GC_BINDUDP,
    HEADER_GC_HANDSHAKE,
	HEADER_GC_CHARACTER_ADD = 1,
	HEADER_GC_CHARACTER_DEL,
	HEADER_GC_MOVE,
	HEADER_GC_CHAT,
    HEADER_GC_SYNC_POSITION,
	HEADER_GC_LOGIN_SUCCESS,
	HEADER_GC_LOGIN_SUCCESS_NEWSLOT = 32,
    HEADER_GC_LOGIN_FAILURE = 7,
	HEADER_GC_CHARACTER_CREATE_SUCCESS,
	HEADER_GC_CHARACTER_CREATE_FAILURE,
    HEADER_GC_CHARACTER_DELETE_SUCCESS,
	HEADER_GC_CHARACTER_DELETE_WRONG_SOCIAL_ID,
	HEADER_GC_ATTACK,
    HEADER_GC_STUN,
	HEADER_GC_DEAD,
	HEADER_GC_MAIN_CHARACTER_OLD,
	HEADER_GC_CHARACTER_POINTS,
    HEADER_GC_CHARACTER_POINT_CHANGE,
	HEADER_GC_CHANGE_SPEED,
	HEADER_GC_CHARACTER_UPDATE,
    HEADER_GC_CHARACTER_UPDATE_NEW = 24,
	HEADER_GC_ITEM_DEL = 20,
	HEADER_GC_ITEM_SET,
	HEADER_GC_ITEM_USE,
    HEADER_GC_ITEM_DROP,
	HEADER_GC_ITEM_UPDATE = 25,
	HEADER_GC_ITEM_GROUND_ADD,
	HEADER_GC_ITEM_GROUND_DEL,
    HEADER_GC_QUICKSLOT_ADD,
	HEADER_GC_QUICKSLOT_DEL,
	HEADER_GC_QUICKSLOT_SWAP,
	HEADER_GC_ITEM_OWNERSHIP,
    HEADER_GC_WHISPER = 34,
	HEADER_GC_MOTION = 36,
	HEADER_GC_PARTS,
	HEADER_GC_SHOP,
	HEADER_GC_SHOP_SIGN,
    HEADER_GC_DUEL_START,
	HEADER_GC_PVP,
	HEADER_GC_EXCHANGE,
	HEADER_GC_CHARACTER_POSITION,
	HEADER_GC_PING,
    HEADER_GC_SCRIPT,
	HEADER_GC_QUEST_CONFIRM,
	HEADER_GC_MOUNT = 61,
	HEADER_GC_OWNERSHIP,
	HEADER_GC_TARGET,
    HEADER_GC_WARP = 65,
	HEADER_GC_ADD_FLY_TARGETING = 69,
	HEADER_GC_CREATE_FLY,
	HEADER_GC_FLY_TARGETING,
    HEADER_GC_SKILL_LEVEL_OLD,
	HEADER_GC_SKILL_LEVEL = 76,
	HEADER_GC_MESSENGER = 74,
	HEADER_GC_GUILD,
    HEADER_GC_PARTY_INVITE = 77,
	HEADER_GC_PARTY_ADD,
	HEADER_GC_PARTY_UPDATE,
	HEADER_GC_PARTY_REMOVE,
    HEADER_GC_QUEST_INFO,
	HEADER_GC_REQUEST_MAKE_GUILD,
	HEADER_GC_PARTY_PARAMETER,
	HEADER_GC_SAFEBOX_SET = 85,
    HEADER_GC_SAFEBOX_DEL,
	HEADER_GC_SAFEBOX_WRONG_PASSWORD,
	HEADER_GC_SAFEBOX_SIZE,
	HEADER_GC_FISHING,
    HEADER_GC_EMPIRE,
	HEADER_GC_PARTY_LINK,
	HEADER_GC_PARTY_UNLINK,
	HEADER_GC_REFINE_INFORMATION_OLD = 95,
    HEADER_GC_VIEW_EQUIP = 99,
	HEADER_GC_MARK_BLOCK,
	HEADER_GC_MARK_IDXLIST = 102,
	HEADER_GC_TIME = 106,
    HEADER_GC_CHANGE_NAME,
	HEADER_GC_DUNGEON = 110,
	HEADER_GC_WALK_MODE,
	HEADER_GC_SKILL_GROUP,
    HEADER_GC_MAIN_CHARACTER,
	HEADER_GC_SEPCIAL_EFFECT,
	HEADER_GC_NPC_POSITION,
	HEADER_GC_MATRIX_CARD,
    HEADER_GC_LOGIN_KEY = 118,
	HEADER_GC_REFINE_INFORMATION,
	HEADER_GC_CHANNEL = 121,
    HEADER_GC_TARGET_UPDATE = 123,
	HEADER_GC_TARGET_DELETE,
	HEADER_GC_TARGET_CREATE,
	HEADER_GC_AFFECT_ADD,
    HEADER_GC_AFFECT_REMOVE,
	HEADER_GC_MALL_OPEN = 122,
	HEADER_GC_MALL_SET = 128,
	HEADER_GC_MALL_DEL,
    HEADER_GC_LAND_LIST,
	HEADER_GC_LOVER_INFO,
	HEADER_GC_LOVE_POINT_UPDATE,
	HEADER_GC_SYMBOL_DATA,
    HEADER_GC_DIG_MOTION,
	HEADER_GC_DAMAGE_INFO,
	HEADER_GC_CHAR_ADDITIONAL_INFO,
	HEADER_GC_MAIN_CHARACTER3_BGM,
    HEADER_GC_MAIN_CHARACTER4_BGM_VOL,
	HEADER_GC_AUTH_SUCCESS = 150,
	HEADER_GC_PANAMA_PACK,
    HEADER_GC_ROULETTE = 200,
	HEADER_GC_REQUEST_PASSPOD = 202,
	HEADER_GC_REQUEST_PASSPOD_FAILED,
    HEADER_GC_HS_REQUEST,
	HEADER_GG_LOGIN = 1,
	HEADER_GG_LOGOUT,
	HEADER_GG_RELAY,
	HEADER_GG_NOTICE,
    HEADER_GG_SHUTDOWN,
	HEADER_GG_GUILD,
	HEADER_GG_DISCONNECT,
	HEADER_GG_SHOUT,
	HEADER_GG_SETUP,
    HEADER_GG_MESSENGER_ADD,
	HEADER_GG_MESSENGER_REMOVE,
	HEADER_GG_FIND_POSITION,
	HEADER_GG_WARP_CHARACTER,
    HEADER_GG_MESSENGER_MOBILE,
	HEADER_GG_GUILD_WAR_ZONE_MAP_INDEX,
	HEADER_GG_TRANSFER,
    HEADER_GG_XMAS_WARP_SANTA,
	HEADER_GG_XMAS_WARP_SANTA_REPLY,
	HEADER_GG_RELOAD_CRC_LIST,
	HEADER_GG_LOGIN_PING,
    HEADER_GG_CHECK_CLIENT_VERSION,
	HEADER_GG_BLOCK_CHAT,
	HEADER_GG_BLOCK_EXCEPTION = 24,
	HEADER_GG_SIEGE,
    HEADER_GG_MONARCH_NOTICE,
	HEADER_GG_MONARCH_TRANSFER,
	HEADER_GG_PCBANG_UPDATE
};


enum EPacketGuildSubHeadersGC {GUILD_SUBHEADER_GC_LOGIN, GUILD_SUBHEADER_GC_LOGOUT, GUILD_SUBHEADER_GC_LIST,
    GUILD_SUBHEADER_GC_GRADE, GUILD_SUBHEADER_GC_ADD, GUILD_SUBHEADER_GC_REMOVE, GUILD_SUBHEADER_GC_GRADE_NAME,
    GUILD_SUBHEADER_GC_GRADE_AUTH, GUILD_SUBHEADER_GC_INFO, GUILD_SUBHEADER_GC_COMMENTS,
    GUILD_SUBHEADER_GC_CHANGE_EXP, GUILD_SUBHEADER_GC_CHANGE_MEMBER_GRADE, GUILD_SUBHEADER_GC_SKILL_INFO,
    GUILD_SUBHEADER_GC_CHANGE_MEMBER_GENERAL, GUILD_SUBHEADER_GC_GUILD_INVITE, GUILD_SUBHEADER_GC_WAR,
    GUILD_SUBHEADER_GC_GUILD_NAME, GUILD_SUBHEADER_GC_GUILD_WAR_LIST, GUILD_SUBHEADER_GC_GUILD_WAR_END_LIST,
    GUILD_SUBHEADER_GC_WAR_SCORE, GUILD_SUBHEADER_GC_MONEY_CHANGE};

/*EPacketTradeSubHeaders
EPacketShopSubHeaders
$_123 // EPacketMessengerSubHeaderCG
$_124 // EPacketMessengerSubHeaderGC
$_128 // EPacketFishingSubHeadersGC
$_116 // EPacketShopSubHeadersCG
$_117 // EPacketExchangeSubHeadersCG
GUILD_SUBHEADER_CG
*/
#include <iterator>
#include <type_traits>

// This works similar to ostream_iterator, but doesn't print a delimiter after the final item
template<typename T, typename TChar = char, typename TCharTraits = std::char_traits<TChar> >
class pretty_ostream_iterator : public std::iterator<std::output_iterator_tag, void, void, void, void>
{
public:
    typedef TChar char_type;
    typedef TCharTraits traits_type;
    typedef std::basic_ostream<TChar, TCharTraits> ostream_type;

    pretty_ostream_iterator(ostream_type &stream, const char_type *delim = NULL)
        : _stream(&stream), _delim(delim), _insertDelim(false)
    {
    }

    pretty_ostream_iterator<T, TChar, TCharTraits>& operator=(const T &value)
    {
        if( _delim != NULL )
        {
            // Don't insert a delimiter if this is the first time the function is called
            if( _insertDelim )
                (*_stream) << _delim;
            else
                _insertDelim = true;
        }
        (*_stream) << value;
        return *this;
    }

    pretty_ostream_iterator<T, TChar, TCharTraits>& operator*()
    {
        return *this;
    }

    pretty_ostream_iterator<T, TChar, TCharTraits>& operator++()
    {
        return *this;
    }

    pretty_ostream_iterator<T, TChar, TCharTraits>& operator++(int)
    {
        return *this;
    }
private:
    ostream_type *_stream;
    const char_type *_delim;
    bool _insertDelim;
};

#if _MSC_VER >= 1400

// Declare pretty_ostream_iterator as checked
template<typename T, typename TChar, typename TCharTraits>
struct std::_Is_checked_helper<pretty_ostream_iterator<T, TChar, TCharTraits> > : public std::tr1::true_type
{
};

#endif // _MSC_VER >= 1400

namespace std
{
    // Pre-declarations of container types so we don't actually have to include the relevant headers if not needed, speeding up compilation time.
    // These aren't necessary if you do actually include the headers.
    template<typename T, typename TAllocator> class vector;
    template<typename T, typename TAllocator> class list;
    template<typename T, typename TTraits, typename TAllocator> class set;
    template<typename TKey, typename TValue, typename TTraits, typename TAllocator> class map;
}

// Basic is_container template; specialize to derive from std::true_type for all desired container types
template<typename T> struct is_container : public std::false_type { };

// Mark vector as a container
template<typename T, typename TAllocator> struct is_container<std::vector<T, TAllocator> > : public std::true_type { };

// Mark list as a container
template<typename T, typename TAllocator> struct is_container<std::list<T, TAllocator> > : public std::true_type { };

// Mark set as a container
template<typename T, typename TTraits, typename TAllocator> struct is_container<std::set<T, TTraits, TAllocator> > : public std::true_type { };

// Mark map as a container
template<typename TKey, typename TValue, typename TTraits, typename TAllocator> struct is_container<std::map<TKey, TValue, TTraits, TAllocator> > : public std::true_type { };

// Holds the delimiter values for a specific character type
template<typename TChar>
struct delimiters_values
{
    typedef TChar char_type;
    const TChar *prefix;
    const TChar *delimiter;
    const TChar *postfix;
};

// Defines the delimiter values for a specific container and character type
template<typename T, typename TChar>
struct delimiters
{
    static const delimiters_values<TChar> values;
};

// Default delimiters
template<typename T> struct delimiters<T, char> { static const delimiters_values<char> values; };
template<typename T> const delimiters_values<char> delimiters<T, char>::values = { "{ ", ", ", " }" };
template<typename T> struct delimiters<T, wchar_t> { static const delimiters_values<wchar_t> values; };
template<typename T> const delimiters_values<wchar_t> delimiters<T, wchar_t>::values = { L"{ ", L", ", L" }" };

// Delimiters for set
template<typename T, typename TTraits, typename TAllocator> struct delimiters<std::set<T, TTraits, TAllocator>, char> { static const delimiters_values<char> values; };
template<typename T, typename TTraits, typename TAllocator> const delimiters_values<char> delimiters<std::set<T, TTraits, TAllocator>, char>::values = { "[ ", ", ", " ]" };
template<typename T, typename TTraits, typename TAllocator> struct delimiters<std::set<T, TTraits, TAllocator>, wchar_t> { static const delimiters_values<wchar_t> values; };
template<typename T, typename TTraits, typename TAllocator> const delimiters_values<wchar_t> delimiters<std::set<T, TTraits, TAllocator>, wchar_t>::values = { L"[ ", L", ", L" ]" };

// Delimiters for pair
template<typename T1, typename T2> struct delimiters<std::pair<T1, T2>, char> { static const delimiters_values<char> values; };
template<typename T1, typename T2> const delimiters_values<char> delimiters<std::pair<T1, T2>, char>::values = { "(", ", ", ")" };
template<typename T1, typename T2> struct delimiters<std::pair<T1, T2>, wchar_t> { static const delimiters_values<wchar_t> values; };
template<typename T1, typename T2> const delimiters_values<wchar_t> delimiters<std::pair<T1, T2>, wchar_t>::values = { L"(", L", ", L")" };

// Functor to print containers. You can use this directly if you want to specificy a non-default delimiters type.
template<typename T, typename TChar = char, typename TCharTraits = std::char_traits<TChar>, typename TDelimiters = delimiters<T, TChar> >
struct print_container_helper
{
    typedef TChar char_type;
    typedef TDelimiters delimiters_type;
    typedef std::basic_ostream<TChar, TCharTraits>& ostream_type;

    print_container_helper(const T &container)
        : _container(&container)
    {
    }

    void operator()(ostream_type &stream) const
    {
        if( delimiters_type::values.prefix != NULL )
            stream << delimiters_type::values.prefix;
        std::copy(_container->begin(), _container->end(), pretty_ostream_iterator<typename T::value_type, TChar, TCharTraits>(stream, delimiters_type::values.delimiter));
        if( delimiters_type::values.postfix != NULL )
            stream << delimiters_type::values.postfix;
    }
private:
    const T *_container;
};

// Prints a print_container_helper to the specified stream.
template<typename T, typename TChar, typename TCharTraits, typename TDelimiters>
std::basic_ostream<TChar, TCharTraits>& operator<<(std::basic_ostream<TChar, TCharTraits> &stream, const print_container_helper<T, TChar, TDelimiters> &helper)
{
    helper(stream);
    return stream;
}

// Prints a container to the stream using default delimiters
template<typename T, typename TChar, typename TCharTraits>
typename std::enable_if<is_container<T>::value, std::basic_ostream<TChar, TCharTraits>&>::type
    operator<<(std::basic_ostream<TChar, TCharTraits> &stream, const T &container)
{
    stream << print_container_helper<T, TChar, TCharTraits>(container);
    return stream;
}

// Prints a pair to the stream using delimiters from delimiters<std::pair<T1, T2>>.
template<typename T1, typename T2, typename TChar, typename TCharTraits>
std::basic_ostream<TChar, TCharTraits>& operator<<(std::basic_ostream<TChar, TCharTraits> &stream, const std::pair<T1, T2> &value)
{
    if( delimiters<std::pair<T1, T2>, TChar>::values.prefix != NULL )
        stream << delimiters<std::pair<T1, T2>, TChar>::values.prefix;

    stream << value.first;

    if( delimiters<std::pair<T1, T2>, TChar>::values.delimiter != NULL )
        stream << delimiters<std::pair<T1, T2>, TChar>::values.delimiter;

    stream << value.second;

    if( delimiters<std::pair<T1, T2>, TChar>::values.postfix != NULL )
        stream << delimiters<std::pair<T1, T2>, TChar>::values.postfix;
    return stream;
}


namespace GameFunc {
class DESC;
class CHARACTER;
class CItem;
class CExchange;
class CEntity;
class SECTREE;
class TAreaInfo;
struct seq_t;
class CGuild;
class CAffect;
class CDungeon;
struct event;
struct regen;
class CShop;
struct buffer;
struct kevent;

typedef std::set<CEntity*,std::less<CEntity*>,std::allocator<CEntity*> > ENTITY_SET;
typedef std::list<SECTREE*,std::allocator<SECTREE*> > LPSECTREE_LIST;
typedef long int (*TEVENTFUNC)(event*) ;
typedef std::vector<seq_t,std::allocator<seq_t> > seq_vector_t;
typedef std::list<CHARACTER*,std::allocator<CHARACTER*> > CHARACTER_LIST;
typedef std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >,TAreaInfo,std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >,std::allocator<std::pair<const std::basic_string<char, std::char_traits<char>, std::allocator<char> >, TAreaInfo> > > TAreaMap;
typedef std::set<CHARACTER*,std::less<CHARACTER*>,std::allocator<CHARACTER*> > CHARACTER_SET;

//pointers

typedef CHARACTER * LPCHARACTER;
typedef DESC * LPDESC;
typedef CEntity * LPENTITY;
typedef regen * LPREGEN;
typedef SECTREE * LPSECTREE;
typedef std::list<SECTREE*, std::allocator<SECTREE*> > LPSECTREE_LIST;
typedef CShop * LPSHOP;
typedef buffer * LPBUFFER;
typedef kevent * LPKEVENT;
typedef CItem * LPITEM;

class CAffect {
    DWORD dwType;
    BYTE bApplyOn;
    long lApplyValue;
    DWORD dwFlag;
    long lDuration;
    long lSPCost;
  public:
    static void * operator new(size_t);
    static void operator delete(void *);
};

struct tItemIDRange {
    DWORD dwMin;
    DWORD dwMax;
    DWORD dwUsableItemIDMin;
} typedef TItemIDRangeTable;

namespace marriage {

	class WeddingMap {


	  private:
		DWORD m_dwMapIndex;
		event* m_pEndEvent;
		std::set<CHARACTER*,std::less<CHARACTER*>,std::allocator<CHARACTER*> > m_set_pkChr;
		bool m_isDark;
		bool m_isSnow;
		bool m_isMusic;
		DWORD dwPID1;
		DWORD dwPID2;
		std::string m_stMusicFileName;

	  public:
		WeddingMap(DWORD, DWORD, DWORD);
		~WeddingMap();
		DWORD GetMapIndex();
		void WarpAll();
		void DestroyAll();
		void Notice(char const*);
		void SetEnded();
		void IncMember(CHARACTER*);
		void DecMember(CHARACTER*);
		bool IsMember(CHARACTER*);
		void SetDark(bool);
		void SetSnow(bool);
		void SetMusic(bool, char const*);
		bool IsPlayingMusic();
		void SendLocalEvent(CHARACTER*);
		void ShoutInMap(unsigned char, char const*);
	};
}


enum e_overtime { OT_NONE,
	OT_3HOUR,
	OT_5HOUR };

struct SGuildGrade {
    char grade_name[9];
    BYTE auth_flag;
} typedef TGuildGrade;


struct SGuildData {
    DWORD guild_id;
    DWORD master_pid;
    DWORD exp;
    BYTE level;
    char name[13];
    TGuildGrade grade_array[15];
    BYTE skill_point;
    BYTE abySkill[12];
    int power;
    int max_power;
    int ladder_point;
    int win;
    int draw;
    int loss;
    int gold;
} typedef TGuildData;

struct seq_t {
    BYTE hdr;
    BYTE seq;
};

struct pixel_position_s {
    int x;
    int y;
    int z;
} typedef PIXEL_POSITION;

struct sectree_coord {
    unsigned int x : 16;
    unsigned int y : 16;
} typedef SECTREE_COORD;


union sectreeid {
    DWORD package;
    SECTREE_COORD coord;
} typedef SECTREEID;


struct kevent {
    uintptr_t ident;
    short int filter;
    u_short flags;
    u_int fflags;
    intptr_t data;
    void *udata;
};

struct fdwatch {
    int kq;
    int nfiles;
    kevent* kqevents;
    int nkqevents;
    kevent* kqrevents;
    int *fd_event_idx;
    void **fd_data;
    int *fd_rw;
};


struct SPacketElement {
    int iSize;
    std::string stName;
    int iCalled;
    DWORD dwLoad;
    bool bSequencePacket;
} typedef TPacketElement;

struct buffer {
    buffer *next;
    char *write_point;
    int write_point_pos;
    const char *read_point;
    int length;
    char *mem_data;
    int mem_size;
    long int flag;
};

 struct SQueueElement {
    void *pvData;
    int iKey;
    bool bCancel;
} typedef TQueueElement;

struct event {
    TEVENTFUNC func;
    DWORD dwInfoID;
    void *info;
    TQueueElement *q_el;
    char is_force_to_end;
    char is_processing;
};

struct SSimplePlayer {
    DWORD dwID;
    char szName[25];
    BYTE byJob;
    BYTE byLevel;
    DWORD dwPlayMinutes;
    BYTE byST;
    BYTE byHT;
    BYTE byDX;
    BYTE byIQ;
    WORD wMainPart;
    BYTE bChangeName;
    WORD wHairPart;
    BYTE bDummy[4];
    long int x;
    long int y;
    long int lAddr;
    WORD wPort;
    BYTE skill_group;
} typedef TSimplePlayer;

struct THorseInfo {
    BYTE bLevel;
    BYTE bRiding;
    short int sStamina;
    short int sHealth;
    DWORD dwHorseHealthDropTime;
};

struct SAccountTable {
    DWORD id;
    char login[31];
    char passwd[17];
    char social_id[19];
    char status[9];
    BYTE bEmpire;
    TSimplePlayer players[4];
} typedef TAccountTable;

struct SMobSkillLevel {
    DWORD dwVnum;
    BYTE bLevel;
} typedef TMobSkillLevel;

struct SMobTable {
    DWORD dwVnum;
    char szName[25];
    char szLocaleName[25];
    BYTE bType;
    BYTE bRank;
    BYTE bBattleType;
    BYTE bLevel;
    BYTE bSize;
    DWORD dwGoldMin;
    DWORD dwGoldMax;
    DWORD dwExp;
    DWORD dwMaxHP;
    BYTE bRegenCycle;
    BYTE bRegenPercent;
    WORD wDef;
    DWORD dwAIFlag;
    DWORD dwRaceFlag;
    DWORD dwImmuneFlag;
    BYTE bStr;
    BYTE bDex;
    BYTE bCon;
    BYTE bInt;
    DWORD dwDamageRange[2];
    short int sAttackSpeed;
    short int sMovingSpeed;
    BYTE bAggresiveHPPct;
    WORD wAggressiveSight;
    WORD wAttackRange;
    char cEnchants[6];
    char cResists[11];
    DWORD dwResurrectionVnum;
    DWORD dwDropItemVnum;
    BYTE bMountCapacity;
    BYTE bOnClickType;
    BYTE bEmpire;
    char szFolder[65];
    float fDamMultiply;
    DWORD dwSummonVnum;
    DWORD dwDrainSP;
    DWORD dwMobColor;
    DWORD dwPolymorphItemVnum;
    TMobSkillLevel Skills[5];
    BYTE bBerserkPoint;
    BYTE bStoneSkinPoint;
    BYTE bGodSpeedPoint;
    BYTE bDeathBlowPoint;
    BYTE bRevivePoint;
} typedef TMobTable;

class SMobSplashAttackInfo {
  public:
    DWORD dwTiming;
    DWORD dwHitDistance;

    SMobSplashAttackInfo(DWORD, DWORD);
};

struct SPlayerItem {
    DWORD id;
    BYTE window;
    WORD pos;
    DWORD count;
    DWORD vnum;
    long alSockets[3];
    TPlayerItemAttribute aAttr[7];
    DWORD owner;
}typedef TPlayerItem;
typedef bool BOOL;
typedef int INT;

enum EDamageType {DAMAGE_TYPE_NONE, DAMAGE_TYPE_NORMAL, DAMAGE_TYPE_NORMAL_RANGE, DAMAGE_TYPE_MELEE,
    DAMAGE_TYPE_RANGE, DAMAGE_TYPE_FIRE, DAMAGE_TYPE_ICE, DAMAGE_TYPE_ELEC, DAMAGE_TYPE_MAGIC,
    DAMAGE_TYPE_POISON, DAMAGE_TYPE_SPECIAL};

struct SShopItemTable {
    DWORD vnum;
    BYTE count;
    BYTE pos;
    DWORD price;
    BYTE display_pos;
}typedef TShopItemTable;

enum MONARCH_INDEX {MI_HEAL, MI_WARP, MI_TRANSFER,
    MI_TAX, MI_SUMMON, MI_MAX};

enum EAffectTypes {
    AFFECT_NONE, AFFECT_MOV_SPEED = 200, AFFECT_ATT_SPEED, AFFECT_ATT_GRADE,
    AFFECT_INVISIBILITY, AFFECT_STR, AFFECT_DEX, AFFECT_CON, AFFECT_INT, AFFECT_FISH_MIND_PILL, AFFECT_POISON,
    AFFECT_STUN, AFFECT_SLOW, AFFECT_DUNGEON_READY, AFFECT_DUNGEON_UNIQUE, AFFECT_BUILDING,
    AFFECT_REVIVE_INVISIBLE, AFFECT_FIRE, AFFECT_CAST_SPEED, AFFECT_HP_RECOVER_CONTINUE,
    AFFECT_SP_RECOVER_CONTINUE, AFFECT_POLYMORPH, AFFECT_MOUNT, AFFECT_WAR_FLAG, AFFECT_BLOCK_CHAT,
    AFFECT_CHINA_FIREWORK, AFFECT_BOW_DISTANCE, AFFECT_DEF_GRADE, AFFECT_PREMIUM_START = 500,
    AFFECT_EXP_BONUS = 500, AFFECT_ITEM_BONUS, AFFECT_SAFEBOX, AFFECT_AUTOLOOT, AFFECT_FISH_MIND,
    AFFECT_MARRIAGE_FAST, AFFECT_GOLD_BONUS, AFFECT_PREMIUM_END = 509, AFFECT_MALL, AFFECT_NO_DEATH_PENALTY,
    AFFECT_SKILL_BOOK_BONUS, AFFECT_SKILL_NO_BOOK_DELAY, AFFECT_HAIR, AFFECT_COLLECT, AFFECT_EXP_BONUS_EURO_FREE,
    AFFECT_EXP_BONUS_EURO_FREE_UNDER_15, AFFECT_UNIQUE_ABILITY, AFFECT_CUBE_1, AFFECT_CUBE_2, AFFECT_CUBE_3,
    AFFECT_CUBE_4, AFFECT_CUBE_5, AFFECT_CUBE_6, AFFECT_CUBE_7, AFFECT_CUBE_8, AFFECT_CUBE_9, AFFECT_CUBE_10,
    AFFECT_CUBE_11, AFFECT_CUBE_12, AFFECT_BLEND, AFFECT_HORSE_NAME, AFFECT_MOUNT_BONUS, AFFECT_AUTO_HP_RECOVERY,
    AFFECT_AUTO_SP_RECOVERY, AFFECT_QUEST_START_IDX = 1000
};

 struct SPacketMyshopPricelistHeader {
    DWORD dwOwnerID;
    BYTE byCount;
} typedef TPacketMyshopPricelistHeader;

 struct SMobSkillInfo {
    DWORD dwSkillVnum;
    BYTE bSkillLevel;
    std::vector<SMobSplashAttackInfo,std::allocator<SMobSplashAttackInfo> > vecSplashAttack;
} typedef TMobSkillInfo;

struct packet_item_use {
    BYTE header;
    BYTE pos;
    DWORD ch_vid;
    DWORD victim_vid;
    DWORD vnum;
};

struct character_point {
    long int points[255];
    BYTE job;
    BYTE voice;
    BYTE level;
    DWORD exp;
    long int gold;
    int hp;
    int sp;
    int iRandomHP;
    int iRandomSP;
    int stamina;
    BYTE skill_group;
} typedef CHARACTER_POINT;

struct character_point_instant {
    long int points[255];
    float fRot;
    int iMaxHP;
    int iMaxSP;
    long int position;
    long int instant_flag;
    DWORD dwAIFlag;
    DWORD dwImmuneFlag;
    DWORD dwLastShoutPulse;
    WORD parts[4];
    CItem* pItems[109];
    BYTE bItemGrid[109];
    CItem* pCubeItems[15];
    CHARACTER* pCubeNpc;
    CHARACTER* battle_victim;
    BYTE gm_level;
    BYTE bBasePart;
    int iMaxStamina;
    BYTE bBlockMode;
} typedef CHARACTER_POINT_INSTANT;

struct SQuickslot {

    BYTE type;
    BYTE pos;
} typedef TQuickSlot;

struct SWarMapInfo {
    BYTE bType;
    long int lMapIndex;
    PIXEL_POSITION posStart[3];
} typedef TWarMapInfo;

struct regen {
    regen* prev;
    regen* next;
    long int lMapIndex;
    int type;
    int sx;
    int sy;
    int ex;
    int ey;
    BYTE z_section;
    BYTE direction;
    DWORD time;
    int max_count;
    int count;
    int vnum;
    bool is_aggressive;
    event* event_lol;
};

struct TGuildWarInfo {
    long lMapIndex;
    int iWarPrice;
    int iWinnerPotionRewardPctToWinner;
    int iLoserPotionRewardPctToWinner;
    int iInitialScore;
    int iEndScore;

};

struct _SQLResult {
    MYSQL_RES *pSQLResult;
    uint32_t uiNumRows;
    uint32_t uiAffectedRows;
    uint32_t uiInsertID;
  public:
    _SQLResult(void);
    ~_SQLResult();
};

typedef _SQLResult SQLResult;

class _SQLMsg {
    public:
    MYSQL *m_pkSQL;
    int iID;
    boost::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > stQuery;
    std::vector<_SQLResult*, std::allocator<_SQLResult*> > vec_pkResult;
    unsigned int uiResultPos;
    void *pvUserData;
    bool bReturn;
    unsigned int uiSQLErrno;
  public:
    _SQLMsg(void);
    ~_SQLMsg();
    void Store(void);
    SQLResult * Get(void);
    bool Next(void);
};

typedef _SQLMsg SQLMsg;


class CAsyncSQL {
  public:
    MYSQL m_hDB;
    const char* m_stHost;
    const char* m_stUser;
    const char* m_stPassword;
    const char* m_stDB;
    const char* m_stLocale;
    int m_iMsgCount;
    int m_aiPipe[2];
    std::queue<_SQLMsg*, std::deque<_SQLMsg*, std::allocator<_SQLMsg*> > > m_queue_query;
    std::queue<_SQLMsg*, std::deque<_SQLMsg*, std::allocator<_SQLMsg*> > > m_queue_query_copy;
    std::queue<_SQLMsg*, std::deque<_SQLMsg*, std::allocator<_SQLMsg*> > > m_queue_result;
    bool m_bEnd;
    pthread_t m_hThread;
    pthread_mutex_t *m_mtxQuery;
    pthread_mutex_t *m_mtxResult;
    int* m_sem;
    int m_iQueryFinished;
    unsigned long m_ulThreadID;
    bool m_bConnected;
    int m_iCopiedQuery;

  public:
    CAsyncSQL(void);
    ~CAsyncSQL();
};



template <class T>
class singleton
{
  public:
    int * _vptr$singleton;
    static T * ms_singelton;
    singleton(void);
    ~singleton();
};

struct CLoginData {
  private:
    DWORD m_dwKey;
    DWORD m_adwClientKey[4];
    BYTE m_bBillType;
    DWORD m_dwBillID;
    DWORD m_dwConnectedPeerHandle;
    DWORD m_dwLogonTime;
    long m_lRemainSecs;
    char m_szIP[16];
    bool m_bBilling;
    bool m_bDeleted;
    const char* m_stLogin;
    int m_aiPremiumTimes[9];

  public:
    CLoginData(void);
};

struct SUseTime {
    DWORD dwLoginKey;
    char szLogin[31];
    BYTE bBillType;
    DWORD dwUseSec;
    char szIP[16];
};

class DBManager : public singleton<DBManager> {
  public:
    CAsyncSQL m_sql;
    CAsyncSQL m_sql_direct;
    bool m_bIsConnect;

    std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> > const, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > > m_map_dbstring;

    std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > m_vec_GreetMessage;

    std::map<unsigned int, CLoginData*, std::less<unsigned int>, std::allocator<std::pair<unsigned int const, CLoginData*> > > m_map_pkLoginData;

    std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, CLoginData*, std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> > const, CLoginData*> > > mapLDBilling;
    std::vector<SUseTime, std::allocator<SUseTime> > m_vec_kUseTime;

  public:
    DBManager(void);
    ~DBManager();
};

namespace quest {


class AStateScriptType {
    std::vector<char, std::allocator<char> > m_code;
  public:
    int GetSize(void) const;
    const char * GetCode(void) const;
};


class AArgScript {
    boost::hash<std::string> arg;
    std::vector<char, std::allocator<char> > when_condition;
    AStateScriptType script;
    unsigned int quest_index;
    int state_index;
  public:
    AArgScript(void);
};



class QuestState {
    lua_State *co;
    int ico;
    short args;
    BYTE suspend_state;
    int iIndex;
    bool bStart;
    int st;
    boost::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > _title;
    boost::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > _clock_name;
    boost::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > _counter_name;
    int _clock_value;
    int _counter_value;
    boost::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > _icon_file;
    std::vector<AArgScript*, std::allocator<AArgScript*> > chat_scripts;
  public:
    QuestState(void);
};


class RewardData {
	enum RewardType {REWARD_TYPE_NONE, REWARD_TYPE_EXP, REWARD_TYPE_ITEM};
  public:
    RewardType type;
    DWORD value1;
    int value2;
  public:
    RewardData(RewardType, DWORD, int);

};

class NPC {
  protected:
    unsigned int m_vnum;

    std::map<unsigned int, std::map<int, AStateScriptType, std::less<int>, std::allocator<std::pair<int const, AStateScriptType> > >, std::less<unsigned int>, std::allocator<std::pair<unsigned int const, std::map<int, AStateScriptType, std::less<int>, std::allocator<std::pair<int const, AStateScriptType> > > > > > m_mapOwnQuest[20];

    std::map<unsigned int, std::map<int, std::vector<AArgScript, std::allocator<AArgScript> >, std::less<int>, std::allocator<std::pair<int const, std::vector<AArgScript, std::allocator<AArgScript> > > > >, std::less<unsigned int>, std::allocator<std::pair<unsigned int const, std::map<int, std::vector<AArgScript, std::allocator<AArgScript> >, std::less<int>, std::allocator<std::pair<int const, std::vector<AArgScript, std::allocator<AArgScript> > > > > > > > m_mapOwnArgQuest[20];

  public:
    NPC(void);
    ~NPC();
};

class PC {

class TQuestStateChangeInfo {
    DWORD quest_idx;
    int prev_state;
    int next_state;
  public:
    TQuestStateChangeInfo(DWORD, int, int);
};

  private:
    std::vector<PC::TQuestStateChangeInfo, std::allocator<PC::TQuestStateChangeInfo> > m_QuestStateChange;
    std::vector<RewardData, std::allocator<RewardData> > m_vRewardData;
    bool m_bIsGivenReward;
    bool m_bShouldSendDone;
    DWORD m_dwID;
    std::map<unsigned int, QuestState, std::less<unsigned int>, std::allocator<std::pair<unsigned int const, QuestState> > > m_QuestInfo;
    QuestState *m_RunningQuestState;
    boost::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > m_stCurQuest;

    std::map<std::string, int> m_FlagMap;

    std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, int, std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> > > m_FlagSaveMap;

    std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, event*, std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> > const, event*> > > m_TimerMap;
    int m_iSendToClient;
    bool m_bLoaded;
    int m_iLastState;
    DWORD m_dwWaitConfirmFromPID;
    bool m_bConfirmWait;

  public:
    PC(void);
    ~PC();
};

class CQuestManager : public singleton<CQuestManager> {

	class stringhash {
	  public:
		size_t operator()(
		const boost::hash<std::string> &) const;
	};
  public:

    std::map<std::string, int> m_mapEventName;
  public:
    CDungeon *m_pSelectedDungeon;
    DWORD m_dwServerTimerArg;

    std::map<std::pair<std::string, unsigned int>, event*> m_mapServerTimer;
    int m_iRunningEventIndex;

    std::map<std::string, int> m_mapEventFlag;
    lua_State *L;
    bool m_bNoSend;
    std::set<unsigned int> m_registeredNPCVnum;
    std::map<unsigned int, NPC> m_mapNPC;

    std::map<std::string, unsigned int> m_mapNPCNameID;

    std::map<std::string, unsigned int> m_mapTimerID;
    QuestState *m_CurrentRunningState;
    std::map<unsigned int, PC> m_mapPC;
    LPCHARACTER m_pCurrentCharacter;
    LPCHARACTER m_pCurrentNPCCharacter;
    LPCHARACTER m_pCurrentPartyMember;
    PC *m_pCurrentPC;
    boost::hash<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > m_strScript;
    int m_iCurrentSkin;

    boost::unordered_map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, int, stringhash, std::equal_to<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> > > m_hmQuestName;

    boost::unordered_map<unsigned int, std::vector<char, std::allocator<char> >, boost::hash<unsigned int>, std::equal_to<unsigned int>, std::allocator<std::pair<unsigned int const, std::vector<char, std::allocator<char> > > > > m_hmQuestStartScript;

    std::map<unsigned int, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<unsigned int>, std::allocator<std::pair<unsigned int const, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > > m_mapQuestNameByIndex;
    bool m_bError;

  public:
    CQuestManager(void);
    ~CQuestManager();
};

}

struct SPlayerSkill {
    BYTE bMasterType;
    BYTE bLevel;
    time_t tNextRead;
} typedef TPlayerSkill;

class SGuildWar {
  public:
    DWORD war_start_time;
    DWORD score;
    DWORD state;
    BYTE type;
    DWORD map_index;

    SGuildWar(BYTE);
    bool IsWarBegin() const;
};

class SGuildMember {
  public:
    DWORD pid;
    BYTE grade;
    BYTE is_general;
    BYTE job;
    BYTE level;
    DWORD offer_exp;
    BYTE _dummy;
    std::string name;

    SGuildMember(CHARACTER*, BYTE, DWORD);
    SGuildMember(DWORD, BYTE, BYTE, BYTE, BYTE, DWORD, char *);
};

class TAreaInfo {
  public:
    int sx;
    int sy;
    int ex;
    int ey;
    int dir;

    TAreaInfo(int, int, int, int, int);
};

class TAffectFlag {
  public:
    DWORD bits[2];

    TAffectFlag(void);
    TAffectFlag(DWORD, DWORD);
    bool IsSet(int) const;
    void Set(int);
    void Reset(int);
    TAffectFlag & operator=(TAffectFlag const&);
};

class VID {
  public:
    DWORD m_id;
    DWORD m_crc;

  public:
    VID(void);
    VID(DWORD, DWORD);
    VID(const VID &);
    const VID & operator=(VID const&);
    bool operator==(VID const&) const;
    bool operator!=(VID const&) const;
    operator unsigned int() const;
    void Reset();
};

class CState {
public:
	virtual ~CState() {}
	virtual void ExecuteBeginState() = 0;
	virtual void ExecuteState()=0;
	virtual void ExecuteEndState()=0;
};

template<class T>
class CStateTemplate : public CState {
protected:
	typedef void (T::*PFNSTATE)(void);
	T*m_pInstance;
	PFNSTATE m_pfnBeginState;
	PFNSTATE m_pfnState;
	PFNSTATE m_pfnEndState;
public:
	CStateTemplate() : m_pInstance(0),m_pfnBeginState(0),m_pfnState(0),m_pfnEndState(0){}
	void Set(T*pInstance,PFNSTATE pfnBeginState,PFNSTATE pfnState,PFNSTATE pfnEndState)
	{
		m_pInstance = pInstance;
		m_pfnBeginState=pfnBeginState;
		m_pfnState=pfnState;
		m_pfnEndState=pfnEndState;
	}

	virtual void ExecuteBeginState()
	{
		(m_pInstance->*m_pfnBeginState)();
	}
	virtual void ExecuteState()
	{
		(m_pInstance->*m_pfnState)();
	}
	virtual void ExecuteEndState()
	{
		(m_pInstance->*m_pfnEndState)();

	}
};

class CFSM {
protected:
	CState *m_pCurrentState;
	CState *m_pNewState;
	CStateTemplate<CFSM> m_StateInitial;
public:
	CFSM();
	virtual ~CFSM(){}
	virtual void Update();
	bool IsState(CState &state);
	bool GotoState(CState &newState);
	virtual void BeginStateInitial(){}
	virtual void StateInitial(){}
	virtual void EndStateInitial(){}

};

class CLoginKey {
  public:
    DWORD m_dwKey;
    DWORD m_dwExpireTime;
    DESC* m_pkDesc;

    CLoginKey(DWORD, DESC*);
    void Expire();
    operator unsigned int() const;
};

struct SItemLimit {
    BYTE bType;
    long int lValue;
} typedef TItemLimit;

struct SItemApply {
    BYTE bType;
    long int lValue;
} typedef TItemApply;

struct SItemTable {
    DWORD dwVnum;
    char szName[25];
    char szLocaleName[25];
    BYTE bType;
    BYTE bSubType;
    BYTE bWeight;
    BYTE bSize;
    DWORD dwAntiFlags;
    DWORD dwFlags;
    DWORD dwWearFlags;
    DWORD dwImmuneFlag;
    DWORD dwGold;
    DWORD dwShopBuyPrice;
    TItemLimit aLimits[2];
    TItemApply aApplies[3];
    long int alValues[6];
    long int alSockets[3];
    DWORD dwRefinedVnum;
    WORD wRefineSet;
    BYTE bAlterToMagicItemPct;
    BYTE bSpecular;
    BYTE bGainSocketPct;
    short int sAddonType;
} typedef TItemTable;

struct TPlayerItemAttribute {
    BYTE bType;
    short int sValue;
};

struct SPlayerTable {
    DWORD id;
    char name[25];
    char ip[16];
    WORD job;
    BYTE voice;
    BYTE level;
    BYTE level_step;
    short st;
    short ht;
    short dx;
    short iq;
    DWORD exp;
    int gold;
    BYTE dir;
    int x;
    int y;
    int z;
    int lMapIndex;
    long lExitX;
    long lExitY;
    long lExitMapIndex;
    short hp;
    short sp;
    short sRandomHP;
    short sRandomSP;
    int playtime;
    short stat_point;
    short skill_point;
    short sub_skill_point;
    short horse_skill_point;
    TPlayerSkill skills[255];
    TQuickSlot quickslot[36];
    BYTE part_base;
    WORD parts[4];
    short stamina;
    BYTE skill_group;
    long lAlignment;
    char szMobile[33];
    short stat_reset_count;
    THorseInfo horse;
    DWORD logoff_interval;
    int aiPremiumTimes[9];
} typedef TPlayerTable;


struct packet_motion {
    BYTE header;
    DWORD vid;
    DWORD victim_vid;
    WORD motion;
};

struct TPacketAffectElement {
    DWORD dwType;
    BYTE bApplyOn;
    long lApplyValue;
    DWORD dwFlag;
    long lDuration;
    long lSPCost;
};

struct packet_party_update {
    BYTE header;
    DWORD pid;
    BYTE role;
    BYTE percent_hp;
    short affects[7];
} typedef TPacketGCPartyUpdate;


class CPacketInfo {
  protected:
    std::map<int,SPacketElement*,std::less<int>,std::allocator<std::pair<const int, SPacketElement*> > > m_pPacketMap;
    TPacketElement *m_pCurrentPacket;
    DWORD m_dwStartTime;

  public:
    CPacketInfo(void);
    ~CPacketInfo();
    void Set(int, int, char const*, bool);
    bool Get(int, int*, char const**);
    void Start();
    void End();
    void Log(char const*);
    bool IsSequence(int);
    void SetSequence(int, bool);
  private:
    TPacketElement * GetElement(int);
};

class CInputProcessor {
  protected:
    CPacketInfo *m_pPacketInfo;
    int m_iBufferLeft;

  public:
    CInputProcessor(void);
    ~CInputProcessor();
    virtual bool Process(DESC*, void const*, int, int&);
    virtual BYTE GetType();
    void BindPacketInfo(CPacketInfo*);
    void Pong(DESC*);
    void Handshake(DESC*, char const*);
    void Version(CHARACTER*, char const*);
  protected:
    virtual int Analyze(DESC*, unsigned char, char const*);
};


class DESC {
  protected:
    class CInputProcessor *m_pInputProcessor;
    fdwatch* m_lpFdw;
    socket_t m_sock;
    int m_iPhase;
    DWORD m_dwHandle;
    std::string m_stHost;
    WORD m_wPort;
    time_t m_LastTryToConnectTime;
    buffer * m_lpInputBuffer;
    int m_iMinInputBufferLen;
    DWORD m_dwHandshake;
    DWORD m_dwHandshakeSentTime;
    int m_iHandshakeRetry;
    DWORD m_dwClientTime;
    bool m_bHandshaking;
    buffer* m_lpBufferedOutputBuffer;
    buffer* m_lpOutputBuffer;
    event * m_pkPingEvent;
    CHARACTER * m_lpCharacter;
    TAccountTable m_accountTable;
    sockaddr_in m_SockAddr;
    sockaddr_in m_UDPSockAddr;
    FILE *m_pLogFile;
    std::string m_stRelayName;
    bool m_bEncrypted;
    std::string m_stP2PHost;
    WORD m_wP2PPort;
    BYTE m_bP2PChannel;
    bool m_bAdminMode;
    bool m_bPong;
    int m_iCurrentSequence;
    DWORD m_dwMatrixRows;
    DWORD m_dwMatrixCols;
    BYTE m_bMatrixTryCount;
    CLoginKey *m_pkLoginKey;
    DWORD m_dwLoginKey;
    DWORD m_dwPanamaKey;
    DWORD m_adwDecryptionKey[4];
    DWORD m_adwEncryptionKey[4];
    BYTE m_bCRCMagicCubeIdx;
    DWORD m_dwProcCRC;
    DWORD m_dwFileCRC;
    bool m_bHackCRCQuery;
    DWORD m_dwBillingExpireSecond;
    std::string m_stClientVersion;
    std::string m_stMatrixCode;
    std::string m_Login;
    int m_outtime;
    int m_playtime;
    int m_offtime;
  public:
    event * m_pkDisconnectEvent;
  protected:
    std::string m_stMatrixCardID;
    std::string m_stMatrixQuiz;
  public:
    seq_vector_t m_seq_vector;

    DESC(void);
    ~DESC();

};


class CAttribute {
  private:
    int dataType;
    DWORD defaultAttr;
    DWORD width;
    DWORD height;
    void *data;
    BYTE **bytePtr;
    WORD **wordPtr;
    DWORD **dwordPtr;

  public:
    CAttribute(DWORD, DWORD);
    CAttribute(DWORD *, DWORD, DWORD);
    ~CAttribute();
    void Alloc();
    int GetDataType();
    void * GetDataPtr();
    void Set(unsigned int, unsigned int, unsigned int);
    void Remove(unsigned int, unsigned int, unsigned int);
    DWORD Get(unsigned int, unsigned int);
    void CopyRow(unsigned int, unsigned int*);
  private:
    void Initialize(unsigned int, unsigned int);
};


class SECTREE {
  private:
    SECTREEID m_id;
    ENTITY_SET m_set_entity;
    LPSECTREE_LIST m_neighbor_list;
    int m_iPCCount;
    bool isClone;
    class CAttribute *m_pkAttribute;

  public:
    SECTREE(void);
    ~SECTREE();
    void Initialize();
    void Destroy();
    SECTREEID GetID();
    bool InsertEntity(CEntity*);
    void RemoveEntity(CEntity*);
    void SetRegenEvent(event*);
    bool Regen();
    void IncreasePC();
    void DecreasePC();
    void BindAttribute(CAttribute*);
    class CAttribute * GetAttributePtr();
    DWORD GetAttribute(long, long);
    bool IsAttr(long, long, unsigned int);
    void CloneAttribute(SECTREE*);
    int GetEventAttribute(long, long);
    void SetAttribute(unsigned int, unsigned int, unsigned int);
    void RemoveAttribute(unsigned int, unsigned int, unsigned int);
};

class CEntity {
  public:
    bool m_bIsObserver;
    bool m_bObserverModeChange;
    std::map<CEntity*,int,std::less<CEntity*>,std::allocator<std::pair<CEntity* const, int> > > m_map_view;
    long int m_lMapIndex;
  public:
    DESC* m_lpDesc;
    int m_iType;
    bool m_bIsDestroyed;
    PIXEL_POSITION m_pos;
    int m_iViewAge;
    SECTREE *m_pSectree;

  public:
    CEntity(void);
    ~CEntity();
    virtual void EncodeInsertPacket(CEntity*);
    virtual void EncodeRemovePacket(CEntity*);
  protected:
    void Initialize(int);
    void Destroy();
  public:
    void SetType(int);
    int GetType() const;
    bool IsType(int) const;
    void ViewCleanup();
    void ViewInsert(CEntity*, bool);
    void ViewRemove(CEntity*, bool);
    void ViewReencode();
    int GetViewAge() const;
    long int GetX() const;
    long int GetY() const;
    long int GetZ() const;
    const PIXEL_POSITION & GetXYZ() const;
    void SetXYZ(long, long, long);
    void SetXYZ(pixel_position_s const&);
    SECTREE * GetSectree() const;
    void SetSectree(SECTREE*);
    void UpdateSectree();
    void PacketAround(void const*, int, CEntity*);
    void PacketView(void const*, int, CEntity*);
    void BindDesc(DESC*);
    DESC* GetDesc() const;
    void SetMapIndex(long);
    long int GetMapIndex() const;
    void SetObserverMode(bool);
    bool IsObserverMode() const;
};


class CWarMap {

    class STeamData {
      public:
        DWORD dwID;
        CGuild *pkGuild;
        int iMemberCount;
        int iUsePotionPrice;
        int iScore;
        CHARACTER* pkChrFlag;
        CHARACTER* pkChrFlagBase;
        std::set<unsigned int,std::less<unsigned int>,std::allocator<unsigned int> > set_pidJoiner;

        void Initialize();
        int GetAccumulatedJoinerCount();
        int GetCurJointerCount();
        void AppendMember(CHARACTER*);
        void RemoveMember(CHARACTER*);
    };


  private:
    TWarMapInfo m_kMapInfo;
    bool m_bEnded;
    event* m_pkBeginEvent;
    event* m_pkTimeoutEvent;
    event* m_pkEndEvent;
    event* m_pkResetFlagEvent;
    CWarMap::STeamData m_TeamData[2];
    int m_iObserverCount;
    DWORD m_dwStartTime;
    BYTE m_bTimeout;
    TGuildWarInfo m_WarInfo;
    CHARACTER_SET m_set_pkChr;
};

class CParty {
    public:
    struct SMember {
        CHARACTER* pCharacter;
        bool bNear;
        BYTE bRole;
        BYTE bLevel;
        std::string strName;
    };

    DWORD * vptr$party;
    std::map<unsigned int,SMember> m_memberMap;
    DWORD m_dwLeaderPID;
    CHARACTER* m_pkChrLeader;
    event* m_eventUpdate;
    std::_Rb_tree_iterator<std::pair<const unsigned int, SMember> > m_itNextOwner;
  public:
    int m_iExpDistributionMode;
    CHARACTER* m_pkChrExpCentralize;
    DWORD m_dwPartyStartTime;
    DWORD m_dwPartyHealTime;
    bool m_bPartyHealReady;
    bool m_bCanUsePartyHeal;
    int m_anRoleCount[8];
    int m_anMaxRole[8];
    int m_iLongTimeExpBonus;
    int m_iLeadership;
    int m_iExpBonus;
    int m_iAttBonus;
    int m_iDefBonus;
    int m_iCountNearPartyMember;
    bool m_bPCParty;

    std::map<std::string,int> m_map_iFlag;
    class CDungeon *m_pkDungeon;

  public:
    CParty(void);
    ~CParty();

};

class CGuild {
  private:
    TGuildData m_data;
    int m_general_count;
    int m_iMemberCountBonus;
    std::map<unsigned int,SGuildMember,std::less<unsigned int>,std::allocator<std::pair<const unsigned int, SGuildMember> > > m_member;
    CHARACTER_SET m_memberOnline;
    std::set<unsigned int,std::less<unsigned int>,std::allocator<unsigned int> > m_memberP2POnline;
    std::map<unsigned int,SGuildWar,std::less<unsigned int>,std::allocator<std::pair<const unsigned int, SGuildWar> > > m_EnemyGuild;
    std::map<unsigned int,unsigned int,std::less<unsigned int>,std::allocator<std::pair<const unsigned int, unsigned int> > > m_mapGuildWarEndTime;
    bool abSkillUsable[12];
    std::map<unsigned int,event*,std::less<unsigned int>,std::allocator<std::pair<const unsigned int, event*> > > m_GuildInviteEventMap;
};

class CDungeon {
  public:
    DWORD m_lOrigMapIndex;
    DWORD m_lMapIndex;
    CHARACTER_SET m_set_pkCharacter;

    std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >,int,std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >,std::allocator<std::pair<const std::basic_string<char, std::char_traits<char>, std::allocator<char> >, int> > > m_map_Flag;
    std::map<CParty*,int,std::less<CParty*>,std::allocator<std::pair<CParty* const, int> > > m_map_pkParty;
    TAreaMap &m_map_Area;

    std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >,CHARACTER*,std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >,std::allocator<std::pair<const std::basic_string<char, std::char_traits<char>, std::allocator<char> >, CHARACTER*> > > m_map_UniqueMob;
    int m_iMobKill;
    int m_iStoneKill;
    bool m_bUsePotion;
    bool m_bUseRevive;
    int m_iMonsterCount;
    bool m_bExitAllAtEliminate;
    bool m_bWarpAtEliminate;
    int m_iWarpDelay;
    long int m_lWarpMapIndex;
    long int m_lWarpX;
    long int m_lWarpY;
    std::string m_stRegenFile;
    std::list<regen*,std::allocator<regen*> > m_regen;
    event* deadEvent;

  public:
    ~CDungeon();
    void Notice(char const*);
    void JoinParty(CParty*);
    void QuitParty(CParty*);
    void Join(CHARACTER*);
    void IncMember(CHARACTER*);
    void DecMember(CHARACTER*);
    void Purge();
    void KillAll();
    void IncMonster();
    void DecMonster();
    int CountMonster();
    int CountRealMonster();
    void IncPartyMember(CParty*, CHARACTER*);
    void DecPartyMember(CParty*, CHARACTER*);
    void IncKillCount(CHARACTER*, CHARACTER*);
    int GetKillMobCount();
    int GetKillStoneCount();
    bool IsUsePotion();
    bool IsUseRevive();
    void UsePotion(CHARACTER*);
    void UseRevive(CHARACTER*);
    long int GetMapIndex();
    void Spawn(unsigned int, char const*);
    CHARACTER* SpawnMob(unsigned int, int, int);
    CHARACTER* SpawnGroup(unsigned int, long, long, float, bool, int);
    void SpawnNameMob(unsigned int, int, int, char const*);
    void SpawnGotoMob(long, long, long, long);
    void SpawnRegen(char const*, bool);
    void AddRegen(regen*);
    void ClearRegen();
    void SetUnique(char const*, unsigned int);
    void SpawnMoveUnique(char const*, unsigned int, char const*, char const*);
    void SpawnMoveGroup(unsigned int, char const*, char const*, int);
    void SpawnUnique(char const*, unsigned int, char const*);
    void SpawnStoneDoor(char const*, char const*);
    void SpawnWoodenDoor(char const*, char const*);
    void KillUnique(std::string const&);
    void PurgeUnique(std::string const&);
    bool IsUniqueDead(std::string const&);
    float GetUniqueHpPerc(std::string const&);
    void DeadCharacter(CHARACTER*);
    void UniqueSetMaxHP(std::string const&, int);
    void UniqueSetHP(std::string const&, int);
    void UniqueSetDefGrade(std::string const&, int);
    void SendDestPositionToParty(CParty*, long, long);
    void CheckEliminated();
    void JumpAll(long, int, int);
    void ExitAll();
    void ExitAllToStartPosition();
    void JumpToEliminateLocation();
    void SetExitAllAtEliminate(long);
    void SetWarpAtEliminate(long, long, int, int, char const*);
    int GetFlag(std::string);
    void SetFlag(std::string, int);
    bool IsAllPCNearTo(int, int, int);
  protected:
    CDungeon(long int, long int);
    void Initialize();
    void CheckDestroy();

};

class CGrid {
  protected:
    int m_iWidth;
    int m_iHeight;
    char *m_pGrid;

  public:
    CGrid(int, int);
    CGrid(CGrid *, int, int);
    ~CGrid();
    void Clear();
    int FindBlank(int, int);
    bool IsEmpty(int, int, int);
    bool Put(int, int, int);
    void Get(int, int, int);
    void Print();
    unsigned int GetSize();
};


class CShop {

public:
    class shop_item {
        public:
            DWORD vnum;
            long int price;
            BYTE count;
            CItem* pkItem;
            int itemid;

			shop_item(void);
    };


  public:
    DWORD m_dwVnum;
    DWORD m_dwNPCVnum;
    class CGrid *m_pGrid;
    std::map<CHARACTER*,bool> m_map_guest;
    std::vector<CShop::shop_item> m_itemVector;
    CHARACTER* m_pkPC;


};

class CExchange {
  private:
    CExchange *m_pCompany;
    CHARACTER* m_pOwner;
    BYTE m_abItemPos[12];
    CItem* m_apItems[12];
    BYTE m_abItemDisplayPos[12];
    bool m_bAccept;
    long int m_lGold;
    CGrid *m_pGrid;

  public:
    CExchange(CHARACTER*);
    ~CExchange();
    bool Accept(bool);
    void Cancel();
    bool AddGold(long);
    bool AddItem(unsigned char, unsigned char);
    bool RemoveItem(unsigned char);
    CHARACTER* GetOwner();
    CExchange * GetCompany();
    bool GetAcceptStatus();
    void SetCompany(CExchange*);
  private:
    bool Done();
    bool Check(int*);
    bool CheckSpace();
};

class CItem : public CEntity {
  public:
    TItemTable *m_pProto;
    CHARACTER * m_pOwner;
    BYTE m_bWindow;
    DWORD m_dwID;
    bool m_bEquipped;
    DWORD m_dwVID;
    BYTE m_bCell;
    DWORD m_dwCount;
    long int m_lFlag;
    DWORD m_dwLastOwnerPID;
    bool m_bExchanging;
    long int m_alSockets[3];
    TPlayerItemAttribute m_aAttr[7];
    event * m_pkDestroyEvent;
    event * m_pkUniqueExpireEvent;
    event * m_pkAccessorySocketExpireEvent;
    event * m_pkOwnershipEvent;
    DWORD m_dwOwnershipPID;
    bool m_bSkipSave;
    bool m_isLocked;

  protected:
    virtual void EncodeInsertPacket(CEntity*);
    virtual void EncodeRemovePacket(CEntity*);
  public:
    CItem(void);
    ~CItem();
    bool CheckItemUseLevel(int);
    bool IsPCBangItem();
    long int FindApplyValue(unsigned char);
    bool IsStackable();
    void Initialize();
    void Destroy();
    void Save();
    void SetWindow(unsigned char);
    BYTE GetWindow();
    void SetID(unsigned int);
    DWORD GetID();
    void SetProto(SItemTable const*);
    const TItemTable * GetProto();
    int GetGold();
    int GetShopBuyPrice();
    const char * GetName();
    BYTE GetSize();
    void SetFlag(long);
    long int GetFlag();
    void AddFlag(long);
    void RemoveFlag(long);
    DWORD GetWearFlag();
    DWORD GetAntiFlag();
    DWORD GetImmuneFlag();
    void SetVID(unsigned int);
    DWORD GetVID();
    bool SetCount(unsigned int);
    DWORD GetCount();
    DWORD GetVnum();
    BYTE GetType();
    BYTE GetSubType();
    long int GetValue(unsigned int);
    void SetCell(CHARACTER*, unsigned char);
    BYTE GetCell();
    CItem * RemoveFromCharacter();
    bool AddToCharacter(CHARACTER*, unsigned char);
    CHARACTER * GetOwner();
    CItem * RemoveFromGround();
    bool AddToGround(long, pixel_position_s const&);
    int FindEquipCell(CHARACTER*);
    bool IsEquipped();
    bool EquipTo(CHARACTER*, unsigned char);
    bool CanUsedBy(CHARACTER*);
    bool DistanceValid(CHARACTER*);
    void UpdatePacket();
    void UsePacketEncode(CHARACTER*, CHARACTER*, packet_item_use*);
    void SetExchanging(bool);
    bool IsExchanging();
    bool IsTwohanded();
    bool IsPolymorphItem();
    void ModifyPoints(bool);
    bool CreateSocket(unsigned char, unsigned char);
    const long int * GetSockets();
    long int GetSocket(int);
    void SetSockets(long const*);
    void SetSocket(int, long);
    int GetSocketCount();
    bool AddSocket();
    const TPlayerItemAttribute * GetAttributes();
    const TPlayerItemAttribute & GetAttribute(int);
    BYTE GetAttributeType(int);
    short int GetAttributeValue(int);
    void SetAttributes(TPlayerItemAttribute const*);
    int FindAttribute(unsigned char);
    bool RemoveAttributeAt(int);
    bool RemoveAttributeType(unsigned char);
    bool HasAttr(unsigned char);
    bool HasRareAttr(unsigned char);
    void SetDestroyEvent(event*);
    void StartDestroyEvent(int);
    DWORD GetRefinedVnum();
    DWORD GetRefineFromVnum();
    int GetRefineLevel();
    void SetSkipSave(bool);
    bool GetSkipSave();
    bool IsOwnership(CHARACTER*);
    void SetOwnership(CHARACTER*, int);
    void SetOwnershipEvent(event*);
    DWORD GetLastOwnerPID();
    int GetAttributeSetIndex();
    void AlterToMagicItem();
    void AlterToSocketItem(int);
    WORD GetRefineSet();
    void StartUniqueExpireEvent();
    void SetUniqueExpireEvent(event*);
    int GetAttributeCount();
    void ClearAttribute();
    void ChangeAttribute(int const*);
    void AddAttribute();
    void AddAttribute(unsigned char, short);
    void ApplyAddon(int);
    int GetSpecialGroup();
    bool IsAccessoryForSocket();
    int GetAccessorySocketGrade();
    int GetAccessorySocketMaxGrade();
    int GetAccessorySocketDownGradeTime();
    void SetAccessorySocketGrade(int);
    void SetAccessorySocketMaxGrade(int);
    void SetAccessorySocketDownGradeTime(unsigned int);
    void AccessorySocketDegrade();
    void StartAccessorySocketExpireEvent();
    void SetAccessorySocketExpireEvent(event*);
    bool CanPutInto(CItem*);
    void CopyAttributeTo(CItem*);
    void CopySocketTo(CItem*);
    int GetRareAttrCount();
    bool AddRareAttribute();
    bool ChangeRareAttribute();
    void AttrLog();
    void Lock(bool);
    bool isLocked() const;
  private:
    void SetAttribute(int, unsigned char, short);
  protected:
    bool EquipEx(bool);
    bool Unequip();
    void AddAttr(unsigned char, unsigned char);
    void PutAttribute(int const*);
    void PutAttributeWithLevel(unsigned char);
    void StopUniqueExpireEvent();
    void StopAccessorySocketExpireEvent();
};

class TSkillUseInfo {
  public:
    int iHitCount;
    int iMaxHitCount;
    int iSplashCount;
    DWORD dwNextSkillUsableTime;
    int iRange;
    bool bUsed;
    DWORD dwVID;
    bool isGrandMaster;
    char TargetVIDMap[28];

    TSkillUseInfo(void);
    bool HitOnce(unsigned int);
    bool UseSkill(bool, unsigned int, unsigned int, int, int, int);
    DWORD GetMainTargetVID() const;
    void SetMainTargetVID(unsigned int);
    void ResetHitCount();
};

class CTrigger {
  public:
    BYTE bType;
    int (*pFunc)(CHARACTER*, CHARACTER*);

    CTrigger(void);
};

class CMob {
  public:
    TMobTable m_table;
    TMobSkillInfo m_mobSkillInfo[5];

    CMob(void);
    ~CMob();
    void AddSkillSplash(int, unsigned int, unsigned int);
};

class CMobInstance {
  public:
    PIXEL_POSITION m_posLastAttacked;
    DWORD m_dwLastAttackedTime;
    DWORD m_dwLastWarpTime;
    bool m_IsBerserk;
    bool m_IsGodSpeed;
    bool m_IsRevive;

    CMobInstance(void);
};

class CArena {
  private:
    DWORD m_dwPIDA;
    DWORD m_dwPIDB;
    event* m_pEvent;
    event* m_pTimeOutEvent;
    PIXEL_POSITION m_StartPointA;
    PIXEL_POSITION m_StartPointB;
    PIXEL_POSITION m_ObserverPoint;
    DWORD m_dwSetCount;
    DWORD m_dwSetPointOfA;
    DWORD m_dwSetPointOfB;
    std::map<unsigned int,CHARACTER*,std::less<unsigned int>,std::allocator<std::pair<const unsigned int, CHARACTER*> > > m_mapObserver;
    CArena(WORD, WORD, WORD, WORD);

};

class CHorseRider {
  private:
    THorseInfo m_Horse;
    event* m_eventStaminaRegen;
    event* m_eventStaminaConsume;

  public:
    CHorseRider(void);
    ~CHorseRider();

};


class CHARACTER : public CEntity, public CFSM, public CHorseRider {
enum PartyJoinErrCode {PERR_NONE, PERR_SERVER, PERR_DUNGEON,
    PERR_OBSERVER, PERR_LVBOUNDARY, PERR_LOWLEVEL, PERR_HILEVEL,
    PERR_ALREADYJOIN, PERR_PARTYISFULL, PERR_SEPARATOR,
    PERR_DIFFEMPIRE, PERR_MAX};

    struct SAttackLog {
        DWORD dwVID;
        DWORD dwTime;
    };

    class AttackedLog {
      public:
        DWORD dwPID;
        DWORD dwAttackedTime;

        AttackedLog(void);
    };
    class TBattleInfo {
      public:
        int iTotalDamage;
        int iAggro;

        TBattleInfo(int, int);
    };


  public:
    DWORD * vptr$singelton;
    CStateTemplate<CHARACTER> m_stateMove;
    CStateTemplate<CHARACTER> m_stateBattle;
    CStateTemplate<CHARACTER> m_stateIdle;
    DWORD m_dwStateDuration;
    DWORD m_dwPolymorphRace;
    bool m_bPolyMaintainStat;
    DWORD m_dwLoginPlayTime;
    DWORD m_dwPlayerID;
    VID m_vid;
    std::string m_stName;
    BYTE m_bCharType;
    CHARACTER_POINT m_points;
    CHARACTER_POINT_INSTANT m_pointsInstant;
    int m_iMoveCount;
    DWORD m_dwPlayStartTime;
    BYTE m_bAddChrState;
    bool m_bSkipSave;
    std::string m_stMobile;
    char m_szMobileAuth[5];
    BYTE m_bChatCounter;
    float m_fSyncTime;
    CHARACTER * m_pkChrSyncOwner;
    CHARACTER_LIST m_kLst_pkChrSyncOwned;
    PIXEL_POSITION m_posDest;
    PIXEL_POSITION m_posStart;
    PIXEL_POSITION m_posWarp;
    long int m_lWarpMapIndex;
    PIXEL_POSITION m_posExit;
    long int m_lExitMapIndex;
    DWORD m_dwMoveStartTime;
    DWORD m_dwMoveDuration;
    DWORD m_dwLastMoveTime;
    DWORD m_dwLastAttackTime;
    DWORD m_dwWalkStartTime;
    DWORD m_dwStopTime;
    bool m_bWalking;
    bool m_bNowWalking;
    bool m_bStaminaConsume;
    SQuickslot m_quickslot[36];
    TAffectFlag m_afAffectFlag;
    std::list<CAffect*> m_list_pkAffect;
    class CParty *m_pkParty;
    DWORD m_dwLastDeadTime;
    event* m_pkPartyRequestEvent;
    std::map<unsigned int,event*> m_PartyInviteEventMap;
    class CDungeon *m_pkDungeon;
    int m_iEventAttr;
    class CGuild *m_pGuild;
    DWORD m_dwUnderGuildWarInfoMessageTime;
    class CWarMap *m_pWarMap;
    bool m_bNoOpenedShop;
    bool m_bItemLoaded;
    int m_iRefineAdditionalCell;
    bool m_bUnderRefine;
    DWORD m_dwRefineNPCVID;
    CShop* m_pkShop;
    CShop* m_pkMyShop;
    std::string m_stShopSign;
    CHARACTER * m_pkChrShopOwner;
    class CExchange *m_pkExchange;
    BYTE m_bComboSequence;
    DWORD m_dwLastComboTime;
    int m_iValidComboInterval;
    BYTE m_bComboIndex;
    int m_iComboHackCount;
    DWORD m_dwSkipComboAttackByTime;
    DWORD m_dwFlyTargetID;
    std::vector<unsigned int> m_vec_dwFlyTargets;
    std::map<VID,CHARACTER::TBattleInfo> m_map_kDamage;
    DWORD m_dwKillerPID;
    int m_iAlignment;
    int m_iRealAlignment;
    int m_iKillerModePulse;
    BYTE m_bPKMode;
    DWORD m_dwLastVictimSetTime;
    int m_iMaxAggro;
    CHARACTER * m_pkChrStone;
    CHARACTER_SET m_set_pkChrSpawnedBy;
    DWORD m_dwDropMetinStone;
    BYTE m_bDropMetinStonePct;
  private:
    bool m_bDisableCooltime;
    DWORD m_dwLastSkillTime;
  protected:
    DWORD m_adwMobSkillCooltime[5];
  private:
    event* m_pkMuyeongEvent;
    int m_iChainLightingIndex;
    CHARACTER_SET m_setExceptChainLighting;
    DWORD m_dwAffectedEunhyungLevel;
  protected:
    TPlayerSkill *m_pSkillLevels;
    char m_SkillDamageBonus[28];
    std::map<int,TSkillUseInfo> m_SkillUseInfo;
  public:
    VID m_kVIDVictim;

  public:
    DWORD m_dwLastChangeAttackPositionTime;
    CTrigger m_triggerOnClick;
    CHARACTER * m_pkChrTarget;
    CHARACTER_SET m_set_pkChrTargetedBy;
    class CSafebox *m_pkSafebox;
    int m_iSafeboxSize;
    int m_iSafeboxLoadTime;
    bool m_bOpeningSafebox;
    class CSafebox *m_pkMall;
    int m_iMallLoadTime;
    PIXEL_POSITION m_posSafeboxOpen;
    CHARACTER * m_chHorse;
    CHARACTER * m_chRider;
    DWORD m_dwMountVnum;
    DWORD m_dwMountTime;
    BYTE m_bSendHorseLevel;
    BYTE m_bSendHorseHealthGrade;
    BYTE m_bSendHorseStaminaGrade;
  private:
    bool m_bDetailLog;
    bool m_bMonsterLog;
  protected:
    BYTE m_bEmpire;
    PIXEL_POSITION m_posRegen;
    float m_fRegenAngle;
    regen* m_pkRegen;
  private:
    DWORD m_dwQuestNPCVID;
    DWORD m_dwQuestByVnum;
    CItem* m_pQuestItem;
  protected:
    DWORD m_dwNextStatePulse;
  private:
    class marriage::WeddingMap *m_pWeddingMap;
    CHARACTER * m_pkChrMarried;
  public:
    event* m_pkDeadEvent;
    event* m_pkStunEvent;
    event* m_pkSaveEvent;
    event* m_pkRecoveryEvent;
    event* m_pkTimedEvent;
    event* m_pkFishingEvent;
    event* m_pkAffectEvent;
    event* m_pkPoisonEvent;
    event* m_pkFireEvent;
    std::map<int,event*> m_mapMobSkillEvent;
    event* m_pkWarpNPCEvent;
    event* m_pkMiningEvent;
    event* m_pkWarpEvent;
    event* m_pkCheckSpeedHackEvent;
    event* m_pkDestroyWhenIdleEvent;
    bool m_bHasPoisoned;
    class CMob *m_pkMobData;
    class CMobInstance *m_pkMobInst;
  private:
    int m_aiPremiumTimes[9];
    static const DWORD msc_dwDefaultChangeItemAttrCycle;
    static char msc_szLastChangeItemAttrFlag[0];
    static char msc_szChangeItemAttrCycleFlag[0];
    bool m_isinPCBang;
    class CArena *m_pArena;
    bool m_ArenaObserver;
    int m_nPotionLimit;
    bool m_isOpenSafebox;
  public:
    int m_iRefineTime;
    int m_iSeedTime;
    int m_iExchangeTime;
    int m_iMyShopTime;
    DWORD m_dwMonarchCooltime[5];
    DWORD m_dwMonarchCooltimelimit[5];
  private:
    e_overtime m_eOverTime;
    int m_deposit_pulse;
  public:
    CHARACTER::SAttackLog m_kAttackLog;
    CHARACTER::AttackedLog m_AttackedLog;
    int m_speed_hack_count;
  private:
    std::string m_strNewName;
    std::set<unsigned int> m_known_guild;
    DWORD m_dwLogOffInterval;
    DWORD m_dwLastGoldDropTime;
  public:
    event* m_HackShieldCheckEvent;
  private:
    bool m_HackShieldCheckMode;
  public:
    // Custom vars begin
    CHARACTER * m_pkPet;
    time_t m_tLastSync;
    float m_fSyncDist;
  protected:
    virtual void EncodeInsertPacket(LPENTITY);
    virtual void EncodeRemovePacket(LPENTITY);
  public:
    LPCHARACTER FindCharacterInView(const char *, bool);
    void UpdatePacket(void);
    virtual void StateMove(void);
    virtual void StateBattle(void);
    virtual void StateIdle(void);
    virtual void StateFlag(void);
    virtual void StateFlagBase(void);
    void StateHorse(void);
  protected:
    void __StateIdle_Monster(void);
    void __StateIdle_Stone(void);
    void __StateIdle_NPC(void);
  public:
    DWORD GetAIFlag(void) const;
    void SetAggressive(void);
    bool IsAggressive(void) const;
    void SetCoward(void);
    bool IsCoward(void) const;
    void CowardEscape(void);
    void SetNoAttackShinsu(void);
    bool IsNoAttackShinsu(void) const;
    void SetNoAttackChunjo(void);
    bool IsNoAttackChunjo(void) const;
    void SetNoAttackJinno(void);
    bool IsNoAttackJinno(void) const;
    void SetAttackMob(void);
    bool IsAttackMob(void) const;
    virtual void BeginStateEmpty(void);
    virtual void EndStateEmpty(void);
    CHARACTER(void);
    ~CHARACTER();
    void Create(const char *, DWORD, bool);
    void Destroy(void);
    void Disconnect(const char *);
  protected:
    void Initialize(void);
  public:
    DWORD GetPlayerID(void) const;
    void SetPlayerProto(const TPlayerTable *);
    void CreatePlayerProto(TPlayerTable &);
    void SetProto(const CMob *);
    WORD GetRaceNum(void) const;
    void Save(void);
    void SaveReal(void);
    void FlushDelayedSaveItem(void);
    const char * GetName(void) const;
    const VID & GetVID(void) const;
    void SetName(
    const std::string &);
    void SetRace(BYTE);
    bool ChangeSex(void);
    DWORD GetAID(void) const;
    int GetChangeEmpireCount(void) const;
    void SetChangeEmpireCount(void);
    int ChangeEmpire(BYTE);
    BYTE GetJob(void) const;
    BYTE GetCharType(void) const;
    bool IsPC(void) const;
    bool IsNPC(void) const;
    bool IsMonster(void) const;
    bool IsStone(void) const;
    bool IsDoor(void) const;
    bool IsBuilding(void) const;
    bool IsWarp(void) const;
    bool IsGoto(void) const;
    DWORD GetLastShoutPulse(void) const;
    void SetLastShoutPulse(DWORD);
    int GetLevel(void) const;
    void SetLevel(BYTE);
    BYTE GetGMLevel(void) const;
    bool IsGM(void) const;
    void SetGMLevel(void);
    DWORD GetExp(void) const;
    void SetExp(DWORD);
    DWORD GetNextExp(void) const;
    LPCHARACTER DistributeExp(void);
    void DistributeHP(LPCHARACTER);
    void DistributeSP(LPCHARACTER, int);
    void SetPosition(int);
    bool IsPosition(int) const;
    int GetPosition(void) const;
    void SetPart(BYTE, WORD);
    WORD GetPart(BYTE) const;
    WORD GetOriginalPart(BYTE) const;
    void SetHP(int);
    int GetHP(void) const;
    void SetSP(int);
    int GetSP(void) const;
    void SetStamina(int);
    int GetStamina(void) const;
    void SetMaxHP(int);
    int GetMaxHP(void) const;
    void SetMaxSP(int);
    int GetMaxSP(void) const;
    void SetMaxStamina(int);
    int GetMaxStamina(void) const;
    void SetRandomHP(int);
    void SetRandomSP(int);
    int GetRandomHP(void) const;
    int GetRandomSP(void) const;
    int GetHPPct(void) const;
    void SetRealPoint(BYTE, int);
    int GetRealPoint(BYTE) const;
    void SetPoint(BYTE, int);
    int GetPoint(BYTE) const;
    int GetLimitPoint(BYTE) const;
    int GetPolymorphPoint(BYTE) const;
    const TMobTable & GetMobTable(void) const;
    BYTE GetMobRank(void) const;
    BYTE GetMobBattleType(void) const;
    BYTE GetMobSize(void) const;
    DWORD GetMobDamageMin(void) const;
    DWORD GetMobDamageMax(void) const;
    WORD GetMobAttackRange(void) const;
    DWORD GetMobDropItemVnum(void) const;
    float GetMobDamageMultiply(void) const;
    bool IsBerserker(void) const;
    bool IsBerserk(void) const;
    void SetBerserk(bool);
    bool IsStoneSkinner(void) const;
    bool IsGodSpeeder(void) const;
    bool IsGodSpeed(void) const;
    void SetGodSpeed(bool);
    bool IsDeathBlower(void) const;
    bool IsDeathBlow(void) const;
    bool IsReviver(void) const;
    bool HasReviverInParty(void) const;
    bool IsRevive(void) const;
    void SetRevive(bool);
    bool IsRaceFlag(DWORD) const;
    bool IsSummonMonster(void) const;
    DWORD GetSummonVnum(void) const;
    DWORD GetPolymorphItemVnum(void) const;
    DWORD GetMonsterDrainSPPoint(void) const;
    void MainCharacterPacket(void);
    void ComputePoints(void);
    void ComputeBattlePoints(void);
    void PointChange(BYTE, int, bool, bool);
    void PointsPacket(void);
    void ApplyPoint(BYTE, int);
    void CheckMaximumPoints(void);
    bool Show(long, long, long, long, bool);
    void Sitdown(int);
    void Standup(void);
    void SetRotation(float);
    void SetRotationToXY(long, long);
    float GetRotation(void) const;
    void MotionPacketEncode(BYTE, LPCHARACTER, packet_motion *);
    void Motion(BYTE, LPCHARACTER);
    void ChatPacket(BYTE, const char *, ...);
    void MonsterChat(BYTE);
    void SendGreetMessage(void);
    void ResetPoint(int);
    void SetBlockMode(BYTE);
    void SetBlockModeForce(BYTE);
    bool IsBlockMode(BYTE) const;
    bool IsPolymorphed(void) const;
    bool IsPolyMaintainStat(void) const;
    void SetPolymorph(DWORD, bool);
    DWORD GetPolymorphVnum(void) const;
    int GetPolymorphPower(void) const;
    void fishing(void);
    void fishing_take(void);
    void mining(LPCHARACTER);
    void mining_cancel(void);
    void mining_take(void);
    void ResetPlayTime(DWORD);
    void CreateFly(BYTE, LPCHARACTER);
    void ResetChatCounter(void);
    BYTE IncreaseChatCounter(void);
    BYTE GetChatCounter(void) const;
    bool IsWalking(void) const;
    void SetWalking(bool);
    void SetNowWalking(bool);
    void ResetWalking(void);
    bool Goto(long, long);
    void Stop(void);
    bool CanMove(void) const;
    void SyncPacket(void);
    bool Sync(long, long);
    bool Move(long, long);
    void OnMove(bool);
    DWORD GetMotionMode(void) const;
    float GetMoveMotionSpeed(void) const;
    float GetMoveSpeed(void) const;
    void CalculateMoveDuration(void);
    void SendMovePacket(BYTE, BYTE, DWORD, DWORD, DWORD, DWORD, int);
    DWORD GetCurrentMoveDuration(void) const;
    DWORD GetWalkStartTime(void) const;
    DWORD GetLastMoveTime(void) const;
    DWORD GetLastAttackTime(void) const;
    void SetLastAttacked(DWORD);
    bool SetSyncOwner(LPCHARACTER, bool);
    bool IsSyncOwner(LPCHARACTER) const;
    bool WarpSet(long, long, long);
    void SetWarpLocation(long, long, long);
    void WarpEnd(void);
    const PIXEL_POSITION & GetWarpPosition(void) const;
    bool WarpToPID(DWORD);
    void SaveExitLocation(void);
    void ExitToSavedLocation(void);
    void StartStaminaConsume(void);
    void StopStaminaConsume(void);
    bool IsStaminaConsume(void) const;
    bool IsStaminaHalfConsume(void) const;
    void ResetStopTime(void);
    DWORD GetStopTime(void) const;
  protected:
    void ClearSync(void);
  public:
    void SyncQuickslot(BYTE, BYTE, BYTE);
    bool GetQuickslot(BYTE, TQuickSlot **);
    bool SetQuickslot(BYTE, TQuickSlot &);
    bool DelQuickslot(BYTE);
    bool SwapQuickslot(BYTE, BYTE);
    void ChainQuickslotItem(LPITEM, BYTE, BYTE);
    void StartAffectEvent(void);
    void ClearAffect(bool);
    void ComputeAffect(CAffect *, bool);
    bool AddAffect(DWORD, BYTE, long, DWORD, long, long, bool, bool);
    void RefreshAffect(void);
    bool RemoveAffect(DWORD);
    bool RemoveAffect(CAffect *);
    bool IsAffectFlag(DWORD) const;
    bool UpdateAffect(void);
    int ProcessAffect(void);
    void LoadAffect(DWORD, TPacketAffectElement *);
    void SaveAffect(void);
    bool IsGoodAffect(BYTE) const;
    void RemoveGoodAffect(void);
    void RemoveBadAffect(void);
    CAffect * FindAffect(DWORD, BYTE);
    const std::list<CAffect*> & GetAffectContainer(void) const;
    void SetParty(CParty *);
    CParty * GetParty(void) const;
    bool RequestToParty(LPCHARACTER);
    void DenyToParty(LPCHARACTER);
    void AcceptToParty(LPCHARACTER);
    void PartyInvite(LPCHARACTER);
    void PartyInviteAccept(LPCHARACTER);
    void PartyInviteDeny(DWORD);
    bool BuildUpdatePartyPacket(TPacketGCPartyUpdate &);
    int GetLeadershipSkillLevel(void) const;
    bool CanSummon(int);
    void SetPartyRequestEvent(event*);
  protected:
    void PartyJoin(LPCHARACTER);
    static CHARACTER::PartyJoinErrCode IsPartyJoinableCondition(LPCHARACTER, LPCHARACTER);
    static CHARACTER::PartyJoinErrCode IsPartyJoinableMutableCondition(LPCHARACTER, LPCHARACTER);
  public:
    void SetDungeon(CDungeon *);
    CDungeon * GetDungeon(void) const;
    CDungeon * GetDungeonForce(void) const;
    void SetGuild(CGuild *);
    CGuild * GetGuild(void) const;
    void SetWarMap(CWarMap *);
    CWarMap * GetWarMap(void) const;
    bool CanHandleItem(bool, bool);
    bool IsItemLoaded(void) const;
    void SetItemLoaded(void);
    void ClearItem(void);
    void SetItem(BYTE, LPITEM);
    LPITEM GetItem(BYTE) const;
    bool IsEmptyItemGrid(BYTE, BYTE, int) const;
    void SetWear(BYTE, LPITEM);
    LPITEM GetWear(BYTE) const;
    void UseSilkBotary(void);
    void UseSilkBotaryReal(const TPacketMyshopPricelistHeader *);
    bool UseItemEx(LPITEM, int);
    bool UseItem(BYTE, int);
    bool IsRefineThroughGuild(void) const;
    CGuild * GetRefineGuild(void) const;
    int ComputeRefineFee(int, int) const;
    void PayRefineFee(int);
    void SetRefineNPC(LPCHARACTER);
    bool RefineItem(LPITEM, LPITEM);
    bool DropItem(BYTE, BYTE);
    bool GiveRecallItem(LPITEM);
    void ProcessRecallItem(LPITEM);
    void EffectPacket(int);
    bool DoRefine(LPITEM, bool);
    bool DoRefineWithScroll(LPITEM);
    bool RefineInformation(BYTE, BYTE, int);
    void SetRefineMode(int);
    void ClearRefineMode(void);
    bool GiveItem(LPCHARACTER, BYTE);
    bool CanReceiveItem(LPCHARACTER, LPITEM) const;
    void ReceiveItem(LPCHARACTER, LPITEM);
    bool GiveItemFromSpecialItemGroup(DWORD, DWORD &, DWORD &, LPITEM &);
    bool MoveItem(BYTE, BYTE, BYTE);
    bool PickupItem(DWORD);
    bool EquipItem(LPITEM);
    bool UnequipItem(LPITEM);
    bool SwapItem(BYTE, BYTE);
    LPITEM AutoGiveItem(DWORD, BYTE, int, bool);
    int GetEmptyInventory(BYTE) const;
    int CountEmptyInventory(void) const;
    int CountSpecifyItem(DWORD) const;
    void RemoveSpecifyItem(DWORD, DWORD);
    LPITEM FindSpecifyItem(DWORD) const;
    LPITEM FindItemByID(DWORD) const;
    bool IsEquipUniqueItem(DWORD) const;
    bool IsEquipUniqueGroup(DWORD) const;
    void SendEquipment(LPCHARACTER);
  protected:
    void SendMyShopPriceListCmd(DWORD, DWORD);
  public:
    INT GetGold(void) const;
    void SetGold(INT);
    bool DropGold(INT);
    INT GetAllowedGold(void) const;
    void GiveGold(INT);
    void SetShop(LPSHOP);
    LPSHOP GetShop(void) const;
    void ShopPacket(BYTE);
    void SetShopOwner(LPCHARACTER);
    LPCHARACTER GetShopOwner(void) const;
    void OpenMyShop(const char *, TShopItemTable *, BYTE);
    LPSHOP GetMyShop(void) const;
    void CloseMyShop(void);
    bool ExchangeStart(LPCHARACTER);
    void SetExchange(CExchange *);
    CExchange * GetExchange(void) const;
    bool Damage(LPCHARACTER, int, EDamageType);
    bool __Profile__Damage(LPCHARACTER, int, EDamageType);
    void DeathPenalty(BYTE);
    void ReviveInvisible(int);
    bool Attack(LPCHARACTER, BYTE);
    bool IsAlive(void) const;
    bool CanFight(void) const;
    bool CanBeginFight(void) const;
    void BeginFight(LPCHARACTER);
    bool CounterAttack(LPCHARACTER);
    bool IsStun(void) const;
    void Stun(void);
    bool IsDead(void) const;
    void Dead(LPCHARACTER, bool);
    void Reward(bool);
    void RewardGold(LPCHARACTER);
    bool Shoot(BYTE);
    void FlyTarget(DWORD, long, long, BYTE);
    void ForgetMyAttacker(void);
    void AggregateMonster(void);
    void AttractRanger(void);
    void PullMonster(void);
    int GetArrowAndBow(LPITEM *, LPITEM *, int);
    void UseArrow(LPITEM, DWORD);
    void AttackedByPoison(LPCHARACTER);
    void RemovePoison(void);
    void AttackedByFire(LPCHARACTER, int, int);
    void RemoveFire(void);
    void UpdateAlignment(int);
    int GetAlignment(void) const;
    int GetRealAlignment(void) const;
    void ShowAlignment(bool);
    void SetKillerMode(bool);
    bool IsKillerMode(void) const;
    void UpdateKillerMode(void);
    BYTE GetPKMode(void) const;
    void SetPKMode(BYTE);
    void ItemDropPenalty(LPCHARACTER);
    void UpdateAggrPoint(LPCHARACTER, EDamageType, int);
    void SetComboSequence(BYTE);
    BYTE GetComboSequence(void) const;
    void SetLastComboTime(DWORD);
    DWORD GetLastComboTime(void) const;
    int GetValidComboInterval(void) const;
    void SetValidComboInterval(int);
    BYTE GetComboIndex(void) const;
    void IncreaseComboHackCount(int);
    void ResetComboHackCount(void);
    void SkipComboAttackByTime(int);
    DWORD GetSkipComboAttackByTime(void) const;
  protected:
    void UpdateAggrPointEx(LPCHARACTER, EDamageType, int, CHARACTER::TBattleInfo &);
    void ChangeVictimByAggro(int, LPCHARACTER);
  public:
    void SetStone(LPCHARACTER);
    void ClearStone(void);
    void DetermineDropMetinStone(void);
    DWORD GetDropMetinStoneVnum(void) const;
    BYTE GetDropMetinStonePct(void) const;
    void SkillLevelPacket(void);
    void SkillLevelUp(DWORD, BYTE);
    bool SkillLevelDown(DWORD);
    bool UseSkill(DWORD, LPCHARACTER, bool);
    void ResetSkill(void);
    void SetSkillLevel(DWORD, BYTE);
    int GetUsedSkillMasterType(DWORD);
    bool IsLearnableSkill(DWORD) const;
    bool CheckSkillHitCount(BYTE, VID);
    bool CanUseSkill(DWORD) const;
    bool IsUsableSkillMotion(DWORD) const;
    int GetSkillLevel(DWORD) const;
    int GetSkillMasterType(DWORD) const;
    int GetSkillPower(DWORD, BYTE) const;
    time_t GetSkillNextReadTime(DWORD) const;
    void SetSkillNextReadTime(DWORD, time_t);
    void SkillLearnWaitMoreTimeMessage(DWORD);
    void ComputePassiveSkill(DWORD);
    int ComputeSkill(DWORD, LPCHARACTER, BYTE);
    int ComputeSkillAtPosition(DWORD, const PIXEL_POSITION &, BYTE);
    void ComputeSkillPoints(void);
    void SetSkillGroup(BYTE);
    BYTE GetSkillGroup(void) const;
    int ComputeCooltime(int);
    void GiveRandomSkillBook(void);
    void DisableCooltime(void);
    bool LearnSkillByBook(DWORD, BYTE);
    bool LearnGrandMasterSkill(DWORD);
    bool HasMobSkill(void) const;
    size_t CountMobSkill(void) const;
    const TMobSkillInfo * GetMobSkill(unsigned int) const;
    bool CanUseMobSkill(unsigned int) const;
    bool UseMobSkill(unsigned int);
    void ResetMobSkillCooltime(void);
    void StartMuyeongEvent(void);
    void StopMuyeongEvent(void);
    int GetChainLightningIndex(void) const;
    void IncChainLightningIndex(void);
    void AddChainLightningExcept(LPCHARACTER);
    void ResetChainLightningIndex(void);
    int GetChainLightningMaxCount(void) const;
    const CHARACTER_SET & GetChainLightingExcept(void) const;
    void SetAffectedEunhyung(void);
    void ClearAffectedEunhyung(void);
    bool GetAffectedEunhyung(void) const;
    void AssignTriggers(const TMobTable *);
    LPCHARACTER GetVictim(void) const;
    void SetVictim(LPCHARACTER);
    LPCHARACTER GetNearestVictim(LPCHARACTER);
    LPCHARACTER GetProtege(void) const;
    bool Follow(LPCHARACTER, float);
    bool Return(void);
    bool IsGuardNPC(void) const;
    bool IsChangeAttackPosition(LPCHARACTER) const;
    void ResetChangeAttackPositionTime(void);
    void SetChangeAttackPositionTime(void);
    bool OnIdle(void);
    void OnAttack(LPCHARACTER);
    void OnClick(LPCHARACTER);
    void SetTarget(LPCHARACTER);
    void BroadcastTargetPacket(void);
    void ClearTarget(void);
    void CheckTarget(void);
    LPCHARACTER GetTarget(void) const;
    int GetSafeboxSize(void) const;
    void QuerySafeboxSize(void);
    void SetSafeboxSize(int);
    CSafebox * GetSafebox(void) const;
    void LoadSafebox(int, DWORD, int, TPlayerItem *);
    void ChangeSafeboxSize(BYTE);
    void CloseSafebox(void);
    void ReqSafeboxLoad(const char *);
    void CancelSafeboxLoad(void);
    void SetMallLoadTime(int);
    int GetMallLoadTime(void) const;
    CSafebox * GetMall(void) const;
    void LoadMall(int, TPlayerItem *);
    void CloseMall(void);
    void SetSafeboxOpenPosition(void);
    float GetDistanceFromSafeboxOpen(void) const;
    void MountVnum(DWORD);
    DWORD GetMountVnum(void) const;
    DWORD GetLastMountTime(void) const;
    virtual void SetHorseLevel(int);
    virtual bool StartRiding(void);
    virtual bool StopRiding(void);
    virtual DWORD GetMyHorseVnum(void) const;
    virtual void HorseDie(void);
    virtual bool ReviveHorse(void);
    virtual void SendHorseInfo(void);
    virtual void ClearHorseInfo(void);
    void HorseSummon(bool, bool);
    bool IsHorseVisible(void) const;
    LPCHARACTER GetRider(void) const;
    void SetRider(LPCHARACTER);
    bool IsRiding(void);
    void DetailLog(void);
    void ToggleMonsterLog(void);
    void MonsterLog(const char *, ...);
    void SetEmpire(BYTE);
    BYTE GetEmpire(void) const;
    void SetRegen(LPREGEN);
    bool CannotMoveByAffect(void) const;
    bool IsImmune(DWORD);
    void SetImmuneFlag(DWORD);
  protected:
    void ApplyMobAttribute(const TMobTable *);
  public:
    void SetQuestNPCID(DWORD);
    DWORD GetQuestNPCID(void) const;
    LPCHARACTER GetQuestNPC(void) const;
    void SetQuestItemPtr(LPITEM);
    void ClearQuestItemPtr(void);
    LPITEM GetQuestItemPtr(void) const;
    void SetQuestBy(DWORD);
    DWORD GetQuestBy(void) const;
    int GetQuestFlag(const std::string &) const;
    void SetQuestFlag(const std::string &, int);
    void ConfirmWithMsg(const char *, int, DWORD);
    bool StartStateMachine(int);
    void StopStateMachine(void);
    void UpdateStateMachine(DWORD);
    void SetNextStatePulse(int);
    LPCHARACTER GetMarryPartner(void) const;
    void SetMarryPartner(LPCHARACTER);
    int GetMarriageBonus(DWORD, bool);
    void SetWeddingMap(marriage::WeddingMap *);
    marriage::WeddingMap * GetWeddingMap(void) const;
    void StartWarpNPCEvent(void);
    void StartSaveEvent(void);
    void StartRecoveryEvent(void);
    void StartCheckSpeedHackEvent(void);
    void StartDestroyWhenIdleEvent(void);
    bool IsWarping(void) const;
    int GetPremiumRemainSeconds(BYTE) const;
    bool SetPCBang(bool);
    bool IsPCBang(void) const;
    bool ItemProcess_Hair(LPITEM, int);
    void ClearSkill(void);
    void ClearSubSkill(void);
    bool ResetOneSkill(DWORD);
  private:
    void SendDamagePacket(LPCHARACTER, int, BYTE);
  public:
    void SetArena(CArena *);
    void SetArenaObserverMode(bool);
    CArena * GetArena(void) const;
    bool GetArenaObserverMode(void) const;
    void SetPotionLimit(int);
    int GetPotionLimit(void) const;
    bool IsOpenSafebox(void) const;
    void SetOpenSafebox(bool);
    int GetSafeboxLoadTime(void) const;
    void SetSafeboxLoadTime(void);
    int GetSkillPowerByLevel(int, bool) const;
    int GetRefineTime(void) const;
    void SetRefineTime(void);
    int GetUseSeedOrMoonBottleTime(void) const;
    void SetUseSeedOrMoonBottleTime(void);
    int GetExchangeTime(void) const;
    void SetExchangeTime(void);
    int GetMyShopTime(void) const;
    void SetMyShopTime(void);
    bool IsHack(bool, bool, int);
    BOOL IsMonarch(void) const;
    void Say(const std::string &);
    void InitMC(void);
    DWORD GetMC(MONARCH_INDEX) const;
    void SetMC(MONARCH_INDEX);
    bool IsMCOK(MONARCH_INDEX) const;
    DWORD GetMCL(MONARCH_INDEX) const;
    DWORD GetMCLTime(MONARCH_INDEX) const;
    bool ItemProcess_Polymorph(LPITEM);
    LPITEM * GetCubeItem(void);
    bool IsCubeOpen(void) const;
    void SetCubeNpc(LPCHARACTER);
    bool CanDoCube(void) const;
    bool IsSiegeNPC(void) const;
    bool IsOverTime(e_overtime) const;
    void SetOverTime(e_overtime);
    void UpdateDepositPulse(void);
    bool CanDeposit(void) const;
  private:
    void __OpenPrivateShop(void);
  public:

    const std::string GetNewName(void) const;
    void SetNewName(std::string);
    void GoHome(void);
    void SendGuildName(CGuild *);
    void SendGuildName(DWORD);
    DWORD GetLogOffInterval(void) const;
    bool UnEquipSpecialRideUniqueItem(void);
    bool CanWarp(void) const;
    void StartHackShieldCheckCycle(int);
    void StopHackShieldCheckCycle(void);
    bool GetHackShieldCheckMode(void) const;
    void SetHackShieldCheckMode(bool);
    void AutoRecoveryItemProcess(EAffectTypes);

};


class CHARACTER_MANAGER : public singleton<CHARACTER_MANAGER> {
  public:
    int m_iMobItemRate;
    int m_iMobDamageRate;
    int m_iMobGoldAmountRate;
    int m_iMobGoldDropRate;
    int m_iMobExpRate;
    int m_iMobItemRatePremium;
    int m_iMobGoldAmountRatePremium;
    int m_iMobGoldDropRatePremium;
    int m_iMobExpRatePremium;
    int m_iUserDamageRate;
    int m_iUserDamageRatePremium;
    int m_iVIDCount;
    std::map<unsigned int, CHARACTER*> m_map_pkChrByVID;
    std::map<unsigned int, CHARACTER*> m_map_pkChrByPID;

    boost::unordered_map<std::string, CHARACTER*, boost::hash<std::string>> m_map_pkPCChr;
    char dummy1[1024];
    CHARACTER_SET m_set_pkChrState;
    CHARACTER_SET m_set_pkChrForDelayedSave;
    CHARACTER_SET m_set_pkChrMonsterLog;
    LPCHARACTER m_pkChrSelectedStone;
    std::map<unsigned int, unsigned int> m_map_dwMobKillCount;
    std::set<unsigned int> m_set_dwRegisteredRaceNum;

    std::map<unsigned int, std::set<CHARACTER*>> m_map_pkChrByRaceNum;
    bool m_bUsePendingDestroy;
    CHARACTER_SET m_set_pkChrPendingDestroy;
};

class CSpecialItemGroup {
    class CSpecialItemInfo {
        DWORD vnum;
        int count;
        int rare;
      public:
        CSpecialItemInfo(DWORD, int, int);
    };


    DWORD m_dwVnum;
    std::vector<int > m_vecProbs;

    std::vector<CSpecialItemInfo> m_vecItems;
  public:
    CSpecialItemGroup(DWORD);
    void AddItem(DWORD, int, int, int);
    bool IsEmpty(void) const;
    int GetOneIndex(void) const;
    int GetVnum(int) const;
    int GetCount(int) const;
    int GetRarePct(int) const;
    bool Contains(DWORD) const;
};
class CBuyerThiefGlovesItemGroup {
	class SThiefGroupInfo {
		DWORD dwVnum;
		DWORD dwPct;
		int iCount;
	  public:
		SThiefGroupInfo(DWORD, DWORD, int);
	};

  private:
    DWORD m_dwVnum;
    DWORD m_dwMobVnum;

    std::string m_stName;

    std::vector<SThiefGroupInfo, std::allocator<SThiefGroupInfo> > m_vec_items;

  public:
    CBuyerThiefGlovesItemGroup(DWORD, DWORD, const std::string &);

    const std::vector<SThiefGroupInfo> & GetVector(void);
    void AddItem(DWORD, DWORD, int);
};


class CLevelItemGroup {
class SLevelItemGroupInfo {
    DWORD dwVNum;
    DWORD dwPct;
    int iCount;
  public:
    SLevelItemGroupInfo(DWORD, DWORD, int);
};
  private:
    DWORD m_dwLevelLimit;

    std::string m_stName;

    std::vector<SLevelItemGroupInfo, std::allocator<SLevelItemGroupInfo> > m_vec_items;

  public:
    CLevelItemGroup(DWORD);
    DWORD GetLevelLimit(void);
    void AddItem(DWORD, DWORD, int);

    const std::vector<SLevelItemGroupInfo> & GetVector(void);
};


class CMobItemGroup {
	class SMobItemGroupInfo {
		DWORD dwItemVnum;
		int iCount;
		int iRarePct;
	  public:
		SMobItemGroupInfo(DWORD, int, int);
	};

  private:
    DWORD m_dwMobVnum;
    int m_iKillDrop;

    std::string m_stName;
    std::vector<int> m_vecProbs;

    std::vector<SMobItemGroupInfo> m_vecItems;

};

class CDropItemGroup {
	class SDropItemGroupInfo {
		DWORD dwVnum;
		DWORD dwPct;
		int iCount;
	  public:
		SDropItemGroupInfo(DWORD, DWORD, int);
	};

  private:
    DWORD m_dwVnum;
    DWORD m_dwMobVnum;

    std::string m_stName;

    std::vector<SDropItemGroupInfo> m_vec_items;

  public:
    CDropItemGroup(DWORD, DWORD, std::string &);

    const std::vector<SDropItemGroupInfo> & GetVector(void);
    void AddItem(DWORD, DWORD, int);
};

class ITEM_MANAGER : public singleton<ITEM_MANAGER> {
  protected:
    std::vector<SItemTable> m_vec_prototype;

    std::map<unsigned int, unsigned int> m_map_ItemRefineFrom;
    int m_iTopOfTable;

    std::map<unsigned int, CItem*> m_VIDMap;
    DWORD m_dwVIDCount;
    DWORD m_dwCurrentID;
    TItemIDRangeTable m_ItemIDRange;
    TItemIDRangeTable m_ItemIDSpareRange;

    std::set<CItem*> m_set_pkItemForDelayedSave;

    std::map<unsigned int, CItem*> m_map_pkItemByID;

    std::map<unsigned int, unsigned int> m_map_dwEtcItemDropProb;


    std::map<unsigned int, CDropItemGroup*> m_map_pkDropItemGroup;

    std::map<unsigned int, CSpecialItemGroup* > m_map_pkSpecialItemGroup;

    std::map<unsigned int, CMobItemGroup*> m_map_pkMobItemGroup;

    std::map<unsigned int, CLevelItemGroup*> m_map_pkLevelItemGroup;

    std::map<unsigned int, CBuyerThiefGlovesItemGroup*> m_map_pkGloveItemGroup;

    std::map<unsigned int, int> m_ItemToSpecialGroup;
  public:

    std::map<unsigned int, SItemTable> m_map_vid;

    ITEM_MANAGER(void);
    ~ITEM_MANAGER();
    bool Initialize(TItemTable *, int);
    void Destroy(void);
    void Update(void);
    void GracefulShutdown(void);
    DWORD GetNewID(void);
    bool SetMaxItemID(TItemIDRangeTable);
    bool SetMaxSpareItemID(TItemIDRangeTable);
    void DelayedSave(LPITEM);
    void FlushDelayedSave(LPITEM);
    void SaveSingleItem(LPITEM);
    LPITEM CreateItem(DWORD, DWORD, DWORD, bool, int);
    void DestroyItem(LPITEM);
    void RemoveItem(LPITEM, const char *);
    LPITEM Find(DWORD);
    LPITEM FindByVID(DWORD);
    TItemTable * GetTable(DWORD);

    const std::vector<SItemTable> & GetTable(void);
    bool GetVnum(const char *, DWORD &);

    bool GetVnumByOriginalName(const char *, DWORD &);
    bool CreateDropItem(LPCHARACTER, LPCHARACTER, std::vector<CItem*> &);
    bool ReadCommonDropItemFile(const char *);
    bool ReadEtcDropItemFile(const char *);
    bool ReadDropItemGroup(const char *);
    bool ReadMonsterDropItemGroup(const char *);
    bool ReadSpecialDropItemFile(const char *);
    bool ConvSpecialDropItemFile(void);
    DWORD GetRefineFromVnum(DWORD);
    const CSpecialItemGroup * GetSpecialItemGroup(DWORD);
    int GetSpecialGroupFromItem(DWORD);
  protected:
    int RealNumber(DWORD);
    void CreateQuestDropItem(LPCHARACTER, LPCHARACTER, std::vector<CItem*> &, int, int);
  public:

    std::map<unsigned int, SItemTable> & GetVIDMap(void);
    std::vector<SItemTable> & GetVecProto(void);
};


}

#endif // __GAMEINFO_HPP
