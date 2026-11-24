#include "Game.h"
#include "Player.h"
#include "Board.h"
#include "Bank.h"
#include "Auction.h"
#include "Dice.h"
#include "Ownable.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Constructor
Game::Game()
    : players{},
      board{nullptr},
      currentPlayer{0},
      gameOver{false},
      auctionManager{nullptr},
      bank{new Bank{}},
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

    // TODO: Initialize the board.
    // TODO: Ask for the number of players.
    // TODO: Initialize players.
    // TODO: Attach and notify TextDisplay.
}

// End the game
void Game::endGame() {
    gameOver = true;

    cout << "Game Over!" << endl;

    for (Player *player : players) {
        if (!player->isBankrupt()) {
            cout << player->getName() << " wins!" << endl;
            break;
        }
    }
}

// Roll dice
void Game::rollDice() {
    if (gameOver || players.empty()) {
        return;
    }

    // TODO: Check whether the player can roll.
    // TODO: Handle Tims Line.

    dice->roll();

    int dice1 = dice->getDice1();
    int dice2 = dice->getDice2();
    int total = dice1 + dice2;

    cout << "Dice 1: " << dice1 << endl;
    cout << "Dice 2: " << dice2 << endl;
    cout << "Total: " << total << endl;

    if (dice1 == dice2) {
        cout << "You rolled doubles!" << endl;

        // TODO: Update consecutive doubles.
        // TODO: Handle three consecutive doubles.
    }

    movePlayer(total);
}

// Move the current player
void Game::movePlayer(int steps) {
    if (players.empty() || board == nullptr) {
        return;
    }

    Player *player = getCurrentPlayer();

    int oldPosition = player->getPosition();

    player->move(steps);

    int newPosition = player->getPosition();

    // Collect OSAP when passing or landing on square 0.
    if (steps > 0) {
        int timesPassed = (oldPosition + steps) / 40;

        if (timesPassed > 0) {
            bank->payPlayer(*player, 200 * timesPassed);
        }
    }

    cout << player->getName()
         << " moved to square "
         << newPosition << endl;

    // TODO: Retrieve the square from Board.
    // TODO: Execute landOn().
    // Collect OSAP must not be awarded again in landOn().

    notifyObservers();
}

// Next turn
void Game::nextTurn() {
    if (gameOver || players.empty()) {
        return;
    }

    // TODO: Check whether the current player can end their turn.
    // TODO: Check for outstanding payments.

    int activePlayers = 0;

    for (Player *player : players) {
        if (!player->isBankrupt()) {
            activePlayers++;
        }
    }

    if (activePlayers <= 1) {
        endGame();
        return;
    }

    getCurrentPlayer()->resetDoubles();

    // Skip bankrupt players.
    do {
        currentPlayer = (currentPlayer + 1) % players.size();
    } while (players[currentPlayer]->isBankrupt());

    cout << "Current player: "
         << getCurrentPlayer()->getName() << endl;

    notifyObservers();
}

// Trade
void Game::trade(string client, string give, string receive) {
    Player *other = findPlayer(client);
    Player *current = getCurrentPlayer();

    if (current == nullptr || other == nullptr) {
        cout << "Player not found." << endl;
        return;
    }

    if (current == other) {
        cout << "You cannot trade with yourself." << endl;
        return;
    }

    if (other->isBankrupt()) {
        cout << "You cannot trade with a bankrupt player." << endl;
        return;
    }

    // TODO: Determine whether give and receive are money or properties.
    // TODO: Validate ownership and improvements.
    // TODO: Ask the other player to accept or reject.
    // TODO: Execute the trade using Bank.
    // TODO: Notify observers.
}

// Improve building
void Game::improveBuilding(string campusBuilding,
                           string buyOrSell) {
    if (buyOrSell != "buy" && buyOrSell != "sell") {
        cout << "Invalid improvement command." << endl;
        return;
    }

    // TODO: Find the campus building.
    // TODO: Call the corresponding Bank method.
    // TODO: Notify observers.
}

// Mortgage
void Game::mortgage(string property) {
    // TODO: Find the property.
    // TODO: Call Bank::mortgage().
    // TODO: Notify observers.
}

// Unmortgage
void Game::unmortgage(string property) {
    // TODO: Find the property.
    // TODO: Call Bank::unmortgage().
    // TODO: Notify observers.
}

// Handle mandatory payments
void Game::handlePayment(Player &from, Player *to, int amount) {
    if (amount <= 0) {
        return;
    }

    bool success;

    if (to == nullptr) {
        success = bank->collectMoney(from, amount);
    } else {
        success = bank->transferMoney(from, *to, amount);
    }

    if (!success) {
        cout << "Insufficient funds!" << endl;

        // TODO: Record outstanding debt.
        // TODO: Prevent the player from ending their turn.
        // TODO: Allow the player to raise money or declare bankruptcy.

        return;
    }

    cout << from.getName() << " paid $" << amount << endl;
}

// Bankruptcy
void Game::handleBankruptcy() {
    // TODO: Check outstanding debt.
    // TODO: Transfer assets to the creditor.
    // TODO: Auction properties if necessary.
    // TODO: Update bankruptcy status.
    // TODO: Check whether the game has ended.
    // TODO: Notify observers.
}

// Current player's assets
void Game::assets() const {
    Player *player = getCurrentPlayer();

    if (player != nullptr) {
        assets(*player);
    }
}

// Specified player's assets
void Game::assets(const Player &player) const {
    cout << player.getName() << endl;
    cout << player.getAssets() << endl;
}

// All players' assets
void Game::all() const {
    for (const Player *player : players) {
        if (!player->isBankrupt()) {
            assets(*player);
        }
    }
}

// Save game
void Game::save(string filename) {
    // TODO: Open output file.
    // TODO: Save active players in turn order.
    // TODO: Save properties in board order.
}

// Load game
void Game::load(string filename) {
    // TODO: Open input file.
    // TODO: Initialize board and players.
    // TODO: Load property ownership and improvements.
    // TODO: Notify observers.
}

// Auction a property
void Game::auction(Ownable &property) {
    // TODO: Use auctionManager to auction the property.
}

// Get Dice
Dice *Game::getDice() const {
    return dice;
}

// Get Board
const Board *Game::getBoard() const {
    return board;
}

// Get all players
const vector<Player *> &Game::getPlayers() const {
    return players;
}

// Get current player
Player *Game::getCurrentPlayer() const {
    if (players.empty()) {
        return nullptr;
    }

    return players[currentPlayer];
}

// Check whether the game has ended
bool Game::isGameOver() const {
    return gameOver;
}

// Find a player by name
Player *Game::findPlayer(string name) const {
    for (Player *player : players) {
        if (player->getName() == name) {
            return player;
        }
    }

    return nullptr;
}