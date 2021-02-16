#pragma once

#include "defines.h"

#include "../game/memory/memory.h"
#include "../math/math.h"

class CHudChat {
private:
	enum indices {
		CHAT_PRINTF_INDEX = 27
	};

public:
	template <typename... Args, size_t N>
	__forceinline void chat_printf(int player_index, int filter, const char(&fmt)[N], Args... args) {
		return util::vtable::func::getter::the_cdecl<void, indices::CHAT_PRINTF_INDEX>(this, player_index, filter, fmt, args...);
	}
};

class CCSGO_HudChat {
public:
};