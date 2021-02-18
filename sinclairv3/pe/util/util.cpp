#include "util.h"

#include "../../cstrike/enums.h"

//  Prototypes
pe::util::types::byte_ptr pe::util::prototypes::static_addresses[pe::util::StaticAddresses::STATIC_ADDRESSES_LIST_SIZE];

namespace pe {
	namespace util {
		//  declare initializer
		namespace init {
			bool the() {
				//  83 3D ? ? ? ? ? 56 8B F1 0F 84 ? ? ? ? 8B 0D ? ? ? ? 8B 01 FF 50 20 83 F8 06 0F 85 ? ? ? ? 
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GET_CURRENT_GAME_TYPE] =
					pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_CLIENT>({ 0x83, 0x3D, -1, -1, -1, -1, -1, 0x56, 0x8B, 0xF1, 0x0F, 0x84, -1, -1, -1, -1, 0x8B, 0x0D, -1, -1, -1, -1, 0x8B, 0x01, 0xFF, 0x50, 0x20,
						0x83, 0xF8, 0x06, 0x0F, 0x85, -1, -1, -1, -1 });

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GET_CURRENT_GAME_TYPE] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_GET_CURRENT_GAME_TYPE\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				//  #STR: "Couldn't get trampoline region lock, will continue possibl
				//  E8 ? ? ? ? 83 C4 10 EB 21
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GAME_OVERAY_RENDERER_HOOKING] =
					pe::util::memory::patterns::util::relative_to_absolute(
						pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_GAME_OVERLAY_RENDERER>({ 0xE8, -1, -1, -1, -1, 0x83, 0xC4, 0x10, 0xEB, 0x21 }) + 1);

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GAME_OVERAY_RENDERER_HOOKING] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_GAME_OVERAY_RENDERER_HOOKING\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				//  #STR: "Aborting UnhookFunc because pRealFunctionAddr is null\n", "Aborting UnhookFunc because pRealFunctionAddr is not hooke, "System page siz
				//  E8 ? ? ? ? 83 C4 08 FF 15 ? ? ? ?
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GAME_OVERAY_RENDERER_UNHOOKING] =
					pe::util::memory::patterns::util::relative_to_absolute(
						pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_GAME_OVERLAY_RENDERER>({ 0xE8, -1, -1, -1, -1, 0x83, 0xC4, 0x08, 0xFF, 0x15, -1, -1, -1, -1 }) + 1);

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GAME_OVERAY_RENDERER_UNHOOKING] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_GAME_OVERAY_RENDERER_UNHOOKING\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				//  #STR: "Weapon '%s' script file not found, but its data was access, "%s (%d) : %s\n", "<unknown>", "..\\shared\\cstrike15\\weapon_csbase.cpp"
				//  55 8B EC 81 EC 0C 01 ? ? 53 8B D9 56 57 8D 8B
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GET_CS_WPN_DATA] =
					pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_CLIENT>({ 0x55, 0x8B, 0xEC, 0x81, 0xEC, 0x0C, 0x01, -1, -1, 0x53, 0x8B, 0xD9, 0x56, 0x57, 0x8D, 0x8B });

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GET_CS_WPN_DATA] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_GET_CS_WPN_DATA\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				//	55 8B EC 83 E4 F8 81 EC ? ? ? ? 53 56 8B F1 57 83 BE ? ? ? ? ? 75 14 8B 46 04 8D 4E 04 FF 50 20
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GET_ENTITY_BOUNDING_BOX] =
					pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_CLIENT>({ 0x55, 0x8B, 0xEC, 0x83, 0xE4, 0xF8, 0x81, 0xEC, -1, -1, -1, -1, 0x53, 0x56, 0x8B, 0xF1, 0x57, 0x83, 0xBE, -1, -1, -1, -1, -1, 0x75, 0x14, 0x8B, 0x46, 0x04, 0x8D, 0x4E, 0x04, 0xFF, 0x50, 0x20 });

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GET_ENTITY_BOUNDING_BOX] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_GET_ENTITY_BOUNDING_BOX\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				//  #STR: "Inaccuracy =\t%f\tSpread =\t%f\tSpreadDistance =\t%f\tPlay, "whiteAdditive"
				//  55 8B EC 83 E4 F0 83 EC 78 56 8B F1 8B 0D ? ? ? ?
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_DRAW_CROSSHAIR] =
					pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_CLIENT>({ 0x55, 0x8B, 0xEC, 0x83, 0xE4, 0xF0, 0x83, 0xEC, 0x78, 0x56, 0x8B, 0xF1, 0x8B, 0x0D, -1, -1, -1, -1 });

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_DRAW_CROSSHAIR] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_DRAW_CROSSHAIR\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				//  Inside DrawCrosshair so the reference strings also stand here
				//  FF D0                             call    eax
				//  83 F8 05                          cmp     eax, 5; if getcswpndata.type != sniper_rifle
				//  ------------------------------------------------
				//  (FF D0 83 F8) 05 75 17 A1 ? ? ? ? B9 ? ? ? ? 8B 40 34 FF D0 85 C0
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_CMP_FORCE_CROSSHAIR] =
					pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_CLIENT>({ 0x05, 0x75, 0x17, 0xA1, -1, -1, -1, -1, 0xB9, -1, -1, -1, -1, 0x8B, 0x40, 0x34, 0xFF, 0xD0, 0x85, 0xC0, 0x0F, 0x84, -1, -1, -1, -1, 0xE8, -1, -1, -1, -1, 0x99 });

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_CMP_FORCE_CROSSHAIR] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_CMP_FORCE_CROSSHAIR\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				//  55 8B EC 51 56 8B 75 0C 8D 45 14 57 8B 7D 08 8B D6 50 51 FF 75 10 8B CF E8 ? ? ? ? 83 C4 0C 85 C0 78 08 85 F6 7E 0C 3B C6 7C 08 8D 46 FF
				//  in Cheat Engine or IDA, look for fps:
				//  and you'll find the formatter immediately
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_NET_GRAPH_TEXT_FORMATTER] =
					pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_CLIENT>({ 0x55, 0x8B, 0xEC, 0x51, 0x56, 0x8B, 0x75, 0x0C, 0x8D, 0x45, 0x14, 0x57, 0x8B, 0x7D, 0x08, 0x8B, 0xD6, 0x50, 0x51, 0xFF, 0x75, 0x10, 0x8B, 0xCF, 0xE8, -1, -1, -1, -1, 0x83, 0xC4, 0x0C, 0x85, 0xC0, 0x78, 0x08, 0x85, 0xF6, 0x7E, 0x0C, 0x3B, 0xC6, 0x7C, 0x08, 0x8D, 0x46, 0xFF });

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_NET_GRAPH_TEXT_FORMATTER] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_NET_GRAPH_TEXT_FORMATTER\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				//  (int)"fps: %5i var: %4.1f ms (v%u%s)",
				//  E8 ? ? ? ? 8B 87 ? ? ? ? 8D 8C 24 ? ? ? ? 51 8B 15 ? ? ? ? 8B C8 68 ? ? ? ? C1 E9 18 51 8B 32 8B C8 C1 E9 10 0F B6 C9 51 8B C8 0F B6 C0 C1 E9 08 0F B6 C9 51 50 8B 87 ? ? ? ? 03 45 10 50
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_NET_GRAPH_TEXT_MAIN_MENU_RET_ADDR] =
					pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_CLIENT>({ 0xE8, -1, -1, -1, -1, 0x8B, 0x87, -1, -1, -1, -1, 0x8D, 0x8C, 0x24, -1, -1, -1, -1, 0x51, 0x8B, 0x15, -1, -1, -1, -1, 0x8B, 0xC8, 0x68, -1, -1, -1, -1, 0xC1, 0xE9, 0x18, 0x51, 0x8B, 0x32, 0x8B, 0xC8, 0xC1, 0xE9, 0x10, 0x0F, 0xB6, 0xC9, 0x51, 0x8B, 0xC8, 0x0F, 0xB6, 0xC0, 0xC1, 0xE9, 0x08, 0x0F, 0xB6, 0xC9, 0x51, 0x50, 0x8B, 0x87, -1, -1, -1, -1, 0x03, 0x45, 0x10, 0x50 }) + 5;

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_NET_GRAPH_TEXT_MAIN_MENU_RET_ADDR] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_NET_GRAPH_TEXT_MAIN_MENU_RET_ADDR\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				//  (int)"fps: %5i var: %4.1f ms (v%u%s)"
				//  E8 ? ? ? ? 8B 87 ? ? ? ? 8D 8C 24 ? ? ? ? 83 C4 1C 8B 15 ? ? ? ? 51 68 ? ? ? ? 8B 32 8B C8 C1 E9 18 51 8B C8 C1 E9 10 0F B6 C9 51 8B C8 0F B6 C0 C1 E9 08 0F B6 C9 51 50 FF 75 10 FF 75 0C FF 74 24 34 
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_NET_GRAPH_TEXT_GAME_RET_ADDR] =
					pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_CLIENT>({ 0xE8, -1, -1, -1, -1, 0x8B, 0x87, -1, -1, -1, -1, 0x8D, 0x8C, 0x24, -1, -1, -1, -1, 0x83, 0xC4, 0x1C, 0x8B, 0x15, -1, -1, -1, -1, 0x51, 0x68, -1, -1, -1, -1, 0x8B, 0x32, 0x8B, 0xC8, 0xC1, 0xE9, 0x18, 0x51, 0x8B, 0xC8, 0xC1, 0xE9, 0x10, 0x0F, 0xB6, 0xC9, 0x51, 0x8B, 0xC8, 0x0F, 0xB6, 0xC0, 0xC1, 0xE9, 0x08, 0x0F, 0xB6, 0xC9, 0x51, 0x50, 0xFF, 0x75, 0x10, 0xFF, 0x75, 0x0C, 0xFF, 0x74, 0x24, 0x34 }) + 5;

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_NET_GRAPH_TEXT_GAME_RET_ADDR] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_NET_GRAPH_TEXT_GAME_RET_ADDR\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				//  #STR: "<font color=\"%S\">%s</font> <font color=\"%S\">%s</font>", "CCSGO_HudVoiceStatus", "#A745F7"
				//  E8 ? ? ? ? 83 7D D4 00 7C 22
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_PUSH_NOTICE] =
					pe::util::memory::patterns::util::relative_to_absolute(
						pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_CLIENT>({ 0xE8, -1, -1, -1, -1, 0x83, 0x7D, 0xD4, 0x00, 0x7C, 0x22 }) + 1);

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_PUSH_NOTICE] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_PUSH_NOTICE\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				//  function before:
				//  #STR: "LevelInit"
				//  this one though has no string associate
				//  55 8B EC 8B 0D ? ? ? ? 85 C9 75 06
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_CREATE_MOVE] =
					pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_CLIENT>({ 0x55, 0x8B, 0xEC, 0x8B, 0x0D, -1, -1, -1, -1, 0x85, 0xC9, 0x75, 0x06 });

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_CREATE_MOVE] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_CREATE_MOVE\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				//  #STR: "No local player %d after full frame update\n", "Setting fallback player %s as local player\n", "cdll_client_int.cpp"
				//  55 8B EC 8B 0D ? ? ? ? 8B 01 8B 80 ? ? ? ? FF D0 A2 ? ? ? ? 
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_FRAME_STAGE_NOTIFY] =
					pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_CLIENT>({ 0x55, 0x8B, 0xEC, 0x8B, 0x0D, -1, -1, -1, -1, 0x8B, 0x01, 0x8B, 0x80, -1, -1, -1, -1, 0xFF, 0xD0, 0xA2, -1, -1, -1, -1 });

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_FRAME_STAGE_NOTIFY] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_FRAME_STAGE_NOTIFY\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				//  thanks @soar, i was too lazy to re this
				//  55 8B EC 83 EC ? 56 8B F1 8A 46
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GET_COLOR_MODULATION] =
					pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_MATERIAL_SYSTEM>({ 0x55, 0x8B, 0xEC, 0x83, 0xEC, -1, 0x56, 0x8B, 0xF1, 0x8A, 0x46 });

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_GET_COLOR_MODULATION] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_GET_COLOR_MODULATION\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				//  E8 ? ? ? ? 84 C0 8B 45 08
				//  refer to leak, it has many convars pointing to it which help with easy deduction
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_IS_USING_STATIC_PROP_DEBUG_MODES] =
					pe::util::memory::patterns::util::relative_to_absolute(
						pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_ENGINE>({ 0xE8, -1, -1, -1, -1, 0x84, 0xC0, 0x8B, 0x45, 0x08 }) + 1);

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_IS_USING_STATIC_PROP_DEBUG_MODES] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_IS_USING_STATIC_PROP_DEBUG_MODES\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				//	55 8B EC 83 EC 08 56 8B F1 8B 86 ? ? ? ? 85 C0 
				//	 Warning("SendNetMsg %s: stream[%s] buffer overflow (maxsize = %d)!\n", v14, v15, v16);
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_SEND_NET_MSG] =
					pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_ENGINE>({ 0x55, 0x8B, 0xEC, 0x83, 0xEC, 0x08, 0x56, 0x8B, 0xF1, 0x8B, 0x86, -1, -1, -1, -1, 0x85, 0xC0 });

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_IS_USING_STATIC_PROP_DEBUG_MODES] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_IS_USING_STATIC_PROP_DEBUG_MODES\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				//	55 8B EC 83 EC 40 53 8B D9 8B 0D ? ? ? ? 89 5D F8
				//	#STR: "CEngineVGui::Paint"
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_PAINT] =
					pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_ENGINE>({ 0x55, 0x8B, 0xEC, 0x83, 0xEC, 0x40, 0x53, 0x8B, 0xD9, 0x8B, 0x0D, -1, -1, -1, -1, 0x89, 0x5D, 0xF8 });

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_PAINT] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_PAINT\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				//	55 8B EC 83 E4 C0 83 EC 38
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_PAINT_START_DRAWING] =
					pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_VGUI_MAT_SURFACE>({ 0x55, 0x8B, 0xEC, 0x83, 0xE4, 0xC0, 0x83, 0xEC, 0x38 });

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_PAINT_START_DRAWING] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_PAINT_START_DRAWING\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				//	8B 0D ? ? ? ? 56 C6 05
				pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_PAINT_FINISH_DRAWING] =
					pe::util::memory::patterns::getter::the<pe::prototypes::images, pe::Images::IMAGE_VGUI_MAT_SURFACE>({ 0x8B, 0x0D, -1, -1, -1, -1, 0x56, 0xC6, 0x05 });

				if (pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_PAINT_FINISH_DRAWING] == nullptr) {
					logger::the<logger::level::error>("%s: \"ADDRESS_PAINT_FINISH_DRAWING\" was nullptr\n", __FUNCTION__);
					SINCLAIR_THROW(errors::Errors::PE_UTIL_ADDRESS_WAS_NULL);
					return false;
				}

				logger::the<logger::level::log>("%s: Initialized | %d addresses stored in address map\n", __FUNCTION__, pe::util::StaticAddresses::STATIC_ADDRESSES_LIST_SIZE);
				return true;
			}
		}

		//  declare detachment
		namespace detach {
			void the() {
				pe::util::memory::byte::patch::detach::the();

				logger::the<logger::level::log>("%s: Detached\n", __FUNCTION__);
			}
		}

		namespace memory {
			namespace byte {
				namespace patch {
					//  declare initializer
					namespace init {
						bool the() {
							if (!pe::util::memory::byte::patch::getter::the<WeaponType::TYPE_MELEE + 1, 1>(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_CMP_FORCE_CROSSHAIR])) {
								logger::the<logger::level::error>("%s: Failed upon byte patching \"ADDRESS_CMP_FORCE_CROSSHAIR\"\n", __FUNCTION__);
								SINCLAIR_THROW(errors::Errors::GAME_MEMORY_BYTE_PATCH_FAILED);
								return false;
							}

							logger::the<logger::level::log>("%s: Initialized\n", __FUNCTION__);
							return true;
						}
					}

					//  declare detachment
					namespace detach {
						void the() {
							if (!pe::util::memory::byte::patch::getter::the<WeaponType::TYPE_SNIPER_RIFLE, 1>(pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_CMP_FORCE_CROSSHAIR])) {
								logger::the<logger::level::error>("%s: Failed restoring \"ADDRESS_CMP_FORCE_CROSSHAIR\" by byte patch\n", __FUNCTION__);
							}

							logger::the<logger::level::log>("%s: Detach\n", __FUNCTION__);
						}
					}
				}
			}
			namespace patterns {
				namespace util {
					pe::util::types::byte_ptr relative_to_absolute(pe::util::types::byte_ptr address) {
						return (pe::util::types::byte_ptr)(address + 4 + *(int*)address);
					}
				}
			}
		}
	}
}