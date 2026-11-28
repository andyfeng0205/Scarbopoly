#include "Residence.h"
#include "Game.h"
#include "Player.h"

const int BASE_RENT = 25;

Residence::Residence(const std::string &name, int position, int purchasePrice)
    : Ownable{name, position, purchasePrice} {}

int Residence::calculateResidenceRent(int residenceCount) const {
    if (residenceCount <= 0) return 0;
    int rent = BASE_RENT;
    for (int i = 1; i < residenceCount; ++i) {
        rent *= 2;
    }
    return rent;
}

void Residence::chargeRentOrTuition(Player &player, Game &game) const {
    if (owner == nullptr || owner == &player || isMortgaged()) {
        return;
    }
    game.handlePayment(player, owner, calculateResidenceRent(owner->getNumResidence()));
}