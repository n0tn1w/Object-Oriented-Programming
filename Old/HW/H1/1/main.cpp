#include <iostream>
#include "TextFilesManager.h"

int main()
{

	TextFilesManager fs(5);
	fs.addFile("test15.txt", 14, 0, 0, 20, 3, 2023, "rwxr--r--");
	fs.addFile("test.txt", 14, 0, 2, 20, 3, 2023, "rwxr--r--");
	fs.addFile("test34.txt", 14, 0, 3, 20, 3, 2023, "rwxr--r--");
	fs.editFile("test34.txt", "foiawjgiofwa", 14, 0, 3, 20, 3, 2023, 'u');

	fs.editFile("test.txt", "Hello, world!", 14, 10, 0, 20, 3, 2023, 'u'); // Hello world!
	// Last modified on: 14:10:00 20.03.2023

	fs.editFile("test.txt", "Hello, world!", 14, 11, 0, 20, 3, 2023, 'o'); // Error! You do not have the rights to edit!

	fs.addInFile("test.txt", "Hello, my friend!", 14, 13, 0, 20, 3, 2023, 'u');	// Hello world! 
	// Hello, my friend!
									// Last modified on: 14:13:00 20.03.2023

	fs.editFile("test.txt", "Hello", 14, 15, 0, 20, 3, 2023, 'u'); 	// Hello

	fs.addFile("attest.txt", 14, 30, 0, 20, 3, 2023, "rwxr--r--");
	fs.deleteFile("test.txt");
	
	fs.deleteFile("test34.txt");


	fs.addFile("attest.txt", 14, 35, 0, 20, 3, 2027, "rwxr--r--");

	fs.changeRights("attest.txt", 'u', 'w'); 		//r-xr—r—

	fs.changeRights("attest.txt", 'u', 'w'); 		//rwxr—r—

	fs.changeRights("attest.txt", 'u', 'r'); 		//-wxr—r—
	fs.printFile("attest.txt", 'u'); 		// Error! You do not have the rights to read!

	fs.printFile("test.txt", 'o'); 		// Hello


	fs.printFile("attest.txt", 'o');		//

	fs.printFileInfo("test.txt");
	// Name: test.txt
	// Size:  5
	// Created on: 14:00:00 20.03.2023
	// Last modified on: 14:15:00 20.03.2023
	// Rights: rwxr—r—
	fs.sort(SortOptions::name);
	fs.print();
	//attest.txt
	//test.txt

	fs.sort(SortOptions::modificationTime);
	fs.print();
		//test.txt
		//attest.txt

	fs.sort(SortOptions::size);
	fs.print();
}

