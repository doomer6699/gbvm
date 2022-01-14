#pragma bank 255

// Tileset: 5

#include "gbs_types.h"

BANKREF(tileset_5)

const struct tileset_t tileset_5 = {
    .n_tiles = 4,
    .tiles = {
        0x00, 0x00, 0xE0, 0xE0, 0xF0, 0xF0, 0xF8, 0x78, 0x3C, 0xFC, 0x3E, 0xFE, 0x1E, 0xFE, 0xDE, 0xBE,
        0x9E, 0x7E, 0x0E, 0xFE, 0xCE, 0xFE, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0, 0xE0, 0x00, 0x00,
        0x00, 0x00, 0x07, 0x07, 0x0F, 0x0F, 0x1F, 0x1C, 0x3E, 0x3D, 0x7E, 0x7D, 0x7C, 0x7B, 0x7D, 0x7B,
        0x7D, 0x7A, 0x78, 0x77, 0x7B, 0x77, 0x3F, 0x3F, 0x1F, 0x1F, 0x0F, 0x0F, 0x07, 0x07, 0x00, 0x00
    }
};
