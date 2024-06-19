#include "StringView.h"

StringView::StringView(const char* str, size_t len) {
    _begin = str;
    _size = len;
}

StringView StringView::substr(size_t begin, size_t end) {
    if(end - begin < 0) {
        throw std::runtime_error("cak  cak");
    }

    return StringView(_begin + begin, end - begin + 1);
}

size_t StringView::GetSize() const {
    return _size;
}

char StringView::operator[](size_t idx) {
    return *(_begin + idx);
}