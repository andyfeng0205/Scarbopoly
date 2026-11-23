#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Ownable;

class Player {
    std::string name;       // the name of the player
    char piece;             // the piece uses to represent the player on the board
    int money;              // aoumnt of 
    int position;           // cuurrent position of the player on the board
    bool inTims;            // whether the player is in the tims line
    int currentTimsTurn;    // current number of turns in tims line
    int numCups;             // number of Roll Up and Rims Cup
    bool bankrupt;          // whether the player is bankrupt
    int consecutiveDoubles; // number of times the player rolls a double in the current turn
    std::vector<Ownable *> properties;   // the ownables buildigns the player owns

public:
    Player();
    Player(std::string name, char piece, int money, int position, bool inTims, 
        int currentTimsTurn, int numCups, bool bankrupt, int consecutiveDoubles,
        std::vector<Ownable *> properties);

    void move(int step);
    void pay(int numToPay);
    void recieve(int numToRecieve);
    void addProperty(Ownable *property);
    void removeProperty(Ownable *property);
    std::string getAssets() const ;
};

#endif
