#include <iostream>
#include "FileSystem.h" 
#include "Files.h"

int main() {
	FileSystem fs;
	fs.getFile("root")->printContent();
	fs.createTextFile("root/file.txt", "samplecontent");
	fs.createDir("root/d1/d2");
	fs.createTextFile("root/dir1/dir2/random", "randomcontent");
	fs.createTextFile("root/dir1/dir2/random2", "randomcontent");
	fs.createDir("root/dir1/dir2/dir3/dir4");
	fs.getFile("root/d1/d2")->printContent();
	fs.getFile("root")->printContent();

}