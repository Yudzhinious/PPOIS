#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab2/Material.h"

TEST(MaterialTest, ShowInfoTest) {
    Material material(2, "Wood", "Building Material", 100);

    testing::internal::CaptureStdout();
    material.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Наименование материала : Building Material, Количество единиц материала : 100"), std::string::npos);
}