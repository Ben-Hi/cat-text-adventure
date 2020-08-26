/**********************************************************
 * * Program name:  Kitchen.hpp
 * * Author:        Benjamin Hillen
 * * Date:          8 December 2019
 * * Description:   Declaration of the Kitchen space,
 * *                derives from Space, holds the Catnip
 * *                Item, which is required to win the
 * *                game, as the player cannot catch
 * *                Sergeant Kib without it. specialAction
 * *                has the user plug their nose or fail
 * *                the game.
**********************************************************/

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include "Space.hpp"

class Kitchen : public Space
{ public:

      Kitchen();

      ~Kitchen();

      virtual void printTravelDescription();

      virtual void describeSpace();

      virtual int specialAction();
};

#endif