#include "StringView.h"

StringView::StringView(const char* begin, int offset) {
    _begin = begin;
    _offset = offset;
}

StringView::StringView(const char* data) {
    _offset = strlen(data);
    _begin = data;
}

StringView::StringView(const MyString& str) {
    _offset = str.length();
    _begin = str.c_str();
}

StringView StringView::substr(unsigned pos, int count) const {
    return StringView(_begin + pos, count);
}

unsigned StringView::size() const {
    return _offset / sizeof(char);
}

char StringView::operator[](unsigned index) const {
    return *(_begin + index);
}

std::ostream& operator<<(std::ostream& os, const StringView& sv) {
    return os.write((const char*)sv._begin, sv._offset);
}


