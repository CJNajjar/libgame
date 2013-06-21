#ifndef ADDR_2089
#define ADDR_2089
namespace General
{
    enum class Addr {
        kGetGlobalTime = 0x81DE6E0,
        kOneArgument = 0x81DE580,
        kNumber_ex = 0x809059B,
        kSingleton_DBManager = 0x84C5B78,
        kSingleton_ITEM_MANAGER = 0x84C5B18,
        kSingleton_CHARACTER_MANAGER = 0x84C485C,
        kSingleton_QUEST_MANAGER = 0x084C4860,
        kSendNoticeMap = 0x80CC910,
        kWriteVersion = 0x81E5260,
        kMetin2Server_Check = 0x81F2AB0,
    };
}
namespace CHARACTER_MANAGER
{
    enum class Addr {
        kFindPC = 0x080A6530,
        kDestroyCharacter = 0x80A6660,
        kSpawnMob = 0x80A7040,
        kFindDWORD = 0x80A4F50,
    };
}
namespace CItem {
    enum class Addr {
        kGetCount = 0x8137DC0,
        kChangeAttr = 0x0813CB10,
        kSetAttribute = 0x813BB20,
        kFindEquipCell = 0x8138E30,
        kEquipTo = 0x813AEF0,
        kClearAttribute = 0x813B930,
    };
}
namespace ITEM_MANAGER{
    enum class Addr {
        kFindByVID = 0x813DA90,
        kCreateItem = 0x813E4F0,
        kDestroyItem = 0x813DFC0,
        kGetSpecialItemGroup = 0x813CE80,
        kRemoveItem = 0x813E390,
    };
}
namespace Command{
    enum class Addr {
        kIPurge = 0x80CC680,
        kBigNotice = 0x80CA6D0,
        kChangeAttr = 0x80CAA40,
        kFirst_cmd = 0x81DE4D0,
        kDouble_dollar = 0x80C2B80,
        kInterpret_command = 0x80C2D00,
    };
}
namespace CParty {
    enum class Addr {
        kGetLeaderPID = 0x81699C0,
    };
};
namespace CHARACTER {
    enum class Addr {
        kGetWear = 0x80919D0,
        kChatPacket = 0x806C9E0,
        kMoveItem = 0x806C9E0,
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
        kSetSkillLevel = 0x80AC6A0,
        kCanUseSkill = 0x80ABE80,
        kRemoveAffect = 0x8081800,
        kHorseSummon = 0x80908F0,
        kUnequipItem = 0x80922A0,
        kSetShop = 0x806A370,
        kDropItem = 0x8094D80,
        kUseItem = 0x80A2570,
        kDropGold = 0x8096CB0,
        kSetRider = 0x8090500,
        kGetJob = 0x806C820,
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
    kBufferedPacket = 0x80EA930,
    kPacket = 0x80ECCD0,
    };
}
namespace Lua{
    enum class Addr {
        kDoString = 0x832ACA0,
        kToString = 0x831DDD0,
        kToBoolean = 0x831CF20,
        kToCFunction = 0x831CF60,
        kToNumber = 0x831DE40,
        kToPointer = 0x831D000,
        kToThread = 0x831CFD0,
        kToUserData = 0x831CF90,
        kPushBoolean = 0x831D0B0,
        kPushCClosure = 0x831D8A0,
        kPushFString = 0x831DCF0,
        kPushLightUserData = 0x831D0E0,
        kPushLString = 0x831D670,
        kPushNil = 0x831D070,
        kPushNumber = 0x831D073,
        kPushString = 0x831DD30,
        kPushUpValues = 0x831D3D0,
        kPushValue = 0x831CE20,
        kPushVFString = 0x831DCA0,
        kIsNumber = 0x831DE80,
        kIsString = 0x831CEC0,
        kNewTable = 0x831DB50,
        kGetTop = 0x831CCC0,
        kRawSetI = 0x831DA40,
        kRawSet = 0x831DAA0,
        kDoFile = 0x832AFB0,
        kSetTable = 0x831DB00,
        kSetTop = 0x831CCE0,
    };
}
namespace CQuestManager{
    enum class Addr{
        kGetCurrentDungeon = 0x81A6F20,
        kGetCurrentNPCCharacterPtr = 0x81A6890,
        kGetCurrentItem = 0x081A6FC0,
    };
}
namespace quest{

    enum class Addr {
        kAddLuaFunctionTable = 0x08176380,
        kRegisterAffectFunctionTable = 0x817A760,
    };
}
namespace DBManager{
    enum class Addr{
        kEscapeString = 0x80E08B0,
        kDirectQuery = 0x80E06D0,
    };
}
namespace libMySQL{
    enum class Addr {
        kFetchField = 0x082D93A0,
        kFreeResult = 0x082D4AF0,
        kFetchRow = 0x82D7050,
        kFetchFields = 0x082D97E0,
        kNumFields = 0x082D3730,
    };
}
namespace CInputMain{
    enum class Addr {
        kItemDrop = 0x08129F50,
        kItemDrop2 = 0x8129ED0,
        kItemPickup = 0x08129E30,
        kItemGive = 0x0812CE10,
        kItemToItem = 0x08129FD0,
        kItemUse = 0x0812A030,
        kItemMove = 0x08129E80,
        kSyncPosition = 0x0812E360,
    };
}
namespace CEntity{
    enum class Addr{
        kPacketAround = 0x080FB380,
    };
}
namespace CAsyncSQL{
    enum class Addr{
        kDirectQuery=0x83353B0,
    };
}
#endif // ADDR_2089