#include "keymap_common.h"


const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    [0] = KEYMAP_ALL(
              F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, F24,
    ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,           PSCR,SLCK,PAUS,    VOLD,VOLU,MUTE,PWR,     HELP,
    GRV, 1,   2,   3,   4,   5,   6,   EQL, 7,   8,   9,   0,   MINS, JYEN,RCTL,     INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,    STOP,AGIN,
    TAB, Q,   W,   F,   P,   B,   LBRC,   J,   L,   U,   Y,   SCLN,QUOT,     BSLS,     DEL, END, PGDN,    P7,  P8,  P9,  PPLS,    MENU,UNDO,
    FN0, A,   R,   S,   T,   G,   RBRC,   K,   N,   E,   I, O,     NUHS,LCTL,                         P4,  P5,  P6,  PCMM,    SLCT,COPY,
    LSFT,TRNS,X,   C,   D,   V,   Z,   SLSH,   M,   H,COMM, DOT,     TRNS,  RSFT,          UP,           P1,  P2,  P3,  PEQL,    EXEC,PSTE,
    FN0,LGUI,LALT,MHEN,HANJ,     SPC,      HAEN,HENK,KANA,LGUI,RGUI,FN0, RCTL,     LEFT,DOWN,RGHT,    P0,       PDOT,PENT,    FIND,CUT
    ),
    [1] = KEYMAP_ALL(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    CAPS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,    TRNS,
    TRNS, F1,  F2,  F3,  F4,  F5,  F6,  F12,  F7,  F8,  F9,  F10, F11,INS,PSCR,      TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,
    TRNS,ESC,WH_U,BTN4, BTN5,MS_U,ESC,PGUP,HOME,  UP, END,DEL,BTN2,     PSCR,      TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,
    TRNS,LALT,WH_D,LSFT,LCTL,MS_D,BTN3,PGDOWN,LEFT,DOWN,RIGHT,BSPC,     TRNS,FN1,                        TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,
    TRNS,TRNS,FN2,FN3,BTN1,FN4,FN5, WH_L,WH_R, MS_L, MS_R,ACL2,      TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,ENT,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,     TRNS,TRNS,    TRNS,TRNS
    ),
    [2] = KEYMAP_ALL(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,    TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  P7,  P8,  P9, PAST, PMNS, TRNS,TRNS,      TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,
    TRNS,WHOM,VOLU,MPRV,MNXT,BRTI,INS,PAUS,P4,  P5, P6,PPLS,PSLS,     TRNS,      TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,
    TRNS,MUTE,VOLD,MSTP,MPLY,BRTD,SLCK,NLCK,P1,P2,P3,PENT,     TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, P0, PEQL,PDOT,      TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,    TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,     MENU,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,     TRNS,TRNS,    TRNS,TRNS
    )
};


enum macro_id {
    MCUT,
    MCOPY,
    MPASTE,
    MUNDO,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case MCUT:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(X), END ) :
                    MACRO(U(X), U(LCTL), END));
        case MCOPY:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(C), END ) :
                    MACRO(U(C), U(LCTL), END));
        case MPASTE:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(V), END ) :
                    MACRO(U(V), U(LCTL), END));
        case MUNDO:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(Z), END ) :
                    MACRO(U(Z), U(LCTL), END));
    }
    return MACRO_NONE;
}


const action_t fn_actions[] PROGMEM = {
    [0] = ACTION_LAYER_TAP_KEY(1, KC_LCTRL),
    [1] = ACTION_LAYER_TAP_KEY(2, KC_ENTER),
    [2] = ACTION_MACRO(MCUT),
    [3] = ACTION_MACRO(MCOPY),
    [4] = ACTION_MACRO(MPASTE),
    [5] = ACTION_MACRO(MUNDO),
};