#ifndef AUCTION_H
#define AUCTION_H

#include "Ownable.h"

class Auction{
public:
    Auction() = default;

    void auction(Ownable *property);
};

#endif