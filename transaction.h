//Just check if this class decleared before
#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction {
private:
    int sender; //Public key
    int recipient; //Public key
    int amount;
public:
    const int getSender() const { return sender; }
    const int getRecipient() const { return recipient; }
    const int getAmount() const { return amount; }
    Transaction(){}
    Transaction(int sender, int recipient, int amount): sender(sender), recipient(recipient), amount(amount) {}
};

#endif
