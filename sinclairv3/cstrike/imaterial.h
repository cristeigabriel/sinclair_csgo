#pragma once

#include "defines.h"

#include "../game/memory/memory.h"
#include "../math/math.h"

class IMaterial {
private:
    enum indices {
        GET_NAME_INDEX = 0,
        GET_TEXTURE_GROUP_NAME_INDEX = 1,
        FIND_VAR_INDEX = 8,
        ALPHA_MODULATE_INDEX = 27,
        COLOR_MODULATE_INDEX = 28,
        SET_MATERIAL_VAR_FLAG_INDEX = 29
    };

public:
    __forceinline const char* get_name() {
        return util::vtable::func::getter::the<const char*, indices::GET_NAME_INDEX>(this);
    }

    __forceinline const char* get_texture_group_name() {
        return util::vtable::func::getter::the<const char*, indices::GET_TEXTURE_GROUP_NAME_INDEX>(this);
    }

    __forceinline IMaterialVar* find_var(const char* var_name, bool* found, bool complain = true) {
        return util::vtable::func::getter::the<IMaterialVar*, indices::FIND_VAR_INDEX>(this, var_name, found, complain);
    }

    __forceinline void alpha_modulate(float a) {
        return util::vtable::func::getter::the<void, indices::ALPHA_MODULATE_INDEX>(this, a);
    }

    __forceinline void color_modulate(float r, float g, float b) {
        return util::vtable::func::getter::the<void, indices::COLOR_MODULATE_INDEX>(this, r, g, b);
    }

    __forceinline void set_material_var_flag(MaterialVarFlags flag, bool on) {
        return util::vtable::func::getter::the<void, indices::SET_MATERIAL_VAR_FLAG_INDEX>(this, flag, on);
    }
};