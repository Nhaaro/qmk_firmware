#pragma once
enum layers {
    _DEFAULTS = 0,
    _COLEMAK = 0,
    _GAMING,

    _LOWER,
    _RAISE,
    _ADJUST,

    _NUMPAD,
    _SWITCH,

    _CHAT,
};

enum custom_keycodes {
    KC_COLEMAK = SAFE_RANGE,
    KC_GAMING,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,

    KC_DISC,
    KC_CHAT
};

enum encoders {
    EN_LEFT,
    EN_RIGHT
};

