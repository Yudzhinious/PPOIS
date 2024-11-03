#pragma once
#include <iostream>
#include <string>

class Fabricator {
protected:
    int experience;
    int time;
    std::string name;
public:
    Fabricator(int experience, int time, std::string name);
    virtual void ShowHelp_1() const;
    virtual void ShowHelp_2() const;
};