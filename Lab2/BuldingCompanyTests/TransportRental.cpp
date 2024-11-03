#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab2/TransportRental.h"

TEST(TransportRentalTest, ExperienceNoTransportTest) {
    TransportRental rental(3, 4, "CompanyB", "Van", 0);

    testing::internal::CaptureStdout();
    rental.Experience();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("ѕроизводителем не был оснащен транспортом"), std::string::npos);
}