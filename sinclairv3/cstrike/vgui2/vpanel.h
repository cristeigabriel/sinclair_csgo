#pragma once

#include "../defines.h"

#include "../../game/memory/memory.h"
#include "../../math/math.h"

class SurfacePlat {
public:
	HWND    hwnd;
	HDC     hdc;
	HDC     hwnd_dc;
	HDC	  texture_dc;
	HGLRC   hglrc;
	HRGN    clip_rgn;
	HBITMAP bitmap;
	math::point_t<int> bitmap_size;
	math::point_4d_t<int>     restore_info;
	bool    is_fullscreen;
	bool	disabled; // whether the window can take user input
	math::point_3d_t<int> fullscreen_info;
	VPanel* embedded_panel;

	bool    is_toolbar;				// whether it has an icon in the tool tray or not
	HICON   notify_icon;
	uint32_t notify_panel;

	HPanel last_key_focus_index;		// index to the last panel to have the focus
};

class VPanel {
public:
	VPanel** child_arr;
	VPanel* parent;
	SurfacePlat* plat;	// platform-specific data
};