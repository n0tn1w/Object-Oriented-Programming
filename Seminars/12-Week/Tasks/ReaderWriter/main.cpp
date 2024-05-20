#include <iostream>
#include "MyString.h"
#include "Reader.h"
#include "Writer.h"
#include "Factory.h"
using std::cout;
using std::endl;

int main() {
    MyString read = "in.dat";
    MyString write = "out.arr";

    size_t cnt = 0;
    Reader* rd = Factory::createReader(read);
    int* data = rd->read(cnt);

    Writer* wr = Factory::createWriter(write);
    wr->write(data, cnt);
}
