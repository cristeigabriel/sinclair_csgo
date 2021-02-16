#include "../../game.h"

#include "../../../cstrike/cstrike.h"

void __fastcall game::hooking::functions::prototypes::get_color_modulation::hooked(REGISTERS, float* r, float* g, float* b) {
	return o_fn(thisptr, dummy, r, g, b);
}