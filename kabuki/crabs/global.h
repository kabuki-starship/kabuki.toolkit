/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki/crabs/global.h
@author  Cale McCollough <cale.mccollough@gmail.com>
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
#ifndef INCLUDED_CRABS_GLOBAL
#define INCLUDED_CRABS_GLOBAL
// Dependencies:

#include "../f2/global.h"

#include <kabuki/f2/ascii.h>
#include <kabuki/f2/str.h>
#include <kabuki/f2/tarray.h>
#include <kabuki/f2/tlst.h>
#include <kabuki/f2/tmap.h>
#include <kabuki/f2/tstk.h>

#if SEAM >= SEAM_00_00_00__00_02
#include "bsq.h"
//#include "multimap.h"
//#include "dictionary.h"
#endif

#if SEAM >= SEAM_00_00_00__00_03
#include "clock.h>
#include "socket.h"
#endif

#if SEAM >= SEAM_00_00_00__00_03
#include "address.h"
#include "args.h"
#include "bin.h"
#include "bout.h"
#include "event.h"
#include "expr.h"
#include "interrupts.h"
#include "op.h"
#include "room.h"
#include "slot.h"
#endif

#if SEAM >= SEAM_00_00_00__00_04
#include "library.h"
#endif
// End dependencies.

#endif  //< INCLUDED_CRABS_GLOBAL
