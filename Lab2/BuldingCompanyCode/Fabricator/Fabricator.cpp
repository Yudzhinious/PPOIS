#include "Fabricator.h"

Fabricator::Fabricator(int experience, int time, std::string name) {
    this->experience = experience;
    this->name = name;
    this->time = time;
}

void Fabricator::ShowHelp_1() const {
    std::cout << "Производитель " << name << " с опытом на рынке в " << experience << " лет предоставляет компании услуги на протяжении " << time << " месяцев" << std::endl;
}
void Fabricator::ShowHelp_2() const {
    std::cout << "Производитель " << name << " с опытом на рынке в " << experience << " лет предоставляет компании услуги на протяжении " << time << " месяцев" << std::endl;
}
