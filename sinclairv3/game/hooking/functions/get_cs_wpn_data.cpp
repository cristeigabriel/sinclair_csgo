#include "../../game.h"

#include "../../../cstrike/cstrike.h"

const CCSWeaponData& game::hooking::functions::prototypes::get_cs_wpn_data::hooked(REGISTERS) {
	//	planning to use this for cl_crosshairstyle 1 on snipers
	return o_fn(thisptr, dummy);
}