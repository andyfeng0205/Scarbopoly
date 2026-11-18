#include "Game.h"
#include "Board.h"
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

class Player;
class Board;

Game::Game() : players{nullptr}, board{new Board()}, currentPlayer{-1}, gameOver{false} {};
