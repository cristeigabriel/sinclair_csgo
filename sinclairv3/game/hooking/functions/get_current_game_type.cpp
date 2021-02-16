#include "../../game.h"

#include "../../../cstrike/cstrike.h"

int __fastcall game::hooking::functions::prototypes::get_current_game_type::hooked(REGISTERS) {
	//	Dangerzone index
	return 6;
}