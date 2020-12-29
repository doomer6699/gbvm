#pragma bank 255

// Background: outside

#include "data/data_types.h"
#include "data/tileset_0.h"

const void __at(255) __bank_background_1;

const struct background_t background_1 = {
  .width = 32,
  .height = 32,
  .tileset = TO_FAR_PTR_T(tileset_0),
  .tiles = {
    0,1,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,6,7,8,7,8,7,7,8,7,8,7,8,7,8,9,10,11,12,13,14,11,12,13,14,11,12,13,14,11,12,13,14,6,8,7,8,7,8,8,7,8,15,8,7,8,7,16,17,18,19,20,21,18,19,20,21,18,19,20,21,18,19,20,21,22,7,23,24,8,15,7,8,7,8,7,8,7,8,25,7,8,26,25,7,8,26,25,7,8,26,25,7,8,26,25,7,6,27,28,29,27,27,8,7,8,7,8,7,8,7,30,31,7,8,7,8,7,8,32,33,32,32,32,32,27,7,8,7,6,6,27,27,27,27,7,15,7,8,7,8,7,8,13,34,7,7,8,7,8,15,35,36,36,36,36,37,27,8,7,8,22,22,6,27,27,27,27,27,8,7,8,7,8,7,38,21,7,8,7,8,7,8,39,40,40,40,40,41,27,7,8,7,6,6,22,42,43,43,43,42,43,42,43,42,43,42,25,7,8,7,8,7,8,7,44,45,46,47,45,48,27,8,7,8,7,8,6,49,50,50,51,52,50,49,50,49,50,49,30,31,7,8,7,8,7,8,53,54,55,56,53,54,27,7,8,7,8,7,15,43,43,42,57,58,42,43,43,42,59,3,13,34,8,7,8,7,8,7,27,15,8,7,8,7,8,7,7,8,7,8,7,8,7,8,7,8,7,8,7,8,60,12,38,21,7,8,7,8,7,8,7,8,7,8,7,8,7,8,8,7,8,15,8,7,8,7,8,7,8,7,8,7,18,19,25,7,8,7,15,7,8,7,8,7,8,7,8,7,8,7,7,8,7,8,7,8,7,8,7,8,7,8,7,8,27,26,30,31,7,8,59,3,30,31,7,8,7,8,7,8,7,8,8,7,8,7,8,7,8,7,8,7,8,7,8,7,59,3,13,34,8,15,60,12,13,34,8,7,8,7,8,7,8,7,7,15,7,8,7,8,7,8,7,61,62,8,7,8,60,12,38,21,7,8,18,19,20,21,7,8,7,8,7,8,15,8,7,8,8,7,8,7,8,7,8,63,64,7,8,15,18,19,25,7,8,7,7,26,25,8,8,7,8,7,8,7,8,7,8,7,8,7,8,27,27,27,27,27,27,27,27,27,27,26,30,31,7,8,7,8,7,8,7,8,7,8,7,8,7,7,7,8,7,8,15,27,27,27,27,27,27,27,27,27,59,3,13,34,8,7,8,7,8,7,8,7,8,7,8,15,8,65,66,66,66,66,66,66,66,66,66,66,66,67,27,27,60,12,38,21,7,8,7,8,7,8,27,27,27,68,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,69,27,18,19,25,7,8,7,8,7,8,7,27,68,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,27,27,26,30,31,15,8,7,8,7,8,27,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,8,59,3,13,34,8,7,8,7,8,7,8,70,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,7,60,12,38,21,7,8,7,8,7,8,7,8,7,27,71,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,72,8,18,19,25,7,8,7,8,7,8,7,8,7,8,7,8,7,73,66,66,66,66,66,66,66,66,66,66,66,74,7,8,7,27,26,30,31,7,8,7,8,7,8,7,8,7,8,7,8,7,8,15,8,7,8,7,8,7,8,7,8,7,8,7,8,59,3,13,34,8,7,8,7,8,7,8,7,8,7,8,7,8,7,8,7,8,7,8,7,8,7,8,7,8,7,8,7,60,12,38,21,7,8,7,8,7,8,7,8,7,8,7,8,7,8,7,8,7,8,7,8,7,8,7,8,7,8,7,8,18,19,25,7,15,7,8,7,8,7,8,7,8,7,8,7,15,7,8,7,8,7,8,7,8,7,8,7,8,7,8,7,27,26,30,31,59,3,30,31,59,3,30,31,59,3,30,31,59,3,30,31,59,3,30,31,59,3,30,31,59,3,30,31,59,3,13,34,60,12,13,34,60,12,13,34,60,12,13,34,60,12,13,34,60,12,13,34,60,12,13,34,60,12,13,34,60,12,2,3,4,5,75,3,4,5,75,3,4,5,75,3,4,5,75,3,4,5,75,3,4,5,75,3,4,5,75,3,4,5,11,12,13,14,11,12,13,14,11,12,13,14,11,12,13,14,11,12,13,14,11,12,13,14,11,12,13,14,11,12,13,14
  }
};