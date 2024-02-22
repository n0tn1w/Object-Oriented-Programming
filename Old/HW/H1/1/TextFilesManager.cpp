#include "TextFilesManager.h"

TextFilesManager::TextFilesManager(size_t len) {
	this->total = len;
	this->files = new File[len];
	this->filesCnt = 0;
}

TextFilesManager::~TextFilesManager() {
	delete[] this->files;
}

size_t TextFilesManager::getFilesCnt() const {
	return this->filesCnt;
}

File& TextFilesManager::getFileByIndex(size_t index){
	return this->files[index];
}

bool TextFilesManager::addFile(const char* name, size_t h, size_t m, size_t s, size_t d, size_t mn, size_t y, const char* perms) {
	
	if (getFilesCnt() + 1 == this->total) {
		cout << "You cant add anymore files!";
		printNewline();
		return false;
	}

	if (indexOfFile(name) != -1) {
		cout << "File already exists!";
		printNewline();
		return false;
	}

	File file{};
	strcopy(file.name, name);
	strcopy(file.perms, perms);
	file.size = 0;
	file.createdTime = createDate(h, m, s, d, mn, y);

	this->files[getFilesCnt()] = file;
	this->filesCnt++;
	return true;
}

bool TextFilesManager::editFile(const char* name, const char* content, size_t h, size_t m, size_t s, size_t d, size_t mn, size_t y, const char role) {
	int index = indexOfFile(name);
	if (index == -1) {
		cout << "File doenst exists!";
		printNewline();
		return false;
	}
	File& file = getFileByIndex(index);
	if (!canRoleAcsessWriteFile(file, role)) {
		cout << "Error! You do not have the rights to edit!";
		printNewline();
		return false;
	}
	file.mtime = createDate(h, m, s, d, mn, y);
	strcopy(file.content, content);
	file.size = strLength(content);

	printEditFile(file);
	return true;
}

int TextFilesManager::indexOfFile(const char* name) {
	
	for (int i = 0; i < getFilesCnt(); i++) {
		if (strCmp(getFileByIndex(i).name, name)) {
			return i;
		}
	}

	return -1;
}

bool TextFilesManager::addInFile(const char* name, const char* content, size_t h, size_t m, size_t s, size_t d, size_t mn, size_t y, const char role) {
	int index = indexOfFile(name);
	if (index == -1) {
		cout << "File doenst exists!";
		printNewline();
		return false;
	}
	File& file = getFileByIndex(index);
	file.mtime = createDate(h, m, s, d, mn, y);
	
	if (!appendToContent(file, content)) {
		cout << "Error! Excided file limit!";
		printNewline();
		return false;
	}

	printEditFile(file);
	return true;
}

bool TextFilesManager::deleteFile(const char* name) {
	int index = indexOfFile(name);
	if (index == -1) {
		cout << "File doenst exists!";
		printNewline();
		return false;
	}

	File& file = getFileByIndex(index);
	file = getFileByIndex(this->filesCnt - 1);
	this->filesCnt--;
	return true;
}

bool TextFilesManager::changeRights(const char* name, const char role, const char roleType) {
	int index = indexOfFile(name);
	if (index == -1) {
		cout << "File doenst exists!";
		printNewline();
		return false;
	}

	File& file = getFileByIndex(index);
	if (!changeRoleFile(file, role, roleType)) {
		cout << "Incorrect right input!";
		printNewline();
		return false;
	}

	printFilePerms(file);
	printNewline();
	return true;
}

void TextFilesManager::printFile(const char* name, const char role) {
	int index = indexOfFile(name);
	if (index == -1) {
		cout << "File doenst exists!";
		printNewline();
		return;
	}

	File& file = getFileByIndex(index);
	if (!canRoleAcsessReadFile(file, role)) {
		cout << "Error! You do not have the rights to reàd!";
		printNewline();
		return;
	}

	printFileContent(file);
	printNewline();
}

void TextFilesManager::printFileInfo(const char* name) {
	int index = indexOfFile(name);
	if (index == -1) {
		cout << "File doenst exists!";
		printNewline();
		return;
	}

	File& file = getFileByIndex(index);
	printFileInfoAll(file);
	printNewline();
}

void TextFilesManager::print() {
	for (size_t i = 0; i < this->filesCnt; i++) {
		printFileName(getFileByIndex(i));
		printNewline();
	}
}

void TextFilesManager::sort(const SortOptions& option) {
	quicksort(0, getFilesCnt() - 1, option);
}

void TextFilesManager::quicksort(int left, int right, int option) {
	if (left >= right) {
		return;
	}

	int pivotIndex = partition(left, right, option);
	quicksort(left, pivotIndex - 1, option);
	quicksort(pivotIndex + 1, right, option);
}

int TextFilesManager::partition(int left, int right, int option) {
	int pivotIndex = (left + right) / 2;
	File pivotValue = getFileByIndex(pivotIndex);

	swappy(pivotIndex, right);

	int storeIndex = left;

	for (int i = left; i < right; i++) {
		if (option == 0) {
			if (compareFilesByName(getFileByIndex(i), pivotValue)) {
				swappy(i, storeIndex);
				storeIndex++;
			}
		}
		else if (option == 1) {
			if (compareFilesBySize(getFileByIndex(i), pivotValue)) {
				swappy(i, storeIndex);
				storeIndex++;
			}
		}
		else if (option == 2) {
			if (compareFilesByCreatedTime(getFileByIndex(i), pivotValue)) {
				swappy(i, storeIndex);
				storeIndex++;
			}
		}else if (option == 3) {
			if (compareFilesByMtime(getFileByIndex(i), pivotValue)) {
				swappy(i, storeIndex);
				storeIndex++;
			}
		}
	}

	swappy(storeIndex, right);
	return storeIndex;
}

void TextFilesManager::swappy(int a, int b) {
	File pivotValue = this->files[a];
	this->files[a] = this->files[b];
	this->files[b] = pivotValue;
}

bool TextFilesManager::compareFilesByName(const File& a, const File& b) {
	return compareStrings(a.name, b.name);
}

bool TextFilesManager::compareFilesBySize(const File& a, const File& b) {
	return a.size < b.size;
}

bool TextFilesManager::compareFilesByCreatedTime(const File& a, const File& b) {
	return dateCmp(a.createdTime, b.createdTime);
}

bool TextFilesManager::compareFilesByMtime(const File& a, const File& b) {
	return dateCmp(a.mtime, b.mtime);
}