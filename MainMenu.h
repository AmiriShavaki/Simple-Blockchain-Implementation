//Just check if this class decleared before
#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <string>
#include "Network.h"
#include <utility> //Using pair
#include "RSA.h"
#include "random.h"
#include "StringUtility.h"

using namespace std;

class MainMenu {
public:
    MainMenu(){}
    void print() const;
    const bool input(Network& net) const;
private:
    Random rng; //Random number generator
};

#endif
