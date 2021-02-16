#pragma once

#include "../../cstrike/defines.h"

#define PROTOTYPE_FUNCTION(function_name, function_prototype) \
struct function_name \
{ \
	using fn = function_prototype; \
	static fn hooked; \
	static fn* o_fn; \
}; \
inline function_name::fn* function_name::o_fn;

namespace game {
	namespace hooking {
		namespace functions {
			namespace prototypes {
				PROTOTYPE_FUNCTION
				(
					push_notice,
					void(__fastcall)(CCSGO_HudChat*, void*, const char*, int, const char*)
				);

				PROTOTYPE_FUNCTION
				(
					create_move,
					bool(__stdcall)(float, CUserCmd*)
				);

				PROTOTYPE_FUNCTION
				(
					frame_stage_notify,
					void(__stdcall)(ClientFrameStages)
				);

				PROTOTYPE_FUNCTION
				(
					get_current_game_type,
					int(__fastcall)(void*, void*)
				);

				PROTOTYPE_FUNCTION
				(
					get_color_modulation,
					void(__fastcall)(IMaterial*, void*, float*, float*, float*)
				);

				PROTOTYPE_FUNCTION
				(
					is_using_static_prop_debug_modes,
					bool(__cdecl)()
				);

				PROTOTYPE_FUNCTION
				(
					get_cs_wpn_data,
					const CCSWeaponData& (__fastcall)(void*, void*)
				);

				PROTOTYPE_FUNCTION
				(
					draw_crosshair,
					void(__fastcall)(void*, void*)
				);

				PROTOTYPE_FUNCTION
				(
					vsnprintf,
					int(__cdecl)(char*, int, const char*, ...)
				);

				PROTOTYPE_FUNCTION
				(
					send_net_msg,
					bool(__fastcall)(void*, void*, INetMessage&, bool, bool)
				);

				PROTOTYPE_FUNCTION
				(
					paint,
					void(__fastcall)(void*, void*, PaintMode)
				);
			}
		}
	}
}