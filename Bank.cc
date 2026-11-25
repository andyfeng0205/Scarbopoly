#include "Bank.h"
#include "Player.h"
#include "Ownable.h"
#include "CampusBuilding.h"
using namespace std;

Bank::Bank() = default;

void Bank::payPlayer(Player &player, int amount) {
    player.recieve(amount);
}

bool Bank::collectMoney(Player &player, int amount) {
    if(player.getMoney() < amount) {
        return false;
    }

    player.pay(amount);
    return true;
}

bool Bank::transferMoney(Player &from, Player &to, int amount) {
    if(!collectMoney(from, amount)) return false;

    payPlayer(to, amount);
    return true;
}

bool Bank::purchaseProperty(Player &player, Ownable &property) {
    if (property.getOwner() != nullptr) return false;
    if (!collectMoney(player, property.getPurchasePrice())) return false;

    player.addProperty(&property);
    property.setOwner(&player);

    return true;
}

bool Bank::purchaseImprovement(Player &player, CampusBuilding &building) {
    if(building.getOwner() != &player) return false;
    if(!collectMoney(player, building.getImprovementPrice())) return false;

    building.improve();

    return true;
}

bool Bank::sellImprovement(Player &player, CampusBuilding &building) {
    if(building.getOwner() != &player) return false;

    building.sellImprovement();
    
    payPlayer(player, building.getImprovementPrice() / 2);

    return true;
}

bool Bank::mortgage(Player &player, Ownable &property) {
    if (property.getOwner() != &player) return false;

    if (property.isMortgaged()) return false;

    CampusBuilding *building = dynamic_cast<CampusBuilding *>(&property);

    if (building != nullptr) {
        if (building->getImprovementLevel() > 0) {
            return false;
        }
    }
    
    payPlayer(player, property.getPurchasePrice() / 2);
    property.mortgage();

    return true;
}

bool Bank::unmortgage(Player &player, Ownable &property) {
    if(property.getOwner() != &player) return false;

    if(!property.isMortgaged()) return false;

    if(!collectMoney(player, 0.6 * property.getPurchasePrice())) return false;

    property.unmortgage();

    return true;
}