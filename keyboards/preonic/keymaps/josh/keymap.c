#include "preonic.h"
#include "action_layer.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16


// mouse keys
#define MOUSEKEY_DELAY 50
#define MOUSEKEY_INTERVAL 10
#define MOUSEKEY_MAX_SPEED 15
#define MOUSEKEY_TIME_TO_MAX 15
#define MOUSEKEY_WHEEL_MAX_SPEED 10
#define MOUSEKEY_WHEEL_TIME_TO_MAX 10

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

// fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Custom macros
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
#define SFT_ENT     SFT_T(KC_ENT)               // Tap for Enter, hold for Shift
/* #define HPR_TAB     ALL_T(KC_TAB)               // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift) */
#define MEH_GRV     MEH_T(KC_GRV)               // Tap for Backtick, hold for Meh (Ctrl+Alt+Shift)
#define TRI_A       LGUI(LSFT(KC_A))            // Trigger A
#define TRI_S       LGUI(LSFT(KC_S))            // Trigger S
#define TRI_D       LGUI(LSFT(KC_D))            // Trigger D
#define TRI_F       LGUI(LSFT(KC_F))            // Trigger F
#define MON_L       LGUI(KC_W)                  // Switch to left monitor
#define MON_R       LGUI(KC_E)                  // Switch to right monitor
#define ROFI        LGUI(KC_P)                  // Rofi
#define RPASTE      LGUI(KC_V)                  // Rofi paste
#define BRT_O       LSFT(KC_F9)                 // Lowest Brightness
#define BRT_D       LSFT(KC_F10)                // Decrease brightness
#define BRT_U       LSFT(KC_F11)                // Increase brightness
#define BRT_F       LSFT(KC_F12)                // Highest brightness
#define SYN_A       LALT(LSFT(KC_A))            // Synergy: Machine 1/A
#define SYN_S       LALT(LSFT(KC_S))            // Synergy: Machine 2/S
#define SYN_D       LALT(LSFT(KC_D))            // Synergy: Machine 3/D
#define SYN_F       LALT(LSFT(KC_F))            // Synergy: Machine 4/F
#define SYN_G       LALT(LSFT(KC_G))            // Synergy: Machine 5/G
#define SYN_H       LALT(LSFT(KC_H))            // Synergy: Machine 6/H
#define SYN_J       LALT(LSFT(KC_J))            // Synergy: Machine 7/J
#define SYN_K       LALT(LSFT(KC_K))            // Synergy: Machine 8/K

enum {
      COL_QUO = 0,
      SYN_TGGL,
      SYN_TGGL_B,
      LFT_BRK,
      RGT_BRK,
      SFT_CAPS,
      BRT_D_O,
      BRT_U_F,
      WS1,
      WS2,
      WS3,
      WS4,
      WS5,
      WS6,
      WS7,
      WS8
};


//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [COL_QUO]    = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
    /* [SYN_TGGL]   = ACTION_TAP_DANCE_DOUBLE(SYN_A, SYN_S), */
    [SYN_TGGL]   = ACTION_TAP_DANCE_DOUBLE(SYN_S, SYN_A),
    [LFT_BRK]    = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    [RGT_BRK]    = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
    [SFT_CAPS]   = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS),
    [BRT_D_O]    = ACTION_TAP_DANCE_DOUBLE(BRT_D, BRT_O),
    [BRT_U_F]    = ACTION_TAP_DANCE_DOUBLE(BRT_U, BRT_F),

    [WS1]      = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_1), LGUI(LSFT(KC_1))),
    [WS2]      = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_2), LGUI(LSFT(KC_2))),
    [WS3]      = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_3), LGUI(LSFT(KC_3))),
    [WS4]      = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_4), LGUI(LSFT(KC_4))),
    [WS5]      = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_5), LGUI(LSFT(KC_5))),
    [WS6]      = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_6), LGUI(LSFT(KC_6))),
    [WS7]      = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_7), LGUI(LSFT(KC_7))),
    [WS8]      = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_8), LGUI(LSFT(KC_8))),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
  * ,-----------------------------------------------------------------------------------.
  * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |  0   |  -   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |  P   | BKSP |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |CTLESC|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | ; "  |ENTER |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | LSFT |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | RSFT |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | CTRL |SYN_TG|  GUI | ALT  |LOWER |SPACE |SPACE |RAISE | LEFT | DOWN |  UP  |RIGHT |
  * `-----------------------------------------------------------------------------------'
  */
  [_QWERTY] = {
  /*  `        1             2        3          4      5       6       7        8        9        0            DEL     */
    { KC_GRV,  KC_1,         KC_2,    KC_3,      KC_4,  KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,        KC_MINS },
    { KC_TAB,  KC_Q,         KC_W,    KC_E,      KC_R,  KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,        KC_BSPC },
    { CTL_ESC, KC_A,         KC_S,    KC_D,      KC_F,  KC_G,   KC_H,   KC_J,    KC_K,    KC_L,    TD(COL_QUO), KC_ENT  },
    { KC_LSPO, KC_Z,         KC_X,    KC_C,      KC_V,  KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,     KC_RSPC },
    { KC_LCTL, TD(SYN_TGGL), KC_LGUI, KC_LALT,   LOWER, KC_SPC, KC_SPC, RAISE,   KC_LEFT, KC_DOWN, KC_UP,       KC_RGHT }
  },


  /* Raise
  * ,-----------------------------------------------------------------------------------.
  * |      | WS 1 | WS 2 | WS 3 | WS 4 | WS 5 | WS 6 | WS 7 |      |      |      |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |MON_L |MON_R |      |      |      |      |      |      |      | DEL  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | TERM | TR-A | TR-S | TR-D | TR-F |      | WH L | WH D | WH U | WH R |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |RPAST |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | MUTE | PAUS |      |      |LOWER | ROFI | ROFI |RAISE | PREV |VOL U |VOL D | NEXT |
  * `-----------------------------------------------------------------------------------'
  */
  [_RAISE] = {
  /*  `        1        2        3        4        5        6        7        8        9        0        DEL    */
    { _______, TD(WS1), TD(WS2), TD(WS3), TD(WS4), TD(WS5), TD(WS6), TD(WS7), TD(WS8), _______, _______, _______ },
    { _______, _______, MON_L,   MON_R,   _______, _______, _______, _______, _______, _______, _______, KC_DEL  },
    { KC_F12,  TRI_A,   TRI_S,   TRI_D,   TRI_F,   _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______ },
    { _______, _______, _______, _______, RPASTE,  _______, _______, _______, _______, _______, _______, _______ },
    { KC_MUTE, KC_MPLY, _______, _______, _______, ROFI,    ROFI,    _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT }
  },


  /* Lower
  * ,-----------------------------------------------------------------------------------.
  * |      | SY:1 | SY:2 | SY:3 | SY:4 | SY:5 | SY:6 |      |      |  {   |   }  |   =  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      | ROFI |   |  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      | BTN1 | BTN2 | MS 0 | MS 1 | MS 2 | MS L | MS D | MS U | MS R |  '   | | \  |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      | [ {  |  ] } |  \   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | LOCK |      |      |      |LOWER | ROFI | ROFI |RAISE |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_LOWER] = {
  /*  `              1        2        3        4        5        6        7        8            9            0        DEL     */
    { _______,       SYN_A,   SYN_S,   SYN_D,   SYN_F,   SYN_G,   SYN_H,   SYN_J,   SYN_K,       KC_LCBR,     KC_RCBR, KC_EQL  },
    { _______,       _______, _______, _______, _______, _______, _______, _______, _______,     _______,     ROFI,    KC_PIPE },
    { _______,       KC_BTN1, KC_BTN2, KC_ACL0, KC_ACL1, KC_ACL2, KC_MS_L, KC_MS_D, KC_MS_U,     KC_MS_R,     KC_QUOT, KC_BSLS },
    { _______,       _______, _______, _______, _______, _______, _______, _______, TD(LFT_BRK), TD(RGT_BRK), KC_BSLS, _______ },
    { LALT(KC_BSPC), SYN_A,   _______, _______, _______, ROFI,    ROFI,    _______, _______,     _______,     _______, _______ }
  },


  /* Adjust (Lower + Raise)
  * ,-----------------------------------------------------------------------------------.
  * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |RESET |      |      |      |      |      |      |      |      |PRTSCR|      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | CAPS |      |      |      |      |      |      |BRT D |BRT U |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_ADJUST] = {
  /* `         1        2        3        4        5        6        7            8            9        0        DEL     */
    { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,       KC_F9,       KC_F10,  KC_F11,  KC_F12  },
    { _______, RESET,   _______, _______, _______, _______, _______, _______,     _______,     _______, KC_PSCR, _______ },
    { KC_CAPS, _______, _______, _______, _______, _______, _______, KC_BRID,     KC_BRIU,     _______, _______, _______ },
    { _______, _______, _______, _______, _______, _______, _______, TD(BRT_D_O), TD(BRT_U_F), _______, _______, _______ },
    { _______, _______, _______, _______, _______, _______, _______, _______,     _______,     _______, _______, _______ }
  },

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
};
