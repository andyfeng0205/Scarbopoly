#include "Ownable.h"
using namespace std;

Ownable::Ownable(string name, int position, int purchasePrice) 
    : Square{name, position}, purchasePrice{purchasePrice} {}

void Ownable::mortgage() {
    mortgaged = true;
}

void Ownable::unmortgage() {
    mortgaged = false;
}

void Ownable::setOwner(Player *player) {
    owner = player;
}

void Ownable::setMortgaged(bool status){
    mortgaged = status;
}

Player *Ownable::getOwner() const {
    return owner;
}

int Ownable::getPurchasePrice() const {
    return purchasePrice;
}

bool Ownable::isMortgaged() const {
    return mortgaged;
}