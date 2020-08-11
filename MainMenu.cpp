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

const bool MainMenu::input(Network& net) const {
    string line;
    getline(cin, line);
    if (line.size() > 1) {
        cout << "!!!!!!!!!!!!!!!!!!!!! Error !!!!!!!!!!!!!!!!!!!!!!!\n";
        cout << "Plesae do not enter anything but a number between 1 to 7 in order to choose an option from Main Menu\n";
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    } else {
        switch (line[0]) {
            case '1': {
                cout << endl;
                cout << "         Add a node to the network          \n";
                cout << "Please enter your valid base10 public key pair: ";
                pair < int, int > publicKey;
                cin >> publicKey.first >> publicKey.second;
                getline(cin, line); //Ignore rest of the line input and make a fresh line for input buffer
                net.addANode(publicKey);
            } break;
            case '7': {
                cout << endl;
                cout << "Program terminated successfully!\n";
                return true; //It means mainloop should terminate the program
            } break;
            default: {
                cout << "!!!!!!!!!!!!!!!!!!!!! Error !!!!!!!!!!!!!!!!!!!!!!!\n";
                cout << "Plesae do not enter anything but a number between 1 to 7 in order to choose an option from Main Menu\n";
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
            }
        }
    }
    return false; //It means mainloop should not terminate the program
}
