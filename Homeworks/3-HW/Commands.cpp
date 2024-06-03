#include "Commands.h"

void RangeCommand::execute(PF* func) const {
    int a, b;
    std::cout << "Enter a: " << std::endl;
    std::cin >> a;
    std::cout << "Enter b: " << std::endl;
    std::cin >> b;

    if(a > b) {
        std::cout << "a should be >= in relation to b" << std::endl;
        return;
    }

    for(int i = a; i <= b; i++) {
        Pair<int, bool> res = func->operator()(i);
        std::cout << i << ": " <<"defined: " << res.second();
        if(res.second()) {
            std::cout << " value: " << res.first();
        }
        std::cout << std::endl;
    }
}

void FollowingNumberCommand::execute(PF* func) const {
    int next = 0;
    std::cout << "Enter 1 for next number: ";
    std::cin >> next;
    bool noDefinedNumber = true;

    for(long i = INT32_MIN; i < INT32_MAX; i++) {
        Pair<int, bool> res = func->operator()(i);

        if(res.second()) {
            noDefinedNumber = false;
            std::cout << i << ": " << res.second();
            std::cout << " value: " << res.first();
            std::cout << std::endl;

            std::cout << "Enter 1 for next number: ";
            std::cin >> next;
        }
    }

    if(noDefinedNumber) {
        std::cout << "No defined numbers!" << std::endl;
    }
}

Command* CommandFactory::createCommand(int regime) {
    if (regime == 1) {
        return new RangeCommand();
    } else if (regime == 2) {
        return new FollowingNumberCommand();
    } else {
        nullptr;
    }
}
