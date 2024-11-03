#pragma once
#include <iostream>
#include <string>
#include "Owner.h"

class Budget : public Owner {
protected:
    std::string source;
    int cash;
public:
    Budget(int exp, std::string name, std::string source, int cash);
    virtual void ShowInfo() const override;

};
