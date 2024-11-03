#include "Staff.h"


Staff::Staff(std::string post , int age)  {
    this->post = post;
    this->age = age;
}
void Staff::AddDelivery(const Delivery& deliveries) {
    delivery.push_back(deliveries);
}

void Staff::ShowingDelivery() const {
    std::cout << "��������� ��������� " << age << " ��� �������� ��������� " << post << std::endl;
    for (const auto& deliver : delivery) {
        deliver.ShowDelivery();
    }
}
std::string Staff::Worker() {
    if (age > 70) {
        std::cout << "�������� ���������� ������������ ���������� �������" << std::endl;
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