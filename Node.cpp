#include "Node.h"

void Node::copyChain(Node* firstNode) {
    if (firstNode != NULL) {
        blockchain = firstNode -> getBlockchain();
    }
}

void Node::addToMemPool(Transaction t) {
    transactionQ.push_back(t);
}

void Node::mine(int difficulty) {
    string prevHash = (blockchain.getLastBlock() == NULL ? "" : blockchain.getLastBlock() -> getHash());

    vector < Transaction > transactions;
    for (int i = 0; i < MAXTRANSACTIONSPERBLOCK && i < transactionQ.size(); i++) { //Add transactions from mempool
        transactions.push_back(transactionQ[i]);
    }

    Block newBlock(prevHash, blockchain.getLen(), difficulty, transactions);

    string input; //Input of hash function
    input += prevHash;
    input += StringUtility::convertNumberToString(newBlock.getIndex());
    input += StringUtility::convertNumberToString(newBlock.getNonce());
    input += StringUtility::convertNumberToString(newBlock.getTimeStamp());
    input += StringUtility::convertNumberToString(difficulty);
    for (int i = 0; i < transactions.size(); i++) {
        input += transactions[i].getString();
    }
    string output = sha256(input);
    while (!StringUtility::isAllZero(output.substr(0, difficulty))) {
        input = "";
        input += prevHash;
        input += StringUtility::convertNumberToString(newBlock.getIndex());
        newBlock.setNonce(newBlock.getNonce() + 1); //New nonce
        input += StringUtility::convertNumberToString(newBlock.getNonce());
        input += StringUtility::convertNumberToString(newBlock.getTimeStamp());
        input += StringUtility::convertNumberToString(difficulty);
        for (int i = 0; i < transactions.size(); i++) {
            input += transactions[i].getString();
        }
        output = sha256(input);
    }
    cout << "output hash: " << output << "\n\n\n\n\n";
}
