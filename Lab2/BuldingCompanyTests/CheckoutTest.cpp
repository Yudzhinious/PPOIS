#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab2/Checkout.h"
#include "C:/Users/ASUS/source/repos/Lab2/Budget.h"
#include "C:/Users/ASUS/source/repos/Lab2/Equipment.h"

TEST(CheckoutTest, ShowCheckoutTest) {
    testing::internal::CaptureStdout();

    Checkout checkout(10, 5, 123.45, "Checkout1");
    checkout.ShowCheckout();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Касса Checkout1 с расположением 123.45 содержит в очереди 10 заказов c задержкой в 5 дней"), std::string::npos);
}

TEST(CheckoutTest, AddBudgetTest) {
    Checkout checkout(10, 5, 123.45, "Checkout1");
    Budget budget(100, "Budget1", "Marketing", 50);

    checkout.AddBudget(budget);

    EXPECT_EQ(checkout.getMoney().size(), 1);
}

TEST(CheckoutTest, AddEquipmentTest) {
    Checkout checkout(10, 5, 123.45, "Checkout1");
    Equipment equipment("Laptop", 500);

    checkout.AddEquipment(equipment);

    EXPECT_EQ(checkout.getEquip().size(), 1);
}

TEST(CheckoutTest, CasherTest) {
    testing::internal::CaptureStdout();

    Checkout checkout(10, 5, 123.45, "Checkout1");
    checkout.Casher();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Заказ готов к выдаче"), std::string::npos);
}


TEST(CheckoutTest, ShowingEquipmentTest) {
    testing::internal::CaptureStdout();

    Checkout checkout(10, 5, 123.45, "Checkout1");
    Equipment equipment("Laptop", 500);
    checkout.AddEquipment(equipment);

    checkout.ShowingEquipment();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Касса Checkout1 с расположением 123.45 содержит в очереди 10 заказов c задержкой в 5 дней"), std::string::npos);
    EXPECT_NE(output.find("Laptop"), std::string::npos);
    EXPECT_NE(output.find("500"), std::string::npos);
}