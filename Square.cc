#include "Square.h"
#include <string>
using namespace std;

Square::Square(string name, int position) : name{name}, position{position} {}

Square::~Square() {}

string Square::getName() const {
    return name;
}

int Square::getImprovementLevel() const {
    return 0;
}

int Square::getPosition() const {
    return position;
}