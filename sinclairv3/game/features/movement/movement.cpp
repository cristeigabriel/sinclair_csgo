#include "movement.h"

#include "../../../cstrike/cstrike.h"

namespace game {
	namespace features {
		namespace movement {
			void bunny_hop(CUserCmd* cmd) {
				static uint8_t old_flags = game::entities::prototypes::local->flags();

				if (!(old_flags & PlayerFlags::FLAG_ONGROUND) &&
					!(game::entities::prototypes::local->flags() & PlayerFlags::FLAG_ONGROUND) &&
					!(game::entities::prototypes::local->movetype() & MoveTypes::MOVETYPE_LADDER))
					cmd->buttons &= ~CmdButtons::IN_JUMP;

				old_flags = game::entities::prototypes::local->flags();
			}
		}
	}
}