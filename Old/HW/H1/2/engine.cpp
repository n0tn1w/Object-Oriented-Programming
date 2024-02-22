#include "engine.h"

void mainMenu(TableContainer &tableContainer) {
	
	while (true) {
		printInputCharacter();
		char** cmds = new char* [INPUT_BUFFER_SIZE];
		size_t cmdCnt = readCommand(cmds);

		if (cmdCnt > 0) {

			if (cmdCnt == 3 && strCmp(cmds[0], CHANGE_CMD)) {
				Field from, to;
				strcopy(from.value, cmds[1]);
				strcopy(to.value, cmds[2]);

				if (!tableContainer.changeColumnName(from, to)) {
					cout << "Invalid column name!";
					printNewline();
				}
			} else if (strCmp(cmds[0], CHANGE_ROW_CMD)) {

				Field colName, value;
				if(!checkIfInt(cmds[1])) {
					cout << "Invalid function";
					printNewline();
					freeCommands(cmds, cmdCnt);
					continue;
				}

				int row = convertToInt(cmds[1]);
				strcopy(colName.value, cmds[2]);
				strcopy(value.value, cmds[3]);

				if(!tableContainer.changeRow(row, colName, value)) {
					cout << "Invalid row number";
					printNewline();
					freeCommands(cmds, cmdCnt);
					continue;
				}
			} else if (strCmp(cmds[0], ADD_ROW_CMD)) {
				size_t tableColNumber = tableContainer.getColNumber();
				if(tableColNumber != (cmdCnt - 1) || cmdCnt == 1) {
					cout << "Invalid number of params!";
					printNewline();
					freeCommands(cmds, cmdCnt);
					continue;
				}

				if(!tableContainer.addRow(convertCmdIntoFields(cmds, cmdCnt), cmdCnt - 1)) {
					cout << "Invalid operation!";
					printNewline();
					freeCommands(cmds, cmdCnt);
					continue;
				}
			} else if (cmdCnt == 4 && strCmp(cmds[0], CHANGE_CMD)) {

				Field colName, from, to;
				strcopy(colName.value, cmds[1]);
				strcopy(from.value, cmds[2]);
				strcopy(to.value, cmds[3]);

				if (!tableContainer.changeOneRow(colName, from, to)) {
					cout << "No such field exists!";
					printNewline();
				}
			} else if (cmdCnt == 1 && strCmp(cmds[0], PRINT_CMD)) {
				tableContainer.print();
			} else if (cmdCnt == 3 && strCmp(cmds[0], SELECT_WHERE_CMD)) {
				Field columnName, fieldName;
				strcopy(columnName.value, cmds[1]);
				strcopy(fieldName.value, cmds[2]);

				if (!tableContainer.selectWhere(columnName, fieldName)) {
					cout << "Invalid field/s!";
					printNewline();
				}
			}
			else if (cmdCnt = 2 && strCmp(cmds[0], SAVE_CMD)) {
				if (!saveFile(cmds[1], tableContainer)) {
					cout << "File failed to save!";
					printNewline();
				}
				else {
					cout << "File successfully saved!";
					printNewline();
					freeCommands(cmds, cmdCnt);
					return;
				}
			}
			else {
				cout << "Wrong cmd!";
				printNewline();
			}
		}
		else {
			return;
		}

		freeCommands(cmds, cmdCnt);
	}
}

void run() {

	TableContainer tableContainer;
	char fileName[FILE_NAME_SIZE];
	
	printInputCharacter();
	cin.getline(fileName, FILE_NAME_SIZE);

	if (readFile(fileName, tableContainer)) {
		cout << "File loaded!";
		printNewline();
	}
	else {
		cout << "Failed to load the file!";
		printNewline();
		return;
	}

	mainMenu(tableContainer);
}