#include "Bug.h"
#include <iostream>
#include <random>
#include <fstream>
#include <sstream>





using namespace std;

Bug::Bug(char type, int id, int x, int y, Direction direction, int size, int hopLength, bool alive, bool isWayBlocked)
        : type(type), id(id), position({x, y}), direction(direction), size(size), hopLength(hopLength), alive(alive), isWayBlocked(isWayBlocked) {}

char Bug::getType() const {
    return type;
}

int Bug::getId() const {
    return id;
}

Position Bug::getPosition() const {
    return position;
}

Direction Bug::getDirection() const {
    return direction;
}

int Bug::getSize() const {
    return size;
}

int Bug::gethopLength() const {
    return hopLength;
}

bool Bug::getDorA() const {
    return alive;
}

bool Bug::getisWayBlocked() const {
    return isWayBlocked;
}

void Bug::setType(char type) {
    this->type = type;
}

void Bug::setId(int id) {
    this->id = id;
}

void Bug::setCurrentPosition(const Position& currentPosition) {
    position = currentPosition;
}

void Bug::setDirection(Direction direction) {
    this->direction = direction;
}

void Bug::setSize(int size) {
    this->size = size;
}

void Bug::setHopLength(int hopLength) {
    this->hopLength = hopLength;
}

void Bug::setAlive(bool alive) {
    this->alive = alive;
}

void Bug::setIsWayBlocked(bool isWayBlocked) {
    this->isWayBlocked = isWayBlocked;
}


bool Bug::CheckIsWayBlocked() {
    bool WayBlocked = false;

    int x = position.x; // Using member variable directly
    int y = position.y; // Using member variable directly

    if (direction == Direction::North || direction == Direction::South) {
        if (y <= 1 || y >= 10) {
            setIsWayBlocked(true); // Using member function to set isWayBlocked
            WayBlocked = true;
        }
    }

    if (direction == Direction::East || direction == Direction::West) {
        if (x <= 1 || x >= 10) {
            setIsWayBlocked(true); // Using member function to set isWayBlocked
            WayBlocked = true;
        }
    }

    return WayBlocked;
}



void Bug::displayPathHistory() const
{
    cout <<"Bug" << id << " which is a ";
    if (type == 'C')
    {
        cout<<"Crawler :";
    }

    else if (type == 'H')
    {
        cout<<"Hopper :";
    }

    else
    {
        cout<<"Flyer :";
    }

    for (const Position& StorePosition : path)
    {
        cout << "(" << StorePosition.x << "," << StorePosition.y << ")" ;
    }

    if(alive == true)
    {
        cout<< " Alive";
    }

    else
    {
        cout<<" Dead";
    }

    cout << endl;
}


Bug::~Bug() {}
