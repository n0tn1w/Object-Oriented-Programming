#include "Writing.h"
#include <fstream>

BinaryWrite::BinaryWrite(const char* filePath) : Serializable(filePath) {}

Serializable* BinaryWrite::clone() const {
	return new BinaryWrite(*this);
}

void BinaryWrite::serialize(const char* data, size_t len) const {
	
	std::ofstream ofs(_filePath, std::ios::binary | std::ios::out | std::ios::app);

	ofs.write(reinterpret_cast<const char*>(data), len);

}


TextWrite::TextWrite(const char* filePath) : Serializable(filePath) {}

Serializable* TextWrite::clone() const {
	return new TextWrite(*this);
}

void TextWrite::serialize(const char* data, size_t len) const {
	
	std::ofstream ofs(_filePath, std::ios::out | std::ios::app);

	ofs.write(reinterpret_cast<const char*>(data), len);
	
}