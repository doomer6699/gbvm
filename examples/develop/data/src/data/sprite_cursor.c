#pragma bank 255
// SpriteSheet: cursor
  
#include "gbs_types.h"
#include "data/tileset_cursor.h"

BANKREF(sprite_cursor)

#define SPRITE_11_STATE_DEFAULT 0
#define SPRITE_11_STATE_OPEN 0

const metasprite_t sprite_cursor_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t sprite_cursor_metasprite_1[]  = {
    {metasprite_end}
};

const metasprite_t * const sprite_cursor_metasprites[] = {
    sprite_cursor_metasprite_0,
    sprite_cursor_metasprite_1
};

const struct animation_t sprite_cursor_animations[] = {
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 1,
        .end = 1
    },
    {
        .start = 1,
        .end = 1
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
        .start = 1,
        .end = 1
    },
    {
        .start = 1,
        .end = 1
    }
};

const UWORD sprite_cursor_animations_lookup[] = {
    SPRITE_11_STATE_DEFAULT
};

const struct spritesheet_t sprite_cursor = {
    .n_metasprites = 2,
    .emote_origin = {
        .x = 0,
        .y = -16
    },
    .metasprites = sprite_cursor_metasprites,
    .animations = sprite_cursor_animations,
    .animations_lookup = sprite_cursor_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_cursor),
    .cgb_tileset = { NULL, NULL }
};
