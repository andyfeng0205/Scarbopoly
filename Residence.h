#ifndef RESIDENCE_H
#define RESIDENCE_H

#include "Ownable.h"
#include <string>

class Residence : public Ownable {
public:
    Residence(const string &name, int position, int purchasePrice);

    int calculateResidenceRent(int residenceCount) const;

    void chargeRentOrTuition(Player &player, Game &game) const override;
};

#endif
