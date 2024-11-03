#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab2/Delivery.h"
#include "C:/Users/ASUS/source/repos/Lab2/Client.h"

TEST(DeliveryTest, ShowDeliveryTest) {
    Delivery delivery(150, 3.0, "PointX", "PointY");
    Client client1(3, "Eve", "Brown", 400);
    Client client2(4, "Charlie", "Davis", 250);

    delivery.AddClient(client1);
    delivery.AddClient(client2);

    testing::internal::CaptureStdout();
    delivery.ShowDelivery();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("—тоимость доставки за 3 часов из точки PointX в точку PointY будет стоить 150 рублей"), std::string::npos);
    EXPECT_NE(output.find(" лиент Brown выполнил заказ на 400 рублей"), std::string::npos);
    EXPECT_NE(output.find(" лиент Davis выполнил заказ на 250 рублей"), std::string::npos);
}