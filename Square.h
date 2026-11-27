#ifndef SQUARE_H
#define SQUARE_H

#include <string>
using namespace std;

class Player;
class Game;

class Square {
protected:
    string name;
    int position;

public:
    Square(string name, int position);
    virtual ~Square();

    string getName() const;
    int getPosition() const;

    virtual int getImprovementLevel() const;
    virtual void landOn(Player &player, Game &game) = 0;
};

#endif
