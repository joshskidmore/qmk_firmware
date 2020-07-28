#include QMK_KEYBOARD_H
#include "action_layer.h"

#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _FN 6
#define _BARRIER 7
#define _ADJUST 16

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};


// macros
#define MC_LOWR     MO(_LOWER)                  // lower layer
#define MC_RAIS     MO(_RAISE)                  // raise layer
#define MC_FNLR     MO(_FN)                     // fn layer
#define MC_BRLR     MO(_BARRIER)                // barrier layer
#define MC_AJLR     MO(_ADJUST)                 // adjust layer
#define MC_ESCT     CTL_T(KC_ESC)               // tap for esc; hold for ctrl
#define MC_ROFI     LGUI(KC_P)                  // rofi
#define MC_RFIW     LGUI(KC_G)                  // rofi: windows
#define MC_RFIM     LGUI(KC_O)                  // rofi: menu
#define MC_BAR1     LALT(LSFT(KC_1))            // barrier: 1
#define MC_BAR2     LALT(LSFT(KC_2))            // barrier: 2
#define MC_BAR3     LALT(LSFT(KC_3))            // barrier: 3
#define MC_BAR4     LALT(LSFT(KC_4))            // barrier: 4
#define MC_BAR5     LALT(LSFT(KC_5))            // barrier: 5
#define MC_BAR6     LALT(LSFT(KC_6))            // barrier: 6
#define MC_BAR7     LALT(LSFT(KC_7))            // barrier: 7
#define MC_BAR8     LALT(LSFT(KC_8))            // barrier: 8
#define MC_BAR9     LALT(LSFT(KC_9))            // barrier: 9
#define MC_BAR0     LALT(LSFT(KC_0))            // barrier: 0
#define MC_BLFT     LALT(LSFT(KC_LEFT))         // barrier: prev
#define MC_BRGT     LALT(LSFT(KC_RGHT))         // barrier: next
#define MC_RBAR     LGUI(LCTL(KC_F9))           // rofi-barrier.sh
#define MC_XAPP     LGUI(KC_A)                  // xmonad: apps menu
#define MC_XMED     LGUI(KC_Z)                  // xmonad: volume menu
#define MC_XMKL     LGUI(LSFT(LCTL(KC_Q)))      // xmonad: kill
#define MC_XMSW     LGUI(KC_TAB)                // xmonad: switch screen
#define MC_HQWE     LGUI(LCTL(KC_F1))           // roficheat: qwerty
#define MC_HRAI     LGUI(LCTL(KC_F2))           // roficheat: raise
#define MC_HLOW     LGUI(LCTL(KC_F3))           // roficheat: lower
#define MC_HFN      LGUI(LCTL(KC_F4))           // roficheat: fn
#define MC_HBAR     LGUI(LCTL(KC_F5))           // roficheat: barrier
#define MC_HADJ     LGUI(LCTL(KC_F6))           // roficheat: adjust


// tap dance helpers
#define TD_SCLN     TD(TD_SCLN_QUOT)
#define TD_LBRC     TD(TD_LBRC_LCBR)
#define TD_RBRC     TD(TD_RBRC_RCBR)
#define TD_COMM     TD(TD_COMM_MINS)
#define TD_CIRC     TD(TD_CIRC_HOME)
#define TD_DLR      TD(TD_DLR_END)
#define TD_WSP1     TD(TD_KC1)
#define TD_WSP2     TD(TD_KC2)
#define TD_WSP3     TD(TD_KC3)
#define TD_WSP4     TD(TD_KC4)
#define TD_WSP5     TD(TD_KC5)
#define TD_WSP6     TD(TD_KC6)
#define TD_WSP7     TD(TD_KC7)
#define TD_WSP8     TD(TD_KC8)


// layer toggle helpers
#define LT_SPC      LT(_FN, KC_SPC)
//#define LT_LOWR     LT(_LOWER, KC_PGDN)
//#define LT_RAIS     LT(_RAISE, KC_PGUP)



// tap dance
enum {
  TD_SCLN_QUOT,
  TD_LBRC_LCBR,
  TD_RBRC_RCBR,
  TD_COMM_MINS,
  TD_CIRC_HOME,
  TD_DLR_END,
  TD_KC1,
  TD_KC2,
  TD_KC3,
  TD_KC4,
  TD_KC5,
  TD_KC6,
  TD_KC7,
  TD_KC8
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SCLN_QUOT]  = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
  [TD_LBRC_LCBR]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
  [TD_RBRC_RCBR]  = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
  [TD_COMM_MINS]  = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_MINS),
  [TD_CIRC_HOME]  = ACTION_TAP_DANCE_DOUBLE(KC_CIRC, KC_HOME),
  [TD_DLR_END]    = ACTION_TAP_DANCE_DOUBLE(KC_DLR, KC_END),
  [TD_KC1]        = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_1), LGUI(LSFT(KC_1))),
  [TD_KC2]        = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_2), LGUI(LSFT(KC_2))),
  [TD_KC3]        = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_3), LGUI(LSFT(KC_3))),
  [TD_KC4]        = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_4), LGUI(LSFT(KC_4))),
  [TD_KC5]        = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_5), LGUI(LSFT(KC_5))),
  [TD_KC6]        = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_6), LGUI(LSFT(KC_6))),
  [TD_KC7]        = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_7), LGUI(LSFT(KC_7))),
  [TD_KC8]        = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_8), LGUI(LSFT(KC_8)))
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* Qwerty
  * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
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
  * │   (   │   z   │   x   │   c   │   v   │   b   │   n   │   m   │ ,  -  │   .   │   /   │   )   │
  * ├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │      FN       │       │       │       │       │       │
  * │ CTRL  │ AJST  │  ALT  │ SUPER │ LOWER │               │ RAISE │ STUCK │ BARRI │ DEAD  │ HELP  │
  * │       │       │       │       │       │     SPACE     │       │       │       │       │       │
  * └───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘
    Qwerty End */

  [_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    MC_ESCT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TD_SCLN, KC_ENT,
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    TD_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    KC_LCTL, MC_AJLR, KC_LALT, KC_LGUI, MC_LOWR, LT_SPC,  LT_SPC,  MC_RAIS, _______, MC_BRLR, _______, MC_HQWE
  ),



 /* Raise
  * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
  * │ XOND  │  WSP  │  WSP  │  WSP  │  WSP  │  WSP  │  WSP  │  WSP  │  WSP  │       │       │   _   │
  * │ SW SCR│   1   │   2   │   3   │   4   │   5   │   6   │   7   │   8   │       │ PRINT │       │
  * │       │       │       │       │       │       │       │       │       │       │       │   -   │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │       │       │       │  DEL  │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │   [   │       │       │       │       │       │       │       │       │       │       │   ]   │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │               │       │       │       │       │       │
  * │       │       │       │       │       │   ROFI WIN    │ XXXXX │       │       │       │ HELP  │
  * │       │       │       │       │       │               │       │       │       │       │       │
  * └───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘
    Raise End */

  [_RAISE] = LAYOUT_planck_grid(

    MC_XMSW, TD_WSP1, TD_WSP2, TD_WSP3, TD_WSP4, TD_WSP5, TD_WSP6, TD_WSP7, TD_WSP8, _______, KC_PSCR, KC_MINS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_LBRC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RBRC,
    _______, _______, _______, _______, _______, MC_RFIW, MC_RFIW, _______, _______, _______, _______, MC_HRAI
  ),



 /* Lower
  * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
  * │   ~   │   !   │   @   │   #   │   $   │   %   │   ^   │   &   │   *   │   (   │   )   │   +   │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │   `   │   1   │   2   │   3   │   4   │   5   │   6   │   7   │   8   │   9   │   0   │   =   │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │   "   │   |   │
  * │       │       │       │       │       │       │ LEFT  │ DOWN  │   UP  │ RIGHT │       │       │
  * │       │       │       │       │       │       │       │       │       │       │   '   │   \   │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │ {  {  │ }  }  │   |   │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │ [  {  │ ]  }  │   \   │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │               │       │       │       │       │       │
  * │       │       │       │       │ XXXXX │     ROFI      │       │       │       │       │ HELP  │
  * │       │       │       │       │       │               │       │       │       │       │       │
  * └───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘
    Lower End */

  [_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, TD_LBRC, TD_RBRC, KC_BSLS, _______,
    _______, _______, _______, _______, _______, MC_ROFI, MC_ROFI, _______, _______, _______, _______, MC_HLOW
  ),



 /* Fn
  * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
  * │ LINE  │       │       │       │       │       │       │       │       │       │       │  LINE │
  * │ START │       │       │       │       │       │       │       │       │       │       │   END │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │ HOME  │ PG DN │ PG UP │  END  │       │ TERM  │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │   {   │       │       │       │       │       │       │       │       │       │       │   }   │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │               │ ROFI  │       │       │       │       │
  * │       │       │       │       │       │     XXXXX     │ MENU  │       │       │       │ HELP  │
  * │       │       │       │       │       │               │       │       │       │       │       │
  * └───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘
    Fn End */

  [_FN] = LAYOUT_planck_grid(
    TD_CIRC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TD_DLR,
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, KC_F12,
    KC_LCBR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RCBR,
    _______, _______, _______, _______, _______, _______, _______, MC_RFIM, _______, _______, _______, MC_HFN
  ),



 /* Barrier
  * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
  * │ BARRI │ BARRI │ BARRI │ BARRI │ BARRI │ BARRI │ BARRI │ BARRI │ BARRI │ BARRI │ BARRI │ BARRI │
  * │ PREV  │   1   │   2   │   3   │   4   │   5   │   6   │   7   │   8   │   9   │   0   │  NEXT │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │       │       │       │       │ ROFI  │       │
  * │       │       │       │       │       │       │       │       │       │       │ BARRI │       │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │               │       │       │       │       │       │
  * │       │       │       │       │       │               │       │       │       │       │ HELP  │
  * │       │       │       │       │       │               │       │       │       │       │       │
  * └───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘
    Barrier End */

  [_BARRIER] = LAYOUT_planck_grid(
    MC_BLFT, MC_BAR1, MC_BAR2, MC_BAR3, MC_BAR4, MC_BAR5, MC_BAR6, MC_BAR7, MC_BAR8, MC_BAR9, MC_BAR0, MC_BRGT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MC_RBAR, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MC_HBAR
  ),



 /* Adjust
  * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * │  F1   │  F2   │  F3   │  F4   │  F5   │  F6   │  F7   │  F8   │  F9   │  F10  │  F11  │  F12  │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │       │       │       │       │       │ PREV  │  VOL  │  VOL  │ NEXT  │       │ PLAY  │
  * │       │       │       │       │       │       │ TRACK │  DN   │  UP   │ TRACK │       │ PAUSE │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  * │ BRGHT │       │       │       │       │       │       │       │       │       │       │ BRGHT │
  * │ DN    │       │       │       │       │       │       │(M)UTE │       │       │       │ UP    │
  * │       │       │       │       │       │       │       │       │       │       │       │       │
  * ├───────┼───────┼───────┼───────┼───────┼───────┴───────┼───────┼───────┼───────┼───────┼───────┤
  * │       │ XM    │       │       │       │               │       │       │       │       │       │
  * │ RESET │ KILL  │       │       │ XXXXX │               │ XXXXX │       │       │       │ HELP  │
  * │       │       │       │       │       │               │       │       │       │       │       │
  * └───────┴───────┴───────┴───────┴───────┴───────────────┴───────┴───────┴───────┴───────┴───────┘
    Adjust End */

  [_ADJUST] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, KC_MPLY,
    KC_BRID, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, KC_BRIU,
    RESET,   MC_XMKL, _______, _______, _______, _______, _______, _______, _______, _______, _______, MC_HADJ
  )

};
