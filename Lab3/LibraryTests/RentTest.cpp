#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Rent.h"

TEST(RentTest, ShowInfoRentTest) {
    Rent rent(3, 2024, "John Doe");

    Customers customer(1000, 10, "Online", 500);
    rent.AddCustomer(customer);

    testing::internal::CaptureStdout();
    rent.ShowInfoRent();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("���������� ���������� John Doe ���� ����� � ����������� �� 3 ������� � 2024 ����."), std::string::npos);
    EXPECT_NE(output.find("�� ������� ����������� ���� ��������� 500 ������."), std::string::npos);
}
TEST(RentTest, AddCustomerTest) {
    Rent rent(6, 2024, "Jane Doe");

    EXPECT_EQ(rent.getCustomer().size(), 0);

    Customers customer(500, 15, "Library", 300);
    rent.AddCustomer(customer);

    EXPECT_EQ(rent.getCustomer().size(), 1);
}

TEST(RentTest, ShowInfoRentMultipleCustomersTest) {
    Rent rent(12, 2024, "Bob Smith");

    Customers customer1(1200, 5, "Store", 200);
    Customers customer2(800, 8, "Library", 400);
    rent.AddCustomer(customer1);
    rent.AddCustomer(customer2);

    testing::internal::CaptureStdout();
    rent.ShowInfoRent();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("���������� ���������� Bob Smith ���� ����� � ����������� �� 12 ������� � 2024 ����."), std::string::npos);
    EXPECT_NE(output.find("�� ������� ����������� ���� ��������� 200 ������."), std::string::npos);
    EXPECT_NE(output.find("�� ������� ����������� ���� ��������� 400 ������."), std::string::npos);
}
TEST(RentTest, ShowInfoRentEmptyCustomerListTest) {
    Rent rent(6, 2024, "Chris Miller");

    testing::internal::CaptureStdout();
    rent.ShowInfoRent();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("���������� ���������� Chris Miller ���� ����� � ����������� �� 6 ������� � 2024 ����."), std::string::npos);
}
