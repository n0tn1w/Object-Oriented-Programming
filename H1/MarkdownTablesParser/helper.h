#pragma once
#include "constants.h"
#include "stringHelper.h"
#include "Field.h"

#include <iostream>
#include <fstream>

using namespace std;

void printInputCharacter();
void printTableCharacter();
void printNewline();

size_t readCommand(char**);
void freeCommands(char**, size_t);

size_t extractColumnData(const char*, char**);
Field* convertCmdIntoFields(char**, const size_t&);

int getOrder(char*);

void printOrderFile(ofstream&, size_t, int);
void printOrder(size_t, int);