#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include "Genre.h"

class Storage {
protected:
    int amount;
    std::string name;
    std::string block;
    std::vector<Genre> genres;
public:
    void AddGenre(Genre& genres);
    Storage(int amount, std::string name, std::string block);
    void ShowInfoStorage();
    std::vector<Genre> getGenre();
};