#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Budget.h"

TEST(BudgetTest, ShowInfoTest) {
    Budget budget(10000, 5, "Government");

    testing::internal::CaptureStdout();
    budget.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Ѕюджет размером 10000 рублей"), std::string::npos);
    EXPECT_NE(output.find("из источника Government"), std::string::npos);
    EXPECT_NE(output.find("с прибылью в 5 процентов"), std::string::npos);
}

TEST(BudgetTest, IncreaseBudgetTest) {
    Budget budget(10000, 5, "Government");

    budget.IncreaseBudget(budget, 10); 

    testing::internal::CaptureStdout();
    budget.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Ѕюджет размером 11000 рублей"), std::string::npos);
    EXPECT_NE(output.find("с прибылью в 15 процентов"), std::string::npos);  
}
TEST(BudgetTest, IncreaseBudgetZeroPercentTest) {
    Budget budget(10000, 5, "Government");

    budget.IncreaseBudget(budget, 0);

    testing::internal::CaptureStdout();
    budget.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Ѕюджет размером 10000 рублей"), std::string::npos);
    EXPECT_NE(output.find("с прибылью в 5 процентов"), std::string::npos); 
}

TEST(BudgetTest, IncreaseBudgetNegativePercentTest) {
    Budget budget(10000, 5, "Government");

    budget.IncreaseBudget(budget, -10);

    testing::internal::CaptureStdout();
    budget.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Ѕюджет размером 9000 рублей"), std::string::npos);
    EXPECT_NE(output.find("с прибылью в -5 процентов"), std::string::npos); 
}
