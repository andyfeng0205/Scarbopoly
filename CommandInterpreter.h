#ifndef COMMANDINTERPRETER_H
#define COMMANDINTERPRETER_H

#include <string>
using namespace std;

class Game;

class CommandInterpreter {
    Game *game;

    string command;
    string commandType;
    string give;
    string receive;
    string property;
    string player2;
    string buyOrSell;
    string filename;

    bool validCommand = false;

public:
    explicit CommandInterpreter(Game *game);

    bool readCommand();
    void parseCommand();
    void executeCommand();
};

#endif