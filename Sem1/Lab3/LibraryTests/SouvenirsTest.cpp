#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Souvenirs.h"

TEST(SouvenirsTest, ApplyDiscountValidTest) {
    Souvenirs souvenir(100, "Кубик Рубика", 500, 10, "Магазин");
    testing::internal::CaptureStdout();
    souvenir.ApplyDiscount(20); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Скидка 20% применена. Новая цена сувенира: 80"), std::string::npos);
}
TEST(SouvenirsTest, ApplyDiscountInvalidTest) {
    Souvenirs souvenir(100, "Кубик Рубика", 500, 10, "Магазин");
    testing::internal::CaptureStdout();
    souvenir.ApplyDiscount(150); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Ошибка: недопустимый процент скидки."), std::string::npos);
}
TEST(SouvenirsTest, CanPurchaseTestEnoughMoney) {
    Souvenirs souvenir(100, "Кубик Рубика", 500, 10, "Магазин");
    testing::internal::CaptureStdout();
    EXPECT_TRUE(souvenir.CanPurchase(150));
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Вы можете купить сувенир Кубик Рубика."), std::string::npos);
}
TEST(SouvenirsTest, IncreasePriceTest) {
    Souvenirs souvenir(100, "Кубик Рубика", 500, 10, "Магазин");
    testing::internal::CaptureStdout();
    souvenir.IncreasePrice(10); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Цена сувенира Кубик Рубика увеличена на 10%. Новая цена: 110"), std::string::npos);
}
TEST(SouvenirsTest, CheckAvailabilityTestInStock) {
    Souvenirs souvenir(100, "Кубик Рубика", 500, 10, "Магазин");
    testing::internal::CaptureStdout();
    souvenir.CheckAvailability(5);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Сувенир Кубик Рубика в наличии. Количество на складе: 5."), std::string::npos);
}
