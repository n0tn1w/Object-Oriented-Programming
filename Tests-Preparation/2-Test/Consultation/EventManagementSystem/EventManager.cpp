#include "EventManager.h"

void EventManager::addEvent(const char* str) {
    events.add(str);
}

void EventManager::addObserver(const char* str) {
    observers.add(str);
}

void EventManager::run() {  
    while(true) {
        for(size_t i = 0; i < events.getSize(); i++) {
            const char* msg = events[i].check();

            if(msg) {
                
                for(size_t k = 0; k < observers.getSize(); k++) {
                    observers[i].notify(msg);
                }
            }
            delete[] msg;
        }
    }
}