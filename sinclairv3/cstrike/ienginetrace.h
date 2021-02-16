#pragma once

#include "defines.h"

#include "../game/memory/memory.h"
#include "../math/math.h"

struct Ray_t {
	__declspec(align(16)) math::point_3d_t<float>  start;
	__declspec(align(16)) math::point_3d_t<float>  delta;
	__declspec(align(16)) math::point_3d_t<float>  start_offset;
	__declspec(align(16)) math::point_3d_t<float>  extents;
	const math::matrix<float, 3, 4>* world_axis_transform = nullptr;
	//without your matrix3x4
	bool	is_ray;
	bool	is_swept;

	__forceinline void init(math::point_3d_t<float> const& start, math::point_3d_t<float> const& end) {
		delta = end - start;

		is_swept = (delta.length_sqr() != 0);

		extents.x = extents.y = extents.z = 0.0f;

		is_ray = true;

		start_offset.x = start_offset.y = start_offset.z = 0.0f;

		this->start = start;
	}

	__forceinline void init(math::point_3d_t<float> const& start, math::point_3d_t<float> const& end, math::point_3d_t<float> const& mins, math::point_3d_t<float> const& maxs) {
		delta = end - start;

		world_axis_transform = nullptr;
		is_swept = (delta.length_sqr() != 0);

		extents = maxs - mins;
		extents *= 0.5f;
		is_ray = (extents.length_sqr() < 1e-6);

		start_offset = maxs + mins;
		start_offset *= 0.5f;
		this->start = math::point_3d_t<float>(start) + start_offset;
		start_offset *= -1.0f;
	}
};

struct cplane_t {
	math::point_3d_t<float>	normal;
	float	dist;
	uint8_t	type;			//  for fast side tests
	uint8_t	signbits;		//  signx + (signy<<1) + (signz<<1)
	char pad000[2];
};

class CBaseTrace {
public:
	math::point_3d_t<float>                  start_pos;
	math::point_3d_t<float>                  end_pos;
	cplane_t                plane;
	float                   fraction;
	int                             contents;
	unsigned short  disp_flags;
	bool                    all_solid;
	bool                    start_solid;
};

struct csurface_t {
	const char* name;
	short                   surface_props;
	unsigned short  flags;
};

class CGameTrace : public CBaseTrace {
public:

	//  Returns true if hEnt points at the world entity.
	//  If this returns true, then you can't use GetHitBoxIndex().
	bool dit_hit_world() const;

	//  Returns true if we hit something and it wasn't the world.
	bool did_hit_non_world_entity() const;

	//  Gets the entity's network index if the trace has hit an entity.
	//  If not, returns -1.
	int get_entity_index() const;

	//  Returns true if there was any kind of impact at all
	bool did_hit() const;
public:

	float		fraction_left_solid;		//  time we left a solid, only valid if we started in solid
	csurface_t	surface;				//  surface hit (impact surface)

	int			hit_group;				//  0 == generic, non-zero is specific body part
	short		physics_bone;			//  physics bone hit by trace in studio

#if defined( CLIENT_DLL )
	C_BaseEntity* m_pEnt;
#else
	//  Change when I add this
	void* ent;
#endif

	//  NOTE: this member is overloaded.
	//  If hEnt points at the world entity, then this is the static prop index.
	//  Otherwise, this is the hitbox index.
	int			hitbox;					//  box hit by trace in studio

	__forceinline CGameTrace() {}

private:
	//  No copy constructors allowed
	CGameTrace(const CGameTrace& vOther);
};


//-----------------------------------------------------------------------------
//  Returns true if there was any kind of impact at all
//-----------------------------------------------------------------------------
__forceinline bool CGameTrace::did_hit() const {
	return fraction < 1 || all_solid || start_solid;
}

__forceinline bool CGameTrace::dit_hit_world() const {
	return ent != nullptr;
}

__forceinline bool CGameTrace::did_hit_non_world_entity() const {
	return ent != nullptr && !dit_hit_world();
}

class ITraceFilter {
public:										//  IClientEntity
	virtual bool            should_hit_entity(void* pEntity, int contentsMask) = 0;
	virtual TraceType     get_trace_type() const = 0;
};

class CTraceFilter : public ITraceFilter {
public:					 //  IClientEntity
	bool should_hit_entity(void* entity_handle, int contents_mask) {
		return !(entity_handle == skip);
	}

	TraceType get_trace_type() const {
		return TRACE_EVERYTHING;
	}

	void* skip;
};

class CTraceFilterSkipTwoEntities : public ITraceFilter {
public:
	__forceinline CTraceFilterSkipTwoEntities(void* pass_ent1, void* pass_ent2) {
		skip1 = pass_ent1;
		skip2 = pass_ent2;
	}
	//  IClientEntity
	virtual bool should_hit_entity(void* entity_handle, int contents_mask) {
		return  !(entity_handle == skip1 || entity_handle == skip2);
	}
	virtual TraceType get_trace_type() const {
		return TRACE_EVERYTHING;
	}

	void* skip1;
	void* skip2;
};

class IEngineTraceClient {
public:
	virtual int		get_point_contents(const math::point_3d_t<float>& vec_abs_pos, int content_mask = MASK_ALL, void** entity = nullptr) = 0;
	virtual int		get_point_contents_world_only(const math::point_3d_t<float>& vec_abs_pos, int content_mask = MASK_ALL) = 0;
	virtual int		get_point_contents_collideable(void* collide, const math::point_3d_t<float>& vec_abs_pos) = 0;
	//  IClientEntity
	virtual void	clip_ray_to_entity(const Ray_t& ray, unsigned int fmask, void* ent, CGameTrace* trace) = 0;
	virtual void	clip_ray_to_collideable(const Ray_t& ray, unsigned int fmask, void* collide, CGameTrace* trace) = 0;
	virtual void	trace_ray(const Ray_t& ray, unsigned int fmask, ITraceFilter* trace_filter, CGameTrace* trace) = 0;
};
