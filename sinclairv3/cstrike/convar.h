#pragma once

#include "defines.h"

#include "../game/memory/memory.h"
#include "../math/math.h"

#include "utl_vector.h"

class CConVar {
public:
    enum indices {
        GET_FLOAT_INDEX = 12,
        GET_INT_INDEX,
        SET_VALUE_SZ_INDEX,
        SET_VALUE_FLOAT_INDEX,
        SET_VALUE_INT_INDEX
    };

public:
    __forceinline float get_float() {
        return util::vtable::func::getter::the<float, indices::GET_FLOAT_INDEX>(this);
    }

    __forceinline int get_int() {
        return util::vtable::func::getter::the<int, indices::GET_INT_INDEX>(this);
    }

    __forceinline void set_value(const char* value) {
        return util::vtable::func::getter::the<void, indices::SET_VALUE_SZ_INDEX>(this, value);
    }

    __forceinline void set_value(float value) {
        return util::vtable::func::getter::the<void, indices::SET_VALUE_FLOAT_INDEX>(this, value);
    }

    __forceinline void set_value(int value) {
        return util::vtable::func::getter::the<void, indices::GET_INT_INDEX>(this, value);
    }

public:
    char pad000[0x4];
    CConVar* next;
    int registered;
    char* name;
    char* description;
    int flags;
    char pad1[0x4];
    CConVar* parent;
    char* default_value;
    char* string;
    int string_length;
    float float_value;
    int int_value;
    int has_min;
    float min;
    int has_max;
    float max;
    UtlVector<convar_callback_t> callback;
};

class ICVar {
public:
    enum indices {
        REGISTER_CON_COMMAND_INDEX = 10,
        UNREGISTER_CON_COMMAND_INDEX,
        FIND_VAR_INDEX = 15
    };

public:
    __forceinline void register_con_command(CConVar* command) {
        return util::vtable::func::getter::the<void, indices::REGISTER_CON_COMMAND_INDEX>(this, command);
    }

    __forceinline void unregister_con_command(CConVar* command) {
        return util::vtable::func::getter::the<void, indices::UNREGISTER_CON_COMMAND_INDEX>(this, command);
    }

    __forceinline CConVar* find_var(const char* name) {
        return util::vtable::func::getter::the<CConVar*, indices::FIND_VAR_INDEX>(this, name);
    }
};