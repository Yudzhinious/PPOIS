#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Documents.h"

TEST(DocumentsTest, ConstructorAndShowInfoTest) {
    Documents doc(200, "DocumentName", "AuthorName", 10);

    testing::internal::CaptureStdout();
    doc.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("¬ архиве наход€тс€ документы на прот€жении уже 10 лет."), std::string::npos);
}

TEST(DocumentsTest, IncreaseAgeTest) {
    Documents doc(200, "DocumentName", "AuthorName", 10);

    doc.IncreaseAge(doc, 5);

    testing::internal::CaptureStdout();
    doc.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("¬ архиве наход€тс€ документы на прот€жении уже 15 лет."), std::string::npos);
}

TEST(DocumentsTest, ShowInfoTest) {
    Documents doc(200, "DocumentName", "AuthorName", 15);

    testing::internal::CaptureStdout();
    doc.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("¬ архиве наход€тс€ документы на прот€жении уже 15 лет."), std::string::npos);
}
