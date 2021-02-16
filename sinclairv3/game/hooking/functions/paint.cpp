#include "../../game.h"

#include "../../../cstrike/cstrike.h"

void __fastcall game::hooking::functions::prototypes::paint::hooked(REGISTERS, PaintMode mode) {
	//	Engine VGui utilities
	const static start_drawing_t o_start_drawing = (start_drawing_t)pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_PAINT_START_DRAWING];
	const static finish_drawing_t o_finish_drawing = (finish_drawing_t)pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_PAINT_FINISH_DRAWING];

	int v3 = *(int*)thisptr /* a1 */;

	if (*(DWORD*)(v3 + 72) /* staticTransitionPanel */ && (mode & PaintMode::PAINT_UI_PANELS) != 0) {
		o_start_drawing(game::memory::interfaces::prototypes::surface);

		//game::memory::interfaces::prototypes::surface->draw_set_color(255, 255, 255, 255);
		//game::memory::interfaces::prototypes::surface->draw_outlined_rectangle(15, 15, 200, 200);
		//game::memory::interfaces::prototypes::surface->draw_line(15, 900, 45, 905);
		//game::memory::interfaces::prototypes::surface->draw_set_color(255, 255, 255, 255);
		//game::memory::interfaces::prototypes::surface->draw_outlined_rectangle(555, 15, 200, 200);

		o_finish_drawing(game::memory::interfaces::prototypes::surface);
	}

	o_fn(thisptr, dummy, mode);
}