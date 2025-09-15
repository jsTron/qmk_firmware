/*
Copyright 2018 Mattia Dal Ben <matthewdibi@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
   _COLEMAK,
   _QWERTY,
   _COLEDN,
   _COLEUP,
   _NAV,
   _ADJUST
};

// Temporary Layer Shifts
#define NAV_L   MO(_NAV)
#define ADJ_L   MO(_ADJUST)

// Base Layer Move
#define QWRT_L DF(_QWERTY)
#define COLE_L DF(_COLEMAK)

// Long-tap Shifts
#define DEL_DN LT(_COLEDN, KC_DEL)
#define ENT_UP LT(_COLEUP, KC_ENT)

// MOD-tap Colemak Layout
#define MT_A MT(MOD_LGUI, KC_A)
#define MT_R MT(MOD_LALT, KC_R)
#define MT_S MT(MOD_LCTL, KC_S)
#define MT_T MT(MOD_LSFT, KC_T)
#define MT_N MT(MOD_RSFT, KC_N)
#define MT_E MT(MOD_RCTL, KC_E)
#define MT_I MT(MOD_RALT, KC_I)
#define MT_O MT(MOD_RGUI, KC_O)

// MOD-tap QWERTY Layout
#define MT_QA MT(MOD_LGUI, KC_A)
#define MT_QS MT(MOD_LALT, KC_S)
#define MT_QD MT(MOD_LCTL, KC_D)
#define MT_QF MT(MOD_LSFT, KC_F)
#define MT_QJ MT(MOD_RSFT, KC_J)
#define MT_QK MT(MOD_RCTL, KC_K)
#define MT_QL MT(MOD_RALT, KC_L)
#define MT_QSC MT(MOD_RGUI, KC_SCLN)

// MOD-tap COLEDN Layout
#define MT_D1 MT(MOD_LGUI, KC_1)
#define MT_D2 MT(MOD_LALT, KC_2)
#define MT_D3 MT(MOD_LCTL, KC_3)
#define MT_D4 MT(MOD_LSFT, KC_4)
#define MT_D7 MT(MOD_RSFT, KC_7)
#define MT_D8 MT(MOD_RCTL, KC_8)
#define MT_D9 MT(MOD_RALT, KC_9)
#define MT_D0 MT(MOD_RGUI, KC_0)

// MOD-tap COLEUP Layout
#define MT_UHM MT(MOD_LGUI, KC_HOME)
#define MT_UEN MT(MOD_LALT, KC_END)
#define MT_U3 MT(MOD_LCTL, KC_NO)
#define MT_UIN MT(MOD_LSFT, KC_INS)
#define MT_UDN MT(MOD_RSFT, KC_DOWN)
#define MT_UUP MT(MOD_RCTL, KC_UP)
#define MT_URT MT(MOD_RALT, KC_RIGHT)
#define MT_UAP MT(MOD_RGUI, KC_APP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_G    ,XXXXXXX ,                          XXXXXXX ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,MT_A    ,MT_R    ,MT_S    ,MT_T    ,KC_D    ,XXXXXXX ,                          XXXXXXX ,KC_H    ,MT_N    ,MT_E    ,MT_I    ,MT_O    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,KC_K    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,ADJ_L   ,     KC_BSPC ,    DEL_DN  ,XXXXXXX ,        XXXXXXX ,ENT_UP  ,    KC_SPC  ,     NAV_L   ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,XXXXXXX ,                          XXXXXXX ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,MT_QA   ,MT_QS   ,MT_QD   ,MT_QF   ,KC_G    ,XXXXXXX ,                          XXXXXXX ,KC_H    ,MT_QJ   ,MT_QK   ,MT_QL   ,MT_QSC  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,ADJ_L   ,     KC_BSPC ,    DEL_DN  ,XXXXXXX ,        XXXXXXX ,ENT_UP  ,    KC_SPC  ,     NAV_L   ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_COLEDN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,XXXXXXX ,                          XXXXXXX ,KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,MT_D1   ,MT_D2   ,MT_D3   ,MT_D4   ,KC_5    ,XXXXXXX ,                          XXXXXXX ,KC_6    ,MT_D7   ,MT_D8   ,MT_D9   ,MT_D0   ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_ESC  ,KC_TILD ,KC_GRV  ,KC_LBRC ,KC_LCBR ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,KC_RCBR ,KC_RBRC ,KC_QUOT ,KC_MINS ,KC_EQL  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,     KC_BSPC ,    DEL_DN  ,XXXXXXX ,        XXXXXXX ,ENT_UP  ,    KC_SPC  ,     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_COLEUP] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,XXXXXXX ,                          XXXXXXX ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,MT_UHM  ,MT_UEN  ,MT_U3   ,MT_UIN  ,KC_PGUP ,XXXXXXX ,                          XXXXXXX ,KC_LEFT ,MT_UDN  ,MT_UUP  ,MT_URT  ,MT_UAP  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_F11  ,KC_F12  ,XXXXXXX ,KC_DEL  ,KC_PGDN ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,KC_PIPE ,KC_BSLS ,KC_VOLD ,KC_VOLU ,KC_MUTE ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,     KC_BSPC ,    DEL_DN  ,XXXXXXX ,        XXXXXXX ,ENT_UP  ,    KC_SPC  ,     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,MS_WHLD ,MS_UP   ,MS_WHLU ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,MS_LEFT ,MS_DOWN ,MS_RGHT ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,     MS_BTN1 ,    MS_BTN2 ,XXXXXXX ,        XXXXXXX ,_______ ,    _______ ,     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,QK_BOOT ,RGB_M_P ,UG_TOGG ,UG_NEXT ,UG_HUED ,UG_HUEU ,                          UG_SATD ,UG_SATU ,UG_VALD ,UG_VALU ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,QK_RBT  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,COLE_L  ,QWRT_L  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,     _______ ,    _______ ,XXXXXXX ,        XXXXXXX ,_______ ,    _______ ,     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};
