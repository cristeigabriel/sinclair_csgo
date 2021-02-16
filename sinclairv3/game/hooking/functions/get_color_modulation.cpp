#include "../../game.h"

#include "../../../cstrike/cstrike.h"

void __fastcall game::hooking::functions::prototypes::get_color_modulation::hooked(REGISTERS_t(IMaterial*), float* r, float* g, float* b) {
	o_fn(thisptr, dummy, r, g, b);

	const uint32_t group_name = HASH_RT(thisptr->get_texture_group_name());
	if (group_name != HASH_CT(TEXTURE_GROUP_WORLD) && group_name != HASH_CT(TEXTURE_GROUP_STATIC_PROP) && group_name != HASH_CT(TEXTURE_GROUP_SKYBOX))
		return;

	*r *= 0.2f;
	*g *= 0.2f;
	*b *= 0.2f;
}