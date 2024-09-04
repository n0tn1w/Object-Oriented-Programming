#pragma once

// decode from file / read

class Deserializable {

protected:

	char _filePath[32 + 1];

public:

	Deserializable(const char*);
	virtual char* deserialize(size_t&) const = 0;

	virtual Deserializable* clone() const = 0;
	virtual ~Deserializable() = default;
};