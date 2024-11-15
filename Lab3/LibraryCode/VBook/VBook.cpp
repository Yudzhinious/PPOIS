#include "VBook.h"
Book::Book(int pages, std::string name, std::string author) {
    this->pages = pages;
    this->name = name;
    this->author = author;
}
std::string Book::GetFirstHalfTitle() const {
    int halfPages = pages / 2;
    return name + " (перва€ половина, " + std::to_string(halfPages) + " страниц)";
}
void Book::SetPages(int newPageCount) {
    if (newPageCount > 0) {
        pages = newPageCount;
        std::cout << " оличество страниц книги изменено на: " << pages << std::endl;
    }
    else {
        std::cout << "ќшибка: количество страниц должно быть положительным числом." << std::endl;
    }
}
void Book::ShowInfo() {
    std::cout << " нига " << name << " автора " << author << " содержит в себе " << pages << " страниц." << std::endl;
}