#pragma bank 255

// Scene: Title Screen

#include "gbs_types.h"
#include "data/background_7.h"
#include "data/scene_3_collisions.h"
#include "data/scene_3_colors.h"
#include "data/palette_2.h"
#include "data/palette_4.h"
#include "data/script_s7_init.h"

const void __at(255) __bank_scene_7;

const struct scene_t scene_7 = {
  .width = 20,
  .height = 18,
  .type = SCENE_TYPE_LOGO,
  .background = TO_FAR_PTR_T(background_7),
  .collisions = TO_FAR_PTR_T(scene_3_collisions),
  .colors = TO_FAR_PTR_T(scene_3_colors),
  .palette = TO_FAR_PTR_T(palette_2),
  .sprite_palette = TO_FAR_PTR_T(palette_4),
  .n_actors = 0,
  .n_triggers = 0,
  .n_sprites = 0,
  .script_init = TO_FAR_PTR_T(script_s7_init)
};
