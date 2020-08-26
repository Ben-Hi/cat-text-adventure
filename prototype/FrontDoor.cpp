/****************************************************************
 * * Program name:  FrontDoor.cpp
 * * Author:        Benjamin Hillen
 * * Date:          9 December 2019
 * * Description:   Declaration of the FrontDoor class,
 * *                prevents user from traveling to it unless
 * *                they have the Shoes item.
****************************************************************/

#include "FrontDoor.hpp"
#include "Shoes.hpp"
#include <iostream>

using std::endl;
using std::cout;
using std::cin;

FrontDoor::FrontDoor()
{
    left = NULL;

    right = NULL;

    top = NULL;

    bottom = NULL;

    identity = "FRONT DOOR";

    travelTime = 2;
}

FrontDoor::~FrontDoor()
{
}

/*********************************************************
 * *              hasRequiredItem(Inventory)
 * * Searches the passed inventory object for a Shoes
 * * Item.
*********************************************************/
bool FrontDoor::hasRequiredItem(Inventory playerItems)
{
    return playerItems.checkForItem("Shoes");
}

void FrontDoor::printTravelDescription()
{
    cout << "your front door. Best hope you have some shoes to protect your delicate feet,\n";
    cout << "otherwise you won't be walking out here (2 time units, Shoes required).";
}

/**************************************************************
 * *                    specialAction()
 * * User is allowed to try to charge the door, kick the handle,
 * * or turn the doorknob. Returns true if the user turns the
 * * knob, false if they do not.
**************************************************************/
int FrontDoor::specialAction()
{
    std::string userInput = "";

    cout << "\n\nDARN DIRTY DOOR\n\n";

    cout << "              ________\n";
    cout << "             / ______ \\n";
    cout << "             || _  _ ||\n";
    cout << "             ||| || |||\n";
    cout << "             |||_||_|||\n";
    cout << "             || _  _o|| (o)\n";
    cout << "             ||| || |||\n";
    cout << "             |||_||_|||      ^~^  , \n";
    cout << "             ||______||     ('Y') ) \n";
    cout << "            /__________\\    /   \\/ \n";
    cout << "    ________|__________|__ (\\|||/) _________\n";
    cout << "   hjw     /____________\\ \n";
    cout << "   `97     |____________| \n\n";

    cout << "As you confidently stride to your door, you bounce right off of it as you recall\n";
    cout << "that yes, doors do in fact need to be open before walking through them as a general\n";
    cout << "rule of thumb. Alas, your front door always did need a little work to get through it...\n\n";

    cout << "1. Shoulder charge the door\n";
    cout << "2. Crane kick the handle\n";
    cout << "3. Turn the knob\n\n";

    //loop ask for the player reaction
    do
    {
        cout << "Reaction: ";

        getline(cin, userInput);
    } while (userInput != "1" && userInput != "2" && userInput != "3");

    //player charges door, 5 minute penalty
    if (userInput == "1")
    {
        cout << "\nRemembering those old noire movies you liked to watch, you square up to the door\n";
        cout << "give it the ol' stink eye, and confidently ram your shoulder into the door. You are\n";
        cout << "then swiftly reminded that Newton and his Laws object to this sort of behavior, as\n";
        cout << "the door rams your shoulder back. Unprepared for this turn of events, you are sent\n";
        cout << "tumbling onto your rear, promptly knocking yourself out. When you come to, you can\n";
        cout << "only hope that Sergeant Kib hasn't decided to find an owner with a little more\n";
        cout << "door-savvy sense...\n\n";

        do
        {
            cout << "[Press enter to continue]";

            getline(cin, userInput);
        } while (userInput.length() != 0);

        return 5;
    }

    //plaer kicks handle, 3 minute penalty
    else if (userInput == "2")
    {
        cout << "\nAh yes, the classic Crane kick, what could possibly go wrong? With the confidence of\n";
        cout << "a master, you hold yourself in the poised stance of the Crane. As you snap your foot at\n";
        cout << "the handle, you are reminded that you are anything BUT a master, as your feet slip on the\n";
        cout << "entry rug and you are sent crashing to the ground. Sergeant Kib will be on the look for a\n";
        cout << "more graceful master unless you hurry up!\n\n";

        do
        {
            cout << "[Press enter to continue]";

            getline(cin, userInput);
        } while (userInput.length() != 0);

        return 3;
    }

    //player tries knob, 0 minute penalty
    else if (userInput == "3")
    {
        cout << "\nBrushing aside thoughts of grandeur, you try the knob on the door and find\n";
        cout << "that it turns easily. Swinging the door open, you prepare yourself and take one\n";
        cout << "final look around...\n\n";

        do
        {
            cout << "[Press enter to continue]";

            getline(cin, userInput);
        } while (userInput.length() != 0);

        return 0;
    }
}

void FrontDoor::describeSpace()
{
    std::string userInput = "";

    do
    {
        cout << "\033[2J\033[1;1H";

        cout << "THE FRONT DOOR\n\n";

        cout << "Yep, that's a door alright, your front door in fact. Beyond it lies the great road,\n";
        cout << "a peculiar expanse of concrete that you are quite certain seems to change every now and then,\n";
        cout << "not to mention the rather disturbing lack of houses along its path. You realize that\n";
        cout << "you have wasted quite enough time pondering and need to find Sergeant Kib a little faster.\n\n";
        
        cout << "[Press enter to continue]";

        getline(cin, userInput);
    } while (userInput.length() != 0);
}