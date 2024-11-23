#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include "Fantastics.h"
#include "Novel.h"
#include "Scientific.h"

class Genre {
protected:
    int amount;
    std::string libname;
    std::string genrename;
    std::string author;
    std::vector<Fantastics> fantastics;
    std::vector<Novel> novels;
    std::vector<Scientific> scientifics;
public:
    void AddFantastics(Fantastics& fantastic);
    void AddNovel(Novel& novel);
    void AddScientific(Scientific& scientific);
    Genre(int amount, std::string libname, std::string genrename, std::string author);
    void ShowInfoGenre();
    void RemoveBookFromGenre(const std::string& genre, int index);
    std::vector<Fantastics> getFantastics();
    std::vector<Novel> getNovel();
    std::vector<Scientific> getScientific();
};