#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab2/Equipment.h"
#include "C:/Users/ASUS/source/repos/Lab2/TransportRental.h"
#include "C:/Users/ASUS/source/repos/Lab2/Things.h"

TEST(EquipmentTest, AddTransportRentalTest) {
    Equipment equipment("Source1", 50000);
    TransportRental rental(5, 3, "Company1", "Car", 10);

    equipment.AddTransportRental(rental);

    EXPECT_EQ(equipment.getRentals().size(), 1);
}

TEST(EquipmentTest, AddThingsTest) {
    Equipment equipment("Source2", 80000);
    Things thing(5, 3, "Company1", "Car", 10);

    equipment.AddThings(thing);

    EXPECT_EQ(equipment.getThings().size(), 1);
}

TEST(EquipmentTest, IsEnoughTest) {
    Equipment equipment("Source3", 12000);

    testing::internal::CaptureStdout();
    equipment.IsEnough();
    std::string output = testing::internal::GetCapturedStdout();

    int money = 360000;
    int real = 12000 * 30;

    if (money > real) {
        EXPECT_NE(output.find("Покупка совершена успешно"), std::string::npos);
    }
    else {
        EXPECT_NE(output.find("Недостаточно средств для закупки оборудования. Покупка отклонена"), std::string::npos);
    }
}

TEST(EquipmentTest, ShowEquipmentForThingsTest) {
    Equipment equipment("Source5", 30000);


    testing::internal::CaptureStdout();
    equipment.ShowEquipmentForThings();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Необходимо купить оборудование Source5 на сумму 30000 рублей."), std::string::npos);
}