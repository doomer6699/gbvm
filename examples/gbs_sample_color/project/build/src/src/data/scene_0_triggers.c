#pragma bank 255

// Scene: Sample Town
// Triggers

#include "gbs_types.h"
#include "data/script_s0t0_interact.h"
#include "data/script_s0t1_interact.h"
#include "data/script_s0t2_interact.h"
#include "data/script_s0t3_interact.h"
#include "data/script_s0t4_interact.h"
#include "data/script_s0t5_interact.h"
#include "data/script_s0t6_interact.h"
#include "data/script_s0t7_interact.h"
#include "data/script_s0t8_interact.h"
#include "data/script_s0t9_interact.h"
#include "data/script_s0t10_interact.h"
#include "data/script_s0t11_interact.h"
#include "data/script_s0t12_interact.h"
#include "data/script_s0t13_interact.h"

const void __at(255) __bank_scene_0_triggers;

const struct trigger_t scene_0_triggers[] = {
    {
        // Trigger 1,
        .x = 25,
        .y = 13,
        .width = 2,
        .height = 2,
        .script = TO_FAR_PTR_T(script_s0t0_interact)
    },
    {
        // Trigger 2,
        .x = 24,
        .y = 8,
        .width = 2,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s0t1_interact)
    },
    {
        // Trigger 3,
        .x = 10,
        .y = 8,
        .width = 2,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s0t2_interact)
    },
    {
        // Trigger 4,
        .x = 0,
        .y = 46,
        .width = 1,
        .height = 4,
        .script = TO_FAR_PTR_T(script_s0t3_interact)
    },
    {
        // Trigger 5,
        .x = 12,
        .y = 46,
        .width = 1,
        .height = 4,
        .script = TO_FAR_PTR_T(script_s0t4_interact)
    },
    {
        // Trigger 6,
        .x = 13,
        .y = 46,
        .width = 1,
        .height = 4,
        .script = TO_FAR_PTR_T(script_s0t5_interact)
    },
    {
        // Trigger 7,
        .x = 31,
        .y = 40,
        .width = 2,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s0t6_interact)
    },
    {
        // Trigger 8,
        .x = 16,
        .y = 40,
        .width = 2,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s0t7_interact)
    },
    {
        // Trigger 9,
        .x = 39,
        .y = 0,
        .width = 13,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s0t8_interact)
    },
    {
        // Trigger 10,
        .x = 36,
        .y = 20,
        .width = 7,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s0t9_interact)
    },
    {
        // Trigger 11,
        .x = 34,
        .y = 29,
        .width = 10,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s0t10_interact)
    },
    {
        // Trigger 12,
        .x = 44,
        .y = 28,
        .width = 9,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s0t11_interact)
    },
    {
        // Trigger 13,
        .x = 47,
        .y = 20,
        .width = 6,
        .height = 1,
        .script = TO_FAR_PTR_T(script_s0t12_interact)
    },
    {
        // Trigger 14,
        .x = 42,
        .y = 42,
        .width = 2,
        .height = 10,
        .script = TO_FAR_PTR_T(script_s0t13_interact)
    }
};
