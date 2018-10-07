/* Kabuki Toolkit
@version 0.x
@file    /kabuki-toolkit/kabuki/f2/socket.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2017 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#pragma once
#include <pch.h>
#if SEAM >= SEAM_00_00_01__01
#ifndef INCLUDED_KABUKI_F2_KABUKI_SOCKET
#define INCLUDED_KABUKI_F2_KABUKI_SOCKET

#include "align.h"
#include "binary.h"

namespace _ {

template <intptr_t kSize_, int kBoundaryBitCount_>
class TSocket {
 public:
  enum {
    kSize = kSize_,  //< Size of the buffer aligned.
    // Size with extra bytes to align to word boundary.
    kSizeUnaligned = kSize + kBoundaryBitCount_,
    // Number of bits of the word boundary to align to.
    kBoundaryBitCount = kBoundaryBitCount_,
  };

  /* Gets the begin byte of the socket. */
  char* Begin() { return reinterpret_cast<char*>(buffer); }

  /* Gets the begin byte of the socket. */
  char* End() { return reinterpret_cast<char*>(buffer) + kSizeUnaligned; }

  template <typename T>
  inline T* Start() {
    return reinterpret_cast<T*>(AlignUp(buffer, kBoundaryBitCount));
  }

 private:
  uintptr_t buffer[kSizeUnaligned];
};

/* @group ::_::Socket */

/* Syntactical sugar for reinterpret_cast using templates. */
template <typename T>
inline T* Ptr(void* ptr) {
  return reinterpret_cast<T*>(ptr);
}

/* Syntactical sugar for reinterpret_cast using templates. */
template <typename T>
inline T* Ptr(const void* ptr) {
  return reinterpret_cast<T*>(ptr);
}

/* Utility function for syntactical sugar creating a pointer from a base plus
offset.
@return Pointer of the type specified by template parameter T.
@param base The base address.
@param offset The offset.
*/
template <typename T>
inline T* Ptr(const void* begin, intptr_t offset) {
  return reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(begin) + offset);
}

/* Creates a new buffer of the given size or deletes it. */
template <typename Size = int32_t>
uintptr_t* New(uintptr_t* buffer, intptr_t size) {
  size = AlignUp(size);
  return new uintptr_t[size >> kWordBitCount];
}

}  // namespace _

#endif  //< INCLUDED_KABUKI_F2_KABUKI_SOCKET
#endif  //< #if SEAM >= SEAM_00_00_01__01
