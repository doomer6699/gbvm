#pragma bank 255

// Tileset: tileset_torch

#include "gbs_types.h"

BANKREF(tileset_torch)

const struct tileset_t tileset_torch = {
    .n_tiles = 4,
    .tiles = {
        0xFE, 0xFE, 0xFA, 0x06, 0x32, 0xCE, 0x64, 0x9C, 0x48, 0xB8, 0x90, 0x70, 0xA0, 0x60, 0xC0, 0xC0,
        0x40, 0xC0, 0xC0, 0x40, 0xC0, 0x40, 0xC0, 0x40, 0xF0, 0x70, 0xCC, 0x7C, 0xF2, 0x0E, 0xCC, 0x3C,
        0x7F, 0x7F, 0x69, 0x7E, 0x74, 0x7F, 0x2A, 0x3F, 0x14, 0x1F, 0x0A, 0x0F, 0x04, 0x07, 0x03, 0x03,
        0x02, 0x03, 0x03, 0x03, 0x02, 0x03, 0x03, 0x03, 0x0E, 0x0F, 0x33, 0x3F, 0x47, 0x78, 0x31, 0x3E
    }
};
