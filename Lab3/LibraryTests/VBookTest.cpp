#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/VBook.h"

TEST(BookTest, ChangePagesAndShowInfoTest) {
    Book book(200, "����� � ���", "��� �������");

    book.SetPages(350);

    testing::internal::CaptureStdout();
    book.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("����� ����� � ��� ������ ��� ������� �������� � ���� 350 �������."), std::string::npos);
}

TEST(BookTest, SetPagesZeroTest) {
    Book book(200, "����� � ���", "��� �������");

    testing::internal::CaptureStdout();
    book.SetPages(0); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������: ���������� ������� ������ ���� ������������� ������."), std::string::npos);
}
TEST(BookTest, GetFirstHalfTitleOddPagesTest) {
    Book book(201, "1984", "������ ������");

    std::string expectedTitle = "1984 (������ ��������, 100 �������)";
    EXPECT_EQ(book.GetFirstHalfTitle(), expectedTitle);
}
TEST(BookTest, ShowInfoTest) {
    Book book(200, "����� � ���", "��� �������");

    testing::internal::CaptureStdout();
    book.ShowInfo(); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("����� ����� � ��� ������ ��� ������� �������� � ���� 200 �������."), std::string::npos);
}
TEST(BookTest, SetPagesTest) {
    Book book(200, "����� � ���", "��� �������");

    book.SetPages(300);

    testing::internal::CaptureStdout();
    book.ShowInfo(); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("����� ����� � ��� ������ ��� ������� �������� � ���� 300 �������."), std::string::npos);
}
TEST(BookTest, SetPagesNegativeTest) {
    Book book(200, "����� � ���", "��� �������");

    testing::internal::CaptureStdout();
    book.SetPages(-100); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������: ���������� ������� ������ ���� ������������� ������."), std::string::npos);
}
TEST(BookTest, GetFirstHalfTitleTest) {
    Book book(200, "����� � ���", "��� �������");

    std::string expectedTitle = "����� � ��� (������ ��������, 100 �������)";
    EXPECT_EQ(book.GetFirstHalfTitle(), expectedTitle);
}
