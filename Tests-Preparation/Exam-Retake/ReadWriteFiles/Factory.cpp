#include "Factory.h"
#include "Reading.h"
#include "Writing.h"
#include <cstring>

const char* getExtensions(const char* str) {

	while (*str != '.') {
		str++;
	}
	str++;
	return str;
}

Serializable* FactorySerialize::create(const char* str) {
	const char* ext = getExtensions(str);
	if (strcmp(ext, "dat") == 0) {
		return new BinaryWrite(str);
	}
	else if (strcmp(ext, "txt") == 0) {
		return new TextWrite(str);
	}
	else {
		throw std::runtime_error("Invalid file format in FactorySerialize!");
	}
} 

Deserializable* FactoryDeserialize::create(const char* str) {
	const char* ext = getExtensions(str);
	if (strcmp(ext, "dat") == 0) {
		return new BinaryRead(str);
	}
	else if (strcmp(ext, "txt") == 0) {
		return new TextRead(str);
	}
	else {
		throw std::runtime_error("Invalid file format in FactoryDeserialize!");
	}
}