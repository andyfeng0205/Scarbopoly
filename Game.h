#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Dice.h"
#include "Bank.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player;
class Board;
class Bank;
class Dice;
class Auction;

class Game{
    // private instance variables
    vector<Player*> players;
    Board* board;
    int currentPlayer;
    bool gameOver;
    Auction *auction;
    Bank *bank; 
public:
    Game();
    Game(const Game &other);
    Game(Game &&other);
    Game &operator=(const Game &other);
    Game &operator=(Game &&other);
    ~Game();

    void startGame();
    void endGame();
    void rollDice();
    void nextTurn();
    void trade(string client, string give, string receieve);
    void improveBuilding(string campusBuilding, string buyOrSell);
    void mortgage(string property);
    void unmortgage(string property);
    void handleBankruptcy();
    void assets();
    void assets(const Player &player) const;
    void all() const;
    void save(string filename);
    void auction();

private:
    void movePlayer();
};

#endif
