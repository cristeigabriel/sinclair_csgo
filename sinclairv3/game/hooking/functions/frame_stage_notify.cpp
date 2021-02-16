#include "../../game.h"

#include "../../../cstrike/cstrike.h"

void __stdcall game::hooking::functions::prototypes::frame_stage_notify::hooked(ClientFrameStages stage) {
	switch (stage) {
	case ClientFrameStages::NET_UPDATE_POSTDATAUPDATE_END:
		//	I could sig the entity that is set to local in FSN but that caused some issues which I don't care enough to bother with
		//	so I'll just update local myself where the game does it too
		game::entities::prototypes::local = game::memory::interfaces::prototypes::entity_list->get<game::entities::player_t*>(game::memory::interfaces::prototypes::engine_client->get_local_player());

		break;
	}

	return o_fn(stage);
}