#pragma once

#include "defines.h"

#include "../game/memory/memory.h"
#include "../math/math.h"

class CUserCmd {
public:
    char pad000[4];

    //  For matching server and client commands for debugging
    int command_number;

    //  the tick the client created this command
    int tick_count;

    //  Player instantaneous view angles.
    math::point_3d_t<float> view_angles;
    math::point_3d_t<float> aim_direction;	//  For pointing devices. 

    //  Intended velocities
    //	forward velocity.
    float forward_move;
    //   sideways velocity.
    float side_move;
    //   upward velocity.
    float up_move;
    //  Attack button states
    int buttons;
    //  Impulse command issued.
    char impulse;
    //  Current weapon id
    int weapon_select;
    int weapon_subtype;

    int random_seed;	//  For shared random functions

    short mouse_dx;		//  mouse accum in x from create move
    short mouse_dy;		//  mouse accum in y from create move

    //  Client only, tracks whether we've predicted this command at least once
    bool has_been_predicted;
};
