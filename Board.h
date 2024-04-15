
#include "Bug.h"
#include <vector>

#ifndef NEWESTBUGSPROJECT_BOARD_H
#define NEWESTBUGSPROJECT_BOARD_H


class Board {
public:
    void createBugs(std::vector<Bug*>& bugs);
    void displayAllBugs(const std::vector<Bug*>& bugs);
    Bug* findBugById(const std::vector<Bug*>& bugs, int id);
    void tap(std::vector<Bug*>& bugs);
    void MoveBugs(std::vector<Bug*>& bugs);

};


#endif //NEWESTBUGSPROJECT_BOARD_H
