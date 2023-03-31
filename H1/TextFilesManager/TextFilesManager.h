#pragma once
#include "File.h"
#include "utilities.h"
#include "stringHelper.h"
#include "SortOptions.h"

#include <iostream>
using namespace std;

class TextFilesManager {

	size_t filesCnt;
	size_t total;
	File* files;

public:

	TextFilesManager(size_t);
	~TextFilesManager();

	size_t getFilesCnt() const;
	File& getFileByIndex(size_t);

	bool addFile(const char*, size_t, size_t, size_t, size_t, size_t, size_t, const char*);
	bool editFile(const char*, const char*, size_t, size_t, size_t, size_t, size_t, size_t, const char);
	bool addInFile(const char*, const char*, size_t, size_t, size_t, size_t, size_t, size_t, const char);
	bool deleteFile(const char*);
	bool changeRights(const char*, const char, const char);

	void printFile(const char*, const char);
	void printFileInfo(const char*);
	void print();

	void sort(const SortOptions&);

private:
	int indexOfFile(const char*);

	void quicksort(int, int, int);
	int partition(int, int, int);
	bool compareFilesByName(const File&, const File&);
	bool compareFilesBySize(const File&, const File&);
	bool compareFilesByCreatedTime(const File&, const File&);
	bool compareFilesByMtime(const File&, const File&);

	void swappy(int, int);
};