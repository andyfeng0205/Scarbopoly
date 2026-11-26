#ifndef BANK_H
#define BANK_H

class Player;
class Ownable;
class CampusBuilding;

/*
 * The Bank class is responsible for managing financial transactions
 * throughout the game, including purchasing properties, transferring
 * money between players, buying and selling improvements, and
 * mortgaging and unmortgaging properties.
 *
 * The Bank also validates transactions to ensure that players have
 * sufficient funds and meet the necessary requirements.
 *
 * The Bank does not maintain its own balance, as it has an
 * unlimited supply of money.
 */

class Bank {
public:
    Bank();

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