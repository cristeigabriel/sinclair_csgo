#pragma once

#include "../../../cstrike/defines.h"

#include "../../../cstrike/cstrike.h"

#include "../../memory/memory.h"

namespace game {
	namespace renderer {
		namespace surface {
			enum Fonts {
				FONT_VERDANA_BOLD,

				FONT_LIST_SIZE
			};

			namespace init {
				bool the();
			}

			namespace prototypes {
				extern HFont fonts[game::renderer::surface::Fonts::FONT_LIST_SIZE];
			}

			inline void set_color(int r, int g, int b, int a) {
				game::memory::interfaces::prototypes::surface->draw_set_color(r, g, b, a);
			}

			//	We're not going to manage text color ourselves, only for geometry

			//	This might be messy but it's to avoid typing more than we already do
			//	We're not going to assert in something that gets called constantly, we just rely on the fact that
			//	Initializer has passed, if it has. But if it hasn't, we won't get to this point

			template <game::renderer::surface::Fonts font,
				HFont(&fonts_list)[game::renderer::surface::Fonts::FONT_LIST_SIZE] = game::renderer::surface::prototypes::fonts, size_t N>
			inline void text(const char(&text)[N], int x, int y, int r, int g, int b, int a) {
				game::memory::interfaces::prototypes::surface->draw_colored_text(fonts_list[font], x, y, r, g, b, a, text);
			}

			//	According to godbolt, there'll never be a cmp, this is processed by compile time
			//	If change color is true, there's a function that sets color normally and does others
			//	Else, it just does others normally

			template <bool change_color = true>
			inline void rectangle(int x, int y, int w, int h, int r = 255, int g = 255, int b = 255, int a = 255) {
				if (change_color)
					game::memory::interfaces::prototypes::surface->draw_set_color(r, g, b, a);

				game::memory::interfaces::prototypes::surface->draw_filled_rectangle(x, y, x + w, y + h);
			}

			template <bool change_color = true>
			inline void outline(int x, int y, int w, int h, int r = 255, int g = 255, int b = 255, int a = 255) {
				if (change_color)
					game::memory::interfaces::prototypes::surface->draw_set_color(r, g, b, a);

				game::memory::interfaces::prototypes::surface->draw_outlined_rectangle(x, y, x + w, y + h);
			}

			template <bool change_color = true>
			inline void line(int x0, int y0, int x1, int y1, int r = 255, int g = 255, int b = 255, int a = 255) {
				if (change_color)
					game::memory::interfaces::prototypes::surface->draw_set_color(r, g, b, a);

				game::memory::interfaces::prototypes::surface->draw_line(x0, y0, x0 + x1, y0 + y1);
			}
		}
	}
}
