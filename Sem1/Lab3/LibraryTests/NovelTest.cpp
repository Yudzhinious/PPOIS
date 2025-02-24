#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Novel.h"

TEST(NovelTest, ShowInfoTest) {
    Novel novel(300, "Таинственный остров", "Жюль Верн", 8, 500);

    testing::internal::CaptureStdout();
    novel.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Новельная книга Таинственный остров качества 8 стоит 500 рублей."), std::string::npos);
}

TEST(NovelTest, IncreaseQualityTest) {
    Novel novel(300, "Таинственный остров", "Жюль Верн", 8, 500);

    testing::internal::CaptureStdout();
    novel.IncreaseQuality(2); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Качество новельной книги увеличено на 2. Новое качество: 10"), std::string::npos);

    testing::internal::CaptureStdout();
    novel.IncreaseQuality(-5); 
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Ошибка: значение должно быть положительным."), std::string::npos);
}

TEST(NovelTest, ReducePriceTest) {
    Novel novel(300, "Таинственный остров", "Жюль Верн", 8, 500);

    testing::internal::CaptureStdout();
    novel.ReducePrice(100); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Цена новельной книги снижена на 100 рублей. Новая цена: 400 рублей."), std::string::npos);

    testing::internal::CaptureStdout();
    novel.ReducePrice(600); 
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Ошибка: уменьшение цены не должно превышать текущую цену."), std::string::npos);

    testing::internal::CaptureStdout();
    novel.ReducePrice(-50);  
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Ошибка: уменьшение цены должно быть положительным."), std::string::npos);
}

TEST(NovelTest, PricePerPageTest) {
    Novel novel(300, "Таинственный остров", "Жюль Верн", 8, 600);

    testing::internal::CaptureStdout();
    double pricePerPage = novel.PricePerPage();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(pricePerPage, 2.0);
    EXPECT_EQ(output, ""); 

    Novel novelWithZeroPages(0, "Таинственный остров", "Жюль Верн", 8, 600);
    testing::internal::CaptureStdout();
    pricePerPage = novelWithZeroPages.PricePerPage();
    output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(pricePerPage, 0.0);
    EXPECT_NE(output.find("Ошибка: количество страниц должно быть положительным."), std::string::npos);
}
