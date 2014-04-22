#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Generic
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/commands/test.o \
	${OBJECTDIR}/src/dif/ApplyInfo.o \
	${OBJECTDIR}/src/dif/ChangeAttr.o \
	${OBJECTDIR}/src/dif/EmpirePriv.o \
	${OBJECTDIR}/src/dif/GuildOfferExp.o \
	${OBJECTDIR}/src/dif/HorseTable.o \
	${OBJECTDIR}/src/game/iCHARACTER.o \
	${OBJECTDIR}/src/globals.o \
	${OBJECTDIR}/src/hooks/CalcAttBonus.o \
	${OBJECTDIR}/src/hooks/CharacterConstructor.o \
	${OBJECTDIR}/src/hooks/DoWar.o \
	${OBJECTDIR}/src/hooks/DropGold.o \
	${OBJECTDIR}/src/hooks/GiveExp.o \
	${OBJECTDIR}/src/hooks/HorseApply.o \
	${OBJECTDIR}/src/hooks/HorseVnum.o \
	${OBJECTDIR}/src/hooks/NumberEx.o \
	${OBJECTDIR}/src/hooks/PointChange.o \
	${OBJECTDIR}/src/hooks/SyncPosition.o \
	${OBJECTDIR}/src/hooks/UseItemEx.o \
	${OBJECTDIR}/src/libm2/Command.o \
	${OBJECTDIR}/src/libm2/IQuest.o \
	${OBJECTDIR}/src/libm2/LibM2.o \
	${OBJECTDIR}/src/libm2/game/CEntity.o \
	${OBJECTDIR}/src/libm2/game/CFSM.o \
	${OBJECTDIR}/src/libm2/game/CGuild.o \
	${OBJECTDIR}/src/libm2/game/CGuildManager.o \
	${OBJECTDIR}/src/libm2/game/CHARACTER.o \
	${OBJECTDIR}/src/libm2/game/CHARACTER_MANAGER.o \
	${OBJECTDIR}/src/libm2/game/CHorseRider.o \
	${OBJECTDIR}/src/libm2/game/CInputAuth.o \
	${OBJECTDIR}/src/libm2/game/CInputClose.o \
	${OBJECTDIR}/src/libm2/game/CInputDB.o \
	${OBJECTDIR}/src/libm2/game/CInputDead.o \
	${OBJECTDIR}/src/libm2/game/CInputHandshake.o \
	${OBJECTDIR}/src/libm2/game/CInputLogin.o \
	${OBJECTDIR}/src/libm2/game/CInputMain.o \
	${OBJECTDIR}/src/libm2/game/CInputP2P.o \
	${OBJECTDIR}/src/libm2/game/CInputProcessor.o \
	${OBJECTDIR}/src/libm2/game/CItem.o \
	${OBJECTDIR}/src/libm2/game/CPetActor.o \
	${OBJECTDIR}/src/libm2/game/CPetSystem.o \
	${OBJECTDIR}/src/libm2/game/CPrivManager.o \
	${OBJECTDIR}/src/libm2/game/CShopManager.o \
	${OBJECTDIR}/src/libm2/game/CState.o \
	${OBJECTDIR}/src/libm2/game/CThreeWayWar.o \
	${OBJECTDIR}/src/libm2/game/DBManager.o \
	${OBJECTDIR}/src/libm2/game/DESC.o \
	${OBJECTDIR}/src/libm2/game/DESC_MANAGER.o \
	${OBJECTDIR}/src/libm2/game/EVENT.o \
	${OBJECTDIR}/src/libm2/game/ITEM_MANAGER.o \
	${OBJECTDIR}/src/libm2/game/LogManager.o \
	${OBJECTDIR}/src/libm2/game/P2P_MANAGER.o \
	${OBJECTDIR}/src/libm2/game/SECTREE.o \
	${OBJECTDIR}/src/libm2/game/SECTREE_MANAGER.o \
	${OBJECTDIR}/src/libm2/game/SECTREE_MAP.o \
	${OBJECTDIR}/src/libm2/game/SQLMsg.o \
	${OBJECTDIR}/src/libm2/game/SQLResult.o \
	${OBJECTDIR}/src/libm2/game/TAffectFlag.o \
	${OBJECTDIR}/src/libm2/game/TEMP_BUFFER.o \
	${OBJECTDIR}/src/libm2/game/VID.o \
	${OBJECTDIR}/src/libm2/game/building/CLand.o \
	${OBJECTDIR}/src/libm2/game/building/CManager.o \
	${OBJECTDIR}/src/libm2/game/building/CObject.o \
	${OBJECTDIR}/src/libm2/game/global.o \
	${OBJECTDIR}/src/libm2/game/lua.o \
	${OBJECTDIR}/src/libm2/game/marriage/CManager.o \
	${OBJECTDIR}/src/libm2/game/marriage/TMarriage.o \
	${OBJECTDIR}/src/libm2/game/misc.o \
	${OBJECTDIR}/src/libm2/game/quest/CQuestManager.o \
	${OBJECTDIR}/src/libm2/game/quest/PC.o \
	${OBJECTDIR}/src/libm2/lib/dif.o \
	${OBJECTDIR}/src/libm2/lib/log.o \
	${OBJECTDIR}/src/libm2/utils/hde/hde32.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/quest/item2.o \
	${OBJECTDIR}/src/quest/npc2.o \
	${OBJECTDIR}/src/quest/pc2.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-I/usr/local/include -L/usr/local/lib -lyaml-cpp -L/usr/local/lib/mysql -lmysqlclient -pthread -lz -lm

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgame.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgame.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgame.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/commands/test.o: nbproject/Makefile-${CND_CONF}.mk src/commands/test.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/commands
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/commands/test.o src/commands/test.cpp

${OBJECTDIR}/src/dif/ApplyInfo.o: nbproject/Makefile-${CND_CONF}.mk src/dif/ApplyInfo.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/dif
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dif/ApplyInfo.o src/dif/ApplyInfo.cpp

${OBJECTDIR}/src/dif/ChangeAttr.o: nbproject/Makefile-${CND_CONF}.mk src/dif/ChangeAttr.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/dif
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dif/ChangeAttr.o src/dif/ChangeAttr.cpp

${OBJECTDIR}/src/dif/EmpirePriv.o: nbproject/Makefile-${CND_CONF}.mk src/dif/EmpirePriv.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/dif
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dif/EmpirePriv.o src/dif/EmpirePriv.cpp

${OBJECTDIR}/src/dif/GuildOfferExp.o: nbproject/Makefile-${CND_CONF}.mk src/dif/GuildOfferExp.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/dif
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dif/GuildOfferExp.o src/dif/GuildOfferExp.cpp

${OBJECTDIR}/src/dif/HorseTable.o: nbproject/Makefile-${CND_CONF}.mk src/dif/HorseTable.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/dif
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dif/HorseTable.o src/dif/HorseTable.cpp

${OBJECTDIR}/src/game/iCHARACTER.o: nbproject/Makefile-${CND_CONF}.mk src/game/iCHARACTER.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/game/iCHARACTER.o src/game/iCHARACTER.cpp

${OBJECTDIR}/src/globals.o: nbproject/Makefile-${CND_CONF}.mk src/globals.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/globals.o src/globals.cpp

${OBJECTDIR}/src/hooks/CalcAttBonus.o: nbproject/Makefile-${CND_CONF}.mk src/hooks/CalcAttBonus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/hooks
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/hooks/CalcAttBonus.o src/hooks/CalcAttBonus.cpp

${OBJECTDIR}/src/hooks/CharacterConstructor.o: nbproject/Makefile-${CND_CONF}.mk src/hooks/CharacterConstructor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/hooks
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/hooks/CharacterConstructor.o src/hooks/CharacterConstructor.cpp

${OBJECTDIR}/src/hooks/DoWar.o: nbproject/Makefile-${CND_CONF}.mk src/hooks/DoWar.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/hooks
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/hooks/DoWar.o src/hooks/DoWar.cpp

${OBJECTDIR}/src/hooks/DropGold.o: nbproject/Makefile-${CND_CONF}.mk src/hooks/DropGold.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/hooks
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/hooks/DropGold.o src/hooks/DropGold.cpp

${OBJECTDIR}/src/hooks/GiveExp.o: nbproject/Makefile-${CND_CONF}.mk src/hooks/GiveExp.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/hooks
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/hooks/GiveExp.o src/hooks/GiveExp.cpp

${OBJECTDIR}/src/hooks/HorseApply.o: nbproject/Makefile-${CND_CONF}.mk src/hooks/HorseApply.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/hooks
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/hooks/HorseApply.o src/hooks/HorseApply.cpp

${OBJECTDIR}/src/hooks/HorseVnum.o: nbproject/Makefile-${CND_CONF}.mk src/hooks/HorseVnum.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/hooks
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/hooks/HorseVnum.o src/hooks/HorseVnum.cpp

${OBJECTDIR}/src/hooks/NumberEx.o: nbproject/Makefile-${CND_CONF}.mk src/hooks/NumberEx.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/hooks
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/hooks/NumberEx.o src/hooks/NumberEx.cpp

${OBJECTDIR}/src/hooks/PointChange.o: nbproject/Makefile-${CND_CONF}.mk src/hooks/PointChange.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/hooks
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/hooks/PointChange.o src/hooks/PointChange.cpp

${OBJECTDIR}/src/hooks/SyncPosition.o: nbproject/Makefile-${CND_CONF}.mk src/hooks/SyncPosition.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/hooks
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/hooks/SyncPosition.o src/hooks/SyncPosition.cpp

${OBJECTDIR}/src/hooks/UseItemEx.o: nbproject/Makefile-${CND_CONF}.mk src/hooks/UseItemEx.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/hooks
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/hooks/UseItemEx.o src/hooks/UseItemEx.cpp

${OBJECTDIR}/src/libm2/Command.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/Command.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/Command.o src/libm2/Command.cpp

${OBJECTDIR}/src/libm2/IQuest.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/IQuest.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/IQuest.o src/libm2/IQuest.cpp

${OBJECTDIR}/src/libm2/LibM2.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/LibM2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/LibM2.o src/libm2/LibM2.cpp

${OBJECTDIR}/src/libm2/game/CEntity.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CEntity.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CEntity.o src/libm2/game/CEntity.cpp

${OBJECTDIR}/src/libm2/game/CFSM.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CFSM.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CFSM.o src/libm2/game/CFSM.cpp

${OBJECTDIR}/src/libm2/game/CGuild.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CGuild.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CGuild.o src/libm2/game/CGuild.cpp

${OBJECTDIR}/src/libm2/game/CGuildManager.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CGuildManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CGuildManager.o src/libm2/game/CGuildManager.cpp

${OBJECTDIR}/src/libm2/game/CHARACTER.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CHARACTER.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CHARACTER.o src/libm2/game/CHARACTER.cpp

${OBJECTDIR}/src/libm2/game/CHARACTER_MANAGER.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CHARACTER_MANAGER.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CHARACTER_MANAGER.o src/libm2/game/CHARACTER_MANAGER.cpp

${OBJECTDIR}/src/libm2/game/CHorseRider.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CHorseRider.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CHorseRider.o src/libm2/game/CHorseRider.cpp

${OBJECTDIR}/src/libm2/game/CInputAuth.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CInputAuth.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CInputAuth.o src/libm2/game/CInputAuth.cpp

${OBJECTDIR}/src/libm2/game/CInputClose.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CInputClose.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CInputClose.o src/libm2/game/CInputClose.cpp

${OBJECTDIR}/src/libm2/game/CInputDB.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CInputDB.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CInputDB.o src/libm2/game/CInputDB.cpp

${OBJECTDIR}/src/libm2/game/CInputDead.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CInputDead.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CInputDead.o src/libm2/game/CInputDead.cpp

${OBJECTDIR}/src/libm2/game/CInputHandshake.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CInputHandshake.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CInputHandshake.o src/libm2/game/CInputHandshake.cpp

${OBJECTDIR}/src/libm2/game/CInputLogin.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CInputLogin.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CInputLogin.o src/libm2/game/CInputLogin.cpp

${OBJECTDIR}/src/libm2/game/CInputMain.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CInputMain.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CInputMain.o src/libm2/game/CInputMain.cpp

${OBJECTDIR}/src/libm2/game/CInputP2P.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CInputP2P.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CInputP2P.o src/libm2/game/CInputP2P.cpp

${OBJECTDIR}/src/libm2/game/CInputProcessor.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CInputProcessor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CInputProcessor.o src/libm2/game/CInputProcessor.cpp

${OBJECTDIR}/src/libm2/game/CItem.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CItem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CItem.o src/libm2/game/CItem.cpp

${OBJECTDIR}/src/libm2/game/CPetActor.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CPetActor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CPetActor.o src/libm2/game/CPetActor.cpp

${OBJECTDIR}/src/libm2/game/CPetSystem.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CPetSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CPetSystem.o src/libm2/game/CPetSystem.cpp

${OBJECTDIR}/src/libm2/game/CPrivManager.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CPrivManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CPrivManager.o src/libm2/game/CPrivManager.cpp

${OBJECTDIR}/src/libm2/game/CShopManager.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CShopManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CShopManager.o src/libm2/game/CShopManager.cpp

${OBJECTDIR}/src/libm2/game/CState.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CState.o src/libm2/game/CState.cpp

${OBJECTDIR}/src/libm2/game/CThreeWayWar.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/CThreeWayWar.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/CThreeWayWar.o src/libm2/game/CThreeWayWar.cpp

${OBJECTDIR}/src/libm2/game/DBManager.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/DBManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/DBManager.o src/libm2/game/DBManager.cpp

${OBJECTDIR}/src/libm2/game/DESC.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/DESC.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/DESC.o src/libm2/game/DESC.cpp

${OBJECTDIR}/src/libm2/game/DESC_MANAGER.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/DESC_MANAGER.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/DESC_MANAGER.o src/libm2/game/DESC_MANAGER.cpp

${OBJECTDIR}/src/libm2/game/EVENT.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/EVENT.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/EVENT.o src/libm2/game/EVENT.cpp

${OBJECTDIR}/src/libm2/game/ITEM_MANAGER.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/ITEM_MANAGER.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/ITEM_MANAGER.o src/libm2/game/ITEM_MANAGER.cpp

${OBJECTDIR}/src/libm2/game/LogManager.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/LogManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/LogManager.o src/libm2/game/LogManager.cpp

${OBJECTDIR}/src/libm2/game/P2P_MANAGER.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/P2P_MANAGER.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/P2P_MANAGER.o src/libm2/game/P2P_MANAGER.cpp

${OBJECTDIR}/src/libm2/game/SECTREE.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/SECTREE.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/SECTREE.o src/libm2/game/SECTREE.cpp

${OBJECTDIR}/src/libm2/game/SECTREE_MANAGER.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/SECTREE_MANAGER.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/SECTREE_MANAGER.o src/libm2/game/SECTREE_MANAGER.cpp

${OBJECTDIR}/src/libm2/game/SECTREE_MAP.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/SECTREE_MAP.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/SECTREE_MAP.o src/libm2/game/SECTREE_MAP.cpp

${OBJECTDIR}/src/libm2/game/SQLMsg.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/SQLMsg.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/SQLMsg.o src/libm2/game/SQLMsg.cpp

${OBJECTDIR}/src/libm2/game/SQLResult.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/SQLResult.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/SQLResult.o src/libm2/game/SQLResult.cpp

${OBJECTDIR}/src/libm2/game/TAffectFlag.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/TAffectFlag.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/TAffectFlag.o src/libm2/game/TAffectFlag.cpp

${OBJECTDIR}/src/libm2/game/TEMP_BUFFER.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/TEMP_BUFFER.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/TEMP_BUFFER.o src/libm2/game/TEMP_BUFFER.cpp

${OBJECTDIR}/src/libm2/game/VID.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/VID.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/VID.o src/libm2/game/VID.cpp

${OBJECTDIR}/src/libm2/game/building/CLand.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/building/CLand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game/building
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/building/CLand.o src/libm2/game/building/CLand.cpp

${OBJECTDIR}/src/libm2/game/building/CManager.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/building/CManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game/building
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/building/CManager.o src/libm2/game/building/CManager.cpp

${OBJECTDIR}/src/libm2/game/building/CObject.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/building/CObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game/building
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/building/CObject.o src/libm2/game/building/CObject.cpp

${OBJECTDIR}/src/libm2/game/global.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/global.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/global.o src/libm2/game/global.cpp

${OBJECTDIR}/src/libm2/game/lua.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/lua.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/lua.o src/libm2/game/lua.cpp

${OBJECTDIR}/src/libm2/game/marriage/CManager.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/marriage/CManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game/marriage
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/marriage/CManager.o src/libm2/game/marriage/CManager.cpp

${OBJECTDIR}/src/libm2/game/marriage/TMarriage.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/marriage/TMarriage.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game/marriage
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/marriage/TMarriage.o src/libm2/game/marriage/TMarriage.cpp

${OBJECTDIR}/src/libm2/game/misc.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/misc.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/misc.o src/libm2/game/misc.cpp

${OBJECTDIR}/src/libm2/game/quest/CQuestManager.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/quest/CQuestManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game/quest
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/quest/CQuestManager.o src/libm2/game/quest/CQuestManager.cpp

${OBJECTDIR}/src/libm2/game/quest/PC.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/game/quest/PC.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/game/quest
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/game/quest/PC.o src/libm2/game/quest/PC.cpp

${OBJECTDIR}/src/libm2/lib/dif.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/lib/dif.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/lib
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/lib/dif.o src/libm2/lib/dif.cpp

${OBJECTDIR}/src/libm2/lib/log.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/lib/log.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/lib
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/lib/log.o src/libm2/lib/log.cpp

${OBJECTDIR}/src/libm2/utils/hde/hde32.o: nbproject/Makefile-${CND_CONF}.mk src/libm2/utils/hde/hde32.c 
	${MKDIR} -p ${OBJECTDIR}/src/libm2/utils/hde
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/libm2/utils/hde/hde32.o src/libm2/utils/hde/hde32.c

${OBJECTDIR}/src/main.o: nbproject/Makefile-${CND_CONF}.mk src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/quest/item2.o: nbproject/Makefile-${CND_CONF}.mk src/quest/item2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/quest
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/quest/item2.o src/quest/item2.cpp

${OBJECTDIR}/src/quest/npc2.o: nbproject/Makefile-${CND_CONF}.mk src/quest/npc2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/quest
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/quest/npc2.o src/quest/npc2.cpp

${OBJECTDIR}/src/quest/pc2.o: nbproject/Makefile-${CND_CONF}.mk src/quest/pc2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/quest
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/quest/pc2.o src/quest/pc2.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgame.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
