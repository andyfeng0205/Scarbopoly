#include "CommandInterpreter.h"
#include <iostream>
#include <string>
using namespace std;

CommandInterpreter::CommandInterpreter(Game *game) : game{game} {}

// We are creating a shallow copy here because there is only one game
CommandInterpreter::CommandInterpreter(const CommandInterpreter &other) : game{other.game}, input{other.input} {}

CommandInterpreter::CommandInterpreter(CommandInterpreter &&other) : game{other.game}, input{other.input} {
    other.game = nullptr;
}

// similar reason for the copy constructor, we are creating a shallow copy because ther is only one Game
CommandInterpreter &CommandInterpreter::operator=(const CommandInterpreter &other) {
    game = other.game;
    input = other.input;

    return *this;
}

CommandInterpreter &CommandInterpreter::operator=(CommandInterpreter &&other) {
    game = other.game;
    input = other.input;
    other.game = nullptr;

    return *this;
}

string CommandInterpreter::readCommand() {
    
}