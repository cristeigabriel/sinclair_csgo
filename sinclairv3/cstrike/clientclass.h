#pragma once

#include "defines.h"

#include "../game/memory/memory.h"
#include "../math/math.h"

#include <cstdint>

class DVariant {
public:
	union {
		float	as_float;
		long	as_nt;
		char* as_string;
		void* as_data;
		math::point_3d_t<float> as_vector;
		int64_t	as_int64;
	};

	SendPropType vType;
};

class CRecvProxyData {
public:
	const RecvProp* recv_prop; //  The property it's receiving.
	DVariant		value; //  The value given to you to store.
	int				element; //  Which array element you're getting.
	int				object_id; //  The object being referred to.
};

struct RecvProp {
	//  This info comes from the receive data table.

	char* var_name;
	int						recv_type;
	int						flags;
	int						string_buf_size;

	bool					inside_array;

	const void* extra_data;

	RecvProp* array_prop;
	array_length_recv_proxy_t	array_length_proxy;

	recv_var_proxy_t			proxy_fn;
	data_table_recv_var_proxy_t	data_table_proxy_fn;

	RecvTable* data_table;
	int						offset;

	int						element_stride;
	int						elements;

	const char* parent_array_prop_name;
};

struct RecvTable {
	RecvProp* props;
	int				props_len;

	CRecvDecoder* decoder;

	char* net_table_name;

private:
	bool			initialized;
	bool			in_main_list;
};

struct ClientClass {
	create_client_class_t		create_fn;
	create_event_t create_event_fn; //  Only called for event objects.
	char* network_name;
	RecvTable* recv_table;
	ClientClass* next;
	ClassIds						class_id; //  Managed by the engine.
};
