#include "Block.h"

Block::Block(string PrevHash, int index, int difficulty, vector < Transaction > transactions):
    PrevHash(PrevHash), index(index), difficulty(difficulty), transactions(transactions) {

    time(&timeStamp); //filling timeStamp

    nonce = 0; //Initial nonce
}
