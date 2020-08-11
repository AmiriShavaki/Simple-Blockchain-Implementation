#include "random.h"

 const int Random::go(int s, int e) const {
     return rand() % (e - s + 1) + s;
 }
