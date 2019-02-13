/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H
//#include quantum/keymap_extras/keymap_swedish.h
#include "keymap_swedish.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _TOP 3

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define _______ KC_TRNS
#define _____________ KC_TRNS
//      LCTL(KC_LSFT)

#define MC_SFTGUICTL LCTL(KC_LGUI | KC_LSFT)

#define TOP_RAI _RAISE | _TOP

enum custm_keycodes {
  ALT_TAB = SAFE_RANGE,
};


/*
PROBLEMS

* Hard to combine F keys with modifiers
* a bit disturbing to have important keys like bkspace and enter activate on release

*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_UNDS,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_LBRC,
     KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH,
                      TG(_RAISE)  ,_______,                                                       KC_DEL,TG(_LOWER),
                                      LT(RAISE,KC_TAB),KC_SPC,                           KC_SFTENT, LT(LOWER,KC_BSPC),
                                      KC_LSFT,KC_LCTL,                        MT(MOD_LALT,KC_APP), KC_RCTL,
                                      KC_LALT, KC_TAB,                        KC_LGUI, MT(MOD_LALT,KC_APP)
  ),

  [_LOWER] = LAYOUT_5x6(

    KC_TILD,RALT(KC_1),RALT(KC_2),RALT(KC_3),RALT(KC_4),   RALT(KC_5),        RALT(KC_6),    RALT(KC_7),RALT(KC_8),RALT(KC_9),RALT(KC_0),RALT(KC_MINS),
    KC_INS,  KC_GRV,    KC_HOME,   KC_UP ,    KC_END,    KC_PGUP,             KC_MEH,LCTL(KC_LGUI),LCTL(KC_LALT),_______,KC_MNXT,   KC_VOLU,
    KC_DEL,  ALT_TAB,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_PGDN,             ALT_TAB,     KC_LCTL,LCTL(KC_LSFT),KC_LALT,KC_MPLY,   KC_VOLD,
    _______,_______, LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),LCTL(KC_Z),             KC_LGUI,     KC_LSFT,LALT(KC_LSFT),_______,KC_MPRV,   KC_MUTE,
                     KC_SLCK,KC_PSCR,                                                TG(_LOWER), _______ ,
                                                _______,_______,              _______,_______,
                                                _______,_______,              _______,_______,
                                                _______,_______,              _______,_______
  ),


  [_RAISE] = LAYOUT_5x6(
    KC_F12,  KC_F1 , KC_F2 , KC_F3 ,KC_F4,  KC_F5 ,                           KC_F6,    KC_F7,     KC_F8,      KC_F9,     KC_F10,          KC_F11 ,
    KC_PLUS,KC_PSLS,KC_P7 , KC_P8 , KC_P9 ,KC_NLCK,                           OSL(_TOP),KC_NUBS,   LSFT(KC_NUBS),LSFT(KC_EQL), KC_EQL,       KC_PLUS,
    KC_MINS,_______,KC_P4 , KC_P5 , KC_P6 ,KC_NUHS,                           _______,  LSFT(KC_8),LSFT(KC_9),   RALT(KC_8),RALT(KC_9),    KC_LPRN,
    KC_UNDS,_______,KC_P1 , KC_P2 , KC_P3 ,NO_CIRC,                           _______,  RALT(KC_7),RALT(KC_0),   KC_PIPE,   RALT(KC_NUBS), KC_GRV,
                          KC_P0,TG(_RAISE),                                          OSM(MOD_MEH),_______,
                                                KC_DEL,  RAISE,               OSM(MOD_RALT), KC_DEL,
                                                OSL(_RAISE), KC_RCTL,         OSM(MOD_LSFT), OSM(MOD_LCTL),
                                                KC_LGUI, KC_LALT,             OSM(MOD_LALT), OSM(MOD_LGUI)
  ),

  [_TOP] = LAYOUT_5x6(
       KC_F12 ,KC_F1  , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                       KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       _______,_______,_______,_______,_______,_______,                       _______,_______,_______,_______,_______,_______,
       RESET  ,_______,_______,_______,_______,_______,                       _______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,                       _______,_______,_______,_______,_______,_______,
                              _______,_______,                                               _______,ALT_TAB,
                                               _______,_______,        _______,_______,
                                               KC_LSFT,KC_LCTL,                        MT(MOD_LALT,KC_APP), KC_RCTL,
                                               KC_LALT, KC_TAB,                        KC_LGUI, MT(MOD_LALT,KC_APP)
   ),
};

// From https://www.reddit.com/r/olkb/comments/9ncbhu/brainstorming_for_a_onekey_alttab_function_what/

/*
QMK KEYCODES in SWEDISH LAYOUT

          = VAN SHF RALT
KC_BSLASH = '   *
KC_EQL    = ´   `   ±
KC_MINS   = +   ?   \
KC_NUBS   = <   >
KC_NUHS   = '   *
KC_PLUS   = `   }
KC_SLSH   = -   _   -
KC_TILD   = ½
KC_UNDS   = ?   .   ¿
KC_QUOT   = ä   Ä   ä
KC_GRV    = §   ½   ←
KC_PAST   = *   *   *
NO_CIRC   = ^   ^   n

*/

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  // persistant variable
  static bool in_tab = false; // does an ALT-TAB, for windows cycling, without an alt key

  if (keycode != ALT_TAB && in_tab
    && keycode != KC_LSHIFT
    && keycode != KC_LEFT
    && keycode != KC_RGHT
    && keycode != KC_UP
    && keycode != KC_DOWN

    )
  {
    // Exit alt tab before treating normally the keycode
    SEND_STRING(SS_UP(X_LALT));
    in_tab = false;
  }

  switch (keycode) {
    case ALT_TAB:
      // Macro to handle lower-tab as alt-tab
      if (record->event.pressed) {
        if (!in_tab)
        {
          SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_PGDOWN));
          in_tab = true;
        } else {
          SEND_STRING(SS_TAP(X_PGDOWN));
          // Do not release Alt here, or it will be impossible to switch more than one window:
          // alt-tab-tab will be interpreted as alt-tab, then tab
        }
      }
      return false;

      //    ... other cases from your custom layout...
    }
  return true;
}
