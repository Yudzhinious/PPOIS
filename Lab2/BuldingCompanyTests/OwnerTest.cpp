#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab2/Owner.h"

TEST(OwnerTest, OrderTest) {
Owner owner(5, "Alice");

testing::internal::CaptureStdout();
owner.Order();
std::string output = testing::internal::GetCapturedStdout();

EXPECT_NE(output.find("Заказ оформлен!"), std::string::npos);
}
