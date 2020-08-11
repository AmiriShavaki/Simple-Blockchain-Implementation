//Just check if this class decleared before
#ifndef CHAIN_H
#define CHAIN_H

#include "Block.h"
#include <cstddef> //using NULL

class Chain {
private:
    Block* lastBlock;
    Block* genesisBlock;
public:
    Chain():lastBlock(NULL), genesisBlock(NULL) {}
};

#endif
