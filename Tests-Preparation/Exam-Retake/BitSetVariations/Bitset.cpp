#pragma once

#include <iostream>

const size_t BUCKET_SIZE = sizeof(unsigned char);

class Bitset {

protected:

	unsigned char* _buckets;
	size_t _size;

	size_t getBucket(int n) const { return n / BUCKET_SIZE; }
	size_t getBit(int n) const { return n % BUCKET_SIZE; }

	void reset() { 
		delete[] _buckets;
		_buckets = new unsigned char[_size % BUCKET_SIZE == 0 ? _size / BUCKET_SIZE : _size / BUCKET_SIZE + 1] {0};
	}
	

public:

	Bitset(size_t count) {
		_buckets = new unsigned char[count % BUCKET_SIZE == 0 ? count / BUCKET_SIZE : count / BUCKET_SIZE + 1] {0};
		_size = count;
	}
	// Big 6
	~Bitset() {
		delete[] _buckets;
		_size = 0;
	}

	void add(size_t n) {
		size_t bucketIndex = getBucket(n);
		size_t bitIndex = getBit(n);

		unsigned char mask = (1 << bitIndex);
		_buckets[bucketIndex] |= mask;
	}

	void remove(size_t n) {
		size_t bucketIndex = getBucket(n);
		size_t bitIndex = getBit(n);

		unsigned char mask = (1 << bitIndex);
		_buckets[bucketIndex] &= (~mask);
	}

	void print() const {
		for (size_t i = 0; i < _size; i++) {
			size_t bucketIndex = getBucket(i);
			size_t bitIndex = getBit(i);

			unsigned char mask = _buckets[bucketIndex] &= (1 << bitIndex);
			if (mask != 0) {
				std::cout << i << " ";
			}

		}
	}
};
