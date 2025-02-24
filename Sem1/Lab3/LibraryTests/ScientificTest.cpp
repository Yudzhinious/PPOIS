#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Scientific.h"

TEST(ScientificTest, ShowInfoTest) {
    Scientific book(300, "Science of AI", "John Doe", 85, 1200);

    testing::internal::CaptureStdout();
    book.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("������� ����� Science of AI �������� 85 ����� 1200 ������."), std::string::npos);
}

TEST(ScientificTest, EvaluateScientificValueTest) {
    Scientific book(300, "Science of AI", "John Doe", 85, 1200);

    testing::internal::CaptureStdout();
    double value = book.EvaluateScientificValue();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(value, 85 * 300);
    EXPECT_NE(output.find("������� �������� �����: 25500"), std::string::npos);
}

TEST(ScientificTest, UpdateEditionTestPositiveIncrease) {
    Scientific book(300, "Science of AI", "John Doe", 85, 1200);

    testing::internal::CaptureStdout();
    book.UpdateEdition(10, 300);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("������� ���������. ����� ��������: 95, ����� ����: 1500 ������."), std::string::npos);
}

TEST(ScientificTest, UpdateEditionTestNegativeQualityIncrease) {
    Scientific book(300, "Science of AI", "John Doe", 85, 1200);

    testing::internal::CaptureStdout();
    book.UpdateEdition(-5, 300);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("������: ���������� �������� ������ ���� �������������."), std::string::npos);
    EXPECT_NE(output.find("������� ���������. ����� ��������: 85, ����� ����: 1500 ������."), std::string::npos);
}

TEST(ScientificTest, UpdateEditionTestNegativePriceIncrease) {
    Scientific book(300, "Science of AI", "John Doe", 85, 1200);

    testing::internal::CaptureStdout();
    book.UpdateEdition(10, -300);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("������: ���������� ���� ������ ���� �������������."), std::string::npos);
    EXPECT_NE(output.find("������� ���������. ����� ��������: 95, ����� ����: 1200 ������."), std::string::npos);
}

TEST(ScientificTest, PriceBasedOnRatingValidRating) {
    Scientific book(300, "Science of AI", "John Doe", 85, 1200);

    testing::internal::CaptureStdout();
    double adjustedPrice = book.PriceBasedOnRating(0.5);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(adjustedPrice, 1200 * 1.5);
    EXPECT_NE(output.find("���� ����� � ������ �������� 0.5: 1800 ������."), std::string::npos);
}

TEST(ScientificTest, PriceBasedOnRatingInvalidRating) {
    Scientific book(300, "Science of AI", "John Doe", 85, 1200);

    testing::internal::CaptureStdout();
    double adjustedPrice = book.PriceBasedOnRating(-0.1);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(adjustedPrice, 0.0);
    EXPECT_NE(output.find("������: ������� ������ ���� � ��������� �� 0 �� 1."), std::string::npos);
}
