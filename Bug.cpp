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

    int x = position.x;
    int y = position.y;

    if (direction == Direction::North || direction == Direction::South) {
        if (y <= 1 || y >= 10) {
            setIsWayBlocked(true);
            WayBlocked = true;
        }
    }

    if (direction == Direction::East || direction == Direction::West) {
        if (x <= 1 || x >= 10) {
            setIsWayBlocked(true);
            WayBlocked = true;
        }
    }

    return WayBlocked;
}


Bug::~Bug() {}
