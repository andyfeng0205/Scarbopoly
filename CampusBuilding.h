#ifndef CAMPUSBUILDING_H
#define CAMPUSBUILDING_H

#include "Ownable.h"
#include <string>
using namespace std;

class CampusBuilding : public Ownable{
    string monopolyBlock;   // the monopoly type the player belongs to
    int improvementLevel;   // Current improve level, from 0 to 5
    int tuition[6];         // The tuition of the current improvement level
    int improvementCost;    // cost to improve the current campus building
public:
    CampusBuilding(string name, int position, int purchasePrice, string monopolyBlock, int improvementCost, int tuition[6]); // ctor
    void landOn(Player &player, Game &game) override;
    void chargeRentOrTuition(Player &player, Game &game) const override; // charge player, other than the owner, the respective
    void improve();         // improve the campus building, and changes its tuition
    void sellImprovement(); // sell an improvement
    int getImprovementPrice() const; // return the improvement price
    int getImprovementLevel() const override; // return the improvement level
    string getMonopolyBlock() const; // return the monopoly block
};

#endif