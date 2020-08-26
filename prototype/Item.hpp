/*******************************************************
 * * Program name:  Item.hpp
 * * Author:        Benjamin Hillen
 * * Date:          9 December 2019
 * * Description:   Declaration of the item class,
 * *                used to make the items in the game.
*******************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item
{ protected:
    
    std::string name;

    std::string description;

  public:

    Item();

    virtual ~Item() = default;

    //mutators
    virtual void setName(std::string);

    virtual void setDescription(std::string);

    //accessors
    virtual std::string getName();

    virtual std::string getDescription();
};

#endif