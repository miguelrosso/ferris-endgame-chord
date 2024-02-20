#include QMK_KEYBOARD_H

#define ___ KC_TRNS
#define KC_A_HRM MT(MOD_LGUI,KC_A)
#define KC_S_HRM MT(MOD_LALT,KC_S)
#define KC_D_HRM MT(MOD_LSFT,KC_D)
#define KC_F_HRM MT(MOD_LCTL,KC_F)
#define KC_G_HRM LT(1,KC_G)
#define KC_H_HRM LT(1,KC_H)
#define KC_J_HRM MT(MOD_LCTL | MOD_RCTL,KC_J)
#define KC_K_HRM MT(MOD_LSFT | MOD_RSFT,KC_K)
#define KC_L_HRM MT(MOD_LALT,KC_L)
#define KC_P_HRM MT(MOD_LGUI | MOD_RGUI,KC_P)
#define KC_Z_HRM MT(MOD_LCTL,KC_Z)
#define KC_SLSH_HRM MT(MOD_LCTL,KC_SLSH)
#define KC_SPC_HRM MT(MOD_LSFT,KC_SPC)

bool bCamelCaseMode = false;
int16_t LastOutputChord = 0;

#define DEFINE_ALL_CHORDS \
    DEFINE_CHORD(CHORD_YES, "yes", KC_Y, KC_S_HRM)   CSEP\
    DEFINE_CHORD(CHORD_NO, "no", KC_N, KC_SPC_HRM)   CSEP\
    DEFINE_CHORD(CHORD_VERY, "very", KC_V, KC_Y) CSEP\
    DEFINE_CHORD(CHORD_MUCH, "much", KC_M, KC_C) CSEP\
    DEFINE_CHORD(CHORD_THE, "the", KC_T, KC_H_HRM) CSEP\
    DEFINE_CHORD(CHORD_TO, "to", KC_T, KC_O) CSEP\
    DEFINE_CHORD(CHORD_OF, "of", KC_O, KC_F_HRM) CSEP\
    DEFINE_CHORD(CHORD_INSTEAD, "instead", KC_N, KC_S_HRM, KC_T_HRM) CSEP\
    DEFINE_CHORD(CHORD_TOO, "too", KC_T, KC_I, KC_O) CSEP\
    DEFINE_CHORD(CHORD_AND, "and", KC_N, KC_D_HRM) CSEP\
    DEFINE_CHORD(CHORD_OR, "or", KC_O, KC_R) CSEP\
    DEFINE_CHORD(CHORD_AN, "an", KC_A_HRM, KC_N) CSEP\
    DEFINE_CHORD(CHORD_FROM, "from", KC_F_HRM, KC_M) CSEP\
    DEFINE_CHORD(CHORD_A, "a", KC_A_HRM, KC_J_HRM) CSEP\
    DEFINE_CHORD(CHORD_IN, "in", KC_I, KC_N) CSEP\
    DEFINE_CHORD(CHORD_OUT, "out", KC_O, KC_U, KC_T) CSEP\
    DEFINE_CHORD(CHORD_OVER, "over", KC_O, KC_V) CSEP\
    DEFINE_CHORD(CHORD_UNDER, "under", KC_N, KC_D_HRM, KC_R) CSEP\
    DEFINE_CHORD(CHORD_INTO, "into", KC_I, KC_T, KC_O) CSEP\
    DEFINE_CHORD(CHORD_THAT, "that", KC_T, KC_H_HRM, KC_A_HRM) CSEP\
    DEFINE_CHORD(CHORD_THERE, "there", KC_T, KC_H_HRM, KC_R) CSEP\
    DEFINE_CHORD(CHORD_HERE, "here", KC_H_HRM, KC_R) CSEP\
    DEFINE_CHORD(CHORD_HAVE, "have", KC_H_HRM, KC_A_HRM, KC_V) CSEP\
    DEFINE_CHORD(CHORD_I, "I", KC_I, KC_SPC_HRM) CSEP\
    DEFINE_CHORD(CHORD_IM, "I'm", KC_I, KC_M) CSEP\
    DEFINE_CHORD(CHORD_IT, "it", KC_I, KC_T) CSEP\
    DEFINE_CHORD(CHORD_IS, "is", KC_I, KC_S_HRM) CSEP\
    DEFINE_CHORD(CHORD_FOR, "for", KC_F_HRM, KC_SPC_HRM) CSEP\
    DEFINE_CHORD(CHORD_NOT, "not", KC_N, KC_T) CSEP\
    DEFINE_CHORD(CHORD_ON, "on", KC_O, KC_N) CSEP\
    DEFINE_CHORD(CHORD_MOST, "most", KC_M, KC_S_HRM, KC_T) CSEP\
    DEFINE_CHORD(CHORD_WITH, "with", KC_W, KC_I) CSEP\
    DEFINE_CHORD(CHORD_WITHOUT, "without", KC_W, KC_O) CSEP\
    DEFINE_CHORD(CHORD_HE, "he", KC_H_HRM, KC_E) CSEP\
    DEFINE_CHORD(CHORD_HIS, "his", KC_H_HRM, KC_I, KC_S_HRM) CSEP\
    DEFINE_CHORD(CHORD_HIM, "him", KC_H_HRM, KC_M) CSEP\
    DEFINE_CHORD(CHORD_SHE, "she", KC_S_HRM, KC_E) CSEP\
    DEFINE_CHORD(CHORD_HER, "her", KC_H_HRM, KC_E, KC_R) CSEP\
    DEFINE_CHORD(CHORD_THEY, "they", KC_D_HRM, KC_Y) CSEP\
    DEFINE_CHORD(CHORD_THEM, "them", KC_D_HRM, KC_M) CSEP\
    DEFINE_CHORD(CHORD_THEIR, "their", KC_D_HRM, KC_Y, KC_R) CSEP\
    DEFINE_CHORD(CHORD_ME, "me", KC_M, KC_E) CSEP\
    DEFINE_CHORD(CHORD_MY, "my", KC_M, KC_R) CSEP\
    DEFINE_CHORD(CHORD_WE, "we", KC_W, KC_E) CSEP\
    DEFINE_CHORD(CHORD_US, "us", KC_U, KC_S_HRM) CSEP\
    DEFINE_CHORD(CHORD_ITS, "its", KC_I, KC_T, KC_S_HRM) CSEP\
    DEFINE_CHORD(CHORD_OTHER, "other", KC_O, KC_D_HRM, KC_R) CSEP\
    DEFINE_CHORD(CHORD_THAN, "than", KC_D_HRM, KC_A_HRM, KC_N) CSEP\
    DEFINE_CHORD(CHORD_THEN, "then", KC_D_HRM, KC_E, KC_N) CSEP\
    DEFINE_CHORD(CHORD_WHO, "who", KC_W, KC_H_HRM) CSEP\
    DEFINE_CHORD(CHORD_WHY, "why", KC_W, KC_Y) CSEP\
    DEFINE_CHORD(CHORD_HOW, "how", KC_H_HRM, KC_O, KC_W) CSEP\
    DEFINE_CHORD(CHORD_WHEN, "when", KC_W, KC_E, KC_H_HRM) CSEP\
    DEFINE_CHORD(CHORD_WHICH, "which", KC_W, KC_H_HRM, KC_I) CSEP\
    DEFINE_CHORD(CHORD_AS, "as", KC_A_HRM, KC_S_HRM) CSEP\
    DEFINE_CHORD(CHORD_YOU, "you", KC_Y, KC_U) CSEP\
    DEFINE_CHORD(CHORD_YOUR, "your", KC_Y, KC_U, KC_R) CSEP\
    DEFINE_CHORD(CHORD_AT, "at", KC_A_HRM, KC_T) CSEP\
    DEFINE_CHORD(CHORD_CHORD, "chord", KC_K_HRM, KC_O, KC_R, KC_D_HRM) CSEP\
    DEFINE_CHORD(CHORD_ABOUT, "about", KC_A_HRM, KC_B) CSEP\
    DEFINE_CHORD(CHORD_ASK, "ask", KC_A_HRM, KC_S_HRM, KC_K_HRM) CSEP\
    DEFINE_CHORD(CHORD_BE, "be", KC_B, KC_J_HRM) CSEP\
    DEFINE_CHORD(CHORD_BECOME, "become", KC_B, KC_M) CSEP\
    DEFINE_CHORD(CHORD_BEGIN, "begin", KC_B, KC_N) CSEP\
    DEFINE_CHORD(CHORD_CALL, "call", KC_C, KC_A_HRM, KC_L_HRM) CSEP\
    DEFINE_CHORD(CHORD_CAN, "can", KC_C, KC_A_HRM, KC_N) CSEP\
    DEFINE_CHORD(CHORD_COME, "come", KC_C, KC_O, KC_M) CSEP\
    DEFINE_CHORD(CHORD_COULD, "could", KC_C, KC_O, KC_U) CSEP\
    DEFINE_CHORD(CHORD_DO, "do", KC_D_HRM, KC_O) CSEP\
    DEFINE_CHORD(CHORD_FEEL, "feel", KC_F_HRM, KC_E, KC_L_HRM) CSEP\
    DEFINE_CHORD(CHORD_GET, "get", KC_G_HRM, KC_E) CSEP\
    DEFINE_CHORD(CHORD_THIS, "this", KC_D_HRM, KC_I, KC_S_HRM) CSEP\
    DEFINE_CHORD(CHORD_BUT, "but", KC_B, KC_U) CSEP\
    DEFINE_CHORD(CHORD_BY, "by", KC_B, KC_Y) CSEP\
    DEFINE_CHORD(CHORD_SAY, "say", KC_S_HRM, KC_A_HRM, KC_Y) CSEP\
    DEFINE_CHORD(CHORD_WILL, "will", KC_W, KC_I, KC_L_HRM) CSEP\
    DEFINE_CHORD(CHORD_WOULD, "would", KC_W, KC_U, KC_L_HRM) CSEP\
    DEFINE_CHORD(CHORD_GO, "go", KC_G_HRM, KC_O) CSEP\
    DEFINE_CHORD(CHORD_MAKE, "make", KC_M, KC_A_HRM, KC_K_HRM) CSEP\
    DEFINE_CHORD(CHORD_SO, "so", KC_S_HRM, KC_O) CSEP\
    DEFINE_CHORD(CHORD_UP, "up", KC_U, KC_P_HRM) CSEP\
    DEFINE_CHORD(CHORD_LIKE, "like", KC_L_HRM, KC_K_HRM, KC_E) CSEP\
    DEFINE_CHORD(CHORD_TIME, "time", KC_T, KC_M) CSEP\
    DEFINE_CHORD(CHORD_JUST, "just", KC_J_HRM, KC_S_HRM) CSEP\
    DEFINE_CHORD(CHORD_KNOW, "know", KC_K_HRM, KC_W) CSEP\
    DEFINE_CHORD(CHORD_DAY, "day", KC_D_HRM, KC_A_HRM, KC_Y) CSEP\
    DEFINE_CHORD(CHORD_NIGHT, "night", KC_N, KC_I, KC_G_HRM) CSEP\
    DEFINE_CHORD(CHORD_TONIGHT, "tonight", KC_N, KC_O, KC_G_HRM) CSEP\
    DEFINE_CHORD(CHORD_NOW, "now", KC_N, KC_W) CSEP\
    DEFINE_CHORD(CHORD_BEFORE, "before", KC_B, KC_F_HRM) CSEP\
    DEFINE_CHORD(CHORD_AFTER, "after", KC_A_HRM, KC_F_HRM) CSEP\
    DEFINE_CHORD(CHORD_THINK, "think", KC_T, KC_N, KC_K_HRM) CSEP\
    DEFINE_CHORD(CHORD_ALSO, "also", KC_A_HRM, KC_O) CSEP\
    DEFINE_CHORD(CHORD_TAKE, "take", KC_T, KC_K_HRM) CSEP\
    DEFINE_CHORD(CHORD_GIVE, "give", KC_G_HRM, KC_I, KC_V) CSEP\
    DEFINE_CHORD(CHORD_SECOND, "second", KC_S_HRM, KC_N, KC_D_HRM) CSEP\
    DEFINE_CHORD(CHORD_MINUTE, "minute", KC_M, KC_N, KC_T) CSEP\
    DEFINE_CHORD(CHORD_HOUR, "hour", KC_H_HRM, KC_U, KC_R) CSEP\
    DEFINE_CHORD(CHORD_PEOPLE, "people", KC_P_HRM, KC_E, KC_L_HRM) CSEP\
    DEFINE_CHORD(CHORD_GOOD, "good", KC_G_HRM, KC_U, KC_D_HRM) CSEP\
    DEFINE_CHORD(CHORD_BAD, "bad", KC_B, KC_D_HRM) CSEP\
    DEFINE_CHORD(CHORD_SOME, "some", KC_S_HRM, KC_O, KC_M) CSEP\
    DEFINE_CHORD(CHORD_HELLO, "hello", KC_H_HRM, KC_E, KC_O) CSEP\
    DEFINE_CHORD(CHORD_WORLD, "world", KC_W, KC_O, KC_D_HRM) CSEP\
    DEFINE_CHORD(CHORD_REALLY, "really", KC_R, KC_L_HRM, KC_Y) CSEP\
    DEFINE_CHORD(CHORD_IF, "if", KC_I, KC_F_HRM) CSEP\
    DEFINE_CHORD(CHORD_NEW, "new", KC_N, KC_E, KC_W) CSEP\
    DEFINE_CHORD(CHORD_VOID, "void", KC_V, KC_D_HRM) CSEP\
    DEFINE_CHORD(CHORD_INT, "int", KC_I, KC_N, KC_T) CSEP\
    DEFINE_CHORD(CHORD_BOOL, "bool", KC_B, KC_L_HRM) CSEP\
    DEFINE_CHORD(CHORD_CHAR, "char", KC_K_HRM, KC_A_HRM, KC_R) CSEP\
    DEFINE_CHORD(CHORD_CONST, "const", KC_K_HRM, KC_N, KC_S_HRM, KC_T) CSEP\
    DEFINE_CHORD(CHORD_RETURN, "return", KC_R, KC_T, KC_U) CSEP\
    DEFINE_CHORD(CHORD_SWITCH, "switch", KC_W, KC_I, KC_T) CSEP\
    DEFINE_CHORD(CHORD_REFLECTION, "reflection", KC_R, KC_F_HRM, KC_N) CSEP\
    DEFINE_CHORD(CHORD_NAME, "name", KC_N, KC_A_HRM, KC_M) CSEP\
    DEFINE_CHORD(CHORD_MROSSO, "Miguel Rosso", KC_M, KC_R, KC_SPC_HRM) CSEP\
    DEFINE_CHORD(CHORD_YVMWEB, "yesverymu.ch", KC_W, KC_V, KC_Y) CSEP\
    DEFINE_CHORD(CHORD_VYCPP, "vy::", KC_V, KC_Y, KC_SCLN) CSEP\
    DEFINE_CHORD(CHORD_NT, SS_TAP(X_BSPC) "n't", KC_T, KC_SCLN) CSEP\
    DEFINE_CHORD(CHORD_ED, SS_TAP(X_BSPC) "ed", KC_D_HRM, KC_SCLN) CSEP\
    DEFINE_CHORD(CHORD_RE, SS_TAP(X_BSPC) "'re", KC_R, KC_SCLN) CSEP\
    DEFINE_CHORD(CHORD_ING, SS_TAP(X_BSPC) "ing", KC_G_HRM, KC_SCLN) CSEP\
    DEFINE_CHORD(CHORD_PLURAL, SS_TAP(X_BSPC) "s", KC_S_HRM, KC_SCLN) CSEP\
    DEFINE_CHORD(CHORD_APOS, SS_TAP(X_BSPC) "'s", KC_X, KC_SCLN) CSEP\
    DEFINE_CHORD(CHORD_DEREF, SS_TAP(X_BSPC) "->", KC_D_HRM, KC_F_HRM, KC_SCLN)

enum endgame_layers
{
    L_MAIN,
    L_SYMBOLS,
    L_FUNCTION,
    L_JUMPS,
    L_CHORD
};

/**
 * Define custom keycodes, including one keycode for each chord
 */
#define CSEP ,
#define DEFINE_CHORD(chordname, ...) chordname
enum custom_keycodes
{
    TOGGLE_COMBOS = SAFE_RANGE,
    TOGGLE_CAMELCASE,
    BASE_CHORD_RANGE = TOGGLE_CAMELCASE,

    DEFINE_ALL_CHORDS

};
#undef DEFINE_CHORD
#undef CSEP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [L_MAIN] = LAYOUT_split_3x5_2(
                // row 0
                KC_Q, KC_W, KC_E, KC_R, KC_T,    // left
                KC_Y, KC_U, KC_I, KC_O, KC_SCLN, // right

                //row 2
                KC_A_HRM, KC_S_HRM, KC_D_HRM, KC_F_HRM, KC_G_HRM,   // left
                KC_H_HRM, KC_J_HRM, KC_K_HRM, KC_L_HRM, KC_P_HRM, // right

                // row 2
                KC_Z_HRM, KC_X, KC_C, KC_V, KC_B,         // left
                KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH_HRM, // right

                // thumbs
                KC_SPC_HRM, LT(2,KC_BSPC), // left
                MO(1), LT(3,KC_ENT)                 // right
            ),

        [L_SYMBOLS] = LAYOUT_split_3x5_2(
                S(KC_1), S(KC_2), S(KC_LBRC), S(KC_RBRC), S(KC_BSLS),
                KC_EQL, KC_7, KC_8, KC_9, S(KC_8),

                KC_ESC, KC_QUOT, S(KC_9), S(KC_0), S(KC_QUOT),
                KC_MINS, KC_4, KC_5, KC_6, KC_PPLS,

                S(KC_5), S(KC_3), KC_LBRC, KC_RBRC, S(KC_GRV),
                S(KC_7), KC_1, KC_2, KC_3, KC_BSLS,

                KC_TRNS, KC_TRNS,
                KC_TRNS, KC_0
            ),

        [L_FUNCTION] = LAYOUT_split_3x5_2(
                KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
                KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,

                KC_TAB, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS,
                KC_F11, KC_F12, S(KC_F11), KC_RBRC, S(KC_BSLS),

                A(KC_F4), KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS,
                S(KC_MINS), S(KC_EQL), KC_F11, KC_F10, KC_GRV,

                KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS
            ),
        [L_JUMPS] = LAYOUT_split_3x5_2(
                KC_TAB, KC_MS_WH_DOWN, KC_MS_UP, KC_MS_WH_UP, KC_TRNS,
                C(G(KC_LEFT)), C(KC_LEFT), KC_UP, C(KC_RGHT), C(G(KC_RGHT)),

                KC_DEL, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_LGUI,
                KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,

                C(KC_TAB), KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_BTN2,
                KC_CAPS, S(KC_TAB), KC_TAB, KC_LALT, LSG(KC_S),

                TOGGLE_CAMELCASE, KC_MS_BTN1,
                TOGGLE_COMBOS, KC_TRNS
            ),

        [L_CHORD] = LAYOUT_split_3x5_2(
                ___, ___, ___, ___, ___,
                ___, ___, ___, ___, ___,

                ___, ___, ___, ___, ___,
                ___, ___, ___, ___, ___,

                ___, ___, ___, ___, ___,
                ___, ___, ___, ___, ___,

                ___, ___,
                ___, ___
            )
};

/**
 * Define all chord key sequences
 */
#define CSEP ;
#define DEFINE_CHORD(chord_keycode, chord_str, ...) \
    const uint16_t PROGMEM combo##chord_keycode [] = { __VA_ARGS__, COMBO_END };
DEFINE_ALL_CHORDS;
#undef DEFINE_CHORD
#undef CSEP

/**
 * Define all actual combos, pairing chord key sequences to the appropriate chord keycode
 */
#define CSEP ,
#define DEFINE_CHORD(chord_keycode, chord_str, ...) \
    COMBO(combo##chord_keycode, chord_keycode)
combo_t key_combos[] =
{
    DEFINE_ALL_CHORDS
};
#undef DEFINE_CHORD
#undef CSEP

void SendChord(char* Output, int16_t Keycode)
{
    char* output = Output;
    if (bCamelCaseMode &&
        strlen(output) > 1)
    {
        char  FirstLetter[2] = { *(output++), '\0' };
        if ((*output) != *SS_TAP(X_BSPC))
        {
            register_code(KC_LSFT);
            send_string(FirstLetter);
            unregister_code(KC_LSFT);
        }
    }
    // TODO:  handle 'a' (single letter) case
    send_string(output+0);
};

/**
 * Switch on every chord keycode and output the correct string
 */
#define CSEP
#define DEFINE_CHORD(chord_keycode, chord_str, ...) \
    case chord_keycode: { \
        if (record->event.pressed) { \
            SendChord(chord_str, chord_keycode); \
        } \
        break; \
    }

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
    switch(keycode)
    {
        case TOGGLE_COMBOS:
            if (record->event.pressed)
            {
                combo_toggle();
            }
            return false;

        case TOGGLE_CAMELCASE:
            if (record->event.pressed)
            {
                bCamelCaseMode = !bCamelCaseMode;
            }
            return false;

        DEFINE_ALL_CHORDS

    }

    if (record->event.pressed &&
        keycode > BASE_CHORD_RANGE)
    {
        if (!bCamelCaseMode)
        {
            tap_code(KC_SPC);
        }
        LastOutputChord = keycode;
        return false;
    }

    return true;
};
#undef DEFINE_CHORD
#undef CSEP


#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE
