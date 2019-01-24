#ifndef _KSTROKE_H
#define _KSTROKE_H

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

extern int callGoPointer(uintptr_t ptr, uint8_t key, bool state);
int callback_kstroke_listen(uintptr_t cb);
typedef int (*kstroke_cb)(uintptr_t, uint8_t, bool);
int kstroke_listen(kstroke_cb cb, uintptr_t arg);

#define KSTROKE_KEY_SPACE 32
#define KSTROKE_KEY_0	48
#define KSTROKE_KEY_1	49
#define KSTROKE_KEY_2	50
#define KSTROKE_KEY_3	51
#define KSTROKE_KEY_4	52
#define KSTROKE_KEY_5	53
#define KSTROKE_KEY_6	54
#define KSTROKE_KEY_7	55
#define KSTROKE_KEY_8	56
#define KSTROKE_KEY_9	57
#define KSTROKE_KEY_BACKSPACE	8
#define KSTROKE_KEY_TAB	9
#define KSTROKE_KEY_ENTER	13
#define KSTROKE_KEY_SHIFT	16
#define KSTROKE_KEY_CTRL	17
#define KSTROKE_KEY_ALT	18
#define KSTROKE_KEY_PAUSE_BREAK	19
#define KSTROKE_KEY_CAPS_LOCK	20
#define KSTROKE_KEY_ESCAPE	27
#define KSTROKE_KEY_PAGE_UP	33
#define KSTROKE_KEY_PAGE_DOWN	34
#define KSTROKE_KEY_END	35
#define KSTROKE_KEY_HOME	36
#define KSTROKE_KEY_LEFT_ARROW	37
#define KSTROKE_KEY_UP_ARROW	38
#define KSTROKE_KEY_RIGHT_ARROW	39
#define KSTROKE_KEY_DOWN_ARROW	40
#define KSTROKE_KEY_INSERT	45
#define KSTROKE_KEY_DELETE	46
#define KSTROKE_KEY_A	65
#define KSTROKE_KEY_B	66
#define KSTROKE_KEY_C	67
#define KSTROKE_KEY_D	68
#define KSTROKE_KEY_E	69
#define KSTROKE_KEY_F	70
#define KSTROKE_KEY_G	71
#define KSTROKE_KEY_H	72
#define KSTROKE_KEY_I	73
#define KSTROKE_KEY_J	74
#define KSTROKE_KEY_K	75
#define KSTROKE_KEY_L	76
#define KSTROKE_KEY_M	77
#define KSTROKE_KEY_N	78
#define KSTROKE_KEY_O	79
#define KSTROKE_KEY_P	80
#define KSTROKE_KEY_Q	81
#define KSTROKE_KEY_R	82
#define KSTROKE_KEY_S	83
#define KSTROKE_KEY_T	84
#define KSTROKE_KEY_U	85
#define KSTROKE_KEY_V	86
#define KSTROKE_KEY_W	87
#define KSTROKE_KEY_X	88
#define KSTROKE_KEY_Y	89
#define KSTROKE_KEY_Z	90
#define KSTROKE_KEY_LEFT_WINDOW_KEY	91
#define KSTROKE_KEY_RIGHT_WINDOW_KEY	92
#define KSTROKE_KEY_SELECT_KEY	93
#define KSTROKE_KEY_NUMPAD_0	96
#define KSTROKE_KEY_NUMPAD_1	97
#define KSTROKE_KEY_NUMPAD_2	98
#define KSTROKE_KEY_NUMPAD_3	99
#define KSTROKE_KEY_NUMPAD_4	100
#define KSTROKE_KEY_NUMPAD_5	101
#define KSTROKE_KEY_NUMPAD_6	102
#define KSTROKE_KEY_NUMPAD_7	103
#define KSTROKE_KEY_NUMPAD_8	104
#define KSTROKE_KEY_NUMPAD_9	105
#define KSTROKE_KEY_NUMPAD_ENTER 13
#define KSTROKE_KEY_NUMPAD_SUBTRACT 109
#define KSTROKE_KEY_MULTIPLY	106
#define KSTROKE_KEY_ADD	107
#define KSTROKE_KEY_SUBTRACT 189
#define KSTROKE_KEY_DECIMAL_POINT	110
#define KSTROKE_KEY_DIVIDE	111
#define KSTROKE_KEY_F1	112
#define KSTROKE_KEY_F2	113
#define KSTROKE_KEY_F3	114
#define KSTROKE_KEY_F4	115
#define KSTROKE_KEY_F5	116
#define KSTROKE_KEY_F6	117
#define KSTROKE_KEY_F7	118
#define KSTROKE_KEY_F8	119
#define KSTROKE_KEY_F9	120
#define KSTROKE_KEY_F10	121
#define KSTROKE_KEY_F11	122
#define KSTROKE_KEY_F12	123
#define KSTROKE_KEY_F13	124
#define KSTROKE_KEY_F14	125
#define KSTROKE_KEY_F15	126
#define KSTROKE_KEY_F16	127
#define KSTROKE_KEY_F17	128
#define KSTROKE_KEY_F18	129
#define KSTROKE_KEY_F19	130
#define KSTROKE_KEY_F20	131
#define KSTROKE_KEY_F21	132
#define KSTROKE_KEY_F22	133
#define KSTROKE_KEY_F23	134
#define KSTROKE_KEY_F24	135

#define KSTROKE_KEY_NUM_LOCK	144
#define KSTROKE_KEY_SCROLL_LOCK	145
#define KSTROKE_KEY_VOLUME_MUTE 173
#define KSTROKE_KEY_VOLUME_DOWN 174
#define KSTROKE_KEY_VOLUME_UP 175
#define KSTROKE_KEY_SEMI_COLON	186
#define KSTROKE_KEY_EQUAL_SIGN	187
#define KSTROKE_KEY_COMMA	188
#define KSTROKE_KEY_DASH	189
#define KSTROKE_KEY_PERIOD	190
#define KSTROKE_KEY_FORWARD_SLASH	191
#define KSTROKE_KEY_GRAVE_ACCENT	192
#define KSTROKE_KEY_OPEN_BRACKET	219
#define KSTROKE_KEY_BACKSLASH	220
#define KSTROKE_KEY_CLOSEBRACKET	221
#define KSTROKE_KEY_SINGLE_QUOTE	222

#endif