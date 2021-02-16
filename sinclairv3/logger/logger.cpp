#include "logger.h"

namespace logger {
	//  declare initializer
	namespace init {
		void the() {
			//  Allow for I/O in our console instance
			freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
			freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);

			logger::the<logger::level::log>("%s: Initialized\n", __FUNCTION__);
		}
	}
}