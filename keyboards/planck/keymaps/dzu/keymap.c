// #include "planck.h"

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.



enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST,
  _FC0,
  _FC1,
  _FC2,
  _FC3
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN0 MO(_FC0)
#define FN1    MO(_FC1)
#define FN2    MO(_FC2)
#define FN3    MO(_FC3)

// macros
enum macros
{
  M_MOVE_NEXT_LINE = 0,
  M_MOVE_PREV_LINE,
  M_STEP_OUT,
  M_MOVE_CUR_LINE,
  M_FIND,
  M_FIND_NEX,
  M_FIND_REV,
  M_HOME,
  M_END,
  M_SYMBOL,
  M_FILE, 
  M_COPY,
  M_PASTE,
  M_CUT,
  M_000 // 3 zeros
};

#define M_CONTINUE_MAC		100

#define FIND M(M_FIND)
#define RFIND M(M_FIND_REV)
#define NFIND M(M_FIND_NEX)

#define SYMBOL M(M_SYMBOL)
#define FILE M(M_FILE)
#define _000 M(M_000)

#define CPY M(M_COPY)
#define PST M(M_PASTE)
#define CUT M(M_CUT)

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

// Fillers to make layering more clear
#define XXXXXXXX KC_NO
#define ________ KC_TRNS
#define LT_FC2 LT(_FC2, ________)

#define _NAVIGATE _FC3
#define MO_FC3 MO(_FC3)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | _FC0|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | FN1  | GUI  |Alt   | Ctrl |LOWER |    Space    |RAISE | Ctrl |      |      | Del  |
 * `-----------------------------------------------------------------------------------'
 */
    [_QWERTY] = LAYOUT_planck_grid(
        KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC ,
        FN0     , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
        KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT  ,
        FN1     , KC_LGUI , KC_LALT , KC_LCTL , LOWER   , KC_SPC  , KC_SPC  , RAISE   , KC_RCTL , ________, ________, KC_DEL  ),

    /* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |   |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
    [_LOWER] = LAYOUT_planck_grid(
        KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_BSPC ,
        ________, ________, KC_LBRC , KC_RBRC , ________, ________, ________, ________, KC_UNDS , KC_PLUS , ________, ________,
        ________, ________, ________, ________, ________, ________, ________, KC_PIPE , KC_LT   , KC_GT   , KC_QUES , ________,
        RESET   , ________, ________, ________, ________, ________, ________, ________, ________, KC_VOLD , KC_VOLU , KC_MPLY),

    /* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
    [_RAISE] = LAYOUT_planck_grid(
        KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC ,
        KC_DEL  , ________, KC_LPRN , KC_RPRN , ________, ________, ________, ________, KC_MINS , KC_EQL  , ________, ________,
        ________, ________, KC_LCBR , KC_RCBR , ________, ________, ________, KC_BSLS , KC_MINS , KC_GT   , ________, ________,
        RESET   , ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________),

    // [_RAISE] = LAYOUT_planck_grid(
    //   KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    ,KC_BSPC  ,
    //   KC_DEL  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS ,
    //   ________, KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_NUHS , KC_NUBS , ________, ________, ________,
    //   RESET   , ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________
    // ),

    /* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_PLOVER] = LAYOUT_planck_grid(
        KC_1    , KC_1    , KC_1    , KC_1    , KC_1    , KC_1    , KC_1    , KC_1    , KC_1    , KC_1    , KC_1    , KC_1    ,
        XXXXXXXX, KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_LBRC ,
        XXXXXXXX, KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
        EXT_PLV , XXXXXXXX, XXXXXXXX, KC_C    , KC_V    , XXXXXXXX, XXXXXXXX, KC_N    , KC_M    , XXXXXXXX, XXXXXXXX, XXXXXXXX),

    /* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_ADJUST] = LAYOUT_planck_grid(
      _______ , RESET   , DEBUG   , RGB_TOG , RGB_MOD , RGB_HUI , RGB_HUD , RGB_SAI , RGB_SAD , RGB_VAI , RGB_VAD , KC_DEL  ,
      _______ , _______ , MU_MOD  , AU_ON   , AU_OFF  , AG_NORM , AG_SWAP , QWERTY  , COLEMAK , DVORAK  , PLOVER  , _______ ,
       _______, MUV_DE  , MUV_IN  , MU_ON   , MU_OFF  , MI_ON   , MI_OFF  , TERM_ON , TERM_OFF, _______ , _______ , _______ ,
       _______, _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______),

    /* _FC0
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
    /* _FC0
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

    [_FC0] = LAYOUT_planck_grid(
        KC_ESC  , XXXXXXXX, XXXXXXXX, KC_MS_U , XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, KC_UP   , XXXXXXXX, XXXXXXXX, XXXXXXXX,
        XXXXXXXX, LT_FC2  , KC_MS_L , KC_MS_D , KC_MS_R , KC_BTN2 , XXXXXXXX, KC_LEFT , KC_DOWN , KC_RGHT , XXXXXXXX, KC_BTN1 ,
        XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, ________,
        ________, ________, ________, ________, ________, MO_FC3  , ________, ________, ________, ________, ________, ________),
    


    /* _FC0
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
    [_FC1] = LAYOUT_planck_grid(
        XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, KC_7    , KC_8    , KC_9    , KC_ASTR , ________,
        XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, KC_4    , KC_5    , KC_6    , KC_MINS , XXXXXXXX,
        XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, KC_1    , KC_2    , KC_3    , KC_PLUS , ________,
        XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, KC_0    , _000    , KC_DOT  , KC_SLSH , XXXXXXXX),

    [_FC2] = LAYOUT_planck_grid(
        XXXXXXXX, XXXXXXXX, XXXXXXXX, SYMBOL  , FILE    , XXXXXXXX, XXXXXXXX, KC_F7   , KC_F8   , KC_F9   , KC_F10  , XXXXXXXX,
        XXXXXXXX, XXXXXXXX, NFIND   , RFIND   , FIND    , XXXXXXXX, XXXXXXXX, KC_F4   , KC_F5   , KC_F6   , KC_F11  , XXXXXXXX,
        XXXXXXXX, XXXXXXXX, CUT     , CPY     , PST     , XXXXXXXX, XXXXXXXX, KC_F1   , KC_F2   , KC_F3   , KC_F12  , ________,
        XXXXXXXX, XXXXXXXX, XXXXXXXX, ________, ________, ________, ________, ________, STEP_OV , STEP_IN , STEP_OUT, CONT), 

    [_FC3] = LAYOUT_planck_grid(
        XXXXXXXX, XXXXXXXX, XXXXXXXX, KC_WH_U , XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, KC_PGUP , XXXXXXXX, XXXXXXXX, XXXXXXXX,
        XXXXXXXX, XXXXXXXX, KC_WH_L , KC_WH_D , KC_WH_R , XXXXXXXX, XXXXXXXX, KC_HOME , KC_PGDN , KC_END  , XXXXXXXX, XXXXXXXX,
        XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, XXXXXXXX, ________,
        ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________)

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
		case M_FIND_REV:
			if (record->event.pressed) {
				return MACRO( D(LSFT), T(F3), U(LSFT), END );
			}
			break;
    case M_FIND_NEX:
      if (record->event.pressed)
      {
        return MACRO(T(F3), END);
      }
      break;
    case M_COPY:
      if (record->event.pressed)
      {
        return MACRO(D(LCTL), T(C), U(LCTL), END);
      }
      break;
    case M_PASTE:
      if (record->event.pressed)
      {
        return MACRO(D(LCTL), T(V), U(LCTL), END);
      }
      break;
    case M_CUT:
      if (record->event.pressed)
      {
        return MACRO(D(LCTL), T(X), U(LCTL), END);
      }
      break;
    case M_FILE:
      if (record->event.pressed)
      {
        return MACRO(D(LALT), D(LSFT), T(O), U(LSFT), U(LALT), END);
      }
      break;
    case M_SYMBOL:
      if (record->event.pressed)
      {
        return MACRO(D(LALT), D(LSFT), T(S), U(LSFT), U(LALT), END);
      }
      break;
    case M_000:
      if (record->event.pressed)
      {
        return MACRO(T(0), T(0), T(0), END);
      }
      break;
  }
	return MACRO_NONE;
}

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case QWERTY:
    //   if (record->event.pressed) {
    //     print("mode just switched to qwerty and this is a huge string\n");
    //     set_single_persistent_default_layer(_QWERTY);
    //   }
    //   return false;
    //   break;
    // case COLEMAK:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_COLEMAK);
    //   }
    //   return false;
    //   break;
    // case DVORAK:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_DVORAK);
    //   }
    //   return false;
    //   break;
    // case BACKLIT:
    //   if (record->event.pressed) {
    //     register_code(KC_RSFT);
    //     #ifdef BACKLIGHT_ENABLE
    //       backlight_step();
    //     #endif
    //     #ifdef KEYBOARD_planck_rev5
    //       PORTE &= ~(1<<6);
    //     #endif
    //   } else {
    //     unregister_code(KC_RSFT);
    //     #ifdef KEYBOARD_planck_rev5
    //       PORTE |= (1<<6);
    //     #endif
    //   }
    //   return false;
    //   break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}


bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #else
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
