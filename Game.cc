#include "Game.h"
#include "Player.h"
#include "Board.h"
#include "Bank.h"
#include "Auction.h"

#include <iostream>
#include <string>
using namespace std;

// Constructor
Game::Game()
    : players{},
      board{nullptr},
      currentPlayer{0},
      gameOver{false},
      auctionManager{nullptr},
      bank{nullptr},
      dice{new Dice{}} {}

// Destructor
Game::~Game() {
    for (Player *player : players) {
        delete player;
    }

    delete board;
    delete auctionManager;
    delete bank;
    delete dice;
}

// Start the game
void Game::startGame() {
    gameOver = false;
    currentPlayer = 0;

    cout << "Welcome to Scarbopoly!" << endl;

    // TODO: Initialize the board and players.
}

// End the game
void Game::endGame() {
    gameOver = true;
    cout << "Game Over!" << endl;
}

// Roll dice
void Game::rollDice() {
    if (gameOver || players.empty()) {
        return;
    }

    dice->roll();

    int dice1 = dice->getDice1();
    int dice2 = dice->getDice2();
    int total = dice1 + dice2;

    cout << "Dice 1: " << dice1 << endl;
    cout << "Dice 2: " << dice2 << endl;
    cout << "Total: " << total << endl;

    if (dice1 == dice2) {
        cout << "You rolled doubles!" << endl;
    }

    movePlayer(total);

    // TODO: Handle doubles, Tims, and landing actions.
}

// Move player
void Game::movePlayer(int steps) {
    if (players.empty() || board == nullptr) {
        return;
    }

    Player *player = players[currentPlayer];

    // TODO: Use Player's movement methods.
    // TODO: Handle passing OSAP and landing actions.
}

// Next turn
void Game::nextTurn() {
    if (gameOver || players.empty()) {
        return;
    }

    currentPlayer =
        (currentPlayer + 1) % players.size();
}

// Trade
void Game::trade(string client, string give, string receive) {
    // TODO: Validate and execute trade.
}

// Improve building
void Game::improveBuilding(string campusBuilding,
                           string buyOrSell) {
    // TODO: Buy or sell improvements.
}

// Mortgage
void Game::mortgage(string property) {
    // TODO: Mortgage property.
}

// Unmortgage
void Game::unmortgage(string property) {
    // TODO: Unmortgage property.
}

// Bankruptcy
void Game::handleBankruptcy() {
    // TODO: Handle bankruptcy.
}

// Current player's assets
void Game::assets() {
    if (players.empty()) {
        return;
    }

    assets(*players[currentPlayer]);
}

// Specified player's assets
void Game::assets(const Player &player) const {
    // TODO: Display player's assets.
}

// All players' assets
void Game::all() const {
    for (const Player *player : players) {
        assets(*player);
    }
}

// Save game
void Game::save(string filename) {
    // TODO: Save game state to file.
}

// Auction
void Game::auction() {
    // TODO: Start auction using auctionManager.
}
