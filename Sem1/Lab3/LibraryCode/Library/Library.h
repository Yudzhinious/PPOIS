#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Owner.h"
#include "Storage.h"
#include "Shop.h"

class Library {
protected:
    int year;
    int capacity;
    double address;
    std::string name;
    std::string street;
    std::vector<Owner> owners;
    std::vector<Storage> storages;
    std::vector<Shop> markets;
public:
    Library(int year, int capacity , double address, std::string street, std::string name);
    void ShowLibrary();
    void ExpandCapacity(int additionalCapacity);
    bool CanAccommodate(int numberOfBooks) const;
    void AddOwner(Owner& owner);
    void AddStorage(Storage& storage);
    void AddShop(Shop& market);
    std::pair<int, int> GetAgeAndCapacity() const;
    std::vector<Owner> getOwner();
    std::vector<Storage> getStorage();
    std::vector<Shop> getShop();
};