#pragma once

// into file / write

class Serializable {

protected:

	char _filePath[32 + 1];

public:

	Serializable(const char*);
	virtual void serialize(const char* data, size_t len) const = 0;

	virtual Serializable* clone() const = 0;
	virtual ~Serializable() = default;

};