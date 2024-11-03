#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab2/Things.h"

TEST(ThingsTest, ValidTest) {
    Things things(10, 5, "ProductB", "Tools", 30);

    testing::internal::CaptureStdout();
    things.Valid();
    std::string output = testing::internal::GetCapturedStdout();

    int a = 30 * 5 - 10;
    if (a < 10000) {
        EXPECT_NE(output.find("Данные вещи соответствуют запросам владельца компании"), std::string::npos);
    }
    else {
        EXPECT_NE(output.find("Данные вещи не соответствуют запросам владельца компании"), std::string::npos);
    }
}