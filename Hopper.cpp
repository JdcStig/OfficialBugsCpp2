#include "Hopper.h"
#include "Bug.h"

Hopper::Hopper(char type, int id, int x, int y, Direction direction, int size, int hopLength, bool alive , bool isWayBlocked)
        : Bug(type, id, x, y, direction, size, hopLength, alive, isWayBlocked) {

}


void Hopper::move() {


    CheckIsWayBlocked(); // checks if the bug's way is blocked

    if (getisWayBlocked()) {
        // if bug's way is blocked, change direction
        Position MovedtoPosition = getPosition();

        // get random direction
        int randomDirection = rand() % 4;

        // set the new direction
        switch (randomDirection) {
            case 0:
                setDirection(Direction::North);
                if (MovedtoPosition.y < 9)
                    MovedtoPosition.y+=hopLength;

                setCurrentPosition(MovedtoPosition);
                break;
            case 1:
                setDirection(Direction::South);
                if (MovedtoPosition.y > 1)
                    MovedtoPosition.y-=hopLength;
                setCurrentPosition(MovedtoPosition);
                break;
            case 2:
                setDirection(Direction::East);
                if (MovedtoPosition.x < 9)
                    MovedtoPosition.x+=hopLength;
                setCurrentPosition(MovedtoPosition);
                break;
            case 3:
                setDirection(Direction::West);
                if (MovedtoPosition.x > 1)
                    MovedtoPosition.x-=hopLength;
                setCurrentPosition(MovedtoPosition);
                break;
        }

        setIsWayBlocked(false);



    } else {
        // Move 1 tile in the direction its facing
        Position MovedtoPosition = getPosition();
        switch (getDirection()) {
            case Direction::North:
                if (MovedtoPosition.y < 9)
                    MovedtoPosition.y+=hopLength;
                setCurrentPosition(MovedtoPosition);
                break;
            case Direction::South:
                if (MovedtoPosition.y > 1)
                    MovedtoPosition.y-=hopLength;
                setCurrentPosition(MovedtoPosition);
                break;
            case Direction::East:
                if (MovedtoPosition.x < 9)
                    MovedtoPosition.x+=hopLength;
                setCurrentPosition(MovedtoPosition);
                break;
            case Direction::West:
                if (MovedtoPosition.x > 1)
                    MovedtoPosition.x-=hopLength;
                setCurrentPosition(MovedtoPosition);
                break;
        }

    }
}




Hopper::~Hopper() {
    // Destructor
}