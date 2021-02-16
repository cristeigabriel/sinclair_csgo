#pragma once

#include "../../pe/pe.h"
#include "../../pe/util/util.h"

#include "../../util/util.h"

#include "../../cstrike/defines.h"

namespace game {
	namespace memory {
		namespace interfaces {
			namespace init {
				bool the();
			}

			namespace getter {
				template <typename T, pe::util::memory::exports::types::create_interface_t(&interface_exports_map)[pe::Images::IMAGES_LIST_SIZE], pe::Images index, size_t N>
				inline T the(const char(&name)[N]) {
					//	If this exists then the map itself is also valid
					assert(interface_exports_map[index]);

					//  Get factory export address from map
					const T result = (T)interface_exports_map[index](name, 0);

					if (result == nullptr) {
						logger::the<logger::level::error>("%s: \"result\" (interface_fn(\"%s\", 0)) was nullptr, returning\n", __FUNCTION__, name);
						SINCLAIR_THROW(errors::Errors::GAME_MEMORY_EXPORT_WAS_NULL);
						return nullptr;
					}

					logger::the<logger::level::log>("%s: Found \"result\" (%s) at 0x%X\n", __FUNCTION__, name, result);
					return result;
				}
			}

			namespace prototypes {
				extern pe::util::memory::exports::types::create_interface_t interface_exports[pe::Images::IMAGES_LIST_SIZE];

				extern IBaseClientDLL* base_client;
				extern CHLClient* client_mode_shared;
				extern CGlobalVarsBase* global_vars;
				extern IVEngineClient* engine_client;
				extern IClientEntityList* entity_list;
				extern IEngineTraceClient* engine_trace;
				extern ISurface* surface;
				extern ICVar* cvar_system;
				extern IInputSystem* input_system;
				extern CModelInfo* model_info;
			}
		}
	}
}