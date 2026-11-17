#include "CommandInterpreter.h"
#include "Game.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

CommandInterpreter::CommandInterpreter(Game *game)
    : game{game} {}

bool CommandInterpreter::readCommand() {
    if(getline(cin, command)) return true;
    return false;
}

void CommandInterpreter::parseCommand() {
    istringstream iss{command};

    // Clear previous command information
    commandType = "";
    give = "";
    receive = "";
    property = "";
    player2 = "";
    buyOrSell = "";
    filename = "";
    validCommand = false;

    // Read command type
    if(!(iss >> commandType)) return;

    string extra;
    if(commandType == "roll" ||
       commandType == "next" ||
       commandType == "bankrupt" ||
       commandType == "assets" ||
       commandType == "all") {

        if(!(iss >> extra)) validCommand = true;
    }
    else if(commandType == "trade") {
        if(iss >> player2 >> give >> receive) {
            if(!(iss >> extra)) validCommand = true;
        }
    }
    else if(commandType == "improve") {
        if(iss >> property >> buyOrSell) {
            if(buyOrSell == "buy" || buyOrSell == "sell") {
                if(!(iss >> extra)) validCommand = true;
            }
        }
    }
    else if(commandType == "mortgage" || commandType == "unmortgage") {
        if(iss >> property) {
            if(!(iss >> extra)) validCommand = true;
        }
    }
    else if(commandType == "save") {
        if(iss >> filename) {
            if(!(iss >> extra)) validCommand = true;
        }
    }
}

void CommandInterpreter::executeCommand() {
    
}