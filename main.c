#include "bintree.h"
#include "menu.h"

int main() {
    system("cls");

    BinTree morseTree;
    createMorseTree(&morseTree);

    binTreeLobby(morseTree);

    return 0;
}