#include "utilities.h"

void printNewline() {
	cout << '\n';
}


Date createDate(size_t h, size_t m, size_t s, size_t d, size_t mn, size_t y) {
	Date date{};

	date.hours = h;
	date.min = m;
	date.sec = s;
	date.day = d;
	date.month = mn;
	date.year = y;

	return date;
}

bool canRoleAcsessWriteFile(const File& file, const char role) {
	int indexOfWrite = -1;
	//-w--w--w-
	if (role == 'u') {
		indexOfWrite = 1;
	}
	else if (role == 'g') {
		indexOfWrite = 4;
	}
	else if (role == 'o') {
		indexOfWrite = 7;
	}

	if (indexOfWrite == -1) {
		return false;
	}

	return file.perms[indexOfWrite] == 'w';
}

bool canRoleAcsessReadFile(const File& file, const char role) {
	int indexOfWrite = -1;
	//-w--w--w-
	if (role == 'u') {
		indexOfWrite = 0;
	}
	else if (role == 'g') {
		indexOfWrite = 3;
	}
	else if (role == 'o') {
		indexOfWrite = 6;
	}

	if (indexOfWrite == -1) {
		return false;
	}

	return file.perms[indexOfWrite] == 'r';
}


bool appendToContent(File& file, const char* str) {
	size_t len = strLength(str);

	if (file.size + len > CONTENT_LENGHT) {
		return false;
	}

	file.content[file.size] = '\n';
	for (int i = 0; i < len; i++) {
		file.content[file.size + i] = str[i];
	}
	file.content[file.size + len] = '\0';

	file.size += len;
	return true;
}

bool changeRoleFile(File& file, const char role, const char roleType) {
	int index = -1;
	//rwx-w-rwx
	if (role == 'u') {
		index = 0;
	}
	else if (role == 'g') {
		index = 3;
	}
	else if (role == 'o') {
		index = 6;
	}
	else {
		return false;
	}

	if (roleType == 'r') {
		index += 0;
	}
	else if (roleType == 'w') {
		index += 1;
	}
	else if (roleType == 'x') {
		index += 2;
	}
	else {
		return false;
	}

	file.perms[index] = (file.perms[index] == '-' ? roleType : '-');
	return true;
}

void printFileSize(File& file) {
	cout << file.size;
}
void printFileCreatedTime(File& file) {
	printDatå(file.createdTime);
}
void printFileModifiedTime(File& file) {
	printDatå(file.mtime);
}
void printFileName(File& file) {
	cout << file.name;
}
void printFileContent(File& file) {
	cout << file.content;
}
void printFilePerms(File& file) {
	/*for (size_t i = 0; i < strLength(file.perms); i++) {
		if (file.perms[i] == '-') {
			cout << '_';
		}
		else {
			cout << file.perms[i];
		}
	}*/
	cout << file.perms;
}

void printEditFile(File& file) {
	printFileContent(file);
	printNewline();
	cout << "Last modified on: ";
	printFileModifiedTime(file);
	printNewline();
}


void printDatå(Date& date) {
	zeroPad(date.hours);
	cout << ":";
	zeroPad(date.min);
	cout << ":";
	zeroPad(date.sec);
	cout << " ";
	zeroPad(date.day);
	cout << ".";
	zeroPad(date.month);
	cout << "." << date.year;
}

void zeroPad(size_t field) {
	if (field < 10) {
		cout << "0";
	}
	cout << field;
}

void printFileInfoAll(File& file) {
	cout << "Name: ";
	printFileName(file);
	printNewline();
	cout << "Size: ";
	printFileSize(file);
	printNewline();
	cout << "Created on: ";
	printFileCreatedTime(file);
	printNewline();
	cout << "Last modified on: ";
	printFileModifiedTime(file);
	printNewline();
	cout << "Rights: ";
	printFilePerms(file);
}

int dateCmp(const Date& a,const Date& b) {
	if (a.year != b.year) {
		return a.year < b.year;
	}
	else if (a.month != b.month) {
		return a.month < b.month;
	}
	else if (a.day != b.day) {
		return a.day < b.day;
	}
	else if (a.hours != b.hours) {
		return a.hours < b.hours;
	}
	else if (a.min != b.min) {
		return a.min < b.min;
	}
	else {
		return a.sec < b.sec;
	}
}