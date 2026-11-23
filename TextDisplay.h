#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "Observer.h"

class Game;

class TextDisplay : public Observer {
    Game &game;

public:
    TextDisplay(Game &game);
    
    void notify() const override;
    void print() const;
};

#endif