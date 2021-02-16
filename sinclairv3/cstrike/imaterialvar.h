#pragma once

#include "defines.h"

#include "../game/memory/memory.h"
#include "../math/math.h"

class IMaterialVar {
private:
    enum indices {
        SET_FLOAT_VALUE_INDEX = 4,
        SET_INT_VALUE_INDEX = 5,
        SET_STRING_VALUE_INDEX = 6,
        GET_STRING_VALUE_INDEX = 7,
        SET_VEC_2D_VALUE_INDEX = 11,
        SET_VEC_3D_VALUE_INDEX = 12
    };

public:
    __forceinline void set_float_value(float value) {
        return util::vtable::func::getter::the<void, indices::SET_FLOAT_VALUE_INDEX>(this, value);
    }

    __forceinline void set_int_value(int value) {
        return util::vtable::func::getter::the<void, indices::SET_INT_VALUE_INDEX>(this, value);
    }

    __forceinline void set_string_value(const char* value) {
        return util::vtable::func::getter::the<void, indices::SET_STRING_VALUE_INDEX>(this, value);
    }

    __forceinline const char* get_string_value() {
        return util::vtable::func::getter::the<const char*, indices::GET_STRING_VALUE_INDEX>(this);
    }

    __forceinline void set_vec_2d_value(const math::point_t<float>& value) {
        return util::vtable::func::getter::the<void, indices::SET_VEC_2D_VALUE_INDEX>(this, value.x, value.y);
    }

    __forceinline void set_vec_3d_value(const math::point_3d_t<float>& value) {
        return util::vtable::func::getter::the<void, indices::SET_VEC_3D_VALUE_INDEX>(this, value.x, value.y, value.z);
    }
};