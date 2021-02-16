#include "../../game.h"

#include "../../../cstrike/cstrike.h"

bool __stdcall game::hooking::functions::prototypes::create_move::hooked(float sample_time, CUserCmd* cmd) {
	if (cmd == nullptr || cmd->command_number == 0)
		return o_fn(sample_time, cmd);

	cmd->buttons |= CmdButtons::IN_BULLRUSH;

	return false;
}