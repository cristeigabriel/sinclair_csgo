#pragma once

#include "../logger/logger.h"

#include <stdexcept>

namespace errors {
	enum Errors {
		PE_GETTER_RESULT_WAS_NULL,
		PE_UTIL_EXPORTS_RESULT_WAS_NULL,
		PE_UTIL_ADDRESS_WAS_NULL,
		GAME_MEMORY_EXPORT_WAS_NULL,
		GAME_MEMORY_INTERFACE_WAS_NULL,
		GAME_MEMORY_BYTE_FAILED_REMOVING_WRITE_PROTECTION,
		GAME_MEMORY_BYTE_FAILED_RESTORING_WRITE_PROTECTION,
		GAME_MEMORY_BYTE_PATCH_FAILED,
		GAME_ENTITIES_LOCAL_WAS_NULL,
		GAME_RENDERER_FONT_WAS_NULL,
		INITIALIZER_FAILED,

		ERRORS_LIST_SIZE
	};

	namespace codes {
		constexpr static const char* the[errors::Errors::ERRORS_LIST_SIZE]
		{
			"While trying to obtain a module, the returned result was NULL",	//	PE_GETTER_RESULT_WAS_NULL
			"WHile trying to obtain an export, the returned result was NULL",	//	PE_UTIL_EXPORTS_RESULT_WAS_NULL
			"While trying to obtain an address, the returned result was NULL", //	PE_UTIL_ADDRESS_WAS_NULL
			"While trying to assign an interface by assesed export, the returned result was NULL", //	GAME_MEMORY_EXPORT_WAS_NULL
			"While verifying an interface, the returned result was NULL", //	GAME_MEMORY_INTERFACE_WAS_NULL
			"While bytepatching, upon trying to remove write protection, the operation has failed", //	GAME_MEMORY_BYTE_FAILED_REMOVING_WRITE_PROTECTION
			"While bytepatching, upon trying to restore write protection, the operation has failed", //	GAME_MEMORY_BYTE_FAILED_RESTORING_WRITE_PROTECTION
			"While bytepatching, the returned result was false", //	GAME_MEMORY_BYTE_PATCH_FAILED
			"While trying to assign local player by an assessed address, the returned result was NULL", //	GAME_ENTITIES_LOCAL_WAS_NULL
			"While trying to create a font, the returned result was NULL", //	GAME_RENDERER_FONT_WAS_NULL
			"Upon initialization, something has thrown" //	INITIALIZER_FAILED
		};
	}
}

#define SINCLAIR_THROW(errno) throw std::runtime_error(errors::codes::the[errno]);