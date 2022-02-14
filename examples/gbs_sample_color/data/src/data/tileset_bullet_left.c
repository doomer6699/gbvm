#pragma bank 255

// Tileset: tileset_bullet_left

#include "gbs_types.h"

BANKREF(tileset_bullet_left)

const struct tileset_t tileset_bullet_left = {
    .n_tiles = 8,
    .tiles = {
        0x00, 0x00, 0x20, 0x00, 0xCC, 0x80, 0x86, 0x00, 0x80, 0x88, 0xDC, 0x00, 0xFE, 0x00, 0xFE, 0x00,
        0xEC, 0x00, 0xE0, 0x06, 0xF0, 0x00, 0xFE, 0x80, 0xF6, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x02, 0x00, 0x0F, 0x03, 0x1C, 0x0F, 0x32, 0x1D, 0x37, 0x19, 0x6F, 0x30, 0x63, 0x3C,
        0x63, 0x3C, 0x6F, 0x30, 0x37, 0x19, 0x32, 0x1D, 0x1C, 0x0F, 0x0F, 0x03, 0x03, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x04, 0x00, 0xC0, 0xC0, 0xE0, 0x02, 0xF8, 0x80, 0xFC, 0x00, 0xE4, 0x01, 0xF0, 0x02,
        0xF0, 0x00, 0xC0, 0x00, 0xDF, 0x00, 0xFF, 0x80, 0xEC, 0x00, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x03, 0x00, 0x0F, 0x03, 0x1C, 0x0F, 0x32, 0x1D, 0x37, 0x19, 0x6F, 0x30, 0x63, 0x3C,
        0x63, 0x3C, 0x6F, 0x30, 0x37, 0x19, 0x32, 0x1D, 0x1C, 0x0F, 0x0F, 0x03, 0x03, 0x00, 0x00, 0x00
    }
};