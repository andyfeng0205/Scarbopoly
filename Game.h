#ifndef GAME_H
#define GAME_H

#include "Subject.h"
#include <string>
#include <vector>

using namespace std;

class Player;
class Board;
class Bank;
class Auction;
class Dice;
class Ownable;

#define MAX_PLAYERS 8

class Game : public Subject {
    vector<Player *> players;
    Board *board;
    int currentPlayer;
    bool gameOver;
    Auction *auctionManager;
    Bank *bank;
    Dice *dice;

public:
    Game();
    ~Game();

    // Game flow
    void startGame();
    void rollDice();
    void nextTurn();

    // Commands
    void trade(string client, string give, string receive);
    void improveBuilding(string campusBuilding, string buyOrSell);
    void mortgage(string property);
    void unmortgage(string property);
    void handleBankruptcy();

    // Display commands
    void assets() const;
    void all() const;

    // Save and load
    void save(string filename);
    void load(string filename);

    // Gameplay coordination
    void handlePayment(Player &from, Player *to, int amount);
    void auction(Ownable &property);

    // Getters
    Dice *getDice() const;
    const Board *getBoard() const;
    const vector<Player *> &getPlayers() const;
    Bank *getBank();
    bool isGameOver() const;

private:
    void endGame();
    void movePlayer(int steps);
    void assets(const Player &player) const;
    Player *getCurrentPlayer() const;
    Player *findPlayer(string name) const;
};

#endif