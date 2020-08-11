#include "MainMenu.h"

int main() {
    MainMenu menu;
    while (true) {
        menu.print();
        if (menu.input()) {
            break;
        }
    }
}
