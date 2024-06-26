#include "MultiSet.h"

MultiSet::MultiSet(size_t N) {
    _N = N;
    _data = new uint8_t[N];
}

size_t MultiSet::getBucket(size_t index) const {
    if(index >= _N) {
        throw "Index out of bound!";
    }
    return index / Consts::NUMBERS_IN_BUCKET;
}

size_t MultiSet::getBitIndex(size_t index) const {
        if(index >= _N) {
        throw "Index out of bound!";
    }
    return index % Consts::NUMBERS_IN_BUCKET;
}

int MultiSet::count(size_t index) const {
    uint8_t bucket = _data[getBucket(index)];
    size_t bitIndex = getBitIndex(index);

    bool f = bucket & (1 << bitIndex * 2);
    bool s = bucket & (1 << bitIndex * 2 + 1);
    
    if(f && s) {
        return 3;
    } else if (f && !s) {
        return 2;
    } else if(!f && s) {
        return 1;
    } else {
        return 0;
    }
}

bool MultiSet::add(size_t index) {
    int cnt = count(index);
    if( cnt >= 3) {
        return false;
    }

    size_t bucketIndex = getBucket(index);
    size_t bitIndex = getBitIndex(index);
    if(cnt == 0 || cnt == 2) {
        uint8_t mask = 1;
        mask <<= 2*bitIndex + 1;
        _data[bucketIndex] |= mask;
    } else {
        uint8_t maskF = 255;
        maskF ^= (1 << 2*bitIndex + 1);
        _data[bucketIndex] &= maskF;
        // uint8_t maskF = 1;
        // maskF <<= 2*bitIndex + 1;
        // maskF = -maskF;
        // _data[bucketIndex] &= maskF;
        uint8_t maskS = 1;
        maskS <<= 2*bitIndex;
        _data[bucketIndex] |= maskS;
    }

    uint8_t kk = _data[bucketIndex];
    return true;
}

bool MultiSet::remove(size_t index) {
    int cnt = count(index);
    if( cnt == 0) {
        return false;
    }

    size_t bucketIndex = getBucket(index);
    size_t bitIndex = getBitIndex(index);

    if(cnt == 1 || cnt == 3) {
        uint8_t mask = 255;
        mask ^= (1 << bitIndex*2 + 1);
        _data[bucketIndex] &= mask;
    } else {
        uint8_t maskF = 1;
        maskF <<= bitIndex*2 + 1;
        _data[bucketIndex] |= maskF;

        uint8_t maskS = 255;
        maskS ^= (1 << bitIndex*2);
        _data[bucketIndex] &= maskS;
    }
    return true;

}

void MultiSet::free() {
    delete [] _data;
    _data = nullptr;
    _N = 0;
}

MultiSet::~MultiSet() {
    free();
}

void MultiSet::print() const {
    cout << "[ ";

    for(size_t i = 0; i < _N; i++) {
        int cnt = count(i);
        while(cnt > 0) {
            cout << i << " ";
            cnt--;
        }
    }

    cout << "]" << endl;
}

// Desis's unify
// This is incorect ill fix it
MultiSet unify(const MultiSet& s1, const MultiSet& s2) {
	//assert(s1.n == s2.n);

	size_t n = s1._N;
	MultiSet res(n);

	for (unsigned i = 0; i < (s1._N / Consts::NUMBERS_IN_BUCKET + 1); i++)
	{
		res._data[i] = s1._data[i] | s2._data[i];
	}

	return res;
}