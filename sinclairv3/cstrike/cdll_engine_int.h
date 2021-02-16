#pragma once

#include "defines.h"

#include "../game/memory/memory.h"
#include "../math/math.h"

class IClientEntityList {
	enum indices {
		GET_INDEX = 3,
		GET_FROM_HANDLE_INDEX = 4,
		GET_HIGHEST_ENITTY_INDEX_INDEX = 6
	};

public:
	template <typename T>
	__forceinline T get(int index) {
		return util::vtable::func::getter::the<T, indices::GET_INDEX>(this, index);
	}

	template <typename T>
	__forceinline T get_from_handle(int index) {
		return util::vtable::func::getter::the<T, indices::GET_FROM_HANDLE_INDEX>(this, index);
	}

	__forceinline int get_highest_entity_index() {
		return util::vtable::func::getter::the<int, indices::GET_HIGHEST_ENITTY_INDEX_INDEX>(this);
	}
};