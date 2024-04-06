// 4. Реализирайте конструктор с параметри, мутатори (сетъри) и селектори (гетъри) за следния клас:

#include <cstring>

class Book {
    double price;
    unsigned pageCount;
    char name[128];
public:
    Book() = default;
    Book(double, unsigned, const char*);

    double getPrice() const;
    unsigned getPageCount() const;
    const char* getName() const;

    void setPrice(double);
    void setPageCount(unsigned);
    void setName(const char*);
};

Book::Book(double price, unsigned pageCount, const char* name) {
    setPrice(price);
    setPageCount(pageCount);
    setName(name);
}

const char* Book::getName() const {
    return name;
}

// Other getters are the same

void Book::setName(const char* _name) {
    //validations
    strcpy(name, _name);
}

// Other setters are the same