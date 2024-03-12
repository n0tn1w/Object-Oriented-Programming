#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>

namespace Const
{
    const char* FIRST_FILE_NAME = "file1.txt";
    const char* SECOND_FILE_NAME = "file2.txt";
    const char* FINAL_FILE_NAME = "fileFinal.txt";
    const size_t MATRIX_SIZE = 3;
    const size_t BUFF_SIZE = 1024;
}

struct Matrix {
    int el[Const::MATRIX_SIZE][Const::MATRIX_SIZE];
};

Matrix FillMatrix(const char* buff) {

    std::stringstream ss(buff);
    //std::cout << ss.str();
    Matrix m;
    for(size_t i = 0; i < Const::MATRIX_SIZE; i++) {
        for(size_t k = 0; k < Const::MATRIX_SIZE; k++) {
            int s;
            ss >> s;            
            m.el[i][k] = s;
            ss.ignore();
        }
    }
    return m;
}

Matrix ReadMatrixFromFile(std::ifstream& ifs) {
    
    char buff[1024];
    size_t i = 0;
    while(!ifs.eof()){
        buff[i++] = ifs.get();
    }
    return FillMatrix(buff);
}

Matrix ReadMatrixFromFile(const char* filename) {
    std::ifstream ifs(filename);

    assert(ifs.is_open());
    Matrix m = ReadMatrixFromFile(ifs);
    ifs.close();

    return m;
}

Matrix AddMartix(const Matrix& m1, const Matrix& m2) {
    Matrix m;
    for(size_t i = 0; i < Const::MATRIX_SIZE; i++) {
        for(size_t k = 0; k < Const::MATRIX_SIZE; k++) {
            m.el[i][k] =  m1.el[i][k] + m2.el[i][k];
        }
    }
    return m;
}

void WriteMatrixIntoFile(const char* filename, const Matrix& mSum) {
    std::ofstream ofs(filename, std::ios::out | std::ios::trunc);
    assert(ofs.is_open());

    for(size_t i = 0; i < Const::MATRIX_SIZE; i++) {
        if(i != 0)
            ofs << '|';

        for(size_t k = 0; k < Const::MATRIX_SIZE; k++) {
            if(k != 0) 
                ofs << ',';
            ofs << mSum.el[i][k];
        }
    }

}

void Print(const Matrix& m) {
    for(size_t i = 0; i < Const::MATRIX_SIZE; i++) {
        for(size_t k = 0; k < Const::MATRIX_SIZE; k++) {
            std::cout << m.el[i][k] << " ";
        }
        std::cout << std::endl;
    }

}

int main() {
    Matrix m1 = ReadMatrixFromFile(Const::FIRST_FILE_NAME);
    Matrix m2 = ReadMatrixFromFile(Const::SECOND_FILE_NAME);
    Matrix mSum = AddMartix(m1, m2);
    Print(mSum);
    WriteMatrixIntoFile(Const::FINAL_FILE_NAME, mSum);

}
