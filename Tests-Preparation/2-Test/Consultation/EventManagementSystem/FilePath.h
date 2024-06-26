#pragma once

class FilePath {

public:

    FilePath() = delete;
    FilePath(const char*);
    FilePath(const FilePath&);
    FilePath(FilePath&&);
    FilePath& operator=(const FilePath&);
    FilePath& operator=(FilePath&&);
    ~FilePath();

private:

    void copyFrom(const FilePath&);
    void moveFrom(FilePath&&);
    void free();

    char* _name = nullptr;

};