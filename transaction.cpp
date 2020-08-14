#include "transaction.h"

const string Transaction::getString() const {
    string result;
    result += StringUtility::convertNumberToString(sender.first);
    result += StringUtility::convertNumberToString(sender.second);
    result += StringUtility::convertNumberToString(recipient.first);
    result += StringUtility::convertNumberToString(recipient.second);
    result += StringUtility::convertNumberToString(amount);
    return result;
}
