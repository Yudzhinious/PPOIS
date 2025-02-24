#pragma once
#include <string>
#include <iostream>

class Owner {
protected:
    int experience;
    std::string name;
public:
    Owner(int exp, std::string name);
    virtual void ShowInfo() const;
    virtual void ShowInfo2() const;
    void Order();
};