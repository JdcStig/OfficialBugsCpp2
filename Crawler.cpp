#include "Crawler.h"
#include "Bug.h"

Crawler::Crawler(char type, int id, int x, int y, Direction direction, int size, int hopLength, bool alive , bool isWayBlocked)
        : Bug(type, id, x, y, direction, size, hopLength, alive, isWayBlocked) {
    // Initialize Crawler variables in the Crawler class
}




void Crawler::move() {


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
                if (MovedtoPosition.y < 10)
                    MovedtoPosition.y++;
                break;
            case 1:
                setDirection(Direction::South);
                if (MovedtoPosition.y > 1)
                    MovedtoPosition.y--;
                break;
            case 2:
                setDirection(Direction::East);
                if (MovedtoPosition.x < 10)
                    MovedtoPosition.x++;
                break;
            case 3:
                setDirection(Direction::West);
                if (MovedtoPosition.x > 1)
                    MovedtoPosition.x--;
                break;
        }

        setIsWayBlocked(false); // Reset way blocked flag

        setCurrentPosition(MovedtoPosition);
    } else {
        // Move 1 tile in the direction its facing
        Position MovedtoPosition = getPosition();
        switch (getDirection()) {
            case Direction::North:
                if (MovedtoPosition.y < 10)
                    MovedtoPosition.y++;
                break;
            case Direction::South:
                if (MovedtoPosition.y > 1)
                    MovedtoPosition.y--;
                break;
            case Direction::East:
                if (MovedtoPosition.x < 10)
                    MovedtoPosition.x++;
                break;
            case Direction::West:
                if (MovedtoPosition.x > 1)
                    MovedtoPosition.x--;
                break;
        }

        setCurrentPosition(MovedtoPosition); // sets the bug's new position
    }
}




Crawler::~Crawler() {
    // Destructor
}