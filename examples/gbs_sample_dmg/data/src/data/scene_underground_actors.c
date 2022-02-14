#pragma bank 255

// Scene: Underground
// Actors

#include "gbs_types.h"
#include "data/sprite_signpost.h"
#include "data/script_s6a0_interact.h"
#include "data/sprite_ice.h"
#include "data/script_s6a1_interact.h"
#include "data/sprite_rock.h"
#include "data/script_s6a2_interact.h"
#include "data/sprite_rock.h"
#include "data/script_s6a3_interact.h"
#include "data/sprite_rock.h"
#include "data/script_s6a4_interact.h"

BANKREF(scene_underground_actors)

const struct actor_t scene_underground_actors[] = {
    {
        // Actor 1,
        .pos = {
            .x = 56 * 16,
            .y = 200 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(sprite_signpost),
        .move_speed = 16,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s6a0_interact),
        .reserve_tiles = 0
    },
    {
        // Ice Block,
        .pos = {
            .x = 192 * 16,
            .y = 144 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(sprite_ice),
        .move_speed = 32,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s6a1_interact),
        .reserve_tiles = 0
    },
    {
        // Rock 3,
        .pos = {
            .x = 184 * 16,
            .y = 216 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(sprite_rock),
        .move_speed = 8,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s6a2_interact),
        .reserve_tiles = 0
    },
    {
        // Rock 2,
        .pos = {
            .x = 168 * 16,
            .y = 216 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(sprite_rock),
        .move_speed = 8,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s6a3_interact),
        .reserve_tiles = 0
    },
    {
        // Rock 1,
        .pos = {
            .x = 152 * 16,
            .y = 216 * 16
        },
        .bounds = {
            .left = 0,
            .bottom = 7,
            .right = 15,
            .top = -8
        },
        .dir = DIR_DOWN,
        .sprite = TO_FAR_PTR_T(sprite_rock),
        .move_speed = 8,
        .anim_tick = 15,
        .pinned = FALSE,
        .collision_group = COLLISION_GROUP_NONE,
        .collision_enabled = TRUE,
        .script = TO_FAR_PTR_T(script_s6a4_interact),
        .reserve_tiles = 0
    }
};