#pragma once

#include "../../../cstrike/defines.h"

#include "../../entities/entities.h"

namespace game {
	namespace features {
		namespace visual {
			namespace util {
				bool compute_2d_bounding_box(game::entities::player_t* entity,
					math::point_4d_t<int>& out);
			}
	
			namespace esp {
				namespace paint {
					void the();
				}
			}
		}
	}
}