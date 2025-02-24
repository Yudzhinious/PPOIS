#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Customers.h"


TEST(CustomersTest, AddExpensePositiveTest) {
    Customers customer(1000, 1, "SourceA", 500);

    testing::internal::CaptureStdout();
    customer.AddExpense(-50);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Ошибка: Сумма должна быть положительной."), std::string::npos);
}

TEST(CustomersTest, ReduceExpenseTest) {
    Customers customer(1000, 1, "SourceA", 500);

    testing::internal::CaptureStdout();
    customer.ReduceExpense(600);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Ошибка: Сумма должна быть положительной и не превышать текущие расходы."), std::string::npos);
}

TEST(CustomersTest, AverageMonthlyExpenseTest) {
    Customers customer(1000, 1, "SourceA", 600);

    testing::internal::CaptureStdout();
    customer.AverageMonthlyExpense(3);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Средний расход за 3 месяц(ев): 200 рублей в месяц."), std::string::npos);

    testing::internal::CaptureStdout();
    customer.AverageMonthlyExpense(0);
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Ошибка: Количество месяцев должно быть положительным."), std::string::npos);
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
    EXPECT_NE(output.find("На расходы покупателем было потрачено 500 рублей."), std::string::npos);
}
