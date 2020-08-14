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
    Block* prevPtr; //Pointer to previous block. it is NULL for genesis block
    int index; //Height of block in the chain
    int nonce;
    time_t timeStamp;
    int difficulty;
    vector < Transaction > transactions;
public:
    Block(){ prevPtr = NULL; }
    Block(string PrevHash, int index, int difficulty, vector < Transaction > transactions);
    const string getHash() const { return curBlockHash; }
    const string getPrevHash() const { return PrevHash; }
    void setHash(string curHash){ curBlockHash = curHash; }
    const int getIndex() const { return index; }
    const int getNonce() const { return nonce; }
    const int getTimeStamp() const { return timeStamp; }
    time_t* getTimeStamp(bool _) { return &timeStamp; }
    const int getDifficulty() const { return difficulty; }
    void setNonce(int nonce) { this -> nonce = nonce; }
    void setPrevPtr(Block* prevPtr) { this -> prevPtr = prevPtr; }
    Block* getPrevPtr() { return prevPtr; }
    vector < Transaction > getTransactions() const { return transactions; }
};

#endif


