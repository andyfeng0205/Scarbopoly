#include "TextDisplay.h"
#include "Game.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>

const int LINE[40] = {
    51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51,   // 0–10   bottom row
    46, 41, 36, 31, 26, 21, 16, 11, 6,            // 11–19  left column
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,              // 20–30  top row
    6, 11, 16, 21, 26, 31, 36, 41, 46             // 31–39  right column
};

const int COL[40] = {
    81, 73, 65, 57, 49, 41, 33, 25, 17, 9, 1,     // 0–10
    1, 1, 1, 1, 1, 1, 1, 1, 1,                    // 11–19
    1, 9, 17, 25, 33, 41, 49, 57, 65, 73, 81,     // 20–30
    81, 81, 81, 81, 81, 81, 81, 81, 81            // 31–39
};

using namespace std;

// TextDisplay constructor
TextDisplay::TextDisplay(Game &game) : game(game) {}

// when notified, class print
void TextDisplay::notify() const{
    print();
}

// prints the entire board
void TextDisplay::print() const {
    vector<string> board = {
        "_________________________________________________________________________________________",
        "|Raccoon|       |ARTS & |       |       |ASP    |       |       |TC     |       |GO TO  |",
        "|Raid   |-------|ADMIN  |-------|-------|       |-------|-------|       |-------|TIMS   |",
        "|       |IC     |       |HL     |IA     |       |EV     |SY     |       |ETP    |       |",
        "|       |       |       |       |       |       |       |       |       |       |       |",
        "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|",
        "|       |                                                                       |       |",
        "|-------|                                                                       |-------|",
        "|AC     |                                                                       |IH     |",
        "|       |                                                                       |       |",
        "|_______|                                                                       |_______|",
        "|       |                                                                       |       |",
        "|-------|                                                                       |-------|",
        "|BV     |                                                                       |KW     |",
        "|       |                                                                       |       |",
        "|_______|                                                                       |_______|",
        "|SL     |                                                                       |SL     |",
        "|       |                                                                       |       |",
        "|       |                                                                       |       |",
        "|       |                                                                       |       |",
        "|_______|                                                                       |_______|",
        "|       |                                                                       |       |",
        "|-------|                                                                       |-------|",
        "|HW     |                                                                       |AM     |",
        "|       |          ___________________________________________________          |       |",
        "|_______|         |                                                   |         |_______|",
        "|HC     |         |  ###  ###  ##  ###  ###   ##  ###   ##  #    #  # |         |KOA    |",
        "|       |         | #    #    #  # #  # #  # #  # #  # #  # #    #  # |         |       |",
        "|       |         |  ##  #    #### ###  ###  #  # ###  #  # #     ##  |         |       |",
        "|       |         |    # #    #  # # #  #  # #  # #    #  # #     ##  |         |       |",
        "|_______|         | ###   ### #  # #  # ###   ##  #     ##  ####  ##  |         |_______|",
        "|       |         |___________________________________________________|         |ARTS & |",
        "|-------|                                                                       |ADMIN  |",
        "|BD     |                                                                       |       |",
        "|       |                                                                       |       |",
        "|_______|                                                                       |_______|",
        "|       |                                                                       |       |",
        "|-------|                                                                       |-------|",
        "|UMG    |                                                                       |SW     |",
        "|       |                                                                       |       |",
        "|_______|                                                                       |_______|",
        "|AQ     |                                                                       |CO-OP  |",
        "|       |                                                                       |FEE    |",
        "|       |                                                                       |       |",
        "|       |                                                                       |       |",
        "|_______|                                                                       |_______|",
        "|       |                                                                       |       |",
        "|-------|                                                                       |-------|",
        "|CF     |                                                                       |MP     |",
        "|       |                                                                       |       |",
        "|_______|_______________________________________________________________________|_______|",
        "|Tims   |       |       |ARTS & |       |JF     |TUITION|       |SL     |       |COLLECT|",
        "|Line   |-------|-------|ADMIN  |-------|       |       |-------|       |-------|OSAP   |",
        "|       |ML     |DMG    |       |LLB    |       |       |HH     |       |CH     |       |",
        "|       |       |       |       |       |       |       |       |       |       |       |",
        "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|"
    };

       // for (int pos = 0; pos < 40; ++pos) {
    //     int level = game.getBoard()->getSquare(pos)->getImprovementLevel();
    //     for (int i = 0; i < level; ++i) {
    //         board[LINE[pos]][COL[pos] + i] = 'I';
    //     }
    // }
        int onSquare[40] = {};
    for (const Player *player : game.getPlayers()) {
        if (player->isBankrupt()) {
            continue;
        }
        int pos = player->getPosition();
        board[LINE[pos] + 3][COL[pos] + onSquare[pos]] = player->getPiece();
        ++onSquare[pos];
    }

    for (const string &line : board) {
        cout << line << endl;
    }
}