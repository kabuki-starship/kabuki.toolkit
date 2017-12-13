/** Kabuki Toolkit
    @file       ~/source/kabuki/cards/player.h
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

#ifndef HEADER_FOR_KABUKI_BLACKJACKAIPLAYER
#define HEADER_FOR_KABUKI_BLACKJACKAIPLAYER

#include "blackjack_player.h"

namespace kabuki { namespace cards {

/** A player in a Blackjack game. */
class BlackjackPlayerAi : public BlackjackPlayer {
    public:

    enum States {
        kStateWaitingToJoin = 0, //< State when player is waiting to join.
        kStatePlayingRound  = 1, //< State when player is playing normally.
        kStateHolding       = 2, //< State when player is holding.
        kStateOutOfGame     = 3  //< State when player has lost game.
    };

    /** Default Constructor. */
    BlackjackPlayerAi (id::User* user, CardStack& stock);

    /** Destructor. */
    virtual ~BlackjackPlayerAi ();

    /** Attempts to take a card from the Deck for a player.
        @pre    The Deck must not be empty.
        @pre    The player must have a max hand score of 21. */
    void PlayRound () override;

    /** Handles Text input.
        @param text     Beginning of the Text buffer. 
        @param text_end End of the Text buffer.
        @return Returns nil upon success and an error string upon failure. */
    const char* Do (const char* text,
                            const char* text_end) override;

};
}       //< namespace cards
}       //< namespace kabuki
#endif  //< HEADER_FOR_KABUKI_BLACKJACKAIPLAYER
