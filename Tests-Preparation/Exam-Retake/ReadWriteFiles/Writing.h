#pragma once
#include "Serializable.h"
#include <fstream>


class BinaryWrite : public Serializable {

public:

	BinaryWrite(const char*);
	BinaryWrite(char*);
	Serializable* clone() const override;
	void serialize(const char* data, size_t len) const override;

};

class TextWrite : public Serializable {

public:

	TextWrite(const char*);
	Serializable* clone() const override;
	void serialize(const char* data, size_t len) const override;
};
