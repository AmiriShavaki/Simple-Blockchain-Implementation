//Just check if this class decleared before
#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include "Transaction.h"
#include <ctime>

using namespace std;

class Block {
private:
    string curBlockHash;
    string PrevHash; //Empty string for genesis block
    int index; //Height of block in the chain
    int nonce;
    time_t timeStamp;
    int difficulty;
    vector < Transaction > transactions;
public:
    Block();
    Block(string PrevHash, int index, int difficulty, vector < Transaction > transactions);
    const string getHash() const { return curBlockHash; }
    void setHash(string curHash){ curBlockHash = curHash; }
    const int getIndex() const { return index; }
    const int getNonce() const { return nonce; }
    const int getTimeStamp() const { return timeStamp; }
    void setNonce(int nonce) { this -> nonce = nonce; }
};

#endif


