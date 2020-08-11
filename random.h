//Just check if this class decleared before
#ifndef RADNOM_H
#define RANDOM_H

#include <cstdlib>
#include <ctime>
#include <cstddef>

using namespace std;

class Random {
public:
    Random() { srand(time(NULL)); }
    const int go(int s, int e) const; //Interval [s, e]
};

#endif
