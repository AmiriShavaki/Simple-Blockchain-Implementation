//Just check if this class decleared before
#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "Node.h"
#include <string>
#include <utility>

using namespace std;

class Network {
private:
    vector < Node > nodes;
public:
    void addANode(pair < int, int > publicKey) { nodes.push_back(Node(publicKey)); }
};

#endif
