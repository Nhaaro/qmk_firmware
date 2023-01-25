// vim: sw=4:sts=4:expandtab

 /* Copyright 2021 Dane Evans
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
  // SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 31

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
    {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
    {1, 6, hsv}, \
    {35+1, 6,hsv}
#define SET_NUMPAD(hsv)     \
    {35+15, 5, hsv},\
    {35+22, 3, hsv},\
    {35+27, 3, hsv}
#define SET_NUMROW(hsv) \
    {10, 2, hsv}, \
    {20, 2, hsv}, \
    {30, 2, hsv}, \
    {35+ 10, 2, hsv}, \
    {35+ 20, 2, hsv}, \
    {35+ 30, 2, hsv}
#define SET_INNER_COL(hsv)	\
    {33, 4, hsv}, \
    {35+ 33, 4, hsv}

#define SET_OUTER_COL(hsv) \
    {7, 4, hsv}, \
    {35+ 7, 4, hsv}
#define SET_THUMB_CLUSTER(hsv) 	\
    {25, 2, hsv}, \
    {35+ 25, 2, hsv}
#define SET_LAYER_ID(hsv) 	\
    {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {1, 6, hsv}, \
    {35+1, 6, hsv}, \
    {7, 4, hsv}, \
    {35+ 7, 4, hsv}, \
    {25, 2, hsv}, \
    {35+ 25, 2, hsv}


enum layers {
    _DEFAULTS = 0,
    _COLEMAK = 0,
    _GAMING,

    _LOWER,
    _RAISE,
    _ADJUST,

    _NUMPAD,
    _SWITCH
};

enum custom_keycodes {
    KC_COLEMAK = SAFE_RANGE,
    KC_GAMING,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,

    KC_DISC
};

enum encoders {
    EN_LEFT,
    EN_RIGHT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * COLEMAK-DH
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * | ESC   |   1   |   2   |   3   |   4   |   5   |                    |   6   |   7   |   8   |   9   |   0   |  `    |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * | TAB   |   Q   |   W   |   F   |   P   |   B   |                    |   J   |   L   |   U   |   Y   |   ;   | Bspc  |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * | LCTRL |   A   |   R   |   S   |   T   |   G   |-------.    ,-------|   M   |   N   |   E   |   I   |   O   |  '    |
 * |-------+-------+-------+-------+-------+-------|  MUTE |    |DISCORD|-------+-------+-------+-------+-------+-------|
 * | LSHFT |   Z   |   X   |   C   |   D   |   V   |-------|    |-------|   K   |   H   |   ,   |   .   |   /   |RShift |
 * `-----------------------------------------------/      /      \      \-----------------------------------------------'
 *                | CTRL | LGUI | LALT  | Space | /Space /        \ Enter\ | RAISE | Bspc  | Del  | AltGr|
 *                |      |      |       | LOWER |/      /          \      \|       |       |      |      |
 *                `-----------------------------'------'            '------'-----------------------------'
 */
            [_COLEMAK] = LAYOUT(
              //,-----------------------------------------------------.                   ,-----------------------------------------------------.
      LT(_NUMPAD, KC_ESC), KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,         LT(_SWITCH, KC_6)  , KC_7   , KC_8   , KC_9   , KC_0   , KC_GRV, 
              //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
                  KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                     KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_BSPC,
              //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
            CTL_T(KC_ESC), KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,                     KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT,
              //|--------+--------+--------+--------+--------+--------|  ===  |   |  ===  |--------+--------+--------+--------+--------+--------|
                  KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,KC_MUTE,    KC_DISC, KC_K   , KC_H   ,KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
              //|--------+--------+--------+--------+--------+--------|  ===  |   |  ===  |--------+--------+--------+--------+--------+--------|
                                  KC_LCTL , KC_LGUI, KC_LALT,KC_LOWER, KC_SPC ,     KC_ENT ,KC_RAISE, KC_BSPC, KC_DEL , KC_ALGR
              //                 \--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------/
            ),

/* LOWER
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * | ----- |  F1   |  F2   |  F3   |  F4   |  F5   |                    |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |   `   |   1   |   2   |   3   |   4   |   5   |                    |   6   |   7   |   8   |   9   |   0   |  F12  |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * | Caps  |   =   |   -   |   +   |   {   |   }   |-------.    ,-------|   [   |   ]   |   ;   |   :   |   \   |  DEL  |
 * |-------+-------+-------+-------+-------+-------| ----- |    | ----- |-------+-------+-------+-------+-------+-------|
 * | ----- | Undo  | Cut   | Copy  | Selec | Paste |-------|    |-------|       |       |   ,   |   .   |   /   | ----- |
 * `-----------------------------------------------/      /      \      \-----------------------------------------------'
 *                | ---- | ---- | ----- | ----- | / ---- /        \ ---- \ | ----- | ----- | ---- | ---- |
 *                |      |      |       |       |/      /          \      \|       |       |      |      |
 *                `-----------------------------'------'            '------'-----------------------------'
 */
            [_LOWER] = LAYOUT(
              //,-----------------------------------------------------.                   ,-----------------------------------------------------.
                  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,         LT(_SWITCH, KC_F6) , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , 
              //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
                  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_F12 ,
              //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
                  KC_CAPS, KC_EQL , KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,                     KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, KC_DEL ,
              //|--------+--------+--------+--------+--------+--------|  ===  |   |  ===  |--------+--------+--------+--------+--------+--------|
                  _______, KC_UNDO, KC_CUT , KC_COPY, KC_SLCT, KC_PSTE,_______,    _______, XXXXXXX, XXXXXXX, KC_COMM, KC_DOT , KC_SLSH, _______,
              //|--------+--------+--------+--------+--------+--------|  ===  |   |  ===  |--------+--------+--------+--------+--------+--------|
                                  _______ ,_______ , _______, _______, _______,    _______ , _______, _______, _______, _______
              //                 \--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------/
            ),

/* RAISE
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * | ----- | ----- | ----- | ----- | ----- | ----- |                    | ----- | ----- | ----- | ----- | ----- | ----- |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * | ----- | Ins   | Pscr  | Menu  | Caps  |       |                    | PG UP | WD PR |  UP   | WD NX | PAUSE |       |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * | ----- | L Alt | LCtrl | LShift|       | Caps  |-------.    ,-------| PG DN | LEFT  | DOWN  | RIGHT |  DEL  |       |
 * |-------+-------+-------+-------+-------+-------| ----- |    | ----- |-------+-------+-------+-------+-------+-------|
 * | ----- | Undo  | Cut   | Copy  | Paste | Find  |-------|    |-------|       | HOME  |       |  END  | DLINE |       |
 * `-----------------------------------------------/      /      \      \-----------------------------------------------'
 *                | ---- | ---- | ----- | ----- | / ---- /        \ ---- \ | ----- | ----- | ---- | ---- |
 *                |      |      |       |       |/      /          \      \|       |       |      |      |
 *                `-----------------------------'------'            '------'-----------------------------'
 */
            [_RAISE] = LAYOUT(
              //,-----------------------------------------------------.                   ,-----------------------------------------------------.
                  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, 
              //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
                  _______, KC_INS , KC_PSCR, KC_APP , KC_CAPS, XXXXXXX,                     KC_PGUP,C(KC_LEFT),KC_UP,C(KC_RGHT),KC_PAUS,XXXXXXX,
              //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
                  _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL , XXXXXXX,
              //|--------+--------+--------+--------+--------+--------|  ===  |   |  ===  |--------+--------+--------+--------+--------+--------|
                  _______, KC_UNDO, KC_CUT , KC_COPY,KC_PASTE, KC_FIND,_______,    _______, XXXXXXX, KC_HOME, XXXXXXX, KC_END,C(KC_BSPC),XXXXXXX,
              //|--------+--------+--------+--------+--------+--------|  ===  |   |  ===  |--------+--------+--------+--------+--------+--------|
                                  _______ ,_______ , _______,KC_LOWER, _______,    _______ , _______, _______, _______, _______
              //                 \--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------/
            ),

/* ADJUST
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * |EEP CLR|       |       |       |       |       |                    |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |QK_MAKE|QK_BOOT|DB_TOGG| QK_RBT|       |       |                    |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |RGB_TOG| hue - | sat - | bri - |       |       |-------.    ,-------| des < |       |       | > des |       |       |
 * |-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
 * |RGM_MOD| hue - | sat - | bri - |       |       |-------|    |-------| STOP  | PREV  | PLAY  | NEXT  |       |       |
 * `-----------------------------------------------/      /      \      \-----------------------------------------------'
 *                | ---- | ---- | ----- | ----- | / ---- /        \ ---- \ | ----- | ----- | ---- | ---- |
 *                |      |      |       |       |/      /          \      \|       |       |      |      |
 *                `-----------------------------'------'            '------'-----------------------------'
 */
            [_ADJUST] = LAYOUT(
              //,-----------------------------------------------------.                   ,-----------------------------------------------------.
                  EE_CLR , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
              //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
                  QK_MAKE, QK_BOOT, DB_TOGG, QK_RBT , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
              //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
                  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,          C(G(KC_LEFT)), XXXXXXX, XXXXXXX,C(G(KC_RGHT)), XXXXXXX, XXXXXXX,
              //|--------+--------+--------+--------+--------+--------|  ===  |   |  ===  |--------+--------+--------+--------+--------+--------|
                  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,XXXXXXX,   XXXXXXX, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
              //|--------+--------+--------+--------+--------+--------|  ===  |   |  ===  |--------+--------+--------+--------+--------+--------|
                                  _______ ,_______ , _______, _______, _______,    _______ , _______, _______, _______, _______
              //                 \--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------/
            ),

/* SWITCH
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * | ----- |       |       |       |       |       |                    |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |colemak|       | qwerty|       |       |  adj  |                    | numpad|       |       |       |       |QK_BOOT|
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * | WinMac|       |       |       |       |       |-------.    ,-------|       |       |       |       |       |EEP CLR|
 * |-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
 * | SLEEP | WAKE  |       |       |       |       |-------|    |-------|       |       |       |       |       |       |
 * `-----------------------------------------------/      /      \      \-----------------------------------------------'
 *              |       |       |       |       | /      /        \      \ |       |       |       |       |
 *              |       |       |       |       |/      /          \      \|       |       |       |       |
 *                `-----------------------------'------'            '------'-------------------------------'
 */
            [_SWITCH] = LAYOUT(
              //,-----------------------------------------------------.                   ,-----------------------------------------------------.
                  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
              //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
          TO(_COLEMAK),XXXXXXX,TO(_GAMING),XXXXXXX,XXXXXXX,TO(_ADJUST),                 TO(_NUMPAD), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
              //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
                  AG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR ,
              //|--------+--------+--------+--------+--------+--------|  ===  |   |  ===  |--------+--------+--------+--------+--------+--------|
                  KC_SLEP, KC_WAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
              //|--------+--------+--------+--------+--------+--------|  ===  |   |  ===  |--------+--------+--------+--------+--------+--------|
                                  XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
              //                 \--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------/
            ),

/* NUMPAD
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * | ----- |       |       |       |       |       |                    | ----- | NumLck|       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                    |   ^   |   7   |   8   |   9   |   *   |       |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |-------.    ,-------|   -   |   4   |   5   |   6   |   =   |   |   |
 * |-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |-------|    |-------|   +   |   1   |   2   |   3   |   \   | ----- |
 * `-----------------------------------------------/      /      \      \-----------------------------------------------'
 *                | ---- | OMEH | ----- | ----- | / ---- /        \ Enter\ | L Alt |   0   |   .   | ---- |
 *                |      |      |       |       |/      /          \      \|       |       |       |      |
 *                `-----------------------------'------'            '------'-----------------------------'
 */
            [_NUMPAD] = LAYOUT(
              //,-----------------------------------------------------.                   ,-----------------------------------------------------.
                  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     _______, KC_NUM , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
              //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_CIRC, KC_P7  , KC_P8  , KC_P9  , KC_PAST, XXXXXXX,
              //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_PMNS, KC_P4  , KC_P5  , KC_P6  , KC_PEQL, KC_PIPE,
              //|--------+--------+--------+--------+--------+--------|  ===  |   |  ===  |--------+--------+--------+--------+--------+--------|
                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,    _______, KC_PPLS, KC_P1  , KC_P2  , KC_P3  , KC_PSLS, _______,
              //|--------+--------+--------+--------+--------+--------|  ===  |   |  ===  |--------+--------+--------+--------+--------+--------|
                                 _______,OSM(MOD_MEH),_______,_______, _______,     KC_PENT, KC_LALT, KC_P0  , KC_PDOT, _______
              //                 \--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------/
            ),

/*
 * GAMING
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * | ESC   |   1   |   2   |   3   |   4   |   5   |                    |   6   |   7   |   8   |   9   |   0   |   `   |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * | TAB   |   Q   |   W   |   E   |   R   |   T   |                    |   Y   |   U   |   I   |   O   |   P   | Bspc  |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * | LCTRL |   A   |   S   |   D   |   F   |   G   |-------.    ,-------|   H   |   J   |   K   |   L   |   ;   |  '    |
 * |-------+-------+-------+-------+-------+-------| MUTE  |    |DISCORD|-------+-------+-------+-------+-------+-------|
 * | LSHFT |   Z   |   X   |   C   |   V   |   B   |-------|    |-------|   N   |   M   |   ,   |   .   |   /   | LShift|
 * `-----------------------------------------------/      /      \      \-----------------------------------------------'
 *                | LCTL | LALT | Space | Space | /Enter /        \ Space\ | Enter | RAISE | RCTR | ALGR |
 *                |      |      |       |       |/      /          \      \|       |       |      |      |
 *                `-----------------------------'------'            '------'-----------------------------'
 */
            [_GAMING] = LAYOUT(
              //,-----------------------------------------------------.                   ,-----------------------------------------------------.
                  KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,         LT(_SWITCH, KC_6)  , KC_7   , KC_8   , KC_9   , KC_0   , KC_GRV ,
              //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
                  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
              //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
                  KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
              //|--------+--------+--------+--------+--------+--------|  ===  |   |  ===  |--------+--------+--------+--------+--------+--------|
                  KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,KC_MUTE,    KC_DISC, KC_N   , KC_M   , KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
              //|--------+--------+--------+--------+--------+--------|  ===  |   |  ===  |--------+--------+--------+--------+--------+--------|
                                  KC_LCTL ,KC_LALT , KC_SPC , KC_SPC , KC_ENT ,     KC_SPC , KC_ENT ,TG(_GAMING),KC_RCTL,KC_ALGR
              //                 \--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------/
            ),

};

#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_RED)
);
const rgblight_segment_t PROGMEM layer_colemakdh_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_WHITE)
);

// _NUM,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_TEAL)
);
// _SYMBOL,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_BLUE)
);
// _COMMAND,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_PURPLE)
);

//_NUMPAD
const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_INDICATORS(HSV_ORANGE),
    SET_UNDERGLOW(HSV_ORANGE),
    SET_NUMPAD(HSV_BLUE),
    {7, 4, HSV_ORANGE},
    {25, 2, HSV_ORANGE},
    {35+6, 4, HSV_ORANGE},
    {35+25, 2, HSV_ORANGE}
);
// _SWITCHER   // light up top row
const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_GREEN),
    SET_NUMROW(HSV_GREEN)
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_colemakdh_lights,
    layer_qwerty_lights,
    layer_num_lights,// overrides layer 1
    layer_symbol_lights,
    layer_command_lights,
    layer_numpad_lights,
    layer_switcher_lights  // Overrides other layers
);

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_COLEMAK, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_COLEMAK));
    rgblight_set_layer_state(_GAMING , layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_GAMING));


    rgblight_set_layer_state(_LOWER , layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(_RAISE , layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(_ADJUST, layer_state_cmp(state, _ADJUST));
    rgblight_set_layer_state(_NUMPAD, layer_state_cmp(state, _NUMPAD));
    rgblight_set_layer_state(_SWITCH, layer_state_cmp(state, _SWITCH));
    return state;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

    rgblight_mode(10);// haven't found a way to set this in a more useful way
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_GAMING:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAMING);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_DISC:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MEH));
                register_code(KC_UP);
            } else {
                unregister_mods(mod_config(MOD_MEH));
                unregister_code(KC_UP);
            }
    }
    return true;
}

#ifdef ENCODER_ENABLE
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
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
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
