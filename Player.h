#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Ownable;

class Player {
    std::string name;
    char piece;
    int money;
    int position;
    bool inTims;
    int currentTimsTurn;
    int numCups;
    bool bankrupt;
    int consecutiveDoubles;
    std::vector<Ownable *> properties;

public:
    // Constructors
    Player();

    Player(std::string name, char piece, int money,
           int position, bool inTims, int currentTimsTurn,
           int numCups, bool bankrupt, int consecutiveDoubles,
           std::vector<Ownable *> properties);

    // Movement
    void move(int step);
    void setPosition(int position);

    // Financial operations
    void pay(int numToPay);
    void recieve(int numToRecieve);

    // Property management
    void addProperty(Ownable *property);
    void removeProperty(Ownable *property);

    int getNumResidence() const;
    int getNumAC() const;

    const std::vector<Ownable *> &getProperties() const;

    // Tims Line management
    void setInTims(bool status);
    void setCurrentTimsTurn(int turns);

    // Roll Up the Rim Cup management
    void addCup();
    void removeCup();

    // Doubles management
    void incrementDoubles();
    void resetDoubles();

    // Bankruptcy
    void setBankrupt(bool status);

    // Getters
    std::string getName() const;
    char getPiece() const;
    int getMoney() const;
    int getPosition() const;
    bool isInTims() const;
    int getCurrentTimsTurn() const;
    int getNumCups() const;
    bool isBankrupt() const;
    int getConsecutiveDoubles() const;

    std::string getAssets() const;
};

#endif