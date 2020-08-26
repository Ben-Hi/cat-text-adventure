/*******************************************************************
 * * Program name: 	Bedroom.cpp
 * * Author:		Benjamin Hillen
 * * Date: 		    5 December 2019
 * * Description: 	Definition of the Bedroom class, derives from
 * *                the Space class, overrides appropriate methods
 * *                to inform the player about the Bedroom. The
 * *                Bedroom specialAction is called at the start
 * *                of the game. The player must dodge the falling
 * *                bookshelf or they will lose.
*******************************************************************/

#include "Bedroom.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Bedroom::Bedroom()
{
    top = NULL;

    bottom = NULL;

    left = NULL;

    right = NULL;

    Item* startingShoes = new Shoes;

    roomItems.addItem(startingShoes);

    identity = "BEDROOM";

    travelTime = 2;
}

Bedroom::~Bedroom()
{
}

/*******************************************************
 * *            printTravelDescription()
 * * Prints out flavor text describing the travel path
 * * to the Bedroom Space. No functionality other than
 * * game immersion.
*******************************************************/
void Bedroom::printTravelDescription()
{
    cout << "a well-worn door with your name bolted to the front of it. (2 time units)";
}

/*******************************************************
 * *                describeSpace()
 * * Prints flavor text describing the Bedroom Space,
 * * no functionality other than game immersion.
*******************************************************/
void Bedroom::describeSpace()
{
    std::string userInput = "";

    do
    {
        cout << "\033[2J\033[1;1H";

        cout << "YOUR BEDROOM\n\n";

        cout << "As you peer around in suspicion, you can't quite shake the feeling that...oh wait.\n";
        cout << "This is your bedroom. Ok, so maybe some memory problems going on, but oh well. Did you\n";     
        cout << "at least remember to put on your shoes?\n\n";

        cout << "[Press Enter to continue]";

        getline(cin, userInput);
    } while (userInput.length() != 0); 
}

/***************************************************************
 * *                    specialAction()
 * * When the user first starts the game or re-enters the
 * * Bedroom, they will be given flavor text describing a 
 * * bookcase falling toward them. The user is allowed to choose
 * * between three reactions by entering the appropriate integer.
 * * Returns true if the user enters 1, returns false if they
 * * enter 2 or 3.
****************************************************************/
int Bedroom::specialAction()
{
    std::string userInput = "";

    //print flavor text and possible reactions
    cout << "\n\nBALLISTIC BIBLIOGRAPHY\n\n";

    cout << " _________________________________________________________\n";
    cout << "||-------------------------------------------------------||\n";
    cout << "||.--.    .-._                        .----.             ||\n";
    cout << "|||==|____| |H|___            .---.___|""""|_____.--.___ ||\n";
    cout << "|||  |====| | |xxx|_          |+++|=-=|_  _|-=+=-|==|---|||\n";
    cout << "|||==|    | | |   | \\         |   |   |_\\/_|Black|  | ^ |||\n";
    cout << "|||  |    | | |   |\\ \\   .--. |   |=-=|_/\\_|-=+=-|  | ^ |||\n";
    cout << "|||  |    | | |   |_\\ \\_( oo )|   |   |    |Magus|  | ^ |||\n";
    cout << "|||==|====| |H|xxx|  \\ \\ |''| |+++|=-=|""""|-=+=-|==|---|||\n";
    cout << "||`--^----'-^-^---'   `-' ""  '---^---^----^-----^--^---^||\n";
    cout << "||-------------------------------------------------------||\n";
    cout << "||-------------------------------------------------------||\n";
    cout << "||               ___                   .-.__.-----. .---.||\n";
    cout << "||              |===| .---.   __   .---| |XX|<(*)>|_|^^^|||\n";
    cout << "||         ,  /(|   |_|III|__|''|__|:x:|=|  |     |=| Q |||\n";
    cout << "||      _a'{ / (|===|+|   |++|  |==|   | |  |Illum| | R |||\n";
    cout << "||      '/\\\\/ _(|===|-|   |  |''|  |:x:|=|  |inati| | Y |||\n";
    cout << "||_____  -\\{___(|   |-|   |  |  |  |   | |  |     | | Z |||\n";
    cout << "||       _(____)|===|+|[I]|DK|''|==|:x:|=|XX|<(*)>|=|^^^|||\n";
    cout << "||              `---^-^---^--^--'--^---^-^--^-----^-^---^||\n";
    cout << "||-------------------------------------------------------||\n";
    cout << "||_______________________________________________________||\n\n";

    cout << "That dratted bookshelf of yours always was quite flimsy. You never bothered to bolt it properly\n";
    cout << "to the wall, and it looks like you might pay the price for that apathy, as a veritable ton of books\n";
    cout << "are now plummeting toward your head!!\n\n";

    cout << "1. Dodge\n";
    cout << "2. Stare in awe\n";
    cout << "3. Scream\n\n";

    //loop asking for the reaction until the user enters 1, 2, or 3
    do
    {
        cout << "Reaction: ";

        getline(cin, userInput);
    } while (userInput != "1" && userInput != "2" && userInput != "3");

    //user chooses to dodge, they succeed at the specialAction,
    //return true
    if (userInput == "1")
    {
        cout << "\nQuickly recollecting yourself, you lunge out of the way of the book bombardment!\n";
        cout << "Heaving up to your feet, you brush off some dust and gaze around the bedroom...\n";

        do
        {
            cout << "[Press enter to continue]";

            getline(cin, userInput);
        } while (userInput.length() != 0);

        return 0;
    }

    //the user fails to dodge, return false
    else if (userInput == "2")
    {
        cout << "\nToo intrigued by the plummeting cacophany of shelves, you gaze slack-jawed at your\n";
        cout << "incoming doom until you are promptly buried by books. By the time you free yourself,\n";
        cout << "several minutes have gone by, hopefully Sergeant Kib is still around somewhere...\n\n";

        do
        {
            cout << "(3 minutes have passed)\n";
            cout << "[Press Enter to continue]";

            getline(cin, userInput);
        } while (userInput.length() != 0);

        return 3;
    }

    //the user fails to dodge, return false
    else if (userInput == "3")
    {
        cout << "\nThe deluge of paper proves too much for your fragile mind, as you let out a piercing\n";
        cout << "wail of fear that will loom over your neighborhood for years to come. Some time later, you\n";
        cout << "snap back to consciousness under the mound of books. Swearing you'll fix that dratted shelf\n";
        cout << "later, you hope Sergeant Kib hasn't left for good while you were out...\n\n";

        do
        {
            cout << "(5 minutes have passed)\n";
            cout << "[Press Enter to continue]";

            getline(cin, userInput);
        } while (userInput.length() != 0);

        return 5;
    }
}