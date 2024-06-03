#include "Factory.h"

namespace ErrorMessagesFunctionFactory {
	constexpr char CANNOT_OPEN_FILE[] = "Can't open file!";
	constexpr char FUNCTION_INVALID_MODE[] = "Invalid mode!";
}

PF* FunctionFactory::createFunction(const char* fileName) {
    std::ifstream in(fileName, std::ios::binary);

    if (!in.is_open()) {
        throw std::runtime_error(ErrorMessagesFunctionFactory::CANNOT_OPEN_FILE);
    }

    uint16_t N;
    in.read((char*)&N, sizeof(uint16_t));

    uint16_t mode;
    in.read((char*)&mode, sizeof(uint16_t));  

    switch (mode) {
        { case 0: return createDefinedInNumbersF(in, N); break; }
        { case 1: return createNotDefinedInNumbersF(in, N); break; }
        { case 2: return createReturnOneAndZeroF(in, N); break; }
        { case 3: return createMaxOfPF(in, N); break; }
        { case 4: return createMinOfPF(in, N); break; }
        { default: throw std::runtime_error(ErrorMessagesFunctionFactory::FUNCTION_INVALID_MODE); break; }
    }
}

PFByCriteria<DefinedInNumbersF>* FunctionFactory::createDefinedInNumbersF(std::ifstream& in, uint16_t N) {
    int numbers[FunctionConsts::MAX_FUNCTION_CONTEXT_DATA * 2];
    in.read((char*)numbers, N * 2 * sizeof(int));
    Pair<int, int> defined[FunctionConsts::MAX_FUNCTION_CONTEXT_DATA];

    for(size_t i = 0; i < FunctionConsts::MAX_FUNCTION_CONTEXT_DATA; i++) {
        defined[i].setFirst(numbers[i]);
        defined[i].setSecond(numbers[i + N]);
    }

    return new PFByCriteria<DefinedInNumbersF>(DefinedInNumbersF(defined, N));
}

PFByCriteria<NotDefinedInNumbersF>* FunctionFactory::createNotDefinedInNumbersF(std::ifstream& in, uint16_t N) {
    int numbers[FunctionConsts::MAX_FUNCTION_CONTEXT_DATA];
    in.read((char*)numbers, N * sizeof(int));

    return new PFByCriteria<NotDefinedInNumbersF>(NotDefinedInNumbersF(numbers, N));
}

PFByCriteria<ReturnOneAndZeroF>* FunctionFactory::createReturnOneAndZeroF(std::ifstream& in, uint16_t N) {
    int numbers[FunctionConsts::MAX_FUNCTION_CONTEXT_DATA];
    in.read((char*)numbers, N * sizeof(int));

    return new PFByCriteria<ReturnOneAndZeroF>(ReturnOneAndZeroF(numbers, N));
}

MaxOfPF* FunctionFactory::createMaxOfPF(std::ifstream& in, uint16_t N) {
    PF** functions = new PF*[N];

    for(int i = 0; i < N; i++) {
        functions[i] = readPFFromFile(in, N);
    }

    return new MaxOfPF(functions, N);
}

MinOfPF* FunctionFactory::createMinOfPF(std::ifstream& in, uint16_t N) {
    PF** functions = new PF*[N];

    for(int i = 0; i < N; i++) {
        functions[i] = readPFFromFile(in, N);
    }

    return new MinOfPF(functions, N);
}

PF* FunctionFactory::readPFFromFile(std::ifstream& in, size_t N) {
    char buffer[FunctionFactoryConsts::BUFFER_SIZE];
    in.getline(buffer, FunctionFactoryConsts::BUFFER_SIZE, '\0');
    return createFunction(buffer);
}