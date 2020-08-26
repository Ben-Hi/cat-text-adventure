/*******************************************************************
 * * Program name: 	Wall.hpp
 * * Author:		Benjamin Hillen
 * * Date: 		    9 December 2019
 * * Description: 	Declaration of the Wall class, serves as the
 * *                boundary of the house area of the game
*******************************************************************/

#ifndef WALL_HPP
#define WALL_HPP

#include "Space.hpp"

class Wall : public Space
{ public:

    Wall();

    ~Wall();
    
    virtual void printTravelDescription();

    virtual void describeSpace();

    virtual void describeSpecialAction();

    virtual int specialAction();

};

#endif