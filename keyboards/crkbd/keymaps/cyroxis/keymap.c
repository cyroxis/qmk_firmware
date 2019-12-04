#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MOVE 3
#define _FUNC 4
#define _ADJUST 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST
};

#define L_BASE 0
#define L_LOWER (1U << _LOWER)
#define L_RAISE (1U << _RAISE)
#define L_MOVE (1U << _MOVE)
#define L_FUNC (1U << _FUNC)
#define L_ADJUST (1U << _ADJUST)

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

// Custom hold modifiers
#define LG(kc) LGUI_T(kc)
#define LA(kc) LALT_T(kc)
#define LC(kc) LCTL_T(kc)
#define LS(kc) LSFT_T(kc)


#define RG(kc) RGUI_T(kc)
#define RA(kc) RALT_T(kc)
#define RC(kc) RCTL_T(kc)
#define RS(kc) RSFT_T(kc)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
     KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,              KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,   \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
     KC_GRAVE,   LG(KC_A),   LA(KC_S),   LC(KC_D),   KC_F,       KC_G,              KC_H,       KC_J,       RC(KC_K),   RA(KC_L),   RG(KC_SCLN),KC_QUOT,   \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
     KC_LSFT,    LC(KC_Z),   KC_X,       KC_C,       KC_V,       KC_B,              KC_N,       KC_M,       KC_COMM,    KC_DOT,     RC(KC_SLSH),KC_SFTENT, \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
                                         MO(_FUNC),  LOWER,      LG(KC_ENT),        KC_SPC,     RAISE,      MO(_MOVE)  \
  //                                    |-----------+-----------+-----------|      |-----------+-----------+-----------|
  ),

  [_RAISE] = LAYOUT( \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,           KC_PMNS,    KC_7,       KC_8,       KC_9,       KC_PSLS,    KC_TRNS,   \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,           KC_PPLS,    KC_4,       KC_5,       KC_6,       KC_PAST,    KC_TRNS,   \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|  
     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,           KC_PDOT,    KC_1,       KC_2,       KC_3,       KC_PEQL,    KC_TRNS,   \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
                                         KC_TRNS,    KC_TRNS,    KC_TRNS,           KC_TRNS,    KC_TRNS,    KC_0       \
  //                                    |-----------+-----------+-----------|      |-----------+-----------+-----------|
  ),

  [_LOWER] = LAYOUT( \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
     KC_MINS,    KC_EXLM,    KC_AT,      KC_LPRN,    KC_RPRN,    KC_AMPR,           KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
     KC_UNDS,    KC_HASH,    KC_DLR,     KC_LBRC,    KC_RBRC,    KC_ASTR,           KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
     KC_PIPE,    KC_PERC,    KC_CIRC,    KC_LCBR,    KC_RCBR,    KC_BSLS,           KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
                                         KC_TRNS,    KC_TRNS,    KC_TRNS,           KC_TRNS,    KC_TRNS,    KC_TRNS    \
  //                                    |-----------+-----------+-----------|      |-----------+-----------+-----------|
  ),

    [_MOVE] = LAYOUT( \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,           KC_TRNS,    KC_HOME,    KC_PGUP,    KC_PGDN,    KC_END,     KC_DELETE, \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,           A(KC_LEFT), KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   A(KC_RGHT),\
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,           KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
                                         KC_TRNS,    KC_TRNS,    KC_TRNS,           KC_TRNS,    KC_TRNS,    KC_TRNS    \
  //                                    |-----------+-----------+-----------|      |-----------+-----------+-----------|
  ),


  [_FUNC] = LAYOUT( \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
     KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_TRNS,           KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
     KC_SPC,     KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_TRNS,           KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
     KC_TRNS,    KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_TRNS,           KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
                                         KC_TRNS,    KC_TRNS,    KC_TRNS,           KC_TRNS,    KC_TRNS,    KC_TRNS    \
  //                                    |-----------+-----------+-----------|      |-----------+-----------+-----------|
  ),

  [_ADJUST] = LAYOUT( \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
     RESET,      RGBRST,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,           KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
     RGB_TOG,    RGB_HUI,    RGB_SAI,    RGB_VAI,    KC_TRNS,    KC_TRNS,           KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
     RGB_MOD,    RGB_HUD,    RGB_SAD,    RGB_VAD,    KC_TRNS,    KC_TRNS,           KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   \
  //|-----------+-----------+-----------+-----------+-----------+-----------|      |-----------+-----------+-----------+-----------+-----------+-----------|
                                         KC_TRNS,    KC_TRNS,    KC_TRNS,           KC_TRNS,    KC_TRNS,    KC_TRNS    \
  //                                    |-----------+-----------+-----------|      |-----------+-----------+-----------|
  ),
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
  iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}

char layer_state_str[24];

const char *read_layer_state(void) {
  if (L_ADJUST & layer_state) {
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
  } else if (L_MOVE & layer_state) {
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Move");
  } else if (L_FUNC & layer_state) {
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Func");
  } else if (L_LOWER & layer_state) {
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
  } else if (L_RAISE & layer_state) {
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
  } else if (L_BASE == layer_state) {
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
  } else {
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}
