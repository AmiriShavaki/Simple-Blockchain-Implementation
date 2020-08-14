#include "Chain.h"

void Chain::addBlock(Block newBlock) {
    Block* newCopyBlock = new Block; //This Block variable won't destruct by any destructor because of using int during definition
    *newCopyBlock = newBlock;
    if (genesisBlock == NULL) {
        genesisBlock = newCopyBlock;
        newCopyBlock -> setPrevPtr(NULL);
        lastBlock = newCopyBlock;
    } else {
        newCopyBlock -> setPrevPtr(lastBlock);
        lastBlock = newCopyBlock;
    }
    len++;
}

void Chain::printBlock(int ind) {
    if (ind >= len) {
        cout << "Unfortunatly there is not any block at height " << ind << endl;
    } else {
        cout << "Block #" << ind << endl;
        Block* block = lastBlock;
        for (int i = len - 1; i != ind; i--) {
            block = block -> getPrevPtr();
        }
        cout << "Hash: " << block -> getHash() << endl;
        cout << "Previous block hash: " << block -> getPrevHash() << endl;
        cout << "Index: " << block -> getIndex() << endl;
        cout << "Nonce: " << block -> getNonce() << endl;

        cout << "TimeStamp: ";
        struct tm* ptm = gmtime(block -> getTimeStamp(true));
        //UTC time
        int hour = ptm -> tm_hour;
        int min = ptm -> tm_min;
        //Convert to Tehran time
        if (min >= 30) {
            hour = (hour + 5) % 24;
            min = (min + 30) % 60;
        } else {
            hour = (hour + 4) % 24;
            min = (min + 30) % 60;
        }
        cout << hour << ':' << min << endl;

        cout << "Difficulty: " << block -> getDifficulty() << endl;

        cout << "Number of transactions: " << block -> getTransactions().size() << endl;
        for (int i = 0; i < block -> getTransactions().size(); i++) {
            cout << "from (" << block -> getTransactions()[i].getSender().first << ", " <<
            block -> getTransactions()[i].getSender().second << ") to (" <<
            block -> getTransactions()[i].getRecipient().first << ", " <<
            block -> getTransactions()[i].getRecipient().second << ")   amount: " <<
            block -> getTransactions()[i].getAmount() << endl;
        }
    }
}

void Chain::printChain() {
    for (int i = 0; i < len; i++) {
        printBlock(i);
    }
}
