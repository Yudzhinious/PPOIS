#pragma once
#include <iostream>
#include <string>
#include "Fabricator.h"

class TransportRental : public Fabricator {
protected:
    std::string naming;
    int amount;
public:
    TransportRental(int experience, int time, std::string name, std::string naming, int amount);
    virtual void ShowHelp_1() const override;
    void Experience() const;
};
