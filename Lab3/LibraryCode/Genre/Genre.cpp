#include "Genre.h"
Genre::Genre(int amount, std::string libname, std::string genrename, std::string author) {
    this->amount = amount;
    this->libname = libname;
    this->genrename = genrename;
    this->author = author;
}

void Genre::ShowInfoGenre() {
    std::cout << "Библиотека" << libname << "представлена " << amount << " жанрами, в том числе" << genrename << " автора " << author << std::endl;
    for (auto it = fantastics.begin(); it != fantastics.end(); ++it) {
        it->ShowInfo();
    }
    for (auto it = novels.begin(); it != novels.end(); ++it) {
        it->ShowInfo();
    }
    for (auto it = scientifics.begin(); it != scientifics.end(); ++it) {
        it->ShowInfo();
    }
}

void Genre::RemoveBookFromGenre(const std::string& genre, int index) {
    if (genre == "Fantastics" && index < fantastics.size()) {
        fantastics.erase(fantastics.begin() + index);
    }
    else if (genre == "Novel" && index < novels.size()) {
        novels.erase(novels.begin() + index);
    }
    else if (genre == "Scientific" && index < scientifics.size()) {
        scientifics.erase(scientifics.begin() + index);
    }
    else {
        std::cout << "Ошибка: Неверный жанр или индекс." << std::endl;
    }
}
std::vector<Fantastics> Genre::getFantastics() {
    return fantastics;
}
std::vector<Novel> Genre::getNovel() {
    return novels;
}
std::vector<Scientific> Genre::getScientific() {
    return scientifics;
}

void Genre::AddFantastics(Fantastics& fantastic) {
    fantastics.push_back(std::move(fantastic));
}
void Genre::AddNovel(Novel& novel) {
    novels.push_back(std::move(novel));
}
void Genre::AddScientific(Scientific& scientific) {
    scientifics.push_back(std::move(scientific));
}