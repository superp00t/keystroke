#include "kstroke.h"
#define KSTROKE_KEYSPACE 230

int callback_kstroke_listen(uintptr_t cb)
{
	return kstroke_listen(callGoPointer, cb);
}

#ifdef _WIN32
#include <windows.h>

int kstroke_listen(kstroke_cb cb, uintptr_t arg)
{
  uint8_t state[KSTROKE_KEYSPACE];
  memset(state, 0, KSTROKE_KEYSPACE);

  for (; ;)
  {
    for (int i = 0; i < KSTROKE_KEYSPACE; i++)
    {
      SHORT kchr = GetAsyncKeyState(i);
      int pressed = (kchr & 0x8000) > 0;

      if (pressed == 0 && state[i] == 1)
      {
        state[i] = 0;
        cb(arg, i, 0);
        // printf("press\n");
        continue;
      }

      if (pressed == 1 && state[i] == 0)
      {
        state[i] = 1;
        cb(arg, i, 1);
        continue;
      }
    }
  }

  return 0;
}
#elif __APPLE__
#include <Carbon/Carbon.h>
#include <ApplicationServices/ApplicationServices.h>

static kstroke_cb constant_cb = NULL;
static uintptr_t constant_arg = 0;

int appleKeyToJSkey(int input)
{
  switch (input)
  {
    case kVK_ANSI_0: return KSTROKE_KEY_0;
    case kVK_ANSI_1: return KSTROKE_KEY_1;
    case kVK_ANSI_2: return KSTROKE_KEY_2;
    case kVK_ANSI_3: return KSTROKE_KEY_3;
    case kVK_ANSI_4: return KSTROKE_KEY_4;
    case kVK_ANSI_5: return KSTROKE_KEY_5;
    case kVK_ANSI_6: return KSTROKE_KEY_6;
    case kVK_ANSI_7: return KSTROKE_KEY_7;
    case kVK_ANSI_8: return KSTROKE_KEY_8;
    case kVK_ANSI_9: return KSTROKE_KEY_9;
    case kVK_ANSI_A: return KSTROKE_KEY_A;
    case kVK_ANSI_B: return KSTROKE_KEY_B;
    case kVK_ANSI_C: return KSTROKE_KEY_C;
    case kVK_ANSI_D: return KSTROKE_KEY_D;
    case kVK_ANSI_E: return KSTROKE_KEY_E;
    case kVK_ANSI_F: return KSTROKE_KEY_F;
    case kVK_ANSI_G: return KSTROKE_KEY_G;
    case kVK_ANSI_H: return KSTROKE_KEY_H;
    case kVK_ANSI_I: return KSTROKE_KEY_I;
    case kVK_ANSI_J: return KSTROKE_KEY_J;
    case kVK_ANSI_K: return KSTROKE_KEY_K;
    case kVK_ANSI_L: return KSTROKE_KEY_L;
    case kVK_ANSI_M: return KSTROKE_KEY_M;
    case kVK_ANSI_N: return KSTROKE_KEY_N;
    case kVK_ANSI_O: return KSTROKE_KEY_O;
    case kVK_ANSI_P: return KSTROKE_KEY_P;
    case kVK_ANSI_Q: return KSTROKE_KEY_Q;
    case kVK_ANSI_R: return KSTROKE_KEY_R;
    case kVK_ANSI_S: return KSTROKE_KEY_S;
    case kVK_ANSI_T: return KSTROKE_KEY_T;
    case kVK_ANSI_U: return KSTROKE_KEY_U;
    case kVK_ANSI_V: return KSTROKE_KEY_V;
    case kVK_ANSI_W: return KSTROKE_KEY_W;
    case kVK_ANSI_X: return KSTROKE_KEY_X;
    case kVK_ANSI_Y: return KSTROKE_KEY_Y;
    case kVK_ANSI_Z: return KSTROKE_KEY_Z;
    case kVK_ANSI_LeftBracket: return KSTROKE_KEY_OPEN_BRACKET;
    case kVK_ANSI_RightBracket: return KSTROKE_KEY_CLOSE_BRACKET;
    case kVK_ANSI_Quote: return KSTROKE_KEY_SINGLE_QUOTE;
    case kVK_ANSI_Semicolon: return KSTROKE_KEY_SEMI_COLON;
    case kVK_ANSI_Backslash: return KSTROKE_KEY_BACKSLASH;
    case kVK_ANSI_Comma: return KSTROKE_KEY_COMMA;
    case kVK_ANSI_Period: return KSTROKE_KEY_PERIOD;
    case kVK_ANSI_Grave: return KSTROKE_KEY_GRAVE_ACCENT;
    case kVK_ANSI_KeypadDecimal: return KSTROKE_KEY_DECIMAL_POINT;
    case kVK_ANSI_KeypadMultiply: return KSTROKE_KEY_MULTIPLY;
    case kVK_ANSI_KeypadPlus: return KSTROKE_KEY_ADD;
    case kVK_ANSI_KeypadClear: return KSTROKE_KEY_DELETE;
    case kVK_ANSI_KeypadDivide: return KSTROKE_KEY_DIVIDE;
    case kVK_ANSI_KeypadEnter: return KSTROKE_KEY_NUMPAD_ENTER;
    case kVK_ANSI_KeypadMinus: return KSTROKE_KEY_NUMPAD_SUBTRACT;
    case kVK_ANSI_KeypadEquals: return KSTROKE_KEY_EQUAL_SIGN;
    case kVK_ANSI_Equal: return KSTROKE_KEY_EQUAL_SIGN;
    case kVK_ANSI_Minus: return KSTROKE_KEY_SUBTRACT;
    case kVK_Return: return KSTROKE_KEY_ENTER;
    case kVK_Delete: return KSTROKE_KEY_BACKSPACE;
    case kVK_Space: return KSTROKE_KEY_SPACE;
    case kVK_Tab: return KSTROKE_KEY_TAB;
    case kVK_Escape: return KSTROKE_KEY_ESCAPE;
    case kVK_Command: return KSTROKE_KEY_LEFT_WINDOW_KEY;
    case kVK_Shift: return KSTROKE_KEY_SHIFT;
    case kVK_CapsLock: return KSTROKE_KEY_CAPS_LOCK;
    case kVK_Option: return KSTROKE_KEY_ALT;
    case kVK_Control: return KSTROKE_KEY_CTRL;
    case kVK_RightShift: return KSTROKE_KEY_SHIFT;
    case kVK_RightOption: return KSTROKE_KEY_ALT;
    case kVK_RightControl: return KSTROKE_KEY_CTRL;
    case kVK_VolumeUp: return KSTROKE_KEY_VOLUME_UP;
    case kVK_VolumeDown: return KSTROKE_KEY_VOLUME_DOWN;
    case kVK_Mute: return KSTROKE_KEY_VOLUME_MUTE;
    case kVK_F1: return KSTROKE_KEY_F1;
    case kVK_F2: return KSTROKE_KEY_F2;
    case kVK_F3: return KSTROKE_KEY_F3;
    case kVK_F4: return KSTROKE_KEY_F4;
    case kVK_F5: return KSTROKE_KEY_F5;
    case kVK_F6: return KSTROKE_KEY_F6;
    case kVK_F7: return KSTROKE_KEY_F7;
    case kVK_F8: return KSTROKE_KEY_F8;
    case kVK_F9: return KSTROKE_KEY_F9;
    case kVK_F10: return KSTROKE_KEY_F10;
    case kVK_F11: return KSTROKE_KEY_F11;
    case kVK_F12: return KSTROKE_KEY_F12;
    case kVK_F13: return KSTROKE_KEY_F13;
    case kVK_F14: return KSTROKE_KEY_F14;
    case kVK_F15: return KSTROKE_KEY_F15;
    case kVK_F16: return KSTROKE_KEY_F16;
    case kVK_F17: return KSTROKE_KEY_F17;
    case kVK_F18: return KSTROKE_KEY_F18;
    case kVK_F19: return KSTROKE_KEY_F19;
    case kVK_F20: return KSTROKE_KEY_F20;
    case kVK_Help: return KSTROKE_KEY_F4;
    case kVK_Home: return KSTROKE_KEY_HOME;
    case kVK_PageUp: return KSTROKE_KEY_PAGE_UP;
    case kVK_PageDown: return KSTROKE_KEY_PAGE_DOWN;
    case kVK_LeftArrow: return KSTROKE_KEY_LEFT_ARROW;
    case kVK_RightArrow: return KSTROKE_KEY_RIGHT_ARROW;
    case kVK_UpArrow: return KSTROKE_KEY_UP_ARROW;
    case kVK_DownArrow: return KSTROKE_KEY_DOWN_ARROW;
  }

  fprintf(stderr, "[Keystroke MacOS error]: unknown key code %d (0x%XX)\n", input, input);

  return -1;
}

CGEventRef myCGEventCallback (CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon)
{
  printf("type data: %d\n", type);

  int check = (type != kCGEventKeyDown) && (type != kCGEventKeyUp);
  printf("apple %d\n", check);

  if (check)
  {
    printf("strange type (0x%lX) %d\n", type, type);
    return event;
  }

  bool state = (type != kCGEventKeyDown);
  
  CGKeyCode keyCode = (CGKeyCode) CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);

  int jsCode = appleKeyToJSkey((int)keyCode);
  if (jsCode > -1)
  {
    constant_cb(constant_arg, (uint8_t)jsCode, state);
  }

  return event;
}

int kstroke_listen(kstroke_cb cb, uintptr_t arg)
{
  constant_cb = cb;
  constant_arg = arg;

  CGEventFlags oldFlags = CGEventSourceFlagsState(kCGEventSourceStateCombinedSessionState);

  CGEventMask eventMask = (CGEventMaskBit(kCGEventKeyDown) | CGEventMaskBit(kCGEventKeyUp) | CGEventMaskBit(kCGEventFlagsChanged));
  CFMachPortRef eventTap = CGEventTapCreate(kCGSessionEventTap, kCGHeadInsertEventTap, kCGEventTapOptionListenOnly, eventMask, myCGEventCallback, &oldFlags);
  
  if (!eventTap) {
    fprintf(stderr, "failed to create event tap\nyou need to enable \"Enable access for assitive devices\" in Universal Access preference panel.");
    return -2;
  }
  
  CFRunLoopSourceRef runLoopSource = CFMachPortCreateRunLoopSource(kCFAllocatorDefault, eventTap, 0);
  CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource, kCFRunLoopCommonModes);
  CGEventTapEnable(eventTap, true);
  
  CFRunLoopRun();

  return 0;
}

// Linux/OpenBSD/FreeBSD/Dragonfly (X Window System)
#else 

#include <X11/Xlib.h>
#include <X11/XKBlib.h>
#include <X11/extensions/XInput.h>

#define XK_MISCELLANY
#include <X11/keysymdef.h>

int kstroke_listen(kstroke_cb cb, uintptr_t arg)
{
  Display *display;
  int screen;
  Window root;
  XIC xic;

  /* open display */
  if (display = XOpenDisplay(NULL), !display)
  {
    return -1
  }

  screen = DefaultScreen(display);
  root = RootWindow(display, screen);

  XSelectInput(display, root, KeyPressMask | KeyReleaseMask );
  for (; ;)
  {
    XEvent event;
    XDeviceKeyEvent *device_event;

    XNextEvent(display, &event);

    device_event = (XDeviceKeyEvent *)&event;
    int original_keycode = device_event->keycode;

    if (event.type == KeyPress)
    {
      cb(arg, original_keycode, true);
    }
    else
    {
      cb(arg, original_keycode, false);
    }
  }
}


#endif