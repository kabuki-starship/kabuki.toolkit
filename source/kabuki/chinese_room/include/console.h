/** The Chinese Room
    @version 0.x
    @file    ~/source/kabuki/chinese_room/include/console.h
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2017 Cale McCollough <calemccollough.github.io>;
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

#ifndef CHINESE_ROOM_CONSOLE_H
#define CHINESE_ROOM_CONSOLE_H

#include "room.h"
#include "mirror.h"
#include "table.h"
#include "set.h"
#include "utils.h"
#include "expression.h"

namespace _ {

/** Reads a single char from the keyboard 
    @param header The header to print. */
KABUKI char ReadChar (const char* header);

/** Reads an int from the keyboard.
    @param header The header to print. 
    @param number The number to read. */
KABUKI int ReadInt (const char* header);

/** Reads a float from the keyboard. 
    @param header The header to print. 
    @param number The number to read. */
KABUKI float ReadFloat (const char* header);

/** Reads a new string from the keyboard.
    @header The header to print.
    @return Returns a new string that you have to delete. */
KABUKI char* ReadString (const char* header, int buffer_size);

/** Reads a new string from the keyboard.
    @param  header      The header to print.
    @param  buffer      A buffer to read keyboard input to.
    @param  buffer_size The size of the buffer.
    @return Returns a new string that you have to delete. */
KABUKI void ReadString (const char* header, char* buffer, int buffer_size);
  
/** A text Console.
    @todo Write me!
*/
class Console: public Room
{
    public:

    /** Constructs a Console. */
    Console ();

    /** Destructor. */
    virtual ~Console ();

    /** Sets a the Room. */
    virtual ticket_t Init ();

    /** Main process loop. */
    virtual ticket_t Loop ();

    /** Chinese room expressions. */
    virtual const Operation* Star (int index, Expression* expr);

    private:

    // 2-to-4-byte vtable pointer here in memory!
  
};

}       //< namespace _
#endif  //< CHINESE_ROOM_CONSOLE_H