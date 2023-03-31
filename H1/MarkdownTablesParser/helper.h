#pragma once
#include "TableContainer.h"

void printInputCharacter();
void printTableCharacter();
void printNewline();

bool readFile(const char* fileName, TableContainer& table);

size_t readCommand(char**);

void freeCommands(char**, size_t);

Field* convertCmdIntoFields(char**, const size_t&);

int getOrder(char*);