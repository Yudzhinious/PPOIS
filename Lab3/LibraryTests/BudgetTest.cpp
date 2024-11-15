#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Budget.h"

TEST(BudgetTest, ShowInfoTest) {
    Budget budget(10000, 5, "Government");

    testing::internal::CaptureStdout();
    budget.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("������ �������� 10000 ������"), std::string::npos);
    EXPECT_NE(output.find("�� ��������� Government"), std::string::npos);
    EXPECT_NE(output.find("� �������� � 5 ���������"), std::string::npos);
}

TEST(BudgetTest, IncreaseBudgetTest) {
    Budget budget(10000, 5, "Government");

    budget.IncreaseBudget(budget, 10); 

    testing::internal::CaptureStdout();
    budget.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("������ �������� 11000 ������"), std::string::npos);
    EXPECT_NE(output.find("� �������� � 15 ���������"), std::string::npos);  
}
TEST(BudgetTest, IncreaseBudgetZeroPercentTest) {
    Budget budget(10000, 5, "Government");

    budget.IncreaseBudget(budget, 0);

    testing::internal::CaptureStdout();
    budget.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("������ �������� 10000 ������"), std::string::npos);
    EXPECT_NE(output.find("� �������� � 5 ���������"), std::string::npos); 
}

TEST(BudgetTest, IncreaseBudgetNegativePercentTest) {
    Budget budget(10000, 5, "Government");

    budget.IncreaseBudget(budget, -10);

    testing::internal::CaptureStdout();
    budget.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("������ �������� 9000 ������"), std::string::npos);
    EXPECT_NE(output.find("� �������� � -5 ���������"), std::string::npos); 
}
