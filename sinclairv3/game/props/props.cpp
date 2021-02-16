#include "props.h"

#include "../../cstrike/cstrike.h"

//  Prototypes
game::props::types::props_type game::props::prototypes::props;

namespace game {
	namespace props {
		//  declare initializer
		namespace init {
			void the() {
				game::props::dumper::the();

				logger::the<logger::level::log>("%s: Initialized\n", __FUNCTION__);
			}
		}

		namespace collecter {
			void the(RecvTable* table) {
				for (int i = 0; i < table->props_len; ++i) {
					const RecvProp* current_prop = &table->props[i];

					if (current_prop == nullptr || isdigit(current_prop->var_name[0]) ||
						(current_prop->var_name[0] == 'b' && current_prop->var_name[4] == 'c')) {

						continue;
					}

					if (current_prop->data_table &&
						(current_prop->recv_type == SendPropType::DPT_FLOAT ||
							current_prop->recv_type == SendPropType::DPT_VECTOR_2D ||
							current_prop->recv_type == SendPropType::DPT_VECTOR_3D ||
							current_prop->recv_type == SendPropType::DPT_STRING ||
							current_prop->recv_type == SendPropType::DPT_ARRAY ||
							current_prop->recv_type == SendPropType::DPT_DATA_TABLE)) {
						game::props::collecter::the(current_prop->data_table);
					}

					game::props::prototypes::props[HASH_RT(table->net_table_name)][HASH_RT(current_prop->var_name)] = current_prop->offset;
				}
			}
		}

		namespace dumper {
			void the() {
				for (ClientClass* data = game::memory::interfaces::prototypes::base_client->get_all_classes(); data != nullptr; data = data->next) {
					if (data->recv_table) {
						game::props::collecter::the(data->recv_table);
					}
				}

				logger::the<logger::level::log>("%s: Initialized\n", __FUNCTION__);
			}
		}
	}
}