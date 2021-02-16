#include "pe.h"

#include "util/util.h"

//  Prototypes
pe::types::image_type pe::prototypes::images[pe::Images::IMAGES_LIST_SIZE];

namespace pe {
	//  declare initializer
	namespace init {
		bool the() {
			if (!pe::getter::the<pe::prototypes::images, pe::Images::IMAGE_CLIENT>("client.dll")) {
				logger::the<logger::level::error>("%s: Can't find \"client.dll\", throwing\n", __FUNCTION__);
				SINCLAIR_THROW(errors::Errors::PE_GETTER_RESULT_WAS_NULL);
				return false;
			}

			if (!pe::getter::the<pe::prototypes::images, pe::Images::IMAGE_ENGINE>("engine.dll")) {
				logger::the<logger::level::error>("%s: Can't find \"engine.dll\", throwing\n", __FUNCTION__);
				SINCLAIR_THROW(errors::Errors::PE_GETTER_RESULT_WAS_NULL);
				return false;
			}

			if (!pe::getter::the<pe::prototypes::images, pe::Images::IMAGE_INPUT_SYSTEM>("inputsystem.dll")) {
				logger::the<logger::level::error>("%s: Can't find \"inputsystem.dll\", throwing\n", __FUNCTION__);
				SINCLAIR_THROW(errors::Errors::PE_GETTER_RESULT_WAS_NULL);
				return false;
			}

			if (!pe::getter::the<pe::prototypes::images, pe::Images::IMAGE_VSTDLIB>("vstdlib.dll")) {
				logger::the<logger::level::error>("%s: Can't find \"vstdlib.dll\", throwing\n", __FUNCTION__);
				SINCLAIR_THROW(errors::Errors::PE_GETTER_RESULT_WAS_NULL);
				return false;
			}

			if (!pe::getter::the<pe::prototypes::images, pe::Images::IMAGE_VGUI2>("vgui2.dll")) {
				logger::the<logger::level::error>("%s: Can't find \"vgui2.dll\", throwing\n", __FUNCTION__);
				SINCLAIR_THROW(errors::Errors::PE_GETTER_RESULT_WAS_NULL);
				return false;
			}

			if (!pe::getter::the<pe::prototypes::images, pe::Images::IMAGE_VGUI_MAT_SURFACE>("vguimatsurface.dll")) {
				logger::the<logger::level::error>("%s: Can't find \"vguimatsurface.dll\", throwing\n", __FUNCTION__);
				SINCLAIR_THROW(errors::Errors::PE_GETTER_RESULT_WAS_NULL);
				return false;
			}

			if (!pe::getter::the<pe::prototypes::images, pe::Images::IMAGE_MATERIAL_SYSTEM>("materialsystem.dll")) {
				logger::the<logger::level::error>("%s: Can't find \"materialsystem.dll\", throwing\n", __FUNCTION__);
				SINCLAIR_THROW(errors::Errors::PE_GETTER_RESULT_WAS_NULL);
				return false;
			}

			if (!pe::getter::the<pe::prototypes::images, pe::Images::IMAGE_GAME_OVERLAY_RENDERER>("GameOverlayRenderer.dll")) {
				logger::the<logger::level::error>("%s: Can't find \"GameOverlayRenderer.dll\", throwing\n", __FUNCTION__);
				SINCLAIR_THROW(errors::Errors::PE_GETTER_RESULT_WAS_NULL);
				return false;
			}

			if (!pe::util::init::the()) {
				logger::the<logger::level::error>("%s: Failed at utilities initializer\n", __FUNCTION__);
				return false;
			}

			pe::util::memory::byte::patch::init::the();

			logger::the<logger::level::log>("%s: Initialized | %d images stored in image map\n", __FUNCTION__, pe::Images::IMAGES_LIST_SIZE);
			return true;
		}
	}

	//	declare detachment
	namespace detach {
		void the() {
			pe::util::detach::the();

			logger::the<logger::level::log>("%s: Detached\n", __FUNCTION__);
		}
	}
}