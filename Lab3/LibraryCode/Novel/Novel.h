#pragma once
#include <string>
#include <iostream>
#include <string>
#include "VBook.h"

class Novel : public Book {
protected:
    int quality;
    int price;
public:
    Novel(int pages, std::string name, std::string author, int quality, int price);
    virtual void ShowInfo() override;
    void IncreaseQuality(int increment);
    void ReducePrice(int decrement);
    double PricePerPage() const;
};