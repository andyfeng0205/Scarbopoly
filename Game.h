#ifndef GAME_H
#define GAME_H

#include "Dice.h"
#include "Subject.h"
#include <string>
#include <vector>

using namespace std;

class Player;
class Board;
class Bank;
class Auction;

#define MAX_PLAYERS 8

class Game : public Subject {
    vector<Player *> players;
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

    Game(const Game &other) = delete;
    Game(Game &&other) = delete;
    Game &operator=(const Game &other) = delete;
    Game &operator=(Game &&other) = delete;

    // Game flow
    void startGame();
    void endGame();
    void rollDice();
    void nextTurn();

    // Property operations
    void trade(string client, string give, string receive);
    void improveBuilding(string campusBuilding, string buyOrSell);
    void mortgage(string property);
    void unmortgage(string property);
    void auction();

    // Financial obligations
    void handleBankruptcy();
    void handlePayment(Player &from, Player *to, int amount);

    // Display information
    void assets();
    void assets(const Player &player) const;
    void all() const;

    // Save and load
    void save(string filename);
    void load(string filename);

    // Getters
    Dice *getDice() const;
    Bank *getBank() const;
    Board *getBoard() const;
    const vector<Player *> &getPlayers() const;
    Player *getCurrentPlayer() const;
    bool isGameOver() const;

private:
    void movePlayer(int steps);
    Player *findPlayer(string name) const;
};

#endif