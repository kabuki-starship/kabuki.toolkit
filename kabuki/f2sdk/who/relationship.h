/* Kabuki Toolkit
    @file    $kabuki-toolkit/library/kt/id/relationship.h
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2014-2017 Cale McCollough <calemccollough.github.io>;
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

#pragma once
#include <pch.h>
#if MAJOR_SEAM > 2 || MAJOR_SEAM == 2 && MINOR_SEAM >= 2
#ifndef HEADER_FOR_KT_ID_RELATIONSHIP
#define HEADER_FOR_KT_ID_RELATIONSHIP

#include "entity.h"

namespace _ {

/* A relationship node between . */
class KABUKI Relationship {
 public:
  /* Default constructor. */
  Relationship();

  /* Prints this object to a expression. */
  void Print(Log& log);

 private:
  const char* type_;
  Entity *a, *b;
};
}       // namespace _
#endif  //< HEADER_FOR_KT_ID_RELATIONSHIP
#endif  //< #if MAJOR_SEAM > 2 || MAJOR_SEAM == 2 && MINOR_SEAM >= 2