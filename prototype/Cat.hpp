/*********************************************************************
 * * Program name:  Cat.hpp
 * * Author:        Benjamin Hillen
 * * Date:          10 December 2019
 * * Description:   Declaration of the Cat class, inherits Item and
 * *                is the win condition of the Cat_Comes_Back game.
 * *                If at any time the player holds a Cat item, the
 * *                game ends and the player wins.
*********************************************************************/

#ifndef CAT_HPP
#define CAT_HPP

#include "Item.hpp"

class Cat : public Item
{ public:
    
    Cat();

    ~Cat();
};

#endif