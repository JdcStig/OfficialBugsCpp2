#ifndef BUG_H
#define BUG_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>

using namespace std;



enum class Direction { North, South, East,  West };

struct Position {
    int x;
    int y;
};

class Bug {
public:
    char type;
    int id;
    Position position;
    Direction direction;
    int size;
    int hopLength;
    bool alive = true;
    bool isWayBlocked = false;

    list<Position> path;// creates a list to store position ( and y coordinates of a bug)

    virtual ~Bug();

    virtual void move()=0;


    void recordPathHistory();// pushes position into the list

    void displayPathHistory() const; //calls to view the list



    Bug(char type, int id, int x, int y, Direction direction, int size, int hopLength, bool alive, bool isWayBlocked);

    char getType() const;

    int getId() const;

    Position getPosition() const;

    Direction getDirection() const;

    int getSize() const;

    int gethopLength() const;

    bool getDorA() const;

    bool getisWayBlocked() const;


    void setType(char type);

    void setId(int id);

    void setCurrentPosition(const Position& currentPosition);

    void setDirection(Direction direction);

    void setSize(int size);

    void setHopLength(int hopLength);

    void setAlive(bool alive);

    void setIsWayBlocked(bool isWayBlocked);

    bool CheckIsWayBlocked();
};









#endif // BUG_H
