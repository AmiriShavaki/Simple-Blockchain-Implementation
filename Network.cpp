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
