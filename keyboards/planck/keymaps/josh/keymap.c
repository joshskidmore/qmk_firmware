#include QMK_KEYBOARD_H
#include "action_layer.h"

#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _FNS 6
#define _ADJUST 16

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};


// core macros
#define FN          MO(_FNS)                    // Fn layer
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
#define MEH_GRV     MEH_T(KC_GRV)               // Tap for Backtick, hold for Meh (Ctrl+Alt+Shift)


// synergy/barrier macros
#define SYN_1       LALT(LSFT(KC_A))            // Synergy: Machine 1/A
#define SYN_2       LALT(LSFT(KC_S))            // Synergy: Machine 2/S
#define SYN_3       LALT(LSFT(KC_D))            // Synergy: Machine 3/D
#define SYN_4       LALT(LSFT(KC_F))            // Synergy: Machine 4/F
#define SYN_5       LALT(LSFT(KC_G))            // Synergy: Machine 5/G
#define SYN_6       LALT(LSFT(KC_H))            // Synergy: Machine 6/H
#define SYN_7       LALT(LSFT(KC_J))            // Synergy: Machine 7/J
#define SYN_8       LALT(LSFT(KC_K))            // Synergy: Machine 8/K


// custom macros
#define ROFI        LGUI(KC_P)                  // Rofi
#define ROFI_W      LGUI(KC_G)                  // Rofi (windows)
#define CHAT        LGUI(LSFT(KC_ENT))          // Chat
#define TRI_A       LGUI(KC_A)                  // xmonad: apps menu
#define TRI_Z       LGUI(KC_Z)                  // xmonad: volume menu


enum {
  COL_QUO = 0,
  LFT_BRK,
  RGT_BRK,
  TAB_TIL,

  WS1,
  WS2,
  WS3,
  WS4,
  WS5,
  WS6,
  WS7,
  WS8
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [COL_QUO]   = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
    [LFT_BRK]   = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    [RGT_BRK]   = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
    [TAB_TIL]   = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_GRV),

    [WS1]       = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_1), SYN_1),
    [WS2]       = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_2), SYN_2),
    [WS3]       = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_3), SYN_3),
    [WS4]       = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_4), SYN_4),
    [WS5]       = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_5), SYN_5),
    [WS6]       = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_6), SYN_6),
    [WS7]       = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_7), SYN_7),
    [WS8]       = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_8), SYN_8)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* Qwerty
  * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
  * │  TAB  │       │       │       │       │       │       │       │       │       │       │       │
  * │   `   │   Q   │   W   │   E   │   R   │   T   │   Y   │   U   │   I   │   O   │   P   │ BCSP  │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │  CTRL │       │       │       │       │       │       │       │       │       │       │       │
  * │  ESC  │   A   │   S   │   D   │   F   │   G   │   H   │   J   │   K   │   L   │   ;   │  RET  │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │ SHIFT │   Z   │   X   │   C   │   V   │   B   │   N   │   M   │   ,   │   .   │   /   │ SHIFT │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │               │       │       │       │       │       │
  * │  CTRL │       │  ALT  │  GUI  │ LOWER │     SPACE     │ RAISE │  FN   │       │       │       │
  * │       │       │       │       │       │               │       │       │       │       │       │
  * └───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘
  */

  [_QWERTY] = LAYOUT_planck_grid(
    TD(TAB_TIL), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,        KC_BSPC,
    CTL_ESC,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,    TD(COL_QUO), KC_ENT,
    KC_LSPO,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,     KC_RSPC,
    KC_LCTL,     _______, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   FN,       _______, _______,     _______
  ),



 /* Raise
  * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
  * │       │ WS 1  │ WS 2  │ WS 3  │ WS 4  │ WS 5  │ WS 6  │ WS 7  │ WS 8  │       │       │       │
  * │       │ SYN 1 │ SYN 2 │ SYN 3 │ SYN 4 │ SYN 5 │ SYN 6 │ SYN 7 │ SYN 8 │   [   │   ]   │  = +  │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │ TERM  │ APPS  │       │       │       │       │       │       │       │       │       │  DEL  │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │ MEDIA │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │               │       │       │       │       │       │
  * │       │       │       │       │ LOWER │   ROFI WIN    │ RAISE │  FN   │       │       │       │
  * │       │       │       │       │       │               │       │       │       │       │       │
  * └───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘
  */

  [_RAISE] = LAYOUT_planck_grid(
    _______, TD(WS1), TD(WS2), TD(WS3), TD(WS4), TD(WS5), TD(WS6), TD(WS7), TD(WS8), KC_LBRC, KC_RCBR, KC_EQL,
    KC_F12,  TRI_A,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, TRI_Z,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, LOWER,   ROFI_W,  ROFI_W,  RAISE,   FN,      _______, _______
  ),



 /* Lower
  * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │   `   │   1   │   2   │   3   │   4   │   5   │   6   │   7   │   8   │   9   │   0   │  - _  │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │ LEFT  │ DOWN  │   UP  │ RIGHT │   '   |  | \  │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │   [   │   ]   │   \   │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │               │       │       │       │       │       │
  * │       │       │       │       │ LOWER │     ROFI      │ RAISE │  FN   │       │       │       │
  * │       │       │       │       │       │               │       │       │       │       │       │
  * └───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘
  */

  [_LOWER] = LAYOUT_planck_grid(
    MEH_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,        KC_9,        KC_0,    KC_MINS,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,       KC_RGHT,     KC_QUOT, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, TD(LFT_BRK), TD(RGT_BRK), KC_BSLS, _______,
    _______, _______, _______, _______, _______, LOWER,   ROFI,    ROFI,    RAISE,       FN,          _______, _______
  ),



 /* Fns
  * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │ RESET │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │               │       │       │       │       │       │
  * │       │       │       │       │ LOWER │               │ RAISE │  FN   │       │       │       │
  * │       │       │       │       │       │               │       │       │       │       │       │
  * └───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘
  */

  [_FNS] = LAYOUT_planck_grid(
    _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, LOWER,   _______, _______, RAISE,   FN,      _______, _______
  ),



 /* Adjust (Lower + Raise)
  * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │  F1   │  F2   │  F3   │  F4   │  F5   │  F6   │  F7   │  F8   │  F9   │  F10  │  F11  │  F12  │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │               │       │       │       │       │       │
  * │       │       │       │       │ LOWER │               │ RAISE │  FN   │       │       │       │
  * │       │       │       │       │       │               │       │       │       │       │       │
  * └───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘
  */

  [_ADJUST] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, LOWER,   _______, _______, RAISE,   FN,      _______, _______
  )

};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
