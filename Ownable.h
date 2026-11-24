
#ifndef OWNABLE_H
#define OWNABLE_H

#include "Square.h"
#include <string>
using namespace std;

class Player;
class Game;

class Ownable : public Square {
protected:
    Player *owner;
    int purchasePrice;
    bool mortgaged;

public:
    Ownable(string &name, int position, int purchasePrice);
    virtual ~Ownable() = default;

    void landOn(Player &player, Game &game) override;

    virtual void chargeRentOrTuition(Player &player, Game &game) const = 0;

    void transferOwnership(Player *newOwner);
    void mortgage();
    void unmortgage();

    Player *getOwner() const;
    int getPurchasePrice() const;
    bool isMortgaged() const;

    virtual bool isResidence() const;
    virtual bool isAthleticFacility() const;
};

#endif
