#include "MainMenu.h"
#include "Network.h"

int main() {
    Network net;
    MainMenu menu;
    while (true) {
        menu.print();
        if (menu.input(net)) {
            break;
        }
    }
}
