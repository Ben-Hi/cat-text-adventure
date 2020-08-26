/**********************************************************
 * * Program name:  Shoes.hpp
 * * Author:        Benjamin Hillen
 * * Date:          9 December 2019
 * * Description:   Declaration of the Shoes class,
 * *                shoes are found in the bedrooma nd are
 * *                required for the player to enter the
 * *                first road space.
***********************************************************/

#ifndef SHOES_HPP
#define SHOES_HPP

#include "Item.hpp"

class Shoes : public Item
{ public:
    
    Shoes();

    ~Shoes();
};

#endif