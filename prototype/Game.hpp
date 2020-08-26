/*******************************************************************
 * * Program name: 	Game.hpp
 * * Author:	    	Benjamin Hillen
 * * Date: 		      5 December 2019
 * * Description: 	Declaration of the Game class, controls the flow
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

#ifndef GAME_HPP
#define GAME_HPP

#include "Space.hpp"
#include "Bedroom.hpp"
#include "Kitchen.hpp"
#include "FrontDoor.hpp"
#include "Wall.hpp"
#include "Road.hpp"
#include "Inventory.hpp"
#include "Item.hpp"
#include "Cat.hpp"
#include <vector>

class Game
{ private:
    
    bool keepPlaying,
         hasWon,
         hasLost;

    int time;

    Inventory inventory;

    int inventorySize;
    
    Space* location;

  public:

    Game();

    ~Game();

    void clearScreen();
    
    //take an item from the current room inventory
    void takeItemFromRoom();

    //menu methods
    void mainMenu();

    int actionMenu();

    void inventoryMenu();

    int travelOptions();

    int travelRight();
    int travelLeft();
    int travelTop();
    int travelBottom();

    void settings();

    //create the structure of Space objects
    void buildGameMap();

    //show the layout of Spaces
    void showMap();

    void play();

    //accessors
    bool getKeepPlaying();
};

#endif