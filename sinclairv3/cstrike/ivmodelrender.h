#pragma once

#include "defines.h"

#include "../game/memory/memory.h"
#include "../math/math.h"

class IVModelRender {
private:
	enum indices {
		FORCE_MATERIAL_OVERRIDE_INDEX = 1,
		IS_FORCED_MATERIAL_OVERRIDE_INDEX = 2,
	};

public:
	__forceinline void force_material_override(IMaterial* material) {
		return util::vtable::func::getter::the<void, indices::FORCE_MATERIAL_OVERRIDE_INDEX>(this, material);
	}

	__forceinline bool force_material_override() {
		return util::vtable::func::getter::the<bool, indices::IS_FORCED_MATERIAL_OVERRIDE_INDEX>(this);
	}
};