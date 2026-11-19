#include "Dice.h"
#include <cstdlib>

Dice::Dice() : dice1{0}, dice2{0} {}

Dice::Dice(int dice1, int dice2)
    : dice1{dice1}, dice2{dice2} {}

void Dice::roll() {
    dice1 = rand() % 6 + 1; // generate a number between 1 and 6
    dice2 = rand() % 6 + 1;
}

int Dice::getDice1() const {
    return dice1;
}

int Dice::getDice2() const {
    return dice2;
}
