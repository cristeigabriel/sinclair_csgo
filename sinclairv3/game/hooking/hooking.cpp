#include "hooking.h"

#include "../../util/util.h"

#include "../../cstrike/cstrike.h"

//  Prototypes
game::hooking::types::game_overlay_renderer_hook_t game::hooking::prototypes::o_hook;
game::hooking::types::game_overlay_renderer_unhook_t game::hooking::prototypes::o_unhook;

namespace game {
	namespace hooking {
		//  declare initialization
		namespace init {
			bool the() {
				game::hooking::prototypes::o_hook = (game::hooking::types::game_overlay_renderer_hook_t)pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GAME_OVERAY_RENDERER_HOOKING];

				if (game::hooking::prototypes::o_hook == nullptr) {
					logger::the<logger::level::error>("%s: \"o_hook\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				game::hooking::prototypes::o_unhook = (game::hooking::types::game_overlay_renderer_unhook_t)pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GAME_OVERAY_RENDERER_UNHOOKING];

				if (game::hooking::prototypes::o_unhook == nullptr) {
					logger::the<logger::level::error>("%s: \"o_unhook\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				game::hooking::init::have_values_been_initialized = true;

				if (!game::hooking::apply_hook<game::hooking::functions::prototypes::paint>(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_PAINT])) {
					logger::the<logger::level::error>("%s: Failed at hooking address \"ADDRESS_PAINT\"\n", __FUNCTION__);
					return false;
				}

				if (!game::hooking::apply_hook<game::hooking::functions::prototypes::send_net_msg>(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_SEND_NET_MSG])) {
					logger::the<logger::level::error>("%s: Failed at hooking address \"ADDRESS_SEND_NET_MSG\"\n", __FUNCTION__);
					return false;
				}

				if (!game::hooking::apply_hook<game::hooking::functions::prototypes::vsnprintf>(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_NET_GRAPH_TEXT_FORMATTER])) {
					logger::the<logger::level::error>("%s: Failed at hooking address \"ADDRESS_NET_GRAPH_TEXT_FORMATTER\"\n", __FUNCTION__);
					return false;
				}

				if (!game::hooking::apply_hook<game::hooking::functions::prototypes::draw_crosshair>(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_DRAW_CROSSHAIR])) {
					logger::the<logger::level::error>("%s: Failed at hooking address \"ADDRESS_DRAW_CROSSHAIR\"\n", __FUNCTION__);
					return false;
				}

				if (!game::hooking::apply_hook<game::hooking::functions::prototypes::get_cs_wpn_data>(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GET_CS_WPN_DATA])) {
					logger::the<logger::level::error>("%s: Failed at hooking address \"ADDRESS_GET_CS_WPN_DATA\"\n", __FUNCTION__);
					return false;
				}

				if (!game::hooking::apply_hook<game::hooking::functions::prototypes::push_notice>(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_PUSH_NOTICE])) {
					logger::the<logger::level::error>("%s: Failed at hooking address \"ADDRESS_PUSH_NOTICE\"\n", __FUNCTION__);
					return false;
				}

				if (!game::hooking::apply_hook<game::hooking::functions::prototypes::create_move>(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_CREATE_MOVE])) {
					logger::the<logger::level::error>("%s: Failed at hooking address \"ADDRESS_CREATE_MOVE\"\n", __FUNCTION__);
					return false;
				}

				if (!game::hooking::apply_hook<game::hooking::functions::prototypes::frame_stage_notify>(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_FRAME_STAGE_NOTIFY])) {
					logger::the<logger::level::error>("%s: Failed at hooking address \"ADDRESS_FRAME_STAGE_NOTIFY\"\n", __FUNCTION__);
					return false;
				}

				if (!game::hooking::apply_hook<game::hooking::functions::prototypes::get_current_game_type>(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GET_CURRENT_GAME_TYPE])) {
					logger::the<logger::level::error>("%s: Failed at hooking address \"ADDRESS_GET_CURRENT_GAME_TYPE\"\n", __FUNCTION__);
					return false;
				}

				if (!game::hooking::apply_hook<game::hooking::functions::prototypes::get_color_modulation>(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GET_COLOR_MODULATION])) {
					logger::the<logger::level::error>("%s: Failed at hooking address \"ADDRESS_GET_COLOR_MODULATION\"\n", __FUNCTION__);
					return false;
				}

				if (!game::hooking::apply_hook<game::hooking::functions::prototypes::is_using_static_prop_debug_modes>(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_IS_USING_STATIC_PROP_DEBUG_MODES])) {
					logger::the<logger::level::error>("%s: Failed at hooking address \"ADDRESS_IS_USING_STATIC_PROP_DEBUG_MODES\"\n", __FUNCTION__);
					return false;
				}

				logger::the<logger::level::log>("%s: Initialized\n", __FUNCTION__);
				return true;
			}
		}

		//  declare detachment
		namespace detach {
			void the() {
				game::hooking::remove_hook(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_PAINT]);
				game::hooking::remove_hook(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_SEND_NET_MSG]);
				game::hooking::remove_hook(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_NET_GRAPH_TEXT_FORMATTER]);
				game::hooking::remove_hook(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_DRAW_CROSSHAIR]);
				game::hooking::remove_hook(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GET_CS_WPN_DATA]);
				game::hooking::remove_hook(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_PUSH_NOTICE]);
				game::hooking::remove_hook(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_CREATE_MOVE]);
				game::hooking::remove_hook(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_FRAME_STAGE_NOTIFY]);
				game::hooking::remove_hook(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GET_CURRENT_GAME_TYPE]);
				game::hooking::remove_hook(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GET_COLOR_MODULATION]);
				game::hooking::remove_hook(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_IS_USING_STATIC_PROP_DEBUG_MODES]);

				logger::the<logger::level::log>("%s: Detached\n", __FUNCTION__);
			}
		}
	}
}