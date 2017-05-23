/** Kabuki Theater
    @file    /.../Source/_Theater/MIDI/MIDIMap.hpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2017 Cale McCollough <https://calemccollough.github.io>

                            All right reserved  (R).

        Licensed under the Apache License, Version 2.0  (the "License"); you may
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

#include <KabukiTheater-Config.hpp>

namespace _Theater { namespace MIDI {

/** Class that remaps MIDI Parameters to other specified values.
*/
class _KabukiTheater_ MIDIMap
{
      public:

    MIDIMap ();
    /*< Constructs a blank MIDI map. */

    void mapParam  (int index, byte input, const byte* output);
    /*< Remaps the input parameter to the outputAddress I2P escpape sequence.
        @param index  The index of the param to remap.
        @param input  The MIDI input to remap.
        @param output The I2P address of the remapped MIDI device.
    */

    private:

    byte in[128];                   //< MIDI input channels to remap.
    const byte* out[128];           //< Remapped MIDI output channels.
};
}   //< namespace MIDI
}   //< namespace _Theater
