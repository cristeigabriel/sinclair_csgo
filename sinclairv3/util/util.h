#pragma once

#include "../pe/pe.h"
#include "../pe/util/util.h"

#include "color/color.h"

namespace util {
    namespace vtable {
        namespace getter {
            template <typename T, DWORD index, int offset = 0>
            inline static T the(void* base_class) {
                return (T)((*(uintptr_t**)(base_class))[index] + offset);
            }
        }

        namespace func {
            namespace getter {
                template <typename T, DWORD index, typename... Args>
                inline static T the(void* base_class, Args... args) {
                    typedef T(__thiscall* fn)(void*, Args...);
                    return (*(fn**)(base_class))[index](base_class, args...);
                }

                template <typename T, DWORD index, typename... Args>
                inline static T the_cdecl(void* base_class, Args... args) {
                    typedef T(__cdecl* fn)(void*, Args...);
                    return (*(fn**)(base_class))[index](base_class, args...);
                }
            }
        }
    }
}