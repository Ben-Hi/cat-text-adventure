/**********************************************************
 * * Program name:  Kitchen.cpp
 * * Author:        Benjamin Hillen
 * * Date:          8 December 2019
 * * Description:   Definition of the Kitchen space,
 * *                derives from Space, holds the Catnip
 * *                Item, which is required to win the
 * *                game, as the player cannot catch
 * *                Sergeant Kib without it. specialAction
 * *                has the user plug their nose or fail
 * *                the game.
**********************************************************/

#include "Kitchen.hpp"
#include "Catnip.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

Kitchen::Kitchen()
{
    left = NULL;

    right = NULL;

    top = NULL;

    bottom = NULL;

    Catnip* startingCatnip = new Catnip;

    roomItems.addItem(startingCatnip);

    identity = "KITCHEN";

    travelTime = 2;
}

Kitchen::~Kitchen()
{
}

/******************************************************
 * *            printTravelDescription()
 * * Same as Bedroom::printTravelDescription() but
 * * text changed to describe kitchen
******************************************************/
void Kitchen::printTravelDescription()
{
    cout << "a door with the distinct odor of food wafting through (2 time units).";
}

/*************************************************************
 * *                    specialAction()
 * * User must enter 1 to plug their nose and block out the
 * * stench of the kitchen. Returns true if the user enters
 * * 1, false if they enter 2.
**************************************************************/
int Kitchen::specialAction()
{
    std::string userInput = "";

    cout << "\n\nSTANKIEST OF STENCHES\n\n";

    cout << "  ____________________________________________________________________\n";    
    cout << "/|    |__I__I__I__I__I__I__I__I__I_|       _-       %       %         |\\ \n";
    cout << " | _- |_I__I__I__I__I__I__I__I__I__|-_              %       %     _-  | \n"; 
    cout << " |    |__I__I__I__I__I__I__I__I__I_|                %       %         | \n";
    cout << " |  - |_I__I__I__I__I__I__I__I__I__|               ,j,      %w ,      | \n";
    cout << " | -  |__I__I__I__I__I__I__I__I__I_|  -_ -        / ) \\    /%mMmMm.   | \n";
    cout << " |    |_I__I__I__I__I__I__I__I__I__|             //|  |   ;  `.,,'    | \n";
    cout << " |-_- /                            \\             w |  |   `.,;`       | \n";
    cout << " |   /                              \\    -_       / ( |    ||         | \n";
    cout << " |  /                                \\           //\\_'/    (.\\    -_  | \n";
    cout << " | /__________________________________\\          w  \\/   -  ``'       | \n";
    cout << " | |__________________________________|                               | \n";
    cout << " |    |   _______________________   |     _-            -             | \n";
    cout << " |_-  |  |                       |  |                        _-       | \n";
    cout << " |    |  |                     _ |  |  T  T  T  T  T                  | \n";
    cout << " | _-_|  |    __.'`'`'`''`;__ /  |  |  |  |  |  |  |        _-     -  | \n";
    cout << " |    |  | _/U  `'.'.,.,\".'  U   |  |  | (_) |  |  |                  | \n";
    cout << " |    |  |   |               |   |  | / \\    @ [_]d b    _@_     |    | \n";   
    cout << " |    |  |   |      `', `,   |   |  | |_|   ____         [ ]     |    | \n";
    cout << " |_-  |  |   |   `') ( )'    |   |  | ______\\__/_________[_]__   |    | \n"; 
    cout << " |    |  |   |____(,`)(,(____|   |  |/________________________\\  |    | \n";
    cout << " |    |  |  /|   `@@(@@)@)'  |\\  |  | ||            _____   ||   |    | \n";
    cout << " |    |  | //!\\  @@)@@)@@@( /!\\ |  | ||   _--      \\   /   ||  /|\\   | \n";
    cout << " |__lc|__|/_____________________\\|__|_||____________/###\\___||_|||||__| \n";
    cout << "/ -_  _ -      _ -   _-_    -  _ - _ -|| -_    _  - \\___/_- || |||||-_ \\ \n\n";

    cout << "Sweet mother of kibble, what is that smell?! You knew that you hadn't had the chance\n";
    cout << "to clean your kitchen in...well a few weeks, but this is absolutely rancid. You start\n";
    cout << "to feel a little queasy...\n\n";

    cout << "1. Plug your nose\n";
    cout << "2. Try to breathe deeply\n\n";

    //loop ask for user reaction
    do
    {
        cout << "Reaction: ";

        getline(cin, userInput);
    } while (userInput != "1" && userInput != "2");

    //user plugs nose, 0 minute penalty
    if (userInput == "1")
    {
        cout << "\n\nWith great difficulty, you manage to block out some of the foul odor by\n";
        cout << "pinching your nose closed. Promising yourself to at least run the dishwasher\n";
        cout << "when you get back, you let your eyes sweep over the kitchen...\n\n";

        do
        {
            cout << "[Press enter to continue]";

            getline(cin, userInput);
        } while (userInput.length() != 0);

        return 0;
    }

    //user doesn't plug nose, 5 minute penalty
    else if (userInput == "2")
    {
        cout << "\n\nYou try to take a few deep breaths to calm yourself, but find that this only\n";
        cout << "invites a greater stench to permeate your entire nasal cavity. Despite your valiant\n";
        cout << "effort, you soon keel over into unconsciousness from the rank smell. By the time you\n";
        cout << "awake, several minutes have passed due to your lack of hygiene...\n\n";

        do
        {
            cout << "[Press enter to continue]";

            getline(cin, userInput);
        } while (userInput.length() != 0);

        return 5;
    }
}

/***********************************************************
 * *                    describeSpace()
 * * Prints flavor text describing the kitchen space
***********************************************************/
void Kitchen::describeSpace()
{
    std::string userInput = "";

    do
    {
        cout << "\033[2J\033[1;1H";

        cout << "YOUR KITCHEN\n\n";

        cout << "Hurgh...Definitely left some old tuna out on the counter a few nights ago, what a stench!\n";
        cout << "Holding your nose, you gaze around the rest of your kitchen, noting a few pots out of place\n";     
        cout << "and the fridge in the corner. Maybe the fridge has something useful inside?\n\n";
        cout << "[Press Enter to continue]";

        getline(cin, userInput);
    } while (userInput.length() != 0);
}