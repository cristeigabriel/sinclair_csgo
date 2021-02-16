#include "game.h"

namespace game {
	//  declare initializer
	namespace init {
		bool the() {
			if (!game::memory::interfaces::init::the()) {
				logger::the<logger::level::log>("%s: Failed at memory interfaces initializer\n", __FUNCTION__);
				return false;
			}

			game::props::init::the();

			if (!game::hooking::init::the()) {
				logger::the<logger::level::log>("%s: Failed at hooking initializer\n", __FUNCTION__);
				return false;
			}

			logger::the<logger::level::log>("%s: Initialized\n", __FUNCTION__);
			return true;
		}
	}

	//  declare detachment
	namespace detach {
		void the() {
			game::hooking::detach::the();

			logger::the<logger::level::log>("%s: Detached\n", __FUNCTION__);
		}
	}
}