#ifndef SQUARE_H
#define SQUARE_H

#include "Square.h"
#include <string>
using namespace std;

class Player;
class Game;

class Special : public Square {
    
public:
    void landOn(Player &player, Game &game);
};

#endif