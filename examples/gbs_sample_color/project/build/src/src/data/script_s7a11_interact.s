.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255



___bank_script_s7a11_interact = 255
.globl ___bank_script_s7a11_interact

_script_s7a11_interact::
        ; Call Script: Enemy Ship Destroy
        VM_PUSH_CONST           0 ; Actor .ARG2
        VM_CALL_FAR             ___bank_script_custom_3, _script_custom_3
        VM_POP                  1

        ; Stop Script
        VM_STOP
