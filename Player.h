#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Ownable;

class Player {
    char piece;             // the piece uses to represent the player on the board
    int money;              // aoumnt of 
    int position;           // cuurrent position of the player on the board
    bool inTims;            // whether the player is in the tims line
    int currentTimsTurn;    // current number of turns in tims line
    int numCup;             // number of Roll Up and Rims Cup
    bool bankrupt;          // whether the player is bankrupt
    int consecutiveDoubles; // number of times the player rolls a double in the current turn
    vector<Ownable *> properties;   // the ownables buildigns the player owns

public:
    void move(int step);
    void pay();
    void recieve();
    void addProperty(Ownable *property);
    void removeProperty();
    string getAssest();
};

#endif
