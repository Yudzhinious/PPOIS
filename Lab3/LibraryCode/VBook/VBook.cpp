#include "VBook.h"
Book::Book(int pages, std::string name, std::string author) {
    this->pages = pages;
    this->name = name;
    this->author = author;
}
std::string Book::GetFirstHalfTitle() const {
    int halfPages = pages / 2;
    return name + " (������ ��������, " + std::to_string(halfPages) + " �������)";
}
void Book::SetPages(int newPageCount) {
    if (newPageCount > 0) {
        pages = newPageCount;
        std::cout << "���������� ������� ����� �������� ��: " << pages << std::endl;
    }
    else {
        std::cout << "������: ���������� ������� ������ ���� ������������� ������." << std::endl;
    }
}
void Book::ShowInfo() {
    std::cout << "����� " << name << " ������ " << author << " �������� � ���� " << pages << " �������." << std::endl;
}