#ifndef AF_H
#define AF_H

#include "Ownable.h"
using namespace std;

class AthleticFacility : public Ownable {
public:
    AthleticFacility(string name, int position, int purchasePrice);

    int calculateFacilityFee(int diceTotal, int facilityCount) const;

    void chargeRentOrTuition(Player &player, Game &game) const override;

    bool isAthleticFacility() const;
};

#endif