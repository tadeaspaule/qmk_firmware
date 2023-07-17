#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  CUSTOM_PIPE,
  LOWER,
  RAISE,
  ADJUST,
};

const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
  {{4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 6}},
  {{4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}},
  {{4, 7}, {3, 7}, {2, 7}, {3, 7}, {4, 7}},
  {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}},
  {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}},
  {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}},
  {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}},
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   .  |   ,  | CTRL |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | Ctrl | LOWER|      |    |      | RAISE| Shift|
 *                  `-------------| Space|    |BckSpc|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_QWERTY] = LAYOUT_split_3x5_3( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_P, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_DOT,  KC_COMM, KC_LCTL, \
                    KC_LALT, LOWER, KC_SPC,         KC_BSPC, RAISE, KC_LSFT                 \
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   +  |   -  |   =  |   /  |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   6  |   7  |   8  |   9  |   0  |           |   :  |   @  |  TAB |   *  |   ^  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |   `  |   ~  |  GUI |      |           |   ;  |   %  |   $  |   \  |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_RAISE] = LAYOUT_split_3x5_3( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_PLUS, KC_MINS, KC_EQL, KC_SLSH, KC_ASTR,   \
  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,         KC_COLN, KC_DQT, KC_TAB, KC_ASTR, KC_CIRC,    \
  KC_0,    KC_GRV,  KC_PIPE, KC_LGUI, KC_0,         KC_SCLN, KC_PERC, KC_DLR, KC_NUBS, _______,       \
                    _______, _______, _______,      _______, _______, _______                    \
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   ?  |   '  |   "  |   #  |           |   (  |   [  |   {  |   &  |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | left | down |  up  | right|  Esc |           |   $  |   _  |   <  |   >  |   |  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Caps | Win  |      | Del  |      |           |   )  |   ]  |   }  |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|  Del |
 *                  `-------------| Enter|    | Enter|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_LOWER] = LAYOUT_split_3x5_3( \
  KC_EXLM, KC_QUES, KC_QUOT, KC_AT, KC_NUHS,       KC_LPRN, KC_LBRC, KC_LCBR, KC_AMPR, LSFT(KC_NUBS), \
  KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ESC,        KC_DLR, KC_UNDS, KC_LT, KC_GT, LSFT(KC_NUBS), \
  KC_CAPS, KC_LGUI, _______, KC_DEL, _______,      KC_RPRN, KC_RBRC, KC_RCBR, _______,  _______, \
                    _______, _______, KC_ENT,      KC_ENT,  _______, KC_DEL                    \
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |      |      |      |           |      |      |      |Taskmg|caltde|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_ADJUST] =  LAYOUT_split_3x5_3( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, \
  KC_F11,  KC_F12,  _______, _______, _______,      _______, _______, _______, TSKMGR, CALTDEL, \
  QK_BOOT,   _______, _______, _______, _______,      _______, _______, _______, _______,  _______, \
                    _______, _______, _______,      _______,  _______, _______                    \
)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
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
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case CUSTOM_PIPE:
      if (record->event.pressed) {
        SEND_STRING("|");
        layer_on(_ADJUST);
      } else {
      }
      return true;
      break;
  }
  return true;
}
