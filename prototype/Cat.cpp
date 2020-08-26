/*********************************************************************
 * * Program name:  Cat.cpp
 * * Author:        Benjamin Hillen
 * * Date:          10 December 2019
 * * Description:   Declaration of the Cat class, inherits Item and
 * *                is the win condition of the Cat_Comes_Back game.
 * *                If at any time the player holds a Cat item, the
 * *                game ends and the player wins.
*********************************************************************/

#include "Cat.hpp"

Cat::Cat()
{
    name = "Sergeant Kib";

    description = "A rascal of a lad who likes to give his human the slip every now and then";
}

Cat::~Cat()
{
}