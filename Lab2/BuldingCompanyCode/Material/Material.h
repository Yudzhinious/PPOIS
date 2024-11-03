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
    void AddAmount(int quantity);
    void ReduceAmount(int quantity);
    std::string GetType() const;
    void SetType(const std::string& newType);
    int GetAmount() const;
    bool HasMoreThan(const Material& other) const;
    bool IsSameType(const Material& other) const;
    virtual void ShowInfo() const override;
};
