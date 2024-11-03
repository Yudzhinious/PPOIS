#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab2/Client.h"
#include "C:/Users/ASUS/source/repos/Lab2/Owner.h"

TEST(ClientTest, ShowInfoTest) {
    Client client(3, "John", "Doe", 500);

    testing::internal::CaptureStdout();
    client.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("������ Doe �������� ����� �� 500 ������"), std::string::npos);
}
TEST(ClientTest, AddOrderTest) {
    Client client(1, "����", "������", 1000);
    client.AddOrder(100.0, "2024-11-01");

    testing::internal::CaptureStdout();
    client.ShowOrderHistory();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expectedOutput = "������� ������� ������� ������:\n����� ������: 100 ������, ����: 2024-11-01\n";
    EXPECT_EQ(output, expectedOutput);
}

TEST(ClientTest, MultipleOrdersTest) {
    Client client(1, "������", "������", 2000);
    client.AddOrder(250.0, "2024-10-25");
    client.AddOrder(150.0, "2024-10-30");

    testing::internal::CaptureStdout();
    client.ShowOrderHistory();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expectedOutput = "������� ������� ������� ������:\n"
        "����� ������: 250 ������, ����: 2024-10-25\n"
        "����� ������: 150 ������, ����: 2024-10-30\n";
    EXPECT_EQ(output, expectedOutput);
}