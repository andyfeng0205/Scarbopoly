#include "Player.h"
#include "Ownable.h"
#include <algorithm>

using namespace std;

// Player ctor, no arguments, default values for all fields
Player::Player() 
    : name{""}, piece{' '}, money{1500}, position{0}, inTims{false}, currentTimsTurn{0}, 
    numCups{0}, bankrupt{false}, consecutiveDoubles{0}, properties{} {}

// Player ctor, with arguments
Player::Player(std::string name, char piece, int money, int position, bool inTims, int currentTimsTurn, 
    int numCups, bool bankrupt, int consecutiveDoubles, std::vector<Ownable *> properties)
    : name{name}, piece{piece}, money{money}, position{position}, inTims{inTims}, currentTimsTurn{currentTimsTurn},
    numCups{numCups}, bankrupt{bankrupt}, consecutiveDoubles{consecutiveDoubles}, properties{properties} {}

// update the player's position
void Player::move(int step) {
    position = (position + step) % 40;
}

// update the player's money, subtracting the amount to pay
void Player::pay(int numToPay) {
    money -= numToPay;
}

// update the player's money, adding the amount to receive
void Player::recieve(int numToRecieve) {
    money += numToRecieve;
}

// add a property to the player's list of properties
void Player::addProperty(Ownable *property) {
    properties.push_back(property);
}

// removes a property from the player's list of properties
void Player::removeProperty(Ownable *property) {
    properties.erase(std::remove(properties.begin(), properties.end(), property), properties.end());
}

// not finished
string Player::getAssets() const {
    string assets = "";
    for (auto property : properties) {
        assets += property->getName() + ", ";
    }
    return assets;
}