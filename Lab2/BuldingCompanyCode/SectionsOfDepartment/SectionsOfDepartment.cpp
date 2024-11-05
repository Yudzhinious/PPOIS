#include "SectionsOfDepartment.h"

SectionsOfDepartment::SectionsOfDepartment(int number, std::string name) {
    this->number = number;
    this->name_of_section = name;
}
void SectionsOfDepartment::AddStorage(Storage& storage) {
    storages.push_back(std::move(storage));
}

void SectionsOfDepartment::ShareSection() {
    if (name_of_section == " ") {
        std::cout << "Данный отдел не обнаружен, необходимо устранить проблему" << std::endl;
    }
}
void SectionsOfDepartment::EditSection() {
        if (number == 0) {
            std::cout << "Отдел " << name_of_section << " необходимо отрегулировать" << std::endl;
        }
        else {
            std::cout << "Отдел " << name_of_section << " содержит в себе достаточное количество товара" << std::endl;
        }
}
void SectionsOfDepartment::ShowSectionsOfDepartment() {
    std::cout << "Компания состоит из отделов " << name_of_section << " количеством " << number << " штук." << std::endl;
    for (auto it = storages.begin(); it != storages.end(); ++it) {
        it->ShowInfo();
    }
}
std::vector<Storage> SectionsOfDepartment::getStorages() {
    return storages;
}