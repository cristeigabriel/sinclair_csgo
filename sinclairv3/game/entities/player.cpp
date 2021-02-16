#include "player.h"

#include "../props/props.h"

#include "../../cstrike/cstrike.h"

namespace game {
	namespace entities {
		int player_t::health() {
			return *(int*)((uintptr_t)this + game::props::prototypes::props[HASH_CT("DT_BasePlayer")][HASH_CT("m_iHealth")]);
		}

		bool player_t::scoped() {
			return *(bool*)((uintptr_t)this + game::props::prototypes::props[HASH_CT("DT_CSPlayer")][HASH_CT("m_bIsScoped")]);
		}
	}
}
