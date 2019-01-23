/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define _______ KC_TRNS

enum custm_keycodes {
  ALT_TAB = SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_PLUS,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_LBRC,
     KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH,
                      KC_DOWN,KC_UP  ,                                                       KC_LEFT,KC_RGHT,
                                      RAISE,KC_SPC,                           KC_SFTENT, LT(LOWER,KC_BSPC),
                                      KC_LCTL,KC_LSFT,                        KC_BSPC, KC_RCTL,
                                      KC_LALT, KC_TAB,                        KC_LGUI, MT(MOD_LALT,KC_APP)

  ),

  [_LOWER] = LAYOUT_5x6(

     KC_TILD,RALT(KC_1),RALT(KC_2),KC_DLR ,RALT(KC_4),RALT(KC_5),                  KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,RALT(KC_9),RALT(KC_0),
     _______,_______,_______,RALT(KC_8),RALT(KC_9),KC_LBRC,                        KC_NUBS, KC_P7 , KC_P8 , KC_P9 ,KC_PLUS,KC_NUBS,
     RESET  ,_______,_______,LSFT(KC_8),LSFT(KC_9),KC_LPRN,                        KC_NUHS, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_QUOT,
     KC_PIPE,RALT(KC_NUBS),_______,RALT(KC_7),RALT(KC_0),_______,                        KC_EQL , KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                     _______,KC_PSCR,                                                              ALT_TAB, KC_P0 ,
                                             _______,KC_BSPC,                      KC_DEL,  RAISE,
                                             OSM(MOD_LCTL),OSM(MOD_LSFT),              KC_SFTENT, KC_RCTL,
                                             OSM(MOD_LALT), OSM(MOD_LGUI),                 KC_LGUI, KC_LALT

  ),

  [_RAISE] = LAYOUT_5x6(
       KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                       KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       KC_RBRC,KC_MNXT,KC_NLCK,KC_LALT ,KC_SLCK,KC_MUTE,                      KC_PGUP,LCTL(KC_C),KC_UP ,LCTL(KC_V),LCTL(KC_Z),_______,
       KC_RPRN,KC_MPLY,KC_INS ,KC_LCTL,LCTL(KC_LSFT),KC_VOLD,                 KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,ALT_TAB,LCTL(KC_Z),
       KC_RPRN,KC_MPRV,_______,KC_MNXT,KC_LSFT,KC_VOLU,                       _______,KC_HOME,KC_END,_______,_______,_______,
                       _______,_______,                                               ALT_TAB,ALT_TAB,
                                               OSL(_RAISE),_______,        _______,OSL(_LOWER),
                                               KC_HOME,KC_END ,            KC_PGUP, KC_PGDN,
                                               _______,_______,            KC_BSPC,_______
  ),
};

// From https://www.reddit.com/r/olkb/comments/9ncbhu/brainstorming_for_a_onekey_alttab_function_what/

/*
KC_PLUS = `   }
KC_NUBS = <   >
KC_UNDS = ?
KC_BSLASH = '   *

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
