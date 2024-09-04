#include "Deserializable.h"
#include <cstring>

Deserializable::Deserializable(const char* path) {
	strcpy(_filePath, path);
}