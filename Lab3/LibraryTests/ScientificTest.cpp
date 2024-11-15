#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Scientific.h"

TEST(ScientificTest, ShowInfoTest) {
    Scientific book(300, "Science of AI", "John Doe", 85, 1200);

    testing::internal::CaptureStdout();
    book.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Научная книга Science of AI качества 85 стоит 1200 рублей."), std::string::npos);
}

TEST(ScientificTest, EvaluateScientificValueTest) {
    Scientific book(300, "Science of AI", "John Doe", 85, 1200);

    testing::internal::CaptureStdout();
    double value = book.EvaluateScientificValue();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(value, 85 * 300);
    EXPECT_NE(output.find("Научная ценность книги: 25500"), std::string::npos);
}

TEST(ScientificTest, UpdateEditionTestPositiveIncrease) {
    Scientific book(300, "Science of AI", "John Doe", 85, 1200);

    testing::internal::CaptureStdout();
    book.UpdateEdition(10, 300);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Издание обновлено. Новое качество: 95, новая цена: 1500 рублей."), std::string::npos);
}

TEST(ScientificTest, UpdateEditionTestNegativeQualityIncrease) {
    Scientific book(300, "Science of AI", "John Doe", 85, 1200);

    testing::internal::CaptureStdout();
    book.UpdateEdition(-5, 300);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Ошибка: увеличение качества должно быть положительным."), std::string::npos);
    EXPECT_NE(output.find("Издание обновлено. Новое качество: 85, новая цена: 1500 рублей."), std::string::npos);
}

TEST(ScientificTest, UpdateEditionTestNegativePriceIncrease) {
    Scientific book(300, "Science of AI", "John Doe", 85, 1200);

    testing::internal::CaptureStdout();
    book.UpdateEdition(10, -300);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Ошибка: увеличение цены должно быть положительным."), std::string::npos);
    EXPECT_NE(output.find("Издание обновлено. Новое качество: 95, новая цена: 1200 рублей."), std::string::npos);
}

TEST(ScientificTest, PriceBasedOnRatingValidRating) {
    Scientific book(300, "Science of AI", "John Doe", 85, 1200);

    testing::internal::CaptureStdout();
    double adjustedPrice = book.PriceBasedOnRating(0.5);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(adjustedPrice, 1200 * 1.5);
    EXPECT_NE(output.find("Цена книги с учетом рейтинга 0.5: 1800 рублей."), std::string::npos);
}

TEST(ScientificTest, PriceBasedOnRatingInvalidRating) {
    Scientific book(300, "Science of AI", "John Doe", 85, 1200);

    testing::internal::CaptureStdout();
    double adjustedPrice = book.PriceBasedOnRating(-0.1);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(adjustedPrice, 0.0);
    EXPECT_NE(output.find("Ошибка: рейтинг должен быть в диапазоне от 0 до 1."), std::string::npos);
}
