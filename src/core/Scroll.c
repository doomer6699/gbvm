#pragma bank 1

#include "Scroll.h"

#include "Actor.h"
#include "Camera.h"
#include "DataManager.h"
#include "GameTime.h"
#include "Math.h"
#include "FadeManager.h"
#include <string.h>
#include "map2buf.h"
#ifdef PARALLAX
    #include "parallax.h"
#endif
#include "data/data_ptrs.h"

void scroll_queue_row(INT16 x, INT16 y);
void scroll_queue_col(INT16 x, INT16 y);
void scroll_load_pending_row();
void scroll_load_pending_col();
void scroll_load_row(INT16 x, INT16 y);
void scroll_load_col(INT16 x, INT16 y, UBYTE height);
void scroll_render_rows(INT16 scroll_x, INT16 scroll_y, BYTE row_offset, BYTE n_rows);
UBYTE scroll_viewport(parallax_row_t * port);

INT16 scroll_x = 0;
INT16 scroll_y = 0;
INT16 draw_scroll_x = 0;
INT16 draw_scroll_y = 0;
UINT16 scroll_x_max = 0;
UINT16 scroll_y_max = 0;
INT16 scroll_offset_x = 0;
INT16 scroll_offset_y = 0;
INT16 pending_h_x, pending_h_y;
UINT8 pending_h_i;
INT16 pending_w_x, pending_w_y;
UINT8 pending_w_i;
INT16 current_row, new_row;
INT16 current_col, new_col;

inline UBYTE * WRAP_Y_9800(UBYTE * ptr) {
    return (UBYTE *)(((UWORD)ptr & 0x03ff) | 0x9800);
}
inline UBYTE * WRAP_X(UBYTE * ptr, UBYTE inc) {
    return (UBYTE *)(((UWORD)ptr & 0xffe0) | (((UWORD)ptr + inc) & 0x001f));
}

void scroll_init() __banked {
    pending_w_i = 0;
    pending_h_i = 0;
    scroll_x = 0x7FFF;
    scroll_y = 0x7FFF;
}

void scroll_update() __banked {
    INT16 x, y;
    UBYTE render = FALSE;

    x = camera_x - (SCREENWIDTH >> 1);
    y = camera_y - (SCREENHEIGHT >> 1);

    if (x & 0x8000u) {  // check for negative signed bit
        x = 0u;
    } else if (x > scroll_x_max) {
        x = scroll_x_max;
    }
    if (y & 0x8000u) {
        y = 0u;
    } else if (y > scroll_y_max) {
        y = scroll_y_max;
    }

    current_col = scroll_x >> 3;
    current_row = scroll_y >> 3;
    new_col = x >> 3;
    new_row = y >> 3;

    scroll_x = x;
    scroll_y = y;
    draw_scroll_x = x + scroll_offset_x;
    draw_scroll_y = y + scroll_offset_y;

    if (scroll_viewport(parallax_rows)) return;
    if (scroll_viewport(parallax_rows + 1)) return;
    scroll_viewport(parallax_rows + 2);
}

UBYTE scroll_viewport(parallax_row_t * port) {
    if (port->shift) {
        // Parallax
        UINT16 shift_scroll_x = draw_scroll_x >> port->shift;
        UBYTE shift_col;

        port->scx = shift_scroll_x;
        shift_col = shift_scroll_x >> 3;

        // If column is +/- 1 just render next column
        if (current_col == new_col - 1) {
            // Render right column
            scroll_load_col(shift_col - SCREEN_PAD_LEFT + SCREEN_TILE_REFRES_W - 1, port->start_tile, port->tile_height);
        } else if (current_col == new_col + 1) {
            // Render left column
            scroll_load_col(shift_col - SCREEN_PAD_LEFT, port->start_tile, port->tile_height);
        } else if (current_col != new_col) {
            // If column differs by more than 1 render entire viewport
            scroll_render_rows(shift_scroll_x, 0, port->start_tile, port->tile_height);
        }     
    } else {
        // No Parallax
        port->scx = draw_scroll_x;

        // If column is +/- 1 just render next column
        if (current_col == new_col - 1) {
            // Queue right column
            scroll_queue_col(new_col - SCREEN_PAD_LEFT + SCREEN_TILE_REFRES_W - 1, MAX((new_row - SCREEN_PAD_TOP), port->start_tile));
        } else if (current_col == new_col + 1) {
            // Queue left column
            scroll_queue_col(new_col - SCREEN_PAD_LEFT, MAX((new_row - SCREEN_PAD_TOP), port->start_tile));
        } else if (current_col != new_col) {
            // If column differs by more than 1 render entire screen
            scroll_render_rows(draw_scroll_x, draw_scroll_y, -SCREEN_PAD_TOP, SCREEN_TILE_REFRES_H);
            return !(port->next_y);
        }

        // If row is +/- 1 just render next row
        if (current_row == new_row - 1) {
            // Queue bottom row
            scroll_queue_row(new_col - SCREEN_PAD_LEFT,
                                    new_row - SCREEN_PAD_TOP + SCREEN_TILE_REFRES_H - 1);
        } else if (current_row == new_row + 1) {
            // Queue top row
            scroll_queue_row(new_col - SCREEN_PAD_LEFT, new_row - SCREEN_PAD_TOP);
        } else if (current_row != new_row) {
            // If row differs by more than 1 render entire screen
            scroll_render_rows(draw_scroll_x, draw_scroll_y, -SCREEN_PAD_TOP, SCREEN_TILE_REFRES_H);
            return !(port->next_y);
        }

        if (IS_FRAME_2) {
            if (pending_h_i) scroll_load_pending_col();
            if (pending_w_i) scroll_load_pending_row();
        }
    }

    return !(port->next_y);
}

void scroll_render_rows(INT16 scroll_x, INT16 scroll_y, BYTE row_offset, BYTE n_rows) {
    INT16 y;
    BYTE i;

    if (!fade_style)
    {
        DISPLAY_OFF
    } else if (!fade_timer == 0)
    {
// Immediately set all palettes black while screen renders.
#ifdef CGB
        if (_cpu == CGB_TYPE) {
            for (UBYTE c = 0; c != 32; ++c) {
                BkgPaletteBuffer[c] = RGB_BLACK;
            }
            set_bkg_palette(0, 8, BkgPaletteBuffer);
            set_sprite_palette(0, 8, BkgPaletteBuffer);
        } else
#endif
        OBP0_REG = 0xFF, BGP_REG = 0xFF;
    }

    // Clear pending rows/ columns
    pending_w_i = 0;
    pending_h_i = 0;

    BYTE end_row = row_offset + n_rows;
    y = scroll_y >> 3;
    for (i = row_offset; i != end_row && y != image_tile_height + 1; ++i, y++) {
        scroll_load_row((scroll_x >> 3) - SCREEN_PAD_LEFT, y + row_offset);
    }

    game_time = 0;

    DISPLAY_ON;
    if (!fade_timer == 0) {
        // Screen palate to nornmal if not fading
        fade_applypalettechange();
    }
}

void scroll_queue_row(INT16 x, INT16 y) {
    actor_t *actor;

    while (pending_w_i) {
        scroll_load_pending_row();
    }

    // Don't queue rows past image height
    if (y >= image_tile_height) {
        return;
    }

    pending_w_x = x;
    pending_w_y = y;
    pending_w_i = SCREEN_TILE_REFRES_W;

    // Activate Actors in Row
    actor = actors_inactive_head;
    while (actor) {
        INT16 ty = actor->y >> 3;
        if (ty == y) {
            INT16 tx = actor->x >> 3;
            if ((tx + 1 > x) && (tx < x + SCREEN_TILE_REFRES_W)) {
                actor_t * next = actor->next;
                activate_actor(actor);
                actor=next;
                continue;
            }
        }
        actor = actor->next;
    }
}

void scroll_queue_col(INT16 x, INT16 y) {
    actor_t *actor;
    
    while (pending_h_i) {
        // If previous column wasn't fully rendered
        // render it now before starting next column
        scroll_load_pending_col();
    }

    // Activate Actors in Column
    actor = actors_inactive_head;
    while (actor) {
        INT16 tx = actor->x >> 3;
        if (tx == x) {
            INT16 ty = actor->y >> 3;
            if ((ty > y) && (ty < y + SCREEN_TILE_REFRES_H)) {
                actor_t * next = actor->next;
                activate_actor(actor);
                actor=next;
                continue;
            }
        }
        actor = actor->next;
    }

    pending_h_x = x;
    pending_h_y = y;
    pending_h_i = MIN(SCREEN_TILE_REFRES_H, image_tile_height - y);
}

/* Update pending (up to 5) rows */
void scroll_load_pending_row() __nonbanked {
    UINT8 _save = _current_bank;
    UBYTE buf[PENDING_BATCH_SIZE];
    UBYTE a = MAX(0, pending_w_x), b = MAX(0, pending_w_y);
    UBYTE width = MIN(pending_w_i, PENDING_BATCH_SIZE);

#ifdef CGB
    if (_cpu == CGB_TYPE) {  // Color Row Load
        SWITCH_ROM_MBC1(image_attr_bank);
        VBK_REG = 1;
        get_map_from_buf(a, b, width, 1, buf, image_attr_ptr, image_tile_width, image_tile_height);
        set_bkg_tiles(MOD_32(a), MOD_32(b), width, 1, buf);
        VBK_REG = 0;
    }
#endif
    // DMG Row Load
    SWITCH_ROM_MBC1(image_bank);
    get_map_from_buf(a, b, width, 1, buf, image_ptr, image_tile_width, image_tile_height);
    set_bkg_tiles(MOD_32(a), MOD_32(b), width, 1, buf);

    pending_w_x += width;
    pending_w_i -= width;

    SWITCH_ROM_MBC1(_save);
}


void scroll_load_row(INT16 x, INT16 y) __nonbanked {
    UINT8 _save = _current_bank;
    UBYTE buf[SCREEN_TILE_REFRES_W];
    UBYTE a = MAX(0, x), b = MAX(0, y);

#ifdef CGB
    if (_cpu == CGB_TYPE) {  // Color Column Load
        VBK_REG = 1;
        SWITCH_ROM_MBC1(image_attr_bank);
        get_map_from_buf(a, b, SCREEN_TILE_REFRES_W, 1, buf, image_attr_ptr, image_tile_width, image_tile_height);
        set_bkg_tiles(MOD_32(a), MOD_32(b), SCREEN_TILE_REFRES_W, 1, buf);
        VBK_REG = 0;
    }
#endif
    // DMG Row Load
    SWITCH_ROM_MBC1(image_bank);
    get_map_from_buf(a, b, SCREEN_TILE_REFRES_W, 1, buf, image_ptr, image_tile_width, image_tile_height);
    set_bkg_tiles(MOD_32(a), MOD_32(b), SCREEN_TILE_REFRES_W, 1, buf);

    // Activate Actors in Row
    actor_t * actor = actors_inactive_head;
    while (actor) {
        INT16 ty = actor->y >> 3;
        if (ty == y) {
            INT16 tx = actor->x >> 3;
            if ((tx + 1 > x) && (tx < x + SCREEN_TILE_REFRES_W)) {
                actor_t * next = actor->next;
                activate_actor(actor);
                actor = next;
                continue;
            }
        }
        actor = actor->next;
    }

    SWITCH_ROM_MBC1(_save);
}

void scroll_load_col(INT16 x, INT16 y, UBYTE height) __nonbanked {
    UINT8 _save = _current_bank;
    UBYTE buf[SCREEN_TILE_REFRES_H];
    UBYTE a = MAX(0, x), b = MAX(0, y);
 
#ifdef CGB
    if (_cpu == CGB_TYPE) {  // Color Column Load
        SWITCH_ROM_MBC1(image_attr_bank);
        VBK_REG = 1;
        get_map_from_buf(a, b, 1, height, buf, image_attr_ptr, image_tile_width, image_tile_height);
        set_bkg_tiles(MOD_32(a), MOD_32(b), 1, height, buf);
        VBK_REG = 0;
    }
#endif
    // DMG Column Load
    unsigned char* map = image_ptr + image_tile_width * y + x;
    SWITCH_ROM_MBC1(image_bank);
    get_map_from_buf(a, b, 1, height, buf, image_ptr, image_tile_width, image_tile_height);
    set_bkg_tiles(MOD_32(a), MOD_32(b), 1, height, buf);
    SWITCH_ROM_MBC1(_save);
}

void scroll_load_pending_col() __nonbanked {
    UINT8 _save = _current_bank;
    UBYTE buf[PENDING_BATCH_SIZE];
    UBYTE a = MAX(0, pending_h_x), b = MAX(0, pending_h_y);
    UBYTE height = MIN(pending_h_i, PENDING_BATCH_SIZE);

    SWITCH_ROM_MBC1(image_bank);
#ifdef CGB
    if (_cpu == CGB_TYPE) {  // Color Column Load
        SWITCH_ROM_MBC1(image_attr_bank);
        VBK_REG = 1;
        get_map_from_buf(a, b, 1, height, buf, image_attr_ptr, image_tile_width, image_tile_height);
        set_bkg_tiles(MOD_32(a), MOD_32(b), 1, height, buf);
        VBK_REG = 0;
    }
#endif
    // DMG Column Load
    SWITCH_ROM_MBC1(image_bank);
    get_map_from_buf(a, b, 1, height, buf, image_ptr, image_tile_width, image_tile_height);
    set_bkg_tiles(MOD_32(a), MOD_32(b), 1, height, buf);

    pending_h_y += height;
    pending_h_i -= height;

    SWITCH_ROM_MBC1(_save);
}
