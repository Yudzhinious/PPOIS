#pragma once
#include <iostream>
#include <string>
#include "Owner.h"

class Client : public Owner {
protected:
    std::string surname;
    int cash;
public:
    Client(int exp, std::string name, std::string surname, int cash);
    virtual void ShowInfo() const override;
};
