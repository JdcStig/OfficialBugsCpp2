
#ifndef CRAWLER_H
#define CRAWLER_H

#include "Bug.h"

class Crawler : public Bug {
    vector<Bug *> bugs;
public:


    Crawler(char type, int id, int x, int y, Direction direction, int size, int hopLength, bool alive,bool isWayBlocked);

    // Override the move so it will work of the code in the crawler.cpp
    void move() override ;


    // Destructor
    ~Crawler();



};

#endif // CRAWLER_H
