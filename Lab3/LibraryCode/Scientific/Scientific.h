#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include "VBook.h"

class Scientific : public Book {
protected:
    int quality;
    int price;
public:
    Scientific(int pages, std::string name, std::string author, int quality, int price);
    virtual void ShowInfo() override;
    double EvaluateScientificValue() const;
    void UpdateEdition(int qualityIncrease, int priceIncrease);
    double PriceBasedOnRating(double rating) const;
};