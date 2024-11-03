#include "Staff.h"


Staff::Staff(std::string post , int age)  {
    this->post = post;
    this->age = age;
}
void Staff::AddDelivery(const Delivery& deliveries) {
    delivery.push_back(deliveries);
}

void Staff::ShowingDelivery() const {
    std::cout << "—отрудник возрастом " << age << " лет занимает должность " << post << std::endl;
    for (const auto& deliver : delivery) {
        deliver.ShowDelivery();
    }
}

std::vector<Delivery> Staff::getDelivery()
{
    return delivery;
}