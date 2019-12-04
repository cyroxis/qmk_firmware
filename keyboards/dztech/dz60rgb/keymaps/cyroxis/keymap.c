#include QMK_KEYBOARD_H
#define _ANSI 0
#define _OSX 1
#define _RGB 2
#define _FN 3	
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[_ANSI] = LAYOUT_60_ansi(
			KC_GESC,         KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,      KC_MINS,  KC_EQL,  KC_BSPC,  \
			KC_TAB,          KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,      KC_LBRC,  KC_RBRC, KC_BSLASH,\
			CTL_T(KC_CAPS),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,   KC_QUOT,           KC_ENT,   \
			KC_LSFT,         KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                      KC_RSFT,  \
			KC_LCTL,         KC_LGUI,  KC_LALT,                      LT(_FN,KC_SPC),                         KC_RALT,  MO(_FN),   KC_NO,             KC_RCTL),
		[_OSX]    = LAYOUT_60_ansi(
			KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  \
			KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  \
			KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  \
			KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  \
			KC_TRNS,         KC_LALT,  KC_LGUI,                      KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS),
		[_FN]     = LAYOUT_60_ansi(
			KC_GRAVE,        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL ,  \
			KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_INS,   KC_TRNS,  KC_PSCR,  KC_SLCK,  KC_PAUS,  RESET  ,  \
			KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_TRNS,  KC_TRNS,            KC_TRNS, \
			KC_TRNS,         KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_HOME,  KC_PGUP,  KC_PGDN,  KC_END,                       KC_TRNS	, \
			KC_TRNS,         KC_TRNS,  KC_TRNS,                      KC_TRNS,                                KC_TRNS,  KC_TRNS,  TG(_OSX),           TG(_RGB)),
		[_RGB]     = LAYOUT_60_ansi(
		  KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_MODE_PLAIN,  \
			KC_TRNS,         RGB_TOG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_MODE_BREATHE,  \
			KC_TRNS,         RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            RGB_MODE_RAINBOW,  \
			KC_TRNS,         RGB_RMOD, RGB_HUD,  RGB_SAD,  RGB_VAD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      RGB_MODE_SWIRL,  \
			KC_TRNS,         KC_LALT,  KC_LGUI,                      KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,            RGB_MODE_XMAS),
		};
