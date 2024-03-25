#include <iostream>
#include <sstream>

using namespace std;

int main() {
    std::stringstream ss1("&#97b3aa"); //ab3aa
    char data[10];

    ss1.ignore();
    ss1.ignore();
    int z = 0;
    ss1 >> z;
    char c  = (char) z;

//     data = ss1.read(char)
// //    cout << c;
//     ss1 << c;
    

    cout << ss1.str();

    std::stringstream ss;
    ss << "This is a test string.";

    // Get the current position in the stringstream
    std::streampos startPos = ss.tellp();

    // Move to the 4th index
    ss.seekp(4, std::ios_base::beg);

    // Move to the 11th index
    ss.seekp(7, std::ios_base::cur); // 7 = 11 (target index) - 4 (current index)

    // Get the position after the 11th index
    std::streampos endPos = ss.tellp();

    // Reset the stringstream
    ss.str("");

    // Rewind the stringstream to the start position
    ss.seekp(startPos);

    // Read and discard characters until the end position
    char s;
    while (ss.tellp() < endPos && ss.get(s)) {
        // Discard characters
    }

    std::cout << "Stream contents after removing data: " << ss.str() << std::endl;

    return 0;
}