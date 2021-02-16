#pragma once

#include "defines.h"

#include "../game/memory/memory.h"
#include "../math/math.h"

class IInputSystem {
public:
    enum indices {
        ENABLE_INPUT_INDEX = 11,
        IS_BUTTON_DOWN_INDEX = 15,
        BUTTON_CODE_TO_STRING_INDEX = 40,
        GET_CURSOR_POSITION_INDEX = 56
    };

public:
    __forceinline void enable_input(bool state) {
        return util::vtable::func::getter::the<void, indices::ENABLE_INPUT_INDEX>(this, state);
    }

    __forceinline bool is_button_down(ButtonCode code) {
        return util::vtable::func::getter::the<bool, indices::IS_BUTTON_DOWN_INDEX>(this, code);
    }

    __forceinline const char* button_code_to_string(ButtonCode code) {
        return util::vtable::func::getter::the<const char*, indices::BUTTON_CODE_TO_STRING_INDEX>(this, code);
    }

    __forceinline void get_cursor_position(int* x, int* y) {
        return util::vtable::func::getter::the<void, indices::GET_CURSOR_POSITION_INDEX>(this, x, y);
    }
};