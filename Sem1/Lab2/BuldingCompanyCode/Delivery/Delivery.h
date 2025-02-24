#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Client.h"

class Delivery {
private:
    int price;
    double speed;
    std::string start_place;
    std::string finish_place;
    std::vector<Client> people;
public:
    Delivery(int price, double speed, std::string start_place, std::string finish_place);
    void AddClient(Client& peoples);
    void ShowDelivery();
    std::vector<Client> getClient();
};