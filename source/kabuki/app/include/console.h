/** Kabuki Starship
    @file    /.../Source/app/IKeyListener.h
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

#ifndef KABUKI_THEATER__CONSOLE_H
#define KABUKI_THEATER__CONSOLE_H

#include <config.h>

namespace app {

int WindowsConosleColoredTextExampleMain ()
{
	const WORD colors[] =
		{
		0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
		0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
		};

	HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
	WORD   index   = 0;

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( hstdout, &csbi );

	// Tell the user how to stop
	SetConsoleTextAttribute( hstdout, 0xEC );
	std::cout << "Press any key to quit.\n";

	// Draw pretty colors until the user presses any key
	while (WaitForSingleObject( hstdin, 100 ) == WAIT_TIMEOUT)
	{
		SetConsoleTextAttribute( hstdout, colors[ index ] );
		std::cout << "\t\t\t\t Hello World \t\t\t\t" << std::endl;
		if (++index > sizeof(colors)/sizeof(colors[0]))
			index = 0;
	}
	FlushConsoleInputBuffer( hstdin );

	// Keep users happy
	SetConsoleTextAttribute( hstdout, csbi.wAttributes );
	return 0;
}
}       //<  namespace app
#endif  //< KABUKI_THEATER__CONSOLE_H