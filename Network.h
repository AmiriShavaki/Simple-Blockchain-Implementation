//Just check if this class decleared before
#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "Node.h"
#include <string>
#include <utility>
#include "transaction.h"

using namespace std;

class Network {
private:
    vector < Node > nodes;
public:
    void addANode(pair < int, int > publicKey);
    const bool findNode(pair < int, int > publicKey) const;
    void removeNode(pair < int, int > publicKey);
    void addTransaction(Transaction t);
};

#endif
