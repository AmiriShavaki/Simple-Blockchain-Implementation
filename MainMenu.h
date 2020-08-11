//Just check if this class decleared before
#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <string>
#include "Network.h"
#include <utility> //Using pair

using namespace std;

class MainMenu {
public:
    MainMenu(){}
    void print() const;
    const bool input(Network& net) const;
};

#endif
