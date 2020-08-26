/****************************************************
 * * Program name:  Road.hpp
 * * Author:        Benjamin Hillen
 * * Date:          10 December 2019
 * * Description:   Definition of the road class,
 * *                each road has a random chance to
 * *                hold the cat in it. If the user
 * *                has the Catnip Item, they can
 * *                pickup the cat. The game ends
 * *                when the user picks up the cat.
*****************************************************/

#ifndef ROAD_HPP
#define ROAD_HPP

#include "Space.hpp"

class Road : public Space
{ public:

    Road();

    ~Road();

    virtual int specialAction();

    virtual bool hasRequiredItem(Inventory);

    virtual void printTravelDescription();

    virtual void describeSpace();
};

#endif