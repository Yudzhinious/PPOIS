#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Storage.h"

TEST(StorageTest, ShowInfoStorageTest) {
    Storage storage(5, "�������� ���������", "�1");
    testing::internal::CaptureStdout();
    storage.ShowInfoStorage();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("��������� �������� ��������� ������� �� ���������1 ����������� 5 ����."), std::string::npos);
}
TEST(StorageTest, AddGenreTest) {
    Storage storage(5, "�������� ���������", "�1");
    Genre genre(3, "����������", "������", "�����������");
    storage.AddGenre(genre);

    testing::internal::CaptureStdout();
    storage.ShowInfoStorage(); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("����������"), std::string::npos); 
    EXPECT_NE(output.find("������"), std::string::npos); 
    EXPECT_NE(output.find("�����������"), std::string::npos); 
}
TEST(StorageTest, AddMultipleGenresTest) {
    Storage storage(5, "�������� ���������", "�1");
    Genre genre1(3, "����������", "������", "�����������");
    Genre genre2(4, "��������", "��������", "�����");

    storage.AddGenre(genre1);
    storage.AddGenre(genre2);

    testing::internal::CaptureStdout();
    storage.ShowInfoStorage();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("����������"), std::string::npos); 
    EXPECT_NE(output.find("������"), std::string::npos);   
    EXPECT_NE(output.find("�����������"), std::string::npos); 
    EXPECT_NE(output.find("��������"), std::string::npos);  
    EXPECT_NE(output.find("��������"), std::string::npos); 
    EXPECT_NE(output.find("�����"), std::string::npos);      
}