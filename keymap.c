#include QMK_KEYBOARD_H

void matrix_init_user(void) {
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

// Readable layer names
enum layers {
  _QWERTY, // Layer 0: Default
  _NUMBER, // Layer 1
  _SYMBOL, // Layer 2
  _CONFIG, // Layer 3
  _CURSOR, // Layer 4
  _GAME    // Layer 5
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUMBER,
  SYMBOL,
  CONFIG,
  CURSOR,
  GAME
};

// Declare tap dance sequences
enum {
  TD_ACTL,
  TD_CALT,
};

// Tap dance definition
tap_dance_action_t tap_dance_actions[] = {
  [TD_ACTL] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LCTL),
  [TD_CALT] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LALT),
};

// Configure home row mods
#define HM_A LT(3, KC_A)
#define HM_S MT(MOD_LCTL, KC_S)
#define HM_D MT(MOD_LALT, KC_D)
#define HM_F LT(2, KC_F)

#define HM_J    LT(2, KC_J)
#define HM_K    MT(MOD_RALT, KC_K)
#define HM_L    MT(MOD_RCTL, KC_L)
#define HM_SCLN LT(3, KC_SCLN)

// Modified keys
#define MO_Z    MT(MOD_LSFT, KC_Z)
#define MO_SLSH MT(MOD_RSFT, KC_SLSH)
#define MO_MUTE KC_MUTE
#define MO_VOLD KC_VOLD
#define MO_VOLU KC_VOLU
#define MO_LEFT LCTL(KC_LEFT)
#define MO_RGHT LCTL(KC_RIGHT)

// Thumb-key clusters
#define TH_SPC LT(1, KC_SPC)
#define TH_ALT TD(TD_ACTL)
#define TH_CTL TD(TD_CALT)
#define TH_LCA LCTL(KC_LALT)
#define TH_RCA RCTL(KC_RALT)
#define TH_GS  LGUI(KC_LSFT)
#define TH_GSC SGUI(KC_LCTL)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,--------------------------------------------.  Layer 0: Default  ,--------------------------------------------.
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         HM_A,    KC_S,    KC_D,    HM_F,    KC_G,                         KC_H,    HM_J,    KC_K,    KC_L, HM_SCLN,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         MO_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, MO_SLSH,\
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                           TH_ALT, KC_LGUI,     TH_SPC,  TH_CTL \
                                      //`-----------------'  `------------------'

  ),

  [_NUMBER] = LAYOUT( \
  //,--------------------------------------------.       Layer 1      ,--------------------------------------------.
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       KC_ESC,  KC_GRV, KC_BSPC,  KC_TAB, KC_CAPS,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,  KC_ENT,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT,   TG(4),   TG(3),   TG(2),   TG(5),                      XXXXXXX, XXXXXXX,  TH_ALT,  TH_CTL, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS \
                                      //`-----------------'  `------------------'
    ),

  [_SYMBOL] = LAYOUT( \
  //,--------------------------------------------.       Layer 2      ,--------------------------------------------.
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       KC_ESC,  KC_GRV, KC_BSPC,  KC_TAB, KC_CAPS,                      KC_LBRC, KC_MINS, KC_EQL,  KC_RBRC, KC_QUOT,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        TO(0), XXXXXXX, XXXXXXX, XXXXXXX, MO_LEFT,                      MO_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS,\
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_LSFT,   KC_RSFT, RCTL(KC_B) \
                                      //`-----------------'  `--------------------'
  ),

  [_CONFIG] = LAYOUT( \
  //,--------------------------------------------.       Layer 3      ,---------------------------------------------.
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------|
      XXXXXXX, MO_MUTE, MO_VOLD, MO_VOLU, XXXXXXX,                      XXXXXXX, KC_PGDN, KC_PGUP,  KC_F11,  KC_F12,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------|
        TO(0), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+---------|
                                          KC_LALT, KC_LSFT,   KC_LCTL, KC_RALT \
                                      //`-----------------'  `-----------------'
  ),

  [_CURSOR] = LAYOUT( \
  //,--------------------------------------------.       Layer 4      ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        TO(0), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                           TH_CTL, KC_LGUI,    KC_BTN1, KC_BTN2 \
                                      //`-----------------'  `------------------'
  ),

  [_GAME] = LAYOUT( \
  //,--------------------------------------------.       Layer 5      ,--------------------------------------------.
       KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,                          KC_H,    HM_J,    KC_K,    KC_L, KC_SCLN,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        TO(0),   KC_Z,    KC_X,    KC_C,    KC_V,                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,\
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                           KC_SPC,  TH_CTL,     TH_SPC,  TH_ALT \
                                      //`-----------------'  `------------------'
  )
};
// clang-format on

// Combo keys
#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_esc[]    = {KC_Q,    KC_W,     COMBO_END};
const uint16_t PROGMEM combo_tab[]    = {KC_W,    KC_E,     COMBO_END};
const uint16_t PROGMEM combo_del[]    = {KC_O,    KC_I,     COMBO_END};
const uint16_t PROGMEM combo_bspc[]   = {KC_P,    KC_O,     COMBO_END};
const uint16_t PROGMEM combo_lgsc[]   = {KC_GRV,  KC_BSPC,  COMBO_END};
const uint16_t PROGMEM combo_lgs[]    = {KC_BSPC, KC_TAB,   COMBO_END};
const uint16_t PROGMEM combo_rgsc[]   = {KC_UP,   KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo_rgs[]    = {KC_DOWN, KC_UP,    COMBO_END};
const uint16_t PROGMEM combo_ntab[]   = {KC_TAB,  KC_UP,    COMBO_END};
const uint16_t PROGMEM combo_ptab[]   = {KC_TAB,  KC_DOWN,  COMBO_END};

combo_t key_combos[] = {
  COMBO(combo_esc,    KC_ESC),
  COMBO(combo_tab,    KC_TAB),
  COMBO(combo_del,    KC_DEL),
  COMBO(combo_bspc,   KC_BSPC),
  COMBO(combo_lgsc,   TH_GSC),
  COMBO(combo_lgs,    TH_GS),
  COMBO(combo_rgsc,   TH_GSC),
  COMBO(combo_rgs,    TH_GS),
  COMBO(combo_ntab,   LCTL(KC_TAB)),
  COMBO(combo_ptab,   RCS(KC_TAB)),
};
#endif
