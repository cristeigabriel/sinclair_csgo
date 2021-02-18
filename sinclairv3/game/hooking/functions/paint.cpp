#include "../../game.h"

#include "../../../cstrike/cstrike.h"

void __fastcall game::hooking::functions::prototypes::paint::hooked(REGISTERS, PaintMode mode) {
	//	Engine VGui utilities
	const static start_drawing_t o_start_drawing = (start_drawing_t)pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_PAINT_START_DRAWING];
	const static finish_drawing_t o_finish_drawing = (finish_drawing_t)pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_PAINT_FINISH_DRAWING];

	int v3 = *(int*)thisptr /* a1 */;

	if (*(DWORD*)(v3 + 72) /* staticTransitionPanel */ && (mode & PaintMode::PAINT_UI_PANELS) != 0) {
		o_start_drawing(game::memory::interfaces::prototypes::surface);

		game::renderer::surface::set_color({ 155, 0, 0, 255 });
		game::renderer::surface::rectangle<game::renderer::surface::ColorPreservation::COLOR_PRESERVE>(15, 15, 100, 100);
		game::renderer::surface::rectangle_outline<game::renderer::surface::ColorPreservation::COLOR_CHANGE_AND_RESTORE>(15, 315, 100, 100, { 255, 0, 255, 255 });
		game::renderer::surface::rectangle<game::renderer::surface::ColorPreservation::COLOR_PRESERVE>(15, 615, 100, 100);

		o_finish_drawing(game::memory::interfaces::prototypes::surface);
	}

	o_fn(thisptr, dummy, mode);
}