#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Souvenirs.h"

TEST(SouvenirsTest, ApplyDiscountValidTest) {
    Souvenirs souvenir(100, "����� ������", 500, 10, "�������");
    testing::internal::CaptureStdout();
    souvenir.ApplyDiscount(20); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������ 20% ���������. ����� ���� ��������: 80"), std::string::npos);
}
TEST(SouvenirsTest, ApplyDiscountInvalidTest) {
    Souvenirs souvenir(100, "����� ������", 500, 10, "�������");
    testing::internal::CaptureStdout();
    souvenir.ApplyDiscount(150); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������: ������������ ������� ������."), std::string::npos);
}
TEST(SouvenirsTest, CanPurchaseTestEnoughMoney) {
    Souvenirs souvenir(100, "����� ������", 500, 10, "�������");
    testing::internal::CaptureStdout();
    EXPECT_TRUE(souvenir.CanPurchase(150));
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("�� ������ ������ ������� ����� ������."), std::string::npos);
}
TEST(SouvenirsTest, IncreasePriceTest) {
    Souvenirs souvenir(100, "����� ������", 500, 10, "�������");
    testing::internal::CaptureStdout();
    souvenir.IncreasePrice(10); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("���� �������� ����� ������ ��������� �� 10%. ����� ����: 110"), std::string::npos);
}
TEST(SouvenirsTest, CheckAvailabilityTestInStock) {
    Souvenirs souvenir(100, "����� ������", 500, 10, "�������");
    testing::internal::CaptureStdout();
    souvenir.CheckAvailability(5);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������� ����� ������ � �������. ���������� �� ������: 5."), std::string::npos);
}
