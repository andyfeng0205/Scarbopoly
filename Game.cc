#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player;
class Board;

class Game{
    // private instance variables
    vector<Player*> players; // 
    Board* board;
    int numCurrentPlayers; // 
public:
    Game();
    Game(const Game &other);
    Game(Game &&other);
    Game &operator=(const Game &other);
    Game &operator=(Game &&other);
    ~Game();
    
    void startGame();
};
