#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab2/Material.h"
#include "C:/Users/ASUS/source/repos/Lab2/Owner.h"

TEST(MaterialTest, ShowInfoTest) {
    Material material(2, "Wood", "Building Material", 100);

    testing::internal::CaptureStdout();
    material.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Наименование материала : Building Material, Количество единиц материала : 100"), std::string::npos);
}

TEST(MaterialTest, AddAmountTest) {
    Material material(2, "Wood", "Building Material", 100);

    material.AddAmount(50);
    EXPECT_EQ(material.GetAmount(), 150);

    testing::internal::CaptureStdout();
    material.AddAmount(-10); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Количество должно быть положительным."), std::string::npos);
}

TEST(MaterialTest, ReduceAmountTest) {
    Material material(2, "Wood", "Building Material", 100);

    material.ReduceAmount(30);
    EXPECT_EQ(material.GetAmount(), 70);

    testing::internal::CaptureStdout();
    material.ReduceAmount(200); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Недопустимое количество."), std::string::npos);
}

TEST(MaterialTest, TypeTest) {
    Material material(2, "Wood", "Building Material", 100);

    EXPECT_EQ(material.GetType(), "Building Material");

    material.SetType("Raw Material");
    EXPECT_EQ(material.GetType(), "Raw Material");
}

TEST(MaterialTest, GetAmountTest) {
    Material material(2, "Wood", "Building Material", 100);
    EXPECT_EQ(material.GetAmount(), 100);
}

TEST(MaterialTest, HasMoreThanTest) {
    Material material1(2, "Wood", "Building Material", 100);
    Material material2(3, "Metal", "Raw Material", 50);

    EXPECT_TRUE(material1.HasMoreThan(material2));
    EXPECT_FALSE(material2.HasMoreThan(material1));
}

TEST(MaterialTest, IsSameTypeTest) {
    Material material1(2, "Wood", "Building Material", 100);
    Material material2(3, "Metal", "Building Material", 50);
    Material material3(4, "Plastic", "Raw Material", 30);

    EXPECT_TRUE(material1.IsSameType(material2));
    EXPECT_FALSE(material1.IsSameType(material3));
}