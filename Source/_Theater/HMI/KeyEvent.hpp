/** Kabuki Theater
    @file    /.../Source/_/KeyEvent.hpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2017 Cale McCollough <https://calemccollough.github.io>

                            All right reserved (R).

        Licensed under the Apache License, Version 2.0 (the "License"); you may
        not use this file except in compliance with the License. You may obtain
        a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
*/

#pragma once

namespace _ { 

class KeyEvent
{
    public:

    enum VK {
        VK_ABNT_C1              = 0xC1, //< Abnt C1
        VK_ABNT_C2              = 0xC2, //< Abnt C2
        VK_ADD                  = 0x6B, //< Numpad +
        VK_ATTN                 = 0xF6, //< Attn
        VK_BACK                 = 0x08, //< Backspace
        VK_CANCEL               = 0x03, //< Break
        VK_CLEAR                = 0x0C, //< Clear
        VK_CRSEL                = 0xF7, //< Cr Sel
        VK_DECIMAL              = 0x6E, //< Numpad .
        VK_DIVIDE               = 0x6F, //< Numpad /
        VK_EREOF                = 0xF9, //< Er Eof
        VK_ESCAPE               = 0x1B, //< Esc
        VK_EXECUTE              = 0x2B, //< Execute
        VK_EXSEL                = 0xF8, //< Ex Sel
        VK_ICO_CLEAR            = 0xE6, //< IcoClr
        VK_ICO_HELP             = 0xE3, //< IcoHlp
        VK_KEY_0                = 0x30, //< '0'
        VK_KEY_1                = 0x31, //< '1'
        VK_KEY_2                = 0x32, //< '2'
        VK_KEY_3                = 0x33, //< '3'
        VK_KEY_4                = 0x34, //< '4'
        VK_KEY_5                = 0x35, //< '5'
        VK_KEY_6                = 0x36, //< '6'
        VK_KEY_7                = 0x37, //< '7'
        VK_KEY_8                = 0x38, //< '8'
        VK_KEY_9                = 0x39, //< '9'
        VK_KEY_A                = 0x41, //< 'A'
        VK_KEY_B                = 0x42, //< 'B'
        VK_KEY_C                = 0x43, //< 'C'
        VK_KEY_D                = 0x44, //< 'D'
        VK_KEY_E                = 0x45, //< 'E'
        VK_KEY_F                = 0x46, //< 'F'
        VK_KEY_G                = 0x47, //< 'G'
        VK_KEY_H                = 0x48, //< 'H'
        VK_KEY_I                = 0x49, //< 'I'
        VK_KEY_J                = 0x4A, //< 'J'
        VK_KEY_K                = 0x4B, //< 'K'
        VK_KEY_L                = 0x4C, //< 'L'
        VK_KEY_M                = 0x4D, //< 'M'
        VK_KEY_N                = 0x4E, //< 'N'
        VK_KEY_O                = 0x4F, //< 'O'
        VK_KEY_P                = 0x50, //< 'P'
        VK_KEY_Q                = 0x51, //< 'Q'
        VK_KEY_R                = 0x52, //< 'R'
        VK_KEY_S                = 0x53, //< 'S'
        VK_KEY_T                = 0x54, //< 'T'
        VK_KEY_U                = 0x55, //< 'U'
        VK_KEY_V                = 0x56, //< 'V'
        VK_KEY_W                = 0x57, //< 'W'
        VK_KEY_X                = 0x58, //< 'X'
        VK_KEY_Y                = 0x59, //< 'Y'
        VK_KEY_Z                = 0x5A, //< 'Z'
        VK_MULTIPLY             = 0x6A, //< Numpad *
        VK_NONAME               = 0xFC, //< NoName
        VK_NUMPAD0              = 0x60, //< Numpad 0
        VK_NUMPAD1              = 0x61, //< Numpad 1
        VK_NUMPAD2              = 0x62, //< Numpad 2
        VK_NUMPAD3              = 0x63, //< Numpad 3
        VK_NUMPAD4              = 0x64, //< Numpad 4
        VK_NUMPAD5              = 0x65, //< Numpad 5
        VK_NUMPAD6              = 0x66, //< Numpad 6
        VK_NUMPAD7              = 0x67, //< Numpad 7
        VK_NUMPAD8              = 0x68, //< Numpad 8
        VK_NUMPAD9              = 0x69, //< Numpad 9
        VK_OEM_1                = 0xBA, //< OEM_1 (: ;)
        VK_OEM_102              = 0xE2, //< OEM_102 (> <)
        VK_OEM_2                = 0xBF, //< OEM_2 (? /)
        VK_OEM_3                = 0xC0, //< OEM_3 (~ `)
        VK_OEM_4                = 0xDB, //< OEM_4 ({ [)
        VK_OEM_5                = 0xDC, //< OEM_5 (| \)
        VK_OEM_6                = 0xDD, //< OEM_6 (} ])
        VK_OEM_7                = 0xDE, //< OEM_7 (" ')
        VK_OEM_8                = 0xDF, //< OEM_8 (§ !)
        VK_OEM_ATTN             = 0xF0, //< Oem Attn
        VK_OEM_AUTO             = 0xF3, //< Auto
        VK_OEM_AX               = 0xE1, //< Ax
        VK_OEM_BACKTAB          = 0xF5, //< Back Tab
        VK_OEM_CLEAR            = 0xFE, //< OemClr
        VK_OEM_COMMA            = 0xBC, //< OEM_COMMA (< ,)
        VK_OEM_COPY             = 0xF2, //< Copy
        VK_OEM_CUSEL            = 0xEF, //< Cu Sel
        VK_OEM_ENLW             = 0xF4, //< Enlw
        VK_OEM_FINISH           = 0xF1, //< Finish
        VK_OEM_FJ_LOYA          = 0x95, //< Loya
        VK_OEM_FJ_MASSHOU       = 0x93, //< Mashu
        VK_OEM_FJ_ROYA          = 0x96, //< Roya
        VK_OEM_FJ_TOUROKU       = 0x94, //< Touroku
        VK_OEM_JUMP             = 0xEA, //< Jump
        VK_OEM_MINUS            = 0xBD, //< OEM_MINUS (_ -)
        VK_OEM_PA1              = 0xEB, //< OemPa1
        VK_OEM_PA2              = 0xEC, //< OemPa2
        VK_OEM_PA3              = 0xED, //< OemPa3
        VK_OEM_PERIOD           = 0xBE, //< OEM_PERIOD (> .)
        VK_OEM_PLUS             = 0xBB, //< OEM_PLUS (+ =)
        VK_OEM_RESET            = 0xE9, //< Reset
        VK_OEM_WSCTRL           = 0xEE, //< WsCtrl
        VK_PA1                  = 0xFD, //< Pa1
        VK_PACKET               = 0xE7, //< Packet
        VK_PLAY                 = 0xFA, //< Play
        VK_PROCESSKEY           = 0xE5, //< Process
        VK_RETURN               = 0x0D, //< Enter
        VK_SELECT               = 0x29, //< Select
        VK_SEPARATOR            = 0x6C, //< Separator
        VK_SPACE                = 0x20, //< Space
        VK_SUBTRACT             = 0x6D, //< Num -
        VK_TAB                  = 0x09, //< Tab
        VK_ZOOM                 = 0xFB, //< Zoom
        VK__none_               = 0xFF, //< no VK mapping
        VK_ACCEPT               = 0x1E, //< Accept
        VK_APPS                 = 0x5D, //< Context Menu
        VK_BROWSER_BACK         = 0xA6, //< Browser Back
        VK_BROWSER_FAVORITES    = 0xAB, //< Browser Favorites
        VK_BROWSER_FORWARD      = 0xA7, //< Browser Forward
        VK_BROWSER_HOME         = 0xAC, //< Browser Home
        VK_BROWSER_REFRESH      = 0xA8, //< Browser Refresh
        VK_BROWSER_SEARCH       = 0xAA, //< Browser Search
        VK_BROWSER_STOP         = 0xA9, //< Browser Stop
        VK_CAPITAL              = 0x14, //< Caps Lock
        VK_CONVERT              = 0x1C, //< Convert
        VK_DELETE               = 0x2E, //< Delete
        VK_DOWN                 = 0x28, //< Arrow Down
        VK_END                  = 0x23, //< End
        VK_F1                   = 0x70, //< F1
        VK_F10                  = 0x79, //< F10
        VK_F11                  = 0x7A, //< F11
        VK_F12                  = 0x7B, //< F12
        VK_F13                  = 0x7C, //< F13
        VK_F14                  = 0x7D, //< F14
        VK_F15                  = 0x7E, //< F15
        VK_F16                  = 0x7F, //< F16
        VK_F17                  = 0x80, //< F17
        VK_F18                  = 0x81, //< F18
        VK_F19                  = 0x82, //< F19
        VK_F2                   = 0x71, //< F2
        VK_F20                  = 0x83, //< F20
        VK_F21                  = 0x84, //< F21
        VK_F22                  = 0x85, //< F22
        VK_F23                  = 0x86, //< F23
        VK_F24                  = 0x87, //< F24
        VK_F3                   = 0x72, //< F3
        VK_F4                   = 0x73, //< F4
        VK_F5                   = 0x74, //< F5
        VK_F6                   = 0x75, //< F6
        VK_F7                   = 0x76, //< F7
        VK_F8                   = 0x77, //< F8
        VK_F9                   = 0x78, //< F9
        VK_FINAL                = 0x18, //< Final
        VK_HELP                 = 0x2F, //< Help
        VK_HOME                 = 0x24, //< Home
        VK_ICO_00               = 0xE4, //< Ico00 *
        VK_INSERT               = 0x2D, //< Insert
        VK_JUNJA                = 0x17, //< Junja
        VK_KANA                 = 0x15, //< Kana
        VK_KANJI                = 0x19, //< Kanji
        VK_LAUNCH_APP1          = 0xB6, //< App1
        VK_LAUNCH_APP2          = 0xB7, //< App2
        VK_LAUNCH_MAIL          = 0xB4, //< Mail
        VK_LAUNCH_MEDIA_SELECT  = 0xB5, //< Media
        VK_LBUTTON              = 0x01, //< Left Button **
        VK_LCONTROL             = 0xA2, //< Left Ctrl
        VK_LEFT                 = 0x25, //< Arrow Left
        VK_LMENU                = 0xA4, //< Left Alt
        VK_LSHIFT               = 0xA0, //< Left Shift
        VK_LWIN                 = 0x5B, //< Left Win
        VK_MBUTTON              = 0x04, //< Middle Button **
        VK_MEDIA_NEXT_TRACK     = 0xB0, //< Next Track
        VK_MEDIA_PLAY_PAUSE     = 0xB3, //< Play / Pause
        VK_MEDIA_PREV_TRACK     = 0xB1, //< Previous Track
        VK_MEDIA_STOP           = 0xB2, //< Stop
        VK_MODECHANGE           = 0x1F, //< Mode Change
        VK_NEXT                 = 0x22, //< Page Down
        VK_NONCONVERT           = 0x1D, //< Non Convert
        VK_NUMLOCK              = 0x90, //< Num Lock
        VK_OEM_FJ_JISHO         = 0x92, //< Jisho
        VK_PAUSE                = 0x13, //< Pause
        VK_PRINT                = 0x2A, //< Print
        VK_PRIOR                = 0x21, //< Page Up
        VK_RBUTTON              = 0x02, //< Right Button
        VK_RCONTROL             = 0xA3, //< Right Ctrl
        VK_RIGHT                = 0x27, //< Arrow Right
        VK_RMENU                = 0xA5, //< Right Alt
        VK_RSHIFT               = 0xA1, //< Right Shift
        VK_RWIN                 = 0x5C, //< Right Win
        VK_SCROLL               = 0x91, //< Scrol Lock
        VK_SLEEP                = 0x5F, //< Sleep
        VK_SNAPSHOT             = 0x2C, //< Print Screen
        VK_UP                   = 0x26, //< Arrow Up
        VK_VOLUME_DOWN          = 0xAE, //< Volume Down
        VK_VOLUME_MUTE          = 0xAD, //< Volume Mute
        VK_VOLUME_UP            = 0xAF, //< Volume Up
        VK_XBUTTON1             = 0x05, //< X Button 1
        VK_XBUTTON2             = 0x06, //< X Button 2
    };
    
    KeyEvent (byte keyEvent);
    /*< Constructs a KeyEvent from the given VK keyboard code. */
    
    byte getVKCode ();
    /*< Gets the VK code of the event. */
    
    inline void print(_::Log& log);
    /*< Prints this object to a Terminal. */
    
    private:
    
    byte key;   //< The VK keybaord code of the event.
};
}   //< _
