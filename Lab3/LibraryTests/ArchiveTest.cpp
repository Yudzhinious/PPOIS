#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Archive.h"

TEST(ArchiveTest, InfoArchiveTest) {
    Archive archive(5, "Test Archive");
    testing::internal::CaptureStdout();
    archive.InfoArchive();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("� ������ ��������� 5 ����������."), std::string::npos);
}

TEST(ArchiveTest, ShowAllDocsEmptyTest) {
    Archive archive(5, "Test Archive");

    testing::internal::CaptureStdout();
    archive.ShowAllDocs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("����� ����."), std::string::npos);
}
