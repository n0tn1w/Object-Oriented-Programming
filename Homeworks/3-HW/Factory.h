#include <fstream>
#include <stdint.h>

#include "Functions.h"
#include "PF.h"
#include "PFByCriteria.hpp"
#include "MinOfPF.h"
#include "MaxOfPF.h"

namespace FunctionFactoryConsts {
    constexpr unsigned BUFFER_SIZE = 1024;
};

class FunctionFactory {

public:

    static PF* createFunction(const char* fileName);

private:

    static PFByCriteria<DefinedInNumbersF>* createDefinedInNumbersF(std::ifstream& in, uint16_t N);

    static PFByCriteria<NotDefinedInNumbersF>* createNotDefinedInNumbersF(std::ifstream& in, uint16_t N);

    static PFByCriteria<ReturnOneAndZeroF>* createReturnOneAndZeroF(std::ifstream& in, uint16_t N);

    static MaxOfPF* createMaxOfPF(std::ifstream& in, uint16_t N);

    static MinOfPF* createMinOfPF(std::ifstream& in, uint16_t N);

    static PF* readPFFromFile(std::ifstream& in, size_t N);
    
};