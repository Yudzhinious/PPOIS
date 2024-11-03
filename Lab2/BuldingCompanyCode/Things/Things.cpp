#include "Things.h"

Things::Things(int experience, int time, std::string name, std::string naming, int amount) : Fabricator(experience, time, name) {
    this->naming = naming;
    this->amount = amount;
}

void Things::ShowHelp_2() const {
    std::cout << "Производителем были оснащены" << naming << " количеством " << amount << " на срок " << time << " месяцев " << std::endl;
}

void Things::Valid() {
    int a = amount*time-experience;
    if (a < 10000) {
        std::cout << "Данные вещи соответствуют запросам владельца компании" << std::endl;
    }
    else {
        std::cout << "Данные вещи не соответствуют запросам владельца компании" << std::endl;
    }
}