#include "SelfCountingClass.h"

unsigned SelfCounting::total = 0;
unsigned SelfCounting::live = 0;

SelfCounting::SelfCounting() {
    total++;
    live++;
}

SelfCounting::SelfCounting(const SelfCounting&) {
    total++;
    live++;
}

SelfCounting::~SelfCounting() {
    live--;
}

unsigned SelfCounting::getLive() {
    return live;
}

unsigned SelfCounting::getTotal() {
    return total;
}