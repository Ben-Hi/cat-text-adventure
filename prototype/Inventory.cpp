/***************************************************************
 * * Program name:  Inventory.cpp
 * * Author:        Benjamin Hillen
 * * Date:          9 December 2019
 * * Description:   Definition of the Inventory class,
 * *                used to hold Items in either a Space
 * *                or that the player holds. Methods allow
 * *                for adding and removing Items by name or
 * *                index. The inventory is implemented with
 * *                a vector of Items.
***************************************************************/

#include "Inventory.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Inventory::Inventory()
{
    inventorySize = 4;

    numItems = 0;
}

Inventory::~Inventory()
{
}

/******************************************************
 * *                    Accessors
******************************************************/
int Inventory::getNumItems()
{
    return numItems;
}

std::string Inventory::getItemName(int index)
{
    return items[index]->getName();
}

/******************************************************
 * *                     Mutators
******************************************************/
void Inventory::setNumItems(int numIn)
{
    numItems = numIn;
}

void Inventory::setInventorySize(int sizeIn)
{
    inventorySize = sizeIn;
}

/******************************************************
 * *                addItem(Item*)
 * * Takes a pointer to an Item object and pushes it
 * * to the end of the inventory
******************************************************/
void Inventory::addItem(Item *input)
{
    if (items.size() < inventorySize)
    {
        items.push_back(input);

        numItems++;
    }
}

/************************************************************
 * *                dropItem(string)
 * * Takes the ID of the item to drop from the inventory in
 * * the form of the item name. If any of the items in the
 * * inventory have the same name as the passed string,
 * * remove that Item from the inventory and return it.
************************************************************/
Item* Inventory::dropItem(std::string target)
{
    //first check if there are items in the inventory
    if (items.size() > 0)
    {
        int i = 0;
        
        //check each item in the inventory, if the name matches
        //the name of the item to be dropped, then take that item
        //out of the vector and return it
        for (auto slot: items)
        {
            if (slot->getName() == target)
            {
                Item* found = items[i];

                items.erase(items.begin() + i);

                numItems--;

                cout << "Dropping " << items[i]->getName();

                return found;
            }

            i++;
        }
    }
}

/**************************************************************
 * *                        dropItem(int)
 * * Takes an integer and returns the item at that index in the
 * * inventory if the inventory is not empty.
***************************************************************/
Item* Inventory::dropItem(int index)
{
    if (items.size() > 0)
    {
        Item* target = items[index];

        cout << "Dropping " << items[index]->getName() << "...";

        items.erase(items.begin() + index);

        numItems--;

        return target;
    }
}

/***************************************************************
 * *                        hasAnyItem()
 * * Returns true if the inventory has any Items inside.
***************************************************************/
bool Inventory::hasAnyItem()
{
    if (items.size() > 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

/***************************************************************
 * *                    checkForItem(string)
 * * Takes a string and searches the inventory for any Items
 * * whose name matches that string. Returns true if any
 * * Items have that name, returns false otherwise.
***************************************************************/
bool Inventory::checkForItem(std::string target)
{
    //check only if there are items in the inventory
    if (items.size() > 0)
    {
        int i = 0;

        //check each item in the inventory, if the name matches
        //then return true
        for (Item* slot: items)
        {
            if (slot->getName() == target)
            {
                return true;
            }

            i++;
        }

        return false;
    }

    else
    {
        return false;
    }
}

/***************************************************************
 * *                       isFull()
 * * Returns true if the size of the inventory is equal to its
 * * size limiter, inventorySize. Returns false otherwise
***************************************************************/
bool Inventory::isFull()
{
    if (items.size() == inventorySize)
    {
        return true;
    }

    else
    {
        return false;
    }    
}

/*************************************************************
 * *                    printInventory()
 * * Prints out the inventory in a numbered list
*************************************************************/
void Inventory::printInventory()
{
    if (items.size() > 0)
    {
        int i = 1;

        for (Item* slot: items)
        {
            cout << i << ". " << slot->getName() << endl;

            i++;
        }
    }
}