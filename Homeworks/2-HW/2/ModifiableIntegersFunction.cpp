#include "ModifiableIntegersFunction.h"

namespace ErrorMessagesMIF {
	constexpr char NUMBER_OUT_OF_RANGE_ERR[] = "Number out of range!";
	constexpr char ALREADY_REMOVED_ERR[] = "Number is already removed!";
	constexpr char ADD_NUMBERS_OVERFLOW[] = "Add numbers overflow!";
	constexpr char SUBTRACT_NUMBERS_OVERFLOW[] = "Subtract numbers overflow!";
	constexpr char ERROR_IN_MULTIPLE_USE_OPERATOR[] = "Error in multiple use operator. k should be positive or -1!";
	constexpr char IMPOSIBLE_MULTIPLE_USE_OPERATOR[] = "Error in multiple use operator. The function is not Bijection!";
	constexpr char NOT_GOOD_OBJECT[] = "Object is not valid!";

}

namespace ResultsOpreationsMIF {
	int add(int16_t a, int16_t b) {
		return a + b;
	}

	int subtract(int16_t a, int16_t b) {
		return a - b;
	}
}

ModifiableIntegersFunction::ModifiableIntegersFunction() {
	_results = new int16_t[ConstsMIF::TOTAL_CAPACITY_RESULTS]{ 0 };
	_isSet = true;

	try {
		_removed = new uint8_t[ConstsMIF::TOTAL_CAPACITY_REMOVED]{ 0 };
	}
	catch (std::bad_alloc& e) {
		delete[] _results;
		_isSet = false;

		throw;
	}

}
void ModifiableIntegersFunction::copyFrom(const ModifiableIntegersFunction& oth) {
	for (size_t i = 0; i < ConstsMIF::TOTAL_CAPACITY_RESULTS; i++)
		_results[i] = oth._results[i];

	for (size_t i = 0; i <= ConstsMIF::TOTAL_CAPACITY_REMOVED; i++)
		_removed[i] = oth._removed[i];

	_isSet = oth._isSet;
}
ModifiableIntegersFunction::ModifiableIntegersFunction(const ModifiableIntegersFunction& oth) : ModifiableIntegersFunction() {
	copyFrom(oth);
}
void ModifiableIntegersFunction::free() {
	delete[] _results;
	delete[] _removed;

	_results = nullptr;
	_removed = nullptr;
	_isSet = false;
}
ModifiableIntegersFunction& ModifiableIntegersFunction::operator=(const ModifiableIntegersFunction& oth) {
	if (this != &oth) {
		free();
		copyFrom(oth);
	}

	return *this;
}
ModifiableIntegersFunction::~ModifiableIntegersFunction() {
	free();
}
void ModifiableIntegersFunction::moveFrom(ModifiableIntegersFunction&& oth) noexcept {
	_results = oth._results;
	_removed = oth._removed;
	_isSet = oth._isSet;

	oth._results = nullptr;
	oth._removed = nullptr;
	oth._isSet = false;
}
ModifiableIntegersFunction::ModifiableIntegersFunction(ModifiableIntegersFunction&& oth) noexcept {
	moveFrom(std::move(oth));
}
ModifiableIntegersFunction& ModifiableIntegersFunction::operator=(ModifiableIntegersFunction&& oth) noexcept {
	if (this != &oth) {
		free();
		moveFrom(std::move(oth));
	}

	return *this;
}

ModifiableIntegersFunction::ModifiableIntegersFunction(FuncPtr func) : ModifiableIntegersFunction() {
	setFunction(func);
}

void ModifiableIntegersFunction::generateValues(FuncPtr func) {
	for (int i = ConstsMIF::MIN_VALUE; i <= ConstsMIF::MAX_VALUE; i++) {
		int16_t res = func(i);
		if (!validateNumberInRange(res)) {
			//throw std::out_of_range(ErrorMessagesMIF::NUMBER_OUT_OF_RANGE_ERR);
			removeResult(res);
			return;
		}
		setResultByNumber(i, res);
	}
}

size_t ModifiableIntegersFunction::getIndexByNumber(int index) const {
	size_t bucketIndex = index - ConstsMIF::MIN_VALUE;
	return bucketIndex;
}

int16_t ModifiableIntegersFunction::getResultByNumber(int number) const {
	return _results[getIndexByNumber(number)];
}


void ModifiableIntegersFunction::setResultByNumber(int index, int16_t value) {
	_results[getIndexByNumber(index)] = value;
}


void ModifiableIntegersFunction::presetResult(int number, int16_t value) {
	if(!good()) {
		throw std::runtime_error(ErrorMessagesMIF::NOT_GOOD_OBJECT);
	}

	if (isRemoved(number)) {
		throw std::logic_error(ErrorMessagesMIF::ALREADY_REMOVED_ERR);
	}

	if (!validateNumberInRange(number)) {
		//throw std::out_of_range(ErrorMessagesMIF::NUMBER_OUT_OF_RANGE_ERR);
		removeResult(number);
		return;
	}

	setResultByNumber(number, value);
}

bool ModifiableIntegersFunction::validateNumberInRange(int number) const {
	return ConstsMIF::MIN_VALUE <= number && number <= ConstsMIF::MAX_VALUE;
}

bool ModifiableIntegersFunction::isRemoved(int index) const {
	size_t bucketIndex = getRemovedBucketIndex(index);
	size_t bitIndex = getRemovedBitIndex(index);

	uint8_t mask = (1 << bitIndex);
	return (_removed[bucketIndex] & mask);
}

size_t ModifiableIntegersFunction::getRemovedBucketIndex(int index) const {
	return getIndexByNumber(index) / ConstsMIF::BUCKET_SIZE;
}

size_t ModifiableIntegersFunction::getRemovedBitIndex(int index) const {
	return getIndexByNumber(index) % ConstsMIF::BUCKET_SIZE;
}

void ModifiableIntegersFunction::removeResult(int number) {
	if(!good()) {
		throw std::runtime_error(ErrorMessagesMIF::NOT_GOOD_OBJECT);
	}


	if (!validateNumberInRange(number)) {
		throw std::out_of_range(ErrorMessagesMIF::NUMBER_OUT_OF_RANGE_ERR);
	}
	
	size_t bucketIndex = getRemovedBucketIndex(number);
	size_t bitIndex = getRemovedBitIndex(number);

	_removed[bucketIndex] |= (1 << bitIndex);
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator+=(const ModifiableIntegersFunction& oth) {
	if(!good() || !oth.good()) {
		throw std::runtime_error(ErrorMessagesMIF::NOT_GOOD_OBJECT);
	}

	unifyRemoved(oth);
	
	for (int i = ConstsMIF::MIN_VALUE; i <= ConstsMIF::MAX_VALUE; i++) {
		if (isRemoved(i)) {
			continue;
		}
		size_t numberIndex = getIndexByNumber(i);
		if (!validateOperation(_results[numberIndex], oth._results[numberIndex], ResultsOpreationsMIF::add)) {
			throw std::logic_error(ErrorMessagesMIF::ADD_NUMBERS_OVERFLOW);
		}
		_results[numberIndex] += oth._results[numberIndex];
	}

	return *this;
}

void ModifiableIntegersFunction::unifyRemoved(const ModifiableIntegersFunction& oth) {
	for (size_t i = 0; i < ConstsMIF::TOTAL_CAPACITY_REMOVED; i++) {
		_removed[i] |= oth._removed[i];
	}
}

bool ModifiableIntegersFunction::validateOperation(int16_t a, int16_t b, ResultsOpreationsMIF::ResultOperation fun) const {
	return validateNumberInRange(fun(a, b));
}

ModifiableIntegersFunction operator+(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
	ModifiableIntegersFunction res(lhs);
	res += rhs;
	return res;
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator-=(const ModifiableIntegersFunction& oth) {
	if(!good() || !oth.good()) {
		throw std::runtime_error(ErrorMessagesMIF::NOT_GOOD_OBJECT);
	}

	unifyRemoved(oth);

	for (int i = ConstsMIF::MIN_VALUE; i <= ConstsMIF::MAX_VALUE; i++) {
		if (isRemoved(i)) {
			continue;
		}

		size_t numberIndex = getIndexByNumber(i);
		if (!validateOperation(_results[numberIndex], oth._results[numberIndex], ResultsOpreationsMIF::subtract)) {
			throw std::logic_error(ErrorMessagesMIF::SUBTRACT_NUMBERS_OVERFLOW);
		}
		_results[numberIndex] -= oth._results[numberIndex];
	}
	return *this;
}

ModifiableIntegersFunction operator-(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
	ModifiableIntegersFunction res(lhs);
	res -= rhs;
	return res;
}

bool operator<(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
	for (int i = ConstsMIF::MIN_VALUE; i <= ConstsMIF::MAX_VALUE; i++) {

		int16_t lhsCurrRes = !lhs.isRemoved(i) ? lhs.getResultByNumber(i) : ConstsMIF::MIN_VALUE;
		int16_t rhsCurrRes = !rhs.isRemoved(i) ? rhs.getResultByNumber(i) : ConstsMIF::MIN_VALUE;

		if (lhsCurrRes >= rhsCurrRes) {
			return false;
		}
	}
	return true;
}

std::ofstream& operator<<(std::ofstream& os, const ModifiableIntegersFunction& oth) {
	if(!oth.good()) {
		throw std::runtime_error(ErrorMessagesMIF::NOT_GOOD_OBJECT);
	}

	os.write((const char*)oth._results, ConstsMIF::TOTAL_CAPACITY_RESULTS * sizeof(int16_t));
	os.write((const char*)oth._removed, ConstsMIF::TOTAL_CAPACITY_REMOVED * sizeof(uint8_t));
	return os;
}

std::ifstream& operator>>(std::ifstream& is, ModifiableIntegersFunction& oth) {
	oth.free();
	is.read((char*)oth._results, ConstsMIF::TOTAL_CAPACITY_RESULTS * sizeof(int16_t));
	is.read((char*)oth._removed, ConstsMIF::TOTAL_CAPACITY_REMOVED * sizeof(uint8_t));
	oth._isSet = true; // We are setting the object from here

	return is;
}

void ModifiableIntegersFunction::draw(Point f, Point s) const {
	if (!(s.x - f.x == 20 && s.y - f.y == 20)) {
		// Draw is expected to print in the terminal
		// So when the range is invalid it should be also there
		std::cerr << "Invalid range!" << std::endl;
	}
	else {
		for (int i = f.y; i <= s.y; i++) {
			int16_t res = getResultByNumber(i);
			if (f.x <= res && res <= s.x) {
				std::cout << "<" << res << ", " << i << ">" << std::endl;
			}
		}
	}
}

bool operator|=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
	if(!lhs.good() || !rhs.good()) {
		throw std::runtime_error(ErrorMessagesMIF::NOT_GOOD_OBJECT);
	}

	bool setOffset = false;
	int offset = 0;
	for (int i = ConstsMIF::MIN_VALUE; i <= ConstsMIF::MAX_VALUE; i++) {
		if (lhs.isRemoved(i) ^ rhs.isRemoved(i)) {
			return false;
		}

		if (!setOffset) {
			setOffset = true;
			offset = std::abs(rhs.getResultByNumber(i) - lhs.getResultByNumber(i));
		}
		int currOffset = std::abs(rhs.getResultByNumber(i) - lhs.getResultByNumber(i));
		if (currOffset != offset) {
			return false;
		}
	}

	return true;
}

bool ModifiableIntegersFunction::isInjection() const {
	if(!good()) {
		throw std::runtime_error(ErrorMessagesMIF::NOT_GOOD_OBJECT);
	}
	
	bool* output = new bool[ConstsMIF::TOTAL_CAPACITY_RESULTS]{ 0 };
	try {

		for (int i = ConstsMIF::MIN_VALUE; i <= ConstsMIF::MAX_VALUE; i++) {
			if (isRemoved(i)) {
				continue;
			}
			int16_t res = getResultByNumber(i);
			size_t ind = getIndexByNumber(res);

			if (output[ind]) {
				return false;
			}
			else
			{
				output[ind] = true;
			}
		}
		return true;
	}
	catch (std::exception& e) {
		delete[] output;
		throw;
	}
}

bool ModifiableIntegersFunction::isSurection() const {
	if(!good()) {
		throw std::runtime_error(ErrorMessagesMIF::NOT_GOOD_OBJECT);
	}

	bool* output = new bool[ConstsMIF::TOTAL_CAPACITY_RESULTS] { 0 };

	try {
		for (int i = ConstsMIF::MIN_VALUE; i <= ConstsMIF::MAX_VALUE; i++) {
			if (isRemoved(i)) {
				continue;
			}
			int16_t res = getResultByNumber(i);
			size_t ind = getIndexByNumber(res);

			output[ind] = true;
		}

		for (size_t i = 0; i < ConstsMIF::TOTAL_CAPACITY_RESULTS; i++) {
			if (!output[i]) {
				return false;
			}
		}

		return true;
	}
	catch (std::exception& e) {
		delete[] output;
		throw;
	}
}

bool ModifiableIntegersFunction::isBijection() const {
	return isInjection() && isSurection();
}

ModifiableIntegersFunction operator^(const ModifiableIntegersFunction& oth, int k) {
	if(!oth.good()) {
		throw std::runtime_error(ErrorMessagesMIF::NOT_GOOD_OBJECT);
	}

	ModifiableIntegersFunction res;
	if (k == -1) {
		if (!oth.isBijection()) {
			throw std::logic_error(ErrorMessagesMIF::IMPOSIBLE_MULTIPLE_USE_OPERATOR);
		}

		for (int i = ConstsMIF::MIN_VALUE; i <= ConstsMIF::MAX_VALUE; i++) {
			res.presetResult(oth.getResultByNumber(i), i);
		}
	}
	else if (k >= 0) {
		// Not supported
		// Because with this structure this cannot be done!
	}
	else {
		throw std::logic_error(ErrorMessagesMIF::ERROR_IN_MULTIPLE_USE_OPERATOR);
	}
	return res;
}

bool ModifiableIntegersFunction::good() const {
	return _isSet;
}

void ModifiableIntegersFunction::setFunction(FuncPtr func) {
	generateValues(func);
	_isSet = true;
}
