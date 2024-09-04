#include "Serializable.h"
#include <cstring>

Serializable::Serializable(const char* path) {
	strcpy(_filePath, path);
}