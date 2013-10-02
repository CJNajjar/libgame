#ifndef __MYADDR_HPP
#define __MYADDR_HPP
namespace myAddr{
const int aApplyInfo_refs[]={
    0x8079C65, // CHARACTER::ApplyPoint
    0x809D47E, // CHARACTER::UseItemEx+4AE
    0x809E439, // CHARACTER::UseItemEx+160C
    0x809EFAA, // CHARACTER::UseItemEx+1FDA
    0x809F45B, // CHARACTER::UseItemEx+248B
    0x80A07E2, // CHARACTER::UseItemEx+3812
    0x80A1F1C, // CHARACTER::UseItemEx+4F4C
    0x8195676, // quest::affect_add
    0x8195792, // quest::affect_remove
    0x8195B18, // quest::affect_add_collect
    0x8195E28, // quest::affect_add_hair
    0x81B5458 // quest::pc_mount_bonus
};
enum class misc{
    priv_empire_maxrate=0x818C1A8,
    priv_empire_maxrate2=0x80DD4A3,
    priv_empire_maxrate3=0x818C3E7,
    aApplyInfo=0x846AD80,
    do_war=0x80D2580,
    number_ex=0x8439620,
    change_attr_time=0x80A6CA3,
    GiveExp=0x808A1F0,
    aiPercentByDeltaLev_euckr=0x846A940,
};
enum class horse{
    c_aHorseStat=0x85EE480,
};
}
#endif // __MYADDR_HPP
