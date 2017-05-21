/** Kabuki Theater
    @file    /.../Source-Impl/_Math/Polar.cpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2017 Cale McCollough <https://calemccollough.github.io>

                            All right reserved (R).

        Licensed under the Apache License, Version 2.0 (the "License"); you may
        not use this file except in compliance with the License. You may obtain
        a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
*/

#include <math.hpp>

#include <_Math/Polar.hpp>

namespace _Math {

Polar::Polar (Type angle, Type radius)
:   angle (angle),
    radius (radius)
{
}

Type Polar::calcMagnitude ()
{
    Type angle = angle,
        radius = radius;
    return sqrt (angle * angle + radius * radius);
}

void Polar::print (Terminal& slot)
{

}

Polar_d::Polar_d (double angle, double radius)
:   angle (angle),
    radius (radius)
{
}

double Polar_d::calcMagnitude ()
{
    double angle = angle,
        radius = radius;
    return sqrt (angle * angle + radius * radius);
}

void Polar_d::print (Terminal& slot)
{
    slot.prints ("Polar_d: ");
}

}   //  _Math