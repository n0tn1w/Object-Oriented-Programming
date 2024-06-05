#include "Event.h"

class TimeEvent : public Event{

public:

    Event* clone() const override;
    const char* check() const override;

private:

    unsigned lastTime;

};