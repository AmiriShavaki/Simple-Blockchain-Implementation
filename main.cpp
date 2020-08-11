#include "MainMenu.h"

int main() {
    MainMenu menu;
    while (true) {
        menu.print();
        menu.input();
    }
}
