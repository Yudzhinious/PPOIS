#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Novel.h"

TEST(NovelTest, ShowInfoTest) {
    Novel novel(300, "������������ ������", "���� ����", 8, 500);

    testing::internal::CaptureStdout();
    novel.ShowInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("��������� ����� ������������ ������ �������� 8 ����� 500 ������."), std::string::npos);
}

TEST(NovelTest, IncreaseQualityTest) {
    Novel novel(300, "������������ ������", "���� ����", 8, 500);

    testing::internal::CaptureStdout();
    novel.IncreaseQuality(2); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("�������� ��������� ����� ��������� �� 2. ����� ��������: 10"), std::string::npos);

    testing::internal::CaptureStdout();
    novel.IncreaseQuality(-5); 
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������: �������� ������ ���� �������������."), std::string::npos);
}

TEST(NovelTest, ReducePriceTest) {
    Novel novel(300, "������������ ������", "���� ����", 8, 500);

    testing::internal::CaptureStdout();
    novel.ReducePrice(100); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("���� ��������� ����� ������� �� 100 ������. ����� ����: 400 ������."), std::string::npos);

    testing::internal::CaptureStdout();
    novel.ReducePrice(600); 
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������: ���������� ���� �� ������ ��������� ������� ����."), std::string::npos);

    testing::internal::CaptureStdout();
    novel.ReducePrice(-50);  
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������: ���������� ���� ������ ���� �������������."), std::string::npos);
}

TEST(NovelTest, PricePerPageTest) {
    Novel novel(300, "������������ ������", "���� ����", 8, 600);

    testing::internal::CaptureStdout();
    double pricePerPage = novel.PricePerPage();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(pricePerPage, 2.0);
    EXPECT_EQ(output, ""); 

    Novel novelWithZeroPages(0, "������������ ������", "���� ����", 8, 600);
    testing::internal::CaptureStdout();
    pricePerPage = novelWithZeroPages.PricePerPage();
    output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(pricePerPage, 0.0);
    EXPECT_NE(output.find("������: ���������� ������� ������ ���� �������������."), std::string::npos);
}
