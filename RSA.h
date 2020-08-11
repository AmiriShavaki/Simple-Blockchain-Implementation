//Just check if this class decleared before
#ifndef RSA_H
#define RSA_H

#include <vector>

using namespace std;

class RSA {
public:
    static vector < int > go(int e, int n, vector < int > m);
};

#endif
