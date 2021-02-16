#pragma once

#include "defines.h"

#include "../game/memory/memory.h"
#include "../math/math.h"

struct mstudiobone_t {
    int					sznameindex;
    inline char* const pszName(void) const { return ((char*)this) + sznameindex; }
    int		 			parent;		//  parent bone
    int					bonecontroller[6];	//  bone controller index, -1 == none

    //  default 
    math::point_3d_t<float> pos;
    math::point_4d_t<float> quat;
    math::point_3d_t<float> rot;
    //  compression scale
    math::point_3d_t<float> posscale;
    math::point_3d_t<float> rotscale;

    math::matrix<float, 3, 4> pose_to_bone;
    math::point_4d_t<float> alignment;
    int flags;
    int proctype;
    int procindex;  //  procedural rule
    mutable int physicsbone; //  index into physically simulated bone
    inline void* pProcedure() const { if (procindex == 0) return NULL; else return  (void*)(((uint8_t*)this) + procindex); };
    int					surfacepropidx;	//  index into string tablefor property name           
    inline char* const pszSurfaceProp(void) const { return ((char*)this) + surfacepropidx; }
    inline int			GetSurfaceProp(void) const { return surfacepropLookup; }
    int					contents;		//  See BSPFlags.h for the contents flags
    int					surfacepropLookup;	//  this index must be cached by the loader, not saved in the file
    int					unused[7];		//  remove as appropriate
};

struct mstudiobbox_t {
    int					bone;
    int					group;				//  intersection group
    math::point_3d_t<float>				bbmin;				//  bounding box, or the ends of the capsule if flCapsuleRadius > 0 
    math::point_3d_t<float>             bbmax;
    int					szhitboxnameindex;	//  offset to the name of the hitbox.
    math::point_3d_t<float> angOffsetOrientation;
    float				flCapsuleRadius;
    int unused[4];

    const char* pszHitboxName() const {
        if (szhitboxnameindex == 0)
            return "";

        return ((const char*)this) + szhitboxnameindex;
    }
};

struct mstudiohitboxset_t {
    int					sznameindex;
    inline char* const	pszName(void) const { return ((char*)this) + sznameindex; }
    int					numhitboxes;
    int					hitboxindex;
    inline mstudiobbox_t* pHitbox(int i) const { return (mstudiobbox_t*)(((uint8_t*)this) + hitboxindex) + i; };
};

struct studiohdr_t {
    int					id;
    int					version;

    int				checksum;		//  this has to be the same in the phy and vtx files to load!

    char				name[64];

    int					length;

    math::point_3d_t<float>				eyeposition;	//  ideal eye position

    math::point_3d_t<float>				illumposition;	//  illumination center

    math::point_3d_t<float>				hull_min;		//  ideal movement hull size
    math::point_3d_t<float>				hull_max;

    math::point_3d_t<float>				view_bbmin;		//  clipping bounding box
    math::point_3d_t<float>				view_bbmax;


    int					flags;

    int					numbones;			//  bones
    int					boneindex;

    inline const mstudiobone_t* pBone(int i) const { assert(i >= 0 && i < numbones); return (mstudiobone_t*)(((uint8_t*)this) + boneindex) + i; };

    int					RemapSeqBone(int iSequence, int iLocalBone) const;	//  maps local sequence bone to global bone
    int					RemapAnimBone(int iAnim, int iLocalBone) const;		//  maps local animations bone to global bone

    int					numbonecontrollers;		//  bone controllers
    int					bonecontrollerindex;

    int					numhitboxsets;
    int					hitboxsetindex;


    //  Look up hitbox set by index
    mstudiohitboxset_t* pHitboxSet(int i) const {
        assert(i >= 0 && i < numhitboxsets);
        return (mstudiohitboxset_t*)(((uint8_t*)this) + hitboxsetindex) + i;
    };

    //  Calls through to hitbox to determine size of specified set
    inline mstudiobbox_t* pHitbox(int i, int set) const {
        mstudiohitboxset_t const* s = pHitboxSet(set);
        if (!s)
            return NULL;

        return s->pHitbox(i);
    };


    //  Calls through to set to get hitbox count for set
    inline int			iHitboxCount(int set) const {
        mstudiohitboxset_t const* s = pHitboxSet(set);
        if (!s)
            return 0;

        return s->numhitboxes;
    };
};

class CModelInfo {
public:
    enum indices {
        GET_MODEL_INDEX = 2,
        GET_MODEL_INDEX_INDEX = 2,
        GET_MODEL_NAME_INDEX = 4,
        GET_MODEL_MATERIALS_INDEX = 18,
        GET_STUDIO_MODEL_INDEX = 31
    };
public:
    __forceinline model_t* get_model(int index) {
        return util::vtable::func::getter::the<model_t*, indices::GET_MODEL_INDEX>(this, index);
    }

    __forceinline int get_model_index(const char* filename) {
        return util::vtable::func::getter::the<int, indices::GET_MODEL_INDEX_INDEX>(this, filename);
    }

    __forceinline const char* get_model_name(const void* modelname) {
        return util::vtable::func::getter::the<const char*, indices::GET_MODEL_NAME_INDEX>(this, modelname);
    }

    __forceinline void get_model_materials(const model_t* model, int count, IMaterial** ppmaterial) {
        return util::vtable::func::getter::the<void, indices::GET_MODEL_MATERIALS_INDEX>(this, model, count, ppmaterial);
    }

    __forceinline studiohdr_t* get_studio_model(const model_t* model) {
        return util::vtable::func::getter::the<studiohdr_t*, indices::GET_STUDIO_MODEL_INDEX>(this, model);
    }
};