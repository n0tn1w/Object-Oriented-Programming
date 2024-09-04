#include <iostream>
#include "Reading.h"
#include "Writing.h"
#include "Factory.h"

int main() {
	Serializable* write = FactorySerialize::create("file.txt");
	write->serialize("Done!", 5);

	Deserializable* read = FactoryDeserialize::create("file.txt");
	size_t len = 0;
	const char* data = read->deserialize(len);
	for (size_t i = 0; i < len; i++) {
		std::cout << data[i];
	}
}