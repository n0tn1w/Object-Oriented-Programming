#pragma once
#include "Deserializable.h"
#include <fstream>

static size_t getFileLen(std::ifstream& ifs);


class BinaryRead : public Deserializable {

public:
	
	BinaryRead(const char*);
	Deserializable* clone() const override;
	char* deserialize(size_t&) const override;
};


class TextRead : public Deserializable {

public:

	TextRead(const char*);
	Deserializable* clone() const override;
	char* deserialize(size_t& len) const override;
};