#include "movement.h"

#include "../../../cstrike/cstrike.h"

namespace game {
	namespace features {
		namespace movement {
			void bunny_hop(CUserCmd* cmd) {
				if (!(game::entities::prototypes::local->flags() & PlayerFlags::FLAG_ONGROUND) &&
					!(game::entities::prototypes::local->movetype() & MoveTypes::MOVETYPE_LADDER))
					cmd->buttons &= ~CmdButtons::IN_JUMP;
			}
		}
	}
}