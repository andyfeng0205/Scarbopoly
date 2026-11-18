#ifndef COMMANDINTERPRETER_H
#define COMMANDINTERPRETER_H

#include <string>
using namespace std;

class Game;

class CommandInterpreter {
    Game *game;

    string command;         // the string (with white space) the user entered or the one line in the file we want to load
    string commandType;     // the type of the command, for example, trade, mortgage, improve etc.
    string give;            // the name of the property the current player wants to give in a trade
    string receive;         // the name of the property the current player wants in return in a trade
    string property;        // name of the property the player wants to mortgage or unmortgage
    string player2;         // name of the other player the current player is trading with
    string buyOrSell;       // buy or sell the 
    string filename;        // the name of the file the player wants to save the current game in

    bool validCommand = false;

public:
    explicit CommandInterpreter(Game *game);
    ~CommandInterpreter();

    bool readCommand(); // read the command from the terminal, o
    void parseCommand(); // determine the type of the command the user is trying to do
    void executeCommand() const ; // tell the game to execute the command by doing game->command()
};

#endif