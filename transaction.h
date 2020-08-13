//Just check if this class decleared before
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <utility>

using namespace std;

class Transaction {
private:
    pair < int, int > sender; //Public key
    pair < int, int > recipient; //Public key
    int amount;
public:
    const pair < int, int > getSender() const { return sender; }
    const pair < int, int > getRecipient() const { return recipient; }
    const int getAmount() const { return amount; }
    Transaction(){}
    Transaction(pair < int, int > sender, pair < int, int > recipient, int amount): sender(sender), recipient(recipient), amount(amount) {}
};

#endif
