#include "Node.h"

void Node::copyChain(Node* firstNode) {
    if (firstNode != NULL) {
        blockchain = firstNode -> getBlockchain();
    }
}
