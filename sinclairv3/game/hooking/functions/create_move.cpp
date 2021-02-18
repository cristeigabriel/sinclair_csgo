#include "../../game.h"

#include "../../../cstrike/cstrike.h"

bool __stdcall game::hooking::functions::prototypes::create_move::hooked(float sample_time, CUserCmd* cmd) {
	if (game::entities::prototypes::local == nullptr ||
		!game::entities::prototypes::local->alive() ||
		cmd == nullptr ||
		cmd->command_number == 0)
		return o_fn(sample_time, cmd);

	cmd->buttons |= CmdButtons::IN_BULLRUSH;

	game::features::movement::bunny_hop(cmd);

	cmd->view_angles.cstrike_clamp();
	cmd->view_angles.cstrike_normalize();

	return false;
}