#pragma once

class SelfCounting {

public:
    SelfCounting();
    SelfCounting(const SelfCounting&);
    ~SelfCounting();

    static unsigned getLive();
    static unsigned getTotal();

private:

    static unsigned live;
    static unsigned total;

};