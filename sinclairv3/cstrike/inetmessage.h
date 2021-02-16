#pragma once

#include "defines.h"

#include "../game/memory/memory.h"
#include "../math/math.h"

class INetMessage {
private:
	enum indices {
		GET_TYPE_INDEX = 7,
		GET_GROUP_INDEX = 8
	};

public:
	int get_type() {
		return util::vtable::func::getter::the<int, indices::GET_TYPE_INDEX>(this);
	}

	int get_group() {
		return util::vtable::func::getter::the<int, indices::GET_GROUP_INDEX>(this);
	}
};