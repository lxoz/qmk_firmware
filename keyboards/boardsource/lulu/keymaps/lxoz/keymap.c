// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// DEFINITION OF LAYER NAMES AND UNICODE SIGNS
enum layers { _QWERTY, _RAISE, _LOWER, _UMLT, _ADJUST };
enum unicode_names { ae_LT, ae_GT, oe_LT, oe_GT, ue_LT, ue_GT, sz, EURO, SNEK, SMILE, LAUGH, COOL, WINK };

const uint32_t PROGMEM unicode_map[] = {
    [ae_LT] = 0x00E4,  // ä OK
    [ae_GT] = 0x00C4,  // Ä OK
    [oe_LT] = 0x00F6,  // ö OK
    [oe_GT] = 0x00D6,  // Ö OK
    [ue_LT] = 0x00FC,  // ü OK
    [ue_GT] = 0x00DC,  // Ü OK
    [sz]    = 0x00DF,  // OK
    [EURO]  = 0x20AC,  // €
    [SNEK]  = 0x1F40D,  // 🐍
    [SMILE] = 0x1F60A,  //
    [LAUGH] = 0x1F602,
    [COOL]  = 0x1F60E,
    [WINK]  = 0x1F609
};

/*  TAP DANCE
enum  {
  TD_SE = 0,
  TD_AH = 1,
  TD_SS = 2,
  TD_OE = 3,
  TD_UE = 4,
  TD_EE = 5,
  TD_QS = 6
};


qk_tap_dance_action_t tap_dance_actions[] = {  a
  [TD_SE] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
  [TD_AH] = ACTION_TAP_DANCE_DOUBLE(KC_A, DE_ADIA),
  [TD_SS] = ACTION_TAP_DANCE_DOUBLE(KC_S, DE_SS),
  [TD_OE] = ACTION_TAP_DANCE_DOUBLE(KC_O, DE_ODIA),
  [TD_UE] = ACTION_TAP_DANCE_DOUBLE(KC_U, DE_UDIA),
  [TD_EE] = ACTION_TAP_DANCE_DOUBLE(KC_E, DE_EURO),
  [TD_QS] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_QUES)
};
*/

// LAYER DEFINITON
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define UMLT MO(_UMLT)
#define ADJUST MO(_ADJUST)

// MOD TAP ALIASES
#define GUI_S LGUI_T(KC_S)
#define ALT_D LALT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

#define CTL_J RCTL_T(KC_J)
#define ALT_K LALT_T(KC_K)
#define GUI_L RGUI_T(KC_L)

#define SFT_ENT LSFT_T(KC_ENT)
#define SFT_SPC LSFT_T(KC_SPC)

// OTHER ALIASES
#define KC_EURO X(EURO)
#define KC_AE XP(ae_LT,ae_GT)
#define KC_OE XP(oe_LT,oe_GT)
#define KC_UE XP(ue_LT,ue_GT)
#define KC_SZ X(sz)
#define KC_SNK X(SNEK)
#define ATCLDL LCTL(LALT(KC_DEL))
#define KC_SNK X(SNEK)
#define KC_SMLE X(SMILE)
#define KC_LAGH X(LAUGH)
#define KC_COOL X(COOL)
#define KC_WINK X(WINK)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY -- Base Layer (1)
     * ,-----------------------------------------.                                ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                                |   6  |   7  |   8  |   9  |   0  | BS   |
     * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                                |   Z  |   U  |   I  |   O  |   P  | DEL  |
     * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
     * |LCTRL |   A  |GUI_S |ALT_D |CTL_F |   G  |-------.                ,-------|   H  |CTL_J |ALT_K |GUI_L |   ;  | INS  |
     * |------+------+------+------+------+------| BOOT  |                | BOOT  |------+------+------+------+------+------|
     * | UMLT |   Y  |   X  |   C  |   V  |   B  |-------|                |-------|   N  |   M  |   ,  |   .  |   /  | UMLT |
     * `-----------------------------------------/       /                \       \-----------------------------------------'
     *                   | LAlt |LOWER |LGUI  | /SFT_ENT/                  \SFT_SPC\ |MENU  |RAISE | RALT |
     *                   |      |      |      |/       /                    \       \|      |      |      |
     *                   `----------------------------'                      '-------'--------------------'
     */

    [_QWERTY] = LAYOUT(
      KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,   KC_7,   KC_8,    KC_9,   KC_0, KC_BSPC, 
      KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                            KC_Z,   KC_U,   KC_I,    KC_O,   KC_P, KC_DEL, 
      KC_LCTL, KC_A,   GUI_S,   ALT_D,   CTL_F,   KC_G,                            KC_H,   CTL_J,  ALT_K,   GUI_L,  KC_SCLN, KC_INS, 
      UMLT,    KC_Y,   KC_X,    KC_C,    KC_V,    KC_B,  QK_BOOT,        QK_BOOT,  KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, UMLT, 
                                KC_LALT, LOWER, KC_LGUI, SFT_ENT,        SFT_SPC,  KC_APP, RAISE, KC_RALT),

    /* RAISE -- LAYER (2)
     * ,-----------------------------------------.                                  ,-----------------------------------------.
     * |   ^  |   _  |   -  |      |      |      |                                  |      |      |      |      |   (  |   )  |
     * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
     * |   ~  |   '  |   "  | HOME |  UP  |  END |                                  |      |      |      |      |   {  |   }  |
     * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
     * |   &  |   +  |   *  | LEFT | DOWN | RIGHT|-------.                  ,-------|      |      |      | COPY |   [  |   ]  |
     * |------+------+------+------+------+------|       |                  |       |------+------+------+------+------+------|
     * |   |  |   \  |   /  |      |      |      |-------|                  |-------|      |      |      |SELECT|   <  |   >  |
     * `-----------------------------------------/       /                   \      \-----------------------------------------'
     *                   | LAlt |LOWER |LGUI  | /    =  /                     \      \  |      | RAISE|      |
     *                   |      |      |      |/       /                       \      \ |      |      |      |
     *                   `----------------------------'                         '------''--------------------'
     */
    [_RAISE] = LAYOUT(
      KC_CIRC, KC_UNDS, KC_PMNS, _______, _______, _______,                          _______, _______, _______, _______, KC_LPRN, KC_RPRN, 
      KC_TILD, KC_QUOT, KC_DQUO, KC_HOME, KC_UP,   KC_END,                           _______, _______, _______, _______, KC_LCBR, KC_RCBR, 
      KC_AMPR, KC_PPLS, KC_ASTR, KC_LEFT, KC_DOWN, KC_RGHT,                          _______, _______, _______, KC_COPY, KC_LBRC, KC_RBRC, 
      KC_PIPE, KC_BSLS, KC_SLSH, _______, _______, _______, _______,        _______, _______, _______, _______, KC_SLCT, KC_LT,   KC_GT,
                                 KC_LALT, LOWER,   KC_LGUI, KC_EQL,         _______, _______, RAISE, _______
                                 
    ),

    /* LOWER -- LAYER (3)
     * ,-----------------------------------------.                                ,-----------------------------------------.
     * | PGUP | MSB1 | MSB2 |      |      |      |                                |  F1  |  F2  |  F3  |   1  |   2  |   3  |
     * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
     * | PGDN | MS U |      |      |      |      |                                |  F4  |  F5  |  F6  |   4  |   5  |   6  |
     * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
     * | MS L | MS D | MS R |      |      |      |-------.                ,-------|  F7  |  F8  |  F9  |   7  |   8  |   9  |
     * |------+------+------+------+------+------|       |                |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|                |-------|  F10 |  F11 |  F12 |   *  |   0  |   +  |
     * `-----------------------------------------/       /                 \      \-----------------------------------------'
     *                   | LAlt |LOWER |LGUI  | /ALT-DEL/                   \      \  |      |      |      |
     *                   |      |      |      |/ CTRL  /                     \      \ |      |      |      |
     *                   `----------------------------'                       '------''--------------------'
     */
    [_LOWER] = LAYOUT(
      KC_PGUP, KC_BTN1, KC_BTN2, _______, _______, _______,                        KC_F1,   KC_F2,   KC_F3,   KC_P1,   KC_P2,   KC_P3, 
      KC_PGDN, KC_MS_U, _______, _______, _______, _______,                        KC_F4,   KC_F5,   KC_F6,   KC_P4,   KC_P5,   KC_P6, 
      KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______,                        KC_F7,   KC_F8,   KC_F9,   KC_P7,   KC_P8,   KC_P9, 
      _______, _______, _______, _______, _______, _______, _______,      _______, KC_F10,  KC_F11,  KC_F12,  KC_PAST, KC_P0,   KC_PPLS, 
                                 KC_LALT, LOWER,  KC_LGUI,  ATCLDL,       _______, _______, _______, _______
                                 
    ),

    /* ADJUST
     * ,-----------------------------------------.                                ,-----------------------------------------.
     * | POWER|BLI/O | BLINC| BLDEC| BLBRT|      |                                |      |      |      |      |      |      |   
     * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
     * | WAKE |      |      |      |      |      |                                |      |      |      |  B+  |  B-  |      |
     * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
     * | SLEEP|BRIT+ |BRIT- |      |      |      |-------.                ,-------|      |      |      |  S+  |  S-  |      |
     * |------+------+------+------+------+------|       |                |       |------+------+------+------+------+------|
     * | MUTE | VOL+ | VOL- |      |      |      |-------|                |-------|      |      | MODE | MODR | SAT- |      |
     * `-----------------------------------------/       /                 \      \-----------------------------------------'
     *                   |      |      |      | /       /                   \      \  |RAISE |BackSP| RGUI |
     *                   |      |      |      |/       /                     \      \ |      |      |      |
     *                   `----------------------------'                       '------''--------------------'
     */
    [_ADJUST] = LAYOUT(
      KC_PWR,  BL_TOGG, BL_INC,  BL_DEC,  BL_BRTG, _______,                         _______, _______, _______, _______, _______, _______, 
      KC_WAKE, _______, _______, _______, _______, _______,                         _______, _______, _______, RGB_VAI, RGB_VAD, _______, 
      KC_SLEP, KC_BRIU, KC_BRID, _______, _______, _______,                         _______, _______, _______, RGB_SAI, RGB_SAD, _______, 
      KC_MUTE, KC_VOLU, KC_VOLD, _______, _______, _______, _______,       _______, _______, _______, RGB_MOD, RGB_RMOD,_______, _______, 
                                 _______, _______, _______, _______,       _______, _______, _______, _______
                                 
    ),

    /* UMLT
     * ,-----------------------------------------.                                ,-----------------------------------------.
     * |      |      |      |      |      |      |                                |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
     * |      |      |      |   €  |      |      |                                |      |  Ü   |      |  Ö   |      |      |
     * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
     * |      |  Ä   |  SZ  |      |      |      |-------.                ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |                |       |------+------+------+------+------+------|
     * |      |      | SNAKE|      |      |      |-------|                |-------| SMILE|LAUGH | COOL | WINK |      |      |
     * `-----------------------------------------/       /                 \      \-----------------------------------------'
     *                   |      |      |      | / SPACE /                   \ ENTER\  |      |      |      |
     *                   |      |      |      |/       /                     \      \ |      |      |      |
     *                   `----------------------------'                       '------''--------------------'
     */
    [_UMLT] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, 
      _______, _______, _______, KC_EURO, _______, _______,                        _______, KC_UE,   _______, KC_OE,   _______, _______, 
      _______, KC_AE,   KC_SZ,   _______, _______, _______,                        _______, _______, _______, _______, _______, _______, 
      _______, _______, KC_SNK,  _______, _______, _______, _______,      _______, KC_SMLE, KC_LAGH, KC_COOL, KC_WINK, _______, _______, 
                                 _______, _______, _______, KC_SPC,       KC_ENT,  _______, _______, _______
                                 
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
