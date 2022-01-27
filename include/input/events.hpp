#pragma once

enum KEY_CODE {
    UNKNOWN,
	KB_F1,
	KB_F2,
	KB_F3,
	KB_F4,
	KB_F5,
	KB_F6,
	KB_F7,
	KB_F8,
	KB_F9,
	KB_F10,
	KB_F11,
	KB_F12,

    KB_0,
    KB_1,
    KB_2,
    KB_3,
    KB_4,
    KB_5,
    KB_6,
    KB_7,
    KB_8,
    KB_9,
    
    KB_A,
    KB_B,
    KB_C,
    KB_D,
    KB_E,
    KB_F,
    KB_G,
    KB_H,
    KB_I,
    KB_J,
    KB_K,
    KB_L,
    KB_M,
    KB_N,
    KB_O,
    KB_P,
    KB_Q,
    KB_R,
    KB_S,
    KB_T,
    KB_U,
    KB_V,
    KB_W,
    KB_X,
    KB_Y,
    KB_Z,

    KB_ESC,
    KB_TAB,
    KB_CAPS,
    KB_LEFT_SHIFT,
    KB_RIGHT_SHIFT,
    KB_LEFT_CONTROL,
    KB_RIGHT_CONTROL,
    KB_LEFT_ALT,
    KB_RIGHT_ALT,
    KB_SPACE,
    KB_ENTER,

    KB_LEFT_ARROW,
    KB_RIGHT_ARROW,
    KB_UP_ARROW,
    KB_DOWN_ARROW,
};

enum EVT_TYPE {
    KEY_PRESSED,
    KEY_RELEASED,

    WINDOW
};

struct Event {
    EVT_TYPE type;
    KEY_CODE key_code;
};