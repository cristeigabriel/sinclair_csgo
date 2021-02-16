#include "../../game.h"

#include "../../../cstrike/cstrike.h"

void __fastcall game::hooking::functions::prototypes::draw_crosshair::hooked(REGISTERS) {
	//	As we currently byte patch on entry point, what we are doing, as I said before,
	//	is patching a comparassion's second argument to something that's not even available
	//	thus never failing

	//	[by not failing, I mean, it never returns, we always proceed with rendering, clarifying
	//	due to different code within the actual source itself and compiled output]

	//	the check. That, though, will cause for our crosshair to render while we are scoped, so my
	//	approach is, don't render the crosshair if you're scoped. This won't cause any issues,
	//	as you shouldn't ever see your crosshair within scope, or with a scopable weapon eitherway
	if (game::entities::prototypes::local->scoped())
		return;

	o_fn(thisptr, dummy);
}