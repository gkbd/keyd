/* Copyright © 2019 Raheman Vaiya.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef _KEYS_H_
#define _KEYS_H_
#define _KEYS_H_

#ifdef __FreeBSD__
#include <dev/evdev/input-event-codes.h>
#else
#include <linux/input-event-codes.h>
#endif

#include <stdint.h>

#define MOD_ALT_GR 0x40
#define MOD_CTRL 0x1
#define MOD_SHIFT 0x2
#define MOD_SUPER 0x8
#define MOD_ALT 0x4

#define KEY_NOOP 0x27b

//Used for macros, bit of a kludge.

#define MOD_TIMEOUT 0x20	//keysequence represents a timeout

//Reserve the last 10 bits for the timeout value in ms.
#define TIMEOUT_KEY(ms) ((ms << 22) | 0x200000)
#define GET_TIMEOUT(key) (key >> 22)
#define MAX_TIMEOUT_LEN ((1<<10)-1)


struct keycode_table_ent {
	const char *name;
	const char *alt_name;
	const char *shifted_name;
};

static const struct keycode_table_ent keycode_table[] = {
	[KEY_ESC] = { "esc", "escape", NULL },
	[KEY_1] = { "1", NULL, "!" },
	[KEY_2] = { "2", NULL, "@" },
	[KEY_3] = { "3", NULL, "#" },
	[KEY_4] = { "4", NULL, "$" },
	[KEY_5] = { "5", NULL, "%" },
	[KEY_6] = { "6", NULL, "^" },
	[KEY_7] = { "7", NULL, "&" },
	[KEY_8] = { "8", NULL, "*" },
	[KEY_9] = { "9", NULL, "(" },
	[KEY_0] = { "0", NULL, ")" },
	[KEY_MINUS] = { "-", "minus", "_" },
	[KEY_EQUAL] = { "=", "equal", "+" },
	[KEY_BACKSPACE] = { "backspace", NULL, NULL },
	[KEY_TAB] = { "tab", NULL, NULL },
	[KEY_Q] = { "q", NULL, "Q" },
	[KEY_W] = { "w", NULL, "W" },
	[KEY_E] = { "e", NULL, "E" },
	[KEY_R] = { "r", NULL, "R" },
	[KEY_T] = { "t", NULL, "T" },
	[KEY_Y] = { "y", NULL, "Y" },
	[KEY_U] = { "u", NULL, "U" },
	[KEY_I] = { "i", NULL, "I" },
	[KEY_O] = { "o", NULL, "O" },
	[KEY_P] = { "p", NULL, "P" },
	[KEY_LEFTBRACE] = { "[", "leftbrace", "{" },
	[KEY_RIGHTBRACE] = { "]", "rightbrace", "}" },
	[KEY_ENTER] = { "enter", NULL, NULL },
	[KEY_LEFTCTRL] = { "control", "leftcontrol", NULL },
	[KEY_A] = { "a", NULL, "A" },
	[KEY_S] = { "s", NULL, "S" },
	[KEY_D] = { "d", NULL, "D" },
	[KEY_F] = { "f", NULL, "F" },
	[KEY_G] = { "g", NULL, "G" },
	[KEY_H] = { "h", NULL, "H" },
	[KEY_J] = { "j", NULL, "J" },
	[KEY_K] = { "k", NULL, "K" },
	[KEY_L] = { "l", NULL, "L" },
	[KEY_SEMICOLON] = { ";", "semicolon", ":" },
	[KEY_APOSTROPHE] = { "'", "apostrophe", "\"" },
	[KEY_GRAVE] = { "`", "grave", "~" },
	[KEY_LEFTSHIFT] = { "shift", "leftshift", NULL },
	[KEY_BACKSLASH] = { "\\", "backslash", "|" },
	[KEY_Z] = { "z", NULL, "Z" },
	[KEY_X] = { "x", NULL, "X" },
	[KEY_C] = { "c", NULL, "C" },
	[KEY_V] = { "v", NULL, "V" },
	[KEY_B] = { "b", NULL, "B" },
	[KEY_N] = { "n", NULL, "N" },
	[KEY_M] = { "m", NULL, "M" },
	[KEY_COMMA] = { ",", "comma", "<" },
	[KEY_DOT] = { ".", "dot", ">" },
	[KEY_SLASH] = { "/", "slash", "?" },
	[KEY_RIGHTSHIFT] = { "rightshift", NULL, NULL },
	[KEY_KPASTERISK] = { "kpasterisk", NULL, NULL },
	[KEY_LEFTALT] = { "alt", "leftalt", NULL },
	[KEY_SPACE] = { "space", NULL, NULL },
	[KEY_CAPSLOCK] = { "capslock", NULL, NULL },
	[KEY_F1] = { "f1", NULL, NULL },
	[KEY_F2] = { "f2", NULL, NULL },
	[KEY_F3] = { "f3", NULL, NULL },
	[KEY_F4] = { "f4", NULL, NULL },
	[KEY_F5] = { "f5", NULL, NULL },
	[KEY_F6] = { "f6", NULL, NULL },
	[KEY_F7] = { "f7", NULL, NULL },
	[KEY_F8] = { "f8", NULL, NULL },
	[KEY_F9] = { "f9", NULL, NULL },
	[KEY_F10] = { "f10", NULL, NULL },
	[KEY_NUMLOCK] = { "numlock", NULL, NULL },
	[KEY_SCROLLLOCK] = { "scrolllock", NULL, NULL },
	[KEY_KP7] = { "kp7", NULL, NULL },
	[KEY_KP8] = { "kp8", NULL, NULL },
	[KEY_KP9] = { "kp9", NULL, NULL },
	[KEY_KPMINUS] = { "kpminus", NULL, NULL },
	[KEY_KP4] = { "kp4", NULL, NULL },
	[KEY_KP5] = { "kp5", NULL, NULL },
	[KEY_KP6] = { "kp6", NULL, NULL },
	[KEY_KPPLUS] = { "kpplus", NULL, NULL },
	[KEY_KP1] = { "kp1", NULL, NULL },
	[KEY_KP2] = { "kp2", NULL, NULL },
	[KEY_KP3] = { "kp3", NULL, NULL },
	[KEY_KP0] = { "kp0", NULL, NULL },
	[KEY_KPDOT] = { "kpdot", NULL, NULL },
	[KEY_ZENKAKUHANKAKU] = { "zenkakuhankaku", NULL, NULL },
	[KEY_102ND] = { "102nd", NULL, NULL },
	[KEY_F11] = { "f11", NULL, NULL },
	[KEY_F12] = { "f12", NULL, NULL },
	[KEY_RO] = { "ro", NULL, NULL },
	[KEY_KATAKANA] = { "katakana", NULL, NULL },
	[KEY_HIRAGANA] = { "hiragana", NULL, NULL },
	[KEY_HENKAN] = { "henkan", NULL, NULL },
	[KEY_KATAKANAHIRAGANA] = { "katakanahiragana", NULL, NULL },
	[KEY_MUHENKAN] = { "muhenkan", NULL, NULL },
	[KEY_KPJPCOMMA] = { "kpjpcomma", NULL, NULL },
	[KEY_KPENTER] = { "kpenter", NULL, NULL },
	[KEY_RIGHTCTRL] = { "rightcontrol", NULL, NULL },
	[KEY_KPSLASH] = { "kpslash", NULL, NULL },
	[KEY_SYSRQ] = { "sysrq", NULL, NULL },
	[KEY_RIGHTALT] = { "rightalt", NULL, NULL },
	[KEY_LINEFEED] = { "linefeed", NULL, NULL },
	[KEY_HOME] = { "home", NULL, NULL },
	[KEY_UP] = { "up", NULL, NULL },
	[KEY_PAGEUP] = { "pageup", NULL, NULL },
	[KEY_LEFT] = { "left", NULL, NULL },
	[KEY_RIGHT] = { "right", NULL, NULL },
	[KEY_END] = { "end", NULL, NULL },
	[KEY_DOWN] = { "down", NULL, NULL },
	[KEY_PAGEDOWN] = { "pagedown", NULL, NULL },
	[KEY_INSERT] = { "insert", NULL, NULL },
	[KEY_DELETE] = { "delete", NULL, NULL },
	[KEY_MACRO] = { "macro", NULL, NULL },
	[KEY_MUTE] = { "mute", NULL, NULL },
	[KEY_VOLUMEDOWN] = { "volumedown", NULL, NULL },
	[KEY_VOLUMEUP] = { "volumeup", NULL, NULL },
	[KEY_POWER] = { "power", NULL, NULL },
	[KEY_KPEQUAL] = { "kpequal", NULL, NULL },
	[KEY_KPPLUSMINUS] = { "kpplusminus", NULL, NULL },
	[KEY_PAUSE] = { "pause", NULL, NULL },
	[KEY_SCALE] = { "scale", NULL, NULL },
	[KEY_KPCOMMA] = { "kpcomma", NULL, NULL },
	[KEY_HANGEUL] = { "hangeul", NULL, NULL },
	[KEY_HANJA] = { "hanja", NULL, NULL },
	[KEY_YEN] = { "yen", NULL, NULL },
	[KEY_LEFTMETA] = { "meta", "leftmeta", NULL },
	[KEY_RIGHTMETA] = { "rightmeta", NULL, NULL },
	[KEY_COMPOSE] = { "compose", NULL, NULL },
	[KEY_STOP] = { "stop", NULL, NULL },
	[KEY_AGAIN] = { "again", NULL, NULL },
	[KEY_PROPS] = { "props", NULL, NULL },
	[KEY_UNDO] = { "undo", NULL, NULL },
	[KEY_FRONT] = { "front", NULL, NULL },
	[KEY_COPY] = { "copy", NULL, NULL },
	[KEY_OPEN] = { "open", NULL, NULL },
	[KEY_PASTE] = { "paste", NULL, NULL },
	[KEY_FIND] = { "find", NULL, NULL },
	[KEY_CUT] = { "cut", NULL, NULL },
	[KEY_HELP] = { "help", NULL, NULL },
	[KEY_MENU] = { "menu", NULL, NULL },
	[KEY_CALC] = { "calc", NULL, NULL },
	[KEY_SETUP] = { "setup", NULL, NULL },
	[KEY_SLEEP] = { "sleep", NULL, NULL },
	[KEY_WAKEUP] = { "wakeup", NULL, NULL },
	[KEY_FILE] = { "file", NULL, NULL },
	[KEY_SENDFILE] = { "sendfile", NULL, NULL },
	[KEY_DELETEFILE] = { "deletefile", NULL, NULL },
	[KEY_XFER] = { "xfer", NULL, NULL },
	[KEY_PROG1] = { "prog1", NULL, NULL },
	[KEY_PROG2] = { "prog2", NULL, NULL },
	[KEY_WWW] = { "www", NULL, NULL },
	[KEY_MSDOS] = { "msdos", NULL, NULL },
	[KEY_COFFEE] = { "coffee", NULL, NULL },
	[KEY_ROTATE_DISPLAY] = { "display", NULL, NULL },
	[KEY_CYCLEWINDOWS] = { "cyclewindows", NULL, NULL },
	[KEY_MAIL] = { "mail", NULL, NULL },
	[KEY_BOOKMARKS] = { "bookmarks", NULL, NULL },
	[KEY_COMPUTER] = { "computer", NULL, NULL },
	[KEY_BACK] = { "back", NULL, NULL },
	[KEY_FORWARD] = { "forward", NULL, NULL },
	[KEY_CLOSECD] = { "closecd", NULL, NULL },
	[KEY_EJECTCD] = { "ejectcd", NULL, NULL },
	[KEY_EJECTCLOSECD] = { "ejectclosecd", NULL, NULL },
	[KEY_NEXTSONG] = { "nextsong", NULL, NULL },
	[KEY_PLAYPAUSE] = { "playpause", NULL, NULL },
	[KEY_PREVIOUSSONG] = { "previoussong", NULL, NULL },
	[KEY_STOPCD] = { "stopcd", NULL, NULL },
	[KEY_RECORD] = { "record", NULL, NULL },
	[KEY_REWIND] = { "rewind", NULL, NULL },
	[KEY_PHONE] = { "phone", NULL, NULL },
	[KEY_ISO] = { "iso", NULL, NULL },
	[KEY_CONFIG] = { "config", NULL, NULL },
	[KEY_HOMEPAGE] = { "homepage", NULL, NULL },
	[KEY_REFRESH] = { "refresh", NULL, NULL },
	[KEY_EXIT] = { "exit", NULL, NULL },
	[KEY_MOVE] = { "move", NULL, NULL },
	[KEY_EDIT] = { "edit", NULL, NULL },
	[KEY_SCROLLUP] = { "scrollup", NULL, NULL },
	[KEY_SCROLLDOWN] = { "scrolldown", NULL, NULL },
	[KEY_KPLEFTPAREN] = { "kpleftparen", NULL, NULL },
	[KEY_KPRIGHTPAREN] = { "kprightparen", NULL, NULL },
	[KEY_NEW] = { "new", NULL, NULL },
	[KEY_REDO] = { "redo", NULL, NULL },
	[KEY_F13] = { "f13", NULL, NULL },
	[KEY_F14] = { "f14", NULL, NULL },
	[KEY_F15] = { "f15", NULL, NULL },
	[KEY_F16] = { "f16", NULL, NULL },
	[KEY_F17] = { "f17", NULL, NULL },
	[KEY_F18] = { "f18", NULL, NULL },
	[KEY_F19] = { "f19", NULL, NULL },
	[KEY_F20] = { "f20", NULL, NULL },
	[KEY_F21] = { "f21", NULL, NULL },
	[KEY_F22] = { "f22", NULL, NULL },
	[KEY_F23] = { "f23", NULL, NULL },
	[KEY_F24] = { "f24", NULL, NULL },
	[KEY_PLAYCD] = { "playcd", NULL, NULL },
	[KEY_PAUSECD] = { "pausecd", NULL, NULL },
	[KEY_PROG3] = { "prog3", NULL, NULL },
	[KEY_PROG4] = { "prog4", NULL, NULL },
	[KEY_DASHBOARD] = { "dashboard", NULL, NULL },
	[KEY_SUSPEND] = { "suspend", NULL, NULL },
	[KEY_CLOSE] = { "close", NULL, NULL },
	[KEY_PLAY] = { "play", NULL, NULL },
	[KEY_FASTFORWARD] = { "fastforward", NULL, NULL },
	[KEY_BASSBOOST] = { "bassboost", NULL, NULL },
	[KEY_PRINT] = { "print", NULL, NULL },
	[KEY_HP] = { "hp", NULL, NULL },
	[KEY_CAMERA] = { "camera", NULL, NULL },
	[KEY_SOUND] = { "sound", NULL, NULL },
	[KEY_QUESTION] = { "question", NULL, NULL },
	[KEY_EMAIL] = { "email", NULL, NULL },
	[KEY_CHAT] = { "chat", NULL, NULL },
	[KEY_SEARCH] = { "search", NULL, NULL },
	[KEY_CONNECT] = { "connect", NULL, NULL },
	[KEY_FINANCE] = { "finance", NULL, NULL },
	[KEY_SPORT] = { "sport", NULL, NULL },
	[KEY_SHOP] = { "shop", NULL, NULL },
	[KEY_ALTERASE] = { "alterase", NULL, NULL },
	[KEY_CANCEL] = { "cancel", NULL, NULL },
	[KEY_BRIGHTNESSDOWN] = { "brightnessdown", NULL, NULL },
	[KEY_BRIGHTNESSUP] = { "brightnessup", NULL, NULL },
	[KEY_MEDIA] = { "media", NULL, NULL },
	[KEY_SWITCHVIDEOMODE] = { "switchvideomode", NULL, NULL },
	[KEY_KBDILLUMTOGGLE] = { "kbdillumtoggle", NULL, NULL },
	[KEY_KBDILLUMDOWN] = { "kbdillumdown", NULL, NULL },
	[KEY_KBDILLUMUP] = { "kbdillumup", NULL, NULL },
	[KEY_SEND] = { "send", NULL, NULL },
	[KEY_REPLY] = { "reply", NULL, NULL },
	[KEY_FORWARDMAIL] = { "forwardmail", NULL, NULL },
	[KEY_SAVE] = { "save", NULL, NULL },
	[KEY_DOCUMENTS] = { "documents", NULL, NULL },
	[KEY_BATTERY] = { "battery", NULL, NULL },
	[KEY_BLUETOOTH] = { "bluetooth", NULL, NULL },
	[KEY_WLAN] = { "wlan", NULL, NULL },
	[KEY_UWB] = { "uwb", NULL, NULL },
	[KEY_UNKNOWN] = { "unknown", NULL, NULL },
	[KEY_VIDEO_NEXT] = { "next", NULL, NULL },
	[KEY_VIDEO_PREV] = { "prev", NULL, NULL },
	[KEY_BRIGHTNESS_CYCLE] = { "cycle", NULL, NULL },
	[KEY_BRIGHTNESS_AUTO] = { "auto", NULL, NULL },
	[KEY_DISPLAY_OFF] = { "off", NULL, NULL },
	[KEY_WWAN] = { "wwan", NULL, NULL },
	[KEY_RFKILL] = { "rfkill", NULL, NULL },
	[KEY_MICMUTE] = { "micmute", NULL, NULL },
	[KEY_OK] = { "ok", NULL, NULL },
	[KEY_SELECT] = { "select", NULL, NULL },
	[KEY_GOTO] = { "goto", NULL, NULL },
	[KEY_CLEAR] = { "clear", NULL, NULL },
	[KEY_POWER2] = { "power2", NULL, NULL },
	[KEY_OPTION] = { "option", NULL, NULL },
	[KEY_INFO] = { "info", NULL, NULL },
	[KEY_TIME] = { "time", NULL, NULL },
	[KEY_VENDOR] = { "vendor", NULL, NULL },
	[KEY_ARCHIVE] = { "archive", NULL, NULL },
	[KEY_PROGRAM] = { "program", NULL, NULL },
	[KEY_CHANNEL] = { "channel", NULL, NULL },
	[KEY_FAVORITES] = { "favorites", NULL, NULL },
	[KEY_EPG] = { "epg", NULL, NULL },
	[KEY_PVR] = { "pvr", NULL, NULL },
	[KEY_MHP] = { "mhp", NULL, NULL },
	[KEY_LANGUAGE] = { "language", NULL, NULL },
	[KEY_TITLE] = { "title", NULL, NULL },
	[KEY_SUBTITLE] = { "subtitle", NULL, NULL },
	[KEY_ANGLE] = { "angle", NULL, NULL },
	[KEY_ZOOM] = { "zoom", NULL, NULL },
	[KEY_MODE] = { "mode", NULL, NULL },
	[KEY_KEYBOARD] = { "keyboard", NULL, NULL },
	[KEY_SCREEN] = { "screen", NULL, NULL },
	[KEY_PC] = { "pc", NULL, NULL },
	[KEY_TV] = { "tv", NULL, NULL },
	[KEY_TV2] = { "tv2", NULL, NULL },
	[KEY_VCR] = { "vcr", NULL, NULL },
	[KEY_VCR2] = { "vcr2", NULL, NULL },
	[KEY_SAT] = { "sat", NULL, NULL },
	[KEY_SAT2] = { "sat2", NULL, NULL },
	[KEY_CD] = { "cd", NULL, NULL },
	[KEY_TAPE] = { "tape", NULL, NULL },
	[KEY_RADIO] = { "radio", NULL, NULL },
	[KEY_TUNER] = { "tuner", NULL, NULL },
	[KEY_PLAYER] = { "player", NULL, NULL },
	[KEY_TEXT] = { "text", NULL, NULL },
	[KEY_DVD] = { "dvd", NULL, NULL },
	[KEY_AUX] = { "aux", NULL, NULL },
	[KEY_MP3] = { "mp3", NULL, NULL },
	[KEY_AUDIO] = { "audio", NULL, NULL },
	[KEY_VIDEO] = { "video", NULL, NULL },
	[KEY_DIRECTORY] = { "directory", NULL, NULL },
	[KEY_LIST] = { "list", NULL, NULL },
	[KEY_MEMO] = { "memo", NULL, NULL },
	[KEY_CALENDAR] = { "calendar", NULL, NULL },
	[KEY_RED] = { "red", NULL, NULL },
	[KEY_GREEN] = { "green", NULL, NULL },
	[KEY_YELLOW] = { "yellow", NULL, NULL },
	[KEY_BLUE] = { "blue", NULL, NULL },
	[KEY_CHANNELUP] = { "channelup", NULL, NULL },
	[KEY_CHANNELDOWN] = { "channeldown", NULL, NULL },
	[KEY_FIRST] = { "first", NULL, NULL },
	[KEY_LAST] = { "last", NULL, NULL },
	[KEY_AB] = { "ab", NULL, NULL },
	[KEY_NEXT] = { "next", NULL, NULL },
	[KEY_RESTART] = { "restart", NULL, NULL },
	[KEY_SLOW] = { "slow", NULL, NULL },
	[KEY_SHUFFLE] = { "shuffle", NULL, NULL },
	[KEY_BREAK] = { "break", NULL, NULL },
	[KEY_PREVIOUS] = { "previous", NULL, NULL },
	[KEY_DIGITS] = { "digits", NULL, NULL },
	[KEY_TEEN] = { "teen", NULL, NULL },
	[KEY_TWEN] = { "twen", NULL, NULL },
	[KEY_VIDEOPHONE] = { "videophone", NULL, NULL },
	[KEY_GAMES] = { "games", NULL, NULL },
	[KEY_ZOOMIN] = { "zoomin", NULL, NULL },
	[KEY_ZOOMOUT] = { "zoomout", NULL, NULL },
	[KEY_ZOOMRESET] = { "zoomreset", NULL, NULL },
	[KEY_WORDPROCESSOR] = { "wordprocessor", NULL, NULL },
	[KEY_EDITOR] = { "editor", NULL, NULL },
	[KEY_SPREADSHEET] = { "spreadsheet", NULL, NULL },
	[KEY_GRAPHICSEDITOR] = { "graphicseditor", NULL, NULL },
	[KEY_PRESENTATION] = { "presentation", NULL, NULL },
	[KEY_DATABASE] = { "database", NULL, NULL },
	[KEY_NEWS] = { "news", NULL, NULL },
	[KEY_VOICEMAIL] = { "voicemail", NULL, NULL },
	[KEY_ADDRESSBOOK] = { "addressbook", NULL, NULL },
	[KEY_MESSENGER] = { "messenger", NULL, NULL },
	[KEY_DISPLAYTOGGLE] = { "displaytoggle", NULL, NULL },
	[KEY_SPELLCHECK] = { "spellcheck", NULL, NULL },
	[KEY_LOGOFF] = { "logoff", NULL, NULL },
	[KEY_DOLLAR] = { "dollar", NULL, NULL },
	[KEY_EURO] = { "euro", NULL, NULL },
	[KEY_FRAMEBACK] = { "frameback", NULL, NULL },
	[KEY_FRAMEFORWARD] = { "frameforward", NULL, NULL },
	[KEY_CONTEXT_MENU] = { "context_menu", NULL, NULL },
	[KEY_MEDIA_REPEAT] = { "repeat", NULL, NULL },
	[KEY_10CHANNELSUP] = { "10channelsup", NULL, NULL },
	[KEY_10CHANNELSDOWN] = { "10channelsdown", NULL, NULL },
	[KEY_IMAGES] = { "images", NULL, NULL },
	[KEY_DEL_EOL] = { "eol", NULL, NULL },
	[KEY_DEL_EOS] = { "eos", NULL, NULL },
	[KEY_INS_LINE] = { "ins_line", NULL, NULL },
	[KEY_DEL_LINE] = { "del_line", NULL, NULL },
	[KEY_FN] = { "fn", NULL, NULL },
	[KEY_FN_ESC] = { "esc", NULL, NULL },
	[KEY_FN_F1] = { "f1", NULL, NULL },
	[KEY_FN_F2] = { "f2", NULL, NULL },
	[KEY_FN_F3] = { "f3", NULL, NULL },
	[KEY_FN_F4] = { "f4", NULL, NULL },
	[KEY_FN_F5] = { "f5", NULL, NULL },
	[KEY_FN_F6] = { "f6", NULL, NULL },
	[KEY_FN_F7] = { "f7", NULL, NULL },
	[KEY_FN_F8] = { "f8", NULL, NULL },
	[KEY_FN_F9] = { "f9", NULL, NULL },
	[KEY_FN_F10] = { "f10", NULL, NULL },
	[KEY_FN_F11] = { "f11", NULL, NULL },
	[KEY_FN_F12] = { "f12", NULL, NULL },
	[KEY_FN_1] = { "1", NULL, NULL },
	[KEY_FN_2] = { "2", NULL, NULL },
	[KEY_FN_D] = { "d", NULL, NULL },
	[KEY_FN_E] = { "e", NULL, NULL },
	[KEY_FN_F] = { "f", NULL, NULL },
	[KEY_FN_S] = { "s", NULL, NULL },
	[KEY_FN_B] = { "b", NULL, NULL },
	[KEY_BRL_DOT1] = { "dot1", NULL, NULL },
	[KEY_BRL_DOT2] = { "dot2", NULL, NULL },
	[KEY_BRL_DOT3] = { "dot3", NULL, NULL },
	[KEY_BRL_DOT4] = { "dot4", NULL, NULL },
	[KEY_BRL_DOT5] = { "dot5", NULL, NULL },
	[KEY_BRL_DOT6] = { "dot6", NULL, NULL },
	[KEY_BRL_DOT7] = { "dot7", NULL, NULL },
	[KEY_BRL_DOT8] = { "dot8", NULL, NULL },
	[KEY_BRL_DOT9] = { "dot9", NULL, NULL },
	[KEY_BRL_DOT10] = { "dot10", NULL, NULL },
	[KEY_NUMERIC_0] = { "np0", NULL, NULL },
	[KEY_NUMERIC_1] = { "np1", NULL, NULL },
	[KEY_NUMERIC_2] = { "np2", NULL, NULL },
	[KEY_NUMERIC_3] = { "np3", NULL, NULL },
	[KEY_NUMERIC_4] = { "np4", NULL, NULL },
	[KEY_NUMERIC_5] = { "np5", NULL, NULL },
	[KEY_NUMERIC_6] = { "np6", NULL, NULL },
	[KEY_NUMERIC_7] = { "np7", NULL, NULL },
	[KEY_NUMERIC_8] = { "np8", NULL, NULL },
	[KEY_NUMERIC_9] = { "np9", NULL, NULL },
	[KEY_NUMERIC_STAR] = { "npstar", NULL, NULL },
	[KEY_NUMERIC_POUND] = { "nppound", NULL, NULL },
	[KEY_NUMERIC_A] = { "npa", NULL, NULL },
	[KEY_NUMERIC_B] = { "npb", NULL, NULL },
	[KEY_NUMERIC_C] = { "npc", NULL, NULL },
	[KEY_NUMERIC_D] = { "npd", NULL, NULL },
	[KEY_CAMERA_FOCUS] = { "focus", NULL, NULL },
	[KEY_WPS_BUTTON] = { "button", NULL, NULL },
	[KEY_TOUCHPAD_TOGGLE] = { "toggle", NULL, NULL },
	[KEY_TOUCHPAD_ON] = { "on", NULL, NULL },
	[KEY_TOUCHPAD_OFF] = { "off", NULL, NULL },
	[KEY_CAMERA_ZOOMIN] = { "zoomin", NULL, NULL },
	[KEY_CAMERA_ZOOMOUT] = { "zoomout", NULL, NULL },
	[KEY_CAMERA_UP] = { "up", NULL, NULL },
	[KEY_CAMERA_DOWN] = { "down", NULL, NULL },
	[KEY_CAMERA_LEFT] = { "left", NULL, NULL },
	[KEY_CAMERA_RIGHT] = { "right", NULL, NULL },
	[KEY_ATTENDANT_ON] = { "on", NULL, NULL },
	[KEY_ATTENDANT_OFF] = { "off", NULL, NULL },
	[KEY_ATTENDANT_TOGGLE] = { "attendant_toggle", NULL, NULL },
	[KEY_LIGHTS_TOGGLE] = { "lights_toggle", NULL, NULL },
	[KEY_ALS_TOGGLE] = { "als_toggle", NULL, NULL },
	[KEY_BUTTONCONFIG] = { "buttonconfig", NULL, NULL },
	[KEY_TASKMANAGER] = { "taskmanager", NULL, NULL },
	[KEY_JOURNAL] = { "journal", NULL, NULL },
	[KEY_CONTROLPANEL] = { "controlpanel", NULL, NULL },
	[KEY_APPSELECT] = { "appselect", NULL, NULL },
	[KEY_SCREENSAVER] = { "screensaver", NULL, NULL },
	[KEY_VOICECOMMAND] = { "voicecommand", NULL, NULL },
	[KEY_BRIGHTNESS_MIN] = { "min", NULL, NULL },
	[KEY_BRIGHTNESS_MAX] = { "max", NULL, NULL },
	[KEY_KBDINPUTASSIST_PREV] = { "prev", NULL, NULL },
	[KEY_KBDINPUTASSIST_NEXT] = { "next", NULL, NULL },
	[KEY_KBDINPUTASSIST_PREVGROUP] = { "prevgroup", NULL, NULL },
	[KEY_KBDINPUTASSIST_NEXTGROUP] = { "nextgroup", NULL, NULL },
	[KEY_KBDINPUTASSIST_ACCEPT] = { "accept", NULL, NULL },
	[KEY_KBDINPUTASSIST_CANCEL] = { "cancel", NULL, NULL },
	[KEY_RIGHT_UP] = { "up", NULL, NULL },
	[KEY_RIGHT_DOWN] = { "down", NULL, NULL },
	[KEY_LEFT_UP] = { "up", NULL, NULL },
	[KEY_LEFT_DOWN] = { "down", NULL, NULL },
	[KEY_ROOT_MENU] = { "root_menu", NULL, NULL },
	[KEY_MEDIA_TOP_MENU] = { "media_top_menu", NULL, NULL },
	[KEY_NUMERIC_11] = { "11", NULL, NULL },
	[KEY_NUMERIC_12] = { "12", NULL, NULL },
	[KEY_AUDIO_DESC] = { "desc", NULL, NULL },
	[KEY_3D_MODE] = { "mode", NULL, NULL },
	[KEY_NEXT_FAVORITE] = { "favorite", NULL, NULL },
	[KEY_STOP_RECORD] = { "stop_record", NULL, NULL },
	[KEY_PAUSE_RECORD] = { "pause_record", NULL, NULL },
	[KEY_VOD] = { "vod", NULL, NULL },
	[KEY_UNMUTE] = { "unmute", NULL, NULL },
	[KEY_FASTREVERSE] = { "fastreverse", NULL, NULL },
	[KEY_SLOWREVERSE] = { "slowreverse", NULL, NULL },
	[KEY_DATA] = { "data", NULL, NULL },
	[KEY_NOOP] = { "noop", NULL, NULL },


	[BTN_0] = { "btn 0", NULL, NULL },
	[BTN_1] = { "btn 1", NULL, NULL },
	[BTN_2] = { "btn 2", NULL, NULL },
	[BTN_3] = { "btn 3", NULL, NULL },
	[BTN_4] = { "btn 4", NULL, NULL },
	[BTN_5] = { "btn 5", NULL, NULL },
	[BTN_6] = { "btn 6", NULL, NULL },
	[BTN_7] = { "btn 7", NULL, NULL },
	[BTN_8] = { "btn 8", NULL, NULL },
	[BTN_9] = { "btn 9", NULL, NULL },

	[BTN_LEFT] = { "btn left", NULL, NULL },
	[BTN_RIGHT] = { "btn right", NULL, NULL },
	[BTN_MIDDLE] = { "btn middle", NULL, NULL },
	[BTN_SIDE] = { "btn side", NULL, NULL },
	[BTN_EXTRA] = { "btn extra", NULL, NULL },
	[BTN_FORWARD] = { "btn forward", NULL, NULL },
	[BTN_BACK] = { "btn back", NULL, NULL },
	[BTN_TASK] = { "btn task", NULL, NULL },

	[KEY_MAX] = { 0 }
};

static const uint16_t evdev_to_hid[290] = {
	0x0001, 0x0029, // ESCAPE
	0x0002, 0x001e, // 1
	0x0003, 0x001f, // 2
	0x0004, 0x0020, // 3
	0x0005, 0x0021, // 4
	0x0006, 0x0022, // 5
	0x0007, 0x0023, // 6
	0x0008, 0x0024, // 7
	0x0009, 0x0025, // 8
	0x000a, 0x0026, // 9
	0x000b, 0x0027, // 0
	0x000c, 0x002d, // MINUS
	0x000d, 0x002e, // EQUAL
	0x000e, 0x002a, // BACKSPACE
	0x000f, 0x002b, // TAB
	0x0010, 0x0014, // Q
	0x0011, 0x001a, // W
	0x0012, 0x0008, // E
	0x0013, 0x0015, // R
	0x0014, 0x0017, // T
	0x0015, 0x001c, // Y
	0x0016, 0x0018, // U
	0x0017, 0x000c, // I
	0x0018, 0x0012, // O
	0x0019, 0x0013, // P
	0x001a, 0x002f, // BRACKET_LEFT
	0x001b, 0x0030, // BRACKET_RIGHT
	0x001c, 0x0028, // ENTER
	0x001d, 0x00e0, // CONTROL_LEFT
	0x001e, 0x0004, // A
	0x001f, 0x0016, // S
	0x0020, 0x0007, // D
	0x0021, 0x0009, // F
	0x0022, 0x000a, // G
	0x0023, 0x000b, // H
	0x0024, 0x000d, // J
	0x0025, 0x000e, // K
	0x0026, 0x000f, // L
	0x0027, 0x0033, // SEMICOLON
	0x0028, 0x0034, // QUOTE
	0x0029, 0x0035, // BACKQUOTE
	0x002a, 0x00e1, // SHIFT_LEFT
	0x002b, 0x0031, // BACKSLASH
	0x002c, 0x001d, // Z
	0x002d, 0x001b, // X
	0x002e, 0x0006, // C
	0x002f, 0x0019, // V
	0x0030, 0x0005, // B
	0x0031, 0x0011, // N
	0x0032, 0x0010, // M
	0x0033, 0x0036, // COMMA
	0x0034, 0x0037, // PERIOD
	0x0035, 0x0038, // SLASH
	0x0036, 0x00e5, // SHIFT_RIGHT
	0x0037, 0x0055, // NUMPAD_MULTIPLY
	0x0038, 0x00e2, // ALT_LEFT
	0x0039, 0x002c, // SPACE
	0x003a, 0x0039, // CAPS_LOCK
	0x003b, 0x003a, // F1
	0x003c, 0x003b, // F2
	0x003d, 0x003c, // F3
	0x003e, 0x003d, // F4
	0x003f, 0x003e, // F5
	0x0040, 0x003f, // F6
	0x0041, 0x0040, // F7
	0x0042, 0x0041, // F8
	0x0043, 0x0042, // F9
	0x0044, 0x0043, // F10
	0x0045, 0x0053, // NUM_LOCK
	0x0046, 0x0047, // SCROLL_LOCK
	0x0047, 0x005f, // NUMPAD7
	0x0048, 0x0060, // NUMPAD8
	0x0049, 0x0061, // NUMPAD9
	0x004a, 0x0056, // NUMPAD_SUBTRACT
	0x004b, 0x005c, // NUMPAD4
	0x004c, 0x005d, // NUMPAD5
	0x004d, 0x005e, // NUMPAD6
	0x004e, 0x0057, // NUMPAD_ADD
	0x004f, 0x0059, // NUMPAD1
	0x0050, 0x005a, // NUMPAD2
	0x0051, 0x005b, // NUMPAD3
	0x0052, 0x0062, // NUMPAD0
	0x0053, 0x0063, // NUMPAD_DECIMAL
	0x0055, 0x0094, // LANG5
	0x0056, 0x0064, // INTL_BACKSLASH
	0x0057, 0x0044, // F11
	0x0058, 0x0045, // F12
	0x0059, 0x0087, // INTL_RO
	0x005a, 0x0092, // LANG3
	0x005b, 0x0093, // LANG4
	0x005c, 0x008a, // CONVERT
	0x005d, 0x0088, // KANA_MODE
	0x005e, 0x008b, // NON_CONVERT
	0x0060, 0x0058, // NUMPAD_ENTER
	0x0061, 0x00e4, // CONTROL_RIGHT
	0x0062, 0x0054, // NUMPAD_DIVIDE
	0x0063, 0x0046, // PRINT_SCREEN
	0x0064, 0x00e6, // ALT_RIGHT
	0x0066, 0x004a, // HOME
	0x0067, 0x0052, // ARROW_UP
	0x0068, 0x004b, // PAGE_UP
	0x0069, 0x0050, // ARROW_LEFT
	0x006a, 0x004f, // ARROW_RIGHT
	0x006b, 0x004d, // END
	0x006c, 0x0051, // ARROW_DOWN
	0x006d, 0x004e, // PAGE_DOWN
	0x006e, 0x0049, // INSERT
	0x006f, 0x004c, // DEL
	0x0071, 0x007f, // VOLUME_MUTE
	0x0072, 0x0081, // VOLUME_DOWN
	0x0073, 0x0080, // VOLUME_UP
	0x0074, 0x0066, // POWER
	0x0075, 0x0067, // NUMPAD_EQUAL
	0x0076, 0x00d7, // NUMPAD_SIGN_CHANGE
	0x0077, 0x0048, // PAUSE
	0x0079, 0x0085, // NUMPAD_COMMA
	0x007a, 0x0090, // LANG1
	0x007b, 0x0091, // LANG2
	0x007c, 0x0089, // INTL_YEN
	0x007d, 0x00e3, // META_LEFT
	0x007e, 0x00e7, // META_RIGHT
	0x007f, 0x0065, // CONTEXT_MENU
	0x0081, 0x0079, // AGAIN
	0x0083, 0x007a, // UNDO
	0x0084, 0x0077, // SELECT
	0x0085, 0x007c, // COPY
	0x0086, 0x0074, // OPEN
	0x0087, 0x007d, // PASTE
	0x0088, 0x007e, // FIND
	0x0089, 0x007b, // CUT
	0x008a, 0x0075, // HELP
	0x00b3, 0x00b6, // NUMPAD_PAREN_LEFT
	0x00b4, 0x00b7, // NUMPAD_PAREN_RIGHT
	0x00b7, 0x0068, // F13
	0x00b8, 0x0069, // F14
	0x00b9, 0x006a, // F15
	0x00ba, 0x006b, // F16
	0x00bb, 0x006c, // F17
	0x00bc, 0x006d, // F18
	0x00bd, 0x006e, // F19
	0x00be, 0x006f, // F20
	0x00bf, 0x0070, // F21
	0x00c0, 0x0071, // F22
	0x00c1, 0x0072, // F23
	0x00c2, 0x0073 // F24
};

#endif
