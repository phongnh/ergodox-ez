#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum custom_layers {
    _PHONG,
    _QWERTY,
    _DVORAK,
    _LOWER,
    _RAISE,
    _SYMBOL,
    _MEDIA,
};

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,
    VRSN,
    EPRM,
    PHONG,
    QWERTY,
    DVORAK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Phong's layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    =   |   1  |   2  |   3  |   4  |   5  | ~L2  |           | ~L1  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  | Del  |           | Esc  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / LGui|
 * |--------+------+------+------+------+------|LOWER |           |RAISE |------+------+------+------+------+--------|
 * |LShift  |Z/Ctrl|   X  |   C  |   V  |   B  |   [  |           |  ]   |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|'"/CAG|   [  |   ]  | GUI  |                                       | ALT  | Left | Down |  Up  |Right |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,--------------.       ,---------------.
 *                                       |App/Alt| LGui |       | Alt  |Ctrl/Esc|
 *                                ,------|-------|------|       |------+--------+------.
 *                                |      |       | Home |       | PgUp |        |      |
 *                                | Space|BkSpace|------|       |------|  Tab   |Enter |
 *                                |      |       | End  |       | PgDn |        |      |
 *                                `---------------------'       `----------------------'
 */
[_PHONG] = LAYOUT_ergodox(
    // left hand
    KC_EQL,               KC_1,             KC_2,           KC_3,     KC_4,     KC_5,           KC_FN2,
    KC_TAB,               KC_Q,             KC_W,           KC_E,     KC_R,     KC_T,           KC_DELT,
    CTL_T(KC_ESC),        KC_A,             KC_S,           KC_D,     KC_F,     KC_G,
    KC_LSFT,              CTL_T(KC_Z),      KC_X,           KC_C,     KC_V,     KC_B,           LT(_LOWER, KC_LBRC),
    LT(_SYMBOL, KC_GRV),  LCAG_T(KC_QUOT),  KC_LBRC,        KC_RBRC,  KC_LGUI,
                                                                                ALT_T(KC_APP),  KC_LGUI,
                                                                                                KC_HOME,
                                                                      KC_SPC,   KC_BSPC,        KC_END,
    // right hand
    KC_FN1,               KC_6,           KC_7,     KC_8,     KC_9,     KC_0,                 KC_MINS,
    KC_ESC,               KC_Y,           KC_U,     KC_I,     KC_O,     KC_P,                 KC_BSLS,
                          KC_H,           KC_J,     KC_K,     KC_L,     LT(_MEDIA, KC_SCLN),  GUI_T(KC_QUOT),
    LT(_RAISE, KC_RBRC),  KC_N,           KC_M,     KC_COMM,  KC_DOT,   CTL_T(KC_SLSH),       KC_RSFT,
                                          KC_RALT,  KC_LEFT,  KC_DOWN,  KC_UP,                LT(_SYMBOL, KC_RGHT),
    KC_LALT,              CTL_T(KC_ESC),
    KC_PGUP,
    KC_PGDN,              KC_TAB,         KC_ENT
),

/* Default Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    =   |   1  |   2  |   3  |   4  |   5  | Left |           | Right|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Del   |   Q  |   W  |   E  |   R  |   T  | ~L2  |           | ~L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Alt/Esc |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / LGui|
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * |LShift  |Z/Ctrl|   X  |   C  |   V  |   B  |   [  |           |  ]   |   N  |   M  |   ,  |   .  |//Ctrl|RShift  |
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
[_QWERTY] = LAYOUT_ergodox(
    // left hand
    KC_EQL,               KC_1,             KC_2,           KC_3,     KC_4,     KC_5,           KC_LEFT,
    KC_DELT,              KC_Q,             KC_W,           KC_E,     KC_R,     KC_T,           KC_FN2,
    ALT_T(KC_ESC),        KC_A,             KC_S,           KC_D,     KC_F,     KC_G,
    KC_LSFT,              CTL_T(KC_Z),      KC_X,           KC_C,     KC_V,     KC_B,           ALL_T(KC_LBRC),
    LT(_SYMBOL, KC_GRV),  LCAG_T(KC_QUOT),  LALT(KC_LSFT),  KC_LEFT,  KC_RGHT,
                                                                                ALT_T(KC_APP),  KC_LGUI,
                                                                                                KC_HOME,
                                                                      KC_SPC,   KC_BSPC,        KC_END,
    // right hand
    KC_RGHT,           KC_6,             KC_7,   KC_8,     KC_9,     KC_0,                 KC_MINS,
    KC_FN1,            KC_Y,             KC_U,   KC_I,     KC_O,     KC_P,                 KC_BSLS,
                       KC_H,             KC_J,   KC_K,     KC_L,     LT(_MEDIA, KC_SCLN),  GUI_T(KC_QUOT),
    MEH_T(KC_RBRC),    KC_N,             KC_M,   KC_COMM,  KC_DOT,   CTL_T(KC_SLSH),       KC_RSFT,
                                         KC_UP,  KC_DOWN,  KC_LBRC,  C_S_T(KC_RBRC),       KC_FN1,
    KC_LALT,           CTL_T(KC_ESC),
    KC_PGUP,
    KC_PGDN,           KC_TAB,           KC_ENT
),

/* Dvorak Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | Left |           |Right |   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   '  |   ,  |   .  |   P  |   Y  | ~L2  |           | ~L1  |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Alt/Esc |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |S / L2|- / LGui|
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |:/Ctrl|   Q  |   J  |   K  |   X  |   [  |           |  ]   |   B  |   M  |   W  |   V  |Z/Ctrl| RShift |
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
[_DVORAK] = LAYOUT_ergodox(
    // left hand
    KC_EQL,               KC_1,             KC_2,           KC_3,     KC_4,     KC_5,           KC_LEFT,
    KC_DELT,              KC_QUOT,          KC_COMM,        KC_DOT,   KC_P,     KC_Y,           KC_FN2,
    ALT_T(KC_ESC),        KC_A,             KC_O,           KC_E,     KC_U,     KC_I,
    KC_LSFT,              CTL_T(KC_SCLN),   KC_Q,           KC_J,     KC_K,     KC_X,           ALL_T(KC_LBRC),
    LT(_SYMBOL, KC_GRV),  LCAG_T(KC_QUOT),  LALT(KC_LSFT),  KC_LEFT,  KC_RGHT,
                                                                                ALT_T(KC_APP),  KC_LGUI,
                                                                                                KC_HOME,
                                                                      KC_SPC,   KC_BSPC,        KC_END,
    // right hand
    KC_RGHT,           KC_6,             KC_7,   KC_8,     KC_9,     KC_0,              KC_BSLS,
    KC_FN1,            KC_F,             KC_G,   KC_C,     KC_R,     KC_L,              KC_SLSH,
                       KC_D,             KC_H,   KC_T,     KC_N,     LT(_MEDIA, KC_S),  GUI_T(KC_MINS),
    MEH_T(KC_RBRC),    KC_B,             KC_M,   KC_W,     KC_V,     CTL_T(KC_Z),       KC_RSFT,
                                         KC_UP,  KC_DOWN,  KC_LBRC,  C_S_T(KC_RBRC),    KC_FN1,
    KC_LALT,           CTL_T(KC_ESC),
    KC_PGUP,
    KC_PGDN,           KC_TAB,           KC_ENT
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
 *   |  ~   |   "  |      |      |      |                                       |      |      |   {  |   }  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_LOWER] = LAYOUT_ergodox(
    // left hand
    KC_F12,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_TRNS,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,
    KC_TRNS,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_LCBR,
    KC_TILD,  KC_DQT,   KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,
                                            KC_TRNS,  KC_TRNS,  KC_TRNS,
    // right hand
    KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
    KC_TRNS,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_PIPE,
              KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_COLN,  KC_DQT,
    KC_RCBR,  KC_UNDS,  KC_PLUS,  KC_LT,    KC_GT,    KC_QUES,  KC_TRNS,
                        KC_TRNS,  KC_TRNS,  KC_LCBR,  KC_RCBR,  KC_TRNS,
    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS
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
 *   |  ~   |   "  |      |      |      |                                       |      |      |   {  |   }  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_RAISE] = LAYOUT_ergodox(
    // left hand
    KC_F12,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_TRNS,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,
    KC_TRNS,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_LCBR,
    KC_TILD,  KC_DQT,   KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,
                                            KC_TRNS,  KC_TRNS,  KC_TRNS,
    // right hand
    KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
    KC_TRNS,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_PIPE,
              KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_COLN,  KC_DQT,
    KC_RCBR,  KC_UNDS,  KC_PLUS,  KC_LT,    KC_GT,    KC_QUES,  KC_TRNS,
                        KC_TRNS,  KC_TRNS,  KC_LCBR,  KC_RCBR,  KC_TRNS,
    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS
),

/* Symbol Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Insert |   !  |   @  |   {  |   }  |   |  |      |           |      |  Up  |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Capslock|   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  | PrtScr |
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
    VRSN,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
    KC_INS,   KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,  KC_PIPE,  KC_TRNS,
    KC_CAPS,  KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,  KC_GRV,
    KC_TRNS,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILD,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,
                                            KC_TRNS,  KC_TRNS,  KC_TRNS,
    // right hand
    KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
    KC_TRNS,  KC_UP,    KC_7,     KC_8,     KC_9,     KC_ASTR,  KC_F12,
              KC_DOWN,  KC_4,     KC_5,     KC_6,     KC_PLUS,  KC_PSCR,
    KC_TRNS,  KC_AMPR,  KC_1,     KC_2,     KC_3,     KC_BSLS,  KC_TRNS,
                        EPRM,     KC_DOT,   KC_0,     KC_EQL,   KC_TRNS,
    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS
),

/* Media and mouse keys
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Wake  | PHONG|QWERTY|DVORAK|      |      |Sleep |           |Power | F14  | F15  |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |MClick| MsUp |RClick|      |      |           |      |      |RClick| SUp  |MClick|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |LClick|MsLeft|MsDown|MsRght|LClick|------|           |------|LClick| SLeft| SDown|SRight|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |AGnorm|AGswap|                                       |VolUp |VolDn | Mute |      |      |
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
    KC_WAKE,  PHONG,    QWERTY,   DVORAK,   KC_TRNS,  KC_TRNS,  KC_SLEP,
    KC_TRNS,  KC_TRNS,  KC_BTN3,  KC_MS_U,  KC_BTN2,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_BTN1,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN1,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  AG_NORM,  AG_SWAP,
                                                      KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,
                                            KC_BTN1,  KC_BTN2,  KC_TRNS,
    // right hand
    KC_PWR,   KC_F14,   KC_F15,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_BTN2,  KC_WH_U,  KC_BTN3,  KC_TRNS,  KC_TRNS,
              KC_BTN1,  KC_WH_L,  KC_WH_D,  KC_WH_R,  KC_TRNS,  KC_MPLY,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MNXT,  KC_TRNS,  KC_TRNS,
                        KC_VOLU,  KC_VOLD,  KC_MUTE,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_BTN1,  KC_BTN2
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
    case PHONG:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_PHONG);
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
// ErgoDox EZ Default
/*
uint32_t layer_state_set_user(uint32_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    ergodox_led_all_set(LED_BRIGHTNESS_LO);   // Phong's change

    uint8_t layer = biton32(state);
    switch (layer) {
        case 0:
            break;
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

    return state;
};
*/

// Runs whenever there is a layer state change.
/*
uint32_t layer_state_set_user(uint32_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_led_all_set(LED_BRIGHTNESS_LO);

    uint8_t layer = biton32(state);
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

    return state;
}
*/

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    ergodox_led_all_set(LED_BRIGHTNESS_LO);

    uint8_t layer = biton32(state);
    switch (layer) {
        case _PHONG:
            break;
        case _LOWER:
            ergodox_right_led_1_on();
            break;
        case _RAISE:
            ergodox_right_led_2_on();
            break;
        case _SYMBOL:
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
