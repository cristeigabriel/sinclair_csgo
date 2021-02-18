#pragma once

#include "../../../cstrike/defines.h"
#include "../../../math/math.h"
#include "../../props/props.h"

namespace game {
	namespace entities {
		struct player_t {
			bool alive();
			int health();
			uint8_t lifestate();
			uint8_t team();
			uint8_t flags();
			uint8_t movetype();
			bool scoped();
			math::point_3d_t<float> origin();
			bool compute_hitbox_surrounding_box(math::point_3d_t<float>* mins, math::point_3d_t<float>* maxs);
		};
	}
}