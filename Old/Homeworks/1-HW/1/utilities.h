#pragma once
#include "Date.h"
#include <iostream>
#include "File.h"
#include "constants.h"
#include "stringHelper.h"

using namespace std;

void printNewline();

Date createDate(size_t, size_t, size_t, size_t, size_t, size_t);

bool canRoleAcsessWriteFile(const File&, const char);
bool canRoleAcsessReadFile(const File&, const char);

bool appendToContent(File&, const char*);

bool changeRoleFile(File&, const char, const char);

void printFileSize(File&);
void printFileCreatedTime(File&);
void printFileModifiedTime(File&);
void printFileName(File&);
void printFileContent(File&);
void printFilePerms(File&);

void printEditFile(File&);

void printDatå(Date&);
void zeroPad(size_t);

void printFileInfoAll(File&);

int dateCmp(const Date&, const Date&);