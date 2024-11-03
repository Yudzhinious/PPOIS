#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab2/Fabricator.h"

TEST(FabricatorTest, ShowHelp1Test) {
    Fabricator fabricator(10, 6, "CompanyX");

    testing::internal::CaptureStdout();
    fabricator.ShowHelp_1();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Производитель CompanyX с опытом на рынке в 10 лет предоставляет компании услуги на протяжении 6 месяцев"), std::string::npos);
}

TEST(FabricatorTest, ShowHelp2Test) {
    Fabricator fabricator(5, 3, "CompanyY");

    testing::internal::CaptureStdout();
    fabricator.ShowHelp_2();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Производитель CompanyY с опытом на рынке в 5 лет предоставляет компании услуги на протяжении 3 месяцев"), std::string::npos);
}