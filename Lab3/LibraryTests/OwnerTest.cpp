#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Owner.h"
#include "C:/Users/ASUS/source/repos/Lab3/Customers.h"

TEST(OwnerTest, ShowInfoOwnerTest) {
    Owner owner(45, 20, "John Doe");

    testing::internal::CaptureStdout();
    owner.ShowInfoOwner();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("¬леделец John Doe"), std::string::npos);
    EXPECT_NE(output.find("возрастом 45 лет"), std::string::npos);
    EXPECT_NE(output.find("занимаетс€ управленческим бизнесом на прот€жении 20 лет"), std::string::npos);
}

TEST(OwnerTest, AddCustomerTest) {
    Owner owner(45, 20, "John Doe");

    Customers customer1(1000, 10, "Salary", 500); 
    Customers customer2(1500, 15, "Investment", 800); 

    owner.AddCustomer(customer1);
    owner.AddCustomer(customer2);

    testing::internal::CaptureStdout();
    owner.ShowInfoOwner();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Ќа расходы покупателем было потрачено 500 рублей."), std::string::npos);
    EXPECT_NE(output.find("Ќа расходы покупателем было потрачено 800 рублей."), std::string::npos);
}
TEST(OwnerTest, AddCustomerEmptyTest) {
    Owner owner(45, 20, "John Doe");

    testing::internal::CaptureStdout();
    owner.ShowInfoOwner();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output.find("Ќа расходы покупателем было потрачено"), std::string::npos);
}
TEST(OwnerTest, ShowInfoOwnerWithOneCustomerTest) {
    Owner owner(45, 20, "John Doe");
    Customers customer1(1000, 10, "Salary", 500);

    owner.AddCustomer(customer1);

    testing::internal::CaptureStdout();
    owner.ShowInfoOwner();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Ќа расходы покупателем было потрачено 500 рублей."), std::string::npos);
}
TEST(OwnerTest, ShowInfoOwnerWithMultipleCustomersTest) {
    Owner owner(45, 20, "John Doe");

    Customers customer1(1000, 10, "Salary", 500);
    Customers customer2(1500, 15, "Investment", 800);

    owner.AddCustomer(customer1);
    owner.AddCustomer(customer2);

    testing::internal::CaptureStdout();
    owner.ShowInfoOwner();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Ќа расходы покупателем было потрачено 500 рублей."), std::string::npos);
    EXPECT_NE(output.find("Ќа расходы покупателем было потрачено 800 рублей."), std::string::npos);
}