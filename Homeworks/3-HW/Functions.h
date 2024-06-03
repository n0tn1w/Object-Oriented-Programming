#include <fstream>
#include <cstring>

#include "PF.h"

namespace FunctionConsts {
    
    constexpr unsigned MAX_FUNCTION_CONTEXT_DATA = 32;

};

class BaseFunction {

public:

    virtual Pair<int, bool> operator()(int) const = 0; 

    virtual ~BaseFunction() = default;

};

class DefinedInNumbersF : public BaseFunction {
    
public:

    DefinedInNumbersF(Pair<int, int>*, size_t);

    Pair<int, bool> operator()(int) const override; 


private: 

    Pair<int, int> _data[FunctionConsts::MAX_FUNCTION_CONTEXT_DATA];
    size_t _size;

};

class NotDefinedInNumbersF : public BaseFunction{

public:

    NotDefinedInNumbersF(int*, size_t);

    Pair<int, bool> operator()(int) const override; 

private: 

    int _data[FunctionConsts::MAX_FUNCTION_CONTEXT_DATA];
    size_t _size;

};

class ReturnOneAndZeroF : public BaseFunction{

public:

    ReturnOneAndZeroF(int*, size_t);

    Pair<int, bool> operator()(int) const override; 

private: 

    int _data[FunctionConsts::MAX_FUNCTION_CONTEXT_DATA];
    size_t _size;

};