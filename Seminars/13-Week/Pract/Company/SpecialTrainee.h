#pragma once
#include "Trainee.h"
#include "Worker.h"

class SpecialTrainee : public Trainee, Worker {

public:

    SpecialTrainee(unsigned, unsigned, const char*, unsigned, unsigned);

    void print() const override;

    Employee* clone() const override;
};