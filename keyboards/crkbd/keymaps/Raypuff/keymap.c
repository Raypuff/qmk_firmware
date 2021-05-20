#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
// Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _ALPHAS 0
#define _MISC 1
#define _CODING 2
#define _DIRECTIONAL 3
#define _FUNCTION 4

enum custom_keycodes { ALPHAS = SAFE_RANGE, MISC, CODING, DIRECTIONAL, FUNCTION, BACKLIT, RGBRST };

enum macro_keycodes {
    KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALPHAS] = LAYOUT(                                                                        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,           //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, MO(1), KC_SPC, KC_ENT, MO(2), MO(3)                                           //`--------------------------'  `--------------------------'

        ),

    [_MISC] = LAYOUT(                                                                                                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,                                     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_CAPS, XXXXXXX, XXXXXXX, LSFT(KC_TAB), XXXXXXX, XXXXXXX, KC_INS, KC_HOME, KC_PGUP, XXXXXXX, XXXXXXX,  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX, XXXXXXX, KC_LALT, KC_TAB, XXXXXXX, XXXXXXX, KC_DEL, KC_END, KC_PGDN, XXXXXXX, XXXXXXX,         //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, KC_TRNS, KC_SPC, KC_ENT, XXXXXXX, XXXXXXX                                                               //`--------------------------'  `--------------------------'
        ),

    [_CODING] = LAYOUT(                                                                                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, KC_GRV, KC_TILD, KC_LBRC, KC_RBRC, KC_COMM, KC_PPLS, KC_7, KC_8, KC_9, KC_PAST, KC_BSPC,   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_MINS, KC_EQL, KC_LPRN, KC_RPRN, KC_COLN, KC_PMNS, KC_4, KC_5, KC_6, KC_PSLS, KC_QUOT,  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSLS, KC_0, KC_1, KC_2, KC_3, KC_DOT, KC_DEL,      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+- -------+--------+--------+--------|
        XXXXXXX, MO(4), KC_SPC, KC_ENT, KC_TRNS, XXXXXXX                                                   //`--------------------------'  `--------------------------'
        ),

    [_DIRECTIONAL] = LAYOUT(                                                                                         //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, XXXXXXX, KC_SPC, KC_ENT, XXXXXXX, KC_TRNS                                                           //`--------------------------'  `--------------------------'
        ),

    [_FUNCTION] = LAYOUT(                                                                                    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET, XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, XXXXXXX, KC_SLEP, KC_BRID, KC_BRIU, KC_MPLY, KC_LALT, KC_F4, KC_F5, KC_F6, KC_F12, TG(6),   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MSTP, XXXXXXX, KC_F1, KC_F2, KC_F3, XXXXXXX, TG(5),  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_TRNS, KC_SPC, KC_ENT, XXXXXXX, XXXXXXX                                                   //`--------------------------'  `--------------------------'
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
// SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED
    iota_gfx_init(!has_usb());  // turns on the display
#endif
}

// SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) { iota_gfx_task(); }

void matrix_render_user(struct CharacterMatrix *matrix) {
    if (is_master) {
        // If you want to change the display of OLED, you need to change here
        matrix_write_ln(matrix, read_layer_state());
        matrix_write_ln(matrix, read_keylog());
        // matrix_write_ln(matrix, read_keylogs());
        // matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
        // matrix_write_ln(matrix, read_host_led_state());
        // matrix_write_ln(matrix, read_timelog());
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
#endif  // SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef SSD1306OLED
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }

    switch (keycode) {
        case ALPHAS:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL << _ALPHAS);
            }
            return false;
        case MISC:
            if (record->event.pressed) {
                layer_on(_MISC);
                update_tri_layer_RGB(_MISC, _CODING, _DIRECTIONAL);
            } else {
                layer_off(_MISC);
                update_tri_layer_RGB(_MISC, _CODING, _DIRECTIONAL);
            }
            return false;
        case CODING:
            if (record->event.pressed) {
                layer_on(_CODING);
                update_tri_layer_RGB(_MISC, _CODING, _DIRECTIONAL);
            } else {
                layer_off(_CODING);
                update_tri_layer_RGB(_MISC, _CODING, _DIRECTIONAL);
            }
            return false;
        case DIRECTIONAL:
            if (record->event.pressed) {
                layer_on(_DIRECTIONAL);
            } else {
                layer_off(_DIRECTIONAL);
            }
            return false;
        case FUNCTION:
            if (record->event.pressed) {
                layer_on(_FUNCTION);
            } else {
                layer_off(_FUNCTION);
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
