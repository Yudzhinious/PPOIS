#include "Staff.h"


Staff::Staff(std::string post , int age)  {
    this->post = post;
    this->age = age;
}
void Staff::AddDelivery(const Delivery& deliveries) {
    delivery.push_back(deliveries);
}

void Staff::ShowingDelivery() const {
    std::cout << "Сотрудник возрастом " << age << " лет занимает должность " << post << std::endl;
    for (const auto& deliver : delivery) {
        deliver.ShowDelivery();
    }
}
std::string Staff::Worker() {
    if (age > 70) {
        std::cout << "Рабочему необходимо предоставить пенсионные выплаты" << std::endl;
        return post;
    }
    else {
        return " ";
    }
}
std::vector<Delivery> Staff::getDelivery()
{
    return delivery;
}