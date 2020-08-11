#include "MainMenu.h"

void MainMenu::print() const {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "            Main Menu              \n";
    cout << "1.Add a node to the network\n";
    cout << "2.Remove a node from the network\n";
    cout << "3.Mine a block\n";
    cout << "4.Make a transaction\n";
    cout << "5.Show the whole chain\n";
    cout << "6.Show block at a specific block index\n";
    cout << "7.Quit\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

const bool MainMenu::input() const {
    string line;
    getline(cin, line);
    if (line.size() > 1) {
        cout << "!!!!!!!!!!!!!!!!!!!!! Error !!!!!!!!!!!!!!!!!!!!!!!\n";
        cout << "Plesae do not enter anything but a number between 1 to 7 in order to choose an option from Main Menu\n";
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    } else {
        switch (line[0]) {
            case '1': { //Add a node to the network
                cout << "Add a node to the network\n";
            } break;
            default: {
                cout << "!!!!!!!!!!!!!!!!!!!!! Error !!!!!!!!!!!!!!!!!!!!!!!\n";
                cout << "Plesae do not enter anything but a number between 1 to 7 in order to choose an option from Main Menu\n";
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
            }
        }
    }
}
