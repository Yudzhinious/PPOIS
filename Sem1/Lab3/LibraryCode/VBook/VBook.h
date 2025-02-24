#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>

class Book {
protected:
    int pages;
    std::string name;
    std::string author;
public:
    Book(int pages, std::string name, std::string author);
    std::string GetFirstHalfTitle() const;
    void SetPages(int newPageCount);
    virtual void ShowInfo();
};
