/****************************************************
 * * Program name:  Road.cpp
 * * Author:        Benjamin Hillen
 * * Date:          10 December 2019
 * * Description:   Declaration of the road class,
 * *                each road has a random chance to
 * *                hold the cat in it. If the user
 * *                has the Catnip Item, they can
 * *                pickup the cat. The game ends
 * *                when the user picks up the cat.
*****************************************************/

#include "Road.hpp"
#include "Cat.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Road::Road()
{
    left = NULL;

    right = NULL;

    top = NULL;

    bottom = NULL;

    int chance = rand() % 10 + 1;

    //60% chance for the road to start with
    //a Cat Item
    if (chance >= 5)
    {
        Cat* sergeantKib = new Cat;

        roomItems.addItem(sergeantKib);
    }

    identity = "ROAD";

    travelTime = 2;
}

Road::~Road()
{
}

/*************************************************************
 * *                specialAction()
 * * A neighborhood rascal confronts the player. If the player
 * * punches him, return false. If the player tells him a joke,
 * * return true
*************************************************************/
int Road::specialAction()
{
    std::string userInput = "";

    cout << "BUNGLE IN THE CONCRETE JUNGLE\n\n";

    cout << " ___  ,--.  __________________________/   ,   /_______\n";
    cout << "    'O---O'~\n";
    cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _   ,--.   _ _ _ _ _\n";
    cout << "         _____                       ~'O---O'\n";
    cout << " _______< Home|_____        __________________________\n\n";
    cout << "           ||      /   ,   /\n";

    cout << "While you sprinted down the road trying to find Sergeant Kib, you thought you heard\n";
    cout << "an aggravated 'meow' come from just ahead. As you approach, you notice one of the\n";
    cout << "neighborhood rascals standing in your way. He announces that Sergeant Kib is quite\n";
    cout << "alright without your stupid face around to scare him. You...\n\n";

    cout << "1. Punch him\n";
    cout << "2. Tell him a joke\n\n";

    //loop asking for the player reaction
    do
    {
        cout << "Reaction: ";

        getline(cin, userInput);
    } while (userInput != "1" && userInput != "2");
    
    //user punches youth, 3 minute penalty
    if (userInput == "1")
    {
        cout << "\n\nIn a fit of rage, you lash out at the youth and drive him to the ground.\n";
        cout << "Quite an overreaction to such petty quibs, which doesn't do you any favors with\n";
        cout << "his father, who has suddenly appeared in front of you. After some well-deserved\n";
        cout << "scolding and a sound-thrashing, you manage to get away and continue your search...\n\n";

        do
        {
            cout << "[Press enter to continue]";

            getline(cin, userInput);
        } while (userInput.length() != 0);

        return 3;
    }

    //user tells a joke, 0 minute penalty
    else if (userInput == "2")
    {
        cout << "You go to tell a joke, but quickly find that your capacity for humor is limited\n";
        cout << "to the most feeble of Dad jokes. Unsurprisingly, this is not amusing to the youth\n";
        cout << "whatsoever. To his father, however, it is the most hilarious thing he has ever heard,\n";
        cout << "as your awful joke seems to have summoned him from nowhere. As the youth tries to explain\n";
        cout << "the sheer comedic homicide you have just committed, you slip past them both...\n\n";

        do
        {
            cout << "[Press enter to continue]";

            getline(cin, userInput);
        } while (userInput.length() != 0);

        return 0;
    }
}

/**********************************************************
 * *            hasRequiredItem(Inventory)
 * * Checks the Inventory object for the Shoes Item,
 * * returns true if it finds a Shoes Item.
**********************************************************/
bool Road::hasRequiredItem(Inventory playerItems)
{
    return playerItems.checkForItem("Shoes");
}

void Road::printTravelDescription()
{
    cout << "a winding concrete road that seems to twist and change of its own volition, Sergeant Kib\n";
    cout << "must be around here somewhere...(2 time units, Shoes required)";
}

void Road::describeSpace()
{
    std::string userInput = "";

    do
    {
        cout << "\033[2J\033[1;1H";

        cout << "THE WINDING ROAD\n\n";

        cout << "The ever present problem with the road outside your house is its utter inability to have\n";
        cout << "even a modicum of consistency. Walking down it one way twists and turns you so horribly that\n";
        cout << "you are bound to not even notice you've arrived back at your home. Curious. But enough of that,\n";
        cout << "Sergeant Kib surely awaits you somewhere along this blasted path!\n\n";
        
        cout << "[Press enter to continue]";

        getline(cin, userInput);
    } while (userInput.length() != 0);
}