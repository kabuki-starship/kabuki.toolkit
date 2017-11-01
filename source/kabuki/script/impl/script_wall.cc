/** kabuki::script
    @version 0.x
    @file    ~/source/kabuki/script/impl/script_wall.cc
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

#include <stdafx.h>
#include "../include/wall.h"
#include "../include/utils.h"

namespace _ {

Wall::~Wall () {
    if (is_dynamic_) {
        byte* buffer = reinterpret_cast<byte*> (doors_);
        delete [] buffer;
    }
}

Wall::Wall (uint_t size_bytes) :
    is_dynamic_ (true) {
    size_bytes = size_bytes < kMinSizeBytes ? kMinSizeBytes : size_bytes;
    size_bytes = AlignSize64 (size_bytes);
    uint_t size_words = (size_bytes >> sizeof (uintptr_t)) + 3;
    uintptr_t* buffer = new uintptr_t[size_words],
             * aligned_buffer = WordAlign64 (buffer);
    //< Shift 3 to divide by 8. The extra 3 elements are for aligning memory
    //< on 16 and 32-bit systems.
    size_bytes -= sizeof (uintptr_t) * (aligned_buffer - buffer);
    buffer_ = buffer;
    doors_ = reinterpret_cast<TStack<Door*>*> (aligned_buffer);
    StackInit (buffer, size_bytes >> sizeof (uintptr_t));
}

Wall::Wall (uintptr_t* buffer, uint_t size_bytes) {
    byte* ptr     = reinterpret_cast<byte*> (buffer),
        * new_ptr = ptr + WordAlignOffset<uint64_t> (ptr),
        * end_ptr = ptr + size_bytes;
    uint_t size_words = (size_bytes >> sizeof (uintptr_t)) + 3;
    //< Computer engineering voodoo for aligning to 64-bit boundary.

    uintptr_t*aligned_buffer = WordAlign64 (buffer);
    //< Shift 3 to divide by 8. The extra 3 elements are for aligning memory
    //< on 16 and 32-bit systems.
    size_bytes -= sizeof (uintptr_t) * (aligned_buffer - buffer);
    buffer_ = buffer;
    doors_ = reinterpret_cast<TStack<Door*>*> (aligned_buffer);
    StackInit (buffer, size_bytes >> sizeof (uintptr_t));
}

Wall::Wall (TStack<Door*>* doors) {
    
}

TStack<Door*>* Wall::Doors () {
    return doors_;
}

Door* Wall::GetDoor (int index) {
    return 0;
}

int Wall::OpenDoor (Door* door) {
    return 0;

}

bool Wall::CloseDoor (int index) {
    return false;
}

void Wall::Print () {
    //printf ("\nDoor:\nis_dynamic %s\nnum_doors: %u\nmax_num_doors: %u\n", 
    //        is_dynamic ? "true" : "false", num_doors, max_num_doors);
}

}       //< namespace _
