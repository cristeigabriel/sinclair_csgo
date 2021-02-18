#include "player.h"

#include "../props/props.h"

#include "../../cstrike/cstrike.h"

namespace game {
	namespace entities {
		bool player_t::alive() {
			return health() > 0 && lifestate() == LifeStates::LIFE_ALIVE;
		}

		int player_t::health() {
			return *(int*)((uintptr_t)this + game::props::prototypes::props[HASH_CT("DT_BasePlayer")][HASH_CT("m_iHealth")]);
		}

		uint8_t player_t::lifestate() {
			return *(uint8_t*)((uintptr_t)this + game::props::prototypes::props[HASH_CT("DT_BasePlayer")][HASH_CT("m_lifeState")]);
		}

		uint8_t player_t::team() {
			return *(uint8_t*)((uintptr_t)this + game::props::prototypes::props[HASH_CT("DT_BasePlayer")][HASH_CT("m_iTeamNum")]);
		}

		uint8_t player_t::flags() {
			return *(uint8_t*)((uintptr_t)this + game::props::prototypes::props[HASH_CT("DT_BasePlayer")][HASH_CT("m_fFlags")]);
		}

		uint8_t player_t::movetype() {
			return *(uint8_t*)((uintptr_t)this + (game::props::prototypes::props[HASH_CT("DT_BaseEntity")][HASH_CT("m_nRenderMode")] + 1));
		}

		bool player_t::scoped() {
			return *(bool*)((uintptr_t)this + game::props::prototypes::props[HASH_CT("DT_CSPlayer")][HASH_CT("m_bIsScoped")]);
		}

		math::point_3d_t<float> player_t::origin() {
			return *(math::point_3d_t<float>*)((uintptr_t)this + game::props::prototypes::props[HASH_CT("DT_BasePlayer")][HASH_CT("m_vecViewOffset[0]")]);
		}

		bool player_t::compute_hitbox_surrounding_box(math::point_3d_t<float>* mins, math::point_3d_t<float>* maxs) {
			typedef bool(__thiscall* compute_hitbox_surrounding_box_t)(player_t*, math::point_3d_t<float>*, math::point_3d_t<float>*);
			static compute_hitbox_surrounding_box_t compute_hitbox_surrounding_box_o = (compute_hitbox_surrounding_box_t)pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GET_ENTITY_BOUNDING_BOX];
			return compute_hitbox_surrounding_box_o(this, mins, maxs);
		}
	}
}
