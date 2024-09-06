#include "ModifiableIntegersFunction.h"

void ModifiableIntegersFunction::adoptBannedList(const ModifiableIntegersFunction& other)
{
    size_t size = other.getBlSize();
    int16_t banned_val;
    for (size_t i = 0; i < size; i++) {
        banned_val = other.bl.getValue(i);
        if (!bl.isBanned(banned_val)) {
            addToBL(banned_val);
        }
    }
}

int16_t ModifiableIntegersFunction::getKResult(int16_t k) const
{
    int16_t value = ml.getXvalueByIndex(0);
    for (size_t i = 1; i < k; i++) {
        value = calculate(value);
    }
    return value;
}

ModifiableIntegersFunction::ModifiableIntegersFunction(int16_t (*func)(int16_t))
{
    for (int i = INT16_MIN; i <= INT16_MAX; i++) {
        int16_t result = func(i);
        addToML(i, result);
    }
}

void ModifiableIntegersFunction::addToML(int16_t xval, int16_t yval)
{
    ml.add(xval, yval);
}

void ModifiableIntegersFunction::changeResult(int16_t xval, int16_t result)
{
    ml.change(xval, result);
}

void ModifiableIntegersFunction::addToBL(int16_t xval)
{
    bl.add(xval);
}

int16_t ModifiableIntegersFunction::calculate(int16_t xval) const
{
    if (bl.isBanned(xval)) {
         return NULL;
    }
    return ml.getResult(xval);
}

size_t ModifiableIntegersFunction::getMlSize() const
{
    return ml.getSize();
}

size_t ModifiableIntegersFunction::getBlSize() const
{
    return bl.getSize();
}

int16_t ModifiableIntegersFunction::getMlXvalueByIndex(size_t index) const
{
    return ml.getXvalueByIndex(index);
}

int16_t ModifiableIntegersFunction::getMlRsultByIndex(size_t index) const
{
    return ml.getRsultByIndex(index);
}

const ModifiedList& ModifiableIntegersFunction::getML() const
{
    return ml;
}

void ModifiableIntegersFunction::setML(const ModifiedList& other)
{
    ml = other;
}


bool ModifiableIntegersFunction::isInjective() const
{
    size_t size = getMlSize();
    int16_t valInside = 0;
    int16_t valOutside = 0;
    for (size_t i = 0; i < size; i++) {
        valOutside = ml.getIndexOfValue(i);
        for (size_t j = 0; j < size; j++) {
            valInside = bl.getValue(j);
            if (bl.isBanned(valOutside)) {
                continue;
            }
            if (!bl.isBanned(valInside)) {
                if (valOutside == valInside && i != j) {
                    return false;
                }
            }
            
        }
    }
    return true;
}

bool ModifiableIntegersFunction::isSurjective() const
{
    return bl.isEmpty();
}

bool ModifiableIntegersFunction::isBijective() const
{
    return isSurjective() && isInjective();
}

bool ModifiableIntegersFunction::isBanned(int16_t value) const
{
    return bl.isBanned(value);
}

void ModifiableIntegersFunction::serialize(const char* filepath) const
{
    std::ofstream ofs(filepath, std::ios::binary);
    ml.serealize(ofs);
    bl.serealize(ofs);
    ofs.close();
}

void ModifiableIntegersFunction::deserialize(const char* filepath)
{
    std::ifstream ifs(filepath, std::ios::binary);
    ml.deserealize(ifs);
    bl.deserealize(ifs);
    ifs.close();
}

void ModifiableIntegersFunction::drawFunction(int size) const
{
    size_t matrixSize = size *2 + 1;
    bool** matrix = new bool*[matrixSize]; 

    for (int i = 0; i < matrixSize; ++i) {
        matrix[i] = new bool[matrixSize] {0};
    }
    int16_t result;
    for (int i = -size; i <= size; i++) {
        if (bl.isBanned(i)) {
            continue;
        }
        result = ml.getResult(i);
        if (size < result || result < -size) {
            continue;
        }
        size_t Xindex = convertToindex(i, size);
        size_t Yindex = convertToindex(result, size);
        matrix[Yindex][Xindex] = true;
    }
    printMatrix(matrix, matrixSize);
    for (int i = 0; i < matrixSize; ++i) {
        delete[] matrix[i];
    }
}

ModifiableIntegersFunction ModifiableIntegersFunction::operator^(int16_t k) const
{
    ModifiableIntegersFunction result;
    result.adoptBannedList(*this);
    size_t size = getMlSize();
    int16_t value, xvalue;
    for (size_t i = 0; i < size; i++) {
        xvalue = ml.getXvalueByIndex(i);
        value = getKResult(k);

    }
    return result;
}

ModifiableIntegersFunction ModifiableIntegersFunction::operator!() const
{
    ModifiableIntegersFunction result;
    result.adoptBannedList(*this);
    size_t size = getMlSize();
    int16_t xval, yval;
    for (size_t i = 0; i < size; i++) {
        xval = ml.getXvalueByIndex(i);
        yval = ml.getRsultByIndex(i);
        if (bl.isBanned(xval)) {
            continue;
        }
        result.addToML(yval, xval);
    }
    return result;
}

ModifiableIntegersFunction operator+(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
    ModifiableIntegersFunction result;
    result.setML(lhs.getML() + rhs.getML());
    result.adoptBannedList(lhs);
    result.adoptBannedList(rhs);
    return result;
}

ModifiableIntegersFunction operator-(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
    ModifiableIntegersFunction result;
    result.setML(lhs.getML() - rhs.getML());
    result.adoptBannedList(lhs);
    result.adoptBannedList(rhs);
    return result;
}

ModifiableIntegersFunction operator*(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
    ModifiableIntegersFunction result;
    size_t size = lhs.getBlSize();
    result.adoptBannedList(lhs);
    result.adoptBannedList(rhs);
    int16_t rhs_val, xval, result_val;
    for (size_t i = 0; i < size; i++) {
        //the xval is the same for both the lhs and rhs at this index, here we want to take 
        //rhs result for each x value, pass it to the lhs to find the result coresponding to it and then insert 
        //the x value and the final result
        xval = lhs.getMlXvalueByIndex(i);
        rhs_val = rhs.getMlRsultByIndex(i);
        result_val = lhs.calculate(rhs_val);
        result.addToML(xval, result_val);
    }
    return result;
}

bool operator<(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
    size_t size = lhs.getMlSize();
    int16_t lhs_val, rhs_val, lxval, rxval;
    for (int i = 0; i < size; i++) {
        lxval = lhs.getMlXvalueByIndex(i);
        rxval = rhs.getMlXvalueByIndex(i);
        lhs_val = lhs.getMlRsultByIndex(i);
        rhs_val = rhs.getMlRsultByIndex(i);
        if (lhs.isBanned(lhs_val)) {
            continue;
        }
        if (rhs.isBanned(rhs_val)) {
            return false;
        }
        if (lhs_val > rhs_val) {
            return false;
        }
       
    }
    return true;
}

bool operator|(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
    size_t size = lhs.getMlSize();
    int16_t lhs_value, rhs_value, lhs_prev, rhs_prev;
    for (size_t i = 1; i < size; i++) {
        //if either of them is interupted in a point they don't cross so we continue
        lhs_value = lhs.getMlRsultByIndex(i);
        lhs_prev = lhs.getMlRsultByIndex(i - 1);
        rhs_value = rhs.getMlRsultByIndex(i);
        rhs_prev = rhs.getMlRsultByIndex(i - 1);
        if (lhs.isBanned(lhs_value) || rhs.isBanned(rhs_value) || 
            lhs.isBanned(lhs_prev) || rhs.isBanned(rhs_prev)) {
            i += 2;
            continue;
        }
        if (lhs_value - rhs_value != lhs_prev - rhs_prev) {
            return false;
        }
    }
    return true;
}
