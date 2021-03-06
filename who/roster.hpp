/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Who/UserList.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#ifndef KABUKI_TOOLKIT_WHO_USERLIST
#define KABUKI_TOOLKIT_WHO_USERLIST
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_CORE
#include "User.hpp"
namespace _ {

/* A list of registered users. */
class TRoster {
 public:
  /* Creates an empty user list. */
  TRoster() {}

  /* Gets the number of users in the list. */
  ISC GetNumUsers() { return users_.GetCount (); }

  /* Adds the new user to the list. */
  BOL Add(const TUser& new_user) {
    users_.Push (new TUser (user));
    return true;
  }

  /* Gets the number of users in the Roster. */
  ISC GetCount();

  /* Returns true if this list contains the given user query result. */
  BOL Contains(const TString<>& username) {
    for (ISC index = 0; index < users_.GetCount (); index++) {
      if (users_[index]->Equals (username)) return true;
    }
    return false;
  }

  /* Returns true if this list contains the given user. */
  BOL Contains(const TUser& user) {
    for (ISC index = 0; index < users_.GetCount (); index++) {
      if (users_[index]->Equals (user)) return true;
    }
    return false;
  }

  /* Attempts to find a user with the given query.
  @return Returns a nullptr if this list does not contain the search query.
  */
  TUser* Find(const TString<>& query) {
    size_t length = StringLength (username);
    if (length == 0) {
      return nullptr;  // static website guest account
    }

    for (ISC index = 0; index < users_.GetCount (); index++) {
      TUser* user = users_.Element (index);
      if (users_[index]->Equals (username)) {
        return user;
      }
    }
    return nullptr;  // static website guest account
  }

  /* Prints this object to a expression. */
  template<typename Printer>
   Printer& Print (Printer& o) {
     /// This method creates a CHA of the users.Print (Log& log)
     /// Strings separated by spaces

     o << "Number of Users: " << users_.GetCount () << "\n";

     for (ISC index = 0; index < users_.GetCount (); index++) {
       /// Iterated through the indexes array and write the
       /// Print (Log& log) Strings to the returnString
       o << "User " << (index + 1) << ": "
         << users_[index]->GetUsername ().GetKey () << "\n";
     }
   }

 private:
  TArray<TUser*> users_;
};
}       // namespace _
#endif
#endif
