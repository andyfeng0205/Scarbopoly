#ifndef SPECIAL_H
#define SPECIAL_H

#include "Square.h"
#include <string>
using namespace std;

class Player;
class Game;

class Special : public Square {
public:
    Special(const string &name, int position);
    virtual ~Special() = default;

    virtual void landOn(Player &player, Game &game) override = 0;
};

#endif
