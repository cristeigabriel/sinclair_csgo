#pragma once

#include "../defines.h"

#include "../../game/memory/memory.h"
#include "../../math/math.h"

class ISurface {
public:
	__forceinline void start_drawing() {
		const static start_drawing_t o_start_drawing = (start_drawing_t)pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_PAINT_START_DRAWING];
		o_start_drawing(this);
	}

	__forceinline void finish_drawing() {
		const static finish_drawing_t o_finish_drawing = (finish_drawing_t)pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_PAINT_FINISH_DRAWING];
		o_finish_drawing(this);
	}
};