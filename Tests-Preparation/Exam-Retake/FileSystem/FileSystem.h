#pragma once
#include "Files.h"

class FileSystem {

private:

	Dir* _root;

public:

	FileSystem();
	File* getFile(const char* str);
	int extractPathName(const char* str);
	File* extractFile(Dir* dir, const char* str);

	void createTextFile(const char* str, const char* content);
	void createDir(const char* str);

	int extractLastName(const char* str);
	void createOrFind(Dir* dir, const char* path, const char* name, const char* content);

};