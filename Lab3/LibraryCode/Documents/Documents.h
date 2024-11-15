#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include "VBook.h"

class Documents : public Book {
protected:
    int age;
public:
    Documents(int pages, std::string name, std::string author, int age);
    void IncreaseAge(Documents& doc, int years);
    void ChangeAuthor(Documents& doc, const std::string& newAuthor);
    virtual void ShowInfo() override;
};