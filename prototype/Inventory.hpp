/***************************************************************
 * * Program name:  Inventory.hpp
 * * Author:        Benjamin Hillen
 * * Date:          9 December 2019
 * * Description:   Declaration of the Inventory class,
 * *                used to hold Items in either a Space
 * *                or that the player holds. Methods allow
 * *                for adding and removing Items by name or
 * *                index. The inventory is implemented with
 * *                a vector of Items.
***************************************************************/

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "Item.hpp"
#include <vector>

class Inventory
{ private:

    std::vector<Item*> items;

    int inventorySize;

    int numItems;

  public:

    Inventory();

    ~Inventory();

    //methods to put Items into inventory
    void addItem(Item*);

    //methods to take Items out of inventory
    void removeItem(Item);

    Item* dropItem(std::string);

    Item* dropItem(int);

    //methods to search for Items in inventory
    bool hasAnyItem();

    bool checkForItem(std::string);

    bool isFull();

    void printInventory();

    //accessors
    int getNumItems();

    std::string getItemName(int);

    //mutators
    void setNumItems(int);

    void setInventorySize(int);
};

#endif