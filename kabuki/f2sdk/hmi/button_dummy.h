/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki/features/hmi/hmi_dummy_button.h
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
#if SEAM >= SEAM_00_03_00_00__00
#ifndef HEADER_FOR_KT_HMI_DUMMYBUTTON
#define HEADER_FOR_KT_HMI_DUMMYBUTTON

#include "button.h"
#include "button_event.h"

namespace _ {

/* A dummy Button that doesn't do anything. */
class API ButtonDummy : public Button {
 public:
  //< Creates a ButtonDummy with the initLabel.
  ButtonDummy(const char* initLabel = "");

  //< Action that gets performed when this button gets pressed.
  void Press(ButtonEvent buttonEvent);

  //< Action that gets performed when this button gets depressed.
  void Depress(ButtonEvent buttonEvent);

  //< Action that gets performed when this button gets double pressed.
  void DoublePress(ButtonEvent buttonEvent);

};  //< class ButtonDummy
}  // namespace _
#endif  //< HEADER_FOR_KT_HMI_DUMMYBUTTON
#endif  //< #if SEAM >= SEAM_00_03_00_00__00
