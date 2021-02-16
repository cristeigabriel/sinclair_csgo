#include "../../game.h"

#include "../../../cstrike/cstrike.h"

void __fastcall game::hooking::functions::prototypes::push_notice::hooked(REGISTERS_t(CCSGO_HudChat*),
	const char* text, int text_len, const char* always_null) {
	return o_fn(thisptr, dummy, text, text_len, always_null);
}