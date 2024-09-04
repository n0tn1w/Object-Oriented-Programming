#include "FileSystem.h"
#include <cstring>
#include <stdexcept>

FileSystem::FileSystem() {
	_root = new Dir("root");
}

File* FileSystem::getFile(const char* str) {
	// "root/d1/d2/f1"
	size_t dirLen = 5;
	char* firstDir = new char[dirLen];
	strncpy(firstDir, str + 0, 4);
	firstDir[4] = '\0';
	if (strcmp(firstDir, "root") != 0) {
		throw;
	}
	delete[] firstDir;
	
	return extractFile(_root, str + 5);
}

File* FileSystem::extractFile(Dir* dir, const char* str) {

	size_t len = strlen(str);
	if (len == 0) {
		return dir;
	}

	int index = extractPathName(str);
	bool last = false;
	if(index == -1) {
		last = true;
		index = len;
	}

	char* firstDir = new char[index + 1];
	strncpy(firstDir, str, index);
	firstDir[index] = '\0';

	if (!last) {
		Dir* f = static_cast<Dir*>(dir->findByName(firstDir));
		delete[] firstDir;
		return extractFile(f, str + index + 1);
	}
	else if(last) {
		File* f = dir->findByName(firstDir);
		delete[] firstDir;
		return f;
	}
}


int FileSystem::extractPathName(const char* str) {
	
	size_t len = strlen(str);

	for (size_t i = 0; i < len; i++) {
		if (str[i] == '/') {
			return i;
		}
	}
	return -1;
}

int FileSystem::extractLastName(const char* str) {

	size_t len = strlen(str);

	for (size_t i = len; i > 0 ; i--) {
		if (str[i] == '/') {
			return i;
		}
	}

	return -1;


}

void FileSystem::createDir(const char* str) {
	int indexF = extractPathName(str);

	size_t dirLen = indexF + 1;
	char* firstDir = new char[dirLen];
	strncpy(firstDir, str + 0, indexF);
	firstDir[indexF] = '\0';
	if (strcmp(firstDir, "root") != 0) {
		return;
	}
	delete[] firstDir;


	size_t len = strlen(str);
	int index = extractLastName(str);
	char* lastDir = new char[len - index];
	strncpy(lastDir, str + index + 1, len - index - 1);
	lastDir[len - index - 1] = '\0';

	const char* path = str + indexF + 1;

	createOrFind(_root, path, lastDir, nullptr);
	delete[] lastDir;
}

void FileSystem::createTextFile(const char* str, const char* content) {
	int indexF = extractPathName(str);

	size_t dirLen = indexF + 1;
	char* firstDir = new char[dirLen];
	strncpy(firstDir, str + 0, indexF);
	firstDir[indexF] = '\0';
	if (strcmp(firstDir, "root") != 0) {
		return;
	}
	delete[] firstDir;


	size_t len = strlen(str);
	int index = extractLastName(str);
	char* lastDir = new char[len - index];
	strncpy(lastDir, str + index + 1, len - index - 1);
	lastDir[len - index - 1] = '\0';

	const char* path = str + indexF + 1;

	createOrFind(_root, path, lastDir, content);
	delete[] lastDir;
}

void FileSystem::createOrFind(Dir* dir, const char* path, const char* lastDir, const char* content) {
	size_t len = strlen(path);
	int index = extractPathName(path);
	char* firstDir = nullptr;
	if (index == -1) {
		index = len;
	}
	firstDir = new char[index + 1];
	strncpy(firstDir, path, index);
	firstDir[index] = '\0';

	if (strcmp(firstDir, lastDir) == 0) {

		if (content == nullptr) {
			dir->add(new Dir(firstDir));
		}
		else {
			dir->add(new TextFile(firstDir, content));
		}
		delete[] firstDir;

		return;
	}

	File* f = dir->findByName(firstDir);
	if (f == nullptr) {
		dir->add(new Dir(firstDir));
		f = dir->findByName(firstDir);
	}
	Dir* dr = static_cast<Dir*>(f);
	delete[] firstDir;

	const char* pathNew = path + index + 1;
	createOrFind(dr, pathNew, lastDir, content);
}


