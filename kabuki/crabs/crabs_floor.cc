/* Kabuki Toolkit
@version 0.x
@file    $kabuki-toolkit/kabuki/crabs/floor.h
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
#include "align.h"
#include "clock.h"
#include "floor.h"

namespace _ {

Floor* FloorInit() {
  static char buffer[sizeof(Floor) + 64];
  Floor* floor = AlignUp<Floor>(buffer);
  floor->epoch = kClockEpochInit;
  return floor;
}

Floor* Global() {
  static Floor* floor = FloorInit();
  return floor;
}

}  // namespace _