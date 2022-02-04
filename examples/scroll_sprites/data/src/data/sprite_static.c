#pragma bank 255
// SpriteSheet: static
  
#include "gbs_types.h"
#include "data/tileset_static.h"

BANKREF(sprite_static)

#define SPRITE_3_STATE_DEFAULT 0

const metasprite_t sprite_static_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t * const sprite_static_metasprites[] = {
    sprite_static_metasprite_0
};

const struct animation_t sprite_static_animations[] = {
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 0,
        .end = 0
    }
};

const UWORD sprite_static_animations_lookup[] = {
    SPRITE_3_STATE_DEFAULT
};

const struct spritesheet_t sprite_static = {
    .n_metasprites = 1,
    .emote_origin = {
        .x = 0,
        .y = -16
    },
    .metasprites = sprite_static_metasprites,
    .animations = sprite_static_animations,
    .animations_lookup = sprite_static_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_static),
    .cgb_tileset = { NULL, NULL }
};
