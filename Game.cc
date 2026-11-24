#include "Game.h"
#include "Player.h"
#include "Board.h"
#include "Bank.h"
#include "Auction.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Constructor
Game::Game()
    : players{},
      board{nullptr},
      currentPlayer{0},
      numPlayers{0},
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
    // TODO: Initialize each player.
    // TODO: Attach and notify TextDisplay.
}

// End the game
void Game::endGame() {
    gameOver = true;

    cout << "Game Over!" << endl;

    // TODO: Display the winner.
}

// Roll dice
void Game::rollDice() {
    if (gameOver || players.empty()) {
        return;
    }

    // TODO: Check whether the player is allowed to roll.
    // TODO: Handle players in Tims Line.

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
        // TODO: Send player to Tims after three doubles.
        // Return without moving if this is the third double.
    }

    movePlayer(total);
}

// Move the current player
void Game::movePlayer(int steps) {
    if (players.empty() || board == nullptr) {
        return;
    }

    Player *player = players[currentPlayer];

    int oldPosition = player->getPosition();

    player->move(steps);

    int newPosition = player->getPosition();

    // Collect OSAP when moving forward across square 0.
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
    // TODO: Execute the square's landOn() method.

    notifyObservers();
}

// Next turn
void Game::nextTurn() {
    if (gameOver || players.empty()) {
        return;
    }

    // TODO: Check whether the current player can end their turn.
    // TODO: Check whether there is an outstanding payment.

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

    // Skip bankrupt players.
    do {
        currentPlayer = (currentPlayer + 1) % players.size();
    } while (players[currentPlayer]->isBankrupt());

    cout << "Current player: "
         << players[currentPlayer]->getName() << endl;

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

    // TODO: Determine whether give and receive are
    //       money or properties.
    // TODO: Validate ownership and improvements.
    // TODO: Ask the other player to accept or reject.
    // TODO: Execute the trade using Bank.
    // TODO: Notify observers after a successful trade.
}

// Improve building
void Game::improveBuilding(string campusBuilding,
                           string buyOrSell) {
    if (buyOrSell != "buy" && buyOrSell != "sell") {
        cout << "Invalid improvement command." << endl;
        return;
    }

    // TODO: Find the campus building.
    // TODO: Verify ownership and monopoly.
    // TODO: Call Bank::purchaseImprovement() or
    //       Bank::sellImprovement().
    // TODO: Notify observers after a successful transaction.
}

// Mortgage
void Game::mortgage(string property) {
    // TODO: Find the property.
    // TODO: Verify ownership.
    // TODO: Call Bank::mortgage().
}

// Unmortgage
void Game::unmortgage(string property) {
    // TODO: Find the property.
    // TODO: Verify ownership.
    // TODO: Call Bank::unmortgage().
}

// Handle mandatory payments
void Game::handlePayment(Player &from, Player *to, int amount) {
    if (amount <= 0) {
        return;
    }

    bool success;

    if (to == nullptr) {
        // Payment to the Bank.
        success = bank->collectMoney(from, amount);
    } else {
        // Payment to another player.
        success = bank->transferMoney(from, *to, amount);
    }

    if (!success) {
        cout << "Insufficient funds!" << endl;

        // TODO: Record the outstanding debt.
        // TODO: Record the creditor.
        // TODO: Prevent rolling or ending the turn.
        // TODO: Allow the player to raise money or
        //       declare bankruptcy.

        return;
    }

    cout << from.getName()
         << " paid $" << amount;

    if (to == nullptr) {
        cout << " to the Bank." << endl;
    } else {
        cout << " to " << to->getName() << "." << endl;
    }
}

// Bankruptcy
void Game::handleBankruptcy() {
    // TODO: Check whether the player has outstanding debt.
    // TODO: Transfer assets to the creditor.
    // TODO: Return properties to the Bank if necessary.
    // TODO: Auction returned properties.
    // TODO: Update the player's bankruptcy status.
    // TODO: Check whether the game has ended.
    // TODO: Notify observers.
}

// Current player's assets
void Game::assets() {
    Player *player = getCurrentPlayer();

    if (player == nullptr) {
        return;
    }

    assets(*player);
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
    // TODO: Open the output file.
    // TODO: Save the number of active players.
    // TODO: Save players, starting with the current player.
    // TODO: Save properties in board order.
}

// Load game
void Game::load(string filename) {
    // TODO: Open the input file.
    // TODO: Initialize the board.
    // TODO: Load player information.
    // TODO: Load property ownership and improvements.
    // TODO: Notify observers.
}

// Auction
void Game::auction() {
    // TODO: Start auction using auctionManager.
}

// Get Dice
Dice *Game::getDice() const {
    return dice;
}

// Get Bank
Bank *Game::getBank() const {
    return bank;
}

// Get Board
Board *Game::getBoard() const {
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