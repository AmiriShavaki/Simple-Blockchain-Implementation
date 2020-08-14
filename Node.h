//Just check if this class decleared before
#ifndef NODE_H
#define NODE_H

#include <string>
#include <utility>
#include "Chain.h"
#include "transaction.h"
#include "Block.h"
#include <cstddef>
#include "sha256.h"
#include "StringUtility.h"
#include <iostream> ///////////////////////////////////////////////////

using namespace std;

const int MAXTRANSACTIONSPERBLOCK = 3;

class Node {
public:
    Node(){}

    //We will copy the whole chain from the oldest node in the network
    Node(pair < int, int > publicKey, Node* firstNode):publicKey(publicKey){ copyChain(firstNode); }
    const Chain getBlockchain() const { return blockchain; }
    const pair < int, int > getPublicKey() const { return publicKey; }
    void addToMemPool(Transaction t);
    void mine(int difficulty);
private:
    pair < int, int > publicKey;
    Chain blockchain;
    void copyChain(Node* firstNode);
    vector < Transaction > transactionQ; //Memory pool
};

#endif
