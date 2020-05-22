#include "preonic.h"
#include "action_layer.h"

#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _FNS 6
#define _ADJUST 16

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};


// macros
#define MC_FNLR     MO(_FNS)                    // fn layer
#define MC_ESCT     CTL_T(KC_ESC)               // tap for esc; hold for ctrl
#define MC_ROFI     LGUI(KC_P)                  // rofi
#define MC_RFIW     LGUI(KC_G)                  // rofi: windows
#define MC_BAR1     LALT(LSFT(KC_A))            // barrier: 1/A
#define MC_BAR2     LALT(LSFT(KC_S))            // barrier: 2/S
#define MC_BAR3     LALT(LSFT(KC_D))            // barrier: 3/D
#define MC_BAR4     LALT(LSFT(KC_F))            // barrier: 4/F
#define MC_BAR5     LALT(LSFT(KC_G))            // barrier: 5/G
#define MC_BAR6     LALT(LSFT(KC_H))            // barrier: 6/H
#define MC_BAR7     LALT(LSFT(KC_J))            // barrier: 7/J
#define MC_BAR8     LALT(LSFT(KC_K))            // barrier: 8/K
#define MC_XAPP     LGUI(KC_A)                  // xmonad: apps menu
#define MC_XMED     LGUI(KC_Z)                  // xmonad: volume menu


// tap dance helpers
#define TD_SCLN     TD(TD_SCLN_QUOT)
#define TD_LBRC     TD(TD_LBRC_LCBR)
#define TD_RBRC     TD(TD_RBRC_RCBR)
#define TD_COMM     TD(TD_COMM_MINS)
#define TD_WSP1     TD(TD_KC1_BAR1)
#define TD_WSP2     TD(TD_KC2_BAR2)
#define TD_WSP3     TD(TD_KC3_BAR3)
#define TD_WSP4     TD(TD_KC4_BAR4)
#define TD_WSP5     TD(TD_KC5_BAR5)
#define TD_WSP6     TD(TD_KC6_BAR6)
#define TD_WSP7     TD(TD_KC7_BAR7)
#define TD_WSP8     TD(TD_KC8_BAR8)


// tap dance
enum {
  TD_SCLN_QUOT,
  TD_LBRC_LCBR,
  TD_RBRC_RCBR,
  TD_COMM_MINS,
  TD_KC1_BAR1,
  TD_KC2_BAR2,
  TD_KC3_BAR3,
  TD_KC4_BAR4,
  TD_KC5_BAR5,
  TD_KC6_BAR6,
  TD_KC7_BAR7,
  TD_KC8_BAR8
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SCLN_QUOT]  = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
  [TD_LBRC_LCBR]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
  [TD_RBRC_RCBR]  = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
  [TD_COMM_MINS]  = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_MINS),

  [TD_KC1_BAR1]   = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_1), LGUI(LSFT(KC_1))),
  [TD_KC2_BAR2]   = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_2), LGUI(LSFT(KC_2))),
  [TD_KC3_BAR3]   = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_3), LGUI(LSFT(KC_3))),
  [TD_KC4_BAR4]   = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_4), LGUI(LSFT(KC_4))),
  [TD_KC5_BAR5]   = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_5), LGUI(LSFT(KC_5))),
  [TD_KC6_BAR6]   = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_6), LGUI(LSFT(KC_6))),
  [TD_KC7_BAR7]   = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_7), LGUI(LSFT(KC_7))),
  [TD_KC8_BAR8]   = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_8), LGUI(LSFT(KC_8)))
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* Qwerty
  * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
  * │   ~   │   !   │   @   │   #   │   $   │   %   │   ^   │   &   │   *   │   (   │   )   │   _   │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │   `   │   1   │   2   │   3   │   4   │   5   │   6   │   7   │   8   │   9   │   0   │   -   │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │   Q   │   W   │   E   │   R   │   T   │   Y   │   U   │   I   │   O   │   P   │       │
  * │  TAB  │       │       │       │       │       │       │       │       │       │       │ BCSP  │
  * │       │   q   │   w   │   e   │   r   │   t   │   y   │   u   │   i   │   o   │   p   │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │ ESC   │   A   │   S   │   D   │   F   │   G   │   H   │   J   │   K   │   L   │ :  "  │       │
  * │ CTRL  │       │       │       │       │       │       │       │       │       │       │  RET  │
  * │       │   a   │   s   │   d   │   f   │   g   │   h   │   j   │   k   │   l   │ ;  '  │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │ SHIFT │   Z   │   X   │   C   │   V   │   B   │   N   │   M   │ <  _  │   >   │   ?   │ SHIFT │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │   )   │   z   │   x   │   c   │   v   │   b   │   n   │   m   │ ,  -  │   .   │   /   │   )   │
  * ├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │               │       │       │       │       │       │
  * │ CTRL  │       │  ALT  │ SUPER │ LOWER │     SPACE     │ RAISE │  FN   │       │       │       │
  * │       │       │       │       │       │               │       │       │       │       │       │
  * └───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘
  */

  [_QWERTY] = LAYOUT_preonic_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,      KC_4,  KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,      KC_R,  KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    MC_ESCT, KC_A,    KC_S,    KC_D,      KC_F,  KC_G,   KC_H,   KC_J,    KC_K,    KC_L,    TD_SCLN, KC_ENT ,
    KC_LSPO, KC_Z,    KC_X,    KC_C,      KC_V,  KC_B,   KC_N,   KC_M,    TD_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    KC_LCTL, _______, KC_LALT, KC_LGUI,   LOWER, KC_SPC, KC_SPC, RAISE,   MC_FNLR, _______, _______, _______
  ),



 /* Raise
  * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
  * │   ~   │  WSP  │  WSP  │  WSP  │  WSP  │  WSP  │  WSP  │  WSP  │  WSP  │   {   │   }   │   +   │
  * │       │   1   │   2   │   3   │   4   │   5   │   6   │   7   │   8   │       │       │       │
  * │   `   │       │       │       │       │       │       │       │       │   [   │   ]   │   =   │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       |       │       │       │       │       │       │       │       │  DEL  │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │ TERM  │ APPS  │       │       │       │       │       │       │       │       │       │       │
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

  [_RAISE] = LAYOUT_preonic_grid(

    KC_GRV,  TD_WSP1, TD_WSP2, TD_WSP3, TD_WSP4, TD_WSP5, TD_WSP6, TD_WSP7, TD_WSP8, KC_LBRC, KC_RCBR, KC_EQL,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL ,
    KC_F12,  MC_XAPP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, MC_XMED, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, LOWER,   MC_RFIW, MC_RFIW, RAISE,   MC_FNLR, _______, _______, _______
  ),



  /* Lower
  * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
  * │       │       │       │       │       │       │       │       │       │       │       │   _   │
  * │       │       │       │       │       │       │       │       │       │   {   │   }   │       │
  * │       │       │       │       │       │       │       │       │       │       │       │   -   │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │   "   │   |   │
  * │       │       │       │       │       │       │ LEFT  │ DOWN  │   UP  │ RIGHT │       │       │
  * │       │       │       │       │       │       │       │       │       │       │   '   │   \   │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │   {   │   }   │   |   │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │   [   │   ]   │   \   │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │               │       │       │       │       │       │
  * │       │       │       │       │ LOWER │     ROFI      │ RAISE │  FN   │       │       │       │
  * │       │       │       │       │       │               │       │       │       │       │       │
  * └───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘
  */

  [_LOWER] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_MINS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, TD_LBRC, TD_RBRC, KC_BSLS, _______,
    _______, _______, _______, _______, LOWER,   MC_ROFI, MC_ROFI, RAISE,   MC_FNLR, _______, _______, _______
  ),


 /* Fn
  * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │ BAR 1 │ BAR 2 │ BAR 3 │ BAR 4 │ BAR 5 │ BAR 6 │ BAR 7 │ BAR 8 │       │       │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │       │       │ PRINT │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │ prev  │  vol  │  vol  │ next  │       │ play  │
  * │       │       │       │       │       │       │ track │  down │  up   │ track │       │ pause │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │brgt dn│       │       │       │       │       │       │(M)ute │       │       │       │brgt up│
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │               │       │       │       │       │       │
  * │       │       │       │       │ LOWER │     RESET     │ RAISE │  FN   │       │       │       │
  * │       │       │       │       │       │               │       │       │       │       │       │
  * └───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘
  */

  [_FNS] = LAYOUT_preonic_grid(
    _______, MC_BAR1, MC_BAR2, MC_BAR3, MC_BAR4, MC_BAR5, MC_BAR6, MC_BAR7, MC_BAR8, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______,
    _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, KC_MPLY,
    KC_BRID, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, KC_BRIU,
    _______, _______, _______, _______, LOWER,   RESET,   RESET,   RAISE,   MC_FNLR, _______, _______, _______
  ),


 /* Adjust (Lower + Raise)
  * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │  F1   │  F2   │  F3   │  F4   │  F5   │  F6   │  F7   │  F8   │  F9   │  F10  │  F11  │  F12  │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
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

  [_ADJUST] = LAYOUT_preonic_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, LOWER,   _______, _______, RAISE,   MC_FNLR, _______, _______, _______
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
};
