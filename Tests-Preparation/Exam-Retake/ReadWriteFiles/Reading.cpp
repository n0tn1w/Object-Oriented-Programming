#include "Reading.h"
#include <fstream>

size_t getFileLen(std::ifstream& ifs) {
	size_t len = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(len);
	return size;
}

BinaryRead::BinaryRead(const char* filePath) : Deserializable(filePath) {}

Deserializable* BinaryRead::clone() const {
	return new BinaryRead(*this);
}

char* BinaryRead::deserialize(size_t& len) const {
	std::ifstream ifs(_filePath, std::ios::binary | std::ios::in);

	len = getFileLen(ifs);
	char* buff = new char[len];
	ifs.read(reinterpret_cast<char*>(buff), len);

	return buff;
}
TextRead::TextRead(const char* filePath) : Deserializable(filePath) { }

Deserializable* TextRead::clone() const {
	return new TextRead(*this);
}

char* TextRead::deserialize(size_t& len) const {
	std::ifstream ifs(_filePath, std::ios::in | std::ios::binary);
	len = getFileLen(ifs);

	char* buff = new char[len];
	ifs.read(reinterpret_cast<char*>(buff), len);

	return buff;
}

