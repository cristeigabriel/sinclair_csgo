#pragma once

#include "defines.h"

#include "../game/memory/memory.h"
#include "../math/math.h"

#include "sdk_hud_chat.h"

#define MAX_PLAYER_NAME_LENGTH 128
#define MAX_STEAM_ID_LENGTH 20
#define MAX_CUSTOM_FILES 4
#define SIGNED_GUID_LEN 32

class IBaseClientDLL {
private:
	enum indices {
		GET_ALL_CLASSES_INDEX = 8,
		IN_ACTIVATE_MOUSE_INDEX = 15,
		IN_DEACTIVATE_MOUSE_INDEX = 16,
		DISPATCH_USER_MESSAGE_INDEX = 38
	};

public:
	__forceinline ClientClass* get_all_classes() {
		return util::vtable::func::getter::the<ClientClass*, indices::GET_ALL_CLASSES_INDEX>(this);
	}

	__forceinline void in_activate_mouse() {
		return util::vtable::func::getter::the<void, indices::IN_ACTIVATE_MOUSE_INDEX>(this);
	}

	__forceinline void in_deactivate_mouse() {
		return util::vtable::func::getter::the<void, indices::IN_DEACTIVATE_MOUSE_INDEX>(this);
	}

	__forceinline bool dispatch_user_message(int msg_type, uint32_t pass_through_flags, uint32_t size, const void* msg = nullptr) {
		return util::vtable::func::getter::the<bool, indices::DISPATCH_USER_MESSAGE_INDEX>(this, msg_type, pass_through_flags, size, msg);
	}
};

class CHLClient {
public:
	char pad_0000[28]; //0x0000
	CHudChat* chat_element; //0x001C
	char pad_0020[8]; //0x0020
	int32_t screen_x; //0x0028
	int32_t screen_y; //0x002C
	char pad_0030[16]; //0x0030
}; //Size: 0x0040

struct player_info_t {
	//	version for future compatibility
	uint64_t version;
	union {
		//	steamid64
		uint64_t steam_id64;
		struct {
			uint32_t xuid_low;
			uint32_t xuid_high;
		};
	};
	//	scoreboard information
	char name[MAX_PLAYER_NAME_LENGTH];
	//	local server user ID, unique while server is running
	int user_id;
	//	global unique player identifer
	char guid[SIGNED_GUID_LEN + 1];
	//	friends identification number
	uint32_t friends_id;
	//	friends name
	char friends_name[MAX_PLAYER_NAME_LENGTH];
	//	true, if player is a bot controlled by game.dll
	bool fake_player;
	//	true if player is the HLTV proxy
	bool is_hltv;
	//  custom files CRC for this player
	int custom_files[MAX_CUSTOM_FILES];
	//  this counter increases each time the server downloaded a new file
	uint8_t files_downloaded;
};

class IVEngineClient {
private:
	enum indices {
		CLIENT_CMD_INDEX = 7,
		GET_PLAYER_INFO_INDEX = 8,
		GET_PLAYER_FOR_UID_INDEX = 9,
		GET_LOCAL_PLAYER_INDEX = 12,
		GET_VIEW_ANGLES_INDEX = 18,
		SET_VIEW_ANGLES_INDEX = 19,
		GET_MAX_CLIENTS_INDEX = 20,
		IS_IN_GAME_INDEX = 26,
		IS_CONNECTED_INDEX = 27,
		GET_GAME_DIRECTORY_INDEX = 36,
		GET_LEVEL_NAME_INDEX = 53,
		GET_LEVEL_NAME_SHORT_INDEX = 54,
		IS_TAKING_SCREENSHOT_INDEX = 92,
		EXECUTE_CLIENT_CMD_INDEX = 108,
		CLIENT_CMD_UNRESTRICTED_INDEX = 114,
		SET_BLUR_FADE_INDEX = 180,
		IS_VOICE_RECORDING_INDEX = 224
	};

public:
	__forceinline void client_cmd(const char* command) {
		return util::vtable::func::getter::the<void, indices::CLIENT_CMD_INDEX>(this, command);
	}

	__forceinline bool get_player_info(int entity_index, const player_info_t* info) {
		return util::vtable::func::getter::the<bool, indices::GET_PLAYER_INFO_INDEX>(this, entity_index, info);
	}

	__forceinline int get_player_for_userid(int userid) {
		return util::vtable::func::getter::the<int, indices::GET_PLAYER_FOR_UID_INDEX>(this, userid);
	}

	__forceinline int get_local_player() {
		return util::vtable::func::getter::the<int, indices::GET_LOCAL_PLAYER_INDEX>(this);
	}

	__forceinline void get_view_angles(math::point_3d_t<float>* angle) {
		return util::vtable::func::getter::the<void, indices::GET_VIEW_ANGLES_INDEX>(this, angle);
	}

	__forceinline void set_view_angles(math::point_3d_t<float>* angle) {
		return util::vtable::func::getter::the<void, indices::SET_VIEW_ANGLES_INDEX>(this, angle);
	}

	__forceinline int get_max_clients() {
		return util::vtable::func::getter::the<int, indices::GET_MAX_CLIENTS_INDEX>(this);
	}

	__forceinline bool is_in_game() {
		return util::vtable::func::getter::the<bool, indices::IS_IN_GAME_INDEX>(this);
	}

	__forceinline bool is_connected() {
		return util::vtable::func::getter::the<bool, indices::IS_CONNECTED_INDEX>(this);
	}

	__forceinline bool is_in_game_and_connected() {
		return is_in_game() && is_connected();
	}

	__forceinline const char* get_game_directory() {
		return util::vtable::func::getter::the<const char*, indices::GET_GAME_DIRECTORY_INDEX>(this);
	}

	__forceinline const char* get_level_name() {
		return util::vtable::func::getter::the<const char*, indices::GET_LEVEL_NAME_INDEX>(this);
	}

	__forceinline const char* get_level_name_short() {
		return util::vtable::func::getter::the<const char*, indices::GET_LEVEL_NAME_SHORT_INDEX>(this);
	}

	__forceinline bool is_taking_screenshot() {
		return util::vtable::func::getter::the<bool, indices::IS_TAKING_SCREENSHOT_INDEX>(this);
	}

	__forceinline void execute_client_cmd(const char* command) {
		return util::vtable::func::getter::the<void, indices::EXECUTE_CLIENT_CMD_INDEX>(this, command);
	}

	__forceinline void client_cmd_unrestricted(const char* command) {
		return util::vtable::func::getter::the<void, indices::CLIENT_CMD_UNRESTRICTED_INDEX>(this, command);
	}

	__forceinline void set_blur_fade(float scale) {
		return util::vtable::func::getter::the<void, indices::SET_BLUR_FADE_INDEX>(this, scale);
	}

	__forceinline bool is_voice_recording() {
		return util::vtable::func::getter::the<bool, indices::IS_VOICE_RECORDING_INDEX>(this);
	}
};
