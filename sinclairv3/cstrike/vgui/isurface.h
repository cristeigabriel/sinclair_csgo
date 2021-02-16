#pragma once

#include "../defines.h"

#include "../../game/memory/memory.h"
#include "../../math/math.h"

struct Vertex_t {
	Vertex_t() {}
	Vertex_t(const math::point_t<int>& pos, const math::point_t<int>& coord = math::point_t<int>{ 0, 0 }) {
		position = pos;
		tex_coord = coord;
	}
	void init(const math::point_t<int>& pos, const math::point_t<int>& coord = math::point_t<int>{ 0, 0 }) {
		position = pos;
		tex_coord = coord;
	}

	math::point_t<int> position;
	math::point_t<int> tex_coord;
};

class ISurface {
private:
	enum indices {
		DRAW_SET_COLOR_RGBA_INDEX = 15,
		DRAW_FILLED_RECTANGLE_INDEX = 16,
		DRAW_OUTLINED_RECTANGLE_INDEX = 18,
		DRAW_LINE_INDEX = 19,
		DRAW_POLY_LINE_INDEX = 20,
		DRAW_SET_TEXT_FONT_INDEX = 23,
		DRAW_SET_TEXT_COLOR_RGBA_INDEX = 24,
		DRAW_SET_TEXT_POSITION_INDEX = 26, 
		DRAW_PRINT_TEXT_INDEX = 28,
		CREATE_FONT_INDEX = 71,
		SET_FONT_GLYPH_SET_INDEX = 72,
		DRAW_TEXTURED_POLY_LINE_INDEX = 104,
		DRAW_TEXTURED_POLYGON_INDEX = 106,
		DRAW_COLORED_TEXT_INDEX = 163
	};

public:
	__forceinline void draw_set_color(int r, int g, int b, int a) {
		return util::vtable::func::getter::the<void, indices::DRAW_SET_COLOR_RGBA_INDEX>(this, r, g, b, a);
	}

	__forceinline void draw_filled_rectangle(int x, int y, int w, int h) {
		return util::vtable::func::getter::the<void, indices::DRAW_FILLED_RECTANGLE_INDEX>(this, x, y, w, h);
	}

	//	This could be remade with vertices but seems to work fine (for now)
	__forceinline void draw_outlined_rectangle(int x, int y, int w, int h) {
		return util::vtable::func::getter::the<void, indices::DRAW_OUTLINED_RECTANGLE_INDEX>(this, x, y, w, h);
	}

	__forceinline void draw_line(int x0, int y0, int x1, int y1) {
		return util::vtable::func::getter::the<void, indices::DRAW_LINE_INDEX>(this, x0, y0, x1, y1);
	}

	__forceinline void draw_poly_line(int* x, int* y, int points) {
		return util::vtable::func::getter::the<void, indices::DRAW_POLY_LINE_INDEX>(this, x, y, points);
	}

	__forceinline void draw_set_text_font(HFont font) {
		return util::vtable::func::getter::the<void, indices::DRAW_SET_TEXT_FONT_INDEX>(this, font);
	}

	__forceinline void draw_set_text_color(int r, int g, int b, int a) {
		return util::vtable::func::getter::the<void, indices::DRAW_SET_TEXT_COLOR_RGBA_INDEX>(this, r, g, b, a);
	}

	__forceinline void draw_set_text_position(int x, int y) {
		return util::vtable::func::getter::the<void, indices::DRAW_SET_TEXT_POSITION_INDEX>(this, x, y);
	}

	__forceinline void draw_print_text(const wchar_t* text, int len, FontDrawType draw_type = FontDrawType::FONT_DRAW_DEFAULT) {
		return util::vtable::func::getter::the<void, indices::DRAW_PRINT_TEXT_INDEX>(this, text, len, draw_type);
	}

	__forceinline HFont create_font() {
		return util::vtable::func::getter::the<HFont, indices::CREATE_FONT_INDEX>(this);
	}

	__forceinline void set_font_glyph_set(HFont font, const char* font_name, int tall, int weight, int blur,
		int scan_lines, FontFlags flags, int range_min = 0, int range_max = 0) {
		return util::vtable::func::getter::the<void, indices::SET_FONT_GLYPH_SET_INDEX>(this, font, font_name,
			tall, weight, blur, scan_lines, flags, range_min, range_max);
	}

	__forceinline void draw_textured_poly_line(const Vertex_t* points_vertices, int points) {
		return util::vtable::func::getter::the<void, indices::DRAW_TEXTURED_POLY_LINE_INDEX>(this, points_vertices, points);
	}

	__forceinline void draw_textured_polygon(int points, Vertex_t* points_vertices, bool clip_vertices = false) {
		return util::vtable::func::getter::the<void, indices::DRAW_TEXTURED_POLYGON_INDEX>(this, points, points_vertices, clip_vertices);
	}

	__forceinline void draw_colored_text(HFont font, int x, int y, int r, int g, int b, int a, const char* text) {
		return util::vtable::func::getter::the_cdecl<void, indices::DRAW_COLORED_TEXT_INDEX>(this, font, x, y, r, g, b, a, text);
	}
};