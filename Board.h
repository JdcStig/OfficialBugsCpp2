//
// Created by duffy on 15/04/2024.
//
#include "Bug.h"
#include <vector>

#ifndef NEWESTBUGSPROJECT_BOARD_H
#define NEWESTBUGSPROJECT_BOARD_H


class Board {
public:
    void createBugs(std::vector<Bug*>& bugs);
    void displayAllBugs(const std::vector<Bug*>& bugs);
    Bug* findBugById(const std::vector<Bug*>& bugs, int id);


};


#endif //NEWESTBUGSPROJECT_BOARD_H
