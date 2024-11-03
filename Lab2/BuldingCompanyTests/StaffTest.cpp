#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab2/Staff.h"
#include "C:/Users/ASUS/source/repos/Lab2/Delivery.h"

TEST(StaffTest, AddDeliveryTest) {
    Staff staff( "директор", 52);
    Delivery delivery1(100, 2.5, "PointA", "PointB");

    staff.AddDelivery(delivery1);

    EXPECT_EQ(staff.getDelivery().size(), 1);
}

TEST(StaffTest, ShowDeliveryTest) {
    Staff staff("директор", 52);
    Delivery delivery1(100, 2.5, "PointA", "PointB");

    staff.AddDelivery(delivery1);

    testing::internal::CaptureStdout();
    staff.ShowingDelivery();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Сотрудник возрастом 52 лет занимает должность директор"), std::string::npos);
}