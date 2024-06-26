#include "Event.h"
#include "FileEvent.h"
#include "TimeEvent.h"

#include "Observer.h"
#include "ConsoleObserver.h"
#include "FileObserver.h"

class EventFactory {
public:
    static Event* create(const char*);
};

class ObserverFactory {
public:
    static Observer* create(const char*);
};