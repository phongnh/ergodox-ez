#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum ergodox_ez_layers {
    _QWERTY,
    _DVORAK,
    _SYMBOL,
    _LOWER,
    _RAISE,
    _MEDIA,
};

enum ergodox_ez_keycodes {
    PLACEHOLDER = SAFE_RANGE,
    VRSN,
    EPRM,
    QWERTY,
    DVORAK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    =   |   1  |   2  |   3  |   4  |   5  |Left  |           |Right |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  | ~L2  |           | ~L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / LGui|
 * |--------+------+------+------+------+------|LOWER |           |RAISE |------+------+------+------+------+--------|
 * |LShift  |Z/Ctrl|   X  |   C  |   V  |   B  |   [  |           |  ]   |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|'"/CAG|AltShf| Left | Right|                                       |  Up  | Down |   [  |  ]   | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,--------------.       ,---------------.
 *                                       |App/Alt| LGui |       | Alt  |Ctrl/Esc|
 *                                ,------|-------|------|       |------+--------+------.
 *                                |      |       | Home |       | PgUp |        |      |
 *                                | Space|BkSpace|------|       |------|  Tab   |Enter |
 *                                |      |       | End  |       | PgDn |        |      |
 *                                `---------------------'       `----------------------'
 */
[_QWERTY] = LAYOUT_ergodox(
    // left hand
    KC_EQL,               KC_1,             KC_2,           KC_3,     KC_4,            KC_5,           KC_LEFT,
    KC_TAB,               KC_Q,             KC_W,           KC_E,     KC_R,            KC_T,           KC_FN2,
    CTL_T(KC_ESC),        KC_A,             KC_S,           KC_D,     KC_F,            KC_G,
    KC_LSFT,              CTL_T(KC_Z),      KC_X,           KC_C,     KC_V,            KC_B,           LT(_LOWER, KC_LBRC),
    LT(_SYMBOL, KC_GRV),  LCAG_T(KC_QUOT),  LALT(KC_LSFT),  KC_LEFT,  GUI_T(KC_RGHT),
                                                                                       ALT_T(KC_APP),  KC_LGUI,
                                                                                                       KC_HOME,
                                                                      KC_SPC,          KC_BSPC,        KC_END,
    // right hand
    KC_RGHT,              KC_6,           KC_7,          KC_8,     KC_9,     KC_0,                 KC_MINS,
    KC_FN1,               KC_Y,           KC_U,          KC_I,     KC_O,     KC_P,                 KC_BSLS,
                          KC_H,           KC_J,          KC_K,     KC_L,     LT(_MEDIA, KC_SCLN),  GUI_T(KC_QUOT),
    LT(_RAISE, KC_RBRC),  KC_N,           KC_M,          KC_COMM,  KC_DOT,   CTL_T(KC_SLSH),       KC_RSFT,
                                          ALT_T(KC_UP),  KC_DOWN,  KC_LBRC,  KC_RBRC,              KC_FN1,
    KC_LALT,              CTL_T(KC_ESC),
    KC_PGUP,
    KC_PGDN,              KC_TAB,         KC_ENT
),

/* Dvorak Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | Left |           |Right |   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   '  |   ,  |   .  |   P  |   Y  | ~L2  |           | ~L1  |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Alt/Esc |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |S / L2|- / LGui|
 * |--------+------+------+------+------+------|LOWER |           |RAISE |------+------+------+------+------+--------|
 * | LShift |:/Ctrl|   Q  |   J  |   K  |   X  |   [  |           |  ]   |   B  |   M  |   W  |   V  |Z/Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|'"/CAG|AltShf| Left | Right|                                       |  Up  | Down |   [  |  ]   | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,--------------.       ,---------------.
 *                                       |App/Alt| LGui |       | Alt  |Ctrl/Esc|
 *                                ,------|-------|------|       |------+--------+------.
 *                                |      |       | Home |       | PgUp |        |      |
 *                                | Space|BkSpace|------|       |------|  Tab   |Enter |
 *                                |      |       | End  |       | PgDn |        |      |
 *                                `---------------------'       `----------------------'
 */
[_DVORAK] = LAYOUT_ergodox(
    // left hand
    KC_EQL,               KC_1,             KC_2,           KC_3,     KC_4,            KC_5,           KC_LEFT,
    KC_DELT,              KC_QUOT,          KC_COMM,        KC_DOT,   KC_P,            KC_Y,           KC_FN2,
    CTL_T(KC_ESC),        KC_A,             KC_O,           KC_E,     KC_U,            KC_I,
    KC_LSFT,              CTL_T(KC_SCLN),   KC_Q,           KC_J,     KC_K,            KC_X,           LT(_LOWER, KC_LBRC),
    LT(_SYMBOL, KC_GRV),  LCAG_T(KC_QUOT),  LALT(KC_LSFT),  KC_LEFT,  GUI_T(KC_RGHT),
                                                                                       ALT_T(KC_APP),  KC_LGUI,
                                                                                                       KC_HOME,
                                                                      KC_SPC,          KC_BSPC,        KC_END,
    // right hand
    KC_RGHT,              KC_6,             KC_7,          KC_8,     KC_9,     KC_0,              KC_BSLS,
    KC_FN1,               KC_F,             KC_G,          KC_C,     KC_R,     KC_L,              KC_SLSH,
                          KC_D,             KC_H,          KC_T,     KC_N,     LT(_MEDIA, KC_S),  GUI_T(KC_MINS),
    LT(_RAISE, KC_RBRC),  KC_B,             KC_M,          KC_W,     KC_V,     CTL_T(KC_Z),       KC_RSFT,
                                            ALT_T(KC_UP),  KC_DOWN,  KC_LBRC,  KC_RBRC,           KC_FN1,
    KC_LALT,              CTL_T(KC_ESC),
    KC_PGUP,
    KC_PGDN,              KC_TAB,           KC_ENT
),

/* Symbol Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |  Up  |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Capslock|   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | EPRM |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_SYMBOL] = LAYOUT_ergodox(
    // left hand
    VRSN,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    _______,
    _______,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,  KC_PIPE,  _______,
    KC_CAPS,  KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,  KC_GRV,
    _______,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILD,  _______,
    _______,  _______,  _______,  _______,  _______,
                                                      _______,  _______,
                                                                _______,
                                            _______,  _______,  _______,
    // right hand
    _______,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
    _______,  KC_UP,    KC_7,     KC_8,     KC_9,     KC_ASTR,  KC_F12,
              KC_DOWN,  KC_4,     KC_5,     KC_6,     KC_PLUS,  _______,
    _______,  KC_AMPR,  KC_1,     KC_2,     KC_3,     KC_BSLS,  _______,
                        EPRM,     KC_DOT,   KC_0,     KC_EQL,   _______,
    _______,  _______,
    _______,
    _______,  _______,  _______
),

/* Lower Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  F12   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   ~    |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   (  |   )  |   |    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   `    |   1  |   2  |   3  |   4  |   5  |------|           |------| LEFT | DOWN |  UP  | RIGHT|   :  |   "    |
 * |--------+------+------+------+------+------|  {   |           |  }   |------+------+------+------+------+--------|
 * |        |   6  |   7  |   8  |   9  |   0  |      |           |      |   _  |   +  |   <  |   >  |   ?  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------| Del  |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_LOWER] = LAYOUT_ergodox(
    // left hand
    KC_F12,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    _______,
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  _______,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,
    _______,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_LCBR,
    _______,  _______,  _______,  _______,  _______,
                                                      _______,  _______,
                                                                _______,
                                            _______,  _______,  _______,
    // right hand
    _______,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
    _______,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_PIPE,
              KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_COLN,  KC_DQT,
    KC_RCBR,  KC_UNDS,  KC_PLUS,  KC_LT,    KC_GT,    KC_QUES,  _______,
                        _______,  _______,  _______,  _______,  _______,
    _______,  _______,
    _______,
    _______,  KC_DELT,  _______
),

/* Raise Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  F12   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   ~    |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   (  |   )  |   |    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   `    |   1  |   2  |   3  |   4  |   5  |------|           |------| LEFT | DOWN |  UP  | RIGHT|   :  |   "    |
 * |--------+------+------+------+------+------|  {   |           |  }   |------+------+------+------+------+--------|
 * |        |   6  |   7  |   8  |   9  |   0  |      |           |      |   _  |   +  |   <  |   >  |   ?  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | LEFT | DOWN |  UP  | RIGHT|                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      | Del  |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_RAISE] = LAYOUT_ergodox(
    // left hand
    KC_F12,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    _______,
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  _______,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,
    _______,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_LCBR,
    _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,
                                                      _______,  _______,
                                                                _______,
                                            _______,  KC_DELT,  _______,
    // right hand
    _______,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
    _______,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_PIPE,
              KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_COLN,  KC_DQT,
    KC_RCBR,  KC_UNDS,  KC_PLUS,  KC_LT,    KC_GT,    KC_QUES,  _______,
                        _______,  _______,  _______,  _______,  _______,
    _______,  _______,
    _______,
    _______,  _______,  _______
),

/* Media and Mouse Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  | F14  | F15  |QWERTY|DVORAK|      |AGNorm|           |AGSwap|      | Prev | Play | Next | Mute |  Vol-  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |MClick| MsUp |RClick|      |      |           |      |      |RClick| SUp  |MClick|      |  Vol+  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |LClick|MsLeft|MsDown|MsRght|LClick|------|           |------|LClick| SLeft| SDown|SRight|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |LClick|RClick|------|       |------|LClick|RClick|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_MEDIA] = LAYOUT_ergodox(
    // left hand
    RESET,    KC_F14,   KC_F15,   QWERTY,   DVORAK,   _______,  AG_NORM,
    _______,  _______,  KC_BTN3,  KC_MS_U,  KC_BTN2,  _______,  _______,
    _______,  KC_BTN1,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN1,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  AG_NORM,  AG_SWAP,
                                                      _______,  _______,
                                                                _______,
                                            KC_BTN1,  KC_BTN2,  _______,
    // right hand
    _______,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,
    _______,  _______,  KC_BTN2,  KC_WH_U,  KC_BTN3,  _______,  KC_VOLU,
              KC_BTN1,  KC_WH_L,  KC_WH_D,  KC_WH_R,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
                        _______,  _______,  _______,  _______,  _______,
    _______,  _______,
    _______,
    _______,  KC_BTN1,  KC_BTN2
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(_SYMBOL),  // FN1 - Momentary Layer Symbols (_SYMBOL)
    [2] = ACTION_LAYER_TAP_TOGGLE(_MEDIA),   // FN2 - Momentary Layer Media (_MEDIA)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    // MACRODOWN only works in this function
    switch(id) {
    case 0:
        if (record->event.pressed) {
            SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
    case 1:
        if (record->event.pressed) { // For resetting EEPROM
            eeconfig_init();
        }
        break;
    }
    return MACRO_NONE;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case VRSN:
        if (record->event.pressed) {
            SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        return false;
        break;
    case EPRM:
        if (record->event.pressed) {
            eeconfig_init();
        }
        return false;
        break;
    case QWERTY:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
        }
        return false;
        break;
    case DVORAK:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
        }
        return false;
        break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
}

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    ergodox_led_all_set(LED_BRIGHTNESS_LO);

    uint8_t layer = biton32(state);
    switch (layer) {
    case _SYMBOL:
        ergodox_right_led_1_on();
        break;
    case _LOWER:
        ergodox_right_led_2_on();
        break;
    case _RAISE:
        ergodox_right_led_3_on();
        break;
    case _MEDIA:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
    default:
        break;
    }

    return state;
}
