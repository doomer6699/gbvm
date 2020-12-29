#pragma bank 1

#include "Trigger.h"
#include "vm.h"

trigger_t triggers[MAX_TRIGGERS];
UBYTE triggers_active[MAX_ACTIVE_TRIGGERS];
UBYTE triggers_active_size = 0;
UBYTE triggers_len = 0;
UBYTE last_trigger_tx = 0;
UBYTE last_trigger_ty = 0;

void TriggerRunScript(UBYTE i) {
  ExecuteScript(triggers[i].script.bank, triggers[i].script.ptr, 0, 0);
}

UBYTE ActivateTriggerAt(UBYTE tx, UBYTE ty, UBYTE force) __banked {
  UBYTE hit_trigger;

  // Don't reactivate trigger if not changed tile
  if (!force && ((tx == last_trigger_tx) && (ty == last_trigger_ty))) {
    return FALSE;
  }

  hit_trigger = TriggerAtTile(tx, ty);
  last_trigger_tx = tx;
  last_trigger_ty = ty;

  if (hit_trigger != NO_TRIGGER_COLLISON) {
    TriggerRunScript(hit_trigger);
    return TRUE;
  }

  return FALSE;
}

UBYTE TriggerAtTile(UBYTE tx_a, UBYTE ty_a) __banked {
  UBYTE i, tx_b, ty_b, tx_c, ty_c;

  for (i = 0; i != triggers_len; i++) {
    tx_b = triggers[i].x;
    ty_b = triggers[i].y;
    tx_c = tx_b + triggers[i].width - 1;
    ty_c = ty_b + triggers[i].height - 1;

    if ((tx_a + 1) >= tx_b && tx_a <= tx_c && ty_a >= ty_b && ty_a <= ty_c) {
      return i;
    }
  }

  return NO_TRIGGER_COLLISON;
}