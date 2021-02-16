#pragma once

#include "defines.h"

#include "../game/memory/memory.h"
#include "../math/math.h"

class CCSWeaponData {
public:
    char pad000[20];
    int max_clip;
    char pad001[112];
    const char* name;
    char pad002[60];
    WeaponType type;
    char pad003[4];
    int price;
    char pad004[8];
    float cycle_time;
    char pad005[12];
    bool full_auto;
    char pad006[3];
    int damage;
    float armor_ratio;
    int bullets;
    float penetration;
    char pad007[8];
    float range;
    float range_modifier;
    char pad008[16];
    bool silencer;
    char pad009[15];
    float max_speed;
    float max_speed_alt;
    char pad010[100];
    float recoil_magnitude;
    float recoil_magnitude_alt;
    char pad011[16];
    float recovery_time_stand;
};