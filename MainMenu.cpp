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

                cout << "Please encrypt below numbers with your private key and enter result to ensure us entered public key is yours\n";
                vector < int > r(3);
                r[0] = rng.go(1, publicKey.second - 1);
                r[1] = rng.go(1, publicKey.second - 1);
                r[2] = rng.go(1, publicKey.second - 1);
                cout << r[0] << ' ' << r[1] << ' ' << r[2] << '\n';

                cout << "Enter result of encryption: ";
                vector < int > res(3);
                cin >> res[0] >> res[1] >> res[2];

                getline(cin, line); //Ignore rest of the line input and make a fresh line for input buffer

                if (RSA::go(publicKey.first, publicKey.second, res) != r) {
                    cout << "There is a problem with your encryption or your private key\n\n";
                } else if (net.findNode(publicKey)) {
                    cout << "There is another node in the network with the given public key\n\n";
                } else {
                    net.addANode(publicKey);
                    cout << "Successfully added!\n\n";
                }
            } break;

            case '2': {
                cout << endl;
                cout << "         Remove a node from the network          \n";
                cout << "Please enter your valid base10 public key pair: ";
                pair < int, int > publicKey;
                cin >> publicKey.first >> publicKey.second;

                cout << "Please encrypt below numbers with your private key and enter result to ensure us entered public key is yours\n";
                vector < int > r(3);
                r[0] = rng.go(1, publicKey.second - 1);
                r[1] = rng.go(1, publicKey.second - 1);
                r[2] = rng.go(1, publicKey.second - 1);
                cout << r[0] << ' ' << r[1] << ' ' << r[2] << '\n';

                cout << "Enter result of encryption: ";
                vector < int > res(3);
                cin >> res[0] >> res[1] >> res[2];

                getline(cin, line); //Ignore rest of the line input and make a fresh line for input buffer

                if (RSA::go(publicKey.first, publicKey.second, res) != r) {
                    cout << "There is a problem with your encryption or your private key\n\n";
                } else if (!net.findNode(publicKey)) {
                    cout << "There is not any stored node in the network with the given public key\n\n";
                } else {
                    net.removeNode(publicKey);
                    cout << "Successfully Removed!\n\n";
                }
            } break;

            case '3': {
                cout << endl;
                cout << "         Mine a block          \n";

                cout << "Please enter difficulty of minning the block: (or just press enter to set difficulty to 4 by default) ";
                int difficulty;
                getline(cin, line);
                if (line.size() == 0) {
                    difficulty = 4;
                } else {
                    difficulty = StringUtility::convertStringToNumber(line);
                }

                cout << "Please enter miner's valid base10 public key pair: ";
                pair < int, int > publicKey;
                cin >> publicKey.first >> publicKey.second;

                cout << "Please encrypt below numbers with your private key and enter result to ensure us entered public key is yours\n";
                vector < int > r(3);
                r[0] = rng.go(1, publicKey.second - 1);
                r[1] = rng.go(1, publicKey.second - 1);
                r[2] = rng.go(1, publicKey.second - 1);
                cout << r[0] << ' ' << r[1] << ' ' << r[2] << '\n';

                cout << "Enter result of encryption: ";
                vector < int > res(3);
                cin >> res[0] >> res[1] >> res[2];

                getline(cin, line); //Ignore rest of the line input and make a fresh line for input buffer

                if (RSA::go(publicKey.first, publicKey.second, res) != r) {
                    cout << "There is a problem with your encryption or your private key\n\n";
                } else if (!net.findNode(publicKey)) {
                    cout << "There is not any stored node in the network with the given public key\n\n";
                } else {
                    net.mine(publicKey, difficulty);
                }

            } break;

            case '4': {
                cout << endl;
                cout << "         Make a transaction          \n";

                cout << "Please enter sender's valid base10 public key pair: ";
                pair < int, int > publicKey1;
                cin >> publicKey1.first >> publicKey1.second;

                cout << "Please enter recipient's valid base10 public key pair: ";
                pair < int, int > publicKey2;
                cin >> publicKey2.first >> publicKey2.second;

                cout << "Please enter amount: ";
                int amount;
                cin >> amount;

                cout << "Please encrypt below numbers with sender's private key and enter result to ensure us entered public key is yours\n";
                vector < int > r(3);
                r[0] = rng.go(1, publicKey1.second - 1);
                r[1] = rng.go(1, publicKey1.second - 1);
                r[2] = rng.go(1, publicKey1.second - 1);
                cout << r[0] << ' ' << r[1] << ' ' << r[2] << '\n';

                cout << "Enter result of encryption: ";
                vector < int > res(3);
                cin >> res[0] >> res[1] >> res[2];

                getline(cin, line); //Ignore rest of the line input and make a fresh line for input buffer

                if (RSA::go(publicKey1.first, publicKey1.second, res) != r) {
                    cout << "There is a problem with your encryption or sender's private key\n\n";
                } else if (!net.findNode(publicKey1)) {
                    cout << "There is not any stored node in the network with the given sender's public key\n\n";
                } else if (!net.findNode(publicKey2)) {
                    cout << "There is not any stored node in the network with the given recipient's public key\n\n";
                } else {
                    net.addTransaction(Transaction(publicKey1, publicKey2, amount));
                    cout << "Transaction successfully made!\n\n";
                }
            } break;

            case '5': {
                cout << endl;
                cout << "         Show the whole chain          \n";

                if (net.isEmpty()) {
                    cout << "Unfortunately there is not any node in the network\n";
                } else {
                    net.getFirstNodePtr() -> getBlockchain() -> printChain();
                }
            } break;

            case '6': {
                cout << endl;
                cout << "         Show block at a specific block index          \n";

                cout << "Please enter index of the block you want to see: ";
                int index;
                cin >> index;
                net.getFirstNodePtr() -> getBlockchain() -> printBlock(index);

                getline(cin, line); //Ignore rest of the line
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
            } break;
        }
    }
    return false; //It means mainloop should not terminate the program
}
