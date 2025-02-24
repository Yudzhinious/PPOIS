#include "Storage.h"

Storage::Storage(int amount, std::string name, std::string block) {
    this->block = block;
    this->name = name;
    this->amount = amount;
}

void Storage::ShowInfoStorage() {
    std::cout << "Хранилище " << name << " состоит из разделов" << block << " количеством "<< amount << " штук." <<std::endl;
    for (auto it = genres.begin(); it != genres.end(); ++it) {
        it->ShowInfoGenre();
    }
}
std::vector<Genre> Storage::getGenre() {
    return genres;
}

void Storage::AddGenre(Genre& genre) {
    genres.push_back(std::move(genre));
}