#pragma once

#include "../../../cstrike/defines.h"

#include "../../../cstrike/cstrike.h"

#include "../../memory/memory.h"

#include <WinUser.h>

#define PLAT(vpanel) (((VPanel *)vpanel)->plat)

namespace game {
	namespace renderer {
		namespace surface {
			enum ColorPreservation {
				COLOR_CHANGE,
				COLOR_CHANGE_AND_RESTORE,
				COLOR_PRESERVE
			};

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

			inline const util::color_t& get_color() {
				return { game::memory::interfaces::prototypes::surface->r,
					game::memory::interfaces::prototypes::surface->g,
					game::memory::interfaces::prototypes::surface->b,
					game::memory::interfaces::prototypes::surface->a };
			}

			inline void set_color(const util::color_t& color) {
				game::memory::interfaces::prototypes::surface->draw_set_color(color.r, color.g, color.b, color.a);
			}

			//	We're not going to manage text color ourselves, only for geometry

			//	This might be messy but it's to avoid typing more than we already do
			//	We're not going to assert in something that gets called constantly, we just rely on the fact that
			//	Initializer has passed, if it has. But if it hasn't, we won't get to this point

			template <game::renderer::surface::Fonts font,
				HFont(&fonts_list)[game::renderer::surface::Fonts::FONT_LIST_SIZE] = game::renderer::surface::prototypes::fonts, size_t N>
				inline void text(const char(&text)[N], int x, int y, const util::color_t& color) {
				game::memory::interfaces::prototypes::surface->draw_colored_text(fonts_list[font], x, y, color.r, color.g, color.b, color.a, text);
			}

			//	According to godbolt, there'll never be a cmp, this is processed by compile time

			//	Uninitialized but created values will be compiled away

			template <game::renderer::surface::ColorPreservation change_color = game::renderer::surface::ColorPreservation::COLOR_CHANGE>
			inline void rectangle(int x, int y, int w, int h, const util::color_t& color = { 255, 255, 255, 255 }) {
				static util::color_t old_color;

				if (change_color == ColorPreservation::COLOR_CHANGE_AND_RESTORE)
					old_color = get_color();

				if (change_color == ColorPreservation::COLOR_CHANGE || change_color == ColorPreservation::COLOR_CHANGE_AND_RESTORE)
					game::renderer::surface::set_color(color);

				game::memory::interfaces::prototypes::surface->draw_filled_rectangle(x, y, x + w, y + h);

				if (change_color == ColorPreservation::COLOR_CHANGE_AND_RESTORE)
					game::renderer::surface::set_color(old_color);
			}

			template <game::renderer::surface::ColorPreservation change_color = game::renderer::surface::ColorPreservation::COLOR_CHANGE>
			inline void rectangle_outline(int x, int y, int w, int h, const util::color_t& color = { 255, 255, 255, 255 }) {
				static util::color_t old_color;

				if (change_color == ColorPreservation::COLOR_CHANGE_AND_RESTORE)
					old_color = get_color();

				if (change_color == ColorPreservation::COLOR_CHANGE || change_color == ColorPreservation::COLOR_CHANGE_AND_RESTORE)
					game::renderer::surface::set_color(color);

				game::memory::interfaces::prototypes::surface->draw_outlined_rectangle(x, y, x + w, y + h);

				if (change_color == ColorPreservation::COLOR_CHANGE_AND_RESTORE)
					game::renderer::surface::set_color(old_color);
			}

			template <game::renderer::surface::ColorPreservation change_color = game::renderer::surface::ColorPreservation::COLOR_CHANGE>
			inline void line(int x0, int y0, int x1, int y1, const util::color_t& color = { 255, 255, 255, 255 }) {
				static util::color_t old_color;

				if (change_color == ColorPreservation::COLOR_CHANGE_AND_RESTORE)
					old_color = get_color();

				if (change_color == ColorPreservation::COLOR_CHANGE || change_color == ColorPreservation::COLOR_CHANGE_AND_RESTORE)
					game::renderer::surface::set_color(color);

				game::memory::interfaces::prototypes::surface->draw_line(x0, y0, x0 + x1, y0 + y1);

				if (change_color == ColorPreservation::COLOR_CHANGE_AND_RESTORE)
					game::renderer::surface::set_color(old_color);
			}
		}
	}
}
