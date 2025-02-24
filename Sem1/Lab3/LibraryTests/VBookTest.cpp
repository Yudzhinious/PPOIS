#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/VBook.h"

TEST(BookTest, ChangePagesAndShowInfoTest) {
    Book book(200, "Война и мир", "Лев Толстой");

    book.SetPages(350);

    testing::internal::CaptureStdout();
    book.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Книга Война и мир автора Лев Толстой содержит в себе 350 страниц."), std::string::npos);
}

TEST(BookTest, SetPagesZeroTest) {
    Book book(200, "Война и мир", "Лев Толстой");

    testing::internal::CaptureStdout();
    book.SetPages(0); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Ошибка: количество страниц должно быть положительным числом."), std::string::npos);
}
TEST(BookTest, GetFirstHalfTitleOddPagesTest) {
    Book book(201, "1984", "Джордж Оруэлл");

    std::string expectedTitle = "1984 (первая половина, 100 страниц)";
    EXPECT_EQ(book.GetFirstHalfTitle(), expectedTitle);
}
TEST(BookTest, ShowInfoTest) {
    Book book(200, "Война и мир", "Лев Толстой");

    testing::internal::CaptureStdout();
    book.ShowInfo(); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Книга Война и мир автора Лев Толстой содержит в себе 200 страниц."), std::string::npos);
}
TEST(BookTest, SetPagesTest) {
    Book book(200, "Война и мир", "Лев Толстой");

    book.SetPages(300);

    testing::internal::CaptureStdout();
    book.ShowInfo(); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Книга Война и мир автора Лев Толстой содержит в себе 300 страниц."), std::string::npos);
}
TEST(BookTest, SetPagesNegativeTest) {
    Book book(200, "Война и мир", "Лев Толстой");

    testing::internal::CaptureStdout();
    book.SetPages(-100); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Ошибка: количество страниц должно быть положительным числом."), std::string::npos);
}
TEST(BookTest, GetFirstHalfTitleTest) {
    Book book(200, "Война и мир", "Лев Толстой");

    std::string expectedTitle = "Война и мир (первая половина, 100 страниц)";
    EXPECT_EQ(book.GetFirstHalfTitle(), expectedTitle);
}
