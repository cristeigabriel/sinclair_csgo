#pragma once

#include "../../cstrike/defines.h"
#include "../props/props.h"

namespace game {
	namespace entities {
		struct player_t {
			int health();
			bool scoped();
		};
	}
}