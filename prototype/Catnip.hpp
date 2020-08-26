/******************************************************
 * * Program name:  Catnip.hpp
 * * Author:        Benjamin Hillen
 * * Date:          9 December 2019
 * * Description:   Declaration of the Catnip class,
 * *                inherits from Item and is used to
 * *                bait the Trap item.
*******************************************************/

#ifndef CATNIP_HPP
#define CATNIP_HPP

#include "Item.hpp"

class Catnip : public Item
{ public:

    Catnip();

    ~Catnip();
};

#endif