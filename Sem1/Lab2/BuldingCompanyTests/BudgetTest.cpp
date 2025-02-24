#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab2/Budget.h"
#include "C:/Users/ASUS/source/repos/Lab2/Owner.h"

TEST(BudgetTest, ShowInfoTest) {
    Budget budget(5, "Budget1", "Marketing", 1000);

    testing::internal::CaptureStdout();
    budget.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expectedOutput = " �� �������  Marketing ������ ���� ��������� 1000 ������\n";

    ASSERT_EQ(output, expectedOutput);
}
TEST(BudgetTest, SumMoneyTest) {
    Budget budget(100, "Budget1", "Marketing", 3);

    testing::internal::CaptureStdout();
    int result = budget.SumMoney(); 
    std::string output = testing::internal::GetCapturedStdout(); 

    int expectedSum =  300; 
    std::string expectedOutput = "� ������� ��������� ������ �� ����� : " + std::to_string(expectedSum) + "\n";

    EXPECT_EQ(result, expectedSum);
}