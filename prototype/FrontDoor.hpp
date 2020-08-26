/****************************************************************
 * * Program name:  FrontDoor.hpp
 * * Author:        Benjamin Hillen
 * * Date:          9 December 2019
 * * Description:   Declaration of the FrontDoor class,
 * *                prevents user from traveling to it unless
 * *                they have the Shoes item.
****************************************************************/

#ifndef FRONTDOOR_HPP
#define FRONTDOOR_HPP

#include "Space.hpp"

class FrontDoor : public Space
{ public:

    FrontDoor();

    ~FrontDoor();

    virtual bool hasRequiredItem(Inventory);

    virtual void printTravelDescription();

    virtual void describeSpace();

    virtual int specialAction();
};

#endif