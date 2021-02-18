#include "surface.h"

//	Prototypes
HFont game::renderer::surface::prototypes::fonts[game::renderer::surface::Fonts::FONT_LIST_SIZE];

namespace game {
	namespace renderer {
		namespace surface {
			//	declare initializer
			namespace init {
				bool the() {
					game::renderer::surface::prototypes::fonts[game::renderer::surface::Fonts::FONT_PF_TEMPESTA_SEVEN] =
						game::memory::interfaces::prototypes::surface->create_font();

					if (!game::renderer::surface::prototypes::fonts[game::renderer::surface::Fonts::FONT_PF_TEMPESTA_SEVEN]) {
						SINCLAIR_THROW(errors::Errors::GAME_RENDERER_FONT_WAS_NULL);
						logger::the<logger::level::error>("%s: \"FONT_VERDANA_BOLD\" (from 0x%X) failed to initialize\n", __FUNCTION__, game::renderer::surface::prototypes::fonts);
						return false;
					}

					game::memory::interfaces::prototypes::surface->set_font_glyph_set(game::renderer::surface::prototypes::fonts[game::renderer::surface::Fonts::FONT_PF_TEMPESTA_SEVEN],
						"PF Tempesta Seven", 13, 0, 0, 0, FontFlags::FONTFLAG_OUTLINE);

					logger::the<logger::level::log>("%s: Initialized\n", __FUNCTION__);
					return true;
				}
			}
		}
	}
}