//Just check if this class decleared before
#ifndef NODE_H
#define NODE_H

#include <string>
#include <utility>

using namespace std;

class Node {
public:
    Node(){}
    Node(pair < int, int > publicKey):publicKey(publicKey){}
private:
    pair < int, int > publicKey;
};

#endif
