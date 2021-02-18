#pragma once

#include <cstdint>

#include "enums.h"

typedef uintptr_t CBaseHandle;
typedef uintptr_t HCursor;
typedef uintptr_t HTexture;
typedef uintptr_t HFont;
typedef uintptr_t HPanel;
typedef uintptr_t MaterialHandle;

class bf_read;
class bf_write;

class CClientThinkHandlePtr;
typedef CClientThinkHandlePtr* ClientThinkHandle_t;

class CRecvDecoder;
class DVariant;
class CRecvProxyData;
struct RecvProp;
struct RecvTable;
struct ClientClass;

class CSaveRestoreData;

class CHudChat;
class CCSGO_HudChat;

class CUserCmd;

class CConVar;
class ICVar;

struct model_t;

class IBaseClientDLL;
class CHLClient;
class CGlobalVarsBase;
struct player_info_t;
class IVEngineClient;
class IClientEntityList;
class IInputSystem;
class IEngineTraceClient;
class IMaterial;
struct mstudiobone_t;
struct mstudiobbox_t;
struct mstudiohitboxset_t;
struct studiohdr_t;
class CModelInfo;
class IMaterialSystem;
class CCSWeaponData;
class INetMessage;
class ISurface;
class IMaterial;
class IMaterialVar;
class IVModelRender;
class CIVDebugOverlay;
class SurfacePlat;
class VPanel;

typedef void(__thiscall* start_drawing_t)(void*);
typedef void(__thiscall* finish_drawing_t)(void*);

typedef void* (*create_client_class_t)(int entity_number, int serial_number);
typedef void* (*create_event_t)();

typedef void(*recv_var_proxy_t)(const CRecvProxyData* proxy_data, void* data, void* out);
typedef void(*data_table_recv_var_proxy_t)(const RecvProp* prop, void** out, void* data, int object_id);
typedef void(*array_length_recv_proxy_t)(void* data, int object_id, int current_array_length);
typedef void(*convar_callback_t)(CConVar* convar, const char* old_svalue, float old_value);


//  actual defines, sorry, this could've been an enum but i'm lazy :p
#define FCVAR_UNREGISTERED		(1<<0)	//  If this is set, don't add to linked list, etc.
#define FCVAR_DEVELOPMENTONLY	(1<<1)	//  Hidden in released products. Flag is removed automatically if ALLOW_DEVELOPMENT_CVARS is defined.
#define FCVAR_GAMEDLL			(1<<2)	//  defined by the game DLL
#define FCVAR_CLIENTDLL			(1<<3)  //  defined by the client DLL
#define FCVAR_HIDDEN			(1<<4)	//  Hidden. Doesn't appear in find or auto complete. Like DEVELOPMENTONLY, but can't be compiled out.

//  ConVar only
#define FCVAR_PROTECTED			(1<<5)  //  It's a server cvar, but we don't send the data since it's a password, etc.  Sends 1 if it's not bland/zero, 0 otherwise as value
#define FCVAR_SPONLY			(1<<6)  //  This cvar cannot be changed by clients connected to a multiplayer server.
#define	FCVAR_ARCHIVE			(1<<7)	//  set to cause it to be saved to vars.rc
#define	FCVAR_NOTIFY			(1<<8)	//  notifies players when changed
#define	FCVAR_USERINFO			(1<<9)	//  changes the client's info string

#define FCVAR_PRINTABLEONLY		(1<<10)  //  This cvar's string cannot contain unprintable characters ( e.g., used for player name etc ).

#define FCVAR_GAMEDLL_FOR_REMOTE_CLIENTS		(1<<10)  //  When on concommands this allows remote clients to execute this cmd on the server. 
                             //  We are changing the default behavior of concommands to disallow execution by remote clients without
                             //  this flag due to the number existing concommands that can lag or crash the server when clients abuse them.

#define FCVAR_UNLOGGED			(1<<11)  //  If this is a FCVAR_SERVER, don't log changes to the log file / console if we are creating a log
#define FCVAR_NEVER_AS_STRING	(1<<12)  //  never try to print that cvar

//  texture group names
// These are given to FindMaterial to reference the texture groups that show up on the 
#define TEXTURE_GROUP_LIGHTMAP						"Lightmaps"
#define TEXTURE_GROUP_WORLD							"World textures"
#define TEXTURE_GROUP_MODEL							"Model textures"
#define TEXTURE_GROUP_STATIC_PROP					"StaticProp textures"
#define TEXTURE_GROUP_COMBINED						"Combined Textures"
#define TEXTURE_GROUP_COMPOSITE						"Composited Textures"
#define TEXTURE_GROUP_VGUI							"VGUI textures"
#define TEXTURE_GROUP_PARTICLE						"Particle textures"
#define TEXTURE_GROUP_DECAL							"Decal textures"
#define TEXTURE_GROUP_SKYBOX						"SkyBox textures"
#define TEXTURE_GROUP_CLIENT_EFFECTS				"ClientEffect textures"
#define TEXTURE_GROUP_OTHER							"Other textures"
#define TEXTURE_GROUP_PRECACHED						"Precached"				// TODO: assign texture groups to the precached materials
#define TEXTURE_GROUP_CUBE_MAP						"CubeMap textures"
#define TEXTURE_GROUP_RENDER_TARGET					"RenderTargets"
#define TEXTURE_GROUP_UNACCOUNTED					"Unaccounted textures"	// Textures that weren't assigned a texture group.
//#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER		"Static Vertex"
#define TEXTURE_GROUP_STATIC_INDEX_BUFFER			"Static Indices"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_DISP		"Displacement Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_COLOR	"Lighting Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_WORLD	"World Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_MODELS	"Model Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_OTHER	"Other Verts"
#define TEXTURE_GROUP_DYNAMIC_INDEX_BUFFER			"Dynamic Indices"
#define TEXTURE_GROUP_DYNAMIC_VERTEX_BUFFER			"Dynamic Verts"
#define TEXTURE_GROUP_DEPTH_BUFFER					"DepthBuffer"
#define TEXTURE_GROUP_VIEW_MODEL					"ViewModel"
#define TEXTURE_GROUP_PIXEL_SHADERS					"Pixel Shaders"
#define TEXTURE_GROUP_VERTEX_SHADERS				"Vertex Shaders"
#define TEXTURE_GROUP_RENDER_TARGET_SURFACE			"RenderTarget Surfaces"
#define TEXTURE_GROUP_MORPH_TARGETS					"Morph Targets"
#define TEXTURE_GROUP_SCALEFORM						"Scaleform textures"