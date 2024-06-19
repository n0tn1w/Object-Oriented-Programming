#pragma once

#include <cstddef>

const size_t DATA_SIZE = 26;

class BoolInterpretation {

public:

    bool getCharAt(char) const;

    void setCharAt(char, bool);

    size_t turnOnCount() const;

    void modify(size_t);

private:

    char _grammer[DATA_SIZE] {false};

};