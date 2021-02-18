#pragma once

#include "defines.h"

#include "../game/memory/memory.h"
#include "../math/math.h"

class CIVDebugOverlay {
private:
	enum indices {
		SCREEN_POSITION_INDEX = 13
	};

public:
	__forceinline int screen_position(const math::point_3d_t<float>& in, math::point_3d_t<float>& out) {
		return util::vtable::func::getter::the<int, indices::SCREEN_POSITION_INDEX>(this, &in, &out);
	}
};