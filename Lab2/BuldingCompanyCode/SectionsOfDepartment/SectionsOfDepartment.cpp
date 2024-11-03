#include "SectionsOfDepartment.h"

SectionsOfDepartment::SectionsOfDepartment(int number, std::string name) {
    this->number = number;
    this->name_of_section = name;
}
void SectionsOfDepartment::AddStorage(const Storage& storage) {
    storages.push_back(storage);
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
void SectionsOfDepartment::ShowSectionsOfDepartment() const {
    std::cout << "Компания состоит из отделов " << name_of_section << " количеством " << number << " штук." << std::endl;
    for (const auto& storage : storages) {
        storage.ShowInfo();
    }
}
std::vector<Storage> SectionsOfDepartment::getStorages() {
    return storages;
}