#include "../../game.h"

#include "../../../cstrike/cstrike.h"

//	We're hooking the CNetChan SendNetMsg to be able to skip protobufs
//	You can do something along these lines by hooking FileCRCCheck by CGameClient
//	but that'll only work in local games
bool __fastcall game::hooking::functions::prototypes::send_net_msg::hooked(REGISTERS,
	INetMessage& msg, bool voice, bool reliable) {
	if (msg.get_type() == ClcMessages::CLC_FIRE_CRC_CHECK) //	skip CNetMessagePB
		return false;

	return o_fn(thisptr, dummy, msg, voice, reliable);
}