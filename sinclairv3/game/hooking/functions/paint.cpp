#include "../../game.h"

#include "../../../cstrike/cstrike.h"

void __fastcall game::hooking::functions::prototypes::paint::hooked(REGISTERS, PaintMode mode) {
	int v3 = *(int*)thisptr /* a1 */;

	if (*(DWORD*)(v3 + 72) /* staticTransitionPanel */ && (mode & PaintMode::PAINT_UI_PANELS) != 0) {
		game::memory::interfaces::prototypes::surface->start_drawing();


		game::memory::interfaces::prototypes::surface->finish_drawing();
	}

	return o_fn(thisptr, dummy, mode);
}