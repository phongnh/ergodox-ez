#include "ergodox.h"
// #include "debug.h"
#include "action_layer.h"
#include "version.h"
// #include "action_util.h"
// #include "led.h"

#define BASE   0 // default layer
#define SYMB   1 // symbols
#define MDIA   2 // media keys
#define DVORAK 3 // Dvorak layout

// #define VER  M(0) // Macro 0: Show version
// #define EPRM M(1) // Macro 1: Reset EEPROM

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    =   |   1  |   2  |   3  |   4  |   5  | Left |           | Right|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Del   |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L2  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Alt/Bks |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |Alt/J |   K  |   L  |; / L2|' / LGui|
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
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
    // left hand
    KC_EQL,            KC_1,             KC_2,           KC_3,     KC_4,     KC_5,           KC_LEFT,
    KC_DELT,           KC_Q,             KC_W,           KC_E,     KC_R,     KC_T,           TG(SYMB),
    ALT_T(KC_BSPC),    KC_A,             KC_S,           KC_D,     KC_F,     KC_G,
    KC_LSFT,           CTL_T(KC_Z),      KC_X,           KC_C,     KC_V,     KC_B,           ALL_T(KC_ESC),
    LT(SYMB, KC_GRV),  LCAG_T(KC_QUOT),  LALT(KC_LSFT),  KC_LEFT,  KC_RGHT,
                                                                             ALT_T(KC_APP),  KC_LGUI,
                                                                                             KC_HOME,
                                                                   KC_SPC,   KC_BSPC,        KC_END,
    // right hand
    KC_RGHT,           KC_6,            KC_7,         KC_8,     KC_9,     KC_0,               KC_MINS,
    TG(MDIA),          KC_Y,            KC_U,         KC_I,     KC_O,     KC_P,               KC_BSLS,
                       KC_H,            ALT_T(KC_J),  KC_K,     KC_L,     LT(MDIA, KC_SCLN),  GUI_T(KC_QUOT),
    MEH_T(KC_SPC),     KC_N,            KC_M,         KC_COMM,  KC_DOT,   CTL_T(KC_SLSH),     KC_RSFT,
                                        KC_UP,        KC_DOWN,  KC_LBRC,  C_S_T(KC_RBRC),     KC_FN1,
    KC_LALT,           CTL_T(KC_ESC),
    KC_PGUP,
    KC_PGDN,           KC_TAB,          KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   <  |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------|   >  |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat| ERPM |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
    // left hand
    VRSN,      KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
    KC_TRNS,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,  KC_PIPE,  KC_TRNS,
    KC_TRNS,  KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,  KC_GRV,
    KC_TRNS,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILD,  KC_TRNS,
    KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      RGB_MOD,  EPRM,
                                                                KC_TRNS,
                                            RGB_VAD,  RGB_VAI,  KC_TRNS,
    // right hand
    KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
    KC_TRNS,  KC_LT,    KC_7,     KC_8,     KC_9,     KC_ASTR,  KC_F12,
              KC_GT,    KC_4,     KC_5,     KC_6,     KC_PLUS,  KC_TRNS,
    KC_TRNS,  KC_AMPR,  KC_1,     KC_2,     KC_3,     KC_BSLS,  KC_TRNS,
                        KC_TRNS,  KC_DOT,   KC_0,     KC_EQL,   KC_TRNS,
    RGB_TOG,  RGB_SLD,
    KC_TRNS,
    KC_TRNS,  RGB_HUD,  RGB_HUI
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Wake  |      |      |      |      |      |SLEEP |           |POWER |PrtScr|ScrLck|Pause |      |      | Delete |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | SUp  | MsUp |SDown | SUp  |      |           |      |      |      |      |      |      | Insert |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Capslock|SLeft |MsLeft|MsDown|MsRght|SRight|------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |SDown |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      | ACL0 | ACL1 | ACL2 |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Lclk | Rclk |------|       |------| Lclk | Mclk |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
    // left hand
    KC_WAKE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_SLEP,
    KC_TRNS,  KC_TRNS,  KC_WH_U,  KC_MS_U,  KC_WH_D,  KC_WH_U,  KC_TRNS,
    KC_CAPS,  KC_WH_L,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_R,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_WH_D,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_ACL0,  KC_ACL1,  KC_ACL2,
                                                      KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,
                                            KC_BTN1,  KC_BTN2,  KC_TRNS,
    // right hand
    KC_PWR ,  KC_PSCR,  KC_SLCK,  KC_PAUS,  KC_TRNS,  KC_TRNS,  KC_DELT,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_INS,
              KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPLY,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MNXT,  KC_TRNS,  KC_TRNS,
                        KC_VOLU,  KC_VOLD,  KC_MUTE,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_BTN1,  KC_BTN3
),
};

const uint16_t PROGMEM fn_actions[] = {
    [SYMB] = ACTION_LAYER_TAP_TOGGLE(SYMB), // FN1 - Momentary Layer 1 (Symbols)
    [MDIA] = ACTION_LAYER_TAP_TOGGLE(MDIA), // FN2 - Momentary Layer 2 (Media)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    // MACRODOWN only works in this function
    switch(id) {
        case 0:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            break;
        case 1:
            if (record->event.pressed) { // For resetting EEPROM
                eeconfig_init();
            }
            break;
    }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // dynamically generate these.
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
        case RGB_SLD:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                    rgblight_mode(1);
                #endif
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
        // TODO: Make this relevant to the ErgoDox EZ.
        case SYMB:
            ergodox_right_led_1_on();
            break;
        case MDIA:
            ergodox_right_led_2_on();
            break;
        default:
            // none
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
