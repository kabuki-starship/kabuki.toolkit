/** Kabuki Toolkit
    @version 0.x
    @file    ~/source/script/ascii.h
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2017 Cale McCollough <calemccollough@gmail.com>;
             All right reserved (R). Licensed under the Apache License, Version 
             2.0 (the "License"); you may not use this file except in 
             compliance with the License. You may obtain a copy of the License 
             [here](http://www.apache.org/licenses/LICENSE-2.0). Unless 
             required by applicable law or agreed to in writing, software
             distributed under the License is distributed on an "AS IS" BASIS,
             WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
             implied. See the License for the specific language governing 
             permissions and limitations under the License.
*/

#include <stdafx.h>
#include "ascii.h"

namespace _ {

#if USE_MORE_ROM
const char* AsciiText (AsciiCode ascii_char) {
    static const char* kTexts[] = {
        "NUL",
        "SOH",
        "STR",
        "ETX",
        "EOT",
        "ENQ",
        "ACK",
        "BEL",
        "BS",
        "TAB",
        "LF",
        "VT",
        "FF",
        "CR",
        "SO",
        "SI",
        "DLE",
        "DC1",
        "DC2",
        "DC3",
        "DC4",
        "NAK",
        "SYN",
        "ETB",
        "CAN",
        "EM",
        "SUB",
        "ESC",
        "FS",
        "GS",
        "RS",
        "US"
    };
    static const char kInvalidText[] = "Invalid\0";
    // Compiler says this will always be false but I thought it enum as signed int?
    //if (ascii_char < 0)
    //    return kInvalidText;
    if (ascii_char > 31) {
        if (ascii_char != 127)
            return kInvalidText;
        return "DEL";
    }
    return kTexts[ascii_char];
}
#endif  //< USE_MORE_ROM

}       //< namespace ascii