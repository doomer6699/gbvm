#pragma bank 255

// Background: underground

#include "gbs_types.h"
#include "data/tileset_0.h"

const void __at(255) __bank_background_4;

const struct background_t background_4 = {
  .width = 32,
  .height = 32,
  .tileset = TO_FAR_PTR_T(tileset_0),
  .tiles = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,143,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,145,0,0,146,147,148,148,148,147,148,147,148,147,148,147,148,147,147,148,147,148,147,147,148,147,148,147,147,148,147,148,147,149,0,0,146,150,151,151,151,150,151,150,151,150,151,150,151,150,150,151,150,151,150,150,151,150,151,150,150,151,150,151,150,149,0,0,146,152,153,154,155,156,152,152,153,152,153,154,152,153,154,155,156,152,153,152,153,154,152,153,154,155,156,152,153,149,0,0,146,0,0,166,167,166,167,166,167,166,167,166,167,166,167,166,167,166,167,166,167,166,167,166,167,166,167,0,0,149,0,0,146,166,167,168,169,168,169,168,169,168,169,168,169,168,169,168,169,168,169,168,169,168,169,168,169,168,169,166,167,149,0,0,146,168,169,114,114,114,114,114,114,114,114,114,114,114,170,171,114,114,114,114,114,114,114,170,171,114,114,168,169,149,0,0,146,166,167,114,114,114,114,114,114,114,114,114,114,114,172,173,114,114,114,114,114,114,114,172,173,114,114,166,167,149,0,0,146,168,169,114,114,170,171,114,114,114,114,114,114,114,174,175,114,114,114,114,114,114,114,114,114,114,114,168,169,149,0,0,146,166,167,114,114,172,173,114,114,114,114,114,114,114,176,177,114,114,114,114,114,114,114,114,114,114,114,166,167,149,0,0,146,168,169,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,168,169,149,0,0,146,166,167,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,166,167,149,0,0,146,168,169,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,168,169,149,0,0,146,166,167,114,114,114,114,114,114,114,114,114,114,114,114,114,170,171,114,114,114,114,114,114,114,114,114,166,167,149,0,0,146,168,169,114,114,114,114,114,114,114,114,114,114,114,114,114,172,173,114,114,114,114,114,114,114,114,114,168,169,149,0,0,146,166,167,114,114,114,114,170,171,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,166,167,149,0,0,146,168,169,114,114,114,114,172,173,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,168,169,149,0,0,146,166,167,166,167,166,167,166,167,166,167,166,167,166,167,166,167,166,167,166,167,166,167,0,0,166,167,166,167,149,0,0,146,168,169,168,169,168,169,168,169,168,169,168,169,168,169,168,169,168,169,168,169,168,169,0,0,168,169,168,169,149,0,0,146,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,149,0,0,146,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,149,0,0,146,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,166,167,166,167,0,0,166,167,166,167,0,0,0,149,0,0,146,0,0,0,0,0,0,0,0,0,0,0,0,0,166,167,168,169,168,169,0,0,168,169,168,169,0,0,0,149,0,0,146,0,0,0,0,0,0,0,0,0,0,0,0,0,168,169,166,167,0,0,0,0,0,0,166,167,0,0,0,149,0,0,146,0,0,0,0,0,0,0,0,0,0,0,0,0,166,167,168,169,0,0,0,0,0,0,168,169,0,166,167,149,0,0,146,0,0,0,0,0,0,0,0,0,0,0,0,0,168,169,166,167,0,0,0,0,0,0,166,167,0,168,169,149,0,0,146,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,168,169,0,0,0,0,0,0,168,169,0,0,0,149,0,0,146,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,166,167,0,0,0,0,0,0,166,167,0,166,167,149,0,0,146,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,168,169,0,0,0,0,0,0,168,169,0,168,169,149,0,0,157,158,158,158,158,158,158,158,158,158,158,158,158,158,158,158,158,158,158,159,160,161,162,158,158,158,158,158,158,163,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,146,164,165,149,0,0,0,0,0,0,0,0
  }
};