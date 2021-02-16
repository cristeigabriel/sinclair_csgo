#include "memory.h"

#include "../../cstrike/cstrike.h"

//  Prototypes
pe::util::memory::exports::types::create_interface_t game::memory::interfaces::prototypes::interface_exports[pe::Images::IMAGES_LIST_SIZE];

IBaseClientDLL* game::memory::interfaces::prototypes::base_client;
CHLClient* game::memory::interfaces::prototypes::client_mode_shared;
CGlobalVarsBase* game::memory::interfaces::prototypes::global_vars;
IVEngineClient* game::memory::interfaces::prototypes::engine_client;
IClientEntityList* game::memory::interfaces::prototypes::entity_list;
IEngineTraceClient* game::memory::interfaces::prototypes::engine_trace;
ISurface* game::memory::interfaces::prototypes::surface;
ICVar* game::memory::interfaces::prototypes::cvar_system;
IInputSystem* game::memory::interfaces::prototypes::input_system;
CModelInfo* game::memory::interfaces::prototypes::model_info;

namespace game {
	namespace memory {
		namespace interfaces {
			//  declare initializer
			namespace init {
				bool the() {
					game::memory::interfaces::prototypes::interface_exports[pe::Images::IMAGE_CLIENT] =
						pe::util::memory::exports::getter::the<pe::util::memory::exports::types::create_interface_t>(pe::prototypes::images[pe::Images::IMAGE_CLIENT], "CreateInterface");

					game::memory::interfaces::prototypes::interface_exports[pe::Images::IMAGE_ENGINE] =
						pe::util::memory::exports::getter::the<pe::util::memory::exports::types::create_interface_t>(pe::prototypes::images[pe::Images::IMAGE_ENGINE], "CreateInterface");

					game::memory::interfaces::prototypes::interface_exports[pe::Images::IMAGE_INPUT_SYSTEM] =
						pe::util::memory::exports::getter::the<pe::util::memory::exports::types::create_interface_t>(pe::prototypes::images[pe::Images::IMAGE_INPUT_SYSTEM], "CreateInterface");

					game::memory::interfaces::prototypes::interface_exports[pe::Images::IMAGE_VGUI_MAT_SURFACE] =
						pe::util::memory::exports::getter::the<pe::util::memory::exports::types::create_interface_t>(pe::prototypes::images[pe::Images::IMAGE_VGUI_MAT_SURFACE], "CreateInterface");

					game::memory::interfaces::prototypes::interface_exports[pe::Images::IMAGE_VSTDLIB] =
						pe::util::memory::exports::getter::the<pe::util::memory::exports::types::create_interface_t>(pe::prototypes::images[pe::Images::IMAGE_VSTDLIB], "CreateInterface");

					game::memory::interfaces::prototypes::base_client = game::memory::interfaces::getter::the<IBaseClientDLL*, game::memory::interfaces::prototypes::interface_exports, pe::Images::IMAGE_CLIENT>("VClient018");

					if (game::memory::interfaces::prototypes::base_client == nullptr) {
						logger::the<logger::level::error>("%s: \"base_client\" was nullptr\n", __FUNCTION__);
						SINCLAIR_THROW(errors::Errors::GAME_MEMORY_INTERFACE_WAS_NULL);
						return false;
					}

					game::memory::interfaces::prototypes::client_mode_shared = **util::vtable::getter::the<CHLClient***, 10, 5>(game::memory::interfaces::prototypes::base_client);

					if (game::memory::interfaces::prototypes::client_mode_shared == nullptr) {
						logger::the<logger::level::error>("%s: \"client_mode_shared\" was nullptr\n", __FUNCTION__);
						SINCLAIR_THROW(errors::Errors::GAME_MEMORY_INTERFACE_WAS_NULL);
						return false;
					}

					logger::the<logger::level::log>("%s: Found \"client_mode_shared\" (0x%X)\n", __FUNCTION__, game::memory::interfaces::prototypes::client_mode_shared);

					game::memory::interfaces::prototypes::global_vars = **util::vtable::getter::the<CGlobalVarsBase***, 11, 10>(game::memory::interfaces::prototypes::base_client);

					if (game::memory::interfaces::prototypes::global_vars == nullptr) {
						logger::the<logger::level::error>("%s: \"global_vars\" was nullptr\n", __FUNCTION__);
						SINCLAIR_THROW(errors::Errors::GAME_MEMORY_INTERFACE_WAS_NULL);
						return false;
					}

					logger::the<logger::level::log>("%s: Found \"global_vars\" (0x%X)\n", __FUNCTION__, game::memory::interfaces::prototypes::global_vars);

					game::memory::interfaces::prototypes::engine_client = game::memory::interfaces::getter::the<IVEngineClient*, game::memory::interfaces::prototypes::interface_exports, pe::Images::IMAGE_ENGINE>("VEngineClient014");

					if (game::memory::interfaces::prototypes::engine_client == nullptr) {
						logger::the<logger::level::error>("%s: \"engine_client\" was nullptr\n", __FUNCTION__);
						SINCLAIR_THROW(errors::Errors::GAME_MEMORY_INTERFACE_WAS_NULL);
						return false;
					}

					game::memory::interfaces::prototypes::entity_list = game::memory::interfaces::getter::the<IClientEntityList*, game::memory::interfaces::prototypes::interface_exports, pe::Images::IMAGE_CLIENT>("VClientEntityList003");

					if (game::memory::interfaces::prototypes::entity_list == nullptr) {
						logger::the<logger::level::error>("%s: \"entity_list\" was nullptr\n", __FUNCTION__);
						SINCLAIR_THROW(errors::Errors::GAME_MEMORY_INTERFACE_WAS_NULL);
						return false;
					}

					game::memory::interfaces::prototypes::engine_trace = game::memory::interfaces::getter::the<IEngineTraceClient*, game::memory::interfaces::prototypes::interface_exports, pe::Images::IMAGE_ENGINE>("EngineTraceClient004");

					if (game::memory::interfaces::prototypes::engine_trace == nullptr) {
						logger::the<logger::level::error>("%s: \"engine_trace\" was nullptr\n", __FUNCTION__);
						SINCLAIR_THROW(errors::Errors::GAME_MEMORY_INTERFACE_WAS_NULL);
						return false;
					}

					game::memory::interfaces::prototypes::surface = game::memory::interfaces::getter::the<ISurface*, game::memory::interfaces::prototypes::interface_exports, pe::Images::IMAGE_VGUI_MAT_SURFACE>("VGUI_Surface031");

					if (game::memory::interfaces::prototypes::surface == nullptr) {
						logger::the<logger::level::error>("%s: \"surface\" was nullptr\n", __FUNCTION__);
						SINCLAIR_THROW(errors::Errors::GAME_MEMORY_INTERFACE_WAS_NULL);
						return false;
					}

					game::memory::interfaces::prototypes::cvar_system = game::memory::interfaces::getter::the<ICVar*, game::memory::interfaces::prototypes::interface_exports, pe::Images::IMAGE_VSTDLIB>("VEngineCvar007");

					if (game::memory::interfaces::prototypes::cvar_system == nullptr) {
						logger::the<logger::level::error>("%s: \"cvar_system\" was nullptr\n", __FUNCTION__);
						SINCLAIR_THROW(errors::Errors::GAME_MEMORY_INTERFACE_WAS_NULL);
						return false;
					}

					game::memory::interfaces::prototypes::input_system = game::memory::interfaces::getter::the<IInputSystem*, game::memory::interfaces::prototypes::interface_exports, pe::Images::IMAGE_INPUT_SYSTEM>("InputSystemVersion001");

					if (game::memory::interfaces::prototypes::input_system == nullptr) {
						logger::the<logger::level::error>("%s: \"input_system\" was nullptr\n", __FUNCTION__);
						SINCLAIR_THROW(errors::Errors::GAME_MEMORY_INTERFACE_WAS_NULL);
						return false;
					}

					game::memory::interfaces::prototypes::model_info = game::memory::interfaces::getter::the<CModelInfo*, game::memory::interfaces::prototypes::interface_exports, pe::Images::IMAGE_ENGINE>("VModelInfoClient004");

					if (game::memory::interfaces::prototypes::model_info == nullptr) {
						logger::the<logger::level::log>("%s: \"model_info\" was nullptr\n", __FUNCTION__);
						SINCLAIR_THROW(errors::Errors::GAME_MEMORY_INTERFACE_WAS_NULL);
						return false;
					}

					logger::the<logger::level::log>("%s: Initialized\n", __FUNCTION__);
					return true;
				}
			}
		}
	}
}