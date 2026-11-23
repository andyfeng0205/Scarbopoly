#ifndef GAME_H
#define GAME_H

#include "Dice.h"
#include <string>
#include <vector>
using namespace std;

class Player;
class Board;
class Bank;
class Auction;

#define MAX_PLAYERS 8

class Game {
    vector<Player*> players;
    Board *board;
    int currentPlayer;
    int numPlayers;
    bool gameOver;
    Auction *auctionManager;
    Bank *bank;
    Dice *dice;

public:
    Game();
    ~Game();

    void startGame();
    void endGame();
    void rollDice();
    void nextTurn();

    void trade(std::string client, std::string give,
               std::string receive);

    void improveBuilding(std::string campusBuilding,
                         std::string buyOrSell);

    void mortgage(std::string property);
    void unmortgage(std::string property);

    void handleBankruptcy();

    void assets();
    void assets(const Player &player) const;
    void all() const;

    void save(std::string filename);
    void auction();

private:
    void movePlayer(int steps);
    Player *findPlayer() const;
};

#endif