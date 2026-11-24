#ifndef DICE_H
#define DICE_H

using namespace std;

class Dice { 
    int dice1, dice2; // represents the number rolled
public:
    Dice(); // default constructor, set each dice to 0
    Dice(int dice1, int dice2); // constructor for testing mode

    void roll();
    int getDice1() const ;
    int getDice2() const ;
    int getSum() const;
};

#endif
