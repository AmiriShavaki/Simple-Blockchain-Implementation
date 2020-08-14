//Just check if this class decleared before
#ifndef CHAIN_H
#define CHAIN_H

#include "Block.h"
#include <cstddef> //using NULL
#include <iostream>
#include <ctime>

class Chain {
private:
    Block* lastBlock;
    Block* genesisBlock;
    int len; //Length of the chain
public:
    Chain():lastBlock(NULL), genesisBlock(NULL), len(0) {}
    const int getLen() const { return len; }
    Block* getLastBlock() { return lastBlock; }
    void addBlock(Block newBlock);
    void printBlock(int ind);
    void printChain();
};

#endif
