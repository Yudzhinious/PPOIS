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
        std::cout << "������ ����� �� ���������, ���������� ��������� ��������" << std::endl;
    }
}
void SectionsOfDepartment::EditSection() {
        if (number == 0) {
            std::cout << "����� " << name_of_section << " ���������� ��������������" << std::endl;
        }
        else {
            std::cout << "����� " << name_of_section << " �������� � ���� ����������� ���������� ������" << std::endl;
        }
}
void SectionsOfDepartment::ShowSectionsOfDepartment() {
    std::cout << "�������� ������� �� ������� " << name_of_section << " ����������� " << number << " ����." << std::endl;
    for (auto it = storages.begin(); it != storages.end(); ++it) {
        it->ShowInfo();
    }
}
std::vector<Storage> SectionsOfDepartment::getStorages() {
    return storages;
}