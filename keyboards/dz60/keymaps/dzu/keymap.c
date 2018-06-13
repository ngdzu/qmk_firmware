#include "dz60.h"


#define M_MOVE_NEXT_LINE 	0
#define M_MOVE_PREV_LINE 	1
#define M_STEP_OUT 			2
#define M_MOVE_CUR_LINE 	3
#define M_FIND 				4
#define M_HOME 				5
#define M_END 				6

#define M_CONTINUE_MAC		100


#define M_MNL M_MOVE_NEXT_LINE
#define M_MPL M_MOVE_PREV_LINE
#define M_STO M_STEP_OUT
#define M_MCL M_MOVE_CUR_LINE

#define M_C_MAC M_CONTINUE_MAC

#define KC_STEP_OVER KC_F10
#define KC_STEP_IN KC_F11
#define CONT KC_F5

#define STEP_OV KC_STEP_OVER
#define STEP_IN KC_STEP_IN
#define STEP_OUT M(M_STO)


#define STEP_OV_MAC KC_F6
#define STEP_IN_MAC KC_F7
#define STEP_OUT_MAC KC_F8
#define CONT_MAC M(M_C_MAC)

enum dz60_layers {
  _WIN,
  _WIN_FUNC,
  _WIN_FUNC_DEBUG,
  _WIN_FUNC2,
  _MAC,
  _MAC_FUNC,
  _MAC_FUNC_DEBUG,
  _MAC_FUNC2,
  _LIGHT
};

enum dz60_keycodes {
  WIN = SAFE_RANGE,
  MAC
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_WIN] = LAYOUT_63(
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_GRV, KC_BSLS, 
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC, 
		MO(_WIN_FUNC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_DEL, 
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RCTL, KC_RALT, KC_NO, MO(_LIGHT)),


	[_WIN_FUNC] = LAYOUT_63(
		RESET, 		KC_F1, KC_F2, 	KC_F3, 	KC_F4, 		KC_F5, KC_F6, KC_F7, 	KC_F8, KC_F9, 	KC_F10, KC_F11, 	KC_F12, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, 	KC_TRNS, KC_TRNS, 
		KC_TRNS, LT(_WIN_FUNC_DEBUG, KC_TRNS), KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_BTN1, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, MO(_WIN_FUNC2), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_WIN_FUNC_DEBUG] = LAYOUT_63(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M(M_MPL), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M(M_FIND), KC_TRNS, KC_TRNS, CONT,   M(M_MNL), M(M_MCL), KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, STEP_OV, STEP_IN, STEP_OUT, CONT),

	[_WIN_FUNC2] = LAYOUT_63(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_D, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_MAC] = LAYOUT_63(
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_GRV, KC_BSLS, 
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC, 
		MO(_MAC_FUNC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_NO, 
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RCTL, KC_RALT, KC_NO, MO(_LIGHT)),

	[_MAC_FUNC] = LAYOUT_63(
		RESET, 	KC_F1, 		KC_F2, KC_F3, 	KC_F4, 	KC_F5, 		KC_F6, KC_F7, 	KC_F8, KC_F9, 	KC_F10, 	KC_F11, KC_F12, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, 	KC_TRNS, KC_TRNS, KC_DEL, 
		KC_TRNS, LT(_MAC_FUNC_DEBUG, KC_TRNS), KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_BTN1, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, MO(_MAC_FUNC2), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_MAC_FUNC_DEBUG] = LAYOUT_63(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M(M_MPL), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M(M_FIND), KC_TRNS, KC_TRNS, CONT,   M(M_MNL), M(M_MCL), KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, STEP_OV_MAC, STEP_IN_MAC, STEP_OUT_MAC, CONT_MAC),

	[_MAC_FUNC2] = LAYOUT_63(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_D, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_LIGHT] = LAYOUT_63(
        KC_TRNS, WIN 	, MAC, 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS,
        KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, RGB_M_G, RGB_M_X, RGB_M_SN, RGB_M_R, RGB_M_B	, RGB_M_K, RGB_M_SW, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	LAYOUT_63(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	LAYOUT_63(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

// How long (in ms) to wait between animation steps for the breathing mode
const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {30, 20, 10, 5};

// How long (in ms) to wait between animation steps for the rainbow mode
const uint8_t RGBLED_RAINBOW_MOOD_INTERVALS[] PROGMEM = {50, 20, 10};

// How long (in ms) to wait between animation steps for the swirl mode
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {50, 20, 10};

// How long (in ms) to wait between animation steps for the snake mode
const uint8_t RGBLED_SNAKE_INTERVALS[] PROGMEM = {50, 80, 40};

// How long (in ms) to wait between animation steps for the knight modes
const uint8_t RGBLED_KNIGHT_INTERVALS[] PROGMEM = {127, 63, 31};

// These control which colors are selected for the gradient mode
const uint16_t RGBLED_GRADIENT_RANGES[] PROGMEM = {360, 240, 180, 120, 90};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	// keyevent_t event = record->event; //unused

	switch (id) {
		case M_MOVE_NEXT_LINE:
			if (record->event.pressed) {
				return MACRO( T(DOWN), D(LCTL), D(LSFT), T(F10), U(LSFT), U(LCTL), END );
			}
			break;
		case M_MOVE_PREV_LINE:
			if (record->event.pressed) {
				return MACRO( T(UP), D(LCTL), D(LSFT), T(F10), U(LSFT), U(LCTL), END );
			}
			break;
		case M_STEP_OUT:
			if (record->event.pressed) {
				return MACRO( D(LSFT), T(F11), U(LSFT), END );
			}
			break;
		case M_MOVE_CUR_LINE:
			if (record->event.pressed) {
				return MACRO( D(LCTL), D(LSFT), T(F10), U(LSFT), U(LCTL), END );
			}
		case M_FIND:
			if (record->event.pressed) {
				return MACRO( D(LCTL), T(F3), U(LCTL), END );
			}
			break;
		case M_HOME:
			if (record->event.pressed) {
				return MACRO( D(LCTL), T(HOME), U(LCTL), END );
			}
			break;
		case M_END:
			if (record->event.pressed) {
				return MACRO( D(LCTL), T(END), U(LCTL), END );
			}
			break;
		case M_CONTINUE_MAC:
			if (record->event.pressed) {
				return MACRO( D(LCTL), D(LALT),T(Y), U(LALT),U(LCTL), END );
			}
			break;
	}
	return MACRO_NONE;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case WIN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WIN);
      }
      return false;
    case MAC:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MAC);
      }
      return false;
  }
  return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}