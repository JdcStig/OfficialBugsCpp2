

#include "Crawler.h"
#include "Bug.h"
#include "Board.h"
#include "Hopper.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>

using namespace std;

void Board::displayAllBugs(const vector<Bug*>& bugs)
{

    cout << "All Bugs:\n";
    for (Bug* b : bugs) {
        if (b != nullptr) {
            int bugX = b->getPosition().x;
            int bugY = b->getPosition().y;

            cout << "Bug Type: " << b->getType() << " Bug ID: " << b->getId() << ", Position: (" << bugX << ", "
                 << bugY << "), Direction: ";

            switch (b->getDirection()) {
                case Direction::North:
                    cout << "North";
                    break;
                case Direction::East:
                    cout << "East";
                    break;
                case Direction::South:
                    cout << "South";
                    break;
                case Direction::West:
                    cout << "West";
                    break;
            }

            cout << ", Size: " << b->getSize() << ", Hop Length: " << b->gethopLength() << " , State: ";

            if (b->getDorA())
                cout << "Alive\n";
            else
                cout << "Dead\n";
        }
    }
}




void Board::createBugs(vector<Bug*>& bugs) {


    ifstream inputFile("bugs.txt");
    if (!inputFile) {
        cout << "Cannot open file bugs.txt" << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string token;

        getline(ss, token, ';'); // Type
        char type = token[0];

        getline(ss, token, ';'); // id
        int id = stoi(token);   // stoi converts a string number into an integer

        getline(ss, token, ';'); // x
        int x = stoi(token);

        getline(ss, token, ';'); // y
        int y = stoi(token);

        getline(ss, token, ';'); // direction

        Direction direction;

        switch (stoi(token)) {
            case 0:
            {
                direction = Direction::North;
                break;
            }
            case 1:
            {

                direction = Direction::South;
                break;
            }

            case 2:
            {
                direction = Direction::East;
                break;
            }
            case 3:
            {
                direction = Direction::West;
                break;
            }
        }

        getline(ss, token, ';'); // size
        int size = stoi(token);

        getline(ss, token, ';'); // hop Length
        int hopLength = stoi(token);

        // Create Crawler or Hopper
        Bug* bug;
        if (type == 'C') {
            bug = new Crawler(type, id, x, y, direction, size, hopLength, true, false);
        } else if (type == 'H') {
            bug = new Hopper(type, id, x, y, direction, size, hopLength, true, false);
        } else {
            // Handle invalid bug type
            cout << "Invalid bug type: " << type << endl;
            continue;
        }


        bugs.push_back(bug);
    }
    inputFile.close();
}


Bug* Board::findBugById(const vector<Bug*>& bugs, int id) {

    for (Bug* bug : bugs) {
        if (bug->getId() == id) {

            cout << "\n --Type: " << bug->getType() << endl;
            cout << " --ID: " << bug->getId() << endl;
            cout << " --Position: (" << bug->getPosition().x << " , " << bug->getPosition().y << ")\n";
            cout << " --Direction: ";
            switch (bug->getDirection()) {
                case Direction::North:
                    cout << "North\n";
                    break;
                case Direction::East:
                    cout << "East\n";
                    break;
                case Direction::South:
                    cout << "South\n";
                    break;
                case Direction::West:
                    cout << "West\n";
                    break;
            }
            cout << " --Size: " << bug->getSize() << endl;
            cout << " --Hop Length: " << bug->gethopLength() << "\n" << endl;
        }
    }

    return nullptr;
}


void Board::tap(vector<Bug*>& bugs)
{
    cout << "Tap" << endl;
    MoveBugs(bugs);
}

void Board::MoveBugs(vector<Bug*>& bugs)
{
    cout << "MoveBugs" << endl;
    cout << bugs.size() << endl;
    for (int i = 0; i < bugs.size(); i++)
    {
        bugs[i]->move();
    }
}


