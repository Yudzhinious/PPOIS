#include "Library.h"


Library::Library(int age, int capacity, double address, std::string street, std::string name) {
    this->year = age;
    this->capacity = capacity;
    this->address = address;
    this->street = street;
    this->name = name;
}
void Library::ShowLibrary() {
    std::cout << "Библиотека " << name << " находится на улице " << street << " по адресу " << address << "."<< std::endl;
    std::cout << "Сооружение было построено " << year << " лет назад и в наше время может вместить в себя до " << capacity << " книг одновременно. " << std::endl;
    for (auto it = owners.begin(); it != owners.end(); ++it) {
        it->ShowInfoOwner();
    }
    for (auto it = storages.begin(); it != storages.end(); ++it) {
        it->ShowInfoStorage();
    }
    for (auto it = markets.begin(); it != markets.end(); ++it) {
        it->ShowInfoShop();
    }
}
void Library::AddOwner(Owner& owner) {
    owners.push_back(std::move(owner));
}
void Library::AddShop(Shop& market) {
    markets.push_back(std::move(market));
}
void Library::AddStorage(Storage& storage) {
    storages.push_back(std::move(storage));
}

std::pair<int, int> Library::GetAgeAndCapacity() const {
    return { year, capacity };
}

bool Library::CanAccommodate(int numberOfBooks) const {
    return (numberOfBooks <= capacity);
}

void Library::ExpandCapacity(int additionalCapacity) {
    if (additionalCapacity > 0) {
        capacity += additionalCapacity;
        std::cout << "Вместимость библиотеки увеличена на " << additionalCapacity << " единиц. Новая вместимость: " << capacity << std::endl;
    }
    else {
        std::cout << "Ошибка: дополнительная вместимость должна быть положительной." << std::endl;
    }
}
std::vector<Owner> Library::getOwner() {
    return owners;
}
std::vector<Storage> Library::getStorage() {
    return storages;
}
std::vector<Shop> Library::getShop() {
    return markets;
}
