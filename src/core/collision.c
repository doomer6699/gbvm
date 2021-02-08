#include "collision.h"

#include "data_manager.h"

#define MAX_UINT8 0xFF

UBYTE bb_contains(bounding_box_t *bb, upoint16_t *offset, upoint16_t *point) {
    if ((point->x < (offset->x >> 4) + bb->left) || 
        (point->x > (offset->x >> 4) + bb->right)) return FALSE;
    if ((point->y < (offset->y >> 4) + bb->top) || 
        (point->y > (offset->y >> 4) + bb->bottom)) return FALSE;
    return TRUE;
}

UBYTE bb_intersects(bounding_box_t *bb_a, upoint16_t *offset_a, bounding_box_t *bb_b, upoint16_t *offset_b) {
    if (((offset_b->x >> 4) + bb_b->left   > (offset_a->x >> 4) + bb_a->right) ||
        ((offset_b->x >> 4) + bb_b->right  < (offset_a->x >> 4) + bb_a->left)) return FALSE;
    if (((offset_b->y >> 4) + bb_b->top    > (offset_a->y >> 4) + bb_a->bottom) ||
        ((offset_b->y >> 4) + bb_b->bottom < (offset_a->y >> 4) + bb_a->top)) return FALSE;
    return TRUE;
}

UBYTE tile_at(UBYTE tx, UBYTE ty) {
    UBYTE _save = _current_bank;
    UWORD y_offset;
    UBYTE tile;

    // Check tile outside of bounds
    if (tx == MAX_UINT8 || tx == image_tile_width || ty == image_tile_height ||
        ty == MAX_UINT8) {
        return COLLISION_ALL;
    }

    y_offset = ty * (UINT16)image_tile_width;

    SWITCH_ROM_MBC1(collision_bank);
    tile = (UBYTE) * (collision_ptr + y_offset + tx);
    SWITCH_ROM_MBC1(_save);

    return tile;
}

UBYTE tile_at_2x1(UBYTE tx, UBYTE ty) {
    UBYTE _save = _current_bank;
    UBYTE* collision_ptr_tmp;
    UBYTE tile;

    // Check tile outside of bounds
    if (tx == MAX_UINT8 || tx == image_tile_width || ty == image_tile_height ||
        ty == MAX_UINT8) {
        return COLLISION_ALL;
    }

    // Get y_offset with ty * width. Then add tx + collision_ptr offset
    collision_ptr_tmp = ty * (UINT16)image_tile_width + tx + collision_ptr;

    SWITCH_ROM_MBC1(collision_bank);
    tile = (UBYTE)*collision_ptr_tmp | (UBYTE) * (collision_ptr_tmp + 1U);
    SWITCH_ROM_MBC1(_save);

    return tile;
}

UBYTE tile_at_2x2(UBYTE tx, UBYTE ty) {
    UBYTE _save = _current_bank;
    UBYTE* collision_ptr_tmp;
    UBYTE tile;

    // Check tile outside of bounds
    if (tx == MAX_UINT8 || tx == image_tile_width || ty == image_tile_height ||
        ty == MAX_UINT8) {
        return COLLISION_ALL;
    }

    // Get y_offset with ty * width. Then add tx + collision_ptr offset
    collision_ptr_tmp = ty * (UINT16)image_tile_width + tx + collision_ptr;

    SWITCH_ROM_MBC1(collision_bank);
    tile = (UBYTE) * (collision_ptr_tmp);
    if (!tile) {
        tile = (UBYTE) * (collision_ptr_tmp + 1U);
        if (!tile) {
            // add 1 more y_offset
            collision_ptr_tmp = collision_ptr_tmp + (UINT16)image_tile_width;
            tile = (UBYTE) * (collision_ptr_tmp);
            if (!tile) {
                tile = (UBYTE) * (collision_ptr_tmp + 1U);
            }
        }
    } 
    SWITCH_ROM_MBC1(_save);

    return tile;
}