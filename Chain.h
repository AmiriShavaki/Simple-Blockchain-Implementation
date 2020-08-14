//Just check if this class decleared before
#ifndef CHAIN_H
#define CHAIN_H

#include "Block.h"
#include <cstddef> //using NULL

class Chain {
private:
    Block* lastBlock;
    Block* genesisBlock;
    int len; //Length of the chain
public:
    Chain():lastBlock(NULL), genesisBlock(NULL), len(0) {}
    const int getLen() const { return len; }
    Block* getLastBlock() { return lastBlock; }
};

#endif
