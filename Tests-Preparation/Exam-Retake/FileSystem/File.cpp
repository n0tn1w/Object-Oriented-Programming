#include "Files.h"
#include <cstring>
#include <iostream>

File::File(const char* name) {
	strcpy_s(_name, name);
}
const char* File::getName() const {
	return _name;
}

void File::printDir(int depth) const {
	for (size_t i = 0; i < depth; i++) {
		std::cout << '\t';
	}
	std::cout << "- " << _name << '\n';
}

TextFile::TextFile(const char* name, const char* data) : File(name){
	size_t len = strlen(data);
	_data = new char[len];

	memcpy(_data, data, len);
}

void TextFile::printContent() const {
	std::cout << _name << std::endl;
	std::cout << "---------" << std::endl;
	std::cout << _data;
}

File* TextFile::clone() const {
	return new TextFile(*this);
}

TextFile::~TextFile() {
	delete[] _data;
}

Dir::Dir(const char* name) : File(name) {
	_size = 0;
	_capacity = 8;
	_files = new File*[_capacity];
}

void Dir::add(File* f){
	_files[_size++] = f;
}
void Dir::add(const File& f) {
	_files[_size++] = f.clone();
}
File* Dir::clone() const {
	return new Dir(*this);
}

void Dir::printDir(int depth) const {
	File::printDir(depth);
	for (int i = 0; i < _size; i++) {
		_files[i]->printDir(depth + 1);
	}
}

void Dir::printContent() const {
	int depth = 0;
	File::printDir(depth);
	for (int i = 0; i < _size; i++) {
		_files[i]->printDir(depth + 1);
	}
}

File* Dir::findByName(const char* str) const {
	for (size_t i = 0; i < _size; i++) {
		if (strcmp(_files[i]->getName(), str) == 0) {
			return _files[i];
		}
	}
	return nullptr;
}

Dir::~Dir() {
	delete[] _files;
}