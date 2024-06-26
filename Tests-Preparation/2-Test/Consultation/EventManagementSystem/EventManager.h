#include "Vector.hpp"
#include "Event.h"
#include "Observer.h"
#include "Factory.h"

class EventManager{

public:

    void addEvent(const char*);
    void addObserver(const char*);

    void run();

private:

    Vector<Event, EventFactory> events;
    Vector<Observer, ObserverFactory> observers;

};