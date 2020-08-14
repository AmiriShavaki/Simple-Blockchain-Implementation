#include "Network.h"

const bool Network::findNode(pair < int, int > publicKey) const {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i].getPublicKey() == publicKey) {
            return true;
        }
    }
    return false;
}

void Network::addANode(pair < int, int > publicKey) {
    nodes.push_back(Node(publicKey, (nodes.empty()?NULL:&nodes[0])));
}

void Network::removeNode(pair < int, int > publicKey) {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i].getPublicKey() == publicKey) {
            nodes.erase(nodes.begin() + i);
        }
    }
}

void Network::addTransaction(Transaction t) {
    for (int i = 0; i < nodes.size(); i++) {
            nodes[i].addToMemPool(t); //Each node in the network will have a copy of new transaction
    }
}

void Network::mine(pair < int, int > publicKey, int difficulty) {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i].getPublicKey() == publicKey) { //We found the miner node!
            Block newBock = nodes[i].mine(difficulty); //Mining process

            int verifiedCount = 0; //Number of nodes verified the new block
            for (int j = 0; j < nodes.size(); j++) { //Consensus
                if (j != i) { //Every node except the miner of the block should verify hash of the block
                    verifiedCount += nodes[j].verifyBlock(newBock);
                }
            }
            cout << "Block verified by " << verifiedCount << " Nodes.\n";
            if (verifiedCount >= (nodes.size() - 1) / 2) { //More than 50% of the nodes verified the block
                cout << "Block verification successfully made!\n";
            } else {
                cout << "Block verification was unsuccessful\n";
            }
        }
    }
}
