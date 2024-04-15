#include <iostream>
#include <vector>
#include "Bug.h"
#include "Crawler.h"
#include "Board.h"

using namespace std;

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Initialise the bug Board\n";
    cout << "2. Display All Bugs\n";
    cout << "3. Find a Bug\n";
    cout << "4. Tap the Bug Board\n";
    cout << "5. Display Life History of all Bugs\n";
    cout << "6. Exit\n";
    cout << "7. Display all Cells\n";
    cout << "8. Run Simulation\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<Bug *> bugs; // Vector to store Bug
    Board board;

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                board.createBugs(bugs); // Use the Board instance to create bugs
                cout << "\nBugs have been created.\n" << endl;
                break;

            case 2: {
                board.displayAllBugs(bugs);
                break;
            }

            case 3: {
                int searchedBug;
                cout << "Enter Bug ID to search: ";
                cin >> searchedBug;
                board.findBugById(bugs, searchedBug);
                break;
            }

            case 4:

                break;

            case 5:



                break;

            case 6:




                break;

            case 7:
                board.displayAllCells(bugs);
                break;


            case 8:
                // Implement exit
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
                break;
        }
    } while (choice != 6);

    // Deletes all bugs when done to free memory
    for (Bug *bug : bugs) {
        delete bug;
    }

    return 0;
}


