#pragma once
#include "Serializable.h"
#include "Deserializable.h"

static const char* getExtensions(const char* str);

class FactorySerialize {

public:

	static Serializable* create(const char* str);

};

class FactoryDeserialize {

public:

	static Deserializable* create(const char* str);

};