package keystroke

type Key uint8

const (
	SPACE            Key = 32
	N0               Key = 48
	N1               Key = 49
	N2               Key = 50
	N3               Key = 51
	N4               Key = 52
	N5               Key = 53
	N6               Key = 54
	N7               Key = 55
	N8               Key = 56
	N9               Key = 57
	BACKSPACE        Key = 8
	TAB              Key = 9
	ENTER            Key = 13
	SHIFT            Key = 16
	CTRL             Key = 17
	ALT              Key = 18
	PAUSE_BREAK      Key = 19
	CAPS_LOCK        Key = 20
	ESCAPE           Key = 27
	PAGE_UP          Key = 33
	PAGE_DOWN        Key = 34
	END              Key = 35
	HOME             Key = 36
	LEFT_ARROW       Key = 37
	UP_ARROW         Key = 38
	RIGHT_ARROW      Key = 39
	DOWN_ARROW       Key = 40
	INSERT           Key = 45
	DELETE           Key = 46
	A                Key = 65
	B                Key = 66
	C                Key = 67
	D                Key = 68
	E                Key = 69
	F                Key = 70
	G                Key = 71
	H                Key = 72
	I                Key = 73
	J                Key = 74
	K                Key = 75
	L                Key = 76
	M                Key = 77
	N                Key = 78
	O                Key = 79
	P                Key = 80
	Q                Key = 81
	R                Key = 82
	S                Key = 83
	T                Key = 84
	U                Key = 85
	V                Key = 86
	W                Key = 87
	X                Key = 88
	Y                Key = 89
	Z                Key = 90
	LEFT_WINDOW_KEY  Key = 91
	RIGHT_WINDOW_KEY Key = 92
	SELECT_KEY       Key = 93
	NUMPAD_0         Key = 96
	NUMPAD_1         Key = 97
	NUMPAD_2         Key = 98
	NUMPAD_3         Key = 99
	NUMPAD_4         Key = 100
	NUMPAD_5         Key = 101
	NUMPAD_6         Key = 102
	NUMPAD_7         Key = 103
	NUMPAD_8         Key = 104
	NUMPAD_9         Key = 105
	NUMPAD_ENTER     Key = 13
	NUMPAD_SUBTRACT  Key = 109
	MULTIPLY         Key = 106
	ADD              Key = 107
	SUBTRACT         Key = 189
	DECIMAL_POINT    Key = 110
	DIVIDE           Key = 111
	F1               Key = 112
	F2               Key = 113
	F3               Key = 114
	F4               Key = 115
	F5               Key = 116
	F6               Key = 117
	F7               Key = 118
	F8               Key = 119
	F9               Key = 120
	F10              Key = 121
	F11              Key = 122
	F12              Key = 123
	F13              Key = 124
	F14              Key = 125
	F15              Key = 126
	F16              Key = 127
	F17              Key = 128
	F18              Key = 129
	F19              Key = 130
	F20              Key = 131
	F21              Key = 132
	F22              Key = 133
	F23              Key = 134
	F24              Key = 135
	NUM_LOCK         Key = 144
	SCROLL_LOCK      Key = 145
	VOLUME_MUTE      Key = 173
	VOLUME_DOWN      Key = 174
	VOLUME_UP        Key = 175
	SEMI_COLON       Key = 186
	EQUAL_SIGN       Key = 187
	COMMA            Key = 188
	DASH             Key = 189
	PERIOD           Key = 190
	FORWARD_SLASH    Key = 191
	GRAVE_ACCENT     Key = 192
	OPEN_BRACKET     Key = 219
	BACKSLASH        Key = 220
	CLOSEBRACKET     Key = 221
	SINGLE_QUOTE     Key = 222
)

var Lookup = map[string]Key{
	"Backspace":      8,
	"Tab":            9,
	"Enter":          13,
	"Shift":          16,
	"Ctrl":           17,
	"Alt":            18,
	"PauseBreak":     19,
	"CapsLock":       20,
	"Escape":         27,
	"Space":          32,
	"PageUp":         33,
	"PageDown":       34,
	"End":            35,
	"Home":           36,
	"LeftArrow":      37,
	"UpArrow":        38,
	"RightArrow":     39,
	"DownArrow":      40,
	"Insert":         45,
	"Delete":         46,
	"N0":             48,
	"N1":             49,
	"N2":             50,
	"N3":             51,
	"N4":             52,
	"N5":             53,
	"N6":             54,
	"N7":             55,
	"N8":             56,
	"N9":             57,
	"A":              65,
	"B":              66,
	"C":              67,
	"D":              68,
	"E":              69,
	"F":              70,
	"G":              71,
	"H":              72,
	"I":              73,
	"J":              74,
	"K":              75,
	"L":              76,
	"M":              77,
	"N":              78,
	"O":              79,
	"P":              80,
	"Q":              81,
	"R":              82,
	"S":              83,
	"T":              84,
	"U":              85,
	"V":              86,
	"W":              87,
	"X":              88,
	"Y":              89,
	"Z":              90,
	"LeftWindowKey":  91,
	"RightWindowKey": 92,
	"SelectKey":      93,
	"Numpad0":        96,
	"Numpad1":        97,
	"Numpad2":        98,
	"Numpad3":        99,
	"Numpad4":        100,
	"Numpad5":        101,
	"Numpad6":        102,
	"Numpad7":        103,
	"Numpad8":        104,
	"Numpad9":        105,
	"Multiply":       106,
	"Add":            107,
	"NumpadSubtract": 109,
	"DecimalPoint":   110,
	"Divide":         111,
	"F1":             112,
	"F2":             113,
	"F3":             114,
	"F4":             115,
	"F5":             116,
	"F6":             117,
	"F7":             118,
	"F8":             119,
	"F9":             120,
	"F10":            121,
	"F11":            122,
	"F12":            123,
	"F13":            124,
	"F14":            125,
	"F15":            126,
	"F16":            127,
	"F17":            128,
	"F18":            129,
	"F19":            130,
	"F20":            131,
	"F21":            132,
	"F22":            133,
	"F23":            134,
	"F24":            135,
	"NumLock":        144,
	"ScrollLock":     145,
	"VolumeMute":     173,
	"VolumeDown":     174,
	"VolumeUp":       175,
	"SemiColon":      186,
	"EqualSign":      187,
	"Comma":          188,
	"Subtract":       189,
	"Period":         190,
	"ForwardSlash":   191,
	"GraveAccent":    192,
	"OpenBracket":    219,
	"Backslash":      220,
	"Closebracket":   221,
	"SingleQuote":    222,
}
