#include "MultiSet.h"

namespace ErrorMessagesMultiSet {
	constexpr char NUMBER_OUT_OF_RANGE_ERR[] = "Number out of range!";
	constexpr char COUNT_OUT_OF_RANGE_ERR[] = "Count out of range!";
	constexpr char SIZE_DOESNT_MATCH_ERR[] = "Size doesnt match!";
	constexpr char VALUES_BREAK_SCOPE_ERR[] = "Added values break type scole!";
	constexpr char INCORRECT_EXPONENT_ERR[] = "Exponent in power function is not correct!";
	constexpr char INVALID_CONVERSION[] = "Invalid converstion!";
}

namespace HelperFunctionsMultiSet {
	int power(int base, int exponent) {
		if (exponent < 0) {
			throw std::logic_error(ErrorMessagesMultiSet::INCORRECT_EXPONENT_ERR);
		}

		int result = 1;
		for (int i = 0; i < exponent; ++i) {
			result *= base;
		}
		return result;
	}
};

size_t MultiSet::getBucketCount() const {
	size_t res = (_n + 1) * _k;
	return res % ConstMultiSet::BUCKET_SIZE == 0 
		? (res /  ConstMultiSet::BUCKET_SIZE) 
		: (res / ConstMultiSet::BUCKET_SIZE) + 1;
}
size_t MultiSet::getBucketIndex(size_t number) const {
	return (number * _k) / ConstMultiSet::BUCKET_SIZE;
}
size_t MultiSet::getBitIndex(size_t number) const {
	return (number * _k) % ConstMultiSet::BUCKET_SIZE;
}

// The validations could be done like the ones in task 2
bool MultiSet::validateNumber(size_t number) const {
	return number < _n;
}
bool MultiSet::validateCountAddition(uint8_t count) const {
	return count <= (HelperFunctionsMultiSet::power(2, _k) - 1);
}
bool MultiSet::validateCountSubtraction(uint8_t count) const {
	return 0 <= count;
}
bool MultiSet::validateCountAdditionTwoNumbers(uint8_t l, uint8_t r) const {
	int res =(int)l + (int)r;
	return res <= UINT8_MAX;
}


MultiSet::MultiSet(size_t n, size_t k) {
	_n = n;
	_k = k;
	_bucketCount = getBucketCount();
	_data = new uint8_t[_bucketCount]{ 0 };
}

void MultiSet::copyFrom(const MultiSet& oth) {
	_n = oth._n;
	_k = oth._k;
	_bucketCount = oth._bucketCount;
	_data = new uint8_t[oth._bucketCount];

	for (size_t i = 0; i < oth._bucketCount; i++) {
		_data[i] = oth._data[i];
	}
}

MultiSet::MultiSet(const MultiSet& oth) {
	copyFrom(oth);
}

void MultiSet::free() {
	delete[] _data;
	_n = 0;
	_k = 0;
	_data = nullptr;
}

MultiSet& MultiSet::operator=(const MultiSet& oth) {
	if (this != &oth) {
		free();
		copyFrom(oth);
	}

	return *this;
}

MultiSet::~MultiSet() {
	free();
}

void MultiSet::moveFrom(MultiSet&& oth) noexcept {
	_n = oth._n;
	_k = oth._k;
	_bucketCount = oth._bucketCount;
	_data = oth._data;

	oth._n = 0;
	oth._k = 0;
	oth._bucketCount = 0;
	oth._data = nullptr;
}

MultiSet::MultiSet(MultiSet&& oth) noexcept {
	moveFrom(std::move(oth));
}

MultiSet& MultiSet::operator=(MultiSet&& oth) noexcept {
	if (this != &oth) 
	{
		free();
		moveFrom(std::move(oth));
	}
	return *this;
}


uint8_t MultiSet::check(size_t number) const{
	if (!validateNumber(number)) {
		throw std::out_of_range(ErrorMessagesMultiSet::NUMBER_OUT_OF_RANGE_ERR);
		//return false;
	}

	size_t bucketIndex = getBucketIndex(number);
	size_t bitIndex = getBitIndex(number);
	uint8_t count = 0;

	for (size_t i = 0; i < _k; i++) {
		size_t shifted = (bitIndex + i) % ConstMultiSet::BUCKET_SIZE;
		size_t bucketOffset = (bitIndex + i) / ConstMultiSet::BUCKET_SIZE;

		count += ((_data[bucketIndex + bucketOffset] >> shifted) & 1) << i;
	}

	return count;
}

bool MultiSet::setCounter(size_t number, uint8_t countNumber) {

	size_t bucketIndex = getBucketIndex(number);
	size_t bitIndex = getBitIndex(number);

	for (size_t i = 0; i < _k; i++) {
		size_t shifted = (bitIndex + i) % ConstMultiSet::BUCKET_SIZE;
		size_t bucketOffset = (bitIndex + i) / ConstMultiSet::BUCKET_SIZE;

		uint8_t bit = (((uint8_t)(countNumber << (ConstMultiSet::BUCKET_SIZE - i - 1)))
			>> (ConstMultiSet::BUCKET_SIZE - 1));
		uint8_t mask = (1 << shifted);

		if (bit == 1) {
			_data[bucketIndex + bucketOffset] |= mask;
		}
		else if (bit == 0) {
			_data[bucketIndex + bucketOffset] &= ~(mask);
		}
		else {
			throw std::runtime_error(ErrorMessagesMultiSet::INVALID_CONVERSION);
			return false;
		}
	}

	return true;
}


bool MultiSet::add(size_t number) {
	if (!validateNumber(number)) {
		throw std::out_of_range(ErrorMessagesMultiSet::NUMBER_OUT_OF_RANGE_ERR);
		//return false;
	}

	int countNumber = check(number);
	countNumber++;
	
	if (!validateCountAddition(countNumber)) {
		throw std::out_of_range(ErrorMessagesMultiSet::COUNT_OUT_OF_RANGE_ERR);
		//return false;
	}

	setCounter(number, countNumber);
	return true;
}

bool MultiSet::remove(size_t number) {
	if (!validateNumber(number)) {
		throw std::out_of_range(ErrorMessagesMultiSet::NUMBER_OUT_OF_RANGE_ERR);
		//return false;
	}

	uint8_t countNumber = check(number);
	countNumber--;
	if (!validateCountSubtraction(countNumber)) {
		throw std::out_of_range(ErrorMessagesMultiSet::COUNT_OUT_OF_RANGE_ERR);
		//return false;
	}

	setCounter(number, countNumber);
	return true;
}

void MultiSet::print() const {
	cout << "[";

	bool coma = true;
	for (size_t i = 0; i < _n; i++) {

		size_t count = check(i);
		for (size_t k = 0; k < count; k++) {

			if (coma) {
				coma = false;
			}
			else {
				cout << ", ";
			}

			cout << i;
		}
	}
	cout << "]" << endl;
}

void MultiSet::printMemory() const {
	for (size_t i = 0; i < _bucketCount; i++) {
		cout << i << ": " << _data[i] << endl;
	}
}

void MultiSet::addMultiple(size_t number, size_t count) {
	for(size_t i = 0; i < count; i++) {
		add(number);
	}
}

MultiSet unification(const MultiSet& lhs, const MultiSet& rhs) {
	
	if (lhs._n != rhs._n) {
		throw std::logic_error(ErrorMessagesMultiSet::SIZE_DOESNT_MATCH_ERR);
	}
	MultiSet res(lhs._n, lhs._k + rhs._k);

	size_t cnt = lhs._n;

	for (size_t i = 0; i < cnt; i++) {
		uint8_t l = lhs.check(i);
		uint8_t r = rhs.check(i);
	
		if (!res.validateCountAdditionTwoNumbers(l, r))
			throw std::range_error(ErrorMessagesMultiSet::VALUES_BREAK_SCOPE_ERR);

		res.addMultiple(i, l+r);
	}

	return res;
}

MultiSet section(const MultiSet& lhs, const MultiSet& rhs) {

	if (lhs._n != rhs._n) {
		throw std::logic_error(ErrorMessagesMultiSet::SIZE_DOESNT_MATCH_ERR);
	}

	MultiSet res(lhs._n, std::max(lhs._k, rhs._k));
	size_t cnt = lhs._n;

	for (size_t i = 0; i < cnt; i++) {
		uint8_t l = lhs.check(i);
		uint8_t r = rhs.check(i);

		res.addMultiple(i, std::min(l,r));
	}

	return res;
}

MultiSet addition(const MultiSet& lhs) {
	MultiSet res(lhs._n, lhs._k);
	size_t cnt = lhs._n;

	for (size_t i = 0; i < cnt; i++) {
		uint8_t l = lhs.check(i);
		int cnt = HelperFunctionsMultiSet::power(2, lhs._k) - 1 - l;
		res.addMultiple(i, cnt);
	}

	return res;
}

std::ofstream& operator<<(std::ofstream& os, const MultiSet& oth) {
	os.write((const char*) &oth._n, sizeof(oth._n));
	os.write((const char*) &oth._k, sizeof(oth._k));
	os.write((const char*) &oth._bucketCount, sizeof(oth._bucketCount));
	os.write((const char*)oth._data, oth._bucketCount * ConstMultiSet::BUCKET_SIZE);
	return os;
}

std::ifstream& operator>>(std::ifstream& is, MultiSet& oth) {
	oth.free();

	is.read((char*)&oth._n, sizeof(oth._n));
	is.read((char*)&oth._k, sizeof(oth._k));
	is.read((char*)&oth._bucketCount, sizeof(oth._bucketCount));
	oth._data = new uint8_t[oth._bucketCount];
	is.read((char*)oth._data, oth._bucketCount * ConstMultiSet::BUCKET_SIZE);
	return is;
}
