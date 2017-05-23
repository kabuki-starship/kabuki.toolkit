/** Kabuki Theater
    @file    /.../Source/_Theater/HMI/ButtonScroller.hpp
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
 
#pragma once

#include <KabukiTheater-Config.hpp>

#include "Label.hpp"
#include "ButtonControl.hpp"

namespace _Theater { namespace HMI {

class _KabukiTheater_ ButtonScroller, public Label
/*< A scrollable array Button (s). */
{
    public:

    enum {
        DefaultNumVisibleButtons = 5,  //< The default number of visible numbers.
    };

    ButtonScroller (string newLabel = "", int newArraySize = DefaultNumVisibleButtons);
    //< Default constructor.
    
    ButtonScroller (const ButtonScroller& o);
    //< Copy constructor.

    vector<ButtonControl*>& buttons ();
    //< gets the array of buttons.

    int getNumButtons () const;
    //< gets the number of buttons in the array.

    int getNumVisibleButtons () const;
    //< gets the number of visible buttons.
    
    int getCurrentIndex () const;
    //< gets the index of the first visible button.

    void setNumVisibleButtons (int value);
    //< sets the number of visible buttons to the new value.

    void removeButton (int index);
    //< Removes the button at the given index from the array.

    void scrollUp ();
    //< Scrolls up the list.
    
    void scrollDown ();
    //< Scrolls down the list.

    void scrollUp (int numNodes);
    //< Scrolls up the list.
    
    void scrollDown (int numNodes);
    //< Scrolls down the list.

    void scrollPageUp ();
    //< Scrolls up one page
    
    void scrollPageDown ();
    //< Scrolls down one page

    int press (int index);
    //< Presses the Button at the specified index.
    
    inline void print(_::Log& log);
    /*< Prints this object to a terminal. */

    private:

    int currentIndex,                   //< The index of the first visible button.
        numVisibleButtons;              //< The number of physical buttons.

    vector<ButtonControl*> buttons;      //< The array of buttons.
};
}   //  _Theater/HMI


