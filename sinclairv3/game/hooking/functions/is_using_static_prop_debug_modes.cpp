#include "../../game.h"

#include "../../../cstrike/cstrike.h"

bool __cdecl game::hooking::functions::prototypes::is_using_static_prop_debug_modes::hooked() {
	return o_fn();
}