#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _DEAD 5
#define _ADJUST 15
#define _FN3 5
//#define _FN4 6

enum {
	TD_CPY_PST = 0,
	TD_CMD,
	TD_SLSH,
	TD_VRDSK
};
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  FN3,
//  FN4,
  dance_cln_finished,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

#define KC_LDWN LOWER				//Numpad
#define KC_LUP RAISE
#define KC_X3 LT(_LOWER,KC_SPC)
#define KC_X4 LT(_RAISE,KC_ENT)
#define FUNC_J LT(_DEAD,KC_J)

#define KC_ESCT MT(MOD_LCTL, KC_ESC)
#define KC_GUIT M(0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
        KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F11,     KC_F12 , KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10,
        KC_1  , KC_2  , KC_3  , KC_4  , KC_5  , KC_EQL,     KC_LBRC, KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,
        KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  , KC_ESC,     KC_MINS, KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,
        KC_A  , KC_S  , KC_D  , KC_F  , KC_G  , KC_TAB,     KC_RSFT, KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,
        KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,KC_LSFT,     KC_BSPC, KC_N  , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,
                    //+--61---+-------+-------+-------+    +-------+-------+---63--+-------+
                    //+--6.3--+-------+-------+-------+    +-------+-------+--6.9--+-------+
                        KC_GRV,KC_LALT,                                     KC_RALT,KC_SLSH,
                                    //+--65---+-------+    +--66---+-------+
                                    //+--6.5--+-------+    +--6.7--+-------+
                                       KC_LGUI, KC_X3 ,      KC_X4 ,KC_RGUI,
                                    //+--68---+-------+    +--70---+-------+
                                    //+--7.6--+--7.4--+    +--7.9-+7.7-----+
                                       KC_LCTL,KC_LEFT,      KC_UP ,KC_RCTL,
                                    //+--72---+-------+    +--74---+-------+
                                    //+--7.5--+--7.3--+    +--7.10-+7.8----+
                                       KC_UP  ,KC_DOWN,     KC_LEFT,KC_RIGHT
	),

	[_DVORAK] = LAYOUT(
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_QUOT,KC_COMM, KC_DOT, KC_P  , KC_Y  ,KC_TRNS,     KC_TRNS, KC_F  , KC_G  , KC_C  , KC_R  , KC_L  ,
        KC_A  , KC_O  , KC_E  , KC_U  , KC_I  ,KC_TRNS,     KC_TRNS, KC_D  , KC_H  , KC_T  , KC_N  , KC_S  ,
       KC_SCLN, KC_Q  , FUNC_J, KC_K  , KC_X  ,KC_TRNS,     KC_TRNS, KC_B  , KC_M  , KC_W  , KC_V  , KC_Z  ,
                       KC_TRNS,KC_TRNS,                                     KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS
	),

	[_LOWER] = LAYOUT(
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_LPRN,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_PIPE,KC_TRNS,KC_TRNS,KC_UNDS,KC_QUES,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_LUP,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                       KC_HOME, KC_END,                                     KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS
	),

	[_RAISE] = LAYOUT(
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_BSLS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_LDWN,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                       KC_TRNS,KC_TRNS,                                     KC_PGUP,KC_PGDN,
                                       KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS
	),

	[_DEAD] = LAYOUT(
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_ENT ,KC_DEL,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_BSPC,KC_TRNS,KC_TRNS,KC_TRNS,
                       KC_TRNS,KC_TRNS,                                     KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS
),

	[_ADJUST] = LAYOUT(
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, RESET ,      RESET ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS, QWERTY, DVORAK,KC_TRNS,     KC_TRNS, DVORAK, QWERTY,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_VOLU,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                       KC_TRNS,KC_TRNS,                                     KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS
)
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
  }
  return true;
}
