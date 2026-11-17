#include <iostream>
#include <string>
#include "Game.h"
using namespace std;

class Game;

class CommandInterpreter {
    // private instance variables
    Game *game;
    string input;
public:
    CommandInterpreter(Game *game); // normal constructor
    CommandInterpreter(const CommandInterpreter &other); // copy constructor
    CommandInterpreter(CommandInterpreter &&other); // move constructor
    CommandInterpreter &operator=(const CommandInterpreter &other); // copy assignment
    CommandInterpreter &operator=(CommandInterpreter &&other); // move assignment

    string readCommand();
    void parseCommand();
    void executeCommand();
};