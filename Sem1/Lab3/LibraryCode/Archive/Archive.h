#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include "Documents.h"

class Archive {
protected:
    int amount;
    std::string name;
    std::vector<Documents> docs;
public:
    Archive(int amount, std::string name);
    void InfoArchive();
    void AddDocs(Documents& doc);
    void ShowAllDocs() const;
    std::vector<Documents> getDocs();
};

