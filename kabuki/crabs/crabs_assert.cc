/* Kabuki Toolkit
@version 0.x
@file    $kabuki-toolkit/library/crabs/crabs_assert.h
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2017 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#include <stdafx.h>
#include <cstdio>
#include <cstdlib>
#include "assert.h"

namespace _ {

void Pause() { system("PAUSE"); }

bool AssertDisplay(int line, const char* file) {
  printf("\nError at line %d in \"%s\"", line, file);
  Pause();
  return true;
}

bool Assert(bool condition) { return !condition; }

bool AssertHandle() {
  printf("\nAssertion failed at line %d in \"%s\"", __LINE__, __FILE__);
  while (1)
    ;
}

}  // namespace _