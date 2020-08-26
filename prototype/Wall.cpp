/*******************************************************************
 * * Program name: 	Wall.cpp
 * * Author:		Benjamin Hillen
 * * Date: 		    9 December 2019
 * * Description: 	Declaration of the Wall class, serves as the
 * *                boundary of the house area of the game
*******************************************************************/

#include "Wall.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Wall::Wall()
{
    left = NULL;

    right = NULL;

    top = NULL;

    bottom = NULL;

    identity = "WALL";
}

Wall::~Wall()
{
}

void Wall::printTravelDescription()
{
    cout << " a wall. You are quite sure you don't want a dent in your head, so maybe not travel here? (cannot move here)";
}

void Wall::describeSpace()
{
    cout << "It's a wall, how on earth did you manage to get in here?";
}

void Wall::describeSpecialAction()
{
    cout << "You get yeeted back to whence you came";
}

int Wall::specialAction()
{
    return 0;   
}