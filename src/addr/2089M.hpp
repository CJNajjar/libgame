#ifndef ADDR_2089M
#define ADDR_2089M
namespace General
{
    enum class Addr {
        kGetGlobalTime = 0x81DE340,
        kOneArgument = 0x81DE1E0,
        kNumber_ex = 0x8315F80,
        kSingleton_DBManager = 0x84C4A38,
        kSingleton_ITEM_MANAGER = 0x84C49D8,
        kSingleton_CHARACTER_MANAGER = 0x84C371C,
        kSingleton_QUEST_MANAGER = 0x084C3720,
        kSendNoticeMap = 0x80CC840,
        kWriteVersion = 0x81E4EC0,
        kMetin2Server_Check = 0x81F23E0,
    };
}
namespace CHARACTER_MANAGER
{
    enum class Addr {
        kFindPC = 0x80A6530,
        kDestroyCharacter = 0x80A6660,
        kSpawnMob = 0x80A7040,
        kFindDWORD = 0x80A4F50,
    };
}
namespace CItem {
    enum class Addr {
        kGetCount = 0x8137A20,
        kChangeAttr = 0x813C770,
        kSetAttribute = 0x813B780,
        kFindEquipCell = 0x8138a90,
        kEquipTo = 0x813ab50,
        kClearAttribute = 0x813b590,
    };
}
namespace ITEM_MANAGER{
    enum class Addr {
        kFindByVID = 0x813d6f0,
        kCreateItem = 0x813e150,
        kDestroyItem = 0x813dc20,
        kGetSpecialItemGroup = 0x813cae0,
        kRemoveItem = 0x813DFF0,
    };
}
namespace Command{
    enum class Addr {
        kIPurge = 0x80CC5B0,
        kBigNotice = 0x80CA600,
        kChangeAttr = 0x80CA970,
        kFirst_cmd = 0x81de130,
        kDouble_dollar = 0x80c2b80,
        kInterpret_command = 0x80c2d00,
    };
}
namespace CParty {
    enum class Addr {
        kGetLeaderPID = 0x8169620,
    };
};
namespace CHARACTER {
    enum class Addr {
        kGetWear = 0x80919D0,
        kChatPacket = 0x806C9E0,
        kMoveItem = 0x8096700,
        kEffectPacket = 0x806D340,
        kSyncQuickslot = 0x80AB1E0,
        kGetName = 0x8069E70,
        kSetItem = 0x80926A0,
        kGetItem = 0x8091B60,
        kIsEmptyItemGrid = 0x8091450,
        kShow = 0x8070A80,
        kStateHorse = 0x80BFCF0,
        kSetWarpLocation = 0x806A4E0,
        kAddAffect = 0x8082370,
        kSetSkillLevel = 0x80ac6a0,
        kCanUseSkill = 0x80abe80,
        kRemoveAffect = 0x8081800,
        kHorseSummon = 0x80908F0,
        kUnequipItem = 0x80922a0,
        kSetShop = 0x806a370,
        kDropItem = 0x8094d80,
        kUseItem = 0x80a2570,
        kDropGold = 0x8096cb0,
        kSetRider = 0x8090500,
        kGetJob = 0x806c820,
        kDestroy=0x8078510,
        kGetRider=0x8090570,
        kCHARACTER=0x807D5E0,
        kGetCharType=0x806A3F0,
        kSetSyncOwner=0x806FC10,
        kSync=0x80716F0,
    };
}
namespace DESC {
    enum class Addr {
    kBufferedPacket = 0x80ea860,
    kPacket = 0x80ECC00,
    };
}
namespace Lua{
    enum class Addr {
        kDoString = 0x0832A5FE,
        kToString = 0x0831D700,
        kToBoolean = 0x0831C850,
        kToCFunction = 0x0831C890,
        kToNumber = 0x0831d770,
        kToPointer = 0x0831C930,
        kToThread = 0x0831C900,
        kToUserData = 0x0831C8C0,
        kPushBoolean = 0x0831C9E0,
        kPushCClosure = 0x0831d1d0,
        kPushFString = 0x0831d620,
        kPushLightUserData = 0x0831ca10,
        kPushLString = 0x0831cfa0,
        kPushNil = 0x0831c9a0,
        kPushNumber = 0x0831C9C0,
        kPushString = 0x0831d660,
        kPushUpValues = 0x0831cd00,
        kPushValue = 0x0831c750,
        kPushVFString = 0x0831d5d0,
        kIsNumber = 0x0831D7B0,
        kIsString = 0x0831C815,
        kNewTable = 0x0831d480,
        kGetTop = 0x0831c5f0,
        kRawSetI = 0x0831d370,
        kRawSet = 0x0831d3d0,
        kDoFile = 0x0832A8E0,
        kSetTable = 0x831D480,
        kSetTop = 0x831C610,
    };
}
namespace CQuestManager{
    enum class Addr{
        kGetCurrentDungeon = 0x81A6B80,
        kGetCurrentNPCCharacterPtr = 0x81A64F0,
        kGetCurrentItem = 0x081A6C20,
    };
}
namespace quest{

    enum class Addr {
        kAddLuaFunctionTable = 0x8175FE0,
        kRegisterAffectFunctionTable = 0x817A3C0,
    };
}
namespace DBManager{
    enum class Addr{
        kEscapeString = 0x80E07E0,
        kDirectQuery = 0x080E0600,
    };
}
namespace libMySQL{
    enum class Addr {
        kFetchField = 0x82D8CD0,
        kFreeResult = 0x82D4420,
        kFetchRow = 0x82D6980,
        kFetchFields = 0x82D9110,
        kNumFields = 0x82D3060,
    };
}
namespace CInputMain{
    enum class Addr {
        kItemDrop = 0x8129bb0,
        kItemDrop2 = 0x8129b30,
        kItemPickup = 0x8129a90,
        kItemGive = 0x812ca70,
        kItemToItem = 0x8129c30,
        kItemUse = 0x8129c90,
        kItemMove = 0x8129ae0,
        kSyncPosition = 0x0812dfc0,
    };
}
namespace CEntity{
    enum class Addr{
        kPacketAround = 0x80FB2B0,
    };
}
namespace CAsyncSQL{
    enum class Addr{
        kDirectQuery=0x08334CE0,
    };
}
#endif // ADDR_2089M
