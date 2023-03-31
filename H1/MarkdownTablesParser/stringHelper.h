#pragma once

int indexOfFirstChar(const char* row, int from);

int indexOfLastChar(const char* row, int from);

bool isCurrCharFromWord(const char& c);

int strLength(const char* str);

char* subStr(const char* str, int from, int to);

void strcopy(char* destination, const char* source);

bool strCmp(const char* left, const char* rigth);

int convertToInt(const char* str);

bool checkIfInt(const char* str);
