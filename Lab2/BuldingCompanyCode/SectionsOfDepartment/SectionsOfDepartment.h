#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Storage.h"

class SectionsOfDepartment {
private:
    int number;
    std::string name_of_section;
    std::vector<Storage> storages;
public:
    SectionsOfDepartment (int number, std::string name_of_section);
    void ShowSectionsOfDepartment() const;
    void EditSection();
    void ShareSection();
    void AddStorage(const Storage& storages);
    std::vector<Storage> getStorages();
};
