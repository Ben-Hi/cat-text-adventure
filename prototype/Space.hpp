/*******************************************************************
 * * Program name: 	Space.hpp
 * * Author:	    	Benjamin Hillen
 * * Date: 		      5 December 2019
 * * Description: 	Declaration of the Space abstract virtual class,
 * *                has pointers to left, right, top, and bottom
 * *                which are connected together in Game to form
 * *                a structure which implements a map. Each Space
 * *                has an Inventory, an identity (name of room in
 * *                all caps), and a travelTime representing the
 * *                time required to travel to the space. Methods
 * *                allow for the checking of specific Items in the
 * *                inventory. THE SPECIAL ACTION REQUIREMENT IS 
 * *                IMPLEMENTED AS A METHOD, WHICH IS OVERRIDEN
 * *                BY EACH CHILD CLASS TO HAVE CONTEXT AND PLAYER
 * *                REACTION OPTIONS. IF THE PLAYER CHOOSES THE
 * *                INCORRECT ACTION, THEY IMMEDIATELY LOSE THE
 * *                GAME.
*******************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "Inventory.hpp"
#include "Item.hpp"
#include "Shoes.hpp"
#include <string>

class Space
{ protected:

    Space* left;
    Space* right;
    Space* top;
    Space* bottom;

    Inventory roomItems;

    std::string identity;

    int travelTime;

  public:

    Space();

    virtual ~Space() = default;

    //Print travel info
    virtual void printTravelDescription() = 0;

    //activate the Space specific specialAction
    virtual int specialAction() = 0;
    
    //give the player info about the Space
    virtual void describeSpace() = 0;

    //print the Space's inventory
    virtual void printInventory();

    //add an Item to the Space inventory
    virtual void addItem(Item*);

    //has Methods, searches the Inventory roomItems
    //object for method-specific Items
    virtual bool hasRequiredItem(Inventory);

    virtual bool hasItem(std::string);

    virtual bool hasAnyItem();

    virtual bool hasSergeantKib();

    //accessors
    virtual int getTravelTime();

    virtual std::string getIdentity();

    virtual Item* getItem(int);
    virtual Item* getItem(std::string);

    virtual int getNumItems();

    virtual std::string getItemName(int);

    virtual Space* getRight();
    virtual Space* getLeft();
    virtual Space* getTop();
    virtual Space* getBottom();

    //mutators
    virtual void setLeft(Space*);
    virtual void setRight(Space*);
    virtual void setTop(Space*);
    virtual void setBottom(Space*);
};

#endif