#pragma once
#include "Reader.h"
#include "ReaderArr.h"
#include "ReaderBinary.h"

#include "Writer.h"
#include "WriterArr.h"
#include "WriterBinary.h"


class Factory {

public:

    static Writer* createWriter(const MyString& fileName) {
        // Something get last one
        
        if(false) {
            return new WriterArr(fileName);
        } else {
            return new WriterBinary(fileName);
        }
    }
    
    static Reader* createReader(const MyString& fileName) {
        // Something get last one
        
        if(false) {
            return new ReaderArr(fileName);
        } else {
            return new ReaderBinary(fileName);
        }
    }

};