#ifndef CAMPUSBUILDING_H
#define CAMPUMBUILDING_H

#include "Ownable.h"
#include <string>
using namespace std;

class CampusBuilding : public Ownable{
    string monopolyBlock;   // the monopoly type the player belongs to
    int improvementLevel;   // Current improve level, from 0 to 5
    int tuition[6];         // The tuition of the current improvement level
    int improvementCost;    // cost to improve the current campus building
public:
    void chargeRentOrTuition(Player &player, Game &game) const; // charge player, other than the owner, the respective
    void improve();         // improve the campus building, and changes its tuition
    void sellImprovement(); // sell an improvement
    int getImprovementPrice();
    int getImprovementLevel(); 
};

#endif