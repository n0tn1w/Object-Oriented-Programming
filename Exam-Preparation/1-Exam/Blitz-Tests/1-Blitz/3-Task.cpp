// 3. В двоичен файл трябва да се запише масив от цели числа с размер 5.

#include <fstream>

int main() {
	std::ofstream file("myFile.dat", std::ios::out | std::ios::binary);
	if (!file.is_open()) {
		return -1;
	}
	int arr[5] = { 1, 2, 3, 4, 5 };

    file.write((const char*)arr, sizeof(arr));  
    file.write((const char*)arr, 5*sizeof(int));
}

//Отбележете всички правилни начини, по които да се запише arr във file.

// a) file.write((const char*)arr, sizeof(arr));
// b) file.write((char*)arr, sizeof(arr));
// c) file.write((const char*)arr, 5*sizeof(int));
// d) file.write((char*)arr, 5*sizeof(int));
// e) нито един от изброените варианти не е верен

// You could write into the file with any of the following lines.;
// But the best practices are to make them const char* imo