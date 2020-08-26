/*******************************************************
 * * Program name:  Item.cpp
 * * Author:        Benjamin Hillen
 * * Date:          9 December 2019
 * * Description:   Declaration of the item class,
 * *                used to make the items in the game.
*******************************************************/

#include "Item.hpp"

Item::Item()
{
    name = "";

    description = "";
}

/***************************************************
 * *                Mutators
***************************************************/
void Item::setName(std::string inputName)
{
    name = inputName;
}

void Item::setDescription(std::string inputDes)
{
    description = inputDes;
}

/****************************************************
 * *                  Accessors
****************************************************/
std::string Item::getName()
{
    return name;
}

std::string Item::getDescription()
{
    return description;
}