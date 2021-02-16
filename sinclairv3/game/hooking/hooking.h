#pragma once

#include "../memory/memory.h"

#include "prototypes.h"

#include <intrin.h>

namespace game {
	namespace hooking {
		namespace init {
			static bool have_values_been_initialized = false;
			bool the();
		}

		namespace detach {
			void the();
		}

		namespace types {
			typedef bool(__cdecl* game_overlay_renderer_hook_t)(void*, void*, void*, int);
			typedef void(__cdecl* game_overlay_renderer_unhook_t)(void*, bool);
		}

		namespace prototypes {
			extern game::hooking::types::game_overlay_renderer_hook_t o_hook;
			extern game::hooking::types::game_overlay_renderer_unhook_t o_unhook;
		}

		template <typename T>
		inline bool apply_hook(void* address) {
			assert(game::hooking::init::have_values_been_initialized);

			logger::the<logger::level::log>("%s: Applying hook at \"address\" (0x%X)\n", __FUNCTION__, address);
			return game::hooking::prototypes::o_hook(address, T::hooked, &T::o_fn, 0);
		}

		inline void remove_hook(void* address) {
			assert(game::hooking::init::have_values_been_initialized);

			logger::the<logger::level::log>("%s: Removing hook at \"address\" (0x%X)\n", __FUNCTION__, address);
			game::hooking::prototypes::o_unhook(address, false);
		}
	}
}