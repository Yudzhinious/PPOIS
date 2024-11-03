#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab2/Budget.h"

TEST(BudgetTest, ShowInfoTest) {
    Budget budget(5, "Budget1", "Marketing", 1000);

    testing::internal::CaptureStdout();
    budget.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expectedOutput = " На расходы  Marketing отдела было потрачено 1000 рублей\n";

    ASSERT_EQ(output, expectedOutput);
}
