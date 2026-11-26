#include "CampusBuilding.h"
#include "Player.h"
#include "Game.h"

using namespace std;

CampusBuilding::CampusBuilding(string name, int position, int purchasePrice, string monopolyBlock, int improvementCost, int tuition[6])
    : Ownable{name, position, purchasePrice}, monopolyBlock{monopolyBlock}, improvementLevel{0}, improvementCost{improvementCost} {
    for (int i = 0; i < 6; ++i) {
        this->tuition[i] = tuition[i];
    }
}

void CampusBuilding::landOn(Player &player, Game &game) {
    if (owner != nullptr && owner != &player) {
        chargeRentOrTuition(player, game);
    }
}

// charge player, other than the owner, the respective
void CampusBuilding::chargeRentOrTuition(Player &player, Game &game) const {
    if (owner == nullptr || owner == &player || isMortgaged()) {
        return;
    }
    int amount = tuition[improvementLevel];
    // TODO: double amount if improvementLevel == 0 and owner has the whole monopoly
    game.handlePayment(player, owner, amount);
}

// improve the campus building, and changes its tuition
void CampusBuilding::improve() {
    if (improvementLevel < 5) {
        improvementLevel++;
    }
}

// sell an improvement
void CampusBuilding::sellImprovement() {
    if (improvementLevel > 0) {
        improvementLevel--;
    }
}

// return the improvement price
int CampusBuilding::getImprovementPrice() const{
    return improvementCost;
}

// return the improvement level
int CampusBuilding::getImprovementLevel() const {
    return improvementLevel;
}

// return the monopoly block
string CampusBuilding::getMonopolyBlock() const {
    return monopolyBlock;
}