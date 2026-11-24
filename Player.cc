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

// returns a string of the player's assets, with the form: Properties: ... , Money: ...
std::string Player::getAssets() const {
    std::string props = "Properties: ";
    for (auto property : properties) {
        props += property->getName() + ", ";
    }
    return props + "Money: " + std::to_string(money);
}

int Player::getNumResidence() const {
    int count = 0;

    for (auto property : properties) {
        if (property->isResidence()) {
            count++;
        }
    }
    return count;
}

int Player::getNumAC() const {
    int count = 0;

    for (auto property : properties) {
        if (property->isAthleticFacility()) {
            count++;
        }
    }
    return count;
}

// Movement
void Player::setPosition(int position) {
    this->position = position;
}

// Property management
int Player::getNumResidence() const {
    int count = 0;

    for (auto property : properties) {
        if (property->isResidence()) {
            count++;
        }
    }

    return count;
}

int Player::getNumAC() const {
    int count = 0;

    for (auto property : properties) {
        if (property->isAthleticFacility()) {
            count++;
        }
    }

    return count;
}

const std::vector<Ownable *> &Player::getProperties() const {
    return properties;
}

// Tims Line management
void Player::setInTims(bool status) {
    inTims = status;
}

void Player::setCurrentTimsTurn(int turns) {
    currentTimsTurn = turns;
}

// Cup management
void Player::addCup() {
    numCups++;
}

void Player::removeCup() {
    if (numCups > 0) {
        numCups--;
    }
}

// Doubles management
void Player::incrementDoubles() {
    consecutiveDoubles++;
}

void Player::resetDoubles() {
    consecutiveDoubles = 0;
}

// Bankruptcy
void Player::setBankrupt(bool status) {
    bankrupt = status;
}

// Getters
std::string Player::getName() const {
    return name;
}

char Player::getPiece() const {
    return piece;
}

int Player::getMoney() const {
    return money;
}

int Player::getPosition() const {
    return position;
}

bool Player::isInTims() const {
    return inTims;
}

int Player::getCurrentTimsTurn() const {
    return currentTimsTurn;
}

int Player::getNumCups() const {
    return numCups;
}

bool Player::isBankrupt() const {
    return bankrupt;
}

int Player::getConsecutiveDoubles() const {
    return consecutiveDoubles;
}