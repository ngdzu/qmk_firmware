#include "planck.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define XXXXXXX KC_NO
#define ________ KC_TRNS
#define LT_FN2 LT(_FN2, ________)



#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2
#define _FUNC   3
#define _FN1    4
#define _FN2    5



#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCT MO(_FUNC)
#define FN1    MO(_FN1)
#define FN2    MO(_FN2)

// macros
#define M_MOVE_NEXT_LINE 	0
#define M_MOVE_PREV_LINE 	1
#define M_STEP_OUT 		  	2
#define M_MOVE_CUR_LINE 	3
#define M_FIND 				    4
#define M_HOME 			      5
#define M_END 				    6

#define M_CONTINUE_MAC		100

#define FIND M(M_FIND)


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



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | _FUNC|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | Fn1   |Lower|    Space    |Raise | Fn2 | Down  |RCtrl |RShift|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
  KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC ,
  FUNCT   , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
  KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT  ,
  KC_LCTL , KC_LALT , KC_LGUI , FN1     , LOWER   , KC_SPC  , KC_SPC  , RAISE   , ________, ________, KC_RCTL , KC_RSFT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
  KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN   , KC_RPRN , KC_BSPC ,
  KC_DEL  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_UNDS , KC_PLUS , KC_LCBR   , KC_RCBR , KC_PIPE ,
  ________, KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , S(KC_NUHS),S(KC_NUBS),________, ________, ________,
  RESET   , ________, ________, ________, ________, ________, ________, ________, KC_MNXT , KC_VOLD   , KC_VOLU , KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    ,KC_BSPC  ,
  KC_DEL  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS ,
  ________, KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_NUHS , KC_NUBS , ________, ________, ________,
  RESET   , ________, ________, ________, ________, ________, ________, ________, KC_MNXT , KC_VOLD , KC_VOLU , KC_MPLY
),


/* _FUNC
 * ,------------------------------------------------------------------------------------------------.
 * | _____  | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ |
 * |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | _____  | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ |
 * |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | _____  | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ |
 * |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | _____  | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ |
 * `------------------------------------------------------------------------------------------------'
 */
/* _FUNC
 * ,------------------------------------------------------------------------------------------------.
 * | _____  | _____ | UP    | _____ | _____ | _____ | _____ | _____ | UP    | _____ | _____ | _____ |
 * |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | _____  | LEFT  | DOWN  | RIGHT | _____ | _____ | _____ | LEFT  | DOWN  | RIGHT | _____ | _____ |
 * |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | _____  | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ |
 * |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | _____  | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ | _____ |
 * `------------------------------------------------------------------------------------------------'
 */ 

[_FUNC] = LAYOUT_planck_grid(
  ________, ________, ________, KC_MS_U , ________, ________, ________, ________, KC_UP   , ________, ________, ________,
  ________, LT_FN2  , KC_MS_L , KC_MS_D , KC_MS_R , ________, ________, KC_LEFT , KC_DOWN , KC_RGHT , ________, KC_BTN1 ,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________
),

[_FN1] = LAYOUT_planck_grid(
  ________, ________, ________, ________, ________, ________, ________, KC_7    , KC_8    , KC_9    , KC_0    , ________,
  ________, ________, ________, ________, ________, ________, ________, KC_4    , KC_5    , KC_6    , ________, ________,
  ________, ________, ________, ________, ________, ________, ________, KC_1    , KC_2    , KC_3    , ________, ________,
  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________
),

[_FN2] = LAYOUT_planck_grid(
  ________, ________, ________, ________, ________, ________, ________, KC_F7   , KC_F8   , KC_F9   , KC_F10  , ________,
  ________, ________, ________, ________, FIND    , ________, ________, KC_F4   , KC_F5   , KC_F6   , KC_F11  , ________,
  ________, ________, ________, ________, ________, ________, ________, KC_F1   , KC_F2   , KC_F3   , KC_F12  , ________,
  ________, ________, ________, ________, ________, ________, ________, ________, STEP_OV , STEP_IN , STEP_OUT, CONT
)


};

const uint16_t PROGMEM fn_actions[] = {

};

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
