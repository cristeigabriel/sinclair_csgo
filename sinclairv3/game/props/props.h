#pragma once

#include "../memory/memory.h"

#include "../../cstrike/defines.h"

#include "../../extern/hasher/hasher.h"

#include <unordered_map>

namespace game {
	namespace props {
		namespace init {
			void the();
		}

		namespace types {
			typedef std::unordered_map<uint32_t, std::unordered_map<uint32_t, uintptr_t>> props_type;
		}

		namespace prototypes {
			extern game::props::types::props_type props;
		}

		namespace collecter {
			void the(RecvTable* table);
		}

		namespace dumper {
			void the();
		}
	}
}