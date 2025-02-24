#include "TransportRental.h"

TransportRental::TransportRental(int experience, int time, std::string name, std::string naming, int amount) : Fabricator( experience, time, name) {
    this->naming = naming;
    this->amount = amount;
}

void TransportRental::ShowHelp_1() const {
    std::cout << "ѕроизводителем был оснащен транспорт" << naming << " количеством " << amount << " в аренду на " << time << " мес€цев " << std::endl;
}
void TransportRental::Experience() const {
    if (amount == 0) {
        std::cout << "ѕроизводителем не был оснащен транспортом"  << std::endl;
    }
    else {
        std::cout << "“ранспорт"<< naming<< "необходимо использовать дл€ строительных работ" << std::endl;
    }
}