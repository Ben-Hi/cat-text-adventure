/*******************************************************************
 * * Program name: 	Space.cpp
 * * Author:	    Benjamin Hillen
 * * Date: 		    5 December 2019
 * * Description: 	Definition of the Space abstract virtual class,
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

#include "Space.hpp"

Space::Space()
{
    left = NULL;

    right = NULL;

    top = NULL;

    bottom = NULL;

    travelTime = 0;
}

/***********************************************
 * *            addItem(Item*)
 * * Calls the addItem(Item*) method of
 * * Inventory on roomItems, passing it the
 * * pointer that Space::addItem(Item*) was
 * * passed, effectively adding that Item to
 * * the room inventory
***********************************************/
void Space::addItem(Item* itemIn)
{
    roomItems.addItem(itemIn);
}

/********************************
 * *    printInventory()
 * * Calls the printInventory()
 * * method of Inventory on
 * * roomItems
********************************/
void Space::printInventory()
{
    roomItems.printInventory();
}

/*******************************************************
 * *                    has Methods
 * * Used to check if the room holds an item or not
 * * using method specific requirements
*******************************************************/
bool Space::hasItem(std::string target)
{
    return roomItems.checkForItem(target);
}

bool Space::hasAnyItem()
{
    return roomItems.hasAnyItem();
}

bool Space::hasRequiredItem(Inventory playerItems)
{
    return true;                //unless overriden, the Space has no item requirement
}

bool Space::hasSergeantKib()
{
    if (roomItems.checkForItem("Sergeant Kib"))
    {
        return true;
    }

    else
    {
        return false;
    }
}

/*********************************************
 * *            Accessors
**********************************************/
Space* Space::getRight()
{
    return right;
}

Space* Space::getLeft()
{
    return left;
}

Space* Space::getTop()
{
    return top;
}

Space* Space::getBottom()
{
    return bottom;
}

int Space::getTravelTime()
{
    return travelTime;
}

std::string Space::getItemName(int index)
{
    return roomItems.getItemName(index);
}

Item* Space::getItem(int index)
{
    return roomItems.dropItem(index);
}

Item* Space::getItem(std::string target)
{
    return roomItems.dropItem(target);
}

int Space::getNumItems()
{
    return roomItems.getNumItems();
}

std::string Space::getIdentity()
{
    return identity;
}

/*********************************************
 * *                Mutators
*********************************************/
void Space::setLeft(Space* roomLeft)
{
    left = roomLeft;
}

void Space::setRight(Space* roomRight)
{
    right = roomRight;
}

void Space::setTop(Space* roomTop)
{
    top = roomTop;
}

void Space::setBottom(Space* roomBottom)
{
    bottom = roomBottom;
}