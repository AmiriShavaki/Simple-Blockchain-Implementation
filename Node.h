//Just check if this class decleared before
#ifndef NODE_H
#define NODE_H

#include <string>
#include <utility>
#include "Chain.h"
#include <queue>
#include "transaction.h"

using namespace std;

class Node {
public:
    Node(){}

    //We will copy the whole chain from the oldest node in the network
    Node(pair < int, int > publicKey, Node* firstNode):publicKey(publicKey){ copyChain(firstNode); }
    const Chain getBlockchain() const { return blockchain; }
    const pair < int, int > getPublicKey() const { return publicKey; }
    void addToMemPool(Transaction t);
private:
    pair < int, int > publicKey;
    Chain blockchain;
    void copyChain(Node* firstNode);
    queue < Transaction > transactionQ; //Memory pool
};

#endif
