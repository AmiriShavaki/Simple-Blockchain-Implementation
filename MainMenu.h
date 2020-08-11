//Just check if this class decleared before
#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <string>

#include "RSA.h"

using namespace std;

class MainMenu {
public:
    MainMenu(){}
    void print() const;
    const bool input() const;
};

#endif
