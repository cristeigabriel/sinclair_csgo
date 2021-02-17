#pragma once

#include "defines.h"

#include "../game/memory/memory.h"
#include "../math/math.h"

class IMaterialSystem {
private:
	enum indices {
		CREATE_MATERIAL_INDEX = 83,
		FIND_MATERIAL_INDEX = 84,
		GET_MATERIAL_INDEX = 89
	};

public:
	//	Reminder: Implement KeyValues
	__forceinline IMaterial* create_material(const char* material_name, void* key_values) {
		return util::vtable::func::getter::the<IMaterial*, indices::CREATE_MATERIAL_INDEX>(this, material_name, key_values);
	}

	__forceinline IMaterial* find_material(const char* material_name, const char* texture_group, bool complain = true, const char* complain_prefix = "") {
		return util::vtable::func::getter::the<IMaterial*, indices::FIND_MATERIAL_INDEX>(this, material_name, texture_group, complain, complain_prefix);
	}

	__forceinline IMaterial* get_material(MaterialHandle handle) {
		return util::vtable::func::getter::the<IMaterial*, indices::GET_MATERIAL_INDEX>(this, handle);
	}
};