#pragma once
#include <iostream>
#include <string>
#include "Owner.h"

class Material : public Owner {
protected:
    std::string type;
    int amount;
public:
    Material(int exp, std::string name, std::string type, int amount);
    virtual void ShowInfo() const override;
};
