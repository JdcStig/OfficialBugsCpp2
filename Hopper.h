//
// Created by duffy on 15/04/2024.
//

#ifndef LATESTBUGSCPP_HOPPER_H
#define LATESTBUGSCPP_HOPPER_H

#include "Bug.h"

class Hopper : public Bug {
public:
    Hopper(char type, int id, int x, int y, Direction direction, int size, int hopLength, bool alive,bool isWayBlocked);

// Override the move so it will work of the code in the crawler.cpp
    void move() override;


// Destructor
    ~Hopper();



};


#endif //LATESTBUGSCPP_HOPPER_H
