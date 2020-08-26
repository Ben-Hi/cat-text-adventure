/*******************************************************************
 * * Program name: 	Game.cpp
 * * Author:		Benjamin Hillen
 * * Date: 		    5 December 2019
 * * Description: 	Definition of the Game class, controls the flow
 * *                of the game. Methods are used to display various
 * *                menus, handle movement of items between player
 * *                and space inventories, and move the player 
 * *                around the Space structure. The player wins
 * *                if they can put a Cat Item in their inventory,
 * *                which is only possible if they have the
 * *                Catnip Item in their inventory. The player loses
 * *                if they run out of time or they fail the
 * *                specialAction event of each Space they move to.
 * *                For simplicity,
 * *                the game map has been hardcoded in. Future
 * *                improvements could involve randomly generating
 * *                the outside of the house and adding more
 * *                random events to the Road specialAction method
*******************************************************************/

#include "Game.hpp"
#include "validateInt.hpp"
#include <iostream>

#define TIME_LIMIT 20
#define TIME_MAX 40
#define TIME_MIN 5

using std::cout;
using std::cin;
using std::endl;

Game::Game()
{
    keepPlaying = true;

    hasWon = false;

    hasLost = false;

    inventorySize = 4;

    inventory.setInventorySize(inventorySize);

    time = TIME_LIMIT;

    location = NULL;
}

Game::~Game()
{
    delete location;
}

bool Game::getKeepPlaying()
{
    return keepPlaying;
}

/**********************************************************************
 * *                            clearScreen()
 * * Clears the screen and starts text at the
 * * top of the console. Cited from 
 * * https://stackoverflow.com/questions/17335816/clear-screen-using-c
 * * posted by catzilla
***********************************************************************/
void Game::clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

/*******************************************************************
 * *                            buildGameMap()
 * * Builds the required linked structure of Space objects by
 * * making a bedroom, kitchen, front door, and road and linking
 * * them together to form the map visualized in the showMap method,
 * * with walls surrounding each Space to prevent the user from
 * * going out of bounds
********************************************************************/
void Game::buildGameMap()
{
    Space* kitchen = new Kitchen;

    Space* frontDoor = new FrontDoor;

    Space* road = new Road;

    Space* firstRoad = new Road;

    Item* sergeantKib = new Cat;

    location = new Bedroom;

    //link the starting location, the bedroom
    location->setRight(kitchen);

    kitchen->setLeft(location);

    location->setLeft(new Wall);

    location->setTop(new Wall);

    location->setBottom(new Wall);

    //link the kitchen
    kitchen->setTop(new Wall);

    kitchen->setRight(new Wall);

    kitchen->setBottom(frontDoor);

    //link the front door
    frontDoor->setTop(kitchen);

    frontDoor->setBottom(road);

    frontDoor->setLeft(new Wall);

    frontDoor->setRight(new Wall);

    //link the first road
    firstRoad->setTop(kitchen);

    firstRoad->setBottom(new Road);

    firstRoad->setRight(new Wall);

    firstRoad->setLeft(new Wall);

    //link the second road
    Space* secondRoad = firstRoad->getBottom();

    secondRoad->setTop(firstRoad);

    secondRoad->setBottom(new Road);

    secondRoad->setRight(new Wall);

    secondRoad->setLeft(new Road);

    //link the third road
    Space* thirdRoad = secondRoad->getBottom();

    thirdRoad->setTop(secondRoad);

    thirdRoad->setBottom(new Wall);

    thirdRoad->setRight(new Wall);

    thirdRoad->setLeft(new Wall);

    thirdRoad->addItem(sergeantKib);
}

/********************************************
 * *              showMap()
 * * Prints the game map to the user.
*********************************************/
void Game::showMap()
{
    std::string userInput = "";

    //display the game map and context info about where the player
    //is currently located
    do
    {
        clearScreen();
    
        cout << "MAP\n\n";
    
        cout << "#####################\n";
        cout << "# Bedroom | Kitchen #\n";
        cout << "#         #         #\n";
        cout << "#################-###\n";
        cout << "            # Front #\n";
        cout << "            #  Door #\n";
        cout << "            #####-###\n";
        cout << "             #  ||  #\n";
        cout << "             # Road #\n";
        cout << "             #  ||  #\n";
        cout << "             # Road #\n";
        cout << "             #  ||  #\n";
        cout << "             # Road #\n";
        cout << "             ########\n";
    
        cout << "You are currently ";
    
        //user is in the house, tell them what room they are in
        if (location->getIdentity() != "ROAD")
        {
            cout << " at home in your " << location->getIdentity();
        }
        
        //user has left the house and is on the road, inform
        //the user
        else
        {
            cout << " on the road in search of Sergeant Kib";
        }

        cout << "\n\n[Press enter to return to action menu]";

        getline(cin, userInput);
    } while (userInput.length() != 0);   
}

/*****************************************************************************************
 * *                                    travelRight()
 * * Attempts to move the player to the Space right of location. Returns the time
 * * lost by Special Action. Will not allow movement into a Wall or a Space that
 * * requires the player to have an Item that they do not currently possess.
*****************************************************************************************/
int Game::travelRight()
{
    std::string userInput = "";

    //check if the next space requires the user to have an item
    if (location->getRight()->hasRequiredItem(inventory))
    {
        //allow the user to move if they have the item and
        //the space is not a wall
        if (location->getRight()->getIdentity() != "WALL")
        {
            location = location->getRight();
            time -= location->getTravelTime();

            return location->specialAction();
        }

        //user tried to enter a wall, print an error message
        else
        {
            cout << "\n\nThat's a wall...You ARE somewhat desperate to find Sergeanat Kib, but\n";
            cout << "not THAT desperate. Best go take another look around\n\n";
            do
            {
            cout << "[Press enter to return to action menu]";
            getline(cin, userInput);
            } while (userInput.length() != 0);

            return 0;
        }
    }
    //user doesn't have item required to move onto that space,
    //print an error message
    else
    {
        cout << "\n\nYou don't have the required item in your inventory!!\n\n";
        do
        {
            cout << "[Press enter to return to action menu]";
            getline(cin, userInput);
        } while (userInput.length() != 0);

        return 0;
    }    
}

/*****************************************************************************************
 * *                                    travelLeft()
 * * Attempts to move the player to the Space left of location. Returns the time
 * * lost by Special Action. Will not allow movement into a Wall or a Space that
 * * requires the player to have an Item that they do not currently possess.
*****************************************************************************************/
int Game::travelLeft()
{
    std::string userInput = "";

    //check if the next space requires the user to have an item
    if (location->getLeft()->hasRequiredItem(inventory))
    {
        //allow the user to move if they have the item and
        //the space is not a wall
        if (location->getLeft()->getIdentity() != "WALL")
        {
            location = location->getLeft();
            time -= location->getTravelTime();

            return location->specialAction();
        }

        //user tried to enter a wall, print an error message
        else
        {
            cout << "\n\nThat's a wall...You ARE somewhat desperate to find Sergeanat Kib, but\n";
            cout << "not THAT desperate. Best go take another look around\n\n";
            do
            {
            cout << "[Press enter to return to action menu]";
            getline(cin, userInput);
            } while (userInput.length() != 0);

            return 0;
        }
    }
    //user doesn't have item required to move onto that space,
    //print an error message
    else
    {
        cout << "\n\nYou don't have the required item in your inventory!!\n\n";
        do
        {
            cout << "[Press enter to return to action menu]";
            getline(cin, userInput);
        } while (userInput.length() != 0);

        return 0;
    }
}

/*****************************************************************************************
 * *                                    travelTop()
 * * Attempts to move the player to the Space top of location. Returns the time
 * * lost by Special Action. Will not allow movement into a Wall or a Space that
 * * requires the player to have an Item that they do not currently possess.
*****************************************************************************************/
int Game::travelTop()
{
    std::string userInput = "";

    //check if the next space requires the user to have an item
    if (location->getTop()->hasRequiredItem(inventory))
    {
        //allow the user to move if they have the item and
        //the space is not a wall
        if (location->getTop()->getIdentity() != "WALL")
        {
            location = location->getTop();
            time -= location->getTravelTime();

            return location->specialAction();
        }

        //user tried to enter a wall, print an error message
        else
        {
            cout << "\n\nThat's a wall...You ARE somewhat desperate to find Sergeanat Kib, but\n";
            cout << "not THAT desperate. Best go take another look around\n\n";
            do
            {
            cout << "[Press enter to return to action menu]";
            getline(cin, userInput);
            } while (userInput.length() != 0);

            return 0;
        }
    }
    //user doesn't have item required to move onto that space,
    //print an error message
    else
    {
        cout << "\n\nYou don't have the required item in your inventory!!\n\n";
        do
        {
            cout << "[Press enter to return to action menu]";
            getline(cin, userInput);
        } while (userInput.length() != 0);

        return 0;
    }
}

/*****************************************************************************************
 * *                                    travelBottom()
 * * Attempts to move the player to the Space bottom of location. Returns the time
 * * lost by Special Action. Will not allow movement into a Wall or a Space that
 * * requires the player to have an Item that they do not currently possess.
*****************************************************************************************/
int Game::travelBottom()
{
    std::string userInput = "";

    //check if the next space requires the user to have an item
    if (location->getBottom()->hasRequiredItem(inventory))
    {
        //allow the user to move if they have the item and
        //the space is not a wall
        if (location->getBottom()->getIdentity() != "WALL")
        {
            location = location->getBottom();
            time -= location->getTravelTime();

            return location->specialAction();
        }

        //user tried to enter a wall, print an error message
        else
        {
            cout << "\n\nThat's a wall...You ARE somewhat desperate to find Sergeanat Kib, but\n";
            cout << "not THAT desperate. Best go take another look around\n\n";
            do
            {
            cout << "[Press enter to return to action menu]";
            getline(cin, userInput);
            } while (userInput.length() != 0);

            return 0;
        }
    }
    //user doesn't have item required to move onto that space,
    //print an error message
    else
    {
        cout << "\n\nYou don't have the required item in your inventory!!\n\n";
        do
        {
            cout << "[Press enter to return to action menu]";
            getline(cin, userInput);
        } while (userInput.length() != 0);

        return 0;
    }
}
/************************************************************************
 * *                        travelOptions()
 * * Displays the four directions the player can move in and the cost
 * * of moving in each direction, then calls the specialAction method
 * * of that Space. Returns the time lost by the player depending on 
 * * their response to the specialAction event.
*************************************************************************/
int Game::travelOptions()
{
    std::string userInput = "";

    //loop asking user which adjacent space they want to travel to
    do
    {
        clearScreen();

        cout << "TRAVEL OPTIONS\n\n";

        cout << "To the right, you see ";
        location->getRight()->printTravelDescription();

        cout << "\n\nTo the left, you see";
        location->getLeft()->printTravelDescription();

        cout << "\n\nA little further above, you see ";
        location->getTop()->printTravelDescription();

        cout << "\n\nJust below, you can see ";
        location->getBottom()->printTravelDescription();

        cout << "\n\nEnter 1 to go right, 2 to go left, 3 to go up, or 4 to go down\n\n";

        cout << "Travel: ";

        getline(cin, userInput);
    } while (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4");

    //user tries to travel right
    if (userInput == "1")
    {
       return travelRight();
    }

    //user tries to travel left
    else if (userInput == "2")
    {
        return travelLeft();
    }

    //user tries to travel up
    else if (userInput == "3")
    {
        return travelTop();
    }

    //user tries to travel bottom
    else if (userInput == "4")
    {
        return travelBottom();
    }
}

/******************************************************************************
 * *                            inventoryMenu()
 * * Prints the items currently in the user's inventory. Gives the user the
 * * option to discard an item by entering the number associated with that
 * * item, or to exit the inventory by pressing enter
*******************************************************************************/
void Game::inventoryMenu()
{
    std::string userInput = "";

    clearScreen();

    //loop display the player inventory and ask which item they want to drop
    do
    {
       //print out all the item names in the players inventory
        inventory.printInventory();

        cout << "INVENTORY - MAX SIZE: " << inventorySize << endl << endl;

        cout << "Enter the number of the item you want to discard, or press enter\n";
        cout << "to exit the inventory screen\n";

        getline(cin, userInput);
    } while (userInput.length() != 0 && userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4");

    //user discards first inventory item to room
    if (userInput == "1")
    {
        location->addItem(inventory.dropItem(0));
    }

    //user discards second inventory item to room
    else if (userInput == "2")
    {
        location->addItem(inventory.dropItem(1));
    }

    //user discards third inventory item to room
    else if (userInput == "3")
    {
        location->addItem(inventory.dropItem(2));
    }

    //user discards fourth inventory item to room
    else if (userInput == "4")
    {
        location->addItem(inventory.dropItem(3));
    }
}

/***********************************************************
 * *                    mainMenu()
 * * Presents user with option to play, change settings,
 * * or quit the game. Settings are changed by calling
 * * the settings() function. Calls play() if user chooses
 * * to play the game.
***********************************************************/
void Game::mainMenu()
{
    const int PLAY = 1;

    const int SETTINGS = 2;

    const int QUIT = 3;

    int choice = 0;

    clearScreen();

    std::string userInput = "";

    //loop display the main menu until the user chooses an option
    do
    {
        cout << "THE CAT COMES BACK" << endl << endl;
        cout << "1. Play\n";
        cout << "2. Settings\n";
        cout << "3. Quit\n\n";

        cout << "Option: ";

        getline(cin, userInput);
        
        //print error message if user enters invalid input
        if (userInput != "1" && userInput != "2" && userInput != "3")
        {
            clearScreen();

            cout << "Error, please enter 1, 2, or 3 only\n";
        }
    } while (userInput != "1" && userInput != "2" && userInput != "3");

    choice = stoi(userInput);

    //menu option cases
    switch (choice)
    {
        //user chooses to play, do nothing and proceed with play()
        case PLAY:
        {
            play();

            break;
        }
        
        //user wants to access settings, do so and then return to 
        //main menu
        case SETTINGS:
        {
            settings();

            mainMenu();

            break;
        }

        //user chooses to quit, set keepPlaying to false and proceed
        //with play()
        case QUIT:
        {
            keepPlaying = false;

            break;
        }
        
        default:
        {
            break;
        }
    }
}

/**************************************************************
 * *                    settings()
 * * Displays changeable settings to the user and allows them
 * * to change them. Currently only allows the time to be
 * * changed, making the game easier or harder to win.
**************************************************************/
void Game::settings()
{
    std::string userInput = "";

    clearScreen();
    
    //loop display the settings of the game until user
    //chooses one to change or return to main menu
    do
    {
        cout << "SETTINGS\n\n";

        cout << "1. Timer:   " << time <<  " minutes" << endl;
        cout << "When the timer expires, the cat will have left the neighborhood\n";
        cout << "and the player will lose the game.\n\n";

        cout << "2. Return to Main Menu\n\n";

        cout << "Option: ";

        getline(cin, userInput);

        if (userInput != "1")
        {
            cout << "Error, invalid option, try again\n\n";
        }
    } while (userInput != "1" && userInput != "2");

    //user chooses to change the timer
    if (userInput == "1")
    {
        clearScreen();

        //loop asking for time value between TIME_MIN and TIME_MAX
        do
        {
            cout << "New Time: ";

            getline(cin, userInput);

            //validateInt(userInput);

            time = stoi(userInput);

            if (time > TIME_MAX || time < TIME_MIN)
            {
                cout << "Error, time must be between " << TIME_MIN << " and " << TIME_MAX << endl;
            }
        } while (time > TIME_MAX || time < TIME_MIN);
    }
}

/*********************************************************************************
 * *                           takeItemFromRoom()
 * * Checks if there are any items in the current location. If there are,
 * * prints them to the user and asks which one they would like to put in their
 * * inventory if they have room. Then places that item into their inventory and
 * * removes it from the room.
**********************************************************************************/
void Game::takeItemFromRoom()
{
    std::string userInput = "";

    //if there are items in the room, display them and allow the user
    //to pick them up if they have room in their inventory
    if (location->hasAnyItem())
    {
        location->printInventory();
        
        //check if the user has space in their inventory
        if (!inventory.isFull())
        {
            int choice = 0;
            //The user grabs an item from the room
            do
            {
                cout << "Enter the number of the item you wish to pickup\n\n";
    
                cout << "Option: ";
    
                getline(cin, userInput);

                validateInt(userInput);

                choice = stoi(userInput);
            } while (choice < 1 || choice > location->getNumItems());
            
            if (choice != 0)
            {
                //let the user pick the item up if it is not Sergeant Kib
                if (location->getItemName(choice - 1) != "Sergeant Kib")
                {    
                    if (choice > 0 && choice <= location->getNumItems())
                    {
                       inventory.addItem(location->getItem(choice - 1));
                    }
                }
            
                //tell the user they have to catch Kib from the main menu
                else
                {
                    cout << "\nYou can't catch Sergeant Kib from this menu!";

                    do
                    {
                        cout << "[Catch Sergeant Kib from action menu, press enter to return there]";

                        getline(cin, userInput);
                    } while (userInput.length() != 0);
                }
            }
        }
        
        //tell the user they need to discard an item if their inventory is full
        else
        {
            do
            {
                cout << "Your inventory is full, better discard something first\n\n";
                cout << "[Press enter to return to action menu]";
                getline(cin, userInput);
            } while (userInput.length() != 0);
        }
    }    

    //There are no items in the room, inform the user
    else
    {
        do
        {
            cout << "It doesn't look like there are any items of interest around here...\n\n";
            
            cout << "[Press enter to return to action menu]";
            getline(cin, userInput);
        } while (userInput.length() != 0);
    }
}

/************************************************************************
 * *                            actionMenu()
 * * Displays the action menu to the user and asks for their input.
 * * Allows user to observe their surroundings, interact with the room,
 * * view their inventory, move to another space, view their map,
 * * or quit the game. Returns the time cost of an action.
*************************************************************************/
int Game::actionMenu()
{
    const std::string LOOK = "1";

    const std::string ACTION = "2";

    const std::string INVENTORY = "3";

    const std::string MAP = "4";

    const std::string TRAVEL = "5";

    const std::string QUIT = "6";

    std::string userInput = "";

    //present the action menu and get user choice
    do
    {
        clearScreen();

        cout << "LOCATION: " << location->getIdentity();

        cout << endl << endl;

        cout << "CHARACTER ACTIONS\n\n";

        cout << "1. Look around (no time cost)\n";
        cout << "2. Try to catch Sergeant Kib (if he's in this area)\n";
        cout << "3. Inventory\n";
        cout << "4. Look at Map on Phone (no time cost)\n";
        cout << "5. Travel to an adjacent space\n";
        cout << "6. Quit\n\n";

        cout << "You have " << time << " minutes left before your cat is gone for good!\n\n";

        cout << "Option: ";

        getline(cin, userInput);
    } while (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5" && userInput != "6");

    //describe the space the user is in and items in the room
    if (userInput == LOOK)
    {
        location->describeSpace();

        cout << "\nTo the right, you see ";

        location->getRight()->printTravelDescription();

        cout << "\n\nTo the left, you see";

        location->getLeft()->printTravelDescription();

        cout << "\n\nA little further above, you see ";

        location->getTop()->printTravelDescription();

        cout << "\n\nJust below, you can see ";

        location->getBottom()->printTravelDescription();

        cout << "\n\n\nYou search the area for any useful items on your cat quest...\n\n";

        takeItemFromRoom();

        return 0;
    }
    
    //user tries to catch Sergeant Kib
    else if (userInput == ACTION)
    {
        //The location has Sergeant Kib, let the player catch him if they
        //have Catnip in their inventory
        if (location->hasSergeantKib())
        {
            if (inventory.checkForItem("Catnip"))
            {
                inventory.addItem(location->getItem("Sergeant Kib"));
            }

            else
            {
                cout << "\n\nYou beckon to Sergeant Kib, only to watch dismayed as he turns his nose up\n";
                cout << "and meanders away from you. Looks like you'll have to find something that strikes\n";
                cout << "his fancy before he'll come home with you...\n\n";

                do
                {
                    cout << "[Press enter to continue]";

                    getline(cin, userInput);
                } while (userInput.length() != 0);
            }
        }

        //the location doesn't have Sergeant Kib, inform the player
        else
        {
            do
            {
                cout << "\n\nHmm, it doesn't look like Sergeant Kib is here. Best try another area\n\n";

                cout << "[Press enter to continue]";

                getline(cin, userInput);
            } while (userInput.length() != 0);
        }

        return 0;
    }

    //display the user's inventory and allow them to drop items
    else if (userInput == INVENTORY)
    {
        int choice = 0;

        do
        {
            clearScreen();

            inventory.printInventory();

            cout << "\n\n[Enter the number associated with the item you want to drop or 5 to continue]\n";

            getline(cin, userInput);

            validateInt(userInput);

            choice = stoi(userInput);
        } while (choice != 5 && choice < 1 && choice > inventory.getNumItems());

        if (choice <= inventory.getNumItems())
        {
            location->addItem(inventory.dropItem(choice - 1));

            do
            {
                cout << "[Press enter to continue]";

                getline(cin, userInput);
            } while (userInput.length() != 0);
        }

        return 0;
    }
    
    //print the map to the user
    else if (userInput == MAP)
    {
        showMap();

        return 0;
    }

    //user wants to travel, bring up travelOptions and
    //see if the user succeeds or fails at the specialAction
    //of the Space they move to
    else if (userInput == TRAVEL)
    {
        return travelOptions();
    }
        
    //quit the game
    else if (userInput == QUIT)
    {
        keepPlaying = false;

        hasLost = true;

        return 0;
    }
}

/**************************************************************************
 * *                                play()
 * * Handles the highest abstraction of gameflow. Displays background info
 * * and game mechanics to the player, then begins the game loop. An
 * * action menu is presented to the player, where they can access their
 * * inventory and take space-specific actions, some of which can subtract
 * * from their time units. The loop ends when the player runs out of time,
 * * finds the cat, or quits the program.
***************************************************************************/
void Game::play()
{
    std::string userInput = "";

    //display the prologue info to the user
    do
    {
        clearScreen();

        cout << "THE CAT COMES BACK - PROLOGUE\n\n";

        cout << "You aren't quite sure of the exact moment when it occured, only that it must have taken place\n";
        cout << "in-between your frustrated rearrangement of your bookshelf and the triumphant yowl your cat let out\n";
        cout << "at having lept the fence in your backyard for the umpteenth time this month. How troublesome.\n";
        cout << "Looks like you have a cat to catch! Best to be quick about it though, the neighborhood kids can be\n";
        cout << "quite mean. We don't want Sergeant Kib leaving the suburb for good now do we?\n\n";

        cout << "(Time Mechanic: you have " << time << " units of time to find and catch your cat. Various actions you take\n";
        cout << "in game will decrease your time. Moving between spaces costs one time unit. Good luck!)\n\n";

        cout << "[Press ENTER to continue]";

        getline(cin, userInput);
    } while (userInput.length() != 0);

    buildGameMap();                     //construct the map

    clearScreen();

    time -= location->specialAction();

    //play the game until the user chooses to quit or they win
    while (keepPlaying)
    {
        time -= actionMenu();

        //if the user runs out of time, stop playing the game and
        //continue to the results part of play()
        if (time <= 0)
        {
            hasLost = true;

            keepPlaying = false;
        }

        //if the user at any time has a Cat item in their inventory,
        //stop playing the game and continue to the results part of play()
        if (inventory.checkForItem("Sergeant Kib"))
        {
            keepPlaying = false;

            hasWon = true;
        }
    }

    //Player Wins Result
    if (hasWon)
    {
        clearScreen();

        cout << "VICTORY\n\n";

        //ASCII Art copied from
        //http://www.ascii-art.de/ascii/c/cat.txt
        cout << "              _\n";                        
        cout << "             \\`*-.\n";                    
        cout << "              )  _`-.\n";               
        cout << "              .  : `. .\n";             
        cout << "              : _   '  \\\n";               
        cout << "              ; *` _.   `*-._\n";          
        cout << "              `-.-'          `-.\n";       
        cout << "                ;       `       `.\n";     
        cout << "                :.       .        \\\n";    
        cout << "                .\\  .   :   .-'   .\n";   
        cout << "                '  `+.;  ;  '      :\n";   
        cout << "                :  '  |    ;       ;-.\n"; 
        cout << "                ; '   : :`-:     _.`* ;\n";
        cout << "             .*' /  .*' ; .*`- +'  `*'\n"; 
        cout << "             `*-*   `*-*  `*-*'        \n\n\n";


        cout << "Congratulations!! You managed to lure Sergeant Kib back to your house\n";
        cout << "with the clever use of catnip. Time for some well-deserved rest.\n\n";

        cout << "END\n\n";
    }

    //Player Loses Result
    else
    {
        clearScreen();

        cout << "GAME OVER\n\n";

        cout << "                         (`.-,')\n";
        cout << "                       .-'     ;\n";
        cout << "                   _.-'   , `,-\n";
        cout << "             _ _.-'     .'  /._\n";
        cout << "           .' `  _.-.  /  ,'._;)\n";
        cout << "          (       .  )-| (\n";
        cout << "           )`,_ ,'_,' \\_;)\n";
        cout << "   ('_  _,'.'  (___,))\n";
        cout << "    `-:;.-'\" \n\n";

        cout << "You were too slow in your journey, it looks like Sergeant Kib is gone for good this time...\n";
    }
}   