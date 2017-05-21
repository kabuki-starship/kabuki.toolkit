////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2016 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_JOYSTICKMANAGER_HPP
#define SFML_JOYSTICKMANAGER_HPP

#include <_HMI/Joystick.hpp>
#include <_HMI/JoystickImpl.hpp>
#include <_/NonCopyable.hpp>


namespace _HMI { namespace priv {

class JoystickManager : NonCopyable
/*< Global joystick manager. */
{
    public:

    static JoystickManager& getInstance();
    /*< Get the global unique instance of the manager
       
        @return Unique instance of the joystick manager. */

    const JoystickCaps& getCapabilities(uint joystick) const;
    /*< Get the capabilities for an open joystick
       
        @param joystick Index of the joystick
       
        @return Capabilities of the joystick. */

    const JoystickState& getState(uint joystick) const;
    /*< Get the current state of an open joystick
       
        @param joystick Index of the joystick
       
        @return Current state of the joystick. */

    const Joystick::Identification& getIdentification(uint joystick) const;
    /*< Get the identification for an open joystick
       
        @param joystick Index of the joystick
       
        @return Identification for the joystick. */

    void update();
    /*< Update the state of all the joysticks. */

    private:

    JoystickManager();
    /*< Default constructor. */

    ~JoystickManager();
    /*< Destructor. */

    struct Item
    /*< Joystick information and state. */
    {
        JoystickImpl             joystick;       ///< Joystick implementation
        JoystickState            state;          ///< The current joystick state
        JoystickCaps             capabilities;   ///< The joystick capabilities
        Joystick::Identification identification; ///< The joystick identification
    };
    
    Item m_joysticks[Joystick::Count];      ///< Joysticks information and state
};

} // namespace priv
} // namespace _HMI


#endif // SFML_JOYSTICKMANAGER_HPP