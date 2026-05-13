#ifdef ENCODER_ENABLE
#include QMK_KEYBOARD_H
#include "enums.h"

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == EN_LEFT) {
        switch (get_highest_layer(layer_state)) {
            case _SWITCH:
                if (clockwise) {
                    tap_code(KC_BRIU);
                } else {
                    tap_code(KC_BRID);
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
        }
    } else if (index == EN_RIGHT) {
        switch (get_highest_layer(layer_state)) {
            case _GAMING:
            case _COLEMAK:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            case _RAISE:
            case _LOWER:
                if (clockwise) {
                    tap_code(KC_MS_WH_DOWN);
                } else {
                    tap_code(KC_MS_WH_UP);
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
                break;
        }
    }
    return true;
}
#endif

