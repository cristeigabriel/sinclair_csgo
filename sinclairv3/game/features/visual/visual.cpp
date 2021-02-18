#include "visual.h"

#include "../../../cstrike/cstrike.h"

#include "../../renderer/surface/surface.h"

namespace game {
    namespace features {
        namespace visual {
            namespace util {
                bool compute_2d_bounding_box(game::entities::player_t* entity,
                    math::point_4d_t<int>& out) {
                    //  Get entity mins/maxs
                    math::point_3d_t<float> mins, maxs;
                    if (!entity->compute_hitbox_surrounding_box(&mins, &maxs)) {
                        return false;
                    }

                    //	Thse Spectacular Mathematical Calculations are not awesome, (or mine on that note)

                    //	Computed box sides used in transformed points (screen) array
                    const math::point_t<float>& flb{ }, brt{ }, blb{ }, frt{ }, frb{ }, brb{ }, blt{ }, flt{ };

                    const math::point_3d_t<float> world[8] = {
                        { mins.x, mins.y, mins.z },
                        { mins.x, maxs.y, mins.z },
                        { maxs.x, maxs.y, mins.z },
                        { maxs.x, mins.y, mins.z },
                        { maxs.x, maxs.y, maxs.z },
                        { mins.x, maxs.y, maxs.z },
                        { mins.x, mins.y, maxs.z },
                        { maxs.x, mins.y, maxs.z }
                    };

                    //  Transformed points
                    math::point_3d_t<float> screen[8] = {
                        { blb.x, blb.y, 0.f },
                        { brb.x, brb.y, 0.f },
                        { frb.x, frb.y, 0.f },
                        { flb.x, flb.y, 0.f },
                        { frt.x, frt.y, 0.f },
                        { brt.x, brt.y, 0.f },
                        { blt.x, blt.y, 0.f },
                        { flt.x, flt.y, 0.f }
                    };

                    //  Calculate screen position points
                    for (int i = 0; i < 8; ++i) {
                        if (game::memory::interfaces::prototypes::debug_overlay->screen_position(world[i], screen[i])) {
                            return false;       
                        }
                    }

                    //  Get individual points
                    float left = screen[3].x;
                    float right = screen[3].x;
                    float bottom = screen[3].y;
                    float top = screen[3].y;

                    //  Assign individual points
                    for (int i = 0; i < 8; ++i) {
                        if (left > screen[i].x) {
                            left = screen[i].x;
                        }

                        if (right < screen[i].x) {
                            right = screen[i].x;
                        }

                        if (bottom < screen[i].y) {
                            bottom = screen[i].y;
                        }

                        if (top > screen[i].y) {
                            top = screen[i].y;
                        }
                    }

                    //  Assign to output 4-dimensional vector of points
                    out.x = (int)left;
                    out.y = (int)top;
                    out.z = (int)(right - left);
                    out.v = (int)(bottom - top);

                    return true;
                }
            }

            namespace esp {
                namespace paint {
                    void the() {
                        if (!game::memory::interfaces::prototypes::engine_client->is_in_game_and_connected()) {
                            return;
                        }

                        game::renderer::surface::set_color({ 0, 0, 0, 255 });

                        for (int i = 1; i < 65; ++i) {
                            game::entities::player_t* entity =
                                game::memory::interfaces::prototypes::entity_list->get<game::entities::player_t*>(i);

                            if (entity == nullptr || entity == game::entities::prototypes::local || !entity->alive())
                                continue;

                            math::point_4d_t<int> position;
                            if (!game::features::visual::util::compute_2d_bounding_box(entity, position))
                                continue;

                            //  Bounding box outline
                            game::renderer::surface::rectangle_outline<game::renderer::surface::ColorPreservation::COLOR_PRESERVE>
                                (position.x - 1, position.y - 1, position.z + 2, position.v + 2);
                            game::renderer::surface::rectangle_outline<game::renderer::surface::ColorPreservation::COLOR_PRESERVE>
                                (position.x + 1, position.y + 1, position.z - 2, position.v - 2);

                            //  Bounding box
                            game::renderer::surface::rectangle_outline(position.x, position.y, position.z, position.v);
                        }
                    }
                }
            }
        }
    }
}
