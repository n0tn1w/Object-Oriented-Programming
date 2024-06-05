#pragma once
#include <iostream>
#include <cstdint>
#include "PF.h"

class Command {
public:
    virtual ~Command() = default;
    virtual void execute(PF* func) const = 0;
};

class RangeCommand : public Command {
public:
    void execute(PF* func) const override;
};

class FollowingNumberCommand : public Command {
public:
    void execute(PF* func) const override;
};


//Factory
class CommandFactory {
public:
    static Command* createCommand(int);
};

// In the same file to be easier for grading
// Split compilation should be utilized in real envrionment