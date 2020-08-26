/*******************************************************************
 * * Program name: 	Bedroom.hpp
 * * Author:		Benjamin Hillen
 * * Date: 		    5 December 2019
 * * Description: 	Declaration of the Bedroom class, derives from
 * *                the Space class, overrides appropriate methods
 * *                to inform the player about the Bedroom. The
 * *                Bedroom specialAction is called at the start
 * *                of the game. The player must dodge the falling
 * *                bookshelf or they will lose.
*******************************************************************/

#ifndef BEDROOM_HPP
#define BEDROOM_HPP

#include "Space.hpp"

class Bedroom : public Space
{ public:

    Bedroom();

    ~Bedroom();

    virtual void printTravelDescription();

    virtual void describeSpace();

    virtual int specialAction();
};

#endif