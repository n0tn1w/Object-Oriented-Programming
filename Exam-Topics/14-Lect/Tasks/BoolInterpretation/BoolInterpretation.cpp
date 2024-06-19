#include "BoolInterpretation.h"

void BoolInterpretation::modify(size_t permutationNo) {
    
    for(int i = DATA_SIZE - 1; i >= 0; --i) {
        
        if(_grammer[i]) {
            if(permutationNo % 2 == 0) {
                _grammer[i] = false;
            }
            permutationNo /= 2;
        }
        
    }
}

bool BoolInterpretation::getCharAt(char ch) const {
    return _grammer[ch - 'a'];
}

void BoolInterpretation::setCharAt(char ch, bool val) {
    _grammer[ch - 'a'] = val;
}

size_t BoolInterpretation::turnOnCount() const {
    
    size_t cnt = 0;

    for(size_t i = 0; i < DATA_SIZE; i++) {
        if(_grammer[i])
            cnt++;
    }

    return cnt;
}
