#include <iostream>
#include <utility>
#include "RSA.h"
#include <vector>

using namespace std;

int main() {
    cout << "Please enter your valid private key pair: ";
    pair < int, int > privateKey;
    cin >> privateKey.first >> privateKey.second;

    cout << "Please enter three numbers to start encryption process: ";
    vector < int > numbers(3);
    cin >> numbers[0] >> numbers[1] >> numbers[2];

    vector < int > res = RSA::go(privateKey.first, privateKey.second, numbers);
    cout << "Result: " << res[0] << ' ' << res[1] << ' ' << res[2];

    char junk;
    cin >> junk; //Prevent terminal from close immediately
}
