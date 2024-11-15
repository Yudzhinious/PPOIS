#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Customers.h"


TEST(CustomersTest, AddExpensePositiveTest) {
    Customers customer(1000, 1, "SourceA", 500);

    testing::internal::CaptureStdout();
    customer.AddExpense(-50);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������: ����� ������ ���� �������������."), std::string::npos);
}

TEST(CustomersTest, ReduceExpenseTest) {
    Customers customer(1000, 1, "SourceA", 500);

    testing::internal::CaptureStdout();
    customer.ReduceExpense(600);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������: ����� ������ ���� ������������� � �� ��������� ������� �������."), std::string::npos);
}

TEST(CustomersTest, AverageMonthlyExpenseTest) {
    Customers customer(1000, 1, "SourceA", 600);

    testing::internal::CaptureStdout();
    customer.AverageMonthlyExpense(3);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������� ������ �� 3 �����(��): 200 ������ � �����."), std::string::npos);

    testing::internal::CaptureStdout();
    customer.AverageMonthlyExpense(0);
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������: ���������� ������� ������ ���� �������������."), std::string::npos);
}

TEST(CustomersTest, HasHigherExpenseThanTest) {
    Customers customer1(1000, 1, "SourceA", 700);
    Customers customer2(1000, 1, "SourceB", 500);

    EXPECT_TRUE(customer1.HasHigherExpenseThan(customer2));
    EXPECT_FALSE(customer2.HasHigherExpenseThan(customer1));
}

TEST(CustomersTest, ShowInfoCustTest) {
    Customers customer(1000, 1, "SourceA", 500);

    testing::internal::CaptureStdout();
    customer.ShowInfoCust();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("�� ������� ����������� ���� ��������� 500 ������."), std::string::npos);
}
