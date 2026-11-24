#include "AthleticFacility.h"
#include "Player.h"
#include "Game.h"
#include "Bank.h"
#include "Dice.h"

using namespace std;

AthleticFacility::AthleticFacility(string name, int position, int purchasePrice)
    : Ownable{name, position, purchasePrice} {}

bool AthleticFacility::isAthleticFacility() const {
    return true;
}

int AthleticFacility::calculateFacilityFee(int facilityCount, int diceSum) const {
    if (facilityCount == 1) {
        return 4 * diceSum;
    } else if (facilityCount == 2) {
        return 10 * diceSum;
    }

    return 0;
}

void AthleticFacility::chargeRentOrTuition(Player &player, Game &game) const {
    Player *owner = getOwner();

    if (owner == nullptr || owner == &player || isMortgaged()) return;

    int facilityCount = owner->getNumAC();
    game.getDice()->roll();
    int diceSum = game.getDice()->getSum();

    int fee = calculateFacilityFee(facilityCount, diceSum);

    game.getBank()->transferMoney(player, *owner, fee);
}