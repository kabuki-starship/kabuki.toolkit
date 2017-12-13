/** Kabuki Toolkit
    @version 0.x
    @file    ~/source/kabuki/script/global.h
    @author  Cale McCollough <calemccollough.github.io>
    @license Copyright (C) 2017 Cale McCollough <calemccollough@gmail.com>;
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
#include <stdafx.h>

#ifndef HEADER_FOR_PROJECTS_SCRIPT_GLOBAL
#define HEADER_FOR_PROJECTS_SCRIPT_GLOBAL

#include "../global.h"

using namespace _;

/* Test Operand for multiple unit tests.
    The name ChildOperand does not mean anything other than it is a child.  */
class ChildOperand : public Operand {
    public:
    

    /** Handles Script Commands.
        @param text     Beginning of the Text buffer. 
        @param text_end End of the Text buffer.
        @return Returns nil upon success and an error string upon failure. */
    virtual const char* Do (const char* text,
                                    const char* text_end) {
        return nullptr;
    }
    
    // Chinese Room operations.
    virtual const Operation* Star (uint index, Expression* expr) {
        void* args[2];

        static const Operation This = { "Child",
            NumOperations (2), OperationFirst ('A'),
            "A child Operand." };

        switch (index) {
            case '?': return &This;
            case 'A': {
                static const Operation OpA = { "SignedIntegerTests",
                    Params<2, UI1, STR, kTextBufferSize> (),
                    Params<2, UI1, STR> (),
                    "Description of function \'A\'.", 0 };
                if (!expr) return &OpA;

                if (ExprArgs (expr, OpA.params, 
                          Args (args, &test_ui1_, test_str_)))
                    return expr->result;
                    
                // Function logic here

                return ExprResult (expr, OpA.result, Args (args, &test_ui1_,
                                                       test_str_));
            }
            case 'B': {
                static const Operation OpB = { "FloatTests",
                    Params<2, FLT, STR, kTextBufferSize> (),
                    Params<2, FLT, STR> (),
                    "Description of function \'B\'.", 0 };
                if (!expr) return &OpB;

                if (ExprArgs (expr, OpB.params, Args (args, &test_flt_,
                          test_str_)))
                    return expr->result;

                return ExprResult (expr, OpB.result, Args (args, &test_flt_,
                                                       test_str_));
            }
            case _::DEL: {

                break;
            }
        }
        return nullptr;
    }
    
    private:

    enum {
        kTextBufferSize = 16         //< Example string buffer size.
    };

    uint8_t test_ui1_;                 //< Text UI1.
    float test_flt_;                   //< Test FLT.
    char test_str_[kTextBufferSize]; //< Test STR.
};

// Test child Operand.
class Parent : public Operand {
    public:

    enum {
        kTextBufferSize = 16         //< Example string buffer size.
    };

    /** Handles Script Commands.
        @param text     Beginning of the Text buffer. 
        @param text_end End of the Text buffer.
        @return Returns nil upon success and an error string upon failure. */
    virtual const char* Do (const char* text,
                                    const char* text_end) {
        return nullptr;
    }

    // Interprocess operations.
    virtual const Operation* Star (uint index, Expression* expr) {
        void* args[2];

        static const Operation This = { "Parent",
            NumOperations (4), OperationFirst ('A'),
            "Root scope device.", 0 };

        switch (index) {
            case '?': return &This;
            case 'A': {
                if (!expr) return child_a.Star ('?', expr);
                return Push (expr, &child_a);
            }
            case 'B': {
                if (!expr) return child_b.Star ('?', expr);
                return Push (expr, &child_b);
            }
            case 'C': {
                static const Operation OpC = { "FloatTests",
                    Params<2, FLT, STR, kTextBufferSize> (),
                    Params<2, FLT, STR> (),
                    "Description of functionA.", 0 };
                if (!expr) return &OpC;

                if (ExprArgs (expr, OpC.params, Args (args, &io_number_,
                                                       io_string_)))
                    return expr->result;
                  // function call here
                return ExprResult (expr, OpC.result, Args (args, &io_number_,
                                                   io_string_));
            }
            case 'D': {
                static const Operation OpD = { "SignedIntegerTests",
                    Params<2, FLT, STR, kTextBufferSize> (),
                    Params<2, FLT, STR> (),
                    "Description of functionB.", 0 };

                if (!expr) return &OpD;

                if (ExprArgs (expr, OpD.params, Args (args, &io_number_,
                                                 io_string_)))
                    return expr->result;

                return ExprResult (expr, OpD.result, Args (args, &io_number_,
                                                      io_string_));
            }
        }
        return nullptr;
    }

    private:
    
    ChildOperand child_a,                //< ChildOperand Expression in index 'A'.
                 child_b;                //< ChildOperand Expression in index 'B'
    float io_number_;                    //< Example variable.
    char  io_string_[kTextBufferSize]; //< Example string.
};

// A test room that can fit in 1KB of RAM. 
class This : public Room {
    public:

    enum {
        kRoomSize = 1024
    };

    This ():
        Room ("Test")
    {
        
    }

    // Interprocess operations.
    virtual const Operation* Star (uint index, Expression* expr) {
        static const Operation This = { "Room",
            NumOperations (1), OperationFirst ('A'),
            "Root scope device.", 0 };

        switch (index) {
            case '?': return &This;
            case 'A': {
                if (!expr) return parent.Star ('?', nullptr);
                return Push (expr, &parent);
            }
            default: {
            }
        }
        return nullptr;
    }

    private:

    Parent parent;
};

#endif  //< HEADER_FOR_PROJECTS_SCRIPT_GLOBAL
