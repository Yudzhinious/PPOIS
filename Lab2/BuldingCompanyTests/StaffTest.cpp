#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab2/Staff.h"
#include "C:/Users/ASUS/source/repos/Lab2/Delivery.h"

TEST(StaffTest, AddDeliveryTest) {
    Staff staff( "��������", 52);
    Delivery delivery1(100, 2.5, "PointA", "PointB");

    staff.AddDelivery(delivery1);

    EXPECT_EQ(staff.getDelivery().size(), 1);
}

TEST(StaffTest, ShowDeliveryTest) {
    Staff staff("��������", 52);
    Delivery delivery1(100, 2.5, "PointA", "PointB");

    staff.AddDelivery(delivery1);

    testing::internal::CaptureStdout();
    staff.ShowingDelivery();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("��������� ��������� 52 ��� �������� ��������� ��������"), std::string::npos);
}
TEST(StaffTest, WorkerTest_Over70) {
    Staff staff("�������", 72);

    testing::internal::CaptureStdout();
    std::string post = staff.Worker(); 
    std::string output = testing::internal::GetCapturedStdout(); 
    std::string expectedOutput = "�������� ���������� ������������ ���������� �������\n";

    EXPECT_EQ(post, "�������");
    EXPECT_EQ(output, expectedOutput);
}

TEST(StaffTest, WorkerTest_Under70) {
    Staff staff("�������", 65);
    std::string post = staff.Worker(); 

    EXPECT_EQ(post, " ");
}