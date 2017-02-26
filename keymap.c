#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "version.h"

enum custom_layers {
    _CUSTOM,
    _QWERTY,
    _DVORAK,
    _SYMBOL,
    _MEDIA,
};

enum custom_keycodes {
    CUSTOM = SAFE_RANGE,
    QWERTY,
    DVORAK,
    VRSN,
    EPRM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* My Custom Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    =   |   1  |   2  |   3  |   4  |   5  | Left |           | Right|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Del   |   Q  |   W  |   E  |   R  |   T  | ~L2  |           | ~L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Alt/Bks |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / LGui|
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * |LShift  |Z/Ctrl|   X  |   C  |   V  |   B  | Esc  |           |Space |   N  |   M  |   ,  |   .  |//Ctrl|RShift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|'"/CAG|AltShf|   [  |   ]  |                                       | Left | Down |  Up  |Right | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,--------------.       ,---------------.
 *                                       |App/Alt| LGui |       | Alt  |Ctrl/Esc|
 *                                ,------|-------|------|       |------+--------+------.
 *                                |      |       | Home |       | PgUp |        |      |
 *                                | Space|BkSpace|------|       |------|  Tab   |Enter |
 *                                |      |       | End  |       | PgDn |        |      |
 *                                `---------------------'       `----------------------'
 */
[_CUSTOM] = KEYMAP(
    // left hand
    KC_EQL,               KC_1,             KC_2,           KC_3,     KC_4,     KC_5,           KC_LEFT,
    KC_DELT,              KC_Q,             KC_W,           KC_E,     KC_R,     KC_T,           KC_FN2,
    ALT_T(KC_BSPC),       KC_A,             KC_S,           KC_D,     KC_F,     KC_G,
    KC_LSFT,              CTL_T(KC_Z),      KC_X,           KC_C,     KC_V,     KC_B,           ALL_T(KC_ESC),
    LT(_SYMBOL, KC_GRV),  LCAG_T(KC_QUOT),  LALT(KC_LSFT),  KC_LBRC,  KC_RBRC,
                                                                                ALT_T(KC_APP),  KC_LGUI,
                                                                                                KC_HOME,
                                                                      KC_SPC,   KC_BSPC,        KC_END,
    // right hand
    KC_RGHT,           KC_6,            KC_7,         KC_8,     KC_9,     KC_0,                 KC_MINS,
    KC_FN1,            KC_Y,            KC_U,         KC_I,     KC_O,     KC_P,                 KC_BSLS,
                       KC_H,            KC_J,         KC_K,     KC_L,     LT(_MEDIA, KC_SCLN),  GUI_T(KC_QUOT),
    MEH_T(KC_SPC),     KC_N,            KC_M,         KC_COMM,  KC_DOT,   CTL_T(KC_SLSH),       KC_RSFT,
                                        KC_LEFT,      KC_DOWN,  KC_UP,    C_S_T(KC_RIGHT),      KC_FN1,
    KC_LALT,           CTL_T(KC_ESC),
    KC_PGUP,
    KC_PGDN,           KC_TAB,          KC_ENT
),

/* Default Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    =   |   1  |   2  |   3  |   4  |   5  | Left |           | Right|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Del   |   Q  |   W  |   E  |   R  |   T  | ~L2  |           | ~L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Alt/Bks |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / LGui|
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * |LShift  |Z/Ctrl|   X  |   C  |   V  |   B  | Esc  |           |Space |   N  |   M  |   ,  |   .  |//Ctrl|RShift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|'"/CAG|AltShf| Left | Right|                                       |  Up  | Down |   [  |]/CShf| ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,--------------.       ,---------------.
 *                                       |App/Alt| LGui |       | Alt  |Ctrl/Esc|
 *                                ,------|-------|------|       |------+--------+------.
 *                                |      |       | Home |       | PgUp |        |      |
 *                                | Space|BkSpace|------|       |------|  Tab   |Enter |
 *                                |      |       | End  |       | PgDn |        |      |
 *                                `---------------------'       `----------------------'
 */
[_QWERTY] = KEYMAP(
    // left hand
    KC_EQL,               KC_1,             KC_2,           KC_3,     KC_4,     KC_5,           KC_LEFT,
    KC_DELT,              KC_Q,             KC_W,           KC_E,     KC_R,     KC_T,           KC_FN2,
    ALT_T(KC_BSPC),       KC_A,             KC_S,           KC_D,     KC_F,     KC_G,
    KC_LSFT,              CTL_T(KC_Z),      KC_X,           KC_C,     KC_V,     KC_B,           ALL_T(KC_ESC),
    LT(_SYMBOL, KC_GRV),  LCAG_T(KC_QUOT),  LALT(KC_LSFT),  KC_LEFT,  KC_RGHT,
                                                                                ALT_T(KC_APP),  KC_LGUI,
                                                                                                KC_HOME,
                                                                      KC_SPC,   KC_BSPC,        KC_END,
    // right hand
    KC_RGHT,           KC_6,            KC_7,         KC_8,     KC_9,     KC_0,                 KC_MINS,
    KC_FN1,            KC_Y,            KC_U,         KC_I,     KC_O,     KC_P,                 KC_BSLS,
                       KC_H,            KC_J,         KC_K,     KC_L,     LT(_MEDIA, KC_SCLN),  GUI_T(KC_QUOT),
    MEH_T(KC_SPC),     KC_N,            KC_M,         KC_COMM,  KC_DOT,   CTL_T(KC_SLSH),       KC_RSFT,
                                        KC_UP,        KC_DOWN,  KC_LBRC,  C_S_T(KC_RBRC),       KC_FN1,
    KC_LALT,           CTL_T(KC_ESC),
    KC_PGUP,
    KC_PGDN,           KC_TAB,          KC_ENT
),

/* Dvorak Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | Left |           |Right |   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   '  |   ,  |   .  |   P  |   Y  | ~L2  |           | ~L1  |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Alt/Bks |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |S / L2|- / LGui|
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |:/Ctrl|   Q  |   J  |   K  |   X  | Esc  |           |Space |   B  |   M  |   W  |   V  |Z/Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|'"/CAG|AltShf| Left | Right|                                       |  Up  | Down |   [  |]/CShf| ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,--------------.       ,---------------.
 *                                       |App/Alt| LGui |       | Alt  |Ctrl/Esc|
 *                                ,------|-------|------|       |------+--------+------.
 *                                |      |       | Home |       | PgUp |        |      |
 *                                | Space|BkSpace|------|       |------|  Tab   |Enter |
 *                                |      |       | End  |       | PgDn |        |      |
 *                                `---------------------'       `----------------------'
 */
[_DVORAK] = KEYMAP(
    // left hand
    KC_EQL,               KC_1,             KC_2,           KC_3,     KC_4,     KC_5,           KC_LEFT,
    KC_DELT,              KC_QUOT,          KC_COMM,        KC_DOT,   KC_P,     KC_Y,           KC_FN2,
    ALT_T(KC_BSPC),       KC_A,             KC_O,           KC_E,     KC_U,     KC_I,
    KC_LSFT,              CTL_T(KC_SCLN),   KC_Q,           KC_J,     KC_K,     KC_X,           ALL_T(KC_ESC),
    LT(_SYMBOL, KC_GRV),  LCAG_T(KC_QUOT),  LALT(KC_LSFT),  KC_LEFT,  KC_RGHT,
                                                                                ALT_T(KC_APP),  KC_LGUI,
                                                                                                KC_HOME,
                                                                      KC_SPC,   KC_BSPC,        KC_END,
    // right hand
    KC_RGHT,        KC_6,           KC_7,     KC_8,     KC_9,     KC_0,              KC_BSLS,
    KC_FN1,         KC_F,           KC_G,     KC_C,     KC_R,     KC_L,              KC_SLSH,
                    KC_D,           KC_H,     KC_T,     KC_N,     LT(_MEDIA, KC_S),  GUI_T(KC_MINS),
    MEH_T(KC_SPC),  KC_B,           KC_M,     KC_W,     KC_V,     CTL_T(KC_Z),       KC_RSFT,
                                    KC_UP,    KC_DOWN,  KC_LBRC,  C_S_T(KC_RBRC),    KC_FN1,
    KC_LALT,        CTL_T(KC_ESC),
    KC_PGUP,
    KC_PGDN,        KC_TAB,         KC_ENT
),

/* Symbol Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |  Up  |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
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
[_SYMBOL] = KEYMAP(
    // left hand
    VRSN,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
    KC_TRNS,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,  KC_PIPE,  KC_TRNS,
    KC_TRNS,  KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,  KC_GRV,
    KC_TRNS,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILD,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,
                                            KC_TRNS,  KC_TRNS,  KC_TRNS,
    // right hand
    KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
    KC_TRNS,  KC_UP,    KC_7,     KC_8,     KC_9,     KC_ASTR,  KC_F12,
              KC_DOWN,  KC_4,     KC_5,     KC_6,     KC_PLUS,  KC_TRNS,
    KC_TRNS,  KC_AMPR,  KC_1,     KC_2,     KC_3,     KC_BSLS,  KC_TRNS,
                        EPRM,     KC_DOT,   KC_0,     KC_EQL,   KC_TRNS,
    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS
),

/* Media and mouse keys
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Wake  |CUSTOM|QWERTY|DVORAK|      |      |Sleep |           |Power |ScrLck|Pause |Insert|      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |MClick| MsUp |RClick|      |      |           |      |      |RClick| SUp  |MClick|PrtScr|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Capslock|LClick|MsLeft|MsDown|MsRght|LClick|------|           |------|LClick| SLeft| SDown|SRight|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      | App  |      |      |           |      |      | Menu | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |LClick|RClick|------|       |------|LClick|RClick|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_MEDIA] = KEYMAP(
    // left hand
    KC_WAKE,  CUSTOM,   QWERTY,   DVORAK,  KC_TRNS,  KC_TRNS,  KC_SLEP,
    KC_TRNS,  KC_TRNS,  KC_BTN3,  KC_MS_U,  KC_BTN2,  KC_TRNS,  KC_TRNS,
    KC_CAPS,  KC_BTN1,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN1,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_APP,   KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,
                                            KC_BTN1,  KC_BTN2,  KC_TRNS,
    // right hand
    KC_PWR,   KC_SLCK,  KC_PAUS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_BTN2,  KC_WH_U,  KC_BTN3,  KC_PSCR,  KC_TRNS,
              KC_BTN1,  KC_WH_L,  KC_WH_D,  KC_WH_R,  KC_TRNS,  KC_MPLY,
    KC_TRNS,  KC_TRNS,  KC_MENU,  KC_MPRV,  KC_MNXT,  KC_TRNS,  KC_TRNS,
                        KC_VOLU,  KC_VOLD,  KC_MUTE,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_BTN1,  KC_BTN2
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(_SYMBOL),
    [2] = ACTION_LAYER_TAP_TOGGLE(_MEDIA),
};

void persistant_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
//     // MACRODOWN only works in this function
//     switch(id) {
//     case 0:
//         if (record->event.pressed) {
//             SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
//         }
//         break;
//     case 1:
//         if (record->event.pressed) { // For resetting EEPROM
//             eeconfig_init();
//         }
//         break;
//     }
//     return MACRO_NONE;
// };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CUSTOM:
        if (record->event.pressed) {
            persistant_default_layer_set(1UL << _CUSTOM);
        }
        return false;
        break;
    case QWERTY:
        if (record->event.pressed) {
            persistant_default_layer_set(1UL << _QWERTY);
        }
        return false;
        break;
    case DVORAK:
        if (record->event.pressed) {
            persistant_default_layer_set(1UL << _DVORAK);
        }
        return false;
        break;
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
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_led_all_set(LED_BRIGHTNESS_LO);

    switch (layer) {
    case _SYMBOL:
        ergodox_right_led_1_on();
        break;
    case _MEDIA:
        ergodox_right_led_2_on();
        break;
    default:
        break;
    }

    // capslock
    if (host_keyboard_leds() & (3 << USB_LED_CAPS_LOCK)) {
        ergodox_right_led_3_on();
    }
    else {
        ergodox_right_led_3_off();
    }
};
