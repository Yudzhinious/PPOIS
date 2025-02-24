#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Fantastics.h"
#include "C:/Users/ASUS/source/repos/Lab3/Genre.h"


TEST(FantasticsTest, IncreaseQualityTest) {
    Fantastics book(300, "The Fantastic Journey", "A. Author", 5, 200);

    testing::internal::CaptureStdout();
    book.IncreaseQuality(3);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Качество книги увеличено на 3. Новое качество: 8"), std::string::npos);

    testing::internal::CaptureStdout();
    book.IncreaseQuality(-2); 
    output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Ошибка: значение должно быть положительным."), std::string::npos);
}

TEST(FantasticsTest, ShowInfoTest) {
    Fantastics book(300, "The Fantastic Journey", "A. Author", 7, 250);

    testing::internal::CaptureStdout();
    book.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Фантастическая книга The Fantastic Journey качества 7 стоит 250 рублей."), std::string::npos);
}

TEST(FantasticsTest, ReducePriceTest) {
    Fantastics book(300, "The Fantastic Journey", "A. Author", 5, 200);

    testing::internal::CaptureStdout();
    book.ReducePrice(50);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Цена книги снижена на 50 рублей. Новая цена: 150 рублей."), std::string::npos);

    testing::internal::CaptureStdout();
    book.ReducePrice(250);
    output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Ошибка: уменьшение цены должно быть положительным и не превышать текущую цену."), std::string::npos);
}

TEST(FantasticsTest, PricePerPageTest) {
    Fantastics book(300, "The Fantastic Journey", "A. Author", 5, 300);

    testing::internal::CaptureStdout();
    double pricePerPage = book.PricePerPage();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_DOUBLE_EQ(pricePerPage, 1.0);

    Fantastics bookWithZeroPages(0, "Empty Book", "No Author", 5, 300);
    testing::internal::CaptureStdout();
    pricePerPage = bookWithZeroPages.PricePerPage();
    output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Ошибка: количество страниц должно быть положительным."), std::string::npos);
    EXPECT_DOUBLE_EQ(pricePerPage, 0.0);
}
