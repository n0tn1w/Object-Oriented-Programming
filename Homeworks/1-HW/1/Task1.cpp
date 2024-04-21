#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::stringstream;

#define tab '\t'
// Put every string in the code into Const namespace

// Constrains
namespace Const{
    const size_t MAX_ROWS_COUNT = 100;
    const size_t MAX_CELLS_COUNT = 15;
    const size_t MAX_CELL_LENGTH = 50;
    const size_t MAX_CELL_INPUT_LENGTH = MAX_CELL_LENGTH * 4;
    const size_t FILE_BUFFER_SIZE = 65000;
    const size_t BUFFER_SIZE = 1024;

    const size_t INPUT_FILE_NAME_SIZE = 50;
    const size_t INPUT_DATA_MAX_LENGTH = MAX_CELL_INPUT_LENGTH;

    const char* TABLE_COMMAND = "table";
    const char* TABLE_END_COMMAND = "/table";
    const char* TABLE_ROW_COMMAND = "tr";
    const char* TABLE_ROW_END_COMMAND = "/tr";
    const char* TABLE_HEADER_COMMAND = "th";
    const char* TABLE_HEADER_END_COMMAND = "/th";
    const char* TABLE_DATA_COMMAND = "td";
    const char* TABLE_DATA_END_COMMAND = "/td";
};

enum class ErrorCode {
    OK,
    CannotOpenFile,
    FileReadIsBroken,
    TableTagNotFound,
    TableEndTagNotFound,
    TableRowTagNotFound,
    TableHeaderEndTagNotFound,
    TableDataEndTagNotFound,
    IncorrectTag,
    InvalidRowIndex,
    InvalidColIndex,
    TableIsFull,
    AmountOfCellsInRowIsInvalid,
    AmountOfRowsInTableIsInvalid,
    InvalidRow
};

enum class Tags {
    Table,
    TableEnd,
    TableRow,
    TableRowEnd,
    TableHeader,
    TableHeaderEnd,
    TableData,
    TableDataEnd,
    IncorretTag
};

namespace Helper 
{
    size_t getFileSize(std::ifstream& ifs) {
        size_t curr = ifs.tellg();
        ifs.seekg(0, std::ios::end);
        size_t len = ifs.tellg();
        ifs.seekg(curr);

        return len;
    }


    Tags decodeBuffer(const char* command, size_t len) {
        if(strcmp(command, Const::TABLE_COMMAND) == 0) {
            return Tags::Table;
        } else if (strcmp(command, Const::TABLE_END_COMMAND) == 0) {
            return Tags::TableEnd;
        } else if (strcmp(command, Const::TABLE_ROW_COMMAND) == 0) {
            return Tags::TableRow;
        } else if (strcmp(command, Const::TABLE_ROW_END_COMMAND) == 0) {
            return Tags::TableRowEnd;
        } else if (strcmp(command, Const::TABLE_HEADER_COMMAND) == 0) {
            return Tags::TableHeader;
        } else if (strcmp(command, Const::TABLE_HEADER_END_COMMAND) == 0) {
            return Tags::TableHeaderEnd;
        } else if (strcmp(command, Const::TABLE_DATA_COMMAND) == 0) {
            return Tags::TableData;
        } else if (strcmp(command, Const::TABLE_DATA_END_COMMAND) == 0) {
            return Tags::TableDataEnd;
        } else {
            return Tags::IncorretTag;
        }
    }

    Tags getTagFromStringstream(stringstream& ss) {
        char buffer[Const::BUFFER_SIZE];
        ss.getline(buffer, Const::BUFFER_SIZE, '<');
        ss.getline(buffer, Const::BUFFER_SIZE, '>');
        size_t bufferLen = strlen(buffer);
        // Check which is the html tag table, tr, th, td
        return decodeBuffer(buffer, bufferLen);
    }
}

struct Cell {
    private: // We will make the internal field of all the classes private so that we have better encapsulation
    char data[Const::MAX_CELL_LENGTH];
    bool isHeader = false; // true if the cell is th and false if the cell is td

    // There is no need to check validity of a cell because it is valid always
    // ErrorCode isValid = ErrorCode::OK;//Validity check of a cell it is not valid it will just be empty

    public:
    // ErrorCode good() const {
    //     return this->isValid;
    // }

    Cell() = default;

    bool isEmpty() const {
        return strlen(this->data) == 0;
    }

    void parse(stringstream& ss) {
        char buffer[Const::MAX_CELL_INPUT_LENGTH];
        ss.getline(buffer, Const::BUFFER_SIZE, '<');
        // getline read the '<' and removes it from the ss
        // When the getTagFromStringstream() comes it skips this closing tag and the line
        // If you dont understand remove the putback and see how it will skip every second closing tag
        ss.putback('<'); 
        setData(buffer);
        
    }

    void print() const {
        if(getIsHeder())
            cout << "*";
        cout << data;
        if(getIsHeder())
            cout << "*";
    }

    bool getIsHeder() const {
        return this->isHeader;
    }

    void setIsHeader(bool isHeader) {
        this->isHeader = isHeader;
    } 

    //setter for data with validation
    void setData(const char* newData) {
        // Not opitaml for edit!
        size_t len = strlen(newData);
        if(len > Const::MAX_CELL_INPUT_LENGTH)
            return;
        
        stringstream ss(newData);
        size_t index = 0;
        // Here could be done in a different way so that 
        // if seter wont work if the filtered data is above 50 chars but whatever
        while(!ss.eof() && index < Const::MAX_CELL_LENGTH) {
            char f = ss.get(); // The current element
            if(ss.eof()) {
                // The endOfFile bit is triggered after the get so we need this
                return;
            }

            if(f == '&') {
                char s = ss.get();
                if(s == '#') {
                    int converted = 0;
                    ss >> converted;
                    f = (char) converted;
                }
            }
            // We have to save them one by one so when the &# appers we will not save it 
            this->data[index++] = f;
        }
        //strcpy(this->data, data);
    }

    void save(stringstream& ss) const {
        // There is not good reasons this method to return ErrorCode.
        if(isHeader) {
            ss << tab << tab << "<th>";
        } else {
            ss << tab << tab << "<td>";
        }
        ss << data;
        if(isHeader) {
            ss << "</th>" << endl;
        } else {
            ss << "</td>" << endl;
        }
    } 
};

struct Row {
    private:
    Cell cells[Const::MAX_CELLS_COUNT];
    size_t cellsCount = 0;
    ErrorCode isValid = ErrorCode::OK;

    public:
    bool good() const {
        return this->isValid == ErrorCode::OK;
    }
    ErrorCode getError() const {
        return this->isValid;
    }

    Row() = default; // For creating array with it.

    void fill(size_t addedCellsCount, char data[][Const::MAX_CELL_INPUT_LENGTH]) {
        if(!good())
            return;
        setCellsCount(addedCellsCount);
        for(size_t i = 0; i < getCellsCount(); i++) {
            cells[i].setData(data[i]);
        }
    }

    size_t getCellsCount() const {
        if(!good())
            return 0;

        return this->cellsCount;
    }

    void setCellsCount(size_t cellsCount) {
        if(!good())
            return;

        if(cellsCount > Const::MAX_CELLS_COUNT) {
            this->isValid = ErrorCode::AmountOfCellsInRowIsInvalid;
            return;
        }

        this->cellsCount = cellsCount;
    }

    void increaseCellsCount() {
        setCellsCount(getCellsCount() + 1);
    }

    void parse(stringstream& ss) {
        if(!good())
            return;

        while(true) {
            Tags headerOrDataTag = Helper::getTagFromStringstream(ss);

            if(headerOrDataTag == Tags::TableHeader) {
                cells[getCellsCount()].parse(ss);
                cells[getCellsCount()].setIsHeader(true);
                increaseCellsCount();

                Tags closingHeaderTag = Helper::getTagFromStringstream(ss);
                if(closingHeaderTag == Tags::TableHeaderEnd) {
                    // Happy path.
                } else {
                    // invalid data no closing table header tag
                    this->isValid = ErrorCode::TableHeaderEndTagNotFound;
                }

            } else if(headerOrDataTag == Tags::TableData) {
                cells[getCellsCount()].parse(ss);
                cells[getCellsCount()].setIsHeader(false);
                increaseCellsCount();

                Tags closingDataTag = Helper::getTagFromStringstream(ss);
                if(closingDataTag == Tags::TableDataEnd) {
                    // Happy path.
                } else {
                    // invalid data no closing table data tag
                    this->isValid = ErrorCode::TableDataEndTagNotFound;
                }
            } else if(headerOrDataTag == Tags::TableRowEnd) {
                break;
            } else {
                this->isValid = ErrorCode::IncorrectTag;
            }
        }
    }

    void print(size_t longestRow) const {
        if(!good())
            return;

        for(size_t i = 0; i < getCellsCount(); i++) {
            if(i != 0)
                cout << "|";

            // If the cell is empty put " - "
            if(cells[i].isEmpty()) {
                cout << " - ";
            } else {
                cells[i].print();
            }
        }

        for(size_t k = getCellsCount(); k < longestRow; k++) {
            cout << "|";
            cout << " - ";
        }
    }

    void edit(size_t col, const char* data) {
        if(!good())
            return;

        // Cells start from 1
        col -= 1;

        if(col < 0 || col >= getCellsCount()) {
            isValid = ErrorCode::InvalidColIndex;
            return;
        }

        
        
        cells[col].setData(data);
        return;
    }

    void save(stringstream& ss) const {
        if(!good())
            return;

        ss << tab << "<tr>" << endl;
        for(size_t i = 0; i < getCellsCount(); i++) {
            cells[i].save(ss);
        }
        ss << tab << "</tr>" << endl;
    }
};

struct Table {
    private:
    Row rows[Const::MAX_ROWS_COUNT];
    size_t rowsCount = 0;
    size_t longestRow = 0; // Will make table full 

    ErrorCode isValid = ErrorCode::OK;
    public:
    ErrorCode getError() const {
        return this->isValid;
    }

    bool good() const {
        return this->isValid == ErrorCode::OK;
    }

    void parse(const char* fileName) {
        if(!good())
            return;

        std::ifstream ifs(fileName, std::ios::in);
        if (!ifs.is_open()) {
            isValid = ErrorCode::CannotOpenFile;
            return;
        }

        parse(ifs);
        ifs.close();
    }

    void parse(std::ifstream& ifs) {
        if(!good())
            return;
        
          char fileBuffer[Const::FILE_BUFFER_SIZE];
    
        size_t fileSize = Helper::getFileSize(ifs) + 1;
        ifs.read(fileBuffer, fileSize);

        if (!ifs.eof()) {
            ifs.close();
            isValid = ErrorCode::FileReadIsBroken;
            return;
        }

        // We close the stream from the file. 
        // From now on we will be working with the file data using stringstream.
        stringstream ss(fileBuffer);
        parse(ss);
    }

    // This could be a contr but i choose a function so that it there could a better error handling
    void parse(stringstream& ss) {
        if(!good())
            return;

        Tags tableTag = Helper::getTagFromStringstream(ss);
        if(tableTag != Tags::Table) {
            isValid = ErrorCode::TableTagNotFound;
            return;
        }

        while(true) {
            Tags rowTag = Helper::getTagFromStringstream(ss);

            if(rowTag == Tags::TableRow) {
                rows[getRowsCount()].parse(ss);

                // ErrorCode rowParse = rows[getRowsCount()].good();
                if(!rows[getRowsCount()].good()) {
                    //isValid = rowParse;
                    isValid = rows[getRowsCount()].getError();
                    return;
                }
                setLongestRow(rows[getRowsCount()].getCellsCount());
                increaseRowsCount();
            } else if(rowTag == Tags::TableEnd) {
                // Happy path. We found the end tag </table> we can stop reading.
                break;
            } else {
                isValid = ErrorCode::IncorrectTag;
                return;
            }

            if(ss.eof()) {
                // We didnt found </table> tag. It doesnt exist.
                isValid = ErrorCode::TableEndTagNotFound;
                return;
            }
        }
    }

    size_t getLongestRow() const {
        if(!good())
            return 0;

        return this->longestRow;
    }

    void setLongestRow(size_t cellsCount) {
        if(!good())
            return;
        if(cellsCount > this->longestRow)
            this->longestRow = cellsCount;
    }

    void setRowsCount(size_t rowsCount) {
        if(!good())
            return;

        if(rowsCount > Const::MAX_ROWS_COUNT) {
            this->isValid = ErrorCode::AmountOfRowsInTableIsInvalid;
            return;
        }

        this->rowsCount = rowsCount;
    }

    void increaseRowsCount() {
        setRowsCount(getRowsCount() + 1);
    }

    size_t getRowsCount() const {
        if(!good())
            return 0;

        return this->rowsCount;
    }

    void print() const {
        if(!good())
            return;

        for(size_t i = 0; i < rowsCount; i++) {
            if(i != 0)
                cout << endl;
            rows[i].print(getLongestRow());
        }
        cout << endl;
    }

    // Will need accept how many column you need to add + the data in them
    // Will be added on the last element
    void add(size_t addedCellsCount, char data[][Const::MAX_CELL_INPUT_LENGTH]) {
        if(!good())
            return;

        if(rowsCount >= 30) {
            isValid = ErrorCode::TableIsFull;
            return;
        }

        rows[rowsCount].fill(addedCellsCount, data);
        setLongestRow(rows[getRowsCount()].getCellsCount());

        increaseRowsCount();
    }

    void edit(int rowIndex, int col, const char* data) {
        if(!good())
            return;

        // Rows start from 1
        rowIndex -= 1;

        if(rowIndex < 0 || rowIndex >= rowsCount) {
            isValid = ErrorCode::InvalidRowIndex;
            return;
        }
        
        rows[rowIndex].edit(col, data);
    }

    void remove(int rowIndex) {
        if(!good())
            return;
        rowIndex -= 1;

        if(rowIndex < 0 || rowIndex >= rowsCount) {
            isValid = ErrorCode::InvalidRowIndex;
            return;
        }

        // We should reevaluate the longestRow in here
        
        rows[rowIndex] = rows[--rowsCount];
    }

    void save(const char* filename) {
        if(!good())
            return;

        // We will buil a stringstream with the needed information and in the end will open the file once to save it
        stringstream ss;

        ss << "<table>" << endl;
        for(size_t i = 0; i < rowsCount; i++) {
            rows[i].save(ss);
        }
        ss << "</table>" << endl;

        // This could be in a different funtion named save stringstream into a filename 
        std::ofstream ofs(filename, std::ios::out);
        if (!ofs.is_open()) {
            isValid = ErrorCode::CannotOpenFile;
            return;
        }

        ofs << ss.str();
        ofs.close();
    }
};

int main() {
    char fileName[Const::BUFFER_SIZE];
    cout << "Enter file name: " << endl;
    cout << '>';
    cin >> fileName;

    Table table;
    table.parse(fileName);

    if(!table.good()) {
        std::cerr << "Failed in reading the file!" << endl;
        return 0;
    }

    char command;
    bool shoudStop = false;
    while(!shoudStop) {
        cout << "a - add, p - print, e - edit, r - remove, s - save, q - quit" << endl;
        cout << "Enter command: " << endl;
        cout << '>';
        cin >> command;

        switch (command)
        {
            case 'a':
            {
                size_t colCount;
                cout << '>';
                cin >> colCount;

                char data[colCount][Const::INPUT_DATA_MAX_LENGTH];
                for(size_t i = 0; i < colCount; i++) {
                    cout << '>';
                    cin >> data[i];
                }

                table.add(colCount, data);
                if(!table.good()) {
                    // You can letter go and check all the errors.
                    cout << "Added failed with error: " << static_cast<int> (table.getError()) << endl;
                } else {
                    cout << "Successfully added!" << endl;
                }   

                break;
            }
            case 'p':
            {
                cout << "<=============================>" << endl;
                table.print();
                break;    
            }
            case 'e':
            {
                int rowIndex, colIndex;
                char data[Const::INPUT_DATA_MAX_LENGTH];
                cout << "Enter row, col and data: " << endl;
                cout << '>';
                cin >> rowIndex;
                cout << '>';
                cin >> colIndex;
                cout << '>';
                cin >> data;

                table.edit(rowIndex, colIndex, data);
                if(!table.good()) {
                    // You can letter go and check all the errors.
                    cout << "Edit failed with error: " << static_cast<int> (table.getError()) << endl;
                } else {
                    cout << "Successfully edited!" << endl;
                }   

                break; 
            } 
            case 'r':
            {
            // Remove row
                int inputRow;
                cout << "Enter row:" << endl;
                cout << '>';
                cin >> inputRow;
                table.remove(inputRow);
                if(!table.good()) {
                    // You can letter go and check all the errors.
                    cout << "Remove failed with error: " << static_cast<int> (table.getError()) << endl;
                } else {
                    cout << "Successfully removed!" << endl;
                }            
                break;  
            }
            case 's':
            {
            // Save into file
                char fileToSave[Const::INPUT_FILE_NAME_SIZE];
                cout << "Enter file name to save to: ";
                cout << endl << '>';
                cin >> fileToSave;

                table.save(fileToSave);
                break;  
            }
            case 'q':
            {
            // Quit
                shoudStop = true;
                table.save(fileName);
                break; 
            }
            default:
            {
                cout << "Incorrect command!" << endl;
                break; 
            }
        }
    }
    return 0;
}