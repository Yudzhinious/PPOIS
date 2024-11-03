#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Owner.h"

class Storage : public Owner {
private:
    int amount;
    int percentage;
    std::string naming;
public:
    Storage(int exp, std::string name, int amount, int percentage, std::string naming);
    virtual void ShowInfo2() const override;
    void Occupancy();
};