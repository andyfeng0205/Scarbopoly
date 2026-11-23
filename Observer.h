#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    Observer();
    virtual void notify() const = 0;
    
};

#endif