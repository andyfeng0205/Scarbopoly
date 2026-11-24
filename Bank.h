#ifndef BANK_H
#define BANK_H

class Player;
class Ownable;
class CampusBuilding;

class Bank {
public:
    Bank() = default;

    // Basic financial transactions
    void payPlayer(Player &player, int amount);
    bool collectMoney(Player &player, int amount);
    bool transferMoney(Player &from, Player &to, int amount);

    // Property transactions
    bool purchaseProperty(Player &player, Ownable &property);

    // Improvement transactions
    bool purchaseImprovement(Player &player, CampusBuilding &building);
    bool sellImprovement(Player &player, CampusBuilding &building);

    // Mortgage transactions
    bool mortgage(Player &player, Ownable &property);
    bool unmortgage(Player &player, Ownable &property);
};

#endif