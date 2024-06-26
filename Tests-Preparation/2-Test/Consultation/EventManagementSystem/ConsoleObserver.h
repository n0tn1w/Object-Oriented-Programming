#include "Observer.h"

class ConsoleObserver : public Observer{

public:

    Observer* clone() const override;
    void notify(const char*) const override;

};