#pragma once

#include "../pe.h"

namespace pe {
	namespace util {
		enum StaticAddresses {
			ADDRESS_GET_CURRENT_GAME_TYPE,
			ADDRESS_GAME_OVERAY_RENDERER_HOOKING,
			ADDRESS_GAME_OVERAY_RENDERER_UNHOOKING,
			ADDRESS_GET_CS_WPN_DATA,
			ADDRESS_GET_ENTITY_BOUNDING_BOX,
			ADDRESS_DRAW_CROSSHAIR,
			ADDRESS_CMP_FORCE_CROSSHAIR,
			ADDRESS_NET_GRAPH_TEXT_FORMATTER,
			ADDRESS_NET_GRAPH_TEXT_MAIN_MENU_RET_ADDR,
			ADDRESS_NET_GRAPH_TEXT_GAME_RET_ADDR,
			ADDRESS_PUSH_NOTICE,
			ADDRESS_CREATE_MOVE,
			ADDRESS_FRAME_STAGE_NOTIFY,
			ADDRESS_GET_COLOR_MODULATION,
			ADDRESS_IS_USING_STATIC_PROP_DEBUG_MODES,
			ADDRESS_SEND_NET_MSG,
			ADDRESS_PAINT,
			ADDRESS_PAINT_START_DRAWING,
			ADDRESS_PAINT_FINISH_DRAWING,

			STATIC_ADDRESSES_LIST_SIZE
		};

		namespace init {
			bool the();
		}

		namespace detach {
			void the();
		}

		namespace types {
			typedef int address_type;
			typedef uint8_t* byte_ptr;
		}

		namespace prototypes {
			extern pe::util::types::byte_ptr static_addresses[StaticAddresses::STATIC_ADDRESSES_LIST_SIZE];
		}

		namespace memory {
			namespace exports {
				namespace getter {
					template <typename T, size_t N>
					inline T the(const pe::types::image_type& image, const char(&name)[N]) {
						//  Get export
						const T o_fn = (T)GetExportAddress(image, name, true);
						if (o_fn == nullptr) {
							logger::the<logger::level::error>("%s: \"o_fn\" (%s) was nullptr, returning\n", __FUNCTION__, name);
							SINCLAIR_THROW(errors::Errors::PE_UTIL_EXPORTS_RESULT_WAS_NULL);
							return nullptr;
						}

						logger::the<logger::level::log>("%s: Found \"o_fn\" (%s) at 0x%X in 0x%X\n", __FUNCTION__, name, o_fn, image);

						//  We found the export
						return o_fn;
					}
				}

				namespace types {
					typedef void* (*create_interface_t)(const char*, int);
				}
			}

			namespace byte {
				namespace patch {
					namespace init {
						bool the();
					}

					namespace detach {
						void the();
					}

					namespace getter {
						//  https://www.unknowncheats.me/wiki/C%2B%2B:Patching_single_bytes_in_a_single_process_using_C%2B%2B
						template <DWORD type, DWORD bytes>
						bool the(pe::util::types::byte_ptr address) {
							//  Old protection state
							DWORD new_protect, old_protect;

							//  Remove write protection, if it exists
							if (!VirtualProtect(address, bytes, PAGE_EXECUTE_READWRITE, &new_protect)) {
								logger::the<logger::level::error>("%s: Failed removing write protection, throwing\n", __FUNCTION__);
								SINCLAIR_THROW(errors::Errors::GAME_MEMORY_BYTE_FAILED_REMOVING_WRITE_PROTECTION);
								return false;
							}

							//  Patch bytes
							memset(address, type, bytes);

							//  Restore old protection state
							if (!VirtualProtect(address, bytes, new_protect, &old_protect)) {
								logger::the<logger::level::error>("%s: Failed restoring write protection, throwing\n", __FUNCTION__);
								SINCLAIR_THROW(errors::Errors::GAME_MEMORY_BYTE_FAILED_RESTORING_WRITE_PROTECTION);
								return false;
							}

							logger::the<logger::level::log>("%s: Byte patched first %d bytes of \"address\" (0x%X)\n", __FUNCTION__, bytes, address);

							return true;
						}
					}
				}
			}

			namespace patterns {
				namespace getter {
					template <pe::types::image_type(&image_map)[Images::IMAGES_LIST_SIZE], pe::Images index, DWORD N>
					inline pe::util::types::byte_ptr the(const pe::util::types::address_type(&address)[N]) {
						//  Assert that image is valid
						assert(image_map[index]);

						//  Get the image as a byte_ptr for future use in comparassion
						const pe::util::types::byte_ptr image_as_byteptr = (pe::util::types::byte_ptr)image_map[index];

						//  Get NT header
						const PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)image_map[index];
						const PIMAGE_NT_HEADERS nt_headers = (PIMAGE_NT_HEADERS)(image_map[index] + dos_header->e_lfanew);

						//  Get image size
						const DWORD image_size = nt_headers->OptionalHeader.SizeOfImage;

						for (DWORD i = 0; i < image_size - N; ++i) {
							bool proceed = true;
							for (DWORD j = 0; j < N; ++j) {
								if (image_as_byteptr[i + j] != address[j] && address[j] != -1) {
									proceed = false;
									break;
								}
							}
							if (proceed) {
								logger::the<logger::level::log>("%s: Found \"address\" (0x%X) in 0x%X\n", __FUNCTION__, &image_as_byteptr[i], image_map[index]);
								//  We found the address
								return &image_as_byteptr[i];
							}
						}

						logger::the<logger::level::error>("%s: Failed finding \"address\" in 0x%X\n", __FUNCTION__, image_map[index]);
						return nullptr;
					}
				}

				namespace util {
					pe::util::types::byte_ptr relative_to_absolute(pe::util::types::byte_ptr address);
				}
			}
		}
	}
}