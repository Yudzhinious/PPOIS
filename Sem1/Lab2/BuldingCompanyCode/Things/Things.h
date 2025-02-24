#pragma once
#include <iostream>
#include <string>
#include "Fabricator.h"

class Things : public Fabricator {
protected:
    std::string naming;
    int amount;
public:
    Things(int experience, int time, std::string name, std::string naming, int amount);
    virtual void ShowHelp_2() const override;
    void Valid();
};
