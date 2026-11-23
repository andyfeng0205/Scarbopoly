#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <vector>

class Subject {
    std::vector<Observer*> observers;

public:
    virtual ~Subject() = default;

    void attach(Observer *observer);
    void detach(Observer *observer);
    void notifyObservers() const;
};

#endif