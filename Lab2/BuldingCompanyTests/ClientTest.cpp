#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab2/Client.h"

TEST(ClientTest, ShowInfoTest) {
    Client client(3, "John", "Doe", 500);

    testing::internal::CaptureStdout();
    client.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Клиент Doe выполнил заказ на 500 рублей"), std::string::npos);
}